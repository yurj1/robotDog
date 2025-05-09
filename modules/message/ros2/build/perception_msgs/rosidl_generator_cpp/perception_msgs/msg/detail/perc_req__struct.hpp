// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from perception_msgs:msg/PercReq.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__PERC_REQ__STRUCT_HPP_
#define PERCEPTION_MSGS__MSG__DETAIL__PERC_REQ__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__perception_msgs__msg__PercReq __attribute__((deprecated))
#else
# define DEPRECATED__perception_msgs__msg__PercReq __declspec(deprecated)
#endif

namespace perception_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PercReq_
{
  using Type = PercReq_<ContainerAllocator>;

  explicit PercReq_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->req_id = 0ull;
      this->perc_kind = 0ul;
      this->danger_info = "";
    }
  }

  explicit PercReq_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : danger_info(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->req_id = 0ull;
      this->perc_kind = 0ul;
      this->danger_info = "";
    }
  }

  // field types and members
  using _req_id_type =
    uint64_t;
  _req_id_type req_id;
  using _perc_kind_type =
    uint32_t;
  _perc_kind_type perc_kind;
  using _danger_info_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _danger_info_type danger_info;

  // setters for named parameter idiom
  Type & set__req_id(
    const uint64_t & _arg)
  {
    this->req_id = _arg;
    return *this;
  }
  Type & set__perc_kind(
    const uint32_t & _arg)
  {
    this->perc_kind = _arg;
    return *this;
  }
  Type & set__danger_info(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->danger_info = _arg;
    return *this;
  }

  // constant declarations
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
  static constexpr uint32_t PERC_HAND_OK =
    70u;
  static constexpr uint32_t PERC_HAND_V =
    71u;
  static constexpr uint32_t PERC_HAND_SHAKE =
    72u;
  static constexpr uint32_t PERC_HAND_COME =
    73u;
  static constexpr uint32_t PERC_HAND_WAVE =
    74u;
  static constexpr uint32_t PERC_CAMERA_DEMO =
    80u;
  static constexpr uint32_t PERC_CANCEL =
    100u;

  // pointer types
  using RawPtr =
    perception_msgs::msg::PercReq_<ContainerAllocator> *;
  using ConstRawPtr =
    const perception_msgs::msg::PercReq_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<perception_msgs::msg::PercReq_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<perception_msgs::msg::PercReq_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      perception_msgs::msg::PercReq_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<perception_msgs::msg::PercReq_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      perception_msgs::msg::PercReq_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<perception_msgs::msg::PercReq_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<perception_msgs::msg::PercReq_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<perception_msgs::msg::PercReq_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__perception_msgs__msg__PercReq
    std::shared_ptr<perception_msgs::msg::PercReq_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__perception_msgs__msg__PercReq
    std::shared_ptr<perception_msgs::msg::PercReq_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PercReq_ & other) const
  {
    if (this->req_id != other.req_id) {
      return false;
    }
    if (this->perc_kind != other.perc_kind) {
      return false;
    }
    if (this->danger_info != other.danger_info) {
      return false;
    }
    return true;
  }
  bool operator!=(const PercReq_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PercReq_

// alias to use template instance with default allocator
using PercReq =
  perception_msgs::msg::PercReq_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_AUTO_CHARGING;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_CHECK_ENV;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_AUTO_MAPPING;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_FOLLOW;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_STRANGER_WELCOME;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_OWNER_WELCOME;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_BEHAVIOR_INTERACTION;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_HANDSHAKE;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_STANDBY_ACCOMPANY;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_HAPPY_ACCOMPANY;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_WORK_ACCOMPANY;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_POSITIVE_ACCOMPANY;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_NEGATIVE_ACCOMPANY;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_CHILD_WATCH;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_OLDER_WATCH;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_DANGER_REMINDER;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_EVENT_REMINDER;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_CATWALK_START;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_CATWALK_ACT;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_CATWALK_SHOW;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_CATWALK_BACK;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_FREE_TIME;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_SOCIALIZE;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_SPECT_PERFORM;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_FACE_DETCTION;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_DANGER_INFO;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_HAND_OK;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_HAND_V;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_HAND_SHAKE;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_HAND_COME;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_HAND_WAVE;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_CAMERA_DEMO;
template<typename ContainerAllocator>
constexpr uint32_t PercReq_<ContainerAllocator>::PERC_CANCEL;

}  // namespace msg

}  // namespace perception_msgs

#endif  // PERCEPTION_MSGS__MSG__DETAIL__PERC_REQ__STRUCT_HPP_
