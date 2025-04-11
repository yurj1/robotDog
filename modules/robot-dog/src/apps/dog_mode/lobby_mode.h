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
                void Handle(const robot_dog::PercCmd& msg, MessageHandleManager* data_manager) override;
            private:
                void Init()override{}
            };
        }
    }
}

#endif //__LOBBY_MODE__H__