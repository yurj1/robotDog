#include "unitree_sdk_service.h"
#include "common/struct/CommonStruct.h"
#include "common/public_fun.h"
#include "apps/robot_dog_main.h"
#include "manager/message_handle_manager.h"

#include <cmath>
#include <thread>
#include <algorithm>  // for std::min and std::max

//uwb 数据
#define TOPIC_UWBSTATE "rt/uwbstate"
//高层状态topic，其中rt表示实时，lf表示低频
#define TOPIC_HIGHSTATE "rt/sportmodestate"
// nav command
#define TOPIC_COMMAND "rt/qt_command"
// nav callback
#define TOPIC_NOTICE "rt/qt_notice"

using namespace unitree::robot;
using namespace robot_dog;
using namespace robot_dog::operations;

static int UnitreeSdkService::nav_index_ = 0;

UnitreeSdkService::UnitreeSdkService(std::string networkInterface)
    :uwb_suber_(nullptr)
    ,sportmodestate_suber_(nullptr)
    ,subQtNotice(nullptr)
    ,conmmand_puber_(nullptr)
    ,sport_client_(nullptr)
    ,obstacles_client_(nullptr)
    ,networkInterface_(networkInterface)
    ,dogStateInfo_()
    ,is_owner_follow(false)
{
}

UnitreeSdkService::~UnitreeSdkService()
{
    uwb_suber_->CloseChannel();

    SAFE_DELETE(uwb_suber_);
    SAFE_DELETE(sportmodestate_suber_);
    SAFE_DELETE(subQtNotice);
    SAFE_DELETE(conmmand_puber_);
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
    //sportmodestate_suber_ = new ChannelSubscriber<unitree_go::msg::dds_::SportModeState_>(TOPIC_HIGHSTATE);
    //
    subQtNotice = new ChannelSubscriber<std_msgs::msg::dds_::String_>(TOPIC_NOTICE);
    // 创建一个导航模式事件发布者
    conmmand_puber_ = new ChannelPublisher<unitree_interfaces::msg::dds_::QtCommand_>(TOPIC_COMMAND);
    conmmand_puber_->InitChannel();
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
    //sportmodestate_suber_->InitChannel(std::bind(&UnitreeSdkService::UnitreeDogStateHandler, this, std::placeholders::_1));
    subQtNotice->InitChannel(std::bind(&UnitreeSdkService::NoticeHandler, this, std::placeholders::_1));

    std::cout  << "Sub rt/uwbstate, rt/sportmodestate" << std::endl;
}

