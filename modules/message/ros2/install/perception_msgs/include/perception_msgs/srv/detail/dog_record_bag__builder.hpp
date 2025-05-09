// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from perception_msgs:srv/DogRecordBag.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__SRV__DETAIL__DOG_RECORD_BAG__BUILDER_HPP_
#define PERCEPTION_MSGS__SRV__DETAIL__DOG_RECORD_BAG__BUILDER_HPP_

#include "perception_msgs/srv/detail/dog_record_bag__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace perception_msgs
{

namespace srv
{

namespace builder
{

class Init_DogRecordBag_Request_bash_name
{
public:
  explicit Init_DogRecordBag_Request_bash_name(::perception_msgs::srv::DogRecordBag_Request & msg)
  : msg_(msg)
  {}
  ::perception_msgs::srv::DogRecordBag_Request bash_name(::perception_msgs::srv::DogRecordBag_Request::_bash_name_type arg)
  {
    msg_.bash_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::perception_msgs::srv::DogRecordBag_Request msg_;
};

class Init_DogRecordBag_Request_topics
{
public:
  explicit Init_DogRecordBag_Request_topics(::perception_msgs::srv::DogRecordBag_Request & msg)
  : msg_(msg)
  {}
  Init_DogRecordBag_Request_bash_name topics(::perception_msgs::srv::DogRecordBag_Request::_topics_type arg)
  {
    msg_.topics = std::move(arg);
    return Init_DogRecordBag_Request_bash_name(msg_);
  }

private:
  ::perception_msgs::srv::DogRecordBag_Request msg_;
};

class Init_DogRecordBag_Request_bag_name
{
public:
  explicit Init_DogRecordBag_Request_bag_name(::perception_msgs::srv::DogRecordBag_Request & msg)
  : msg_(msg)
  {}
  Init_DogRecordBag_Request_topics bag_name(::perception_msgs::srv::DogRecordBag_Request::_bag_name_type arg)
  {
    msg_.bag_name = std::move(arg);
    return Init_DogRecordBag_Request_topics(msg_);
  }

private:
  ::perception_msgs::srv::DogRecordBag_Request msg_;
};

class Init_DogRecordBag_Request_bag_mode
{
public:
  Init_DogRecordBag_Request_bag_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DogRecordBag_Request_bag_name bag_mode(::perception_msgs::srv::DogRecordBag_Request::_bag_mode_type arg)
  {
    msg_.bag_mode = std::move(arg);
    return Init_DogRecordBag_Request_bag_name(msg_);
  }

private:
  ::perception_msgs::srv::DogRecordBag_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::perception_msgs::srv::DogRecordBag_Request>()
{
  return perception_msgs::srv::builder::Init_DogRecordBag_Request_bag_mode();
}

}  // namespace perception_msgs


namespace perception_msgs
{

namespace srv
{

namespace builder
{

class Init_DogRecordBag_Response_error_info
{
public:
  explicit Init_DogRecordBag_Response_error_info(::perception_msgs::srv::DogRecordBag_Response & msg)
  : msg_(msg)
  {}
  ::perception_msgs::srv::DogRecordBag_Response error_info(::perception_msgs::srv::DogRecordBag_Response::_error_info_type arg)
  {
    msg_.error_info = std::move(arg);
    return std::move(msg_);
  }

private:
  ::perception_msgs::srv::DogRecordBag_Response msg_;
};

class Init_DogRecordBag_Response_success
{
public:
  Init_DogRecordBag_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DogRecordBag_Response_error_info success(::perception_msgs::srv::DogRecordBag_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_DogRecordBag_Response_error_info(msg_);
  }

private:
  ::perception_msgs::srv::DogRecordBag_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::perception_msgs::srv::DogRecordBag_Response>()
{
  return perception_msgs::srv::builder::Init_DogRecordBag_Response_success();
}

}  // namespace perception_msgs

#endif  // PERCEPTION_MSGS__SRV__DETAIL__DOG_RECORD_BAG__BUILDER_HPP_
