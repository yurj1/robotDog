// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from perception_msgs:msg/PercState.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__PERC_STATE__STRUCT_HPP_
#define PERCEPTION_MSGS__MSG__DETAIL__PERC_STATE__STRUCT_HPP_

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

#ifndef _WIN32
# define DEPRECATED__perception_msgs__msg__PercState __attribute__((deprecated))
#else
# define DEPRECATED__perception_msgs__msg__PercState __declspec(deprecated)
#endif

namespace perception_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PercState_
{
  using Type = PercState_<ContainerAllocator>;

  explicit PercState_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->action_id = 0ull;
      this->perc_kind = 0ul;
      this->exe_state = 0;
      this->exe_result = 0;
      this->err_code = 0;
      this->err_info = "";
      this->wait_for_millisec = 0ull;
    }
  }

  explicit PercState_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    err_info(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->action_id = 0ull;
      this->perc_kind = 0ul;
      this->exe_state = 0;
      this->exe_result = 0;
      this->err_code = 0;
      this->err_info = "";
      this->wait_for_millisec = 0ull;
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
  using _exe_state_type =
    uint8_t;
  _exe_state_type exe_state;
  using _exe_result_type =
    uint8_t;
  _exe_result_type exe_result;
  using _err_code_type =
    uint16_t;
  _err_code_type err_code;
  using _err_info_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _err_info_type err_info;
  using _wait_for_millisec_type =
    uint64_t;
  _wait_for_millisec_type wait_for_millisec;

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
  Type & set__exe_state(
    const uint8_t & _arg)
  {
    this->exe_state = _arg;
    return *this;
  }
  Type & set__exe_result(
    const uint8_t & _arg)
  {
    this->exe_result = _arg;
    return *this;
  }
  Type & set__err_code(
    const uint16_t & _arg)
  {
    this->err_code = _arg;
    return *this;
  }
  Type & set__err_info(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->err_info = _arg;
    return *this;
  }
  Type & set__wait_for_millisec(
    const uint64_t & _arg)
  {
    this->wait_for_millisec = _arg;
    return *this;
  }

  // constant declarations
  static constexpr uint8_t ACTION_IDLE =
    0u;
  static constexpr uint8_t ACTION_RUNNING =
    1u;
  static constexpr uint8_t ACTION_DONE =
    2u;
  static constexpr uint8_t ACTION_NONE =
    0u;
  static constexpr uint8_t ACTION_SUCCESS =
    1u;
  static constexpr uint8_t ACTION_FAIL =
    2u;
  static constexpr uint16_t ACTION_ERR_NONE =
    0u;
  static constexpr uint16_t ACTION_ERR_NOWORK =
    1u;
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
  static constexpr uint32_t PERC_DANGER_INFO =
    60u;
  static constexpr uint32_t PERC_WELCOME_DEMO =
    70u;
  static constexpr uint32_t PERC_CANCEL =
    100u;
  static constexpr uint32_t PERC_NODE_CLOSE =
    200u;
  static constexpr uint32_t PERC_NODE_START =
    201u;
  static constexpr uint32_t PERC_NODE_RESET =
    202u;

  // pointer types
  using RawPtr =
    perception_msgs::msg::PercState_<ContainerAllocator> *;
  using ConstRawPtr =
    const perception_msgs::msg::PercState_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<perception_msgs::msg::PercState_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<perception_msgs::msg::PercState_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      perception_msgs::msg::PercState_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<perception_msgs::msg::PercState_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      perception_msgs::msg::PercState_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<perception_msgs::msg::PercState_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<perception_msgs::msg::PercState_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<perception_msgs::msg::PercState_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__perception_msgs__msg__PercState
    std::shared_ptr<perception_msgs::msg::PercState_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__perception_msgs__msg__PercState
    std::shared_ptr<perception_msgs::msg::PercState_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PercState_ & other) const
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
    if (this->exe_state != other.exe_state) {
      return false;
    }
    if (this->exe_result != other.exe_result) {
      return false;
    }
    if (this->err_code != other.err_code) {
      return false;
    }
    if (this->err_info != other.err_info) {
      return false;
    }
    if (this->wait_for_millisec != other.wait_for_millisec) {
      return false;
    }
    return true;
  }
  bool operator!=(const PercState_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PercState_

// alias to use template instance with default allocator
using PercState =
  perception_msgs::msg::PercState_<std::allocator<void>>;

// constant definitions
template<typename ContainerAllocator>
constexpr uint8_t PercState_<ContainerAllocator>::ACTION_IDLE;
template<typename ContainerAllocator>
constexpr uint8_t PercState_<ContainerAllocator>::ACTION_RUNNING;
template<typename ContainerAllocator>
constexpr uint8_t PercState_<ContainerAllocator>::ACTION_DONE;
template<typename ContainerAllocator>
constexpr uint8_t PercState_<ContainerAllocator>::ACTION_NONE;
template<typename ContainerAllocator>
constexpr uint8_t PercState_<ContainerAllocator>::ACTION_SUCCESS;
template<typename ContainerAllocator>
constexpr uint8_t PercState_<ContainerAllocator>::ACTION_FAIL;
template<typename ContainerAllocator>
constexpr uint16_t PercState_<ContainerAllocator>::ACTION_ERR_NONE;
template<typename ContainerAllocator>
constexpr uint16_t PercState_<ContainerAllocator>::ACTION_ERR_NOWORK;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_DEST;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_ABS;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_REL;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_AUTO_CHARGING;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_CHECK_ENV;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_AUTO_MAPPING;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_FOLLOW;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_STRANGER_WELCOME;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_OWNER_WELCOME;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_BEHAVIOR_INTERACTION;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_HANDSHAKE;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_STANDBY_ACCOMPANY;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_HAPPY_ACCOMPANY;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_WORK_ACCOMPANY;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_POSITIVE_ACCOMPANY;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_NEGATIVE_ACCOMPANY;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_CHILD_WATCH;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_OLDER_WATCH;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_DANGER_REMINDER;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_EVENT_REMINDER;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_CATWALK_START;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_CATWALK_ACT;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_CATWALK_SHOW;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_CATWALK_BACK;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_FREE_TIME;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_SOCIALIZE;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_DANGER_INFO;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_WELCOME_DEMO;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_CANCEL;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_NODE_CLOSE;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_NODE_START;
template<typename ContainerAllocator>
constexpr uint32_t PercState_<ContainerAllocator>::PERC_NODE_RESET;

}  // namespace msg

}  // namespace perception_msgs

#endif  // PERCEPTION_MSGS__MSG__DETAIL__PERC_STATE__STRUCT_HPP_
