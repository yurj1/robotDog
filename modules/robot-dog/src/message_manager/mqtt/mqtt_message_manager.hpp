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
       client = std::make_shared<mqtt::async_client>(messages["MQTT"].url, "robot_dog_q1");
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
                           .mqtt_version(MQTTVERSION_3_1_1) // 指定协议版本为 3.1.1
                           .finalize();
 
       auto TOPICS = mqtt::string_collection::create({"jsx_remote_controller/#", sub_callback_to_cmd});
       const vector<int> QOS{1, 1};
 
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
    //  template <typename T>
    //  void MqttMessageManager<T>::HandleJoyMsg(JoyMessage msg)
    //  {
    //    //std::cout << "HandleJoyMsg " << std::endl;
    //    instance_->HandleMqttJoyMsgInput(msg);
    //  }
    template <typename T>
    void MqttMessageManager<T>::HandleTaskMsg(std::string msg)
    {
      try {
        std::cout << "recv sub_callback_to_cmd message: " << std::endl << msg << std::endl;
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

        if(_AppIsRosServiceNotNull)
        {
          _AppGetRosService->handleTaskEvent(cmd);
        }
      }
      catch (const nlohmann::json::exception& e) {
        // 捕获解析错误
        std::cerr << "Error parsing JSON: " << e.what() << std::endl;
      }
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
        std::cout << "listenTopic" << std::endl;
         auto msg = client->consume_message();
 
         if (!msg)
           continue;
        //  if (msg->get_topic() == GetTopic("jsx_remote_controller/joymsg"))
        //  {
        //    JoyMessage joymsg;
        //    // std::cout << "sub" << std::endl;
        //    joymsg.ParseFromString(msg->get_payload_str());
        //    HandleJoyMsg(joymsg);
        //  }
         //任务消息接受
         if (msg->get_topic() == sub_callback_to_cmd)
         {
          HandleTaskMsg(msg->get_payload_str());
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
 