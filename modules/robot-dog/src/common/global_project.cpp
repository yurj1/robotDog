#include "global_project.h"

namespace athena
{
  namespace common {
      std::shared_ptr<athena::function::RobotDogMain> AGetMain()
              {
                static std::shared_ptr<athena::function::RobotDogMain> instance;
                
                if(instance == nullptr){
                  instance = std::make_shared<athena::function::RobotDogMain>();
                }
                return instance;
              }
  }
}