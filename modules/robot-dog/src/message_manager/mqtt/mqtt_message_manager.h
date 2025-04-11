/*
 * @Author: wqf 2549058524@qq.com
 * @Date: 2025-04-07 13:58:07
 * @LastEditors: wqf 2549058524@qq.com
 * @LastEditTime: 2025-04-07 18:36:27
 * @FilePath: /reboot_dog_remote/modules/jsx_remote_bridge/src/message_manager/mqtt/mqtt_message_manager.h
 * @Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
 */
/**
 * @file    lcm_message_manager.h
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

 #pragma once
 #if MQTT_ENABLE
 #include <thread>
 #include "mqtt/async_client.h"
 
 //#include "interface/MSG_V_1_0_0.pb.h"
 
 #include "message_manager/message_manager.h"
 
 /**
  * @namespace athena::jsx_remote_bridge
  * @brief athena::jsx_remote_bridge
  */
 
 namespace athena
 {
   namespace function
   {
     /**
      * @class MqttMessageManager
      * @brief  Mqtt消息管理器.
      */
     template <typename T>
     class MqttMessageManager : public MessageManager<T>
     {
     public:
       MqttMessageManager() = default;
       ~MqttMessageManager() = default;
 
       /**
        * @brief     初始化。
        * @param[in] obu_url LCM组播信息.
        * @return    void.
        */
       void Init(T *t) override;
 
       //void PublishJoyMsgOutput(athena::interface::JoyMsg msg) override;
       void PublishTaskList(perception_msgs::TaskList msg)override;
       void PublishPose(geometry_msgs::Pose msg)override;
       void PublishState(perception_msgs::PercState msg)override;
       void PublishAction(perception_msgs::ActionEntry msg)override;
       const std::map<std::string, geometry_msgs::Pose>& GetPointMap() override {return point_map_;};

    //    void PublishJoyMsgLoad(std_msgs::Float32 data)override;
    //    void PublishJoyMsgStandup(std_msgs::Float32 data)override;
    //    void PublishJoyMsgGetdown(std_msgs::Float32 data)override;
    //    void PublishJoyMsgStop(std_msgs::Float32 data)override;
       //void PublishJoyMsgTwist(geometry_msgs::Twist msg)override;
       
       bool Activate();
       bool DeActivate();
 
       string GetTopic(string topic);
       bool CheckTopic(string topic);
 
     protected:
       T *instance_;
       bool is_init_;
       bool is_active_;
       std::mutex mutex_;
 
       mqtt::async_client_ptr client;
       std::string VIN;
       
       std::unique_ptr<std::thread>
           handle_message_thread_;

       // 固定点映射表
       std::map<std::string, geometry_msgs::Pose> point_map_;
 
       /**
        * @brief     线程运行函数.
        * @return    void.
        */
       void Run();
       //void HandleJoyMsg(JoyMessage msg);
       void HandleTaskMsg(std::string msg);
       /**
        * @brief     线程结束函数.
        * @return    void.
        */
       void Stop();
 
     };
   } // namespace jsx_remote_bridge
 } // namespace athena
 #include "mqtt_message_manager.hpp"
 #endif
 