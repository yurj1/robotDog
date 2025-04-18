#include <apps/robot_dog_main.h>
#include "version/version.h"

#include <csignal>
namespace global {
  // 全局标志位，用于控制主循环
  sig_atomic_t appRun = 1;
}

namespace athena
{
  namespace function 
  {
    RobotDogMain::RobotDogMain(std::string file_path)
      : config_file_path_(file_path)
      ,message_handle_manager_(nullptr)
    {
    }
      
    void RobotDogMain::Start()
    {
      // step1 初始化状态设置为false
      {
        is_init_ = false;
        function_activation_ = false;
      }

      // step2 变量初始化
      {
        VariableInit();
      }
      //std::cout << "perception_bridge_json_ is start : " << config_file_path_ << std::endl;
      // step3 配置文件初始化
      {
        std::ifstream in(config_file_path_);
        in >> roobt_dog_json_;
        if (roobt_dog_json_.is_null())
        {
          std::cout << "perception_bridge_json_ is null" << std::endl;
          return;
        }
      }

      // step4 日志初始化
      {
        LOGGING_INIT(robot_dog_conf_, roobt_dog_json_)
      }

      // step4 IPC初始化
      {
        MESSAGE_INIT(robot_dog_conf_, roobt_dog_json_)
      }

      // step5 读取配置文件
      {
        robot_dog_conf_->set_use_system_timestamp(
        roobt_dog_json_["use_system_timestamp"]);
      }

      // step6 故障码初始化
      // FaultMonitorInit();

      // step7 算法初始化
      {
        RobotDogMainStateMachineInit();
      }
      //step7.5 ros消息管理初始化
      {
        message_handle_manager_ = new MessageHandleManager();
      }
      

      // step8 定时器和线程初始化
      {

        ad_timer_manager_ = std::make_shared<ADTimerManager<RobotDogMain, void>>();
        task_1000ms_ =
            std::make_shared<WheelTimer<RobotDogMain, void>>(ad_timer_manager_);
        task_state_callback_ = 
            std::make_shared<WheelTimer<RobotDogMain, void>>(ad_timer_manager_);
        task_thread_.reset(new std::thread([this]
                                          { Spin(); }));
        if (task_thread_ == nullptr)
        {
          AERROR << "Unable to create task_thread_ thread.";
          return;
        }
      }
      // step9 初始化状态为true
      {
        is_init_ = true;
      }
      TaskActivate();

      Detach();
    }

    void RobotDogMain::Loop()
    {
      while (true)
      {
        std::cout << "\033[32m" << Version::GetVersion() <<  "\tDate: " << Version::GetCurrentDateTime() << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(30));
      }
      
    }

    void RobotDogMain::Join()
    {
      if (task_thread_ != nullptr /* && task_thread_->joinable() */)
      {
        task_thread_->join();
        task_thread_.reset();
        AINFO << "task_thread_ stopped [ok].";
      }
    }

    void RobotDogMain::Detach()
    {
      if (task_thread_ != nullptr /* && task_thread_->joinable() */)
      {
        task_thread_->detach();
      }
    }

    void RobotDogMain::Close()
    {
      if (task_thread_ != nullptr /* && task_thread_->joinable() */)
      {
        task_thread_.reset();
        AINFO << "task_thread_ stopped [ok].";
      }

    }

    void RobotDogMain::VariableInit()
    {
      robot_dog_conf_ = std::make_shared<RobotDogConf>();
      robot_dog_conf_sm = nullptr;
      clear();
    }

    void RobotDogMain::Print() {}

    void RobotDogMain::Log() {}

    void RobotDogMain::TaskActivate()
    {
      if (is_init_ == false)
      {
        return;
      }
      // IPC激活
      MessagesActivate();
      if (function_activation_)
      {
        return;
      }
      task_1000ms_->AddTimer(1000, &RobotDogMain::Task1000ms, this);
      task_state_callback_->AddTimer(50, &RobotDogMain::StateCallback, this);//50ms 1次 == 20hz
      // 所有定时器都使用高级定时器，方便激活和去激活。
      std::cout << "===================function activate=================="
                << std::endl;
      function_activation_ = true;
      return;
    }

