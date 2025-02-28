#ifndef __FOLLOW_MODE__H__
#define __FOLLOW_MODE__H__
#include "base.h"

class FollowMode : public ModeBase
{
public:
    FollowMode();
    void Handle(const perception_msgs::PercCmd::ConstPtr& msg, RobotDogState* data_manager) override;
private:
    void Init()override{}
private:
    perception_msgs::TaskList pubData_;
};

#endif //__FOLLOW_MODE__H__