#ifndef __BASE__H__
#define __BASE__H__
#include "manager/ros_service_manager.h"

namespace athena {
    namespace function {
        namespace action {
            class ModeBase
            {
                
            public:
                typedef robot_dog::operations::TaskType TaskType;

                ModeBase(TaskType type)
                : type_(type){}
                virtual void Handle(const perception_msgs::PercCmd::ConstPtr& msg, RosServiceManager* data_manager) = 0;
                TaskType GetType(){return type_;}
            protected:
                virtual void Init() = 0;

                TaskType type_;
            };

        }
    }
}


#endif