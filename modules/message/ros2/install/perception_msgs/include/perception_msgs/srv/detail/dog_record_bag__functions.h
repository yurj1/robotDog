// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from perception_msgs:srv/DogRecordBag.idl
// generated code does not contain a copyright notice

#ifndef PERCEPTION_MSGS__SRV__DETAIL__DOG_RECORD_BAG__FUNCTIONS_H_
#define PERCEPTION_MSGS__SRV__DETAIL__DOG_RECORD_BAG__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "perception_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "perception_msgs/srv/detail/dog_record_bag__struct.h"

/// Initialize srv/DogRecordBag message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * perception_msgs__srv__DogRecordBag_Request
 * )) before or use
 * perception_msgs__srv__DogRecordBag_Request__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
bool
perception_msgs__srv__DogRecordBag_Request__init(perception_msgs__srv__DogRecordBag_Request * msg);

/// Finalize srv/DogRecordBag message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
void
perception_msgs__srv__DogRecordBag_Request__fini(perception_msgs__srv__DogRecordBag_Request * msg);

/// Create srv/DogRecordBag message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * perception_msgs__srv__DogRecordBag_Request__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
perception_msgs__srv__DogRecordBag_Request *
perception_msgs__srv__DogRecordBag_Request__create();

/// Destroy srv/DogRecordBag message.
/**
 * It calls
 * perception_msgs__srv__DogRecordBag_Request__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
void
perception_msgs__srv__DogRecordBag_Request__destroy(perception_msgs__srv__DogRecordBag_Request * msg);

/// Check for srv/DogRecordBag message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
bool
perception_msgs__srv__DogRecordBag_Request__are_equal(const perception_msgs__srv__DogRecordBag_Request * lhs, const perception_msgs__srv__DogRecordBag_Request * rhs);

/// Copy a srv/DogRecordBag message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
bool
perception_msgs__srv__DogRecordBag_Request__copy(
  const perception_msgs__srv__DogRecordBag_Request * input,
  perception_msgs__srv__DogRecordBag_Request * output);

/// Initialize array of srv/DogRecordBag messages.
/**
 * It allocates the memory for the number of elements and calls
 * perception_msgs__srv__DogRecordBag_Request__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
bool
perception_msgs__srv__DogRecordBag_Request__Sequence__init(perception_msgs__srv__DogRecordBag_Request__Sequence * array, size_t size);

/// Finalize array of srv/DogRecordBag messages.
/**
 * It calls
 * perception_msgs__srv__DogRecordBag_Request__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
void
perception_msgs__srv__DogRecordBag_Request__Sequence__fini(perception_msgs__srv__DogRecordBag_Request__Sequence * array);

/// Create array of srv/DogRecordBag messages.
/**
 * It allocates the memory for the array and calls
 * perception_msgs__srv__DogRecordBag_Request__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
perception_msgs__srv__DogRecordBag_Request__Sequence *
perception_msgs__srv__DogRecordBag_Request__Sequence__create(size_t size);

/// Destroy array of srv/DogRecordBag messages.
/**
 * It calls
 * perception_msgs__srv__DogRecordBag_Request__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
void
perception_msgs__srv__DogRecordBag_Request__Sequence__destroy(perception_msgs__srv__DogRecordBag_Request__Sequence * array);

/// Check for srv/DogRecordBag message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
bool
perception_msgs__srv__DogRecordBag_Request__Sequence__are_equal(const perception_msgs__srv__DogRecordBag_Request__Sequence * lhs, const perception_msgs__srv__DogRecordBag_Request__Sequence * rhs);

/// Copy an array of srv/DogRecordBag messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
bool
perception_msgs__srv__DogRecordBag_Request__Sequence__copy(
  const perception_msgs__srv__DogRecordBag_Request__Sequence * input,
  perception_msgs__srv__DogRecordBag_Request__Sequence * output);

/// Initialize srv/DogRecordBag message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * perception_msgs__srv__DogRecordBag_Response
 * )) before or use
 * perception_msgs__srv__DogRecordBag_Response__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
bool
perception_msgs__srv__DogRecordBag_Response__init(perception_msgs__srv__DogRecordBag_Response * msg);

/// Finalize srv/DogRecordBag message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
void
perception_msgs__srv__DogRecordBag_Response__fini(perception_msgs__srv__DogRecordBag_Response * msg);

/// Create srv/DogRecordBag message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * perception_msgs__srv__DogRecordBag_Response__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
perception_msgs__srv__DogRecordBag_Response *
perception_msgs__srv__DogRecordBag_Response__create();

/// Destroy srv/DogRecordBag message.
/**
 * It calls
 * perception_msgs__srv__DogRecordBag_Response__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
void
perception_msgs__srv__DogRecordBag_Response__destroy(perception_msgs__srv__DogRecordBag_Response * msg);

/// Check for srv/DogRecordBag message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
bool
perception_msgs__srv__DogRecordBag_Response__are_equal(const perception_msgs__srv__DogRecordBag_Response * lhs, const perception_msgs__srv__DogRecordBag_Response * rhs);

/// Copy a srv/DogRecordBag message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
bool
perception_msgs__srv__DogRecordBag_Response__copy(
  const perception_msgs__srv__DogRecordBag_Response * input,
  perception_msgs__srv__DogRecordBag_Response * output);

/// Initialize array of srv/DogRecordBag messages.
/**
 * It allocates the memory for the number of elements and calls
 * perception_msgs__srv__DogRecordBag_Response__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
bool
perception_msgs__srv__DogRecordBag_Response__Sequence__init(perception_msgs__srv__DogRecordBag_Response__Sequence * array, size_t size);

/// Finalize array of srv/DogRecordBag messages.
/**
 * It calls
 * perception_msgs__srv__DogRecordBag_Response__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
void
perception_msgs__srv__DogRecordBag_Response__Sequence__fini(perception_msgs__srv__DogRecordBag_Response__Sequence * array);

/// Create array of srv/DogRecordBag messages.
/**
 * It allocates the memory for the array and calls
 * perception_msgs__srv__DogRecordBag_Response__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
perception_msgs__srv__DogRecordBag_Response__Sequence *
perception_msgs__srv__DogRecordBag_Response__Sequence__create(size_t size);

/// Destroy array of srv/DogRecordBag messages.
/**
 * It calls
 * perception_msgs__srv__DogRecordBag_Response__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
void
perception_msgs__srv__DogRecordBag_Response__Sequence__destroy(perception_msgs__srv__DogRecordBag_Response__Sequence * array);

/// Check for srv/DogRecordBag message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
bool
perception_msgs__srv__DogRecordBag_Response__Sequence__are_equal(const perception_msgs__srv__DogRecordBag_Response__Sequence * lhs, const perception_msgs__srv__DogRecordBag_Response__Sequence * rhs);

/// Copy an array of srv/DogRecordBag messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_perception_msgs
bool
perception_msgs__srv__DogRecordBag_Response__Sequence__copy(
  const perception_msgs__srv__DogRecordBag_Response__Sequence * input,
  perception_msgs__srv__DogRecordBag_Response__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // PERCEPTION_MSGS__SRV__DETAIL__DOG_RECORD_BAG__FUNCTIONS_H_