    void RobotDogMain::TaskStop()
    {
      if (is_init_ == false)
      {
        return;
      }
      // IPC去激活
      MessagesDeActivate();
      if (!function_activation_)
      {
        return;
      }
      task_1000ms_->Stop();
      task_state_callback_->Stop();
      {
        // 清除所有内部计算的中间结果，保证回到刚init完的状态
      }
      std::cout << "******************function stop***************" << std::endl;
      function_activation_ = false;
      return;
    }

    void RobotDogMain::ResigerMessageManager(
        std::string name,
        std::shared_ptr<MessageManager<RobotDogMain>> message_manager)
    {
      message_manager_.insert(
          std::pair<std::string, std::shared_ptr<MessageManager<RobotDogMain>>>(
              name, message_manager));
    }

    void RobotDogMain::Task1000ms(void *param)
    {
      robot_dog_conf_sm->OnUpdate();
    }
    //按周期发布状态
    void RobotDogMain::StateCallback(void *param)
    {
      PublishState(message_handle_manager_->GetConstStateMsg()); // 发布状态
    }

    std::shared_ptr<RobotDogConf> RobotDogMain::GetConf() const
    {
      return robot_dog_conf_;
    }

    void RobotDogMain::PublishTaskList(perception_msgs::TaskList msg) {
#if LCM_ENABLE
      if (message_manager_.count("LCM") > 0)
        message_manager_["LCM"]->PublishTaskList(msg);
#endif

#if DDS_ENABLE
      if (message_manager_.count("DDS") > 0)
        message_manager_["DDS"]->PublishTaskList(msg);
#endif

#if ROS_ENABLE
      if (message_manager_.count("ROS") > 0)
        message_manager_["ROS"]->PublishTaskList(msg);
#endif  

#if ROS2_ENABLE
      if (message_manager_.count("ROS2") > 0)
        message_manager_["ROS2"]->PublishTaskList(msg);
#endif  
    }
    void RobotDogMain::PublishPose(geometry_msgs::Pose msg) {
#if LCM_ENABLE
      if (message_manager_.count("LCM") > 0)
        message_manager_["LCM"]->PublishPose(msg);
#endif

#if DDS_ENABLE
      if (message_manager_.count("DDS") > 0)
        message_manager_["DDS"]->PublishPose(msg);
#endif

#if ROS_ENABLE
      if (message_manager_.count("ROS") > 0)
        message_manager_["ROS"]->PublishPose(msg);
#endif  

#if ROS2_ENABLE
      if (message_manager_.count("ROS2") > 0)
        message_manager_["ROS2"]->PublishPose(msg);
#endif    
    }
    void RobotDogMain::PublishState(perception_msgs::PercState msg) {
#if LCM_ENABLE
      if (message_manager_.count("LCM") > 0)
        message_manager_["LCM"]->PublishState(msg);
#endif

#if DDS_ENABLE
      if (message_manager_.count("DDS") > 0)
        message_manager_["DDS"]->PublishState(msg);
#endif

#if ROS_ENABLE
      if (message_manager_.count("ROS") > 0)
        message_manager_["ROS"]->PublishState(msg);
#endif

#if ROS2_ENABLE
      if (message_manager_.count("ROS2") > 0)
        message_manager_["ROS2"]->PublishState(msg);
#endif
    }

    void RobotDogMain::PublishAction(perception_msgs::ActionEntry&msg) {
#if LCM_ENABLE
      if (message_manager_.count("LCM") > 0)
        message_manager_["LCM"]->PublishAction(msg);
#endif

#if DDS_ENABLE
      if (message_manager_.count("DDS") > 0)
        message_manager_["DDS"]->PublishAction(msg);
#endif

#if ROS_ENABLE
      if (message_manager_.count("ROS") > 0)
        message_manager_["ROS"]->PublishAction(msg);
#endif

#if ROS2_ENABLE
      if (message_manager_.count("ROS2") > 0)
        message_manager_["ROS2"]->PublishAction(msg);
#endif
    }

