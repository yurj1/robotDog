// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from perception_msgs:srv/DogRecordBag.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "perception_msgs/srv/detail/dog_record_bag__rosidl_typesupport_introspection_c.h"
#include "perception_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "perception_msgs/srv/detail/dog_record_bag__functions.h"
#include "perception_msgs/srv/detail/dog_record_bag__struct.h"


// Include directives for member types
// Member `bag_name`
// Member `topics`
// Member `bash_name`
#include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void DogRecordBag_Request__rosidl_typesupport_introspection_c__DogRecordBag_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  perception_msgs__srv__DogRecordBag_Request__init(message_memory);
}

void DogRecordBag_Request__rosidl_typesupport_introspection_c__DogRecordBag_Request_fini_function(void * message_memory)
{
  perception_msgs__srv__DogRecordBag_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember DogRecordBag_Request__rosidl_typesupport_introspection_c__DogRecordBag_Request_message_member_array[4] = {
  {
    "bag_mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_UINT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_msgs__srv__DogRecordBag_Request, bag_mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bag_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_msgs__srv__DogRecordBag_Request, bag_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "topics",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_msgs__srv__DogRecordBag_Request, topics),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "bash_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_msgs__srv__DogRecordBag_Request, bash_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers DogRecordBag_Request__rosidl_typesupport_introspection_c__DogRecordBag_Request_message_members = {
  "perception_msgs__srv",  // message namespace
  "DogRecordBag_Request",  // message name
  4,  // number of fields
  sizeof(perception_msgs__srv__DogRecordBag_Request),
  DogRecordBag_Request__rosidl_typesupport_introspection_c__DogRecordBag_Request_message_member_array,  // message members
  DogRecordBag_Request__rosidl_typesupport_introspection_c__DogRecordBag_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  DogRecordBag_Request__rosidl_typesupport_introspection_c__DogRecordBag_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t DogRecordBag_Request__rosidl_typesupport_introspection_c__DogRecordBag_Request_message_type_support_handle = {
  0,
  &DogRecordBag_Request__rosidl_typesupport_introspection_c__DogRecordBag_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_perception_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, perception_msgs, srv, DogRecordBag_Request)() {
  if (!DogRecordBag_Request__rosidl_typesupport_introspection_c__DogRecordBag_Request_message_type_support_handle.typesupport_identifier) {
    DogRecordBag_Request__rosidl_typesupport_introspection_c__DogRecordBag_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &DogRecordBag_Request__rosidl_typesupport_introspection_c__DogRecordBag_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "perception_msgs/srv/detail/dog_record_bag__rosidl_typesupport_introspection_c.h"
// already included above
// #include "perception_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "perception_msgs/srv/detail/dog_record_bag__functions.h"
// already included above
// #include "perception_msgs/srv/detail/dog_record_bag__struct.h"


// Include directives for member types
// Member `error_info`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void DogRecordBag_Response__rosidl_typesupport_introspection_c__DogRecordBag_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  perception_msgs__srv__DogRecordBag_Response__init(message_memory);
}

void DogRecordBag_Response__rosidl_typesupport_introspection_c__DogRecordBag_Response_fini_function(void * message_memory)
{
  perception_msgs__srv__DogRecordBag_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember DogRecordBag_Response__rosidl_typesupport_introspection_c__DogRecordBag_Response_message_member_array[2] = {
  {
    "success",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_msgs__srv__DogRecordBag_Response, success),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "error_info",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(perception_msgs__srv__DogRecordBag_Response, error_info),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers DogRecordBag_Response__rosidl_typesupport_introspection_c__DogRecordBag_Response_message_members = {
  "perception_msgs__srv",  // message namespace
  "DogRecordBag_Response",  // message name
  2,  // number of fields
  sizeof(perception_msgs__srv__DogRecordBag_Response),
  DogRecordBag_Response__rosidl_typesupport_introspection_c__DogRecordBag_Response_message_member_array,  // message members
  DogRecordBag_Response__rosidl_typesupport_introspection_c__DogRecordBag_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  DogRecordBag_Response__rosidl_typesupport_introspection_c__DogRecordBag_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t DogRecordBag_Response__rosidl_typesupport_introspection_c__DogRecordBag_Response_message_type_support_handle = {
  0,
  &DogRecordBag_Response__rosidl_typesupport_introspection_c__DogRecordBag_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_perception_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, perception_msgs, srv, DogRecordBag_Response)() {
  if (!DogRecordBag_Response__rosidl_typesupport_introspection_c__DogRecordBag_Response_message_type_support_handle.typesupport_identifier) {
    DogRecordBag_Response__rosidl_typesupport_introspection_c__DogRecordBag_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &DogRecordBag_Response__rosidl_typesupport_introspection_c__DogRecordBag_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "perception_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "perception_msgs/srv/detail/dog_record_bag__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers perception_msgs__srv__detail__dog_record_bag__rosidl_typesupport_introspection_c__DogRecordBag_service_members = {
  "perception_msgs__srv",  // service namespace
  "DogRecordBag",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // perception_msgs__srv__detail__dog_record_bag__rosidl_typesupport_introspection_c__DogRecordBag_Request_message_type_support_handle,
  NULL  // response message
  // perception_msgs__srv__detail__dog_record_bag__rosidl_typesupport_introspection_c__DogRecordBag_Response_message_type_support_handle
};

static rosidl_service_type_support_t perception_msgs__srv__detail__dog_record_bag__rosidl_typesupport_introspection_c__DogRecordBag_service_type_support_handle = {
  0,
  &perception_msgs__srv__detail__dog_record_bag__rosidl_typesupport_introspection_c__DogRecordBag_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, perception_msgs, srv, DogRecordBag_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, perception_msgs, srv, DogRecordBag_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_perception_msgs
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, perception_msgs, srv, DogRecordBag)() {
  if (!perception_msgs__srv__detail__dog_record_bag__rosidl_typesupport_introspection_c__DogRecordBag_service_type_support_handle.typesupport_identifier) {
    perception_msgs__srv__detail__dog_record_bag__rosidl_typesupport_introspection_c__DogRecordBag_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)perception_msgs__srv__detail__dog_record_bag__rosidl_typesupport_introspection_c__DogRecordBag_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, perception_msgs, srv, DogRecordBag_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, perception_msgs, srv, DogRecordBag_Response)()->data;
  }

  return &perception_msgs__srv__detail__dog_record_bag__rosidl_typesupport_introspection_c__DogRecordBag_service_type_support_handle;
}
