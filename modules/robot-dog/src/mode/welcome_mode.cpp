#include "welcome_mode.h"
#include "apps/global_project.h"

WelcomeMode::WelcomeMode()
  :pubData_()
{
}

void WelcomeMode::Handle(const perception_msgs::PercCmd::ConstPtr& msg, RobotDogState* data_manager)
{
    //状态更新
    {
        auto& stateResult = data_manager->GetStateMsg();
        stateResult.perc_kind = perception_msgs::PercCmd::PERC_WELCOME_DEMO;
        stateResult.action_id = msg->action_id;
    }
    
    data_manager->SetCanFinish(true);
    pubData_.task_id = msg->action_id;
    pubData_.task_type = perception_bridge::TaskType::TASK_WELCOME;
    pubData_.target_object = msg->follow_name;
    
    ROS_INFO("Welcome %s:", msg->follow_name.c_str());
    AfjGetMain()->PublishTaskList(pubData_);
}