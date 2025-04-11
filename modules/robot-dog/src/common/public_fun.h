#ifndef __ROBOT_DOG_PROJECT_H__
#define __ROBOT_DOG_PROJECT_H__
 
 #include <memory>

namespace athena {
  namespace function {
    class RobotDogMain;
  }
}

#define AppIsNotNull AfxGetApp() != nullptr

#define _AppGetRosService (AfxGetApp()->GetRosServiceManager())
#define _AppIsRosServiceNotNull (AppIsNotNull && _AppGetRosService != nullptr)
#define AppGetRosService() (_AppIsRosServiceNotNull ? _AppGetRosService : nullptr)

athena::function::RobotDogMain*& AfxGetApp();

#endif //__ROBOT_DOG_PROJECT_H__