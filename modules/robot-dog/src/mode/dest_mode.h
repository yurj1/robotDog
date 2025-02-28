#ifndef __DEST_MODE__H__
#define __DEST_MODE__H__
#include "base.h"

class DestMode : public ModeBase
{
public:
    DestMode();
    void Handle(const perception_msgs::PercCmd::ConstPtr& msg, RobotDogState* data_manager) override;
private:
    void Init()override;
private:
    perception_msgs::TaskList pubData_;
};

#endif //__DEST_MODE__H__