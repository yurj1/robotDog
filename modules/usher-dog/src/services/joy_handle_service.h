#ifndef __joy_handle_service_H__
#define __joy_handle_service_H__

#include <mutex>
#include <atomic>
#include <queue>
#include <condition_variable>

#include "common/struct/CommonStruct.h"

using namespace robot_dog::operations;
using namespace robot_dog;
namespace robot_dog {
    namespace services {
        class JoyHandleService
        {
        public:
            JoyHandleService();
            ~JoyHandleService();
            void Init();
            //处理手柄数据
            void HandleJoyMsg(const robot_dog::JoyInfo& joyMsg);
        private:
            void LoopPublishVelocity();
            void LoopPublishAction();
        private:
            int speedLevel; // 1: 低速; 2: 中速; 3: 高速
            Velocity    current_joy_velocity_; //手柄下发的速度
            std::atomic<bool> is_run_; //速度发布线程使能
            std::atomic<bool> is_send_;//是否发布速度使能
            robot_dog::JoyInfo joy_msg_mqtt_input_; //手柄历史数据

            //动作执行
            std::mutex action_mtx_;
            std::queue<robot_dog::operations::DogMition> action_queue_;
            std::condition_variable action_cv_;
        };
    }// namespace services
}// namespace robot_dog

#endif //__joy_handle_service_H__