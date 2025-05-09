// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from perception_msgs:msg/PercCmd.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__PERC_CMD__BUILDER_HPP_
#define PERCEPTION_MSGS__MSG__DETAIL__PERC_CMD__BUILDER_HPP_

#include "perception_msgs/msg/detail/perc_cmd__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace perception_msgs
{

namespace msg
{

namespace builder
{

class Init_PercCmd_point
{
public:
  explicit Init_PercCmd_point(::perception_msgs::msg::PercCmd & msg)
  : msg_(msg)
  {}
  ::perception_msgs::msg::PercCmd point(::perception_msgs::msg::PercCmd::_point_type arg)
  {
    msg_.point = std::move(arg);
    return std::move(msg_);
  }

private:
  ::perception_msgs::msg::PercCmd msg_;
};

class Init_PercCmd_point_name
{
public:
  explicit Init_PercCmd_point_name(::perception_msgs::msg::PercCmd & msg)
  : msg_(msg)
  {}
  Init_PercCmd_point point_name(::perception_msgs::msg::PercCmd::_point_name_type arg)
  {
    msg_.point_name = std::move(arg);
    return Init_PercCmd_point(msg_);
  }

private:
  ::perception_msgs::msg::PercCmd msg_;
};

class Init_PercCmd_angle
{
public:
  explicit Init_PercCmd_angle(::perception_msgs::msg::PercCmd & msg)
  : msg_(msg)
  {}
  Init_PercCmd_point_name angle(::perception_msgs::msg::PercCmd::_angle_type arg)
  {
    msg_.angle = std::move(arg);
    return Init_PercCmd_point_name(msg_);
  }

private:
  ::perception_msgs::msg::PercCmd msg_;
};

class Init_PercCmd_follow_name
{
public:
  explicit Init_PercCmd_follow_name(::perception_msgs::msg::PercCmd & msg)
  : msg_(msg)
  {}
  Init_PercCmd_angle follow_name(::perception_msgs::msg::PercCmd::_follow_name_type arg)
  {
    msg_.follow_name = std::move(arg);
    return Init_PercCmd_angle(msg_);
  }

private:
  ::perception_msgs::msg::PercCmd msg_;
};

class Init_PercCmd_on_off
{
public:
  explicit Init_PercCmd_on_off(::perception_msgs::msg::PercCmd & msg)
  : msg_(msg)
  {}
  Init_PercCmd_follow_name on_off(::perception_msgs::msg::PercCmd::_on_off_type arg)
  {
    msg_.on_off = std::move(arg);
    return Init_PercCmd_follow_name(msg_);
  }

private:
  ::perception_msgs::msg::PercCmd msg_;
};

class Init_PercCmd_req_id
{
public:
  explicit Init_PercCmd_req_id(::perception_msgs::msg::PercCmd & msg)
  : msg_(msg)
  {}
  Init_PercCmd_on_off req_id(::perception_msgs::msg::PercCmd::_req_id_type arg)
  {
    msg_.req_id = std::move(arg);
    return Init_PercCmd_on_off(msg_);
  }

private:
  ::perception_msgs::msg::PercCmd msg_;
};

class Init_PercCmd_perc_kind
{
public:
  explicit Init_PercCmd_perc_kind(::perception_msgs::msg::PercCmd & msg)
  : msg_(msg)
  {}
  Init_PercCmd_req_id perc_kind(::perception_msgs::msg::PercCmd::_perc_kind_type arg)
  {
    msg_.perc_kind = std::move(arg);
    return Init_PercCmd_req_id(msg_);
  }

private:
  ::perception_msgs::msg::PercCmd msg_;
};

class Init_PercCmd_action_id
{
public:
  explicit Init_PercCmd_action_id(::perception_msgs::msg::PercCmd & msg)
  : msg_(msg)
  {}
  Init_PercCmd_perc_kind action_id(::perception_msgs::msg::PercCmd::_action_id_type arg)
  {
    msg_.action_id = std::move(arg);
    return Init_PercCmd_perc_kind(msg_);
  }

private:
  ::perception_msgs::msg::PercCmd msg_;
};

class Init_PercCmd_header
{
public:
  Init_PercCmd_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PercCmd_action_id header(::perception_msgs::msg::PercCmd::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_PercCmd_action_id(msg_);
  }

private:
  ::perception_msgs::msg::PercCmd msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::perception_msgs::msg::PercCmd>()
{
  return perception_msgs::msg::builder::Init_PercCmd_header();
}

}  // namespace perception_msgs

#endif  // PERCEPTION_MSGS__MSG__DETAIL__PERC_CMD__BUILDER_HPP_
