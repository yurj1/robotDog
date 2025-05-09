// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from perception_msgs:msg/DogState.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "perception_msgs/msg/detail/dog_state__rosidl_typesupport_introspection_c.h"
#include "perception_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "perception_msgs/msg/detail/dog_state__functions.h"
#include "perception_msgs/msg/detail/dog_state__struct.h"


// Include directives for member types
// Member `target_position`
#include "geometry_msgs/msg/pose.h"
// Member `target_position`
#include "geometry_msgs/msg/detail/pose__rosidl_typesupport_introspection_c.h"
// Member `alarm_info`
#include "perception_msgs/msg/alarm_entry.h"
// Member `alarm_info`
#include "perception_msgs/msg/detail/alarm_entry__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void DogState__rosidl_typesupport_introspection_c__DogState_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  perception_msgs__msg__DogState__init(message_memory);
}

void DogState__rosidl_typesupport_introspection_c__DogState_fini_function(void * message_memory)
{
  perception_msgs__msg__DogState__fini(message_memory);
}

size_t DogState__rosidl_typesupport_introspection_c__size_function__AlarmEntry__alarm_info(
  const void * untyped_member)
{
  const perception_msgs__msg__AlarmEntry__Sequence * member =
    (const perception_msgs__msg__AlarmEntry__Sequence *)(untyped_member);
  return member->size;
}

const void * DogState__rosidl_typesupport_introspection_c__get_const_function__AlarmEntry__alarm_info(
  const void * untyped_member, size_t index)
{
  const perception_msgs__msg__AlarmEntry__Sequence * member =
    (const perception_msgs__msg__AlarmEntry__Sequence *)(untyped_member);
  return &member->data[index];
}

void * DogState__rosidl_typesupport_introspection_c__get_function__AlarmEntry__alarm_info(
  void * untyped_member, size_t index)
{
  perception_msgs__msg__AlarmEntry__Sequence * member =
    (perception_msgs__msg__AlarmEntry__Sequence *)(untyped_member);
  return &member->data[index];
}

bool DogState__rosidl_typesupport_introspection_c__resize_function__AlarmEntry__alarm_info(
  void * untyped_member, size_t size)
{
  perception_msgs__msg__AlarmEntry__Sequence * member =
    (perception_msgs__msg__AlarmEntry__Sequence *)(untyped_member);
  perception_msgs__msg__AlarmEntry__Sequence__fini(member);
  return perception_msgs__msg__AlarmEntry__Sequence__init(member, size);
}

static rosidl_typesupport_introspection_c__MessageMember DogState__rosidl_typesupport_introspection_c__DogState_message_member_array[7] = {
  {
    "battery",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_msgs__msg__DogState, battery),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "charging_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_msgs__msg__DogState, charging_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "gesture",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_msgs__msg__DogState, gesture),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "speed",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_DOUBLE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_msgs__msg__DogState, speed),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "person_state",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_msgs__msg__DogState, person_state),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_msgs__msg__DogState, target_position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "alarm_info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_msgs__msg__DogState, alarm_info),  // bytes offset in struct
    NULL,  // default value
    DogState__rosidl_typesupport_introspection_c__size_function__AlarmEntry__alarm_info,  // size() function pointer
    DogState__rosidl_typesupport_introspection_c__get_const_function__AlarmEntry__alarm_info,  // get_const(index) function pointer
    DogState__rosidl_typesupport_introspection_c__get_function__AlarmEntry__alarm_info,  // get(index) function pointer
    DogState__rosidl_typesupport_introspection_c__resize_function__AlarmEntry__alarm_info  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers DogState__rosidl_typesupport_introspection_c__DogState_message_members = {
  "perception_msgs__msg",  // message namespace
  "DogState",  // message name
  7,  // number of fields
  sizeof(perception_msgs__msg__DogState),
  DogState__rosidl_typesupport_introspection_c__DogState_message_member_array,  // message members
  DogState__rosidl_typesupport_introspection_c__DogState_init_function,  // function to initialize message memory (memory has to be allocated)
  DogState__rosidl_typesupport_introspection_c__DogState_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t DogState__rosidl_typesupport_introspection_c__DogState_message_type_support_handle = {
  0,
  &DogState__rosidl_typesupport_introspection_c__DogState_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_perception_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, perception_msgs, msg, DogState)() {
  DogState__rosidl_typesupport_introspection_c__DogState_message_member_array[5].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Pose)();
  DogState__rosidl_typesupport_introspection_c__DogState_message_member_array[6].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, perception_msgs, msg, AlarmEntry)();
  if (!DogState__rosidl_typesupport_introspection_c__DogState_message_type_support_handle.typesupport_identifier) {
    DogState__rosidl_typesupport_introspection_c__DogState_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &DogState__rosidl_typesupport_introspection_c__DogState_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
