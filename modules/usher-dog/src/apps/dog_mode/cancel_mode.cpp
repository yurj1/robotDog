#include "cancel_mode.h"
#include "common/public_fun.h"
#include "robot_dog_main.h"

using namespace athena::function::action;

CancelMode::CancelMode(TaskType type)
  : ModeBase(type)
  , pubData_()
{
}

void CancelMode::Handle(const robot_dog::PercCmd& msg, MessageHandleManager* data_manager)
{
    //可直接完成
    data_manager->SetCanFinish(true);
    
    //状态更新
    auto& stateResult = data_manager->GetStateMsg();
    stateResult.perc_kind = robot_dog::operations::PercCmd::PERC_CANCEL;
    stateResult.action_id = msg.action_id;
    pubData_.task_id = msg.action_id;
    pubData_.task_type = robot_dog::operations::TaskType::TASK_CANCEL;
    
    printf("Cancel Task \n");
    AfxGetApp()->PublishTaskList(pubData_);
}