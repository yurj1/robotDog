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

#define nanosec nsec
#include "rclcpp/rclcpp.hpp"
#undef nanosec nsec

#include "ros2_interface/msg/chassis.hpp"
#include "ros2_interface/msg/events.hpp"
#include "ros2_interface/msg/obu_cmd_msg.hpp"

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
  void PublishObuCmdMsgOutput(athena::interface::ObuCmdMsg msg) override;

  /**
   * @brief     ObuCmdMsg消息发布.
   * @param[in] obu_cmd_msg.
   * @return    void.
   */
  void PublishEventsOutput(athena::interface::Events msg) override;

  bool Activate() override;
  bool DeActivate() override;

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

protected:
  std::mutex mutex_;
  rclcpp::Publisher<::ros2_interface::msg::ObuCmdMsg>::SharedPtr
      obu_cmd_msg_output_pub_;
  rclcpp::Publisher<::ros2_interface::msg::Events>::SharedPtr
      events_output_pub_;

  rclcpp::Subscription<::ros2_interface::msg::Chassis>::SharedPtr chassis_sub_;
  rclcpp::Subscription<::ros2_interface::msg::Events>::SharedPtr events_sub_;
  rclcpp::Subscription<::ros2_interface::msg::ObuCmdMsg>::SharedPtr
      obu_cmd_msg_input_sub_;

  void
  HandleChassisMessage(const ros2_interface::msg::Chassis::SharedPtr msg_obj);
  void
  HandleEventsMessage(const ros2_interface::msg::Events::SharedPtr msg_obj);

  void HandleObuCmdMsgMessage(
      const ros2_interface::msg::ObuCmdMsg::SharedPtr msg_obj);
};
} // namespace function
} // namespace athena
#include "ros2_message_manager.hpp"
#endif // ROS2_ENABLE
