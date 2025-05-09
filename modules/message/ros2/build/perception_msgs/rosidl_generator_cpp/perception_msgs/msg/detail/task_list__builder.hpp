// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from perception_msgs:msg/TaskList.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__TASK_LIST__BUILDER_HPP_
#define PERCEPTION_MSGS__MSG__DETAIL__TASK_LIST__BUILDER_HPP_

#include "perception_msgs/msg/detail/task_list__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace perception_msgs
{

namespace msg
{

namespace builder
{

class Init_TaskList_is_in_place_rotation
{
public:
  explicit Init_TaskList_is_in_place_rotation(::perception_msgs::msg::TaskList & msg)
  : msg_(msg)
  {}
  ::perception_msgs::msg::TaskList is_in_place_rotation(::perception_msgs::msg::TaskList::_is_in_place_rotation_type arg)
  {
    msg_.is_in_place_rotation = std::move(arg);
    return std::move(msg_);
  }

private:
  ::perception_msgs::msg::TaskList msg_;
};

class Init_TaskList_task_result
{
public:
  explicit Init_TaskList_task_result(::perception_msgs::msg::TaskList & msg)
  : msg_(msg)
  {}
  Init_TaskList_is_in_place_rotation task_result(::perception_msgs::msg::TaskList::_task_result_type arg)
  {
    msg_.task_result = std::move(arg);
    return Init_TaskList_is_in_place_rotation(msg_);
  }

private:
  ::perception_msgs::msg::TaskList msg_;
};

class Init_TaskList_task_state
{
public:
  explicit Init_TaskList_task_state(::perception_msgs::msg::TaskList & msg)
  : msg_(msg)
  {}
  Init_TaskList_task_result task_state(::perception_msgs::msg::TaskList::_task_state_type arg)
  {
    msg_.task_state = std::move(arg);
    return Init_TaskList_task_result(msg_);
  }

private:
  ::perception_msgs::msg::TaskList msg_;
};

class Init_TaskList_target_object
{
public:
  explicit Init_TaskList_target_object(::perception_msgs::msg::TaskList & msg)
  : msg_(msg)
  {}
  Init_TaskList_task_state target_object(::perception_msgs::msg::TaskList::_target_object_type arg)
  {
    msg_.target_object = std::move(arg);
    return Init_TaskList_task_state(msg_);
  }

private:
  ::perception_msgs::msg::TaskList msg_;
};

class Init_TaskList_target_position
{
public:
  explicit Init_TaskList_target_position(::perception_msgs::msg::TaskList & msg)
  : msg_(msg)
  {}
  Init_TaskList_target_object target_position(::perception_msgs::msg::TaskList::_target_position_type arg)
  {
    msg_.target_position = std::move(arg);
    return Init_TaskList_target_object(msg_);
  }

private:
  ::perception_msgs::msg::TaskList msg_;
};

class Init_TaskList_task_type
{
public:
  explicit Init_TaskList_task_type(::perception_msgs::msg::TaskList & msg)
  : msg_(msg)
  {}
  Init_TaskList_target_position task_type(::perception_msgs::msg::TaskList::_task_type_type arg)
  {
    msg_.task_type = std::move(arg);
    return Init_TaskList_target_position(msg_);
  }

private:
  ::perception_msgs::msg::TaskList msg_;
};

class Init_TaskList_task_id
{
public:
  Init_TaskList_task_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_TaskList_task_type task_id(::perception_msgs::msg::TaskList::_task_id_type arg)
  {
    msg_.task_id = std::move(arg);
    return Init_TaskList_task_type(msg_);
  }

private:
  ::perception_msgs::msg::TaskList msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::perception_msgs::msg::TaskList>()
{
  return perception_msgs::msg::builder::Init_TaskList_task_id();
}

}  // namespace perception_msgs

#endif  // PERCEPTION_MSGS__MSG__DETAIL__TASK_LIST__BUILDER_HPP_
