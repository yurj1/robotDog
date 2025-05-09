// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from perception_msgs:msg/AlarmEntry.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__ALARM_ENTRY__BUILDER_HPP_
#define PERCEPTION_MSGS__MSG__DETAIL__ALARM_ENTRY__BUILDER_HPP_

#include "perception_msgs/msg/detail/alarm_entry__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace perception_msgs
{

namespace msg
{

namespace builder
{

class Init_AlarmEntry_message
{
public:
  explicit Init_AlarmEntry_message(::perception_msgs::msg::AlarmEntry & msg)
  : msg_(msg)
  {}
  ::perception_msgs::msg::AlarmEntry message(::perception_msgs::msg::AlarmEntry::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::perception_msgs::msg::AlarmEntry msg_;
};

class Init_AlarmEntry_status
{
public:
  explicit Init_AlarmEntry_status(::perception_msgs::msg::AlarmEntry & msg)
  : msg_(msg)
  {}
  Init_AlarmEntry_message status(::perception_msgs::msg::AlarmEntry::_status_type arg)
  {
    msg_.status = std::move(arg);
    return Init_AlarmEntry_message(msg_);
  }

private:
  ::perception_msgs::msg::AlarmEntry msg_;
};

class Init_AlarmEntry_level
{
public:
  explicit Init_AlarmEntry_level(::perception_msgs::msg::AlarmEntry & msg)
  : msg_(msg)
  {}
  Init_AlarmEntry_status level(::perception_msgs::msg::AlarmEntry::_level_type arg)
  {
    msg_.level = std::move(arg);
    return Init_AlarmEntry_status(msg_);
  }

private:
  ::perception_msgs::msg::AlarmEntry msg_;
};

class Init_AlarmEntry_source
{
public:
  explicit Init_AlarmEntry_source(::perception_msgs::msg::AlarmEntry & msg)
  : msg_(msg)
  {}
  Init_AlarmEntry_level source(::perception_msgs::msg::AlarmEntry::_source_type arg)
  {
    msg_.source = std::move(arg);
    return Init_AlarmEntry_level(msg_);
  }

private:
  ::perception_msgs::msg::AlarmEntry msg_;
};

class Init_AlarmEntry_id
{
public:
  Init_AlarmEntry_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AlarmEntry_source id(::perception_msgs::msg::AlarmEntry::_id_type arg)
  {
    msg_.id = std::move(arg);
    return Init_AlarmEntry_source(msg_);
  }

private:
  ::perception_msgs::msg::AlarmEntry msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::perception_msgs::msg::AlarmEntry>()
{
  return perception_msgs::msg::builder::Init_AlarmEntry_id();
}

}  // namespace perception_msgs

#endif  // PERCEPTION_MSGS__MSG__DETAIL__ALARM_ENTRY__BUILDER_HPP_
