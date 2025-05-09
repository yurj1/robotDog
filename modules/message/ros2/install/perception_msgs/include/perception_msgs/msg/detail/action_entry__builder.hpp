// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from perception_msgs:msg/ActionEntry.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__ACTION_ENTRY__BUILDER_HPP_
#define PERCEPTION_MSGS__MSG__DETAIL__ACTION_ENTRY__BUILDER_HPP_

#include "perception_msgs/msg/detail/action_entry__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace perception_msgs
{

namespace msg
{

namespace builder
{

class Init_ActionEntry_info
{
public:
  explicit Init_ActionEntry_info(::perception_msgs::msg::ActionEntry & msg)
  : msg_(msg)
  {}
  ::perception_msgs::msg::ActionEntry info(::perception_msgs::msg::ActionEntry::_info_type arg)
  {
    msg_.info = std::move(arg);
    return std::move(msg_);
  }

private:
  ::perception_msgs::msg::ActionEntry msg_;
};

class Init_ActionEntry_param3
{
public:
  explicit Init_ActionEntry_param3(::perception_msgs::msg::ActionEntry & msg)
  : msg_(msg)
  {}
  Init_ActionEntry_info param3(::perception_msgs::msg::ActionEntry::_param3_type arg)
  {
    msg_.param3 = std::move(arg);
    return Init_ActionEntry_info(msg_);
  }

private:
  ::perception_msgs::msg::ActionEntry msg_;
};

class Init_ActionEntry_param2
{
public:
  explicit Init_ActionEntry_param2(::perception_msgs::msg::ActionEntry & msg)
  : msg_(msg)
  {}
  Init_ActionEntry_param3 param2(::perception_msgs::msg::ActionEntry::_param2_type arg)
  {
    msg_.param2 = std::move(arg);
    return Init_ActionEntry_param3(msg_);
  }

private:
  ::perception_msgs::msg::ActionEntry msg_;
};

class Init_ActionEntry_param1
{
public:
  explicit Init_ActionEntry_param1(::perception_msgs::msg::ActionEntry & msg)
  : msg_(msg)
  {}
  Init_ActionEntry_param2 param1(::perception_msgs::msg::ActionEntry::_param1_type arg)
  {
    msg_.param1 = std::move(arg);
    return Init_ActionEntry_param2(msg_);
  }

private:
  ::perception_msgs::msg::ActionEntry msg_;
};

class Init_ActionEntry_id
{
public:
  Init_ActionEntry_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ActionEntry_param1 id(::perception_msgs::msg::ActionEntry::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_ActionEntry_param1(msg_);
  }

private:
  ::perception_msgs::msg::ActionEntry msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::perception_msgs::msg::ActionEntry>()
{
  return perception_msgs::msg::builder::Init_ActionEntry_id();
}

}  // namespace perception_msgs

#endif  // PERCEPTION_MSGS__MSG__DETAIL__ACTION_ENTRY__BUILDER_HPP_
