#ifndef __BASE__H__
#define __BASE__H__
#include "common/struct/CommonStruct.h"
#include "manager/message_handle_manager.h"

#include <cstdio>  // printf

namespace athena {
    namespace function {
        namespace action {
            class ModeBase
            {
                
            public:
                typedef robot_dog::operations::TaskType TaskType;

                ModeBase(TaskType type)
                : type_(type){}
                virtual void Handle(const robot_dog::PercCmd& msg, MessageHandleManager* data_manager) = 0;
                TaskType GetType(){return type_;}
            protected:
                virtual void Init() = 0;

                TaskType type_;
            };

        }
    }
}


#endif