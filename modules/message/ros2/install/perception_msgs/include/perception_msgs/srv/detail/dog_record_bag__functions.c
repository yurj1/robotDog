// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from perception_msgs:srv/DogRecordBag.idl
// generated code does not contain a copyright notice
#include "perception_msgs/srv/detail/dog_record_bag__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

// Include directives for member types
// Member `bag_name`
// Member `topics`
// Member `bash_name`
#include "rosidl_runtime_c/string_functions.h"

bool
perception_msgs__srv__DogRecordBag_Request__init(perception_msgs__srv__DogRecordBag_Request * msg)
{
  if (!msg) {
    return false;
  }
  // bag_mode
  // bag_name
  if (!rosidl_runtime_c__String__init(&msg->bag_name)) {
    perception_msgs__srv__DogRecordBag_Request__fini(msg);
    return false;
  }
  // topics
  if (!rosidl_runtime_c__String__Sequence__init(&msg->topics, 0)) {
    perception_msgs__srv__DogRecordBag_Request__fini(msg);
    return false;
  }
  // bash_name
  if (!rosidl_runtime_c__String__init(&msg->bash_name)) {
    perception_msgs__srv__DogRecordBag_Request__fini(msg);
    return false;
  }
  return true;
}

void
perception_msgs__srv__DogRecordBag_Request__fini(perception_msgs__srv__DogRecordBag_Request * msg)
{
  if (!msg) {
    return;
  }
  // bag_mode
  // bag_name
  rosidl_runtime_c__String__fini(&msg->bag_name);
  // topics
  rosidl_runtime_c__String__Sequence__fini(&msg->topics);
  // bash_name
  rosidl_runtime_c__String__fini(&msg->bash_name);
}

bool
perception_msgs__srv__DogRecordBag_Request__are_equal(const perception_msgs__srv__DogRecordBag_Request * lhs, const perception_msgs__srv__DogRecordBag_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // bag_mode
  if (lhs->bag_mode != rhs->bag_mode) {
    return false;
  }
  // bag_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->bag_name), &(rhs->bag_name)))
  {
    return false;
  }
  // topics
  if (!rosidl_runtime_c__String__Sequence__are_equal(
      &(lhs->topics), &(rhs->topics)))
  {
    return false;
  }
  // bash_name
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->bash_name), &(rhs->bash_name)))
  {
    return false;
  }
  return true;
}

bool
perception_msgs__srv__DogRecordBag_Request__copy(
  const perception_msgs__srv__DogRecordBag_Request * input,
  perception_msgs__srv__DogRecordBag_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // bag_mode
  output->bag_mode = input->bag_mode;
  // bag_name
  if (!rosidl_runtime_c__String__copy(
      &(input->bag_name), &(output->bag_name)))
  {
    return false;
  }
  // topics
  if (!rosidl_runtime_c__String__Sequence__copy(
      &(input->topics), &(output->topics)))
  {
    return false;
  }
  // bash_name
  if (!rosidl_runtime_c__String__copy(
      &(input->bash_name), &(output->bash_name)))
  {
    return false;
  }
  return true;
}

