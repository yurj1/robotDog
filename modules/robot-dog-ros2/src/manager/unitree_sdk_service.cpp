#include "unitree_sdk_service.h"
#include "common/struct/CommonStruct.h"
#include "common/public_fun.h"

#include <cmath>
#include <thread>
#include <algorithm>  // for std::min and std::max

//uwb 数据
#define TOPIC_UWBSTATE "rt/uwbstate"
//高层状态topic，其中rt表示实时，lf表示低频
#define TOPIC_HIGHSTATE "rt/sportmodestate"

using namespace unitree::robot;
using namespace robot_dog;
using namespace robot_dog::operations;

// 从单位四元数中提取旋转角度（弧度）
static float GetRotationAngleInRadians(const robot_dog::Quaternion& q) {
    // 计算四元数模长
    float norm = std::sqrt(q.x * q.x + q.y * q.y + q.z * q.z + q.w * q.w);

    // 避免除零错误
    if (norm < 1e-6f) {
        return 0.0f; // 非法四元数，返回无旋转
    }

    // 归一化实部 w
    float w = q.w / norm;

    // 限制 w 范围防止 acos 越界
    w = std::max(-1.0f, std::min(w, 1.0f));

    // 返回弧度表示的旋转角度
    return 2.0f * std::acos(w);
}

UnitreeSdkService::UnitreeSdkService(std::string networkInterface)
    :uwb_suber_(nullptr)
    ,sportmodestate_suber_(nullptr)
    ,sport_client_(nullptr)
    ,obstacles_client_(nullptr)
    ,networkInterface_(networkInterface)
    //,uwbStateInfo_()
    ,dogStateInfo_()
    ,is_owner_follow(false)
{
}

UnitreeSdkService::~UnitreeSdkService()
{
    uwb_suber_->CloseChannel();

    SAFE_DELETE(uwb_suber_);
    SAFE_DELETE(sportmodestate_suber_);
    SAFE_DELETE(obstacles_client_);
}

void UnitreeSdkService::Init()
{
    if(!networkInterface_.empty())
        unitree::robot::ChannelFactory::Instance()->Init(0, networkInterface_);//domain id , interface
    else
    unitree::robot::ChannelFactory::Instance()->Init(0);

    //创建一个 uwb Subscriber
    uwb_suber_ = new ChannelSubscriber<unitree_go::msg::dds_::UwbState_>(TOPIC_UWBSTATE);
    //创建一个state Subscriber
    sportmodestate_suber_ = new ChannelSubscriber<unitree_go::msg::dds_::SportModeState_>(TOPIC_HIGHSTATE);
    //动作执行对象
    sport_client_ = new unitree::robot::go2::SportClient();
    sport_client_->SetTimeout(3.0f);//超时时间
    sport_client_->Init();
    //避障类初始化
    obstacles_client_ = new unitree::robot::go2::ObstaclesAvoidClient();
    obstacles_client_->SetTimeout(3.0f);
    obstacles_client_->Init();
    //sc.SwitchSet(true);//开启避障

    //初始化Channel
    uwb_suber_->InitChannel(std::bind(&UnitreeSdkService::UwbStateHandler, this, std::placeholders::_1));
    sportmodestate_suber_->InitChannel(std::bind(&UnitreeSdkService::UnitreeDogStateHandler, this, std::placeholders::_1));

    std::cout  << "Sub rt/uwbstate, rt/sportmodestate" << std::endl;
}

const robot_dog::Pose& UnitreeSdkService::GetOwnerPose()
{
    return owner_pose_;
}

