#ifndef __ROS_SERVICE_MANAGER_H__
#define __ROS_SERVICE_MANAGER_H__

#include <mutex>

#include <common/enum.h>
#include "message_manager/message_manager.h"

using namespace robot_dog::operations;
//状态机切换
class RosServiceManager
{
public:
    RosServiceManager();

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
    //处理订阅集成发过来的任务信息
    void handleTaskEvent(const perception_msgs::PercCmd::ConstPtr& msg);
    //处理规划集成发过来的状态信息
    void handleStateEvent(const perception_msgs::TaskList::ConstPtr& msg);
    //处理感知发送过来的反馈信息
    void handlePerceptionEvent(const perception_msgs::TaskList::ConstPtr& msg);
    //处理录包服务的反馈处理
    bool recordBagCallback(perception_msgs::DogRecordBag::Request &req, perception_msgs::DogRecordBag::Response &res);
private:
    bool _isRunningChildren();
    
    //数据
    perception_msgs::PercCmd recv_cmd_msg_info_; //to planning
    perception_msgs::TaskList task_list_planning_; //to planning
    perception_msgs::PercState perc_state_;

    bool m_can_finish;//完成条件

    std::atomic<bool> start_record_;
    pid_t             recorder_pid_;

    std::mutex m_mutex;
};

#endif //__ROS_SERVICE_MANAGER_H__