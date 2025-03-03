#include "follow_mode.h"
#include "common/global_project.h"

using namespace athena::function::action;

FollowMode::FollowMode(TaskType type)
  : ModeBase(type)
  , pubData_()
{
}

void FollowMode::Handle(const perception_msgs::PercCmd::ConstPtr& msg, RobotDogState* data_manager)
{
    //状态更新
    {
      auto& stateResult = data_manager->GetStateMsg();
      stateResult.perc_kind = perception_msgs::PercState::PERC_FOLLOW;
      stateResult.action_id = msg->action_id;
    }
    data_manager->SetCanFinish(false);
    
    pubData_.task_id = msg->action_id;
    pubData_.target_object = msg->follow_name;
    pubData_.task_type = perception_bridge::TaskType::TASK_FOLLOW;
    
    ROS_INFO("Follow %s:", msg->follow_name.c_str());
    AfjGetMain()->PublishTaskList(pubData_);
}