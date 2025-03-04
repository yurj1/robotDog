#include "global_project.h"
using namespace athena::function;
namespace global
{
  std::shared_ptr<RobotDogMain> AGetMain()
          {
            static std::shared_ptr<RobotDogMain> instance;
            
            if(instance == nullptr){
              instance = std::make_shared<RobotDogMain>();
            }
            return instance;
          }
}
