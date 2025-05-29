#include "joy_handle_service.h"
#include "common/public_fun.h"
#include "apps/robot_dog_main.h"
#include "unitree_sdk_service.h"

#include <thread>

#define X_MAX_SPEED 3.0f
#define X_MIN_SPEED 2.0f

#define Y_MAX_SPEED 1.0f
#define Y_MIN_SPEED 1.0f

#define W_MAX_SPEED 4.0f
#define W_MIN_SPEED 4.0f

using namespace robot_dog::services;

JoyHandleService::JoyHandleService()
    : speedLevel(2)
    , is_run_(true)
    , is_send_(false)
{
    Init();
}

JoyHandleService::~JoyHandleService()
{
    is_run_ = false;
}

void JoyHandleService::Init()
{
    std::thread(&JoyHandleService::LoopPublishVelocity, this).detach();
    std::thread(&JoyHandleService::LoopPublishAction, this).detach();

    //初始化手柄数据
    joy_msg_mqtt_input_.buttons.resize(11);
    joy_msg_mqtt_input_.axes.resize(8);
}

void JoyHandleService::HandleJoyMsg(const robot_dog::JoyInfo& joy_msg)
{
    if(! AppGetUnitreeService()) return ;

       std::cout << "速度摇杆_a0[左右]: " << joy_msg.axes[0] << std::endl;//MA 左摇杆
       std::cout << "速度摇杆_a1:[上下]: " << joy_msg.axes[1] << std::endl;
       std::cout << "joy_msg_axes2_:" << joy_msg.axes[2] << std::endl;
       std::cout << "转弯摇杆_a3[左右]: " << joy_msg.axes[3] << std::endl;//MB 右摇杆 LEFT :1  RIGHT : -1
      std::cout << "joy_msg_axes4_:" << joy_msg.axes[4] << std::endl;
      std::cout << "joy_msg_axes5_:" << joy_msg.axes[5] << std::endl;
      std::cout << "joy_msg_axes6_:" << joy_msg.axes[6] << std::endl;
      std::cout << "joy_msg_axes7_:" << joy_msg.axes[7] << std::endl;
      std::cout << "joy_msg_buttons0_:" << joy_msg.buttons[0] << std::endl;
       std::cout << "B按键_b1: " << joy_msg.buttons[1] << std::endl;//B
      std::cout << "joy_msg_buttons2_:" << joy_msg.buttons[2] << std::endl;
      std::cout << "joy_msg_buttons3_:" << joy_msg.buttons[3] << std::endl;
       std::cout << "LB按键_b4: " << joy_msg.buttons[4] << std::endl;//LB
       std::cout << "RB按键_b5: " << joy_msg.buttons[5] << std::endl;//RB
      std::cout << "减速_BACK_b6:" << joy_msg.buttons[6] << std::endl;
       std::cout << "加速_START_b7: " << joy_msg.buttons[7] << std::endl;//START
      std::cout << "joy_msg_buttons8_:" << joy_msg.buttons[8] << std::endl;
       std::cout << "速度摇杆按下_b9:" << joy_msg.buttons[9] << std::endl;
       std::cout << "转弯摇杆按下_b10:" << joy_msg.buttons[10] << std::endl;
       std::cout << "=============================" << std::endl << std::endl;
       
    if(joy_msg.buttons[5] == 1&&joy_msg.buttons[9] == 1)// 站立
    {
        std::unique_lock<std::mutex> lock(action_mtx_, std::try_to_lock);
        if (! lock.owns_lock())
            return ;

        printf("站立\n");
        action_queue_.push(DogMition::RECOVERY_STAND);
        action_cv_.notify_one();
    //AppGetUnitreeService()->PerformingAcrtion(robot_dog::operations::DogMition::MORMAL_STAND); //正常站立
    //AppGetUnitreeService()->PerformingAcrtion(robot_dog::operations::DogMition::BLANCE_STAND);//平衡站立
    //AppGetUnitreeService()->PerformingAcrtion(robot_dog::operations::DogMition::RECOVERY_STAND);//恢复站立
    //return;
    }
    else if(joy_msg.buttons[5] == 1 && joy_msg.buttons[10] == 1) // 趴下
    {
        std::unique_lock<std::mutex> lock(action_mtx_, std::try_to_lock);
        if (! lock.owns_lock())
            return ;

        printf("趴下\n");
        action_queue_.push(DogMition::STAND_DOWN);
        action_cv_.notify_one();
        //AppGetUnitreeService()->PerformingAcrtion(robot_dog::operations::DogMition::STAND_DOWN);
        //return;
    }
    else if(joy_msg.buttons[5] == 1 && joy_msg.buttons[1] == 1) // 阻尼
    {
        std::unique_lock<std::mutex> lock(action_mtx_, std::try_to_lock);
        if (! lock.owns_lock())
            return ;

        printf("阻尼\n");
        action_queue_.push(DogMition::DAMP);
        action_cv_.notify_one();
        //AppGetUnitreeService()->PerformingAcrtion(robot_dog::operations::DogMition::STOP_MOVE);
        //return;
    }
    else if(joy_msg.buttons[5] == 1 && joy_msg.buttons[0] == 1) // 打招呼
    {
        std::unique_lock<std::mutex> lock(action_mtx_, std::try_to_lock);
        if (! lock.owns_lock())
            return ;

        printf("打招呼\n");
        action_queue_.push(DogMition::HELLO);
        action_cv_.notify_one();
        //AppGetUnitreeService()->PerformingAcrtion(robot_dog::operations::DogMition::STOP_MOVE);
        //return;
    }
    else if(joy_msg.buttons[6] && joy_msg_mqtt_input_.buttons[6] != joy_msg.buttons[6]) //减速档位
    {
        speedLevel = speedLevel - 1 < 1 ? 1 : speedLevel - 1;
        std::cout << "已减速, 当前速度档位为: " << speedLevel << std::endl;
    }
    else if(joy_msg.buttons[7] && joy_msg_mqtt_input_.buttons[7] != joy_msg.buttons[7]) //减速档位
    {
        speedLevel = speedLevel + 1 > 3 ? 3 : speedLevel + 1;
        std::cout << "已加速, 当前速度档位为: " << speedLevel << std::endl;
    }
    else if(joy_msg.buttons[4]==1) // 遥控机器狗
    {
        current_joy_velocity_.vx = joy_msg.axes[1] > 0 ? (joy_msg.axes[1] * X_MAX_SPEED / 3 * speedLevel) : (joy_msg.axes[1] * X_MIN_SPEED / 3 * speedLevel);   // vx
        current_joy_velocity_.vy = joy_msg.axes[0] > 0 ? (joy_msg.axes[0] * Y_MAX_SPEED / 3 * speedLevel) : (joy_msg.axes[0] * Y_MIN_SPEED / 3 * speedLevel);   // vy
        current_joy_velocity_.vw = joy_msg.axes[3] > 0 ? (joy_msg.axes[3] * W_MAX_SPEED / 3 * speedLevel) : (joy_msg.axes[3] * W_MIN_SPEED / 3 * speedLevel);   // vw
        std::cout << "vx: [" << current_joy_velocity_.vx << "]" \
        << " vy: [" << current_joy_velocity_.vy << "]" \
        << " vw: [" << current_joy_velocity_.vw << "]" << std::endl;
        if(! is_send_) is_send_ = true;
    }
    else if(is_send_)
    {
        std::cout << "关闭手柄控制使能" << std::endl;
        is_send_ = false;
        action_queue_.push(DogMition::STOP_MOVE);
        action_cv_.notify_one();
        //AppGetUnitreeService()->ObstaclesMoveStop();
    }

    if(joy_msg_mqtt_input_ != joy_msg)
    {
        joy_msg_mqtt_input_ = joy_msg;
    }
}

void JoyHandleService::LoopPublishVelocity()
{
    while(is_run_)
    {
        if(AppGetUnitreeService() && is_send_)
        {
            AppGetUnitreeService()->MoveOnObstaclesAvoid(current_joy_velocity_.vx, current_joy_velocity_.vy, current_joy_velocity_.vw);
            std::this_thread::sleep_for(std::chrono::milliseconds(50));
        }
        else
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

void JoyHandleService::LoopPublishAction()
{
    while(is_run_)
    {
        if(AppGetUnitreeService())
        {
            std::unique_lock<std::mutex> lock(action_mtx_);
            action_cv_.wait(lock, [this]() { return !action_queue_.empty(); });  // 等待直到队列非空
            while (! action_queue_.empty())
            {
                std::cout << "action run " << std::endl;
                AppGetUnitreeService()->PerformingAcrtion(action_queue_.front());
                action_queue_.pop();
            }
        }
        else
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}