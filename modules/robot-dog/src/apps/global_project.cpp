#include "global_project.h"
namespace athena
{
  namespace function {
      std::shared_ptr<RobotDogMain> rMain;

      std::shared_ptr<RobotDogMain> AGetMain()
              {
                  if(rMain == nullptr)
                    rMain = std::make_shared<RobotDogMain>();
                  return rMain;
              }
  }
}