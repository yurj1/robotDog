// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from perception_msgs:msg/PercCmd.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__PERC_CMD__STRUCT_H_
#define PERCEPTION_MSGS__MSG__DETAIL__PERC_CMD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'PERC_DEST'.
enum
{
  perception_msgs__msg__PercCmd__PERC_DEST = 1ul
};

/// Constant 'PERC_ABS'.
enum
{
  perception_msgs__msg__PercCmd__PERC_ABS = 2ul
};

/// Constant 'PERC_REL'.
enum
{
  perception_msgs__msg__PercCmd__PERC_REL = 3ul
};

/// Constant 'PERC_AUTO_CHARGING'.
enum
{
  perception_msgs__msg__PercCmd__PERC_AUTO_CHARGING = 20ul
};

/// Constant 'PERC_CHECK_ENV'.
enum
{
  perception_msgs__msg__PercCmd__PERC_CHECK_ENV = 21ul
};

/// Constant 'PERC_AUTO_MAPPING'.
enum
{
  perception_msgs__msg__PercCmd__PERC_AUTO_MAPPING = 22ul
};

/// Constant 'PERC_FOLLOW'.
enum
{
  perception_msgs__msg__PercCmd__PERC_FOLLOW = 30ul
};

/// Constant 'PERC_STRANGER_WELCOME'.
enum
{
  perception_msgs__msg__PercCmd__PERC_STRANGER_WELCOME = 31ul
};

/// Constant 'PERC_OWNER_WELCOME'.
enum
{
  perception_msgs__msg__PercCmd__PERC_OWNER_WELCOME = 32ul
};

/// Constant 'PERC_BEHAVIOR_INTERACTION'.
enum
{
  perception_msgs__msg__PercCmd__PERC_BEHAVIOR_INTERACTION = 33ul
};

/// Constant 'PERC_HANDSHAKE'.
enum
{
  perception_msgs__msg__PercCmd__PERC_HANDSHAKE = 34ul
};

/// Constant 'PERC_STANDBY_ACCOMPANY'.
enum
{
  perception_msgs__msg__PercCmd__PERC_STANDBY_ACCOMPANY = 35ul
};

/// Constant 'PERC_HAPPY_ACCOMPANY'.
enum
{
  perception_msgs__msg__PercCmd__PERC_HAPPY_ACCOMPANY = 36ul
};

/// Constant 'PERC_WORK_ACCOMPANY'.
enum
{
  perception_msgs__msg__PercCmd__PERC_WORK_ACCOMPANY = 37ul
};

/// Constant 'PERC_POSITIVE_ACCOMPANY'.
enum
{
  perception_msgs__msg__PercCmd__PERC_POSITIVE_ACCOMPANY = 38ul
};

/// Constant 'PERC_NEGATIVE_ACCOMPANY'.
enum
{
  perception_msgs__msg__PercCmd__PERC_NEGATIVE_ACCOMPANY = 39ul
};

/// Constant 'PERC_CHILD_WATCH'.
enum
{
  perception_msgs__msg__PercCmd__PERC_CHILD_WATCH = 40ul
};

/// Constant 'PERC_OLDER_WATCH'.
enum
{
  perception_msgs__msg__PercCmd__PERC_OLDER_WATCH = 41ul
};

/// Constant 'PERC_DANGER_REMINDER'.
enum
{
  perception_msgs__msg__PercCmd__PERC_DANGER_REMINDER = 42ul
};

/// Constant 'PERC_EVENT_REMINDER'.
enum
{
  perception_msgs__msg__PercCmd__PERC_EVENT_REMINDER = 43ul
};

/// Constant 'PERC_CATWALK_START'.
enum
{
  perception_msgs__msg__PercCmd__PERC_CATWALK_START = 44ul
};

/// Constant 'PERC_CATWALK_ACT'.
enum
{
  perception_msgs__msg__PercCmd__PERC_CATWALK_ACT = 45ul
};

/// Constant 'PERC_CATWALK_SHOW'.
enum
{
  perception_msgs__msg__PercCmd__PERC_CATWALK_SHOW = 46ul
};

/// Constant 'PERC_CATWALK_BACK'.
enum
{
  perception_msgs__msg__PercCmd__PERC_CATWALK_BACK = 47ul
};

/// Constant 'PERC_FREE_TIME'.
enum
{
  perception_msgs__msg__PercCmd__PERC_FREE_TIME = 50ul
};

/// Constant 'PERC_SOCIALIZE'.
enum
{
  perception_msgs__msg__PercCmd__PERC_SOCIALIZE = 51ul
};

/// Constant 'PERC_SPECT_PERFORM'.
enum
{
  perception_msgs__msg__PercCmd__PERC_SPECT_PERFORM = 55ul
};

/// Constant 'PERC_FACE_DETCTION'.
enum
{
  perception_msgs__msg__PercCmd__PERC_FACE_DETCTION = 56ul
};

/// Constant 'PERC_DANGER_INFO'.
enum
{
  perception_msgs__msg__PercCmd__PERC_DANGER_INFO = 60ul
};

/// Constant 'PERC_WELCOME_DEMO'.
enum
{
  perception_msgs__msg__PercCmd__PERC_WELCOME_DEMO = 61ul
};

/// Constant 'PERC_LOBBY_DEMO'.
enum
{
  perception_msgs__msg__PercCmd__PERC_LOBBY_DEMO = 62ul
};

/// Constant 'PERC_CANCEL'.
enum
{
  perception_msgs__msg__PercCmd__PERC_CANCEL = 100ul
};

/// Constant 'PERC_NODE_CLOSE'.
enum
{
  perception_msgs__msg__PercCmd__PERC_NODE_CLOSE = 200ul
};

/// Constant 'PERC_NODE_START'.
enum
{
  perception_msgs__msg__PercCmd__PERC_NODE_START = 201ul
};

/// Constant 'PERC_NODE_RESET'.
enum
{
  perception_msgs__msg__PercCmd__PERC_NODE_RESET = 202ul
};

/// Constant 'FOLLOW_ON'.
enum
{
  perception_msgs__msg__PercCmd__FOLLOW_ON = 1ul
};

/// Constant 'FOLLOW_OFF'.
enum
{
  perception_msgs__msg__PercCmd__FOLLOW_OFF = 2ul
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'follow_name'
// Member 'point_name'
#include "rosidl_runtime_c/string.h"
// Member 'point'
#include "geometry_msgs/msg/detail/point__struct.h"

// Struct defined in msg/PercCmd in the package perception_msgs.
typedef struct perception_msgs__msg__PercCmd
{
  std_msgs__msg__Header header;
  uint64_t action_id;
  uint32_t perc_kind;
  uint64_t req_id;
  uint32_t on_off;
  rosidl_runtime_c__String follow_name;
  double angle;
  rosidl_runtime_c__String point_name;
  geometry_msgs__msg__Point point;
} perception_msgs__msg__PercCmd;

// Struct for a sequence of perception_msgs__msg__PercCmd.
typedef struct perception_msgs__msg__PercCmd__Sequence
{
  perception_msgs__msg__PercCmd * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} perception_msgs__msg__PercCmd__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PERCEPTION_MSGS__MSG__DETAIL__PERC_CMD__STRUCT_H_
