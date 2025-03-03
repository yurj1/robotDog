#ifndef __ROBOT_DOG_PROJECT_H__
#define __ROBOT_DOG_PROJECT_H__
#include "robot_dog_main.h"

#define AfjGetMain athena::common::AGetMain
#define AfjGetMainNotNull athena::common::AGetMain() != nullptr

namespace athena
{
  namespace common {
        std::shared_ptr<athena::function::RobotDogMain> AGetMain();
  }
}
#endif //__ROBOT_DOG_PROJECT_H__