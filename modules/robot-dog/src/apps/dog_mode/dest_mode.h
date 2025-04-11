#ifndef __DEST_MODE__H__
#define __DEST_MODE__H__
#include "mode_base.h"

namespace athena {
    namespace function {
        namespace action {
            class DestMode : public ModeBase
            {
            public:
                DestMode(TaskType type);
                void Handle(const robot_dog::PercCmd& msg, RosServiceManager* data_manager) override;
            private:
                void Init()override;
            private:
                perception_msgs::TaskList pubData_;
            };
        }
    }
}

#endif //__DEST_MODE__H__