    void RobotDogMain::PublishJoyMsgTwist(geometry_msgs::Twist& msg) {
#if LCM_ENABLE
      if (message_manager_.count("LCM") > 0)
        message_manager_["LCM"]->PublishJoyMsgTwist(msg);
#endif

#if DDS_ENABLE
      if (message_manager_.count("DDS") > 0)
        message_manager_["DDS"]->PublishJoyMsgTwist(msg);
#endif

#if ROS_ENABLE
      if (message_manager_.count("ROS") > 0)
        message_manager_["ROS"]->PublishJoyMsgTwist(msg);
#endif

#if ROS2_ENABLE
      if (message_manager_.count("ROS2") > 0)
        message_manager_["ROS2"]->PublishJoyMsgTwist(msg);
#endif
    }

    void RobotDogMain::PublishJoyMsgLoad(std_msgs::Float32& msg) {
#if LCM_ENABLE
      if (message_manager_.count("LCM") > 0)
        message_manager_["LCM"]->PublishJoyMsgLoad(msg);
#endif

#if DDS_ENABLE
      if (message_manager_.count("DDS") > 0)
        message_manager_["DDS"]->PublishJoyMsgLoad(msg);
#endif

#if ROS_ENABLE
      if (message_manager_.count("ROS") > 0)
        message_manager_["ROS"]->PublishJoyMsgLoad(msg);
#endif

#if ROS2_ENABLE
      if (message_manager_.count("ROS2") > 0)
        message_manager_["ROS2"]->PublishJoyMsgLoad(msg);
#endif
    }

    void RobotDogMain::PublishJoyMsgStandup(std_msgs::Float32& msg) {
#if LCM_ENABLE
      if (message_manager_.count("LCM") > 0)
        message_manager_["LCM"]->PublishJoyMsgStandup(msg);
#endif

#if DDS_ENABLE
      if (message_manager_.count("DDS") > 0)
        message_manager_["DDS"]->PublishJoyMsgStandup(msg);
#endif

#if ROS_ENABLE
      if (message_manager_.count("ROS") > 0)
        message_manager_["ROS"]->PublishJoyMsgStandup(msg);
#endif

#if ROS2_ENABLE
      if (message_manager_.count("ROS2") > 0)
        message_manager_["ROS2"]->PublishJoyMsgStandup(msg);
#endif
    }

    void RobotDogMain::PublishJoyMsgGetdown(std_msgs::Float32& msg) {
#if LCM_ENABLE
      if (message_manager_.count("LCM") > 0)
        message_manager_["LCM"]->PublishJoyMsgGetdown(msg);
#endif

#if DDS_ENABLE
      if (message_manager_.count("DDS") > 0)
        message_manager_["DDS"]->PublishJoyMsgGetdown(msg);
#endif

#if ROS_ENABLE
      if (message_manager_.count("ROS") > 0)
        message_manager_["ROS"]->PublishJoyMsgGetdown(msg);
#endif

#if ROS2_ENABLE
      if (message_manager_.count("ROS2") > 0)
        message_manager_["ROS2"]->PublishJoyMsgGetdown(msg);
#endif
    }

    void RobotDogMain::PublishJoyMsgStop(std_msgs::Float32& msg) {
      #if LCM_ENABLE
            if (message_manager_.count("LCM") > 0)
              message_manager_["LCM"]->PublishJoyMsgStop(msg);
      #endif
      
      #if DDS_ENABLE
            if (message_manager_.count("DDS") > 0)
              message_manager_["DDS"]->PublishJoyMsgStop(msg);
      #endif
      
      #if ROS_ENABLE
            if (message_manager_.count("ROS") > 0)
              message_manager_["ROS"]->PublishJoyMsgStop(msg);
      #endif
      
      #if ROS2_ENABLE
            if (message_manager_.count("ROS2") > 0)
              message_manager_["ROS2"]->PublishJoyMsgStop(msg);
      #endif
          }
    
    const std::map<std::string, geometry_msgs::Pose>& RobotDogMain::GetPointMap()
    {
#if LCM_ENABLE
      if (message_manager_.count("LCM") > 0)
  return message_manager_["LCM"]->GetPointMap();
#endif

#if DDS_ENABLE
      if (message_manager_.count("DDS") > 0)
        return message_manager_["DDS"]->GetPointMap();
#endif

#if ROS_ENABLE
      if (message_manager_.count("ROS") > 0)
        return message_manager_["ROS"]->GetPointMap();
#endif

#if ROS2_ENABLE
      if (message_manager_.count("ROS2") > 0)
        return message_manager_["ROS2"]->GetPointMap();
#endif
      return std::map<std::string, geometry_msgs::Pose>();
    }

