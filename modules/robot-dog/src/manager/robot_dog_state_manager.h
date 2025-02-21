#ifndef __ROBOT_DOG_STATE_H__
#define __ROBOT_DOG_STATE_H__
#include <common/enum.h>
#include "message_manager/message_manager.h"
using namespace perception_bridge;
//状态机切换
class RobotDogState
{
public:
    RobotDogState();

    TaskState GetState();
    TaskResult GetResult();
    void Init();
    void SetCanFinish(const bool& enable);
    bool GetCanFinish();
    const perception_msgs::TaskList& GetOutputPerception();
    const perception_msgs::TaskList& GetOutputPlanning();
    const perception_msgs::PercState& GetStateCallback();

    void handleTaskEvent(const perception_msgs::PercCmd::ConstPtr& msg);
    void handleStateEvent(const TaskState& state, const TaskResult& result);
    void handlePerceptionEvent(const perception_msgs::TaskList::ConstPtr& msg);
private:
        // 根据 point_name 获取 geometry_msgs/Pose
      bool getPose(const std::string& point_name, geometry_msgs::Pose& pose);
      // 取消任务
      void CancelTask();
      // 前往固定点任务
      void GoDest(const perception_msgs::PercCmd::ConstPtr& msg);
      // 跟随任务
      void Follow(const perception_msgs::PercCmd::ConstPtr& msg);
      // 欢迎任务
      void Welcome(const perception_msgs::PercCmd::ConstPtr& msg);
      // 找人任务
      void GoDestAndFindTarget(const perception_msgs::PercCmd::ConstPtr& msg);
private:
    //数据
    perception_msgs::TaskList task_list_perception_; //to perception
    perception_msgs::TaskList task_list_planning_; //to planning
    perception_msgs::PercState perc_state_;

    TaskType m_taskType;//模式类型
    TaskState m_currentState;//当前状态（0：空闲；1：执行中；2：完成）
    TaskResult m_currentResult;//当前结果（0：无效；1：成功；2：失败）
    bool m_can_finish;//完成条件


};

#endif //__ROBOT_DOG_STATE_H__