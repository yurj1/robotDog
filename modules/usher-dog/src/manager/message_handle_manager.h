#ifndef __message_handle_manager_H__
#define __message_handle_manager_H__

#include <mutex>

#include "message_manager/message_manager.h"
#include "interface/MSG_V_1_0_0.pb.h"

namespace robot_dog::services {
    class JoyHandleService;
    class VideoService;
}

class MessageHandleManager
{
public:
    MessageHandleManager();
    ~MessageHandleManager();

    //TaskState GetState();
    //TaskResult GetResult();
    const robot_dog::operations::UsherDogState& GetDogState();
    void SetDogState(const robot_dog::operations::UsherDogState& state) { if(state != dog_state_) dog_state_ = state;};
    void Init();
    
    const robot_dog::TaskList& GetOutputPlanning();
    const robot_dog::PercState& GetConstStateMsg();
    robot_dog::PercState& GetStateMsg();

    void SetCanFinish(const bool& enable);
    void SetStateMsg(const robot_dog::PercState& result){perc_state_ = result;}
    //处理规划集成发过来的状态信息
    void handleStateEvent(const robot_dog::TaskList& msg);
    //处理感知发送过来的反馈信息
    void handlePerceptionEvent(const robot_dog::TaskList& msg);
    //处理语音指令消息
    void HandleObuCmdMsg(const std::vector<robot_dog::ObuCmd>& obu_cmd_msg);
    //处理任务事件
    void handleTaskEvent(const robot_dog::PercCmd& msg);
    //处理录包服务的反馈处理
    bool recordBagCallback(robot_dog::RecordBag &req, robot_dog::CallbackInfo &rsp);

    //joy service
    robot_dog::services::JoyHandleService* GetJoyService() {return joy_services_ptr_;}
    robot_dog::services::VideoService* GetVoiceService() {return voice_services_ptr_;}
private:
    bool _isCanFinish();
    bool _isRunningChildren();
    
private:
    //狗状态信息
    robot_dog::operations::UsherDogState dog_state_;
    
    //数据
    robot_dog::PercCmd recv_cmd_msg_info_;
    robot_dog::TaskList task_list_planning_; //to planning
    robot_dog::PercState perc_state_;

    robot_dog::JoyInfo joy_msg_mqtt_input_;  // joy data

    bool m_can_finish;//完成条件
    std::atomic<bool> start_record_;
    pid_t             recorder_pid_;

    std::mutex mutex_;

    robot_dog::services::JoyHandleService* joy_services_ptr_;
    robot_dog::services::VideoService* voice_services_ptr_;
};

#endif //__message_handle_manager_H__