    void RobotDogMain::MessagesInit()
    {
      if (robot_dog_conf_ == nullptr)
        return;

      std::map<std::string, athena::common::Message>::iterator iter;
      for (auto &iter : robot_dog_conf_->messages())
      {
        auto message = iter.second;

        switch (message.type)
        {
#if LCM_ENABLE
        case athena::common::MessageType::LCM:
        {
          AINFO << "message type:LCM";

          lcm_message_manager_ =
              std::make_shared<LcmMessageManager<RobotDogMain>>();
          ResigerMessageManager(message.name, lcm_message_manager_);

          lcm_message_manager_->Init(this);
        }
        break;
#endif
#if DDS_ENABLE
        case athena::common::MessageType::DDS:
        {
          AINFO << "message type:DDS";

          dds_message_manager_ =
              std::make_shared<DdsMessageManager<RobotDogMain>>();
          ResigerMessageManager(message.name, dds_message_manager_);

          dds_message_manager_->Init(this);
        }
        break;
#endif
#if ROS_ENABLE
        case athena::common::MessageType::ROS:
        {
            AINFO << "message type:ROS";

          ros_message_manager_ =
              std::make_shared<RosMessageManager<RobotDogMain>>();
          ResigerMessageManager(message.name, ros_message_manager_);
          ros_message_manager_->Init(this);
        }
        break;
#endif
#if ROS2_ENABLE
        case athena::common::MessageType::ROS2:
        {
          AINFO << "message type:ROS2";

          ros2_message_manager_ =
              std::make_shared<Ros2MessageManager<RobotDogMain>>();
          ResigerMessageManager(message.name, ros2_message_manager_);

          ros2_message_manager_->Init(this);
        }
        break;
#endif

#if ADSFI_ENABLE
        case athena::common::MessageType::ADSFI:
        {
          AINFO << "message type:ADSFI";

          adsfi_message_manager_ =
              std::make_shared<AdsfiMessageManager<RobotDogMain>>();
          ResigerMessageManager(message.name, adsfi_message_manager_);

          adsfi_message_manager_->Init(this);
        }
        break;
#endif

#if MQTT_ENABLE
        case athena::common::MessageType::MQTT:
        {
          AINFO << "message type:MQTT";

          mqtt_message_manager_ =
              std::make_shared<MqttMessageManager<RobotDogMain>>();
          ResigerMessageManager(message.name, mqtt_message_manager_);

          mqtt_message_manager_->Init(this);
        }
        break;
#endif
        default:
        {
          AERROR << "unknown message type";
        }
        break;
        }
      }
    }

    void RobotDogMain::MessagesActivate()
    {
      if (robot_dog_conf_ == nullptr)
      {
        return;
      }
      for (auto message_manager : message_manager_)
      {
        //message_manager.second->Activate();
      }
      return;
    }

    void RobotDogMain::MessagesDeActivate()
    {
      if (robot_dog_conf_ == nullptr)
      {
        return;
      }
      for (auto message_manager : message_manager_)
      {
        //message_manager.second->DeActivate();
      }
      return;
    }

    void RobotDogMain::Spin()
        {
          while (true)
          {
            if (function_activation_)
            {
              ad_timer_manager_->DetectTimers(NULL);
              usleep(1000);
            }
            else
              usleep(100000);
          }
        }

    void RobotDogMain::clear() {
      if(message_handle_manager_) message_handle_manager_->Init();
    }
      
    //处理集成消息
    void RobotDogMain::cmdCallback(const robot_dog::PercCmd& msg) {
        message_handle_manager_->handleTaskEvent(msg);
    }
    //处理感知反馈消息
    void RobotDogMain::ptCallback(const perception_msgs::TaskList::ConstPtr& msg) {
        message_handle_manager_->handlePerceptionEvent(msg);
    }
    //处理规划状态反馈消息
    void RobotDogMain::stateCallback(const perception_msgs::TaskList::ConstPtr& msg) {
        message_handle_manager_->handleStateEvent(msg);
    }

  }
}