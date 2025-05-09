// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from perception_msgs:msg/PercCmd.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__PERC_CMD__STRUCT_HPP_
#define PERCEPTION_MSGS__MSG__DETAIL__PERC_CMD__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"
// Member 'point'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__perception_msgs__msg__PercCmd __attribute__((deprecated))
#else
# define DEPRECATED__perception_msgs__msg__PercCmd __declspec(deprecated)
#endif

namespace perception_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PercCmd_
{
  using Type = PercCmd_<ContainerAllocator>;

  explicit PercCmd_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init),
    point(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->action_id = 0ull;
      this->perc_kind = 0ul;
      this->req_id = 0ull;
      this->on_off = 0ul;
      this->follow_name = "";
      this->angle = 0.0;
      this->point_name = "";
    }
  }

  explicit PercCmd_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    follow_name(_alloc),
    point_name(_alloc),
    point(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->action_id = 0ull;
      this->perc_kind = 0ul;
      this->req_id = 0ull;
      this->on_off = 0ul;
      this->follow_name = "";
      this->angle = 0.0;
      this->point_name = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _action_id_type =
    uint64_t;
  _action_id_type action_id;
  using _perc_kind_type =
    uint32_t;
  _perc_kind_type perc_kind;
  using _req_id_type =
    uint64_t;
  _req_id_type req_id;
  using _on_off_type =
    uint32_t;
  _on_off_type on_off;
  using _follow_name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _follow_name_type follow_name;
  using _angle_type =
    double;
  _angle_type angle;
  using _point_name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _point_name_type point_name;
  using _point_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _point_type point;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__action_id(
    const uint64_t & _arg)
  {
    this->action_id = _arg;
    return *this;
  }
  Type & set__perc_kind(
    const uint32_t & _arg)
  {
    this->perc_kind = _arg;
    return *this;
  }
  Type & set__req_id(
    const uint64_t & _arg)
  {
    this->req_id = _arg;
    return *this;
  }
  Type & set__on_off(
    const uint32_t & _arg)
  {
    this->on_off = _arg;
    return *this;
  }
  Type & set__follow_name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->follow_name = _arg;
    return *this;
  }
  Type & set__angle(
    const double & _arg)
  {
    this->angle = _arg;
    return *this;
  }
  Type & set__point_name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->point_name = _arg;
    return *this;
  }
  Type & set__point(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->point = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint32_t PERC_DEST =
    1u;
  static constexpr uint32_t PERC_ABS =
    2u;
  static constexpr uint32_t PERC_REL =
    3u;
  static constexpr uint32_t PERC_AUTO_CHARGING =
    20u;
  static constexpr uint32_t PERC_CHECK_ENV =
    21u;
  static constexpr uint32_t PERC_AUTO_MAPPING =
    22u;
  static constexpr uint32_t PERC_FOLLOW =
    30u;
  static constexpr uint32_t PERC_STRANGER_WELCOME =
    31u;
  static constexpr uint32_t PERC_OWNER_WELCOME =
    32u;
  static constexpr uint32_t PERC_BEHAVIOR_INTERACTION =
    33u;
  static constexpr uint32_t PERC_HANDSHAKE =
    34u;
  static constexpr uint32_t PERC_STANDBY_ACCOMPANY =
    35u;
  static constexpr uint32_t PERC_HAPPY_ACCOMPANY =
    36u;
  static constexpr uint32_t PERC_WORK_ACCOMPANY =
    37u;
  static constexpr uint32_t PERC_POSITIVE_ACCOMPANY =
    38u;
  static constexpr uint32_t PERC_NEGATIVE_ACCOMPANY =
    39u;
  static constexpr uint32_t PERC_CHILD_WATCH =
    40u;
  static constexpr uint32_t PERC_OLDER_WATCH =
    41u;
  static constexpr uint32_t PERC_DANGER_REMINDER =
    42u;
  static constexpr uint32_t PERC_EVENT_REMINDER =
    43u;
  static constexpr uint32_t PERC_CATWALK_START =
    44u;
  static constexpr uint32_t PERC_CATWALK_ACT =
    45u;
  static constexpr uint32_t PERC_CATWALK_SHOW =
    46u;
  static constexpr uint32_t PERC_CATWALK_BACK =
    47u;
  static constexpr uint32_t PERC_FREE_TIME =
    50u;
  static constexpr uint32_t PERC_SOCIALIZE =
    51u;
  static constexpr uint32_t PERC_SPECT_PERFORM =
    55u;
  static constexpr uint32_t PERC_FACE_DETCTION =
    56u;
  static constexpr uint32_t PERC_DANGER_INFO =
    60u;
  static constexpr uint32_t PERC_WELCOME_DEMO =
    61u;
  static constexpr uint32_t PERC_LOBBY_DEMO =
    62u;
  static constexpr uint32_t PERC_CANCEL =
    100u;
  static constexpr uint32_t PERC_NODE_CLOSE =
    200u;
  static constexpr uint32_t PERC_NODE_START =
    201u;
  static constexpr uint32_t PERC_NODE_RESET =
    202u;
  static constexpr uint32_t FOLLOW_ON =
    1u;
  static constexpr uint32_t FOLLOW_OFF =
    2u;

  // pointer types
  using RawPtr =
    perception_msgs::msg::PercCmd_<ContainerAllocator> *;
  using ConstRawPtr =
    const perception_msgs::msg::PercCmd_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<perception_msgs::msg::PercCmd_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<perception_msgs::msg::PercCmd_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      perception_msgs::msg::PercCmd_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<perception_msgs::msg::PercCmd_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      perception_msgs::msg::PercCmd_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<perception_msgs::msg::PercCmd_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<perception_msgs::msg::PercCmd_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<perception_msgs::msg::PercCmd_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__perception_msgs__msg__PercCmd
    std::shared_ptr<perception_msgs::msg::PercCmd_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__perception_msgs__msg__PercCmd
    std::shared_ptr<perception_msgs::msg::PercCmd_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PercCmd_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->action_id != other.action_id) {
      return false;
    }
    if (this->perc_kind != other.perc_kind) {
      return false;
    }
    if (this->req_id != other.req_id) {
      return false;
    }
    if (this->on_off != other.on_off) {
      return false;
    }
    if (this->follow_name != other.follow_name) {
      return false;
    }
    if (this->angle != other.angle) {
      return false;
    }
    if (this->point_name != other.point_name) {
      return false;
    }
    if (this->point != other.point) {
      return false;
    }
    return true;
  }
  bool operator!=(const PercCmd_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PercCmd_

// alias to use template instance with default allocator
using PercCmd =
  perception_msgs::msg::PercCmd_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_DEST;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_ABS;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_REL;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_AUTO_CHARGING;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_CHECK_ENV;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_AUTO_MAPPING;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_FOLLOW;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_STRANGER_WELCOME;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_OWNER_WELCOME;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_BEHAVIOR_INTERACTION;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_HANDSHAKE;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_STANDBY_ACCOMPANY;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_HAPPY_ACCOMPANY;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_WORK_ACCOMPANY;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_POSITIVE_ACCOMPANY;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_NEGATIVE_ACCOMPANY;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_CHILD_WATCH;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_OLDER_WATCH;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_DANGER_REMINDER;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_EVENT_REMINDER;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_CATWALK_START;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_CATWALK_ACT;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_CATWALK_SHOW;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_CATWALK_BACK;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_FREE_TIME;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_SOCIALIZE;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_SPECT_PERFORM;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_FACE_DETCTION;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_DANGER_INFO;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_WELCOME_DEMO;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_LOBBY_DEMO;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_CANCEL;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_NODE_CLOSE;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_NODE_START;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::PERC_NODE_RESET;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::FOLLOW_ON;
template<typename ContainerAllocator>
constexpr uint32_t PercCmd_<ContainerAllocator>::FOLLOW_OFF;

}  // namespace msg

}  // namespace perception_msgs

#endif  // PERCEPTION_MSGS__MSG__DETAIL__PERC_CMD__STRUCT_HPP_
