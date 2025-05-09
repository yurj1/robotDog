// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from perception_msgs:msg/TaskList.idl
// generated code does not contain a copyright notice
#include "perception_msgs/msg/detail/task_list__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `target_position`
#include "geometry_msgs/msg/detail/pose__functions.h"
// Member `target_object`
#include "rosidl_runtime_c/string_functions.h"

bool
perception_msgs__msg__TaskList__init(perception_msgs__msg__TaskList * msg)
{
  if (!msg) {
    return false;
  }
  // task_id
  // task_type
  // target_position
  if (!geometry_msgs__msg__Pose__init(&msg->target_position)) {
    perception_msgs__msg__TaskList__fini(msg);
    return false;
  }
  // target_object
  if (!rosidl_runtime_c__String__init(&msg->target_object)) {
    perception_msgs__msg__TaskList__fini(msg);
    return false;
  }
  // task_state
  // task_result
  // is_in_place_rotation
  return true;
}

void
perception_msgs__msg__TaskList__fini(perception_msgs__msg__TaskList * msg)
{
  if (!msg) {
    return;
  }
  // task_id
  // task_type
  // target_position
  geometry_msgs__msg__Pose__fini(&msg->target_position);
  // target_object
  rosidl_runtime_c__String__fini(&msg->target_object);
  // task_state
  // task_result
  // is_in_place_rotation
}

bool
perception_msgs__msg__TaskList__are_equal(const perception_msgs__msg__TaskList * lhs, const perception_msgs__msg__TaskList * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // task_id
  if (lhs->task_id != rhs->task_id) {
    return false;
  }
  // task_type
  if (lhs->task_type != rhs->task_type) {
    return false;
  }
  // target_position
  if (!geometry_msgs__msg__Pose__are_equal(
      &(lhs->target_position), &(rhs->target_position)))
  {
    return false;
  }
  // target_object
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->target_object), &(rhs->target_object)))
  {
    return false;
  }
  // task_state
  if (lhs->task_state != rhs->task_state) {
    return false;
  }
  // task_result
  if (lhs->task_result != rhs->task_result) {
    return false;
  }
  // is_in_place_rotation
  if (lhs->is_in_place_rotation != rhs->is_in_place_rotation) {
    return false;
  }
  return true;
}

bool
perception_msgs__msg__TaskList__copy(
  const perception_msgs__msg__TaskList * input,
  perception_msgs__msg__TaskList * output)
{
  if (!input || !output) {
    return false;
  }
  // task_id
  output->task_id = input->task_id;
  // task_type
  output->task_type = input->task_type;
  // target_position
  if (!geometry_msgs__msg__Pose__copy(
      &(input->target_position), &(output->target_position)))
  {
    return false;
  }
  // target_object
  if (!rosidl_runtime_c__String__copy(
      &(input->target_object), &(output->target_object)))
  {
    return false;
  }
  // task_state
  output->task_state = input->task_state;
  // task_result
  output->task_result = input->task_result;
  // is_in_place_rotation
  output->is_in_place_rotation = input->is_in_place_rotation;
  return true;
}

perception_msgs__msg__TaskList *
perception_msgs__msg__TaskList__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__TaskList * msg = (perception_msgs__msg__TaskList *)allocator.allocate(sizeof(perception_msgs__msg__TaskList), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(perception_msgs__msg__TaskList));
  bool success = perception_msgs__msg__TaskList__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
perception_msgs__msg__TaskList__destroy(perception_msgs__msg__TaskList * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    perception_msgs__msg__TaskList__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
perception_msgs__msg__TaskList__Sequence__init(perception_msgs__msg__TaskList__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__TaskList * data = NULL;

  if (size) {
    data = (perception_msgs__msg__TaskList *)allocator.zero_allocate(size, sizeof(perception_msgs__msg__TaskList), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = perception_msgs__msg__TaskList__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        perception_msgs__msg__TaskList__fini(&data[i - 1]);
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
perception_msgs__msg__TaskList__Sequence__fini(perception_msgs__msg__TaskList__Sequence * array)
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
      perception_msgs__msg__TaskList__fini(&array->data[i]);
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

perception_msgs__msg__TaskList__Sequence *
perception_msgs__msg__TaskList__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__msg__TaskList__Sequence * array = (perception_msgs__msg__TaskList__Sequence *)allocator.allocate(sizeof(perception_msgs__msg__TaskList__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = perception_msgs__msg__TaskList__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
perception_msgs__msg__TaskList__Sequence__destroy(perception_msgs__msg__TaskList__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    perception_msgs__msg__TaskList__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
perception_msgs__msg__TaskList__Sequence__are_equal(const perception_msgs__msg__TaskList__Sequence * lhs, const perception_msgs__msg__TaskList__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!perception_msgs__msg__TaskList__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
perception_msgs__msg__TaskList__Sequence__copy(
  const perception_msgs__msg__TaskList__Sequence * input,
  perception_msgs__msg__TaskList__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(perception_msgs__msg__TaskList);
    perception_msgs__msg__TaskList * data =
      (perception_msgs__msg__TaskList *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!perception_msgs__msg__TaskList__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          perception_msgs__msg__TaskList__fini(&data[i]);
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
    if (!perception_msgs__msg__TaskList__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
