// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from perception_msgs:msg/DogState.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__DOG_STATE__BUILDER_HPP_
#define PERCEPTION_MSGS__MSG__DETAIL__DOG_STATE__BUILDER_HPP_

#include "perception_msgs/msg/detail/dog_state__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace perception_msgs
{

namespace msg
{

namespace builder
{

class Init_DogState_alarm_info
{
public:
  explicit Init_DogState_alarm_info(::perception_msgs::msg::DogState & msg)
  : msg_(msg)
  {}
  ::perception_msgs::msg::DogState alarm_info(::perception_msgs::msg::DogState::_alarm_info_type arg)
  {
    msg_.alarm_info = std::move(arg);
    return std::move(msg_);
  }

private:
  ::perception_msgs::msg::DogState msg_;
};

class Init_DogState_target_position
{
public:
  explicit Init_DogState_target_position(::perception_msgs::msg::DogState & msg)
  : msg_(msg)
  {}
  Init_DogState_alarm_info target_position(::perception_msgs::msg::DogState::_target_position_type arg)
  {
    msg_.target_position = std::move(arg);
    return Init_DogState_alarm_info(msg_);
  }

private:
  ::perception_msgs::msg::DogState msg_;
};

class Init_DogState_person_state
{
public:
  explicit Init_DogState_person_state(::perception_msgs::msg::DogState & msg)
  : msg_(msg)
  {}
  Init_DogState_target_position person_state(::perception_msgs::msg::DogState::_person_state_type arg)
  {
    msg_.person_state = std::move(arg);
    return Init_DogState_target_position(msg_);
  }

private:
  ::perception_msgs::msg::DogState msg_;
};

class Init_DogState_speed
{
public:
  explicit Init_DogState_speed(::perception_msgs::msg::DogState & msg)
  : msg_(msg)
  {}
  Init_DogState_person_state speed(::perception_msgs::msg::DogState::_speed_type arg)
  {
    msg_.speed = std::move(arg);
    return Init_DogState_person_state(msg_);
  }

private:
  ::perception_msgs::msg::DogState msg_;
};

class Init_DogState_gesture
{
public:
  explicit Init_DogState_gesture(::perception_msgs::msg::DogState & msg)
  : msg_(msg)
  {}
  Init_DogState_speed gesture(::perception_msgs::msg::DogState::_gesture_type arg)
  {
    msg_.gesture = std::move(arg);
    return Init_DogState_speed(msg_);
  }

private:
  ::perception_msgs::msg::DogState msg_;
};

class Init_DogState_charging_state
{
public:
  explicit Init_DogState_charging_state(::perception_msgs::msg::DogState & msg)
  : msg_(msg)
  {}
  Init_DogState_gesture charging_state(::perception_msgs::msg::DogState::_charging_state_type arg)
  {
    msg_.charging_state = std::move(arg);
    return Init_DogState_gesture(msg_);
  }

private:
  ::perception_msgs::msg::DogState msg_;
};

class Init_DogState_battery
{
public:
  Init_DogState_battery()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DogState_charging_state battery(::perception_msgs::msg::DogState::_battery_type arg)
  {
    msg_.battery = std::move(arg);
    return Init_DogState_charging_state(msg_);
  }

private:
  ::perception_msgs::msg::DogState msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::perception_msgs::msg::DogState>()
{
  return perception_msgs::msg::builder::Init_DogState_battery();
}

}  // namespace perception_msgs

#endif  // PERCEPTION_MSGS__MSG__DETAIL__DOG_STATE__BUILDER_HPP_
