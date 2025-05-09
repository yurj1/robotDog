// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from perception_msgs:msg/DogState.idl
// generated code does not contain a copyright notice
#define NPY_NO_DEPRECATED_API NPY_1_7_API_VERSION
#include <Python.h>
#include <stdbool.h>
#ifndef _WIN32
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Wunused-function"
#endif
#include "numpy/ndarrayobject.h"
#ifndef _WIN32
# pragma GCC diagnostic pop
#endif
#include "rosidl_runtime_c/visibility_control.h"
#include "perception_msgs/msg/detail/dog_state__struct.h"
#include "perception_msgs/msg/detail/dog_state__functions.h"

#include "rosidl_runtime_c/primitives_sequence.h"
#include "rosidl_runtime_c/primitives_sequence_functions.h"

// Nested array functions includes
#include "perception_msgs/msg/detail/alarm_entry__functions.h"
// end nested array functions include
ROSIDL_GENERATOR_C_IMPORT
bool geometry_msgs__msg__pose__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * geometry_msgs__msg__pose__convert_to_py(void * raw_ros_message);
bool perception_msgs__msg__alarm_entry__convert_from_py(PyObject * _pymsg, void * _ros_message);
PyObject * perception_msgs__msg__alarm_entry__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool perception_msgs__msg__dog_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[40];
    {
      char * class_name = NULL;
      char * module_name = NULL;
      {
        PyObject * class_attr = PyObject_GetAttrString(_pymsg, "__class__");
        if (class_attr) {
          PyObject * name_attr = PyObject_GetAttrString(class_attr, "__name__");
          if (name_attr) {
            class_name = (char *)PyUnicode_1BYTE_DATA(name_attr);
            Py_DECREF(name_attr);
          }
          PyObject * module_attr = PyObject_GetAttrString(class_attr, "__module__");
          if (module_attr) {
            module_name = (char *)PyUnicode_1BYTE_DATA(module_attr);
            Py_DECREF(module_attr);
          }
          Py_DECREF(class_attr);
        }
      }
      if (!class_name || !module_name) {
        return false;
      }
      snprintf(full_classname_dest, sizeof(full_classname_dest), "%s.%s", module_name, class_name);
    }
    assert(strncmp("perception_msgs.msg._dog_state.DogState", full_classname_dest, 39) == 0);
  }
  perception_msgs__msg__DogState * ros_message = _ros_message;
  {  // battery
    PyObject * field = PyObject_GetAttrString(_pymsg, "battery");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->battery = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // charging_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "charging_state");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->charging_state = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // gesture
    PyObject * field = PyObject_GetAttrString(_pymsg, "gesture");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->gesture = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // speed
    PyObject * field = PyObject_GetAttrString(_pymsg, "speed");
    if (!field) {
      return false;
    }
    assert(PyFloat_Check(field));
    ros_message->speed = PyFloat_AS_DOUBLE(field);
    Py_DECREF(field);
  }
  {  // person_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "person_state");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->person_state = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // target_position
    PyObject * field = PyObject_GetAttrString(_pymsg, "target_position");
    if (!field) {
      return false;
    }
    if (!geometry_msgs__msg__pose__convert_from_py(field, &ros_message->target_position)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // alarm_info
    PyObject * field = PyObject_GetAttrString(_pymsg, "alarm_info");
    if (!field) {
      return false;
    }
    PyObject * seq_field = PySequence_Fast(field, "expected a sequence in 'alarm_info'");
    if (!seq_field) {
      Py_DECREF(field);
      return false;
    }
    Py_ssize_t size = PySequence_Size(field);
    if (-1 == size) {
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    if (!perception_msgs__msg__AlarmEntry__Sequence__init(&(ros_message->alarm_info), size)) {
      PyErr_SetString(PyExc_RuntimeError, "unable to create perception_msgs__msg__AlarmEntry__Sequence ros_message");
      Py_DECREF(seq_field);
      Py_DECREF(field);
      return false;
    }
    perception_msgs__msg__AlarmEntry * dest = ros_message->alarm_info.data;
    for (Py_ssize_t i = 0; i < size; ++i) {
      if (!perception_msgs__msg__alarm_entry__convert_from_py(PySequence_Fast_GET_ITEM(seq_field, i), &dest[i])) {
        Py_DECREF(seq_field);
        Py_DECREF(field);
        return false;
      }
    }
    Py_DECREF(seq_field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * perception_msgs__msg__dog_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of DogState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("perception_msgs.msg._dog_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "DogState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  perception_msgs__msg__DogState * ros_message = (perception_msgs__msg__DogState *)raw_ros_message;
  {  // battery
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->battery);
    {
      int rc = PyObject_SetAttrString(_pymessage, "battery", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // charging_state
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->charging_state);
    {
      int rc = PyObject_SetAttrString(_pymessage, "charging_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // gesture
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->gesture);
    {
      int rc = PyObject_SetAttrString(_pymessage, "gesture", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // speed
    PyObject * field = NULL;
    field = PyFloat_FromDouble(ros_message->speed);
    {
      int rc = PyObject_SetAttrString(_pymessage, "speed", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // person_state
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->person_state);
    {
      int rc = PyObject_SetAttrString(_pymessage, "person_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // target_position
    PyObject * field = NULL;
    field = geometry_msgs__msg__pose__convert_to_py(&ros_message->target_position);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "target_position", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // alarm_info
    PyObject * field = NULL;
    size_t size = ros_message->alarm_info.size;
    field = PyList_New(size);
    if (!field) {
      return NULL;
    }
    perception_msgs__msg__AlarmEntry * item;
    for (size_t i = 0; i < size; ++i) {
      item = &(ros_message->alarm_info.data[i]);
      PyObject * pyitem = perception_msgs__msg__alarm_entry__convert_to_py(item);
      if (!pyitem) {
        Py_DECREF(field);
        return NULL;
      }
      int rc = PyList_SetItem(field, i, pyitem);
      (void)rc;
      assert(rc == 0);
    }
    assert(PySequence_Check(field));
    {
      int rc = PyObject_SetAttrString(_pymessage, "alarm_info", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
