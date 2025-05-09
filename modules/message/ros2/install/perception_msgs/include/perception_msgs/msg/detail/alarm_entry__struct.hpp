// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from perception_msgs:msg/AlarmEntry.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__ALARM_ENTRY__STRUCT_HPP_
#define PERCEPTION_MSGS__MSG__DETAIL__ALARM_ENTRY__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__perception_msgs__msg__AlarmEntry __attribute__((deprecated))
#else
# define DEPRECATED__perception_msgs__msg__AlarmEntry __declspec(deprecated)
#endif

namespace perception_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct AlarmEntry_
{
  using Type = AlarmEntry_<ContainerAllocator>;

  explicit AlarmEntry_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->source = 0l;
      this->level = 0l;
      this->status = 0l;
      this->message = "";
    }
  }

  explicit AlarmEntry_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : message(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->source = 0l;
      this->level = 0l;
      this->status = 0l;
      this->message = "";
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _source_type =
    int32_t;
  _source_type source;
  using _level_type =
    int32_t;
  _level_type level;
  using _status_type =
    int32_t;
  _status_type status;
  using _message_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _message_type message;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__source(
    const int32_t & _arg)
  {
    this->source = _arg;
    return *this;
  }
  Type & set__level(
    const int32_t & _arg)
  {
    this->level = _arg;
    return *this;
  }
  Type & set__status(
    const int32_t & _arg)
  {
    this->status = _arg;
    return *this;
  }
  Type & set__message(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->message = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    perception_msgs::msg::AlarmEntry_<ContainerAllocator> *;
  using ConstRawPtr =
    const perception_msgs::msg::AlarmEntry_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<perception_msgs::msg::AlarmEntry_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<perception_msgs::msg::AlarmEntry_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      perception_msgs::msg::AlarmEntry_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<perception_msgs::msg::AlarmEntry_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      perception_msgs::msg::AlarmEntry_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<perception_msgs::msg::AlarmEntry_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<perception_msgs::msg::AlarmEntry_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<perception_msgs::msg::AlarmEntry_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__perception_msgs__msg__AlarmEntry
    std::shared_ptr<perception_msgs::msg::AlarmEntry_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__perception_msgs__msg__AlarmEntry
    std::shared_ptr<perception_msgs::msg::AlarmEntry_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const AlarmEntry_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->source != other.source) {
      return false;
    }
    if (this->level != other.level) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    if (this->message != other.message) {
      return false;
    }
    return true;
  }
  bool operator!=(const AlarmEntry_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct AlarmEntry_

// alias to use template instance with default allocator
using AlarmEntry =
  perception_msgs::msg::AlarmEntry_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace perception_msgs

#endif  // PERCEPTION_MSGS__MSG__DETAIL__ALARM_ENTRY__STRUCT_HPP_
