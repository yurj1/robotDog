// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from perception_msgs:srv/DogRecordBag.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__SRV__DETAIL__DOG_RECORD_BAG__STRUCT_HPP_
#define PERCEPTION_MSGS__SRV__DETAIL__DOG_RECORD_BAG__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__perception_msgs__srv__DogRecordBag_Request __attribute__((deprecated))
#else
# define DEPRECATED__perception_msgs__srv__DogRecordBag_Request __declspec(deprecated)
#endif

namespace perception_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DogRecordBag_Request_
{
  using Type = DogRecordBag_Request_<ContainerAllocator>;

  explicit DogRecordBag_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->bag_mode = 0;
      this->bag_name = "";
      this->bash_name = "";
    }
  }

  explicit DogRecordBag_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : bag_name(_alloc),
    bash_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->bag_mode = 0;
      this->bag_name = "";
      this->bash_name = "";
    }
  }

  // field types and members
  using _bag_mode_type =
    uint8_t;
  _bag_mode_type bag_mode;
  using _bag_name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _bag_name_type bag_name;
  using _topics_type =
    std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>, typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>>::other>;
  _topics_type topics;
  using _bash_name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _bash_name_type bash_name;

  // setters for named parameter idiom
  Type & set__bag_mode(
    const uint8_t & _arg)
  {
    this->bag_mode = _arg;
    return *this;
  }
  Type & set__bag_name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->bag_name = _arg;
    return *this;
  }
  Type & set__topics(
    const std::vector<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>, typename ContainerAllocator::template rebind<std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>>::other> & _arg)
  {
    this->topics = _arg;
    return *this;
  }
  Type & set__bash_name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->bash_name = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    perception_msgs::srv::DogRecordBag_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const perception_msgs::srv::DogRecordBag_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<perception_msgs::srv::DogRecordBag_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<perception_msgs::srv::DogRecordBag_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      perception_msgs::srv::DogRecordBag_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<perception_msgs::srv::DogRecordBag_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      perception_msgs::srv::DogRecordBag_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<perception_msgs::srv::DogRecordBag_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<perception_msgs::srv::DogRecordBag_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<perception_msgs::srv::DogRecordBag_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__perception_msgs__srv__DogRecordBag_Request
    std::shared_ptr<perception_msgs::srv::DogRecordBag_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__perception_msgs__srv__DogRecordBag_Request
    std::shared_ptr<perception_msgs::srv::DogRecordBag_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DogRecordBag_Request_ & other) const
  {
    if (this->bag_mode != other.bag_mode) {
      return false;
    }
    if (this->bag_name != other.bag_name) {
      return false;
    }
    if (this->topics != other.topics) {
      return false;
    }
    if (this->bash_name != other.bash_name) {
      return false;
    }
    return true;
  }
  bool operator!=(const DogRecordBag_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DogRecordBag_Request_

// alias to use template instance with default allocator
using DogRecordBag_Request =
  perception_msgs::srv::DogRecordBag_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace perception_msgs


#ifndef _WIN32
# define DEPRECATED__perception_msgs__srv__DogRecordBag_Response __attribute__((deprecated))
#else
# define DEPRECATED__perception_msgs__srv__DogRecordBag_Response __declspec(deprecated)
#endif

namespace perception_msgs
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct DogRecordBag_Response_
{
  using Type = DogRecordBag_Response_<ContainerAllocator>;

  explicit DogRecordBag_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->error_info = "";
    }
  }

  explicit DogRecordBag_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : error_info(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->success = false;
      this->error_info = "";
    }
  }

  // field types and members
  using _success_type =
    bool;
  _success_type success;
  using _error_info_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _error_info_type error_info;

  // setters for named parameter idiom
  Type & set__success(
    const bool & _arg)
  {
    this->success = _arg;
    return *this;
  }
  Type & set__error_info(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->error_info = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    perception_msgs::srv::DogRecordBag_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const perception_msgs::srv::DogRecordBag_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<perception_msgs::srv::DogRecordBag_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<perception_msgs::srv::DogRecordBag_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      perception_msgs::srv::DogRecordBag_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<perception_msgs::srv::DogRecordBag_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      perception_msgs::srv::DogRecordBag_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<perception_msgs::srv::DogRecordBag_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<perception_msgs::srv::DogRecordBag_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<perception_msgs::srv::DogRecordBag_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__perception_msgs__srv__DogRecordBag_Response
    std::shared_ptr<perception_msgs::srv::DogRecordBag_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__perception_msgs__srv__DogRecordBag_Response
    std::shared_ptr<perception_msgs::srv::DogRecordBag_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DogRecordBag_Response_ & other) const
  {
    if (this->success != other.success) {
      return false;
    }
    if (this->error_info != other.error_info) {
      return false;
    }
    return true;
  }
  bool operator!=(const DogRecordBag_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DogRecordBag_Response_

// alias to use template instance with default allocator
using DogRecordBag_Response =
  perception_msgs::srv::DogRecordBag_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace perception_msgs

namespace perception_msgs
{

namespace srv
{

struct DogRecordBag
{
  using Request = perception_msgs::srv::DogRecordBag_Request;
  using Response = perception_msgs::srv::DogRecordBag_Response;
};

}  // namespace srv

}  // namespace perception_msgs

#endif  // PERCEPTION_MSGS__SRV__DETAIL__DOG_RECORD_BAG__STRUCT_HPP_
