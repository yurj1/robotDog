#include "cancel_mode.h"
#include "common/global_project.h"

using namespace athena::function::action;

CancelMode::CancelMode(TaskType type)
  : ModeBase(type)
  , pubData_()
{
}

void CancelMode::Handle(const perception_msgs::PercCmd::ConstPtr& msg, RobotDogState* data_manager)
{
    //可直接完成
    data_manager->SetCanFinish(true);
    
    //状态更新
    auto& stateResult = data_manager->GetStateMsg();
    stateResult.perc_kind = perception_msgs::PercState::PERC_CANCEL;
    stateResult.action_id = msg->action_id;
    pubData_.task_id = msg->action_id;
    pubData_.task_type = perception_bridge::TaskType::TASK_CANCEL;
    
    ROS_INFO("Cancel Task");
    AfjGetMain()->PublishTaskList(pubData_);
}