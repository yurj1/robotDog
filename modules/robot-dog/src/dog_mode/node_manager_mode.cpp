#include "node_manager_mode.h"
#include "common/global_project.h"

using namespace athena::function::action;

NodeManagerMode::NodeManagerMode(TaskType t_type, NodeType n_type)
  : ModeBase(t_type)
  , pubData_()
  , n_type_(n_type)
{
}

void NodeManagerMode::Handle(const perception_msgs::PercCmd::ConstPtr& msg, RobotDogState* data_manager)
{
    
    //状态更新
    auto& stateResult = data_manager->GetStateMsg();
    stateResult.action_id = msg->action_id;
    data_manager->SetCanFinish(true);
    pubData_.task_id = msg->action_id;

    switch (n_type_)
    {
    case NodeManagerMode::NodeType::CLOSE:
        pubData_.task_type = perception_bridge::TaskType::TASK_NODE_CLOSE;
        stateResult.perc_kind = perception_msgs::PercState::PERC_NODE_CLOSE;
        break;
    case NodeManagerMode::NodeType::START:
        pubData_.task_type = perception_bridge::TaskType::TASK_NODE_START;
        stateResult.perc_kind = perception_msgs::PercState::PERC_NODE_START;
        break;
    case NodeManagerMode::NodeType::RESET:
        pubData_.task_type = perception_bridge::TaskType::TASK_NODE_RESET;
        stateResult.perc_kind = perception_msgs::PercState::PERC_NODE_RESET;
        break;
    default:
        AERROR << "node type is not parse";
        return;
        break;
    }

    AfjGetMain()->PublishTaskList(pubData_);
}