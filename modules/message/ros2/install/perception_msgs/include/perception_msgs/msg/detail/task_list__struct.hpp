// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from perception_msgs:msg/TaskList.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__TASK_LIST__STRUCT_HPP_
#define PERCEPTION_MSGS__MSG__DETAIL__TASK_LIST__STRUCT_HPP_

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

#ifndef _WIN32
# define DEPRECATED__perception_msgs__msg__TaskList __attribute__((deprecated))
#else
# define DEPRECATED__perception_msgs__msg__TaskList __declspec(deprecated)
#endif

namespace perception_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct TaskList_
{
  using Type = TaskList_<ContainerAllocator>;

  explicit TaskList_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_id = 0ull;
      this->task_type = 0ul;
      this->target_object = "";
      this->task_state = 0;
      this->task_result = 0;
      this->is_in_place_rotation = 0;
    }
  }

  explicit TaskList_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_position(_alloc, _init),
    target_object(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->task_id = 0ull;
      this->task_type = 0ul;
      this->target_object = "";
      this->task_state = 0;
      this->task_result = 0;
      this->is_in_place_rotation = 0;
    }
  }

  // field types and members
  using _task_id_type =
    uint64_t;
  _task_id_type task_id;
  using _task_type_type =
    uint32_t;
  _task_type_type task_type;
  using _target_position_type =
    geometry_msgs::msg::Pose_<ContainerAllocator>;
  _target_position_type target_position;
  using _target_object_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _target_object_type target_object;
  using _task_state_type =
    uint8_t;
  _task_state_type task_state;
  using _task_result_type =
    uint8_t;
  _task_result_type task_result;
  using _is_in_place_rotation_type =
    uint8_t;
  _is_in_place_rotation_type is_in_place_rotation;

  // setters for named parameter idiom
  Type & set__task_id(
    const uint64_t & _arg)
  {
    this->task_id = _arg;
    return *this;
  }
  Type & set__task_type(
    const uint32_t & _arg)
  {
    this->task_type = _arg;
    return *this;
  }
  Type & set__target_position(
    const geometry_msgs::msg::Pose_<ContainerAllocator> & _arg)
  {
    this->target_position = _arg;
    return *this;
  }
  Type & set__target_object(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->target_object = _arg;
    return *this;
  }
  Type & set__task_state(
    const uint8_t & _arg)
  {
    this->task_state = _arg;
    return *this;
  }
  Type & set__task_result(
    const uint8_t & _arg)
  {
    this->task_result = _arg;
    return *this;
  }
  Type & set__is_in_place_rotation(
    const uint8_t & _arg)
  {
    this->is_in_place_rotation = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    perception_msgs::msg::TaskList_<ContainerAllocator> *;
  using ConstRawPtr =
    const perception_msgs::msg::TaskList_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<perception_msgs::msg::TaskList_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<perception_msgs::msg::TaskList_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      perception_msgs::msg::TaskList_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<perception_msgs::msg::TaskList_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      perception_msgs::msg::TaskList_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<perception_msgs::msg::TaskList_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<perception_msgs::msg::TaskList_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<perception_msgs::msg::TaskList_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__perception_msgs__msg__TaskList
    std::shared_ptr<perception_msgs::msg::TaskList_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__perception_msgs__msg__TaskList
    std::shared_ptr<perception_msgs::msg::TaskList_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const TaskList_ & other) const
  {
    if (this->task_id != other.task_id) {
      return false;
    }
    if (this->task_type != other.task_type) {
      return false;
    }
    if (this->target_position != other.target_position) {
      return false;
    }
    if (this->target_object != other.target_object) {
      return false;
    }
    if (this->task_state != other.task_state) {
      return false;
    }
    if (this->task_result != other.task_result) {
      return false;
    }
    if (this->is_in_place_rotation != other.is_in_place_rotation) {
      return false;
    }
    return true;
  }
  bool operator!=(const TaskList_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct TaskList_

// alias to use template instance with default allocator
using TaskList =
  perception_msgs::msg::TaskList_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace perception_msgs

#endif  // PERCEPTION_MSGS__MSG__DETAIL__TASK_LIST__STRUCT_HPP_
