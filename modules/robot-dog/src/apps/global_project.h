#ifndef __ROBOT_DOG_PROJECT_H__
#define __ROBOT_DOG_PROJECT_H__
#include <robot_dog_main.h>

#define AfjGetMain athena::function::AGetMain
#define AfjGetMainNotNull athena::function::AGetMain() != nullptr

namespace athena
{
  namespace function {
        RobotDogMain* AGetMain();
  }
}
#endif //__ROBOT_DOG_PROJECT_H__