void UnitreeSdkService::FaceOwner()
{
    if(is_owner_follow) return;

    is_owner_follow = true;
    static int start_count = 0;
    static bool is_run = false;
    std::thread([this](){
        while(is_owner_follow)
        {
            float v_x = 0;
            float v_w = 0;
            //float v_y = 0;
            if(dogStateInfo_.progress() == 0)
            {
                v_w = std::abs(owner_pose_.theta) > 0.2 ? (owner_pose_.theta > 0 ? 0.5 : -0.5) : 0;
                v_x = std::abs(owner_pose_.x) > 1 ? (owner_pose_.x > 0 ? 0.3 : -0.3) : 0;

                if(v_w != 0 || v_x != 0)
                {
                    if(start_count <= 3)
                    {
                        start_count++;
                        std::cout << "count: " << start_count << std::endl;
                        if(start_count == 3) std::cout << "Start Owner follow" << std::endl;
                        return;
                    }
                    if(! is_run) {
                        is_run = true;
                        obstacles_client_->SwitchSet(true);
                        obstacles_client_->UseRemoteCommandFromApi(true);
                    }
                    obstacles_client_->Move(v_x, 0, v_w);
                    //obstacles_client_->MoveToIncrementPosition(owner_pose_.x, owner_pose_.x,owner_pose_.theta);
                }
                else if(is_run)
                {
                    std::cout << "Owner follow over" << std::endl;
                    int code = 0;
                    obstacles_client_->SwitchSet(false);
                    obstacles_client_->UseRemoteCommandFromApi(false);
                    code = PerformingAcrtion(robot_dog::operations::DogMition::STOP_MOVE);
                    if(code)
                    {
                        std::cout << "action: [STOP_MOVE] error code: " << code;
                        return;
                    }

                    std::thread([this](){
                        std::this_thread::sleep_for(std::chrono::milliseconds(500));
                        int code = PerformingAcrtion(robot_dog::operations::DogMition::HELLO);
                        if(code)
                            std::cout << "action: [HELLO] error code: " << code;
                    }).detach();

                    is_run = false;
                    start_count = 0;
                    v_w = 0;
                    v_x = 0;
                }
            }
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }

        PerformingAcrtion(robot_dog::operations::DogMition::STOP_MOVE);
    }).detach();
}

void UnitreeSdkService::FaceOwnerStop()
{
    if(is_owner_follow)
        is_owner_follow = false;
}

int UnitreeSdkService::MoveToAbsolutePosition(const robot_dog::Position& pose)
{
    if(! obstacles_client_)return -1;

    obstacles_client_->SwitchSet(true);
    obstacles_client_->UseRemoteCommandFromApi(true);

    return obstacles_client_->MoveToAbsolutePosition(pose.x, pose.y, GetRotationAngleInRadians(robot_dog::Quaternion(pose.q_x, pose.q_y, pose.q_z, pose.q_w)));
}

void UnitreeSdkService::ObstaclesMoveStop()
{
    if(! obstacles_client_)return;
    
    //obstacles_client_->SwitchSet(false);
    obstacles_client_->UseRemoteCommandFromApi(false);
}

void UnitreeSdkService::PrintState()
{
    std::lock_guard<std::mutex> lock(mutex_);
    //打印输出机器狗位置
    std::cout<<"position: "
    <<dogStateInfo_.position()[0]<<", "
    <<dogStateInfo_.position()[1]<<", "
    <<dogStateInfo_.position()[2]<<std::endl;
    //打印输出机器狗姿态四元数 (w,x,y,z)
    std::cout<<"quaternion: "
    <<dogStateInfo_.imu_state().quaternion()[0]<<", "
    <<dogStateInfo_.imu_state().quaternion()[1]<<", "
    <<dogStateInfo_.imu_state().quaternion()[2]<<", "
    <<dogStateInfo_.imu_state().quaternion()[3]<<std::endl;
    std::cout << "mode: " << dogStateInfo_.mode() << std::endl;
    std::cout << "action progress_: " << dogStateInfo_.progress() << std::endl;
    std::cout << "action gaitType: " << dogStateInfo_.gait_type() << std::endl;

    std::cout << "Dog V_x: " << vx_ << std::endl;
    std::cout << "Dog y: " << vy_ << std::endl;
    std::cout << "Dog V_z: " << vz_ << std::endl;
}

