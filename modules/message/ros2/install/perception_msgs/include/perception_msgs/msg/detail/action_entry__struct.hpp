// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from perception_msgs:msg/ActionEntry.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__ACTION_ENTRY__STRUCT_HPP_
#define PERCEPTION_MSGS__MSG__DETAIL__ACTION_ENTRY__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__perception_msgs__msg__ActionEntry __attribute__((deprecated))
#else
# define DEPRECATED__perception_msgs__msg__ActionEntry __declspec(deprecated)
#endif

namespace perception_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ActionEntry_
{
  using Type = ActionEntry_<ContainerAllocator>;

  explicit ActionEntry_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->param1 = 0l;
      this->param2 = 0l;
      this->param3 = "";
      this->info = "";
    }
  }

  explicit ActionEntry_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : param3(_alloc),
    info(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->id = 0l;
      this->param1 = 0l;
      this->param2 = 0l;
      this->param3 = "";
      this->info = "";
    }
  }

  // field types and members
  using _id_type =
    int32_t;
  _id_type id;
  using _param1_type =
    int32_t;
  _param1_type param1;
  using _param2_type =
    int32_t;
  _param2_type param2;
  using _param3_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _param3_type param3;
  using _info_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _info_type info;

  // setters for named parameter idiom
  Type & set__id(
    const int32_t & _arg)
  {
    this->id = _arg;
    return *this;
  }
  Type & set__param1(
    const int32_t & _arg)
  {
    this->param1 = _arg;
    return *this;
  }
  Type & set__param2(
    const int32_t & _arg)
  {
    this->param2 = _arg;
    return *this;
  }
  Type & set__param3(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->param3 = _arg;
    return *this;
  }
  Type & set__info(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->info = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    perception_msgs::msg::ActionEntry_<ContainerAllocator> *;
  using ConstRawPtr =
    const perception_msgs::msg::ActionEntry_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<perception_msgs::msg::ActionEntry_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<perception_msgs::msg::ActionEntry_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      perception_msgs::msg::ActionEntry_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<perception_msgs::msg::ActionEntry_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      perception_msgs::msg::ActionEntry_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<perception_msgs::msg::ActionEntry_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<perception_msgs::msg::ActionEntry_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<perception_msgs::msg::ActionEntry_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__perception_msgs__msg__ActionEntry
    std::shared_ptr<perception_msgs::msg::ActionEntry_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__perception_msgs__msg__ActionEntry
    std::shared_ptr<perception_msgs::msg::ActionEntry_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ActionEntry_ & other) const
  {
    if (this->id != other.id) {
      return false;
    }
    if (this->param1 != other.param1) {
      return false;
    }
    if (this->param2 != other.param2) {
      return false;
    }
    if (this->param3 != other.param3) {
      return false;
    }
    if (this->info != other.info) {
      return false;
    }
    return true;
  }
  bool operator!=(const ActionEntry_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ActionEntry_

// alias to use template instance with default allocator
using ActionEntry =
  perception_msgs::msg::ActionEntry_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace perception_msgs

#endif  // PERCEPTION_MSGS__MSG__DETAIL__ACTION_ENTRY__STRUCT_HPP_
