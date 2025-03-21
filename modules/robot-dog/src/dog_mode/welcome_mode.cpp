#include "welcome_mode.h"
#include "common/global_project.h"

using namespace athena::function::action;

WelcomeMode::WelcomeMode(TaskType type)
  : ModeBase(type)
  , pubData_()
{
}

void WelcomeMode::Handle(const perception_msgs::PercCmd::ConstPtr& msg, RobotDogState* data_manager)
{
    data_manager->SetCanFinish(true);
    
    //状态更新
    {
        auto& stateResult = data_manager->GetStateMsg();
        stateResult.perc_kind = perception_msgs::PercCmd::PERC_WELCOME_DEMO;
        stateResult.action_id = msg->action_id;
    }
    
    
    pubData_.task_id = msg->action_id;
    pubData_.task_type = robot_dog::operations::TaskType::TASK_WELCOME;
    pubData_.target_object = msg->follow_name;
    
    ROS_INFO("Welcome %s:", msg->follow_name.c_str());
    AfjGetMain()->PublishTaskList(pubData_);
}