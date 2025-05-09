#include "welcome_mode.h"
#include "common/public_fun.h"
#include "robot_dog_main.h"

using namespace athena::function::action;

WelcomeMode::WelcomeMode(TaskType type)
  : ModeBase(type)
  , pubData_()
{
}

void WelcomeMode::Handle(const robot_dog::PercCmd& msg, MessageHandleManager* data_manager)
{
    data_manager->SetCanFinish(true);
    
    //状态更新
    {
        auto& stateResult = data_manager->GetStateMsg();
        stateResult.perc_kind = perception_msgs::PercCmd::PERC_WELCOME_DEMO;
        stateResult.action_id = msg.action_id;
    }
    
    
    pubData_.task_id = msg.action_id;
    pubData_.task_type = robot_dog::operations::TaskType::TASK_WELCOME;
    pubData_.target_object = msg.follow_name;
    
    printf("Welcome %s:", msg.follow_name.c_str());
    AfxGetApp()->PublishTaskList(pubData_);
}