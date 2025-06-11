/**
 * @file    message_manager.h
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#pragma once
#include "modules/common/enum/enum.h"
#include "common/struct/CommonStruct.h"

#if ROS_ENABLE
#include <perception_msgs/PercCmd.h>
#include <perception_msgs/PercState.h>
#include <perception_msgs/TaskList.h>
#include <perception_msgs/ActionEntry.h>
#include <perception_msgs/DogRecordBag.h>
#include <quad_msgs/RobotPlan.h>

#include <geometry_msgs/Pose.h>
#include <geometry_msgs/Twist.h>
#include <nav_msgs/Odometry.h> 
#include <visualization_msgs/MarkerArray.h>
#include <std_msgs/Float32.h>
#elif ROS2_ENABLE
#include <perception_msgs/msg/perc_cmd.hpp>
#include <perception_msgs/msg/perc_state.hpp>
#include <perception_msgs/msg/task_list.hpp>
#include <perception_msgs/msg/action_entry.hpp>
#include <perception_msgs/srv/dog_record_bag.hpp>

#include <geometry_msgs/msg/pose.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <visualization_msgs/msg/marker_array.hpp>
#include <std_msgs/msg/float32.hpp>
#endif

#include <map>

//发布反馈消息给集成模块
#ifndef pub_feedback_to_cmd
 #define pub_feedback_to_cmd "/planning/perc_state"
#endif

//发布动作消息给集成模块
#ifndef pub_action_info_to_cmd
 #define pub_action_info_to_cmd "/dog_action"
#endif

//发布任务模式给规划和感知模块
#ifndef pub_perception_mode
 #define pub_perception_mode "/perception_bridge/task_list"
#endif

//发布点坐标消息给可视化
#ifndef pub_goal_state_extern
 #define pub_goal_state_extern "/goal_state_extern"
#endif

/************* Pub joy ****************/

//发布速度
#ifndef pub_joy_speed
 #define pub_joy_speed "/cmd_vel"
#endif

//启动控制器
#ifndef pub_joy_load_controller
 #define pub_joy_load_controller "/load_controller"
#endif

//机器狗站立
#ifndef pub_joy_to_standup
 #define pub_joy_to_standup "/joyToStandup"
#endif

//机器狗趴下
#ifndef pub_joy_load_to_getdown
 #define pub_joy_load_to_getdown "/joyToGetdown"
#endif

//机器狗紧急停止
#ifndef pub_joy_load_emergency_stop
 #define pub_joy_load_emergency_stop "/emergency_stop"
#endif

//发布语音播放
#ifndef pub_video_play_on_int
 #define pub_video_play_on_int "/Speech/ObuCmdMsg"
#endif

#ifndef pub_video_play_on_string
 #define pub_video_play_on_string "/Speech/Events"
#endif

/**************** Sub ****************/

//订阅集成模块给到的任务消息
#ifndef sub_callback_to_cmd
 #define sub_callback_to_cmd "/planning/perc_cmd"
#endif

//订阅感知模块的反馈消息
#ifndef sub_recv_callback_perception
 #define sub_recv_callback_perception "/perception/task_pt_feedback"
#endif

//订阅规划模块的反馈消息
#ifndef sub_planning_feedback
 #define sub_planning_feedback "/planning/task_list_feedback"
#endif

//订阅狗当前坐标
#ifndef sub_current_point
 #define sub_current_point "/odom"
#endif

//订阅狗当前的规划路径
#ifndef sub_current_plan
 #define sub_current_plan "/global_plan"
#endif

//订阅狗局部点云
#ifndef sub_current_global_cloud
 #define sub_current_global_cloud "/map/occ_obstacle_list"
#endif

//订阅当前任务点
#ifndef sub_current_task_point
 #define sub_current_task_point "/goal_state_extern"
#endif

//订阅大模型发送的指令
#ifndef sub_order_exec
 #define sub_order_exec "/dog/order_exec"
#endif

//订阅 语音指令
#ifndef sub_obu_cmd
 #define sub_obu_cmd "/Command/ObuCmdMsg"
#endif

/************************** Service *******************************/ 

//集成界面向应用层申请录包（服务端）
#ifndef dog_ros_service_record_bag
#define dog_ros_service_record_bag "/dog/record_bag"
#endif

/************************** MQTT *******************************/ 

//订阅客户端的任务消息
#ifndef mqtt_task_list_sub
#define mqtt_task_list_sub "robot_dog/task_list"
#endif

//订阅客户端的功能操作请求（录包、执行脚本）
#ifndef mqtt_function_request_sub
#define mqtt_function_request_sub "robot_dog/function/request"
#endif

//订阅手柄消息
#ifndef mqtt_joy_msg_sub
 #define mqtt_joy_msg_sub "robot_dog/joy_msg"
#endif

//发布给客户端的功能操作结果的回复
#ifndef mqtt_function_response_pub
#define mqtt_function_response_pub "robot_dog/function/response"
#endif

//发布狗当前位置
#ifndef mqtt_current_point_pub
 #define mqtt_current_point_pub "robot_dog/current/point"
#endif

//发布规划路径
#ifndef mqtt_planning_plan_pub
 #define mqtt_planning_plan_pub "robot_dog/current/route_plan"
#endif

//发布狗局部点云
#ifndef mqtt_global_cloud_pub
#define mqtt_global_cloud_pub "robot_dog/current/local_point_cloud"
#endif

//发布任务点
#ifndef mqtt_task_point_pub
 #define mqtt_task_point_pub "robot_dog/task_point"
#endif

//发布狗的经纬度坐标
#ifndef mqtt_doorout_position
 #define mqtt_doorout_position "/robot/outdoor/current_position"
#endif

//发布景点坐标和推荐路线
#ifndef mqtt_outdoor_recommended_route
 #define mqtt_outdoor_recommended_route "/robot/outdoor/recommended_route"
#endif

/**
 * @namespace athena::function
 * @brief athena::function
 */

namespace athena {
namespace function {
using namespace athena::common;
template <typename T> class MessageManager {
public:

  MessageManager() = default;
  virtual ~MessageManager() = default;

  virtual void Init(T* t) = 0;
  virtual void PublishTaskList(robot_dog::TaskList msg) = 0;
  virtual void PublishPose(robot_dog::Position msg) = 0;
  virtual void PublishState(robot_dog::PercState msg) = 0;
  virtual void PublishAction(robot_dog::ActionEntry msg) = 0;
  virtual void PublishVideoOnInt(const robot_dog::ObuCmdMsg& msg) = 0;
  virtual void PublishVideoOnString(const std::vector<robot_dog::Event>& msg) = 0;
  //joy
  // virtual void PublishJoyMsgTwist(geometry_msgs::Twist msg) = 0;
  // virtual void PublishJoyMsgLoad(std_msgs::Float32 data) = 0;
  // virtual void PublishJoyMsgStandup(std_msgs::Float32 data) = 0;
  // virtual void PublishJoyMsgGetdown(std_msgs::Float32 data) = 0;
  // virtual void PublishJoyMsgStop(std_msgs::Float32 data) = 0;
  //rosparse data
  //virtual const std::map<std::string, robot_dog::Position>& GetPointMap() = 0;
  
};
} // namespace function
} // namespace athena
