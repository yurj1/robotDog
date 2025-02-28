#ifndef __BASE__H__
#define __BASE__H__
#include "manager/robot_dog_state_manager.h"

class ModeBase
{
public:
    virtual void Handle(const perception_msgs::PercCmd::ConstPtr& msg, RobotDogState* data_manager) = 0;
private:
    virtual void Init() = 0;
};

#endif