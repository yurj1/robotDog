#ifndef __ROBOT_DOG_PROJECT_H__
#define __ROBOT_DOG_PROJECT_H__
 
#include <memory>

#define SAFE_DELETE(x)    \
do {                      \
  if(x) {                 \
    delete (x);           \
    (x)=nullptr;          \
  }                       \
}while(0);

#define SAFE_DELETE_ARRAY(x)    \
do {                            \
  if(x) {                       \
    delete [](x);               \
    (x)=nullptr;                \
  }                             \
}while(0);


#define AppIsNotNull AfxGetApp() != nullptr

#define _AppGetMessageHandManager (AfxGetApp()->GetMessageHandleManager())
#define _AppIsMessageHandManagerNotNull (AppIsNotNull && _AppGetMessageHandManager != nullptr)
#define AppGetMessageHandManager() (_AppIsMessageHandManagerNotNull ? _AppGetMessageHandManager : nullptr)

#define _AppGetJoyService (AfxGetApp()->GetMessageHandleManager()->GetJoyService())
#define _AppIsJoyServiceNotNull (_AppIsMessageHandManagerNotNull &&  _AppGetJoyService != nullptr)
#define AppGetJoyService() (_AppIsJoyServiceNotNull ? _AppGetJoyService : nullptr)

#define _AppGetUnitreeService (AfxGetApp()->GetUnitreeMessageManager())
#define _AppIsUnitreeServiceNotNull (AppIsNotNull && _AppGetUnitreeService != nullptr)
#define AppGetUnitreeService() (_AppIsUnitreeServiceNotNull ? _AppGetUnitreeService : nullptr)

#define _AppGetVoiceService (AfxGetApp()->GetMessageHandleManager()->GetVoiceService())
#define _AppIsVideoServiceNotNull (_AppIsMessageHandManagerNotNull && _AppGetVoiceService != nullptr)
#define AppGetVoiceService() (_AppIsVideoServiceNotNull ? _AppGetVoiceService : nullptr)

#if MQTT_ENABLE
#define _AppGetMqttService (AfxGetApp()->GetMqttMessageManager())
#define _AppIsMqttServiceNotNull (AppIsNotNull && _AppGetMqttService != nullptr)
#define AppGetMqttService() (_AppIsMqttServiceNotNull ? _AppGetMqttService : nullptr)
#endif

namespace athena {
  namespace function {
    class RobotDogMain;
  }
}

athena::function::RobotDogMain*& AfxGetApp();

#endif //__ROBOT_DOG_PROJECT_H__