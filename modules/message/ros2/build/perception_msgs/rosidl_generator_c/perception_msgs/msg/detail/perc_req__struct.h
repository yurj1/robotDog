// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from perception_msgs:msg/PercReq.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__PERC_REQ__STRUCT_H_
#define PERCEPTION_MSGS__MSG__DETAIL__PERC_REQ__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'PERC_AUTO_CHARGING'.
enum
{
  perception_msgs__msg__PercReq__PERC_AUTO_CHARGING = 20ul
};

/// Constant 'PERC_CHECK_ENV'.
enum
{
  perception_msgs__msg__PercReq__PERC_CHECK_ENV = 21ul
};

/// Constant 'PERC_AUTO_MAPPING'.
enum
{
  perception_msgs__msg__PercReq__PERC_AUTO_MAPPING = 22ul
};

/// Constant 'PERC_FOLLOW'.
enum
{
  perception_msgs__msg__PercReq__PERC_FOLLOW = 30ul
};

/// Constant 'PERC_STRANGER_WELCOME'.
enum
{
  perception_msgs__msg__PercReq__PERC_STRANGER_WELCOME = 31ul
};

/// Constant 'PERC_OWNER_WELCOME'.
enum
{
  perception_msgs__msg__PercReq__PERC_OWNER_WELCOME = 32ul
};

/// Constant 'PERC_BEHAVIOR_INTERACTION'.
enum
{
  perception_msgs__msg__PercReq__PERC_BEHAVIOR_INTERACTION = 33ul
};

/// Constant 'PERC_HANDSHAKE'.
enum
{
  perception_msgs__msg__PercReq__PERC_HANDSHAKE = 34ul
};

/// Constant 'PERC_STANDBY_ACCOMPANY'.
enum
{
  perception_msgs__msg__PercReq__PERC_STANDBY_ACCOMPANY = 35ul
};

/// Constant 'PERC_HAPPY_ACCOMPANY'.
enum
{
  perception_msgs__msg__PercReq__PERC_HAPPY_ACCOMPANY = 36ul
};

/// Constant 'PERC_WORK_ACCOMPANY'.
enum
{
  perception_msgs__msg__PercReq__PERC_WORK_ACCOMPANY = 37ul
};

/// Constant 'PERC_POSITIVE_ACCOMPANY'.
enum
{
  perception_msgs__msg__PercReq__PERC_POSITIVE_ACCOMPANY = 38ul
};

/// Constant 'PERC_NEGATIVE_ACCOMPANY'.
enum
{
  perception_msgs__msg__PercReq__PERC_NEGATIVE_ACCOMPANY = 39ul
};

/// Constant 'PERC_CHILD_WATCH'.
enum
{
  perception_msgs__msg__PercReq__PERC_CHILD_WATCH = 40ul
};

/// Constant 'PERC_OLDER_WATCH'.
enum
{
  perception_msgs__msg__PercReq__PERC_OLDER_WATCH = 41ul
};

/// Constant 'PERC_DANGER_REMINDER'.
enum
{
  perception_msgs__msg__PercReq__PERC_DANGER_REMINDER = 42ul
};

/// Constant 'PERC_EVENT_REMINDER'.
enum
{
  perception_msgs__msg__PercReq__PERC_EVENT_REMINDER = 43ul
};

/// Constant 'PERC_CATWALK_START'.
enum
{
  perception_msgs__msg__PercReq__PERC_CATWALK_START = 44ul
};

/// Constant 'PERC_CATWALK_ACT'.
enum
{
  perception_msgs__msg__PercReq__PERC_CATWALK_ACT = 45ul
};

/// Constant 'PERC_CATWALK_SHOW'.
enum
{
  perception_msgs__msg__PercReq__PERC_CATWALK_SHOW = 46ul
};

/// Constant 'PERC_CATWALK_BACK'.
enum
{
  perception_msgs__msg__PercReq__PERC_CATWALK_BACK = 47ul
};

/// Constant 'PERC_FREE_TIME'.
enum
{
  perception_msgs__msg__PercReq__PERC_FREE_TIME = 50ul
};

/// Constant 'PERC_SOCIALIZE'.
enum
{
  perception_msgs__msg__PercReq__PERC_SOCIALIZE = 51ul
};

/// Constant 'PERC_SPECT_PERFORM'.
enum
{
  perception_msgs__msg__PercReq__PERC_SPECT_PERFORM = 55ul
};

/// Constant 'PERC_FACE_DETCTION'.
enum
{
  perception_msgs__msg__PercReq__PERC_FACE_DETCTION = 56ul
};

/// Constant 'PERC_DANGER_INFO'.
enum
{
  perception_msgs__msg__PercReq__PERC_DANGER_INFO = 60ul
};

/// Constant 'PERC_HAND_OK'.
enum
{
  perception_msgs__msg__PercReq__PERC_HAND_OK = 70ul
};

/// Constant 'PERC_HAND_V'.
enum
{
  perception_msgs__msg__PercReq__PERC_HAND_V = 71ul
};

/// Constant 'PERC_HAND_SHAKE'.
enum
{
  perception_msgs__msg__PercReq__PERC_HAND_SHAKE = 72ul
};

/// Constant 'PERC_HAND_COME'.
enum
{
  perception_msgs__msg__PercReq__PERC_HAND_COME = 73ul
};

/// Constant 'PERC_HAND_WAVE'.
enum
{
  perception_msgs__msg__PercReq__PERC_HAND_WAVE = 74ul
};

/// Constant 'PERC_CAMERA_DEMO'.
enum
{
  perception_msgs__msg__PercReq__PERC_CAMERA_DEMO = 80ul
};

/// Constant 'PERC_CANCEL'.
enum
{
  perception_msgs__msg__PercReq__PERC_CANCEL = 100ul
};

// Include directives for member types
// Member 'danger_info'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/PercReq in the package perception_msgs.
typedef struct perception_msgs__msg__PercReq
{
  uint64_t req_id;
  uint32_t perc_kind;
  rosidl_runtime_c__String danger_info;
} perception_msgs__msg__PercReq;

// Struct for a sequence of perception_msgs__msg__PercReq.
typedef struct perception_msgs__msg__PercReq__Sequence
{
  perception_msgs__msg__PercReq * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} perception_msgs__msg__PercReq__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PERCEPTION_MSGS__MSG__DETAIL__PERC_REQ__STRUCT_H_
