// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from perception_msgs:srv/DogRecordBag.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__SRV__DETAIL__DOG_RECORD_BAG__TRAITS_HPP_
#define PERCEPTION_MSGS__SRV__DETAIL__DOG_RECORD_BAG__TRAITS_HPP_

#include "perception_msgs/srv/detail/dog_record_bag__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<perception_msgs::srv::DogRecordBag_Request>()
{
  return "perception_msgs::srv::DogRecordBag_Request";
}

template<>
inline const char * name<perception_msgs::srv::DogRecordBag_Request>()
{
  return "perception_msgs/srv/DogRecordBag_Request";
}

template<>
struct has_fixed_size<perception_msgs::srv::DogRecordBag_Request>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<perception_msgs::srv::DogRecordBag_Request>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<perception_msgs::srv::DogRecordBag_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<perception_msgs::srv::DogRecordBag_Response>()
{
  return "perception_msgs::srv::DogRecordBag_Response";
}

template<>
inline const char * name<perception_msgs::srv::DogRecordBag_Response>()
{
  return "perception_msgs/srv/DogRecordBag_Response";
}

template<>
struct has_fixed_size<perception_msgs::srv::DogRecordBag_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<perception_msgs::srv::DogRecordBag_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<perception_msgs::srv::DogRecordBag_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<perception_msgs::srv::DogRecordBag>()
{
  return "perception_msgs::srv::DogRecordBag";
}

template<>
inline const char * name<perception_msgs::srv::DogRecordBag>()
{
  return "perception_msgs/srv/DogRecordBag";
}

template<>
struct has_fixed_size<perception_msgs::srv::DogRecordBag>
  : std::integral_constant<
    bool,
    has_fixed_size<perception_msgs::srv::DogRecordBag_Request>::value &&
    has_fixed_size<perception_msgs::srv::DogRecordBag_Response>::value
  >
{
};

template<>
struct has_bounded_size<perception_msgs::srv::DogRecordBag>
  : std::integral_constant<
    bool,
    has_bounded_size<perception_msgs::srv::DogRecordBag_Request>::value &&
    has_bounded_size<perception_msgs::srv::DogRecordBag_Response>::value
  >
{
};

template<>
struct is_service<perception_msgs::srv::DogRecordBag>
  : std::true_type
{
};

template<>
struct is_service_request<perception_msgs::srv::DogRecordBag_Request>
  : std::true_type
{
};

template<>
struct is_service_response<perception_msgs::srv::DogRecordBag_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // PERCEPTION_MSGS__SRV__DETAIL__DOG_RECORD_BAG__TRAITS_HPP_
