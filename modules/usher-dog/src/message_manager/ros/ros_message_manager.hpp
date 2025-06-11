/**
 * @file    ros_message_manager.hpp
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#include "ros_message_manager.h"
#include "common/public_fun.h"
#include "services/voice_service.h"
#include "modules/common/macros/macros.h"
#include "modules/common/logging/logging.h"
#include "modules/common/json/json.hpp"
using Json = nlohmann::json;
#if ROS_ENABLE
/**
 * @namespace athena::function
 * @brief athena::function
 */

namespace athena {
namespace function {
using namespace athena::common;
template <typename T> void RosMessageManager<T>::Init(T* t)
{
  //loadPointMap();
  is_init_ = false;
  instance_ = t;

  // 发布任务给感知规划模块
  _pubscriber.insert(std::make_pair<std::string, ros::Publisher>(pub_perception_mode, nh_.advertise<perception_msgs::TaskList>(pub_perception_mode, 10)));
  // 发布点消息给可视化
  _pubscriber.insert(std::make_pair<std::string, ros::Publisher>(pub_goal_state_extern, nh_.advertise<geometry_msgs::Pose>(pub_goal_state_extern, 10)));
  // 发布反馈消息给集成
  _pubscriber.insert(std::make_pair<std::string, ros::Publisher>(pub_feedback_to_cmd, nh_.advertise<perception_msgs::PercState>(pub_feedback_to_cmd, 10)));
  // 发布动作信息给集成
  _pubscriber.insert(std::make_pair<std::string, ros::Publisher>(pub_action_info_to_cmd, nh_.advertise<perception_msgs::ActionEntry>(pub_action_info_to_cmd, 10)));
  //语音播放发布
  _pubscriber.insert(std::make_pair<std::string, ros::Publisher>(pub_video_play_on_int, nh_.advertise<ros_interface::ObuCmdMsg>(pub_video_play_on_int, 10)));
  _pubscriber.insert(std::make_pair<std::string, ros::Publisher>(pub_video_play_on_string, nh_.advertise<ros_interface::Events>(pub_video_play_on_string, 10)));
  
  //joy
  _pubscriber.insert(std::make_pair<std::string, ros::Publisher>(pub_joy_speed, nh_.advertise<::geometry_msgs::Twist>("/cmd_vel", 10)));
  _pubscriber.insert(std::make_pair<std::string, ros::Publisher>(pub_joy_load_controller, nh_.advertise<std_msgs::Float32>("/load_controller", 1)));
  _pubscriber.insert(std::make_pair<std::string, ros::Publisher>(pub_joy_to_standup, nh_.advertise<std_msgs::Float32>("/joyToStandup", 1)));
  _pubscriber.insert(std::make_pair<std::string, ros::Publisher>(pub_joy_load_to_getdown, nh_.advertise<std_msgs::Float32>("/joyToGetdown", 1)));
  _pubscriber.insert(std::make_pair<std::string, ros::Publisher>(pub_joy_load_emergency_stop, nh_.advertise<std_msgs::Float32>("/emergency_stop", 1)));

  // 订阅任务消息
  _subscriber.insert(std::make_pair<std::string, ros::Subscriber>(sub_callback_to_cmd, nh_.subscribe(sub_callback_to_cmd, 10, &RosMessageManager::cmdCallback, this)));
  // 订阅感知模块的反馈消息
  _subscriber.insert(std::make_pair<std::string, ros::Subscriber>(sub_recv_callback_perception, nh_.subscribe(sub_recv_callback_perception, 10, &RosMessageManager::ptCallback, this)));
  
  _subscriber.insert(std::make_pair<std::string, ros::Subscriber>(sub_obu_cmd, nh_.subscribe(sub_obu_cmd, 10, &RosMessageManager::obuCallback, this)));
  // 订阅狗当前坐标
  _subscriber.insert(std::make_pair<std::string, ros::Subscriber>(sub_current_point, nh_.subscribe(sub_current_point, 10, &RosMessageManager::handleCurrentPoint, this)));
  
  #if MQTT_ENABLE
  // 订阅狗当前的规划路径
  _subscriber.insert(std::make_pair<std::string, ros::Subscriber>(sub_current_plan, nh_.subscribe(sub_current_plan, 10, &RosMessageManager::handleCurrentPlan, this)));
  // 订阅狗局部点云
  _subscriber.insert(std::make_pair<std::string, ros::Subscriber>(sub_current_global_cloud, nh_.subscribe(sub_current_global_cloud, 10, &RosMessageManager::handleCurrentglobalCloud, this)));
  // 订阅当前任务点
  _subscriber.insert(std::make_pair<std::string, ros::Subscriber>(sub_current_task_point, nh_.subscribe(sub_current_task_point, 10, &RosMessageManager::handleCurrentTaskPoint, this)));
  #endif

  // dog作为server端的服务
  // 功能操作请求
  ros::ServiceServer record_bag_service = nh_.advertiseService(dog_ros_service_record_bag,
                              &RosMessageManager::recordBagCallback, this);
  map_service_server_.insert(std::pair<std::string, ros::ServiceServer>(dog_ros_service_record_bag, record_bag_service));

  // 线程执行开始
  handle_message_thread_.reset(new std::thread([this] { Run(); }));
  if (handle_message_thread_ == nullptr) {
    AERROR << "Unable to create handle_message_thread thread.";
    return;
  }
  is_init_ = true;
}

// template <typename T>
// void RosMessageManager<T>::loadPointMap() {
//   // 获取 point_map 参数
//   XmlRpc::XmlRpcValue point_map_param;
//   if (nh_.getParam("/robot_dog/point_map", point_map_param)) {
//     ROS_INFO("Loaded point_map from parameter server.");
//     for (auto& pair : point_map_param) {
//       std::string point_name = pair.first;
//       XmlRpc::XmlRpcValue pose_param = pair.second;

//       // 解析 pose 参数
//       geometry_msgs::Pose pose;
//       pose.position.x = static_cast<double>(pose_param["x"]);
//       pose.position.y = static_cast<double>(pose_param["y"]);
//       pose.position.z = static_cast<double>(pose_param["z"]);
//       pose.orientation.x = static_cast<double>(pose_param["qx"]);
//       pose.orientation.y = static_cast<double>(pose_param["qy"]);
//       pose.orientation.z = static_cast<double>(pose_param["qz"]);
//       pose.orientation.w = static_cast<double>(pose_param["qw"]);

//       // 将 point_name 和 pose 添加到 point_map_
//       point_map_[point_name] = pose;
//       ROS_INFO("Added point: %s", point_name.c_str());
//     }
//   } else {
//     ROS_ERROR("Failed to load point_map from parameter server.");
//   }
// }

template <typename T>
void RosMessageManager<T>::PublishTaskList(robot_dog::TaskList msg) {
  perception_msgs::TaskList task;
  task.task_id = msg.task_id;
  task.task_type = msg.task_type;

  task.target_position.position.x = msg.target_position.x;
  task.target_position.position.y = msg.target_position.y;
  task.target_position.position.z = msg.target_position.z;
  task.target_position.orientation.x = msg.target_position.q_x;
  task.target_position.orientation.y = msg.target_position.q_y;
  task.target_position.orientation.z = msg.target_position.q_z;
  task.target_position.orientation.w = msg.target_position.q_w;
  
  task.target_object = msg.target_object;
  task.task_state = msg.task_state;
  task.task_result = msg.task_result;
  task.isInPlaceRotation = msg.is_in_place_rotation;

  _pubscriber[pub_perception_mode].publish(task);
}
template <typename T>
void RosMessageManager<T>::PublishPose(robot_dog::Position msg) {
  geometry_msgs::Pose pose;
  pose.position.x = msg.x;
  pose.position.y = msg.y;
  pose.position.z = msg.z;
  pose.orientation.x = msg.q_x;
  pose.orientation.y = msg.q_y;
  pose.orientation.z = msg.q_z;
  pose.orientation.w = msg.q_w;

  _pubscriber[pub_goal_state_extern].publish(pose);

}
template <typename T>
void RosMessageManager<T>::PublishState(robot_dog::PercState msg) {
  perception_msgs::PercState perc_state;
  perc_state.action_id = msg.action_id;
  perc_state.perc_kind = msg.perc_kind;
  perc_state.exe_state = msg.exe_state;
  perc_state.exe_result = msg.exe_result;
  perc_state.err_code = msg.err_code;
  perc_state.err_info = msg.err_info;
  perc_state.wait_for_millisec = msg.wait_for_millisec;

  _pubscriber[pub_feedback_to_cmd].publish(perc_state);
}

template <typename T>
void RosMessageManager<T>::PublishAction(robot_dog::ActionEntry msg) {
  perception_msgs::ActionEntry actions;
  actions.id = msg.id;
  actions.param1 = msg.param1;
  actions.param2 = msg.param2;
  actions.param3 = msg.param3;
  actions.info = msg.info;
  _pubscriber[pub_action_info_to_cmd].publish(actions);
}

template <typename T>
void RosMessageManager<T>::PublishVideoOnInt(const robot_dog::ObuCmdMsg& msg) {
  ros_interface::ObuCmdMsg obu_msg;
  // 设置 header（自动填充时间戳）
  obu_msg.header.stamp = ros::Time::now();
  obu_msg.id = msg.id;
  obu_msg.name = obu_msg.name;
  ros_interface::ObuCmd obu_cmd;
  for(const auto& m : msg.obu_cmd_list)
  {
    obu_cmd.code = m.code;
    obu_cmd.val = m.val;
    obu_msg.obu_cmd_list.push_back(obu_cmd);
  }
  _pubscriber[pub_video_play_on_int].publish(obu_msg);
}

template <typename T>
void RosMessageManager<T>::PublishVideoOnString(const std::vector<robot_dog::Event>& msg) {
  ros_interface::Events events_msg;
  // 设置 header（自动填充时间戳）
  events_msg.header.stamp = ros::Time::now();
  ros_interface::Event event_cmd;
  for(const auto& m : msg)
  {
    event_cmd.code = m.code;
    event_cmd.reason = m.reason;
    events_msg.events.push_back(event_cmd);
  }
  _pubscriber[pub_video_play_on_string].publish(events_msg);
}

template <typename T>
void RosMessageManager<T>::cmdCallback(const perception_msgs::PercCmd::ConstPtr& msg) {
  robot_dog::PercCmd cmd;
  cmd.action_id = msg->action_id;
  cmd.angle = msg->angle;
  cmd.follow_name = msg->follow_name;
  cmd.on_off = msg->on_off;
  cmd.perc_kind = msg->perc_kind;
  cmd.point.x = msg->point.x;
  cmd.point.y = msg->point.y;
  cmd.point.z = msg->point.z;
  cmd.point_name = msg->point_name;
  cmd.req_id = msg->req_id;

  instance_->cmdCallback(cmd);
}
template <typename T>
void RosMessageManager<T>::ptCallback(const perception_msgs::TaskList::ConstPtr& msg) {
  robot_dog::TaskList task_list;

    task_list.task_id = msg->task_id;
    task_list.task_type = msg->task_type;

    task_list.target_position.x = msg->target_position.position.x;
    task_list.target_position.y = msg->target_position.position.y;
    task_list.target_position.z = msg->target_position.position.z;
    task_list.target_position.q_x = msg->target_position.orientation.x;
    task_list.target_position.q_y = msg->target_position.orientation.y;
    task_list.target_position.q_z = msg->target_position.orientation.z;
    task_list.target_position.q_w = msg->target_position.orientation.w;

    task_list.target_object = msg->target_object;
    task_list.task_state = msg->task_state;
    task_list.task_result = msg->task_result;
    task_list.is_in_place_rotation = msg->isInPlaceRotation;

    instance_->ptCallback(task_list);
}

template <typename T>
void RosMessageManager<T>::stateCallback(const perception_msgs::TaskList::ConstPtr& msg) {
  robot_dog::TaskList task_list;
      
      task_list.task_id = msg->task_id;
      task_list.task_type = msg->task_type;

      task_list.target_position.x = msg->target_position.position.x;
      task_list.target_position.y = msg->target_position.position.y;
      task_list.target_position.z = msg->target_position.position.z;
      task_list.target_position.q_x = msg->target_position.orientation.x;
      task_list.target_position.q_y = msg->target_position.orientation.y;
      task_list.target_position.q_z = msg->target_position.orientation.z;
      task_list.target_position.q_w = msg->target_position.orientation.w;

      task_list.target_object = msg->target_object;
      task_list.task_state = msg->task_state;
      task_list.task_result = msg->task_result;
      task_list.is_in_place_rotation = msg->isInPlaceRotation;
      
      instance_->stateCallback(task_list);
}

template <typename T>
void RosMessageManager<T>::obuCallback(const ros_interface::ObuCmdMsg& msg_obj) {
  if(! AppGetVoiceService()) return;

  robot_dog::ObuCmdMsg v_obu;

  const ros_interface::ObuCmdMsg* msg_obj_ptr = &msg_obj;
  ros_interface::ObuCmdMsg* msg =
      const_cast<ros_interface::ObuCmdMsg*>(msg_obj_ptr);

  //std::vector<athena::interface::ObuCmd> obu_cmd_list;
  for (auto it_obu_cmd_list : msg->obu_cmd_list) {
    robot_dog::ObuCmd obu_cmd_msg_obu_cmd;
    obu_cmd_msg_obu_cmd.code = it_obu_cmd_list.code;
    obu_cmd_msg_obu_cmd.val = it_obu_cmd_list.val;
    v_obu.obu_cmd_list.emplace_back(obu_cmd_msg_obu_cmd);
  }

  AppGetVoiceService()->HandleVideoCode(v_obu);
}

template <typename T>
void RosMessageManager<T>::handleCurrentPoint(const nav_msgs::Odometry& msg) {
  robot_dog::Pose currentPoint;
  currentPoint.x = msg.pose.pose.position.x;
  currentPoint.y = msg.pose.pose.position.y;
  currentPoint.z = msg.pose.pose.position.z;

  tf::Quaternion q(msg.pose.pose.orientation.x, msg.pose.pose.orientation.y, msg.pose.pose.orientation.z, msg.pose.pose.orientation.w);

  // 使用 getEulerYPR 获取 yaw, pitch, roll
  double roll, pitch, yaw;
  tf::Matrix3x3(q).getEulerYPR(roll, pitch, yaw);

  currentPoint.theta = yaw;

  #if MQTT_ENABLE
    Json info;
    info["position"]["x"] = msg.pose.pose.position.x;
    info["position"]["y"] = msg.pose.pose.position.y;
    info["position"]["z"] = msg.pose.pose.position.z;

    info["orientation"]["x"] = msg.pose.pose.orientation.x;
    info["orientation"]["y"] = msg.pose.pose.orientation.y;
    info["orientation"]["z"] = msg.pose.pose.orientation.z;
    info["orientation"]["w"] = msg.pose.pose.orientation.w;

    _AppGetMqttService->PublishCurrentPoint(info.dump());
#endif
  instance_->SetCurrrentPoint(currentPoint);
}

template <typename T>
void RosMessageManager<T>::handleCurrentPlan(const quad_msgs::RobotPlan& msg) {
  #if MQTT_ENABLE
    //instance_->stateCallback(msg);
    Json route_points;
    json r_point;
    for(const auto &state : msg.states)
    {
      r_point["position"]["x"] = state.body.pose.position.x;
      r_point["position"]["y"] = state.body.pose.position.y;
      r_point["position"]["z"] = state.body.pose.position.z;
      
      r_point["orientation"]["x"] = state.body.pose.orientation.x;
      r_point["orientation"]["y"] = state.body.pose.orientation.y;
      r_point["orientation"]["z"] = state.body.pose.orientation.z;
      r_point["orientation"]["w"] = state.body.pose.orientation.w;
      
      route_points.push_back(r_point);
    }
    _AppGetMqttService->PublishPlanningPlan(route_points.dump());
#endif
}

template <typename T>
void RosMessageManager<T>::handleCurrentglobalCloud(const visualization_msgs::MarkerArray& msg) {
#if MQTT_ENABLE
    //instance_->stateCallback(msg);
    Json cloud_points;
    json cloud_point;
    for(const auto &marker : msg.markers)
    {
      for(const auto& point : marker.points)
      {
        cloud_point["x"] = point.x;
        cloud_point["y"] = point.y;
        cloud_point["z"] = point.z;
        cloud_points.push_back(cloud_point);
      }
    }
    _AppGetMqttService->PublishGlobalCloud(cloud_points.dump());
#endif
}

template <typename T>
void RosMessageManager<T>::handleCurrentTaskPoint(const geometry_msgs::Pose& msg) {
#if MQTT_ENABLE
    Json info;
    info["position"]["x"] = msg.position.x;
    info["position"]["y"] = msg.position.y;
    info["position"]["z"] = msg.position.z;

    info["orientation"]["x"] = msg.orientation.x;
    info["orientation"]["y"] = msg.orientation.y;
    info["orientation"]["z"] = msg.orientation.z;
    info["orientation"]["w"] = msg.orientation.w;

    _AppGetMqttService->PublishTaskPoint(info.dump());
#endif
}

//处理录包服务响应
template <typename T>
bool RosMessageManager<T>::recordBagCallback(perception_msgs::DogRecordBag::Request &req, perception_msgs::DogRecordBag::Response &rsp)
{
  robot_dog::RecordBag tReq;
  robot_dog::CallbackInfo tRsp;

  tReq.bag_mode = req.bagMode;
  tReq.bag_name = req.bagName;
  for(const auto& topic : req.topics)
  {
    tReq.topics.push_back(topic);
  }
  tReq.bash_name = req.bashName;

  if(_AppIsMessageHandManagerNotNull)
  {
    bool success = _AppGetMessageHandManager->recordBagCallback(tReq, tRsp);
    rsp.success = tRsp.success;
    rsp.errorInfo = tRsp.info;
    return success;
  }
  return false;
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
