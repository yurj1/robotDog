#ifndef __FOLLOW_MODE__H__
#define __FOLLOW_MODE__H__
#include "mode_base.h"

namespace athena {
    namespace function {
        namespace action {
            class FollowMode : public ModeBase
            {
            public:
                FollowMode(TaskType type);
                void Handle(const perception_msgs::PercCmd::ConstPtr& msg, RosServiceManager* data_manager) override;
            private:
                void Init()override{}
            private:
                perception_msgs::TaskList pubData_;
            };
        }
    }
}

#endif //__FOLLOW_MODE__H__