#ifndef __ROBOT_DOG_STATE_H__
#define __ROBOT_DOG_STATE_H__

#include <mutex>

#include <common/enum.h>
#include "message_manager/message_manager.h"

using namespace robot_dog::operations;
//状态机切换
class RobotDogState
{
public:
    RobotDogState();

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

    void handleTaskEvent(const perception_msgs::PercCmd::ConstPtr& msg);
    void handleStateEvent(const perception_msgs::TaskList::ConstPtr& msg);
    void handlePerceptionEvent(const perception_msgs::TaskList::ConstPtr& msg);
private:
    //数据
    perception_msgs::PercCmd recv_cmd_msg_info_; //to planning
    perception_msgs::TaskList task_list_planning_; //to planning
    perception_msgs::PercState perc_state_;

    bool m_can_finish;//完成条件

    std::mutex m_mutex;
};

#endif //__ROBOT_DOG_STATE_H__