#include "node_manager_mode.h"
#include "common/public_fun.h"
#include "robot_dog_main.h"

using namespace athena::function::action;

NodeManagerMode::NodeManagerMode(TaskType t_type, NodeType n_type)
  : ModeBase(t_type)
  , pubData_()
  , n_type_(n_type)
{
}

void NodeManagerMode::Handle(const robot_dog::PercCmd& msg, MessageHandleManager* data_manager)
{
    
    //状态更新
    auto& stateResult = data_manager->GetStateMsg();
    stateResult.action_id = msg.action_id;
    data_manager->SetCanFinish(true);
    pubData_.task_id = msg.action_id;

    switch (n_type_)
    {
    case NodeManagerMode::NodeType::CLOSE:
        pubData_.task_type = robot_dog::operations::TaskType::TASK_NODE_CLOSE;
        stateResult.perc_kind = robot_dog::operations::PercCmd::PERC_NODE_CLOSE;
        break;
    case NodeManagerMode::NodeType::START:
        pubData_.task_type = robot_dog::operations::TaskType::TASK_NODE_START;
        stateResult.perc_kind = robot_dog::operations::PercCmd::PERC_NODE_START;
        break;
    case NodeManagerMode::NodeType::RESET:
        pubData_.task_type = robot_dog::operations::TaskType::TASK_NODE_RESET;
        stateResult.perc_kind = robot_dog::operations::PercCmd::PERC_NODE_RESET;
        break;
    default:
        AERROR << "node type is not parse";
        return;
        break;
    }

    AfxGetApp()->PublishTaskList(pubData_);
}