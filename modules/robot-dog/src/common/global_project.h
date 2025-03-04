#ifndef __ROBOT_DOG_PROJECT_H__
#define __ROBOT_DOG_PROJECT_H__
#include "robot_dog_main.h"

#define AfjGetMain global::AGetMain
#define AfjGetMainNotNull global::AGetMain() != nullptr

namespace global
{
  std::shared_ptr<athena::function::RobotDogMain> AGetMain();
}
#endif //__ROBOT_DOG_PROJECT_H__