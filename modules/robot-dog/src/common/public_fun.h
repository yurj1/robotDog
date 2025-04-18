#ifndef __ROBOT_DOG_PROJECT_H__
#define __ROBOT_DOG_PROJECT_H__
 
 #include <memory>

namespace athena {
  namespace function {
    class RobotDogMain;
  }
}

#define AppIsNotNull AfxGetApp() != nullptr

#define _AppGetMessageHandManager (AfxGetApp()->GetMessageHandleManager())
#define _AppIsMessageHandManagerNotNull (AppIsNotNull && _AppGetMessageHandManager != nullptr)
#define AppGetRosService() (_AppIsMessageHandManagerNotNull ? _AppGetMessageHandManager : nullptr)

#if MQTT_ENABLE
#define _AppGetMqttService (AfxGetApp()->GetMqttMessageManager())
#define _AppIsMqttServiceNotNull (AppIsNotNull && _AppGetMqttService != nullptr)
#define AppGetMqttService() (_AppIsMqttServiceNotNull ? _AppGetMqttService : nullptr)
#endif


athena::function::RobotDogMain*& AfxGetApp();

#endif //__ROBOT_DOG_PROJECT_H__