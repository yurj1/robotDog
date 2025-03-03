#ifndef __NODE_MANAGER_MODE__H__
#define __NODE_MANAGER_MODE__H__
#include "mode_base.h"

namespace athena {
    namespace function {
        namespace action {
            class NodeManagerMode : public ModeBase
            {
            public:
                enum class NodeType{
                    CLOSE = 0,
                    START,
                    RESET
                };
                NodeManagerMode(TaskType t_type, NodeType n_type);
                
                void Handle(const perception_msgs::PercCmd::ConstPtr& msg, RobotDogState* data_manager) override;
            private:
                void Init()override{}
            private:
                perception_msgs::TaskList pubData_;
                NodeType n_type_;
            };
        }
    }
}

#endif //__NODE_MANAGER_MODE__H__