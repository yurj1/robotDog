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

#include <perception_msgs/PercCmd.h>
#include <perception_msgs/PercState.h>
#include <perception_msgs/TaskList.h>
#include <geometry_msgs/Pose.h>
#include <apps/enum.h>

//发布反馈消息给集成模块
#ifndef pub_feedback_to_cmd
 #define pub_feedback_to_cmd "/planning/perc_state"
#endif
//发布任务模式给规划和感知模块
#ifndef pub_perception_mode
 #define pub_perception_mode "/perception_bridge/task_list"
#endif

//发布点坐标消息给可视化
#ifndef pub_goal_state_extern
 #define pub_goal_state_extern "/goal_state_extern"
#endif

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
  virtual void PublishTaskList(perception_msgs::TaskList msg) = 0;
  virtual void PublishPose(geometry_msgs::Pose msg) = 0;
  virtual void PublishState(perception_msgs::PercState msg) = 0;
  virtual const std::map<std::string, geometry_msgs::Pose>& GetPointMap() = 0;
  
};
} // namespace function
} // namespace athena
