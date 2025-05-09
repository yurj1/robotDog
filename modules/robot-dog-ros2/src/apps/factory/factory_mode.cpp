#include "factory.h"
#include "dog_mode/dest_mode.h"
#include "dog_mode/cancel_mode.h"
#include "dog_mode/follow_mode.h"
#include "dog_mode/welcome_mode.h"
#include "dog_mode/lobby_mode.h"
#include "dog_mode/node_manager_mode.h"

using namespace athena::function::action;

std::shared_ptr<ModeBase> Factory::CreateModeFactory(const uint32_t& mode)
    {
        switch(mode)
        {
            case robot_dog::operations::PercCmd::PERC_DEST : 
                return std::make_shared<DestMode>(TaskType::TASK_NAVIGATION);
                break;
            case robot_dog::operations::PercCmd::PERC_CANCEL :
                return std::make_shared<CancelMode>(TaskType::TASK_CANCEL);
                break;
            case robot_dog::operations::PercCmd::PERC_FOLLOW :
                return std::make_shared<FollowMode>(TaskType::TASK_FOLLOW);
                break;
            case robot_dog::operations::PercCmd::PERC_WELCOME_DEMO :
                return std::make_shared<WelcomeMode>(TaskType::TASK_WELCOME);
            case robot_dog::operations::PercCmd::PERC_LOBBY_DEMO :
                return std::make_shared<LobbyMode>(TaskType::TASK_LOBBY);
            case robot_dog::operations::PercCmd::PERC_NODE_CLOSE :
                return std::make_shared<NodeManagerMode>(TaskType::TASK_NODE_CLOSE, NodeManagerMode::NodeType::CLOSE);
            case robot_dog::operations::PercCmd::PERC_NODE_START :
                return std::make_shared<NodeManagerMode>(TaskType::TASK_NODE_START, NodeManagerMode::NodeType::START);
            case robot_dog::operations::PercCmd::PERC_NODE_RESET :
                return std::make_shared<NodeManagerMode>(TaskType::TASK_NODE_RESET, NodeManagerMode::NodeType::RESET);
            default :
            break;
        }
    }