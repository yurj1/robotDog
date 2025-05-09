// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from perception_msgs:msg/ActionEntry.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__ACTION_ENTRY__STRUCT_H_
#define PERCEPTION_MSGS__MSG__DETAIL__ACTION_ENTRY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'param3'
// Member 'info'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/ActionEntry in the package perception_msgs.
typedef struct perception_msgs__msg__ActionEntry
{
  int32_t id;
  int32_t param1;
  int32_t param2;
  rosidl_runtime_c__String param3;
  rosidl_runtime_c__String info;
} perception_msgs__msg__ActionEntry;

// Struct for a sequence of perception_msgs__msg__ActionEntry.
typedef struct perception_msgs__msg__ActionEntry__Sequence
{
  perception_msgs__msg__ActionEntry * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} perception_msgs__msg__ActionEntry__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PERCEPTION_MSGS__MSG__DETAIL__ACTION_ENTRY__STRUCT_H_
