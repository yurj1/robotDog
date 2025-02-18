#ifndef __PERCEPTION_BRIDGE_H__
#define __PERCEPTION_BRIDGE_H__

#include <ros/ros.h>
#include <perception_msgs/PercCmd.h>
#include <perception_msgs/PercState.h>
#include <perception_msgs/TaskList.h>
#include <geometry_msgs/Pose.h>
#include <perception_bridge/enum.h>
#include <perception_bridge/RobotDogState.h>
//#include <map>
//发布反馈消息给集成模块
#ifndef pub_feedback_to_cmd
 #define pub_feedback_to_cmd "/planning/perc_state"
#endif
//发布任务模式给感知模块，控制模块
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

using namespace perception_bridge;

class RobotDogMain {
public:
  enum class PUB_TOP {
    CMD = 0,
    PT,
    STATE
  };

  RobotDogMain();
  // 初始化所有参数
  void clear();

  // 根据 point_name 获取 geometry_msgs/Pose
  bool getPose(const std::string& point_name, geometry_msgs::Pose& pose);

  // 将状态机的状态更新到字段消息中
  void UpdateState();
  
  void Publish(const PUB_TOP& topicType, void* data);
private:
  void loadPointMap();

  // 取消任务
  void CancelTask();
  // 前往固定点任务
  void GoDest(const perception_msgs::PercCmd::ConstPtr& msg);
  // 跟随任务
  void Follow(const perception_msgs::PercCmd::ConstPtr& msg);
  // 欢迎任务
  void Welcome(const perception_msgs::PercCmd::ConstPtr& msg);
  // 找人任务
  void GoDestAndFindTarget(const perception_msgs::PercCmd::ConstPtr& msg);
  
  // 处理集成消息
  void cmdCallback(const perception_msgs::PercCmd::ConstPtr& msg);
  // 处理感知反馈消息
  void ptCallback(const perception_msgs::TaskList::ConstPtr& msg);
  // 处理规划状态反馈消息
  void stateCallback(const perception_msgs::TaskList::ConstPtr& msg);

  // 定时器回调函数，按周期发布状态
  void timerCallback(const ros::TimerEvent& event);
private:
  // 初始化 ROS 节点
  ros::NodeHandle nh;

  // ROS 订阅器和发布器
  std::map<std::string, ros::Subscriber> _subscriber;
  std::map<PUB_TOP, ros::Publisher> _pubscriber;

  // 定时器
  ros::Timer state_timer_;

  perception_msgs::TaskList task_list_;
  perception_msgs::PercState perc_state_;

  // 完成状态是否可上报
  RobotDogState m_state;
  // 固定点映射表
  std::map<std::string, geometry_msgs::Pose> point_map_;
};

#endif