const robot_dog::Pose& UnitreeSdkService::GetOwnerPose()
{
    return uwb_state_.owner_pose;
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
                v_w = std::abs(uwb_state_.owner_pose.theta) > 0.2 ? (uwb_state_.owner_pose.theta > 0 ? 0.5 : -0.5) : 0;
                v_x = std::abs(uwb_state_.owner_pose.x) > 1 ? (uwb_state_.owner_pose.x > 0 ? 0.3 : -0.3) : 0;

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
                    //obstacles_client_->MoveToIncrementPosition(owner_pose.x, owner_pose.x,owner_pose.theta);
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

int UnitreeSdkService::MoveOnObstaclesAvoid(float vx, float vy, float vw)
{
    if(! obstacles_client_)return -1;

    obstacles_client_->SwitchSet(true);
    obstacles_client_->UseRemoteCommandFromApi(true);

    return obstacles_client_->Move(vx, vy, vw);
}

void UnitreeSdkService::SingleNav(int node_edge_name_)
{
    unitree_interfaces::msg::dds_::QtCommand_ send_msg;
    nav_index_++;
    // Go to the location with node name 1
    send_msg.seq_().data() = "index:" + std::to_string(nav_index_) + ";";   // The value 123 is set by the user (1-10000).
    send_msg.command_() = 9;                 // 9 is a single node navigation command
    send_msg.node_edge_name_().push_back(node_edge_name_); // Target node name

    conmmand_puber_->Write(send_msg);
    std::cout << "send single nav command index: " << nav_index_ << std::endl;
}

void UnitreeSdkService::StopNav()
{
    unitree_interfaces::msg::dds_::QtCommand_ send_msg;
    nav_index_++;
    send_msg.seq_().data() = "index:" + std::to_string(nav_index_) + ";";   // The value 123 is set by the user (1-10000).
    send_msg.command_() = 13;                 // 13 is the pause navigation command

    conmmand_puber_->Write(send_msg);
    std::cout << "send single nav command index: " << nav_index_ << std::endl;
}

int UnitreeSdkService::ObstaclesMoveStop()
{
    if(! obstacles_client_)return -1;
    
    //obstacles_client_->SwitchSet(false);
    return obstacles_client_->UseRemoteCommandFromApi(false);
}

// void UnitreeSdkService::PrintState()
// {
//     std::lock_guard<std::mutex> lock(mutex_);
//     //打印输出机器狗位置
//     std::cout<<"position: "
//     <<dogStateInfo_.position()[0]<<", "
//     <<dogStateInfo_.position()[1]<<", "
//     <<dogStateInfo_.position()[2]<<std::endl;
//     //打印输出机器狗姿态四元数 (w,x,y,z)
//     std::cout<<"quaternion: "
//     <<dogStateInfo_.imu_state().quaternion()[0]<<", "
//     <<dogStateInfo_.imu_state().quaternion()[1]<<", "
//     <<dogStateInfo_.imu_state().quaternion()[2]<<", "
//     <<dogStateInfo_.imu_state().quaternion()[3]<<std::endl;
//     std::cout << "mode: " << dogStateInfo_.mode() << std::endl;
//     std::cout << "action progress_: " << dogStateInfo_.progress() << std::endl;
//     std::cout << "action gaitType: " << dogStateInfo_.gait_type() << std::endl;
// }

int UnitreeSdkService::PerformingAcrtion(const robot_dog::operations::DogMition& action)
{
    if(!sport_client_) return -1;

    int code = -1;

    if(action == STOP_MOVE)
    {
        return ObstaclesMoveStop();
    }

    switch (action)
    {
    case MORMAL_STAND:
        code = sport_client_->StandDown();
        break;
    case STAND_DOWN:
        /* code */
        code = sport_client_->StandDown();
        break;
    case STAND_UP:
        /* code */
        code = sport_client_->StandUp();
        break;
    case DAMP:
        /* code */
        break;
    case RECOVERY_STAND:
        code = sport_client_->RecoveryStand();
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
        code = sport_client_->Hello();
        break;
    case STOP_MOVE:
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
    if(uwb_state_.joy_mode != uwbstate_.joy_mode()) {
        uwb_state_.joy_mode = uwbstate_.joy_mode();
        std::cout << "joxmode: " << uwb_state_.joy_mode << std::endl;
        if(1 == uwb_state_.joy_mode) //伴随模式
            _AppGetMessageHandManager->SetDogState(robot_dog::operations::UsherDogState::DOG_USHER);
        else
            _AppGetMessageHandManager->SetDogState(robot_dog::operations::UsherDogState::DOG_IDLE);
    }
    if(uwb_state_.error_state != uwbstate_.error_state()) uwb_state_.error_state = uwbstate_.error_state();
    if(uwb_state_.buttons != uwbstate_.buttons()) uwb_state_.joy_mode = uwbstate_.buttons();
    if(uwb_state_.enabled_from_app != uwbstate_.enabled_from_app()) 
    {
        uwb_state_.enabled_from_app = uwbstate_.enabled_from_app();
    }

    robot_dog::Pose r_pose;
    r_pose.theta = uwbstate_.orientation_est();
    r_pose.x = uwbstate_.distance_est() * std::cos(uwbstate_.pitch_est()) * std::cos(uwbstate_.orientation_est());
    r_pose.x = uwbstate_.distance_est() * std::cos(uwbstate_.pitch_est()) * std::sin(uwbstate_.orientation_est());
    r_pose.z = uwbstate_.distance_est() * std::sin(uwbstate_.pitch_est()); 
    if(IsVaildPose(r_pose))
        uwb_state_.owner_pose = r_pose;

    // std::cout << "joxmode: " << uwb_state_.joy_mode << std::endl;
    // std::cout << "x: " <<uwb_state_.owner_pose.x << "- y: " << uwb_state_.owner_pose.x << "- z: " << uwb_state_.owner_pose.z << "- theta: " << uwb_state_.owner_pose.theta <<  std::endl; 
    // printf("error_state: [%d], buttons: [%d], enabled_from_app: [%d]\n", uwb_state_.error_state, uwb_state_.buttons, uwb_state_.enabled_from_app);
}

//获取运动状态的回调函数
void UnitreeSdkService::UnitreeDogStateHandler(const void* message)
{
//   std::lock_guard<std::mutex> lock(mutex_);
//   unitree_go::msg::dds_::SportModeState_ state = *(unitree_go::msg::dds_::SportModeState_*)message;

//   if(dogStateInfo_ != state)
//   {
//     dogStateInfo_ =  state;
//     robot_dog_posiotn_.x = state.position()[0];
//     robot_dog_posiotn_.y = state.position()[0];
//     robot_dog_posiotn_.z = state.position()[0];

//     robot_dog_posiotn_.q_w = state.imu_state().quaternion()[0];
//     robot_dog_posiotn_.q_x = state.imu_state().quaternion()[1];
//     robot_dog_posiotn_.q_y = state.imu_state().quaternion()[2];
//     robot_dog_posiotn_.q_z = state.imu_state().quaternion()[3];
//   }
}
/*
其中index为指令唯一识别码数字，用于区分不同指令，由用户端确定（取值范围1—10000）；
feedback为执行情况（1为执行成功，0为执行失败，2执行等待）；
state为当前系统状态（0为空闲状态，1为系统错误，2为建图状态，3为导航状态，4为重定位开启状态，5为初始化定位完成状态，6为导航节点打开状态）；
notice为发送出的提示string消息。

index=10001的qt_notice消息为导航过程中信息反馈，反馈示例如下。arrive为当前到达点名称；
finish：单次循环任务中已完成点总数，单点导航时值为-1；all：单次循环任务的点总数，单点导航时值为-1；
loop：已完成的循环次数，单点导航时值为-1；
obstruct：是否遇到障碍物(1否/-1是)；notice为提示消息。
*/
void UnitreeSdkService::NoticeHandler(const void *message)
{
    //std::cout << "recv NoticeHandler" << std::endl;
    int index_, begin_, end_, feedback_, arrive_;
    const std_msgs::msg::dds_::String_ *seq = (const std_msgs::msg::dds_::String_ *)message;
    std::string str_, notice_;

    begin_ = seq->data().find("index:", 0); // Instruction unique identifier
    end_ = seq->data().find(";", begin_);
    str_ = seq->data().substr(begin_ + 6, end_ - begin_ - 6);
    index_ = atoi(str_.c_str());

    begin_ = seq->data().find("notice:", 0); // Prompt message
    end_ = seq->data().find(";", begin_);
    notice_ = seq->data().substr(begin_ + 7, end_ - begin_ - 7);

    if (index_ <= 10000)
    { // Command execution feedback
        begin_ = seq->data().find("feedback:", 0);
        end_ = seq->data().find(";", begin_);
        str_ = seq->data().substr(begin_ + 9, end_ - begin_ - 9);
        feedback_ = atoi(str_.c_str());
        if (feedback_ == 0 || feedback_ == -1)
            std::cout << "\033[1;31m"
                 << "Command execution failed with index = " << index_ << "."
                 << "\033[0m";
        std::cout << notice_ << std::endl;
    }
    else if (index_ == 10001)
    { // Navigation feedback
        begin_ = seq->data().find("arrive:", 0);
        end_ = seq->data().find(";", begin_);
        str_ = seq->data().substr(begin_ + 7, end_ - begin_ - 7);
        arrive_ = atoi(str_.c_str());
        std::cout << " I arrived node " << arrive_ << ". " << notice_ << std::endl;
    }
}

bool UnitreeSdkService::IsVaildPose(robot_dog::Pose pose) 
{
    if(std::abs(uwb_state_.owner_pose.x - pose.x) < 0.1 && std::abs(uwb_state_.owner_pose.x - pose.x) < 0.1 && std::abs(uwb_state_.owner_pose.theta - pose.theta) < 0.1)
        return false;
    return true;
}

// 从单位四元数中提取旋转角度（弧度）
float UnitreeSdkService::GetRotationAngleInRadians(const robot_dog::Quaternion& q) {
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