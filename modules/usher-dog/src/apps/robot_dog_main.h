#ifndef __PERCEPTION_BRIDGE_H__
#define __PERCEPTION_BRIDGE_H__

#include <mutex>
#include <thread>
#include <iomanip>

#include "modules/common/json/json.hpp"
#include "modules/common/status/status.h"
#include "modules/common/logging/logging.h"
#include "modules/common/state_machine/state_context.hpp"
#include "modules/common/state_machine/state_flags.hpp"
#include "modules/common/state_machine/state.hpp"
#include "modules/common/timer/timer_manager.h"
#include "modules/common/fault/fault_client.hpp"
#include "modules/common/timer/ad_timer_manager.h"
#include "modules/common/base_message/message_status.hpp"
#include "modules/common/base_message/message_status.hpp"

#if LCM_ENABLE
#include "message_manager/lcm/lcm_message_manager.h"
#endif
#if DDS_ENABLE
#include "message_manager/dds/dds_message_manager.h"
#endif
#if ROS_ENABLE
#include "message_manager/ros/ros_message_manager.h"
#endif
#if ROS2_ENABLE
#include "message_manager/ros2/ros2_message_manager.h"
#endif
#if MQTT_ENABLE
#include "message_manager/mqtt/mqtt_message_manager.h"
#endif

#include "conf/robot_dog_conf.hpp"
class UnitreeSdkService;
class MessageHandleManager;
namespace athena
{
  namespace function {
    using namespace athena::common;
    using json = nlohmann::json;

    class RobotDogMain {
    public:
    RobotDogMain(std::string file_path = "./conf/function/robot-dog/robot_dog.json");
    ~RobotDogMain() = default;
      /**
       * @brief     初始化．
       * @param[in] void．
       * @return    void.
       */
      void Start();

      /**
       * @brief     loop
       * @param[in] void．
       * @return    void.
       */
      void Loop();

      /**
       * @brief     join．
       * @param[in] void.
       * @return    void.
       */
      void Join();

      /**
       * @brief     Close.
       * @param[in] void.
       * @return    void.
       */
      void Close();

      /**
       * @brief     detach．
       * @param[in] void.
       * @return    void.
       */
      void Detach();

      /**
       * @brief Get the Conf object
       * @return std::shared_ptr<RobotDogConf>
       */
      std::shared_ptr<RobotDogConf> GetConf() const;
      const json& GetJsonConfig()const{return roobt_dog_json_;}
      const std::map<std::string, robot_dog::Position>& GetPointMap(){return point_map_;}
      const std::map<std::string, int>& GetVoiceMap(){return voice_map_;}
      // 初始化待传参数
      void clear();

    protected:
      // 初始化状态
      bool is_init_;
      // 配置文件路径
      std::string config_file_path_;
      // 配置文件操作类
      json roobt_dog_json_;
      // 控制逻辑设置
      std::shared_ptr<RobotDogConf> robot_dog_conf_;
      // 消息控制器
      std::map<std::string, std::shared_ptr<MessageManager<RobotDogMain>>>
          message_manager_;
      //点名名字映射坐标集合
      std::map<std::string, robot_dog::Position> point_map_;
      //点名名字映射语音code集合
      std::map<std::string, int> voice_map_;
      //目标点生效半径
      int within_target_radius_;
      //狗的当前位置信息
      robot_dog::Pose current_point_;
      // ros消息管理器
      MessageHandleManager* message_handle_manager_;
      //unitree sdk 消息获取
      UnitreeSdkService* unitree_sdk_service_;
    #if LCM_ENABLE
      std::shared_ptr<LcmMessageManager<RobotDogMain>> lcm_message_manager_;
    #endif
    #if DDS_ENABLE
          // DDS消息控制器
          std::shared_ptr<DdsMessageManager<RobotDogMain>> dds_message_manager_;
    #endif
    #if ROS_ENABLE
          std::shared_ptr<RosMessageManager<RobotDogMain>> ros_message_manager_;
    #endif
    #if ROS2_ENABLE
          std::shared_ptr<Ros2MessageManager<RobotDogMain>> ros2_message_manager_;
    #endif
    #if ADSFI_ENABLE
          std::shared_ptr<AdsfiMessageManager<RobotDogMain>> adsfi_message_manager_;
    #endif
    #if MQTT_ENABLE
          std::shared_ptr<MqttMessageManager<RobotDogMain>> mqtt_message_manager_;
    #endif

