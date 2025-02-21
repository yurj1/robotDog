#include <apps/robot_dog_main.h>
#include "version/version.h"

#include <csignal>
// 全局标志位，用于控制主循环
volatile sig_atomic_t appRun = 1;
void signal_handler(int signal) {
    if (signal == SIGINT) { // 检查是否为 Ctrl+C 信号(SIGINT)
        AINFO << "Caught SIGINT, initiating graceful shutdown...";
        appRun = 0; // 设置标志位以退出程序循环
        // 终止程序
        std::exit(EXIT_SUCCESS);
    }
}

namespace athena
{
  namespace function {
    RobotDogMain::RobotDogMain(std::string file_path)
      : config_file_path_(file_path) 
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
            /* produce_emergency_stop_command_duration_ =
                roobt_dog_json_["produce_emergency_stop_command_duration"];
            publish_emergency_stop_command_duration_ =
                roobt_dog_json_["publish_emergency_stop_command_duration"]; */
            robot_dog_conf_->set_use_system_timestamp(
                roobt_dog_json_["use_system_timestamp"]);
          }

          // step6 故障码初始化
          // FaultMonitorInit();

          // step7 算法初始化
          {
            RobotDogMainStateMachineInit();
          }

          // step8 定时器和线程初始化
          {
            /* status_detect_duration_ = (uint32_t)(double)
                roobt_dog_json_["status"]["status_detect_duration"]; */

            ad_timer_manager_ = std::make_shared<ADTimerManager<RobotDogMain, void>>();
            task_1000ms_ =
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
      while (appRun)
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
      task_1000ms_->AddTimer(50, &RobotDogMain::StateCallback, this);//只有50hz
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
      PublishState(state_manager_.GetStateCallback()); // 发布状态
    }

    /* void RobotDogMain::PublishObuCmdMsg(int code, int val)
    {
      athena::interface::Header header;
      INTERFACE_HEADER_ASSIGN(obu_cmd_msg_output_)
      obu_cmd_msg_output_.set_id(4);
      obu_cmd_msg_output_.set_name("RobotDogMain");
      athena::interface::ObuCmd obu_cmd_;
      obu_cmd_.set_code(code);
      obu_cmd_.set_val(val);
      obu_cmd_msg_output_.clear_obu_cmd_list();
      obu_cmd_msg_output_.add_obu_cmd_list(obu_cmd_);
      PublishObuCmdMsgOutput(obu_cmd_msg_output_);
    } */

      /* void RobotDogMain::PublishObuCmdMsgOutput(
        athena::interface::ObuCmdMsg obu_cmd_msg_output)
    {
#if LCM_ENABLE
      if (message_manager_.count("LCM") > 0)
        message_manager_["LCM"]->PublishObuCmdMsgOutput(obu_cmd_msg_output);
#endif

#if ROS_ENABLE
      if (message_manager_.count("ROS") > 0)
        message_manager_["ROS"]->PublishObuCmdMsgOutput(obu_cmd_msg_output);
#endif

#if DDS_ENABLE
      if (message_manager_.count("DDS") > 0)
        message_manager_["DDS"]->PublishObuCmdMsgOutput(obu_cmd_msg_output);
#endif

#if ROS2_ENABLE
      if (message_manager_.count("ROS2") > 0)
        message_manager_["ROS2"]->PublishObuCmdMsgOutput(obu_cmd_msg_output);
#endif
    } 

    void RobotDogMain::PublishEvents(athena::interface::Events events)
    {
#if LCM_ENABLE
      if (message_manager_.count("LCM") > 0)
        message_manager_["LCM"]->PublishEventsOutput(events);
#endif

#if ROS_ENABLE
      if (message_manager_.count("ROS") > 0)
        message_manager_["ROS"]->PublishEventsOutput(events);
#endif

#if DDS_ENABLE
      if (message_manager_.count("DDS") > 0)
        message_manager_["DDS"]->PublishEventsOutput(events);
#endif

#if ROS2_ENABLE
      if (message_manager_.count("ROS2") > 0)
        message_manager_["ROS2"]->PublishEventsOutput(events);
#endif
    }*/

