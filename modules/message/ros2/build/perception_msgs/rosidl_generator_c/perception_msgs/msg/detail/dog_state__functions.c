// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from perception_msgs:msg/DogState.idl
// generated code does not contain a copyright notice
#include "perception_msgs/msg/detail/dog_state__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `target_position`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `alarm_info`
#include "perception_msgs/msg/detail/alarm_entry__functions.h"

bool
perception_msgs__msg__DogState__init(perception_msgs__msg__DogState * msg)
{
  if (!msg) {
    return false;
  }
  // battery
  // charging_state
  // gesture
  // speed
  // person_state
  // target_position
  if (!geometry_msgs__msg__Pose__init(&msg->target_position)) {
    perception_msgs__msg__DogState__fini(msg);
    return false;
  }
  // alarm_info
  if (!perception_msgs__msg__AlarmEntry__Sequence__init(&msg->alarm_info, 0)) {
    perception_msgs__msg__DogState__fini(msg);
    return false;
  }
  return true;
}

void
perception_msgs__msg__DogState__fini(perception_msgs__msg__DogState * msg)
{
  if (!msg) {
    return;
  }
  // battery
  // charging_state
  // gesture
  // speed
  // person_state
  // target_position
  geometry_msgs__msg__Pose__fini(&msg->target_position);
  // alarm_info
  perception_msgs__msg__AlarmEntry__Sequence__fini(&msg->alarm_info);
}

bool
perception_msgs__msg__DogState__are_equal(const perception_msgs__msg__DogState * lhs, const perception_msgs__msg__DogState * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // battery
  if (lhs->battery != rhs->battery) {
    return false;
  }
  // charging_state
  if (lhs->charging_state != rhs->charging_state) {
    return false;
  }
  // gesture
  if (lhs->gesture != rhs->gesture) {
    return false;
  }
  // speed
  if (lhs->speed != rhs->speed) {
    return false;
  }
  // person_state
  if (lhs->person_state != rhs->person_state) {
    return false;
  }
  // target_position
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->target_position), &(rhs->target_position)))
  {
    return false;
  }
  // alarm_info
  if (!perception_msgs__msg__AlarmEntry__Sequence__are_equal(
      &(lhs->alarm_info), &(rhs->alarm_info)))
  {
    return false;
  }
  return true;
}

bool
perception_msgs__msg__DogState__copy(
  const perception_msgs__msg__DogState * input,
  perception_msgs__msg__DogState * output)
{
  if (!input || !output) {
    return false;
  }
  // battery
  output->battery = input->battery;
  // charging_state
  output->charging_state = input->charging_state;
  // gesture
  output->gesture = input->gesture;
  // speed
  output->speed = input->speed;
  // person_state
  output->person_state = input->person_state;
  // target_position
  if (!geometry_msgs__msg__Pose__copy(
      &(input->target_position), &(output->target_position)))
  {
    return false;
  }
  // alarm_info
  if (!perception_msgs__msg__AlarmEntry__Sequence__copy(
      &(input->alarm_info), &(output->alarm_info)))
  {
    return false;
  }
  return true;
}

perception_msgs__msg__DogState *
perception_msgs__msg__DogState__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__DogState * msg = (perception_msgs__msg__DogState *)allocator.allocate(sizeof(perception_msgs__msg__DogState), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(perception_msgs__msg__DogState));
  bool success = perception_msgs__msg__DogState__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
perception_msgs__msg__DogState__destroy(perception_msgs__msg__DogState * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    perception_msgs__msg__DogState__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
perception_msgs__msg__DogState__Sequence__init(perception_msgs__msg__DogState__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__DogState * data = NULL;

  if (size) {
    data = (perception_msgs__msg__DogState *)allocator.zero_allocate(size, sizeof(perception_msgs__msg__DogState), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = perception_msgs__msg__DogState__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        perception_msgs__msg__DogState__fini(&data[i - 1]);
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
perception_msgs__msg__DogState__Sequence__fini(perception_msgs__msg__DogState__Sequence * array)
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
      perception_msgs__msg__DogState__fini(&array->data[i]);
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

perception_msgs__msg__DogState__Sequence *
perception_msgs__msg__DogState__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__DogState__Sequence * array = (perception_msgs__msg__DogState__Sequence *)allocator.allocate(sizeof(perception_msgs__msg__DogState__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = perception_msgs__msg__DogState__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
perception_msgs__msg__DogState__Sequence__destroy(perception_msgs__msg__DogState__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    perception_msgs__msg__DogState__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
perception_msgs__msg__DogState__Sequence__are_equal(const perception_msgs__msg__DogState__Sequence * lhs, const perception_msgs__msg__DogState__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!perception_msgs__msg__DogState__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
perception_msgs__msg__DogState__Sequence__copy(
  const perception_msgs__msg__DogState__Sequence * input,
  perception_msgs__msg__DogState__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(perception_msgs__msg__DogState);
    perception_msgs__msg__DogState * data =
      (perception_msgs__msg__DogState *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!perception_msgs__msg__DogState__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          perception_msgs__msg__DogState__fini(&data[i]);
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
    if (!perception_msgs__msg__DogState__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
