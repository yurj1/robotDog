/**
 * @file    ros_message_manager.h
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#pragma once
#if ROS_ENABLE
#include <thread>

#include <ros/ros.h>
#include <rosbag/bag.h>
#include <rosbag/recorder.h>
#include <tf/transform_datatypes.h>  // 包含转换函数

#include "ros_interface/Events.h"
#include "ros_interface/ObuCmdMsg.h"

#include "message_manager/message_manager.h"

/**
 * @namespace athena::function
 * @brief athena::function
 */

namespace athena {
namespace function {
/**
 * @class RosMessageManager
 * @brief ROS消息管理器.
 */
template <typename T> class RosMessageManager : public MessageManager<T> {
public:
  RosMessageManager() = default;
  ~RosMessageManager() = default;

  /**
   * @brief     初始化。
   * @param[in] obu_url LCM组播信息.
   * @return    void.
   */
  void Init(T* t) override;

  /**
   * @brief     ObuCmdMsg消息发布.
   * @param[in] obu_cmd_msg.
   * @return    void.
   */
  void PublishTaskList(robot_dog::TaskList msg)override;
  void PublishPose(robot_dog::Position msg)override;
  void PublishState(robot_dog::PercState msg)override;
  void PublishAction(robot_dog::ActionEntry msg)override;
  void PublishVideoOnInt(const robot_dog::ObuCmdMsg& msg)override;
  void PublishVideoOnString(const std::vector<robot_dog::Event>& msg)override;
  //joy
  // void PublishJoyMsgTwist(geometry_msgs::Twist msg) override;
  // void PublishJoyMsgLoad(std_msgs::Float32 data) override;
  // void PublishJoyMsgStandup(std_msgs::Float32 data) override;
  // void PublishJoyMsgGetdown(std_msgs::Float32 data) override;
  // void PublishJoyMsgStop(std_msgs::Float32 data) override;
  //录包服务
  bool recordBagCallback(perception_msgs::DogRecordBag::Request &req, perception_msgs::DogRecordBag::Response &rsp);

  // const std::map<std::string, geometry_msgs::Pose>& GetPointMap() override{
  //   return point_map_;
  // }
protected:
  //void loadPointMap();
  // 处理集成消息
  void cmdCallback(const perception_msgs::PercCmd::ConstPtr& msg);
  // 处理感知反馈消息
  void ptCallback(const perception_msgs::TaskList::ConstPtr& msg);
  // 处理规划状态反馈消息
  void stateCallback(const perception_msgs::TaskList::ConstPtr& msg);
  void obuCallback(const ros_interface::ObuCmdMsg& msg_obj);
  
  void handleCurrentPoint(const nav_msgs::Odometry& msg);
  void handleCurrentPlan(const quad_msgs::RobotPlan& msg);
  void handleCurrentglobalCloud(const visualization_msgs::MarkerArray& msg);
  void handleCurrentTaskPoint(const geometry_msgs::Pose& msg);
  
protected:
  T* instance_;
  bool is_init_;
  std::mutex mode_mutex_;

  std::unique_ptr<std::thread> handle_message_thread_;

  /**
   * @brief     线程运行函数.
   * @return    void.
   */
  void Run();

  /**
   * @brief     线程结束函数.
   * @return    void.
   */
  void Stop();

protected:
  ros::NodeHandle nh_;
  std::mutex mutex_;
  // ROS 订阅器和发布器
  std::map<std::string, ros::Subscriber> _subscriber;
  std::map<std::string, ros::Publisher> _pubscriber;
  std::map<std::string, ros::ServiceServer> map_service_server_; //<作为服务端的服务,服务端句柄>

  // 固定点映射表
  //std::map<std::string, geometry_msgs::Pose> point_map_;
};
} // namespace function
} // namespace athena
#include "ros_message_manager.hpp"
#endif // ROS_ENABLE