    protected:
      /**
       * @brief     注册消息控制器.
       * @param[in] message_manager　消息控制器对象指针.
       * @return    void.
       */
      void ResigerMessageManager(
          std::string name,
          std::shared_ptr<MessageManager<RobotDogMain>> message_manager);

      /**
       * @brief
       *
       */
      void VariableInit();

      /**
       * @brief     消息初始化.
       * @return    void.
       */
      void MessagesInit();

      /**
       * @brief     消息激活.
       * @return    void.
       */
      void MessagesActivate();

      /**
       * @brief     消息去激活.
       * @return    void.
       */
      void MessagesDeActivate();

      /**
       * @brief 定时器任务激活
       */
      void TaskActivate();

      /**
       * @brief 定时器任务停止
       */
      void TaskStop();

      /**
       * @brief 故障码监控初始化
       */
      //void FaultMonitorInit();

      /**
       * @brief 周期发送状态到集成,以及广播robot_dog状态
       * @return void.
       */
      void Task1000ms(void *param);
      void on_check_arrival_callback(void *param);
      /**
       * @brief     打印调试.
       * @return    void.
       */
      void Print();

      /**
       * @brief     日志调试.
       * @return    void.
       */
      void Log();

      bool IsArrival(const  robot_dog::Position& p, float threshold = 0.1);
      bool IsArrival(const  robot_dog::Pose& p, float threshold = 0.1);

    public:
      //dog position
      void SetCurrrentPoint(const robot_dog::Pose& point);
      const robot_dog::Pose& GetCurrentPoint() { return current_point_; }
      // 处理集成消息
      void cmdCallback(const robot_dog::PercCmd& msg);
      // 处理感知反馈消息
      void ptCallback(const robot_dog::TaskList& msg);
      // 处理规划状态反馈消息
      void stateCallback(const robot_dog::TaskList& msg);

      void PublishTaskList(const robot_dog::TaskList& msg);
      void PublishPose(const robot_dog::Position& msg);
      void PublishState(const robot_dog::PercState& msg);
      void PublishAction(const robot_dog::ActionEntry& msg);
      void PublishVideoOnInt(const std::vector<robot_dog::ObuCmd>& msg);
      void PublishVideoOnString(const std::vector<robot_dog::Event>& msg);

      MessageHandleManager* GetMessageHandleManager(){ return message_handle_manager_; }
      UnitreeSdkService* GetUnitreeMessageManager(){ return unitree_sdk_service_; }

#if MQTT_ENABLE
      std::shared_ptr<MqttMessageManager<RobotDogMain>> GetMqttMessageManager(){ return mqtt_message_manager_; };
#endif

    protected:
      /**
       * @brief     状态机初始化.
       */
      bool RobotDogMainStateMachineInit();
      /**
       * @brief     空闲状态.
       */
      void IdleStateUpdate(const std::string &state_name, int state);
      /**
       * @brief     任务执行中状态.
       */
      void RunningStateUpdate(const std::string &state_name, int state);
      /**
       * @brief     完成状态.
       */
      void FinishStateUpdate(const std::string &state_name, int state);

    private:
      std::unique_ptr<state_machine::StateContext> robot_dog_conf_sm;

    protected:
      //athena::interface::FaultCodeSet *faultcodeset_;
      // 功能激活状态,激活为true，未激活为false
      bool function_activation_;
      // 消息状态
      std::map<std::string, MessageStatus> message_status_;
      // task线程
      std::unique_ptr<std::thread> task_thread_;

      std::mutex mutex_;

    protected:
      // 定时器
      std::shared_ptr<ADTimerManager<RobotDogMain, void>> ad_timer_manager_;
      std::shared_ptr<WheelTimer<RobotDogMain, void>> state_machine_loop_timer_;
      std::shared_ptr<WheelTimer<RobotDogMain, void>> check_arrival_timer_;;
      
      /**
       * @brief     Spin．
       * @param[in] void.
       * @return    void.
       */
      void Spin();
    };
  }
}
#endif