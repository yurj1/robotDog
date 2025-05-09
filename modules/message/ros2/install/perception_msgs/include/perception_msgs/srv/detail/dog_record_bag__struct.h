// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from perception_msgs:srv/DogRecordBag.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__SRV__DETAIL__DOG_RECORD_BAG__STRUCT_H_
#define PERCEPTION_MSGS__SRV__DETAIL__DOG_RECORD_BAG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'bag_name'
// Member 'topics'
// Member 'bash_name'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/DogRecordBag in the package perception_msgs.
typedef struct perception_msgs__srv__DogRecordBag_Request
{
  uint8_t bag_mode;
  rosidl_runtime_c__String bag_name;
  rosidl_runtime_c__String__Sequence topics;
  rosidl_runtime_c__String bash_name;
} perception_msgs__srv__DogRecordBag_Request;

// Struct for a sequence of perception_msgs__srv__DogRecordBag_Request.
typedef struct perception_msgs__srv__DogRecordBag_Request__Sequence
{
  perception_msgs__srv__DogRecordBag_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} perception_msgs__srv__DogRecordBag_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'error_info'
// already included above
// #include "rosidl_runtime_c/string.h"

// Struct defined in srv/DogRecordBag in the package perception_msgs.
typedef struct perception_msgs__srv__DogRecordBag_Response
{
  bool success;
  rosidl_runtime_c__String error_info;
} perception_msgs__srv__DogRecordBag_Response;

// Struct for a sequence of perception_msgs__srv__DogRecordBag_Response.
typedef struct perception_msgs__srv__DogRecordBag_Response__Sequence
{
  perception_msgs__srv__DogRecordBag_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} perception_msgs__srv__DogRecordBag_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PERCEPTION_MSGS__SRV__DETAIL__DOG_RECORD_BAG__STRUCT_H_
