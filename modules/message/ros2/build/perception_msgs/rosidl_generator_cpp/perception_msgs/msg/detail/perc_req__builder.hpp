// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from perception_msgs:msg/PercReq.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__PERC_REQ__BUILDER_HPP_
#define PERCEPTION_MSGS__MSG__DETAIL__PERC_REQ__BUILDER_HPP_

#include "perception_msgs/msg/detail/perc_req__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace perception_msgs
{

namespace msg
{

namespace builder
{

class Init_PercReq_danger_info
{
public:
  explicit Init_PercReq_danger_info(::perception_msgs::msg::PercReq & msg)
  : msg_(msg)
  {}
  ::perception_msgs::msg::PercReq danger_info(::perception_msgs::msg::PercReq::_danger_info_type arg)
  {
    msg_.danger_info = std::move(arg);
    return std::move(msg_);
  }

private:
  ::perception_msgs::msg::PercReq msg_;
};

class Init_PercReq_perc_kind
{
public:
  explicit Init_PercReq_perc_kind(::perception_msgs::msg::PercReq & msg)
  : msg_(msg)
  {}
  Init_PercReq_danger_info perc_kind(::perception_msgs::msg::PercReq::_perc_kind_type arg)
  {
    msg_.perc_kind = std::move(arg);
    return Init_PercReq_danger_info(msg_);
  }

private:
  ::perception_msgs::msg::PercReq msg_;
};

class Init_PercReq_req_id
{
public:
  Init_PercReq_req_id()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PercReq_perc_kind req_id(::perception_msgs::msg::PercReq::_req_id_type arg)
  {
    msg_.req_id = std::move(arg);
    return Init_PercReq_perc_kind(msg_);
  }

private:
  ::perception_msgs::msg::PercReq msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::perception_msgs::msg::PercReq>()
{
  return perception_msgs::msg::builder::Init_PercReq_req_id();
}

}  // namespace perception_msgs

#endif  // PERCEPTION_MSGS__MSG__DETAIL__PERC_REQ__BUILDER_HPP_
