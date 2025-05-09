// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from perception_msgs:msg/DogState.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__DOG_STATE__STRUCT_HPP_
#define PERCEPTION_MSGS__MSG__DETAIL__DOG_STATE__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'target_position'
#include "geometry_msgs/msg/detail/pose__struct.hpp"
// Member 'alarm_info'
#include "perception_msgs/msg/detail/alarm_entry__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__perception_msgs__msg__DogState __attribute__((deprecated))
#else
# define DEPRECATED__perception_msgs__msg__DogState __declspec(deprecated)
#endif

namespace perception_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DogState_
{
  using Type = DogState_<ContainerAllocator>;

  explicit DogState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->battery = 0.0;
      this->charging_state = 0;
      this->gesture = 0;
      this->speed = 0.0;
      this->person_state = 0;
    }
  }

  explicit DogState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_position(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->battery = 0.0;
      this->charging_state = 0;
      this->gesture = 0;
      this->speed = 0.0;
      this->person_state = 0;
    }
  }

  // field types and members
  using _battery_type =
    double;
  _battery_type battery;
  using _charging_state_type =
    uint8_t;
  _charging_state_type charging_state;
  using _gesture_type =
    uint8_t;
  _gesture_type gesture;
  using _speed_type =
    double;
  _speed_type speed;
  using _person_state_type =
    uint8_t;
  _person_state_type person_state;
  using _target_position_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _target_position_type target_position;
  using _alarm_info_type =
    std::vector<perception_msgs::msg::AlarmEntry_<ContainerAllocator>, typename ContainerAllocator::template rebind<perception_msgs::msg::AlarmEntry_<ContainerAllocator>>::other>;
  _alarm_info_type alarm_info;

  // setters for named parameter idiom
  Type & set__battery(
    const double & _arg)
  {
    this->battery = _arg;
    return *this;
  }
  Type & set__charging_state(
    const uint8_t & _arg)
  {
    this->charging_state = _arg;
    return *this;
  }
  Type & set__gesture(
    const uint8_t & _arg)
  {
    this->gesture = _arg;
    return *this;
  }
  Type & set__speed(
    const double & _arg)
  {
    this->speed = _arg;
    return *this;
  }
  Type & set__person_state(
    const uint8_t & _arg)
  {
    this->person_state = _arg;
    return *this;
  }
  Type & set__target_position(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->target_position = _arg;
    return *this;
  }
  Type & set__alarm_info(
    const std::vector<perception_msgs::msg::AlarmEntry_<ContainerAllocator>, typename ContainerAllocator::template rebind<perception_msgs::msg::AlarmEntry_<ContainerAllocator>>::other> & _arg)
  {
    this->alarm_info = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    perception_msgs::msg::DogState_<ContainerAllocator> *;
  using ConstRawPtr =
    const perception_msgs::msg::DogState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<perception_msgs::msg::DogState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<perception_msgs::msg::DogState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      perception_msgs::msg::DogState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<perception_msgs::msg::DogState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      perception_msgs::msg::DogState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<perception_msgs::msg::DogState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<perception_msgs::msg::DogState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<perception_msgs::msg::DogState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__perception_msgs__msg__DogState
    std::shared_ptr<perception_msgs::msg::DogState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__perception_msgs__msg__DogState
    std::shared_ptr<perception_msgs::msg::DogState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DogState_ & other) const
  {
    if (this->battery != other.battery) {
      return false;
    }
    if (this->charging_state != other.charging_state) {
      return false;
    }
    if (this->gesture != other.gesture) {
      return false;
    }
    if (this->speed != other.speed) {
      return false;
    }
    if (this->person_state != other.person_state) {
      return false;
    }
    if (this->target_position != other.target_position) {
      return false;
    }
    if (this->alarm_info != other.alarm_info) {
      return false;
    }
    return true;
  }
  bool operator!=(const DogState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DogState_

// alias to use template instance with default allocator
using DogState =
  perception_msgs::msg::DogState_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace perception_msgs

#endif  // PERCEPTION_MSGS__MSG__DETAIL__DOG_STATE__STRUCT_HPP_
