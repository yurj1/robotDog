// generated from rosidl_generator_py/resource/_idl_support.c.em
// with input from perception_msgs:msg/PercState.idl
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
#include "perception_msgs/msg/detail/perc_state__struct.h"
#include "perception_msgs/msg/detail/perc_state__functions.h"

#include "rosidl_runtime_c/string.h"
#include "rosidl_runtime_c/string_functions.h"

ROSIDL_GENERATOR_C_IMPORT
bool std_msgs__msg__header__convert_from_py(PyObject * _pymsg, void * _ros_message);
ROSIDL_GENERATOR_C_IMPORT
PyObject * std_msgs__msg__header__convert_to_py(void * raw_ros_message);

ROSIDL_GENERATOR_C_EXPORT
bool perception_msgs__msg__perc_state__convert_from_py(PyObject * _pymsg, void * _ros_message)
{
  // check that the passed message is of the expected Python class
  {
    char full_classname_dest[42];
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
    assert(strncmp("perception_msgs.msg._perc_state.PercState", full_classname_dest, 41) == 0);
  }
  perception_msgs__msg__PercState * ros_message = _ros_message;
  {  // header
    PyObject * field = PyObject_GetAttrString(_pymsg, "header");
    if (!field) {
      return false;
    }
    if (!std_msgs__msg__header__convert_from_py(field, &ros_message->header)) {
      Py_DECREF(field);
      return false;
    }
    Py_DECREF(field);
  }
  {  // action_id
    PyObject * field = PyObject_GetAttrString(_pymsg, "action_id");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->action_id = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }
  {  // perc_kind
    PyObject * field = PyObject_GetAttrString(_pymsg, "perc_kind");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->perc_kind = PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // exe_state
    PyObject * field = PyObject_GetAttrString(_pymsg, "exe_state");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->exe_state = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // exe_result
    PyObject * field = PyObject_GetAttrString(_pymsg, "exe_result");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->exe_result = (uint8_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // err_code
    PyObject * field = PyObject_GetAttrString(_pymsg, "err_code");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->err_code = (uint16_t)PyLong_AsUnsignedLong(field);
    Py_DECREF(field);
  }
  {  // err_info
    PyObject * field = PyObject_GetAttrString(_pymsg, "err_info");
    if (!field) {
      return false;
    }
    assert(PyUnicode_Check(field));
    PyObject * encoded_field = PyUnicode_AsUTF8String(field);
    if (!encoded_field) {
      Py_DECREF(field);
      return false;
    }
    rosidl_runtime_c__String__assign(&ros_message->err_info, PyBytes_AS_STRING(encoded_field));
    Py_DECREF(encoded_field);
    Py_DECREF(field);
  }
  {  // wait_for_millisec
    PyObject * field = PyObject_GetAttrString(_pymsg, "wait_for_millisec");
    if (!field) {
      return false;
    }
    assert(PyLong_Check(field));
    ros_message->wait_for_millisec = PyLong_AsUnsignedLongLong(field);
    Py_DECREF(field);
  }

  return true;
}

ROSIDL_GENERATOR_C_EXPORT
PyObject * perception_msgs__msg__perc_state__convert_to_py(void * raw_ros_message)
{
  /* NOTE(esteve): Call constructor of PercState */
  PyObject * _pymessage = NULL;
  {
    PyObject * pymessage_module = PyImport_ImportModule("perception_msgs.msg._perc_state");
    assert(pymessage_module);
    PyObject * pymessage_class = PyObject_GetAttrString(pymessage_module, "PercState");
    assert(pymessage_class);
    Py_DECREF(pymessage_module);
    _pymessage = PyObject_CallObject(pymessage_class, NULL);
    Py_DECREF(pymessage_class);
    if (!_pymessage) {
      return NULL;
    }
  }
  perception_msgs__msg__PercState * ros_message = (perception_msgs__msg__PercState *)raw_ros_message;
  {  // header
    PyObject * field = NULL;
    field = std_msgs__msg__header__convert_to_py(&ros_message->header);
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "header", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // action_id
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->action_id);
    {
      int rc = PyObject_SetAttrString(_pymessage, "action_id", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // perc_kind
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->perc_kind);
    {
      int rc = PyObject_SetAttrString(_pymessage, "perc_kind", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // exe_state
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->exe_state);
    {
      int rc = PyObject_SetAttrString(_pymessage, "exe_state", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // exe_result
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->exe_result);
    {
      int rc = PyObject_SetAttrString(_pymessage, "exe_result", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // err_code
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLong(ros_message->err_code);
    {
      int rc = PyObject_SetAttrString(_pymessage, "err_code", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // err_info
    PyObject * field = NULL;
    field = PyUnicode_DecodeUTF8(
      ros_message->err_info.data,
      strlen(ros_message->err_info.data),
      "replace");
    if (!field) {
      return NULL;
    }
    {
      int rc = PyObject_SetAttrString(_pymessage, "err_info", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }
  {  // wait_for_millisec
    PyObject * field = NULL;
    field = PyLong_FromUnsignedLongLong(ros_message->wait_for_millisec);
    {
      int rc = PyObject_SetAttrString(_pymessage, "wait_for_millisec", field);
      Py_DECREF(field);
      if (rc) {
        return NULL;
      }
    }
  }

  // ownership of _pymessage is transferred to the caller
  return _pymessage;
}
