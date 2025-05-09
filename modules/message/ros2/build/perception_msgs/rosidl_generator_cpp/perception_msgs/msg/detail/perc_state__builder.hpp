// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from perception_msgs:msg/PercState.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__PERC_STATE__BUILDER_HPP_
#define PERCEPTION_MSGS__MSG__DETAIL__PERC_STATE__BUILDER_HPP_

#include "perception_msgs/msg/detail/perc_state__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace perception_msgs
{

namespace msg
{

namespace builder
{

class Init_PercState_wait_for_millisec
{
public:
  explicit Init_PercState_wait_for_millisec(::perception_msgs::msg::PercState & msg)
  : msg_(msg)
  {}
  ::perception_msgs::msg::PercState wait_for_millisec(::perception_msgs::msg::PercState::_wait_for_millisec_type arg)
  {
    msg_.wait_for_millisec = std::move(arg);
    return std::move(msg_);
  }

private:
  ::perception_msgs::msg::PercState msg_;
};

class Init_PercState_err_info
{
public:
  explicit Init_PercState_err_info(::perception_msgs::msg::PercState & msg)
  : msg_(msg)
  {}
  Init_PercState_wait_for_millisec err_info(::perception_msgs::msg::PercState::_err_info_type arg)
  {
    msg_.err_info = std::move(arg);
    return Init_PercState_wait_for_millisec(msg_);
  }

private:
  ::perception_msgs::msg::PercState msg_;
};

class Init_PercState_err_code
{
public:
  explicit Init_PercState_err_code(::perception_msgs::msg::PercState & msg)
  : msg_(msg)
  {}
  Init_PercState_err_info err_code(::perception_msgs::msg::PercState::_err_code_type arg)
  {
    msg_.err_code = std::move(arg);
    return Init_PercState_err_info(msg_);
  }

private:
  ::perception_msgs::msg::PercState msg_;
};

class Init_PercState_exe_result
{
public:
  explicit Init_PercState_exe_result(::perception_msgs::msg::PercState & msg)
  : msg_(msg)
  {}
  Init_PercState_err_code exe_result(::perception_msgs::msg::PercState::_exe_result_type arg)
  {
    msg_.exe_result = std::move(arg);
    return Init_PercState_err_code(msg_);
  }

private:
  ::perception_msgs::msg::PercState msg_;
};

class Init_PercState_exe_state
{
public:
  explicit Init_PercState_exe_state(::perception_msgs::msg::PercState & msg)
  : msg_(msg)
  {}
  Init_PercState_exe_result exe_state(::perception_msgs::msg::PercState::_exe_state_type arg)
  {
    msg_.exe_state = std::move(arg);
    return Init_PercState_exe_result(msg_);
  }

private:
  ::perception_msgs::msg::PercState msg_;
};

class Init_PercState_perc_kind
{
public:
  explicit Init_PercState_perc_kind(::perception_msgs::msg::PercState & msg)
  : msg_(msg)
  {}
  Init_PercState_exe_state perc_kind(::perception_msgs::msg::PercState::_perc_kind_type arg)
  {
    msg_.perc_kind = std::move(arg);
    return Init_PercState_exe_state(msg_);
  }

private:
  ::perception_msgs::msg::PercState msg_;
};

class Init_PercState_action_id
{
public:
  explicit Init_PercState_action_id(::perception_msgs::msg::PercState & msg)
  : msg_(msg)
  {}
  Init_PercState_perc_kind action_id(::perception_msgs::msg::PercState::_action_id_type arg)
  {
    msg_.action_id = std::move(arg);
    return Init_PercState_perc_kind(msg_);
  }

private:
  ::perception_msgs::msg::PercState msg_;
};

class Init_PercState_header
{
public:
  Init_PercState_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PercState_action_id header(::perception_msgs::msg::PercState::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PercState_action_id(msg_);
  }

private:
  ::perception_msgs::msg::PercState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::perception_msgs::msg::PercState>()
{
  return perception_msgs::msg::builder::Init_PercState_header();
}

}  // namespace perception_msgs

#endif  // PERCEPTION_MSGS__MSG__DETAIL__PERC_STATE__BUILDER_HPP_
