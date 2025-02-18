/**
 * @file    ros_message_manager.hpp
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#include "ros_message_manager.h"
#include "modules/common/macros/macros.h"
#include "modules/common/logging/logging.h"

#if ROS_ENABLE
/**
 * @namespace athena::function
 * @brief athena::function
 */

namespace athena {
namespace function {
using namespace athena::common;
template <typename T> void RosMessageManager<T>::Init(T* t) {

  loadPointMap();
  is_init_ = false;
  instance_ = t;

  // 订阅集成模块的消息
  _subscriber.insert(std::make_pair<std::string, ros::Subscriber>(sub_callback_to_cmd, nh_.subscribe(sub_callback_to_cmd, 10, &RosMessageManager::cmdCallback, this)));
  //cmd_sub_ = nh.subscribe(sub_callback_to_cmd, 10, &RobotDogMain::cmdCallback, this);

  // 发布消息给感知规划模块
  _pubscriber.insert(std::make_pair<std::string, ros::Publisher>(pub_perception_mode, nh_.advertise<perception_msgs::TaskList>(pub_perception_mode, 10)));
  //cmd_pub_ = nh.advertise<perception_msgs::TaskList>(pub_perception_mode, 10);

  // 订阅感知模块的反馈消息
  _subscriber.insert(std::make_pair<std::string, ros::Subscriber>(sub_recv_callback_perception, nh_.subscribe(sub_recv_callback_perception, 10, &RosMessageManager::ptCallback, this)));
  //pt_sub_ = nh.subscribe(sub_recv_callback_perception, 10, &RobotDogMain::ptCallback, this);

  // 发布点消息给可视化
  _pubscriber.insert(std::make_pair<std::string, ros::Publisher>(pub_goal_state_extern, nh_.advertise<geometry_msgs::Pose>(pub_goal_state_extern, 10)));
  //pt_pub_ = nh.advertise<geometry_msgs::Pose>(pub_goal_state_extern, 10);

  // 订阅规划模块的反馈消息
  _subscriber.insert(std::make_pair<std::string, ros::Subscriber>(sub_planning_feedback, nh_.subscribe(sub_planning_feedback, 10, &RosMessageManager::stateCallback, this)));
  //state_sub_ = nh.subscribe(sub_planning_feedback, 10, &RobotDogMain::stateCallback, this);

  // 发布反馈消息给集成
  _pubscriber.insert(std::make_pair<std::string, ros::Publisher>(pub_feedback_to_cmd, nh_.advertise<perception_msgs::PercState>(pub_feedback_to_cmd, 10)));
  //state_pub_ = nh.advertise<perception_msgs::PercState>(pub_feedback_to_cmd, 10);

  // 线程执行开始
  handle_message_thread_.reset(new std::thread([this] { Run(); }));
  if (handle_message_thread_ == nullptr) {
    AERROR << "Unable to create handle_message_thread thread.";
    return;
  }
  is_init_ = true;
}

template <typename T>
void RosMessageManager<T>::loadPointMap() {
  // 获取 point_map 参数
  XmlRpc::XmlRpcValue point_map_param;
  if (nh_.getParam("/robot_dog/point_map", point_map_param)) {
    ROS_INFO("Loaded point_map from parameter server.");
    for (auto& pair : point_map_param) {
      std::string point_name = pair.first;
      XmlRpc::XmlRpcValue pose_param = pair.second;

      // 解析 pose 参数
      geometry_msgs::Pose pose;
      pose.position.x = static_cast<double>(pose_param["x"]);
      pose.position.y = static_cast<double>(pose_param["y"]);
      pose.position.z = static_cast<double>(pose_param["z"]);
      pose.orientation.x = static_cast<double>(pose_param["qx"]);
      pose.orientation.y = static_cast<double>(pose_param["qy"]);
      pose.orientation.z = static_cast<double>(pose_param["qz"]);
      pose.orientation.w = static_cast<double>(pose_param["qw"]);

      // 将 point_name 和 pose 添加到 point_map_
      point_map_[point_name] = pose;
      ROS_INFO("Added point: %s", point_name.c_str());
    }
  } else {
    ROS_ERROR("Failed to load point_map from parameter server.");
  }
}

template <typename T>
void RosMessageManager<T>::PublishTaskList(perception_msgs::TaskList msg) {
  _pubscriber[pub_perception_mode].publish(msg);
}
template <typename T>
void RosMessageManager<T>::PublishPose(geometry_msgs::Pose msg) {
  _pubscriber[pub_goal_state_extern].publish(msg);
}
template <typename T>
void RosMessageManager<T>::PublishState(perception_msgs::PercState msg) {
  _pubscriber[pub_feedback_to_cmd].publish(msg);
}

template <typename T>
void RosMessageManager<T>::cmdCallback(const perception_msgs::PercCmd::ConstPtr& msg) {
  instance_->cmdCallback(msg);
}
template <typename T>
void RosMessageManager<T>::ptCallback(const perception_msgs::TaskList::ConstPtr& msg) {
  instance_->ptCallback(msg);
}   
template <typename T>
void RosMessageManager<T>::stateCallback(const perception_msgs::TaskList::ConstPtr& msg) {
    instance_->stateCallback(msg);
}
template <typename T> void RosMessageManager<T>::Run() {
  ros::spin();
  ros::shutdown();
  exit(0);
}

template <typename T> void RosMessageManager<T>::Stop() {
  if (handle_message_thread_ != nullptr && handle_message_thread_->joinable()) {
    handle_message_thread_->join();
    handle_message_thread_.reset();
    AINFO << "handle_message_thread stopped [ok].";
  }
}
} // namespace function
} // namespace athena
#endif
