// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from perception_msgs:msg/TaskList.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__TASK_LIST__STRUCT_H_
#define PERCEPTION_MSGS__MSG__DETAIL__TASK_LIST__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'target_position'
#include "geometry_msgs/msg/detail/pose__struct.h"
// Member 'target_object'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/TaskList in the package perception_msgs.
typedef struct perception_msgs__msg__TaskList
{
  uint64_t task_id;
  uint32_t task_type;
  geometry_msgs__msg__Pose target_position;
  rosidl_runtime_c__String target_object;
  uint8_t task_state;
  uint8_t task_result;
  uint8_t is_in_place_rotation;
} perception_msgs__msg__TaskList;

// Struct for a sequence of perception_msgs__msg__TaskList.
typedef struct perception_msgs__msg__TaskList__Sequence
{
  perception_msgs__msg__TaskList * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} perception_msgs__msg__TaskList__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PERCEPTION_MSGS__MSG__DETAIL__TASK_LIST__STRUCT_H_