int UnitreeSdkService::PerformingAcrtion(const robot_dog::operations::DogMition& action)
{
    if(!sport_client_) return -1;

    int code = -1;

    switch (action)
    {
    case STAND_DOWN:
        /* code */
        break;
    case STAND_UP:
        /* code */
        break;
    case DAMP:
        /* code */
        break;
    case RECOVERY_STAND:
        /* code */
        break;
    case SIT:
        /* code */
        break;
    case RISE_SIT:
        /* code */
        break;
    case STRETCH:
        /* code */
        break;  
    case WALLOW:
        /* code */
        break;
    case CONTENT:
        /* code */
        break;
    case POSE:
        /* code */
        break;
    case SCRAPE:
        /* code */
        if(dogStateInfo_.progress() == 0) // 当前没有执行的动作
            code = sport_client_->Scrape();
        break;
    case FRONT_FILP:
        /* code */
        break;
    case FRONT_JUMP:
        /* code */
        break;
    case FRONT_POUNCE:
        /* code */
        break;
    case HELLO:
        /* code */
        if(dogStateInfo_.progress() == 0) // 当前没有执行的动作
            code = sport_client_->Hello();
        break;
    case STOP_MOVE:
        /* code */
        code = sport_client_->StopMove();
        break;
    
    default:
        break;
    }
    return code;
}

void UnitreeSdkService::UwbStateHandler(const void* message)
{
    unitree_go::msg::dds_::UwbState_ uwbstate_ = *(unitree_go::msg::dds_::UwbState_*)message;

    // std::cout << "orientation_est:" << uwbstate_.orientation_est() << std::endl;
    // std::cout << "pitch_est:" << uwbstate_.pitch_est() << std::endl;
    // std::cout << "distance_est:" << uwbstate_.distance_est() << std::endl;
    // std::cout << "yaw_est:" << uwbstate_.yaw_est() << std::endl;
    // std::cout << "-------------------------"  << std::endl;
    std::cout << "joxmode: " << uwbstate_.joy_mode() << std::endl;
    std::cout << std::endl;

    robot_dog::Pose r_pose;
    r_pose.theta = uwbstate_.orientation_est();
    r_pose.x = uwbstate_.distance_est() * std::cos(uwbstate_.pitch_est()) * std::cos(uwbstate_.orientation_est());
    r_pose.x = uwbstate_.distance_est() * std::cos(uwbstate_.pitch_est()) * std::sin(uwbstate_.orientation_est());
    r_pose.z = uwbstate_.distance_est() * std::sin(uwbstate_.pitch_est());
    if(IsVaildPose(r_pose)) 
    {
        owner_pose_ = r_pose;
    }

    std::cout << "x: " <<owner_pose_.x << "- y: " << owner_pose_.x << "- z: " << owner_pose_.z << "- theta: " << owner_pose_.theta <<  std::endl; 
    //if(uwbStateInfo_ != uwbstate_) uwbStateInfo_ = uwbstate_;
}

//获取运动状态的回调函数
void UnitreeSdkService::UnitreeDogStateHandler(const void* message)
{
  std::lock_guard<std::mutex> lock(mutex_);
  unitree_go::msg::dds_::SportModeState_ state = *(unitree_go::msg::dds_::SportModeState_*)message;

  if(dogStateInfo_ != state)
  {
    dogStateInfo_ =  state;
    robot_dog_posiotn_.x = state.position()[0];
    robot_dog_posiotn_.y = state.position()[0];
    robot_dog_posiotn_.z = state.position()[0];

    robot_dog_posiotn_.q_w = state.imu_state().quaternion()[0];
    robot_dog_posiotn_.q_x = state.imu_state().quaternion()[1];
    robot_dog_posiotn_.q_y = state.imu_state().quaternion()[2];
    robot_dog_posiotn_.q_z = state.imu_state().quaternion()[3];

    vx_ = state.velocity()[0];
    vy_ = state.velocity()[0];
    vz_ = state.velocity()[0];
  }
  
}

bool UnitreeSdkService::IsVaildPose(robot_dog::Pose pose) 
{
    if(std::abs(owner_pose_.x - pose.x) < 0.1 && std::abs(owner_pose_.x - pose.x) < 0.1 && std::abs(owner_pose_.theta - pose.theta) < 0.1)
        return false;
    return true;
}