    std::shared_ptr<RobotDogConf> RobotDogMain::GetConf() const
    {
      return robot_dog_conf_;
    }
/*
    void RobotDogMain::HandleChassis(athena::interface::Chassis chassis)
    {
      if (is_init_ == false)
      {
        return;
      }
      if (function_activation_ == false)
      {
        return;
      }
      {
        std::lock_guard<std::mutex> lock(mutex_);
        if (robot_dog_conf_->use_system_timestamp() == true)
        {
          athena::interface::Header header = chassis.header();
          header.set_stamp(TimeTool::Now2TmeStruct());
          chassis.set_header(header);
        }
        chassis_ = chassis;
      }
    }

    void RobotDogMain::HandleEvents(athena::interface::Events events)
    {
      if (is_init_ == false)
      {
        return;
      }
      if (function_activation_ == false)
      {
        return;
      }
      {
        std::lock_guard<std::mutex> lock(mutex_);
        if (robot_dog_conf_->use_system_timestamp() == true)
        {
          athena::interface::Header header = events.header();
          header.set_stamp(TimeTool::Now2TmeStruct());
          events.set_header(header);
        }
        events_ = events;
      }
    }

    void RobotDogMain::HandleObuCmdMsgInput(
        athena::interface::ObuCmdMsg obu_cmd_msg_input)
    {
      if (is_init_ == false)
      {
        return;
      }
      if (function_activation_ == false)
      {
        return;
      }
      {
        std::lock_guard<std::mutex> lock(mutex_);
        if (robot_dog_conf_->use_system_timestamp() == true)
        {
          athena::interface::Header header = obu_cmd_msg_input.header();
          header.set_stamp(TimeTool::Now2TmeStruct());
          obu_cmd_msg_input.set_header(header);
        }
        obu_cmd_msg_input_ = obu_cmd_msg_input;
      }
      for (auto cmd : obu_cmd_msg_input_.obu_cmd_list())
      {
        std::cout << "code : " << cmd.code() << " val : " << cmd.val() << std::endl;
        // 急停按钮
        if (cmd.code() == (int)EmergencyModeCMD::CODE)
        {
          switch (cmd.val())
          {
          case (int)EmergencyModeCMD::VAL_ACTIVATE:
            // 急停按下
            emergency_stop_activation_ = true;
            break;
          case (int)EmergencyModeCMD::VAL_DEACTIVATE:
            // 急停解除
            emergency_stop_activation_ = false;
            break;
          default:
            emergency_stop_activation_ = false;
            break;
          }
        }
      }
    }
*/
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
          while (appRun)
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
      //感知数据初始化
      {
        task_list_perception_.task_id = 0;
        geometry_msgs::Pose pose;
        pose.position.x = 0;
        pose.position.y = 0;
        pose.position.z = 0;
        pose.orientation.x = 0;
        pose.orientation.y = 0;
        pose.orientation.z = 0;
        pose.orientation.w = 0;
        task_list_perception_.target_position = pose;
        task_list_perception_.target_object = "";
        task_list_perception_.task_state = perception_bridge::TaskState::STATE_IDLE;
        task_list_perception_.task_result = perception_bridge::TaskResult::RESULT_INVALID;
        task_list_perception_.isInPlaceRotation = false;
      }
      //规控数据初始化
      {
        task_list_planning_.task_id = 0;
        geometry_msgs::Pose pose;
        pose.position.x = 0;
        pose.position.y = 0;
        pose.position.z = 0;
        pose.orientation.x = 0;
        pose.orientation.y = 0;
        pose.orientation.z = 0;
        pose.orientation.w = 0;
        task_list_planning_.target_position = pose;
        task_list_planning_.target_object = "";
        task_list_planning_.task_state = perception_bridge::TaskState::STATE_IDLE;
        task_list_planning_.task_result = perception_bridge::TaskResult::RESULT_INVALID;
        task_list_planning_.isInPlaceRotation = false;
      } 
      //状态反馈初始化
      {
        perc_state_.action_id = 0;
        perc_state_.err_code = 0;
        perc_state_.exe_result = 0;
      }
        
      state_manager_.Init();
    }
      
    //处理集成消息
    void RobotDogMain::cmdCallback(const perception_msgs::PercCmd::ConstPtr& msg) {
        state_manager_.handleTaskEvent(msg);
    }
    //处理感知反馈消息
    void RobotDogMain::ptCallback(const perception_msgs::TaskList::ConstPtr& msg) {
        state_manager_.handlePerceptionEvent(msg);
    }
    //处理规划状态反馈消息
    void RobotDogMain::stateCallback(const perception_msgs::TaskList::ConstPtr& msg) {
        state_manager_.handleStateEvent(static_cast<TaskState>(msg->task_state), static_cast<TaskResult>(msg->task_result));
    }

  }
}