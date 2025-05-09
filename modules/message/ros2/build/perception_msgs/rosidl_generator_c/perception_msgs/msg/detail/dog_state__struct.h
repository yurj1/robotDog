// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from perception_msgs:msg/DogState.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__DOG_STATE__STRUCT_H_
#define PERCEPTION_MSGS__MSG__DETAIL__DOG_STATE__STRUCT_H_

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
// Member 'alarm_info'
#include "perception_msgs/msg/detail/alarm_entry__struct.h"

// Struct defined in msg/DogState in the package perception_msgs.
typedef struct perception_msgs__msg__DogState
{
  double battery;
  uint8_t charging_state;
  uint8_t gesture;
  double speed;
  uint8_t person_state;
  geometry_msgs__msg__Pose target_position;
  perception_msgs__msg__AlarmEntry__Sequence alarm_info;
} perception_msgs__msg__DogState;

// Struct for a sequence of perception_msgs__msg__DogState.
typedef struct perception_msgs__msg__DogState__Sequence
{
  perception_msgs__msg__DogState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} perception_msgs__msg__DogState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PERCEPTION_MSGS__MSG__DETAIL__DOG_STATE__STRUCT_H_
