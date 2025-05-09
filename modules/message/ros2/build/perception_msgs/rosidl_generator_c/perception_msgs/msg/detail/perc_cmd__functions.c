// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from perception_msgs:msg/PercCmd.idl
// generated code does not contain a copyright notice
#include "perception_msgs/msg/detail/perc_cmd__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `follow_name`
// Member `point_name`
#include "rosidl_runtime_c/string_functions.h"
// Member `point`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
perception_msgs__msg__PercCmd__init(perception_msgs__msg__PercCmd * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    perception_msgs__msg__PercCmd__fini(msg);
    return false;
  }
  // action_id
  // perc_kind
  // req_id
  // on_off
  // follow_name
  if (!rosidl_runtime_c__String__init(&msg->follow_name)) {
    perception_msgs__msg__PercCmd__fini(msg);
    return false;
  }
  // angle
  // point_name
  if (!rosidl_runtime_c__String__init(&msg->point_name)) {
    perception_msgs__msg__PercCmd__fini(msg);
    return false;
  }
  // point
  if (!geometry_msgs__msg__Point__init(&msg->point)) {
    perception_msgs__msg__PercCmd__fini(msg);
    return false;
  }
  return true;
}

void
perception_msgs__msg__PercCmd__fini(perception_msgs__msg__PercCmd * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // action_id
  // perc_kind
  // req_id
  // on_off
  // follow_name
  rosidl_runtime_c__String__fini(&msg->follow_name);
  // angle
  // point_name
  rosidl_runtime_c__String__fini(&msg->point_name);
  // point
  geometry_msgs__msg__Point__fini(&msg->point);
}

bool
perception_msgs__msg__PercCmd__are_equal(const perception_msgs__msg__PercCmd * lhs, const perception_msgs__msg__PercCmd * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // action_id
  if (lhs->action_id != rhs->action_id) {
    return false;
  }
  // perc_kind
  if (lhs->perc_kind != rhs->perc_kind) {
    return false;
  }
  // req_id
  if (lhs->req_id != rhs->req_id) {
    return false;
  }
  // on_off
  if (lhs->on_off != rhs->on_off) {
    return false;
  }
  // follow_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->follow_name), &(rhs->follow_name)))
  {
    return false;
  }
  // angle
  if (lhs->angle != rhs->angle) {
    return false;
  }
  // point_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->point_name), &(rhs->point_name)))
  {
    return false;
  }
  // point
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->point), &(rhs->point)))
  {
    return false;
  }
  return true;
}

bool
perception_msgs__msg__PercCmd__copy(
  const perception_msgs__msg__PercCmd * input,
  perception_msgs__msg__PercCmd * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // action_id
  output->action_id = input->action_id;
  // perc_kind
  output->perc_kind = input->perc_kind;
  // req_id
  output->req_id = input->req_id;
  // on_off
  output->on_off = input->on_off;
  // follow_name
  if (!rosidl_runtime_c__String__copy(
      &(input->follow_name), &(output->follow_name)))
  {
    return false;
  }
  // angle
  output->angle = input->angle;
  // point_name
  if (!rosidl_runtime_c__String__copy(
      &(input->point_name), &(output->point_name)))
  {
    return false;
  }
  // point
  if (!geometry_msgs__msg__Point__copy(
      &(input->point), &(output->point)))
  {
    return false;
  }
  return true;
}

perception_msgs__msg__PercCmd *
perception_msgs__msg__PercCmd__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__PercCmd * msg = (perception_msgs__msg__PercCmd *)allocator.allocate(sizeof(perception_msgs__msg__PercCmd), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(perception_msgs__msg__PercCmd));
  bool success = perception_msgs__msg__PercCmd__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
perception_msgs__msg__PercCmd__destroy(perception_msgs__msg__PercCmd * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    perception_msgs__msg__PercCmd__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
perception_msgs__msg__PercCmd__Sequence__init(perception_msgs__msg__PercCmd__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__PercCmd * data = NULL;

  if (size) {
    data = (perception_msgs__msg__PercCmd *)allocator.zero_allocate(size, sizeof(perception_msgs__msg__PercCmd), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = perception_msgs__msg__PercCmd__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        perception_msgs__msg__PercCmd__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
perception_msgs__msg__PercCmd__Sequence__fini(perception_msgs__msg__PercCmd__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      perception_msgs__msg__PercCmd__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

perception_msgs__msg__PercCmd__Sequence *
perception_msgs__msg__PercCmd__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__PercCmd__Sequence * array = (perception_msgs__msg__PercCmd__Sequence *)allocator.allocate(sizeof(perception_msgs__msg__PercCmd__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = perception_msgs__msg__PercCmd__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
perception_msgs__msg__PercCmd__Sequence__destroy(perception_msgs__msg__PercCmd__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    perception_msgs__msg__PercCmd__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
perception_msgs__msg__PercCmd__Sequence__are_equal(const perception_msgs__msg__PercCmd__Sequence * lhs, const perception_msgs__msg__PercCmd__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!perception_msgs__msg__PercCmd__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
perception_msgs__msg__PercCmd__Sequence__copy(
  const perception_msgs__msg__PercCmd__Sequence * input,
  perception_msgs__msg__PercCmd__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(perception_msgs__msg__PercCmd);
    perception_msgs__msg__PercCmd * data =
      (perception_msgs__msg__PercCmd *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!perception_msgs__msg__PercCmd__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          perception_msgs__msg__PercCmd__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!perception_msgs__msg__PercCmd__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