perception_msgs__srv__DogRecordBag_Request *
perception_msgs__srv__DogRecordBag_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__srv__DogRecordBag_Request * msg = (perception_msgs__srv__DogRecordBag_Request *)allocator.allocate(sizeof(perception_msgs__srv__DogRecordBag_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(perception_msgs__srv__DogRecordBag_Request));
  bool success = perception_msgs__srv__DogRecordBag_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
perception_msgs__srv__DogRecordBag_Request__destroy(perception_msgs__srv__DogRecordBag_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    perception_msgs__srv__DogRecordBag_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
perception_msgs__srv__DogRecordBag_Request__Sequence__init(perception_msgs__srv__DogRecordBag_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__srv__DogRecordBag_Request * data = NULL;

  if (size) {
    data = (perception_msgs__srv__DogRecordBag_Request *)allocator.zero_allocate(size, sizeof(perception_msgs__srv__DogRecordBag_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = perception_msgs__srv__DogRecordBag_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        perception_msgs__srv__DogRecordBag_Request__fini(&data[i - 1]);
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
perception_msgs__srv__DogRecordBag_Request__Sequence__fini(perception_msgs__srv__DogRecordBag_Request__Sequence * array)
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
      perception_msgs__srv__DogRecordBag_Request__fini(&array->data[i]);
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

perception_msgs__srv__DogRecordBag_Request__Sequence *
perception_msgs__srv__DogRecordBag_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__srv__DogRecordBag_Request__Sequence * array = (perception_msgs__srv__DogRecordBag_Request__Sequence *)allocator.allocate(sizeof(perception_msgs__srv__DogRecordBag_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = perception_msgs__srv__DogRecordBag_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
perception_msgs__srv__DogRecordBag_Request__Sequence__destroy(perception_msgs__srv__DogRecordBag_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    perception_msgs__srv__DogRecordBag_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
perception_msgs__srv__DogRecordBag_Request__Sequence__are_equal(const perception_msgs__srv__DogRecordBag_Request__Sequence * lhs, const perception_msgs__srv__DogRecordBag_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!perception_msgs__srv__DogRecordBag_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
perception_msgs__srv__DogRecordBag_Request__Sequence__copy(
  const perception_msgs__srv__DogRecordBag_Request__Sequence * input,
  perception_msgs__srv__DogRecordBag_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(perception_msgs__srv__DogRecordBag_Request);
    perception_msgs__srv__DogRecordBag_Request * data =
      (perception_msgs__srv__DogRecordBag_Request *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!perception_msgs__srv__DogRecordBag_Request__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          perception_msgs__srv__DogRecordBag_Request__fini(&data[i]);
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
    if (!perception_msgs__srv__DogRecordBag_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `error_info`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

bool
perception_msgs__srv__DogRecordBag_Response__init(perception_msgs__srv__DogRecordBag_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // error_info
  if (!rosidl_runtime_c__String__init(&msg->error_info)) {
    perception_msgs__srv__DogRecordBag_Response__fini(msg);
    return false;
  }
  return true;
}

void
perception_msgs__srv__DogRecordBag_Response__fini(perception_msgs__srv__DogRecordBag_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // error_info
  rosidl_runtime_c__String__fini(&msg->error_info);
}

bool
perception_msgs__srv__DogRecordBag_Response__are_equal(const perception_msgs__srv__DogRecordBag_Response * lhs, const perception_msgs__srv__DogRecordBag_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // error_info
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->error_info), &(rhs->error_info)))
  {
    return false;
  }
  return true;
}

bool
perception_msgs__srv__DogRecordBag_Response__copy(
  const perception_msgs__srv__DogRecordBag_Response * input,
  perception_msgs__srv__DogRecordBag_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // error_info
  if (!rosidl_runtime_c__String__copy(
      &(input->error_info), &(output->error_info)))
  {
    return false;
  }
  return true;
}

perception_msgs__srv__DogRecordBag_Response *
perception_msgs__srv__DogRecordBag_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__srv__DogRecordBag_Response * msg = (perception_msgs__srv__DogRecordBag_Response *)allocator.allocate(sizeof(perception_msgs__srv__DogRecordBag_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(perception_msgs__srv__DogRecordBag_Response));
  bool success = perception_msgs__srv__DogRecordBag_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
perception_msgs__srv__DogRecordBag_Response__destroy(perception_msgs__srv__DogRecordBag_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    perception_msgs__srv__DogRecordBag_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
perception_msgs__srv__DogRecordBag_Response__Sequence__init(perception_msgs__srv__DogRecordBag_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__srv__DogRecordBag_Response * data = NULL;

  if (size) {
    data = (perception_msgs__srv__DogRecordBag_Response *)allocator.zero_allocate(size, sizeof(perception_msgs__srv__DogRecordBag_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = perception_msgs__srv__DogRecordBag_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        perception_msgs__srv__DogRecordBag_Response__fini(&data[i - 1]);
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
perception_msgs__srv__DogRecordBag_Response__Sequence__fini(perception_msgs__srv__DogRecordBag_Response__Sequence * array)
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
      perception_msgs__srv__DogRecordBag_Response__fini(&array->data[i]);
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

perception_msgs__srv__DogRecordBag_Response__Sequence *
perception_msgs__srv__DogRecordBag_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  perception_msgs__srv__DogRecordBag_Response__Sequence * array = (perception_msgs__srv__DogRecordBag_Response__Sequence *)allocator.allocate(sizeof(perception_msgs__srv__DogRecordBag_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = perception_msgs__srv__DogRecordBag_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
perception_msgs__srv__DogRecordBag_Response__Sequence__destroy(perception_msgs__srv__DogRecordBag_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    perception_msgs__srv__DogRecordBag_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
perception_msgs__srv__DogRecordBag_Response__Sequence__are_equal(const perception_msgs__srv__DogRecordBag_Response__Sequence * lhs, const perception_msgs__srv__DogRecordBag_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!perception_msgs__srv__DogRecordBag_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
perception_msgs__srv__DogRecordBag_Response__Sequence__copy(
  const perception_msgs__srv__DogRecordBag_Response__Sequence * input,
  perception_msgs__srv__DogRecordBag_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(perception_msgs__srv__DogRecordBag_Response);
    perception_msgs__srv__DogRecordBag_Response * data =
      (perception_msgs__srv__DogRecordBag_Response *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!perception_msgs__srv__DogRecordBag_Response__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          perception_msgs__srv__DogRecordBag_Response__fini(&data[i]);
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
    if (!perception_msgs__srv__DogRecordBag_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
