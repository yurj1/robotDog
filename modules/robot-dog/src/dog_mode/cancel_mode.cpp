#include "cancel_mode.h"
#include "common/global_project.h"
#include "robot_dog_main.h"

using namespace athena::function::action;

CancelMode::CancelMode(TaskType type)
  : ModeBase(type)
  , pubData_()
{
}

void CancelMode::Handle(const perception_msgs::PercCmd::ConstPtr& msg, RosServiceManager* data_manager)
{
    //可直接完成
    data_manager->SetCanFinish(true);
    
    //状态更新
    auto& stateResult = data_manager->GetStateMsg();
    stateResult.perc_kind = perception_msgs::PercState::PERC_CANCEL;
    stateResult.action_id = msg->action_id;
    pubData_.task_id = msg->action_id;
    pubData_.task_type = robot_dog::operations::TaskType::TASK_CANCEL;
    
    ROS_INFO("Cancel Task");
    AfjGetMain()->PublishTaskList(pubData_);
}