// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from perception_msgs:msg/PercState.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__MSG__DETAIL__PERC_STATE__STRUCT_H_
#define PERCEPTION_MSGS__MSG__DETAIL__PERC_STATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'ACTION_IDLE'.
enum
{
  perception_msgs__msg__PercState__ACTION_IDLE = 0
};

/// Constant 'ACTION_RUNNING'.
enum
{
  perception_msgs__msg__PercState__ACTION_RUNNING = 1
};

/// Constant 'ACTION_DONE'.
enum
{
  perception_msgs__msg__PercState__ACTION_DONE = 2
};

/// Constant 'ACTION_NONE'.
enum
{
  perception_msgs__msg__PercState__ACTION_NONE = 0
};

/// Constant 'ACTION_SUCCESS'.
enum
{
  perception_msgs__msg__PercState__ACTION_SUCCESS = 1
};

/// Constant 'ACTION_FAIL'.
enum
{
  perception_msgs__msg__PercState__ACTION_FAIL = 2
};

/// Constant 'ACTION_ERR_NONE'.
enum
{
  perception_msgs__msg__PercState__ACTION_ERR_NONE = 0
};

/// Constant 'ACTION_ERR_NOWORK'.
enum
{
  perception_msgs__msg__PercState__ACTION_ERR_NOWORK = 1
};

/// Constant 'PERC_DEST'.
enum
{
  perception_msgs__msg__PercState__PERC_DEST = 1ul
};

/// Constant 'PERC_ABS'.
enum
{
  perception_msgs__msg__PercState__PERC_ABS = 2ul
};

/// Constant 'PERC_REL'.
enum
{
  perception_msgs__msg__PercState__PERC_REL = 3ul
};

/// Constant 'PERC_AUTO_CHARGING'.
enum
{
  perception_msgs__msg__PercState__PERC_AUTO_CHARGING = 20ul
};

/// Constant 'PERC_CHECK_ENV'.
enum
{
  perception_msgs__msg__PercState__PERC_CHECK_ENV = 21ul
};

/// Constant 'PERC_AUTO_MAPPING'.
enum
{
  perception_msgs__msg__PercState__PERC_AUTO_MAPPING = 22ul
};

/// Constant 'PERC_FOLLOW'.
enum
{
  perception_msgs__msg__PercState__PERC_FOLLOW = 30ul
};

/// Constant 'PERC_STRANGER_WELCOME'.
enum
{
  perception_msgs__msg__PercState__PERC_STRANGER_WELCOME = 31ul
};

/// Constant 'PERC_OWNER_WELCOME'.
enum
{
  perception_msgs__msg__PercState__PERC_OWNER_WELCOME = 32ul
};

/// Constant 'PERC_BEHAVIOR_INTERACTION'.
enum
{
  perception_msgs__msg__PercState__PERC_BEHAVIOR_INTERACTION = 33ul
};

/// Constant 'PERC_HANDSHAKE'.
enum
{
  perception_msgs__msg__PercState__PERC_HANDSHAKE = 34ul
};

/// Constant 'PERC_STANDBY_ACCOMPANY'.
enum
{
  perception_msgs__msg__PercState__PERC_STANDBY_ACCOMPANY = 35ul
};

/// Constant 'PERC_HAPPY_ACCOMPANY'.
enum
{
  perception_msgs__msg__PercState__PERC_HAPPY_ACCOMPANY = 36ul
};

/// Constant 'PERC_WORK_ACCOMPANY'.
enum
{
  perception_msgs__msg__PercState__PERC_WORK_ACCOMPANY = 37ul
};

/// Constant 'PERC_POSITIVE_ACCOMPANY'.
enum
{
  perception_msgs__msg__PercState__PERC_POSITIVE_ACCOMPANY = 38ul
};

/// Constant 'PERC_NEGATIVE_ACCOMPANY'.
enum
{
  perception_msgs__msg__PercState__PERC_NEGATIVE_ACCOMPANY = 39ul
};

/// Constant 'PERC_CHILD_WATCH'.
enum
{
  perception_msgs__msg__PercState__PERC_CHILD_WATCH = 40ul
};

/// Constant 'PERC_OLDER_WATCH'.
enum
{
  perception_msgs__msg__PercState__PERC_OLDER_WATCH = 41ul
};

/// Constant 'PERC_DANGER_REMINDER'.
enum
{
  perception_msgs__msg__PercState__PERC_DANGER_REMINDER = 42ul
};

/// Constant 'PERC_EVENT_REMINDER'.
enum
{
  perception_msgs__msg__PercState__PERC_EVENT_REMINDER = 43ul
};

/// Constant 'PERC_CATWALK_START'.
enum
{
  perception_msgs__msg__PercState__PERC_CATWALK_START = 44ul
};

/// Constant 'PERC_CATWALK_ACT'.
enum
{
  perception_msgs__msg__PercState__PERC_CATWALK_ACT = 45ul
};

/// Constant 'PERC_CATWALK_SHOW'.
enum
{
  perception_msgs__msg__PercState__PERC_CATWALK_SHOW = 46ul
};

/// Constant 'PERC_CATWALK_BACK'.
enum
{
  perception_msgs__msg__PercState__PERC_CATWALK_BACK = 47ul
};

/// Constant 'PERC_FREE_TIME'.
enum
{
  perception_msgs__msg__PercState__PERC_FREE_TIME = 50ul
};

/// Constant 'PERC_SOCIALIZE'.
enum
{
  perception_msgs__msg__PercState__PERC_SOCIALIZE = 51ul
};

/// Constant 'PERC_DANGER_INFO'.
enum
{
  perception_msgs__msg__PercState__PERC_DANGER_INFO = 60ul
};

/// Constant 'PERC_WELCOME_DEMO'.
enum
{
  perception_msgs__msg__PercState__PERC_WELCOME_DEMO = 70ul
};

/// Constant 'PERC_CANCEL'.
enum
{
  perception_msgs__msg__PercState__PERC_CANCEL = 100ul
};

/// Constant 'PERC_NODE_CLOSE'.
enum
{
  perception_msgs__msg__PercState__PERC_NODE_CLOSE = 200ul
};

/// Constant 'PERC_NODE_START'.
enum
{
  perception_msgs__msg__PercState__PERC_NODE_START = 201ul
};

/// Constant 'PERC_NODE_RESET'.
enum
{
  perception_msgs__msg__PercState__PERC_NODE_RESET = 202ul
};

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'err_info'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/PercState in the package perception_msgs.
typedef struct perception_msgs__msg__PercState
{
  std_msgs__msg__Header header;
  uint64_t action_id;
  uint32_t perc_kind;
  uint8_t exe_state;
  uint8_t exe_result;
  uint16_t err_code;
  rosidl_runtime_c__String err_info;
  uint64_t wait_for_millisec;
} perception_msgs__msg__PercState;

// Struct for a sequence of perception_msgs__msg__PercState.
typedef struct perception_msgs__msg__PercState__Sequence
{
  perception_msgs__msg__PercState * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} perception_msgs__msg__PercState__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // PERCEPTION_MSGS__MSG__DETAIL__PERC_STATE__STRUCT_H_
