/**
 * @file    mqtt_message_manager.hpp
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

 #include "mqtt_message_manager.h"
 #include "common/public_fun.h"
 #include "modules/common/macros/macros.h"
 #include "modules/common/logging/logging.h"
 #include "modules/common/base_message/message.h"
 #include <common/json/json.hpp>
 //#include "modules/common/math/euler_angles_zxy.h"
 
 #if MQTT_ENABLE
 /**
  * @namespace athena::jsx_remote_bridge
  * @brief athena::jsx_remote_bridge
  */
using  Json = nlohmann::json;
 namespace athena
 {
  namespace function {
     using namespace athena::common;
     template <typename T>
     void MqttMessageManager<T>::Init(T *t)
     {
       is_init_ = false;
       is_active_ = false;
       instance_ = t;
 
       // const string DFLT_SERVER_ADDRESS{"mqtt://localhost:1883"};
       // const string CLIENT_ID{"paho_cpp_async_publish"};
       const string PERSIST_DIR{"./persist"};
 
       // string address = DFLT_SERVER_ADDRESS,
       //        clientID = CLIENT_ID;
 
       std::map<std::string, athena::common::Message> messages =
           instance_->GetConf()->messages();
       //VIN = instance_->GetVIN();
 
       string address = messages["MQTT"].url;
              //clientID = VIN;
 
       // client = std::make_shared<mqtt::async_client>(address, CLIENT_ID);
       client = std::make_shared<mqtt::async_client>(messages["MQTT"].url, instance_->GetJsonConfig()["ClientId"]);
       // auto sslopts = mqtt::ssl_options_builder()
       //                    .trust_store("/home/ywb/Documents/c++project/SLS/mqtt_certs/ca.crt")
       //                    .key_store("/home/ywb/Documents/c++project/SLS/mqtt_certs/client.crt")
       //                    .private_key("/home/ywb/Documents/c++project/SLS/mqtt_certs/client.key")
       //                    .verify(false)
       //                    .error_handler([](const std::string &msg)
       //                                   { std::cerr << "SSL Error: " << msg << std::endl; })
       //                    .finalize();
 
       auto connOpts = mqtt::connect_options_builder()
                           .user_name("hy")
                           .password("123")
                           .finalize();
 
       auto TOPICS = mqtt::string_collection::create({mqtt_joy_msg_sub, mqtt_task_list_sub, mqtt_function_request_sub});
       const vector<int> QOS{0, 1, 1};
 
       client->start_consuming();
 
       cout << "Connecting to the MQTT server at " << address << "..." << flush;
       auto rsp = client->connect(connOpts)->get_connect_response();
       cout << "OK!\n"
            << endl;
 
       if (!rsp.is_session_present())
         client->subscribe(TOPICS, QOS);
 
       // 线程执行开始
       handle_message_thread_.reset(new std::thread([this]
                                                    { Run(); }));
       if (handle_message_thread_ == nullptr)
       {
         AERROR << "Unable to create handle_message_thread thread.";
         return;
       }
       is_init_ = true;
     }
 
     template <typename T>
     bool MqttMessageManager<T>::Activate()
     {
       if (is_active_)
       {
         return false;
       }
       std::lock_guard<std::mutex> lock(mutex_);
       std::cout << "mqtt activate" << std::endl;
       is_active_ = true;
       return true;
     }
 
     template <typename T>
     bool MqttMessageManager<T>::DeActivate()
     {
       if (is_active_ == false)
       {
         return false;
       }
       std::lock_guard<std::mutex> lock(mutex_);
       is_active_ = false;
       std::cout << "mqtt deactivate" << std::endl;
       return true;
     }
 
     // template <typename T>
     // void MqttMessageManager<T>::PublishFaults(athena::interface::Faults msg)
     // {
     //   // client->publish("Server/V1/AUTO_DRIVE/DATA_REPORT-VEHICLE_STATUS/V001", msg.faults()[0].reason())->wait();
     // }
    //  template <typename T>
    //  void MqttMessageManager<T>::PublishJoyMsgOutput(athena::interface::JoyMsg msg)
    //  {
    //    // client->publish("Server/V1/AUTO_DRIVE/DATA_REPORT-VEHICLE_STATUS/V001", msg.faults()[0].reason())->wait();
    //  }
    //  template <typename T>
    //  void MqttMessageManager<T>::PublishJoyMsgTwist(geometry_msgs::Twist msg)
    //  {
    //    // client->publish("Server/V1/AUTO_DRIVE/DATA_REPORT-VEHICLE_STATUS/V001", msg.faults()[0].reason())->wait();
    //  }
    //  template <typename T>
    //  void MqttMessageManager<T>::PublishJoyMsgLoad(std_msgs::Float32 data)
    //  {
 
    //  }
    //  template <typename T>
    //  void MqttMessageManager<T>::PublishJoyMsgStandup(std_msgs::Float32 data)
    //  {
 
    //  }
    //  template <typename T>
    //  void MqttMessageManager<T>::PublishJoyMsgGetdown(std_msgs::Float32 data)
    //  {
 
    //  }
    //  template <typename T>
    //  void MqttMessageManager<T>::PublishJoyMsgStop(std_msgs::Float32 data)
    //  {
 
    //  }
     template <typename T>
     void MqttMessageManager<T>::PublishTaskList(perception_msgs::TaskList msg) {
       //_pubscriber[pub_perception_mode].publish(msg);
     }
     template <typename T>
     void MqttMessageManager<T>::PublishPose(geometry_msgs::Pose msg) {
       //_pubscriber[pub_goal_state_extern].publish(msg);
     }
     template <typename T>
     void MqttMessageManager<T>::PublishState(perception_msgs::PercState msg) {
       //_pubscriber[pub_feedback_to_cmd].publish(msg);
     }
     
     template <typename T>
     void MqttMessageManager<T>::PublishAction(perception_msgs::ActionEntry msg) {
       //_pubscriber[pub_action_info_to_cmd].publish(msg);
     }

     template <typename T>
     void MqttMessageManager<T>::PublishRecordBagCallbackInfo(const robot_dog::CallbackInfo& rsp)
     {
      if ( !client->is_connected()) return;

      Json msg;
      msg["success"] = rsp.success;
      msg["info"] = rsp.info;

      //client->publish("/robot_dog/record_bag/callback_msg",rsp, rsp.size(), 2); 
      client->publish(mqtt::make_message(mqtt_function_response_pub, msg.dump(), 2, false));//采用qos ==2 否则网络不稳定时多发会导致多次弹窗
     }

    template <typename T>
    void MqttMessageManager<T>::PublishCurrentPoint(const std::string& data)
    {
      if ( !client->is_connected()) return;
      client->publish(mqtt::make_message(mqtt_current_point_pub, data, 0, false));//采用qos ==2 否则网络不稳定时多发会导致多次弹窗
    }

    template <typename T>
    void MqttMessageManager<T>::PublishGlobalCloud(const std::string& data)
    {
      if ( !client->is_connected()) return;
      client->publish(mqtt::make_message(mqtt_global_cloud_pub, data, 0, false));//采用qos ==2 否则网络不稳定时多发会导致多次弹窗
    }

    template <typename T>
    void MqttMessageManager<T>::PublishPlanningPlan(const std::string& data)
    {
      if ( !client->is_connected()) return;
      client->publish(mqtt::make_message(mqtt_planning_plan_pub, data, 0, false));//采用qos ==2 否则网络不稳定时多发会导致多次弹窗
    }

    template <typename T>
    void MqttMessageManager<T>::PublishTaskPoint(const std::string& data)
    {
      if ( !client->is_connected()) return;
      client->publish(mqtt::make_message(mqtt_task_point_pub, data, 0, false));//采用qos ==2 否则网络不稳定时多发会导致多次弹窗
    }

    template <typename T>
    void MqttMessageManager<T>::HandleTaskMsg(const std::string& msg)
    {
      try {
        AINFO << "recv sub_callback_to_cmd message:\n" << msg;
        Json info = Json::parse(msg);
        robot_dog::PercCmd cmd;
        cmd.action_id = info["action_id"];
        cmd.angle = info["angle"];
        cmd.follow_name = info["follow_name"];
        cmd.on_off = info["on_off"];
        cmd.perc_kind = info["perc_kind"];
        cmd.point.x = info["point"]["x"];
        cmd.point.y = info["point"]["y"];
        cmd.point.z = info["point"]["z"];
        cmd.point_name = info["point_name"];
        cmd.req_id = info["req_id"];

        if(_AppIsMessageHandManagerNotNull)
        {
          _AppGetMessageHandManager->handleTaskEvent(cmd);
        }
      }
      catch (const nlohmann::json::exception& e) {
        // 捕获解析错误
        AERROR << "Error parsing JSON: " << e.what() << std::endl;
      }
    }

    template <typename T>
    void MqttMessageManager<T>::HandRecordBagMsg(const std::string& msg)
    {
      try {
        std::cout << "recv sub_callback_to_cmd message: " << std::endl << msg << std::endl;
        Json info = Json::parse(msg);
        robot_dog::RecordBag req;
        robot_dog::CallbackInfo rsp;
        req.bag_mode = info["bag_mode"];
        switch (req.bag_mode)
        {
          case 1 :
            req.bag_name =  info["bag_name"];
            req.topics = info["topics"].get<std::vector<std::string>>();
            break;
          case 2 :
            req.bash_name =  info["bash_name"];
            break;
          default:
            break;
        }

        if(_AppIsMessageHandManagerNotNull)
        {
          _AppGetMessageHandManager->recordBagCallback(req,rsp);
          PublishRecordBagCallbackInfo(rsp);
        }
      }
      catch (const nlohmann::json::exception& e) {
        // 捕获解析错误
        AERROR << "Error parsing JSON: " << e.what();
        AERROR << "msg json : " << msg;
      }
    }

    template <typename T>
    void MqttMessageManager<T>::HandleJoyMsg(const std::string& msg)
    {
      Json joy = Json::parse(msg);
      robot_dog::JoyInfo result;
      try {

        for(auto btn : joy["buttons"])
        {
            //AINFO << btn.get<int>();
            result.buttons.push_back(btn.get<int>());
        }

        for(auto axe : joy["axes"])
        {
            result.axes.push_back(axe.get<double>());
        }
      } catch (std::exception ex) {
        AINFO << " parse error: " <<ex.what();
          return false;
      }

      if(_AppIsMessageHandManagerNotNull)
        _AppGetMessageHandManager->HandleJoyMsg(result);
        
    }

     template <typename T>
     string MqttMessageManager<T>::GetTopic(string topic)
     {
       // instance_->GetVIN();
       // std::cout << "currentTopic===" << topic + instance_->GetVIN() << std::endl;
       //return topic + instance_->GetVIN();
       return "";
     }
 
     template <typename T>
     bool MqttMessageManager<T>::CheckTopic(string topic)
     {
       std::stringstream ss(topic);
       std::string item;
       std::vector<std::string> elems;
       while (std::getline(ss, item, '/'))
       {
         if (!item.empty())
         {
           elems.push_back(item);
         }
       }
       if (elems.back() == VIN)
       {
         return true;
       }
       else
       {
         return false;
       }
     }
 
     template <typename T>
     void MqttMessageManager<T>::Run()
     {
       while (true)
       {
        AINFO << "listenTopic";
         auto msg = client->consume_message();
 
         if (!msg)
           continue;

         //任务消息接受
         if (msg->get_topic() == mqtt_task_list_sub)
         {
          HandleTaskMsg(msg->get_payload_str());
         }
         //录包请求 会阻塞1s
         else if (msg->get_topic() == mqtt_function_request_sub)
         {
          HandRecordBagMsg(msg->get_payload_str());
         }
         //手柄信息
         else if(msg->get_topic() == mqtt_joy_msg_sub)
         {
          // JoyMessage joymsg;
          // joymsg.ParseFromString(msg->get_payload_str());
          // HandleJoyMsg(joymsg);
          HandleJoyMsg(msg->get_payload_str());
         }
         //std::cout << "recv mqtt message: " << msg->get_payload_str() <<  std::endl << "topic: " << msg->get_topic() <<  std::endl;
       }
      }
 
     template <typename T>
     void MqttMessageManager<T>::Stop()
     {
       if (handle_message_thread_ != nullptr && handle_message_thread_->joinable())
       {
         handle_message_thread_->join();
         handle_message_thread_.reset();
         AINFO << "handle_message_thread stopped [ok].";
       }
     }
    }//namespace function
 } // namespace athena
 #endif
 