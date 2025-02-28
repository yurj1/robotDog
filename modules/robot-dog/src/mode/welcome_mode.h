#ifndef __WELCOME_MODE__H__
#define __WELCOME_MODE__H__
#include "base.h"

class WelcomeMode : public ModeBase
{
public:
    WelcomeMode();
    void Handle(const perception_msgs::PercCmd::ConstPtr& msg, RobotDogState* data_manager) override;
private:
    void Init()override{}
private:
    perception_msgs::TaskList pubData_;
};

#endif //__WELCOME_MODE__H__