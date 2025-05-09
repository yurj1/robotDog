// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from perception_msgs:msg/AlarmEntry.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__ALARM_ENTRY__STRUCT_H_
#define PERCEPTION_MSGS__MSG__DETAIL__ALARM_ENTRY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/AlarmEntry in the package perception_msgs.
typedef struct perception_msgs__msg__AlarmEntry
{
  int32_t id;
  int32_t source;
  int32_t level;
  int32_t status;
  rosidl_runtime_c__String message;
} perception_msgs__msg__AlarmEntry;

// Struct for a sequence of perception_msgs__msg__AlarmEntry.
typedef struct perception_msgs__msg__AlarmEntry__Sequence
{
  perception_msgs__msg__AlarmEntry * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} perception_msgs__msg__AlarmEntry__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PERCEPTION_MSGS__MSG__DETAIL__ALARM_ENTRY__STRUCT_H_
