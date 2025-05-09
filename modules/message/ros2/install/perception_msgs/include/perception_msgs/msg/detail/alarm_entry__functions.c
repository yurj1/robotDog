// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from perception_msgs:msg/AlarmEntry.idl
// generated code does not contain a copyright notice
#include "perception_msgs/msg/detail/alarm_entry__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
perception_msgs__msg__AlarmEntry__init(perception_msgs__msg__AlarmEntry * msg)
{
  if (!msg) {
    return false;
  }
  // id
  // source
  // level
  // status
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    perception_msgs__msg__AlarmEntry__fini(msg);
    return false;
  }
  return true;
}

void
perception_msgs__msg__AlarmEntry__fini(perception_msgs__msg__AlarmEntry * msg)
{
  if (!msg) {
    return;
  }
  // id
  // source
  // level
  // status
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
perception_msgs__msg__AlarmEntry__are_equal(const perception_msgs__msg__AlarmEntry * lhs, const perception_msgs__msg__AlarmEntry * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // id
  if (lhs->id != rhs->id) {
    return false;
  }
  // source
  if (lhs->source != rhs->source) {
    return false;
  }
  // level
  if (lhs->level != rhs->level) {
    return false;
  }
  // status
  if (lhs->status != rhs->status) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
perception_msgs__msg__AlarmEntry__copy(
  const perception_msgs__msg__AlarmEntry * input,
  perception_msgs__msg__AlarmEntry * output)
{
  if (!input || !output) {
    return false;
  }
  // id
  output->id = input->id;
  // source
  output->source = input->source;
  // level
  output->level = input->level;
  // status
  output->status = input->status;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

perception_msgs__msg__AlarmEntry *
perception_msgs__msg__AlarmEntry__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__AlarmEntry * msg = (perception_msgs__msg__AlarmEntry *)allocator.allocate(sizeof(perception_msgs__msg__AlarmEntry), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(perception_msgs__msg__AlarmEntry));
  bool success = perception_msgs__msg__AlarmEntry__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
perception_msgs__msg__AlarmEntry__destroy(perception_msgs__msg__AlarmEntry * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    perception_msgs__msg__AlarmEntry__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
perception_msgs__msg__AlarmEntry__Sequence__init(perception_msgs__msg__AlarmEntry__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__AlarmEntry * data = NULL;

  if (size) {
    data = (perception_msgs__msg__AlarmEntry *)allocator.zero_allocate(size, sizeof(perception_msgs__msg__AlarmEntry), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = perception_msgs__msg__AlarmEntry__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        perception_msgs__msg__AlarmEntry__fini(&data[i - 1]);
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
perception_msgs__msg__AlarmEntry__Sequence__fini(perception_msgs__msg__AlarmEntry__Sequence * array)
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
      perception_msgs__msg__AlarmEntry__fini(&array->data[i]);
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

perception_msgs__msg__AlarmEntry__Sequence *
perception_msgs__msg__AlarmEntry__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__AlarmEntry__Sequence * array = (perception_msgs__msg__AlarmEntry__Sequence *)allocator.allocate(sizeof(perception_msgs__msg__AlarmEntry__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = perception_msgs__msg__AlarmEntry__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
perception_msgs__msg__AlarmEntry__Sequence__destroy(perception_msgs__msg__AlarmEntry__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    perception_msgs__msg__AlarmEntry__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
perception_msgs__msg__AlarmEntry__Sequence__are_equal(const perception_msgs__msg__AlarmEntry__Sequence * lhs, const perception_msgs__msg__AlarmEntry__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!perception_msgs__msg__AlarmEntry__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
perception_msgs__msg__AlarmEntry__Sequence__copy(
  const perception_msgs__msg__AlarmEntry__Sequence * input,
  perception_msgs__msg__AlarmEntry__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(perception_msgs__msg__AlarmEntry);
    perception_msgs__msg__AlarmEntry * data =
      (perception_msgs__msg__AlarmEntry *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!perception_msgs__msg__AlarmEntry__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          perception_msgs__msg__AlarmEntry__fini(&data[i]);
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
    if (!perception_msgs__msg__AlarmEntry__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
