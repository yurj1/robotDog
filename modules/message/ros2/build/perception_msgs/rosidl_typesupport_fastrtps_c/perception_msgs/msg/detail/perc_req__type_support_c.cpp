// generated from rosidl_typesupport_fastrtps_c/resource/idl__type_support_c.cpp.em
// with input from perception_msgs:msg/PercReq.idl
// generated code does not contain a copyright notice
#include "perception_msgs/msg/detail/perc_req__rosidl_typesupport_fastrtps_c.h"


#include <cassert>
#include <limits>
#include <string>
#include "rosidl_typesupport_fastrtps_c/identifier.h"
#include "rosidl_typesupport_fastrtps_c/wstring_conversion.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "perception_msgs/msg/rosidl_typesupport_fastrtps_c__visibility_control.h"
#include "perception_msgs/msg/detail/perc_req__struct.h"
#include "perception_msgs/msg/detail/perc_req__functions.h"
#include "fastcdr/Cdr.h"

#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-parameter"
# ifdef __clang__
#  pragma clang diagnostic ignored "-Wdeprecated-register"
#  pragma clang diagnostic ignored "-Wreturn-type-c-linkage"
# endif
#endif
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif

// includes and forward declarations of message dependencies and their conversion functions

#if defined(__cplusplus)
extern "C"
{
#endif

#include "rosidl_runtime_c/string.h"  // danger_info
#include "rosidl_runtime_c/string_functions.h"  // danger_info

// forward declare type support functions


using _PercReq__ros_msg_type = perception_msgs__msg__PercReq;

static bool _PercReq__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  const _PercReq__ros_msg_type * ros_message = static_cast<const _PercReq__ros_msg_type *>(untyped_ros_message);
  // Field name: req_id
  {
    cdr << ros_message->req_id;
  }

  // Field name: perc_kind
  {
    cdr << ros_message->perc_kind;
  }

  // Field name: danger_info
  {
    const rosidl_runtime_c__String * str = &ros_message->danger_info;
    if (str->capacity == 0 || str->capacity <= str->size) {
      fprintf(stderr, "string capacity not greater than size\n");
      return false;
    }
    if (str->data[str->size] != '\0') {
      fprintf(stderr, "string not null-terminated\n");
      return false;
    }
    cdr << str->data;
  }

  return true;
}

static bool _PercReq__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  if (!untyped_ros_message) {
    fprintf(stderr, "ros message handle is null\n");
    return false;
  }
  _PercReq__ros_msg_type * ros_message = static_cast<_PercReq__ros_msg_type *>(untyped_ros_message);
  // Field name: req_id
  {
    cdr >> ros_message->req_id;
  }

  // Field name: perc_kind
  {
    cdr >> ros_message->perc_kind;
  }

  // Field name: danger_info
  {
    std::string tmp;
    cdr >> tmp;
    if (!ros_message->danger_info.data) {
      rosidl_runtime_c__String__init(&ros_message->danger_info);
    }
    bool succeeded = rosidl_runtime_c__String__assign(
      &ros_message->danger_info,
      tmp.c_str());
    if (!succeeded) {
      fprintf(stderr, "failed to assign string into field 'danger_info'\n");
      return false;
    }
  }

  return true;
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_perception_msgs
size_t get_serialized_size_perception_msgs__msg__PercReq(
  const void * untyped_ros_message,
  size_t current_alignment)
{
  const _PercReq__ros_msg_type * ros_message = static_cast<const _PercReq__ros_msg_type *>(untyped_ros_message);
  (void)ros_message;
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // field.name req_id
  {
    size_t item_size = sizeof(ros_message->req_id);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name perc_kind
  {
    size_t item_size = sizeof(ros_message->perc_kind);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // field.name danger_info
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message->danger_info.size + 1);

  return current_alignment - initial_alignment;
}

static uint32_t _PercReq__get_serialized_size(const void * untyped_ros_message)
{
  return static_cast<uint32_t>(
    get_serialized_size_perception_msgs__msg__PercReq(
      untyped_ros_message, 0));
}

ROSIDL_TYPESUPPORT_FASTRTPS_C_PUBLIC_perception_msgs
size_t max_serialized_size_perception_msgs__msg__PercReq(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;

  // member: req_id
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint64_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint64_t));
  }
  // member: perc_kind
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }
  // member: danger_info
  {
    size_t array_size = 1;

    full_bounded = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  return current_alignment - initial_alignment;
}

static size_t _PercReq__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_perception_msgs__msg__PercReq(
    full_bounded, 0);
}


static message_type_support_callbacks_t __callbacks_PercReq = {
  "perception_msgs::msg",
  "PercReq",
  _PercReq__cdr_serialize,
  _PercReq__cdr_deserialize,
  _PercReq__get_serialized_size,
  _PercReq__max_serialized_size
};

static rosidl_message_type_support_t _PercReq__type_support = {
  rosidl_typesupport_fastrtps_c__identifier,
  &__callbacks_PercReq,
  get_message_typesupport_handle_function,
};

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, perception_msgs, msg, PercReq)() {
  return &_PercReq__type_support;
}

#if defined(__cplusplus)
}
#endif
