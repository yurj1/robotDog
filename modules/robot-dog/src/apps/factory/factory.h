#ifndef __FACTORY__H__
#define __FACTORY__H__

#include <perception_msgs/PercCmd.h>

#include "dog_mode/mode_base.h"

class Factory
{
public:
    //模式工厂： 固定点、找人等模式
    static std::shared_ptr<athena::function::action::ModeBase> CreateModeFactory(const uint32_t& mode);
};

#endif //__FACTORY__H__