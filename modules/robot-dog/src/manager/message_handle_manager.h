#ifndef __message_handle_manager_H__
#define __message_handle_manager_H__

#include <mutex>

#include "message_manager/message_manager.h"
#include "interface/MSG_V_1_0_0.pb.h"

using namespace robot_dog::operations;

class MessageHandleManager
{
public:
    MessageHandleManager();

    TaskState GetState();
    TaskResult GetResult();
    void Init();
    
    bool GetCanFinish();
    const perception_msgs::TaskList& GetOutputPerception();
    const perception_msgs::TaskList& GetOutputPlanning();
    const perception_msgs::PercState& GetConstStateMsg();
    perception_msgs::PercState& GetStateMsg();

    void SetCanFinish(const bool& enable);
    void SetStateMsg(const perception_msgs::PercState& result){perc_state_ = result;}
    //处理规划集成发过来的状态信息
    void handleStateEvent(const perception_msgs::TaskList::ConstPtr& msg);
    //处理感知发送过来的反馈信息
    void handlePerceptionEvent(const perception_msgs::TaskList::ConstPtr& msg);
    //处理手柄数据
    void HandleJoyMsg(const robot_dog::JoyInfo& joy_msg);

    //处理订阅集成发过来的任务信息
    void handleTaskEvent(const robot_dog::PercCmd& msg);
    //处理录包服务的反馈处理
    bool recordBagCallback(robot_dog::RecordBag &req, robot_dog::CallbackInfo &rsp);
private:
    bool _isRunningChildren();
    
    //数据
    perception_msgs::PercCmd recv_cmd_msg_info_; //to planning
    perception_msgs::TaskList task_list_planning_; //to planning
    perception_msgs::PercState perc_state_;

    robot_dog::JoyInfo joy_msg_mqtt_input_;  // joy data
    geometry_msgs::Twist twist_;  // speed data

    bool m_can_finish;//完成条件
    std::atomic<bool> start_record_;
    pid_t             recorder_pid_;

    std::mutex mutex_;
};

#endif //__message_handle_manager_H__