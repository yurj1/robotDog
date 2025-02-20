#include "global_project.h"
namespace athena
{
  namespace function {
        RobotDogMain* AGetMain()
                {
                    static RobotDogMain m;
                    return &m;
                }
  }
}