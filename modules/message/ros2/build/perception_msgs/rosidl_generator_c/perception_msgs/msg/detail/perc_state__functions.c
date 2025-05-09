// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from perception_msgs:msg/PercState.idl
// generated code does not contain a copyright notice
#include "perception_msgs/msg/detail/perc_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `err_info`
#include "rosidl_runtime_c/string_functions.h"

bool
perception_msgs__msg__PercState__init(perception_msgs__msg__PercState * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    perception_msgs__msg__PercState__fini(msg);
    return false;
  }
  // action_id
  // perc_kind
  // exe_state
  // exe_result
  // err_code
  // err_info
  if (!rosidl_runtime_c__String__init(&msg->err_info)) {
    perception_msgs__msg__PercState__fini(msg);
    return false;
  }
  // wait_for_millisec
  return true;
}

void
perception_msgs__msg__PercState__fini(perception_msgs__msg__PercState * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // action_id
  // perc_kind
  // exe_state
  // exe_result
  // err_code
  // err_info
  rosidl_runtime_c__String__fini(&msg->err_info);
  // wait_for_millisec
}

bool
perception_msgs__msg__PercState__are_equal(const perception_msgs__msg__PercState * lhs, const perception_msgs__msg__PercState * rhs)
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
  // exe_state
  if (lhs->exe_state != rhs->exe_state) {
    return false;
  }
  // exe_result
  if (lhs->exe_result != rhs->exe_result) {
    return false;
  }
  // err_code
  if (lhs->err_code != rhs->err_code) {
    return false;
  }
  // err_info
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->err_info), &(rhs->err_info)))
  {
    return false;
  }
  // wait_for_millisec
  if (lhs->wait_for_millisec != rhs->wait_for_millisec) {
    return false;
  }
  return true;
}

bool
perception_msgs__msg__PercState__copy(
  const perception_msgs__msg__PercState * input,
  perception_msgs__msg__PercState * output)
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
  // exe_state
  output->exe_state = input->exe_state;
  // exe_result
  output->exe_result = input->exe_result;
  // err_code
  output->err_code = input->err_code;
  // err_info
  if (!rosidl_runtime_c__String__copy(
      &(input->err_info), &(output->err_info)))
  {
    return false;
  }
  // wait_for_millisec
  output->wait_for_millisec = input->wait_for_millisec;
  return true;
}

perception_msgs__msg__PercState *
perception_msgs__msg__PercState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__PercState * msg = (perception_msgs__msg__PercState *)allocator.allocate(sizeof(perception_msgs__msg__PercState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(perception_msgs__msg__PercState));
  bool success = perception_msgs__msg__PercState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
perception_msgs__msg__PercState__destroy(perception_msgs__msg__PercState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    perception_msgs__msg__PercState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
perception_msgs__msg__PercState__Sequence__init(perception_msgs__msg__PercState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__PercState * data = NULL;

  if (size) {
    data = (perception_msgs__msg__PercState *)allocator.zero_allocate(size, sizeof(perception_msgs__msg__PercState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = perception_msgs__msg__PercState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        perception_msgs__msg__PercState__fini(&data[i - 1]);
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
perception_msgs__msg__PercState__Sequence__fini(perception_msgs__msg__PercState__Sequence * array)
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
      perception_msgs__msg__PercState__fini(&array->data[i]);
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

perception_msgs__msg__PercState__Sequence *
perception_msgs__msg__PercState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__PercState__Sequence * array = (perception_msgs__msg__PercState__Sequence *)allocator.allocate(sizeof(perception_msgs__msg__PercState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = perception_msgs__msg__PercState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
perception_msgs__msg__PercState__Sequence__destroy(perception_msgs__msg__PercState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    perception_msgs__msg__PercState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
perception_msgs__msg__PercState__Sequence__are_equal(const perception_msgs__msg__PercState__Sequence * lhs, const perception_msgs__msg__PercState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!perception_msgs__msg__PercState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
perception_msgs__msg__PercState__Sequence__copy(
  const perception_msgs__msg__PercState__Sequence * input,
  perception_msgs__msg__PercState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(perception_msgs__msg__PercState);
    perception_msgs__msg__PercState * data =
      (perception_msgs__msg__PercState *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!perception_msgs__msg__PercState__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          perception_msgs__msg__PercState__fini(&data[i]);
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
    if (!perception_msgs__msg__PercState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
