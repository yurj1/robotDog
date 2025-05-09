// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from perception_msgs:msg/ActionEntry.idl
// generated code does not contain a copyright notice
#include "perception_msgs/msg/detail/action_entry__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `param3`
// Member `info`
#include "rosidl_runtime_c/string_functions.h"

bool
perception_msgs__msg__ActionEntry__init(perception_msgs__msg__ActionEntry * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // param1
  // param2
  // param3
  if (!rosidl_runtime_c__String__init(&msg->param3)) {
    perception_msgs__msg__ActionEntry__fini(msg);
    return false;
  }
  // info
  if (!rosidl_runtime_c__String__init(&msg->info)) {
    perception_msgs__msg__ActionEntry__fini(msg);
    return false;
  }
  return true;
}

void
perception_msgs__msg__ActionEntry__fini(perception_msgs__msg__ActionEntry * msg)
{
  if (!msg) {
    return;
  }
  // id
  // param1
  // param2
  // param3
  rosidl_runtime_c__String__fini(&msg->param3);
  // info
  rosidl_runtime_c__String__fini(&msg->info);
}

bool
perception_msgs__msg__ActionEntry__are_equal(const perception_msgs__msg__ActionEntry * lhs, const perception_msgs__msg__ActionEntry * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // param1
  if (lhs->param1 != rhs->param1) {
    return false;
  }
  // param2
  if (lhs->param2 != rhs->param2) {
    return false;
  }
  // param3
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->param3), &(rhs->param3)))
  {
    return false;
  }
  // info
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->info), &(rhs->info)))
  {
    return false;
  }
  return true;
}

bool
perception_msgs__msg__ActionEntry__copy(
  const perception_msgs__msg__ActionEntry * input,
  perception_msgs__msg__ActionEntry * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // param1
  output->param1 = input->param1;
  // param2
  output->param2 = input->param2;
  // param3
  if (!rosidl_runtime_c__String__copy(
      &(input->param3), &(output->param3)))
  {
    return false;
  }
  // info
  if (!rosidl_runtime_c__String__copy(
      &(input->info), &(output->info)))
  {
    return false;
  }
  return true;
}

perception_msgs__msg__ActionEntry *
perception_msgs__msg__ActionEntry__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__ActionEntry * msg = (perception_msgs__msg__ActionEntry *)allocator.allocate(sizeof(perception_msgs__msg__ActionEntry), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(perception_msgs__msg__ActionEntry));
  bool success = perception_msgs__msg__ActionEntry__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
perception_msgs__msg__ActionEntry__destroy(perception_msgs__msg__ActionEntry * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    perception_msgs__msg__ActionEntry__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
perception_msgs__msg__ActionEntry__Sequence__init(perception_msgs__msg__ActionEntry__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__ActionEntry * data = NULL;

  if (size) {
    data = (perception_msgs__msg__ActionEntry *)allocator.zero_allocate(size, sizeof(perception_msgs__msg__ActionEntry), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = perception_msgs__msg__ActionEntry__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        perception_msgs__msg__ActionEntry__fini(&data[i - 1]);
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
perception_msgs__msg__ActionEntry__Sequence__fini(perception_msgs__msg__ActionEntry__Sequence * array)
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
      perception_msgs__msg__ActionEntry__fini(&array->data[i]);
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

perception_msgs__msg__ActionEntry__Sequence *
perception_msgs__msg__ActionEntry__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__ActionEntry__Sequence * array = (perception_msgs__msg__ActionEntry__Sequence *)allocator.allocate(sizeof(perception_msgs__msg__ActionEntry__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = perception_msgs__msg__ActionEntry__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
perception_msgs__msg__ActionEntry__Sequence__destroy(perception_msgs__msg__ActionEntry__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    perception_msgs__msg__ActionEntry__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
perception_msgs__msg__ActionEntry__Sequence__are_equal(const perception_msgs__msg__ActionEntry__Sequence * lhs, const perception_msgs__msg__ActionEntry__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!perception_msgs__msg__ActionEntry__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
perception_msgs__msg__ActionEntry__Sequence__copy(
  const perception_msgs__msg__ActionEntry__Sequence * input,
  perception_msgs__msg__ActionEntry__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(perception_msgs__msg__ActionEntry);
    perception_msgs__msg__ActionEntry * data =
      (perception_msgs__msg__ActionEntry *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!perception_msgs__msg__ActionEntry__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          perception_msgs__msg__ActionEntry__fini(&data[i]);
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
    if (!perception_msgs__msg__ActionEntry__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
