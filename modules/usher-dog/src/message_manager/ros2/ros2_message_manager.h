/**
 * @file    ros_2_message_manager.h
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#pragma once
#if ROS2_ENABLE
#include <thread>

//#define nanosec nsec
#include "rclcpp/rclcpp.hpp"
//#undef nanosec nsec

// #include "ros2_interface/msg/chassis.hpp"
// #include "ros2_interface/msg/events.hpp"
// #include "ros2_interface/msg/obu_cmd_msg.hpp"

#include "message_manager/message_manager.h"

/**
 * @namespace athena::function
 * @brief athena::function
 */

namespace athena {
namespace function {
/**
 * @class Ros2MessageManager
 * @brief ROS2消息管理器.
 */
template <typename T>
class Ros2MessageManager : public MessageManager<T>, public rclcpp::Node {
public:
  Ros2MessageManager();
  ~Ros2MessageManager() = default;

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
  //void PublishObuCmdMsgOutput(athena::interface::ObuCmdMsg msg) override;

  /**
   * @brief     ObuCmdMsg消息发布.
   * @param[in] obu_cmd_msg.
   * @return    void.
   */
  //void PublishEventsOutput(athena::interface::Events msg) override;

  void PublishTaskList(robot_dog::TaskList msg)override;
  void PublishPose(robot_dog::Position msg)override;
  void PublishState(robot_dog::PercState msg)override;
  void PublishAction(robot_dog::ActionEntry msg)override;
  void PublishVideoOnInt(const robot_dog::ObuCmdMsg& msg){}override;
  void PublishVideoOnString(const std::vector<robot_dog::Event>& msg){}override;

  // const std::map<std::string, robot_dog::Position>& GetPointMap() override{
  //   return point_map_;
  // }

protected:
  T* instance_;
  bool is_init_;
  bool is_active_;
  // 0 do_nothing ; 1 activate ; 2 deactivate
  MessageActionMode action_mode_;
  std::mutex mode_mutex_;

  std::unique_ptr<std::thread> handle_message_thread_;

  std::unique_ptr<std::thread> handle_avtive_thread_;

  /**
   * @brief     线程运行函数.
   * @return    void.
   */
  void Run();

  /**
   * @brief     线程运行函数.
   * @return    void.
   */
  void ActivateMode();

  /**
   * @brief     线程结束函数.
   * @return    void.
   */
  void Stop();

  void TaskStop();

  void TaskStart();

  // 处理集成消息
  void cmdCallback(const perception_msgs::msg::PercCmd::SharedPtr msg);
  // 处理感知反馈消息
  void ptCallback(const perception_msgs::msg::TaskList::SharedPtr msg);
  // 处理规划状态反馈消息
  void stateCallback(const perception_msgs::msg::TaskList::SharedPtr msg);
protected:
  std::mutex mutex_;
  // rclcpp::Publisher<::ros2_interface::msg::ObuCmdMsg>::SharedPtr
  //     obu_cmd_msg_output_pub_;
  // rclcpp::Publisher<::ros2_interface::msg::Events>::SharedPtr
  //     events_output_pub_;
  rclcpp::Publisher<perception_msgs::msg::TaskList>::SharedPtr task_msg_output_pub_;
  rclcpp::Publisher<geometry_msgs::msg::Pose>::SharedPtr rviz_target_point_msg_output_pub_;
  rclcpp::Publisher<perception_msgs::msg::PercState>::SharedPtr feedback_to_cmd_output_pub_;
  rclcpp::Publisher<perception_msgs::msg::ActionEntry>::SharedPtr action_to_cmd_output_pub_;

  // rclcpp::Subscription<::ros2_interface::msg::Chassis>::SharedPtr chassis_sub_;
  // rclcpp::Subscription<::ros2_interface::msg::Events>::SharedPtr events_sub_;
  // rclcpp::Subscription<::ros2_interface::msg::ObuCmdMsg>::SharedPtr
  //     obu_cmd_msg_input_sub_;
  rclcpp::Subscription<perception_msgs::msg::PercCmd>::SharedPtr task_sub_;
  rclcpp::Subscription<perception_msgs::msg::TaskList>::SharedPtr callback_perception_sub_;
  rclcpp::Subscription<perception_msgs::msg::TaskList>::SharedPtr callback_planning_sub_;
  //rclcpp::Subscription<perception_msgs::msg::Order>::SharedPtr order_exec_sub_;

  // 固定点映射表
  //std::map<std::string, robot_dog::Position> point_map_;

  // void
  // HandleChassisMessage(const ros2_interface::msg::Chassis::SharedPtr msg_obj);
  // void
  // HandleEventsMessage(const ros2_interface::msg::Events::SharedPtr msg_obj);

  // void HandleObuCmdMsgMessage(
  //     const ros2_interface::msg::ObuCmdMsg::SharedPtr msg_obj);
};
} // namespace function
} // namespace athena
#include "ros2_message_manager.hpp"
#endif // ROS2_ENABLE
