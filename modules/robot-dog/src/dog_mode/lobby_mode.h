#ifndef __LOBBY_MODE__H__
#define __LOBBY_MODE__H__
#include "mode_base.h"

namespace athena {
    namespace function {
        namespace action {
            class LobbyMode : public ModeBase
            {
            public:
                LobbyMode(TaskType type);
                void Handle(const perception_msgs::PercCmd::ConstPtr& msg, RobotDogState* data_manager) override;
            private:
                void Init()override{}
            private:
                perception_msgs::TaskList task_list_perception_;
                perception_msgs::TaskList task_list_planning_;
            };
        }
    }
}

#endif //__LOBBY_MODE__H__