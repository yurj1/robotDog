#ifndef __NODE_MANAGER_MODE__H__
#define __NODE_MANAGER_MODE__H__
#include "base.h"

class NodeManagerMode : public ModeBase
{
public:
    enum class NodeType{
        CLOSE = 0,
        START,
        RESET,

        NONE = 9999
    };
    NodeManagerMode(NodeType type = NodeType::NONE);
    
    void Handle(const perception_msgs::PercCmd::ConstPtr& msg, RobotDogState* data_manager) override;
private:
    void Init()override{}
private:
    perception_msgs::TaskList pubData_;
    NodeType type_;
};

#endif //__NODE_MANAGER_MODE__H__