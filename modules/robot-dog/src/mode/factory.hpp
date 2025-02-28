#ifndef __FACTORY__H__
#define __FACTORY__H__

#include <perception_msgs/PercCmd.h>
#include "dest_mode.h"
#include "cancel_mode.h"
#include "follow_mode.h"
#include "welcome_mode.h"
#include "lobby_mode.h"
#include "node_manager_mode.h"

class Factory
{
public:
    static std::shared_ptr<ModeBase> CreateModeFactory(const uint32_t& mode)
    {
        switch(mode)
        {
            case perception_msgs::PercCmd::PERC_DEST : 
                return std::make_shared<DestMode>();
                break;
            case perception_msgs::PercCmd::PERC_CANCEL :
                return std::make_shared<CancelMode>();
                break;
            case perception_msgs::PercCmd::PERC_FOLLOW :
                return std::make_shared<FollowMode>();
                break;
            case perception_msgs::PercCmd::PERC_WELCOME_DEMO :
                return std::make_shared<WelcomeMode>();
            case perception_msgs::PercCmd::PERC_LOBBY_DEMO :
                return std::make_shared<LobbyMode>();
            case perception_msgs::PercCmd::PERC_NODE_CLOSE :
                return std::make_shared<NodeManagerMode>(NodeManagerMode::NodeType::CLOSE);
            case perception_msgs::PercCmd::PERC_NODE_START :
                return std::make_shared<NodeManagerMode>(NodeManagerMode::NodeType::START);
            case perception_msgs::PercCmd::PERC_NODE_RESET :
                return std::make_shared<NodeManagerMode>(NodeManagerMode::NodeType::RESET);
            default :
            break;
        }
    }
};


#endif //__FACTORY__H__