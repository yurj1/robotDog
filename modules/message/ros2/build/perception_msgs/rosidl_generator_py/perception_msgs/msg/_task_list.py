# generated from rosidl_generator_py/resource/_idl.py.em
# with input from perception_msgs:msg/TaskList.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_TaskList(type):
    """Metaclass of message 'TaskList'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('perception_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'perception_msgs.msg.TaskList')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__task_list
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__task_list
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__task_list
            cls._TYPE_SUPPORT = module.type_support_msg__msg__task_list
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__task_list

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class TaskList(metaclass=Metaclass_TaskList):
    """Message class 'TaskList'."""

    __slots__ = [
        '_task_id',
        '_task_type',
        '_target_position',
        '_target_object',
        '_task_state',
        '_task_result',
        '_is_in_place_rotation',
    ]

    _fields_and_field_types = {
        'task_id': 'uint64',
        'task_type': 'uint32',
        'target_position': 'geometry_msgs/Pose',
        'target_object': 'string',
        'task_state': 'uint8',
        'task_result': 'uint8',
        'is_in_place_rotation': 'uint8',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.task_id = kwargs.get('task_id', int())
        self.task_type = kwargs.get('task_type', int())
        from geometry_msgs.msg import Pose
        self.target_position = kwargs.get('target_position', Pose())
        self.target_object = kwargs.get('target_object', str())
        self.task_state = kwargs.get('task_state', int())
        self.task_result = kwargs.get('task_result', int())
        self.is_in_place_rotation = kwargs.get('is_in_place_rotation', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.task_id != other.task_id:
            return False
        if self.task_type != other.task_type:
            return False
        if self.target_position != other.target_position:
            return False
        if self.target_object != other.target_object:
            return False
        if self.task_state != other.task_state:
            return False
        if self.task_result != other.task_result:
            return False
        if self.is_in_place_rotation != other.is_in_place_rotation:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def task_id(self):
        """Message field 'task_id'."""
        return self._task_id

    @task_id.setter
    def task_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'task_id' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'task_id' field must be an unsigned integer in [0, 18446744073709551615]"
        self._task_id = value

    @property
    def task_type(self):
        """Message field 'task_type'."""
        return self._task_type

    @task_type.setter
    def task_type(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'task_type' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'task_type' field must be an unsigned integer in [0, 4294967295]"
        self._task_type = value

    @property
    def target_position(self):
        """Message field 'target_position'."""
        return self._target_position

    @target_position.setter
    def target_position(self, value):
        if __debug__:
            from geometry_msgs.msg import Pose
            assert \
                isinstance(value, Pose), \
                "The 'target_position' field must be a sub message of type 'Pose'"
        self._target_position = value

    @property
    def target_object(self):
        """Message field 'target_object'."""
        return self._target_object

    @target_object.setter
    def target_object(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'target_object' field must be of type 'str'"
        self._target_object = value

    @property
    def task_state(self):
        """Message field 'task_state'."""
        return self._task_state

    @task_state.setter
    def task_state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'task_state' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'task_state' field must be an unsigned integer in [0, 255]"
        self._task_state = value

    @property
    def task_result(self):
        """Message field 'task_result'."""
        return self._task_result

    @task_result.setter
    def task_result(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'task_result' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'task_result' field must be an unsigned integer in [0, 255]"
        self._task_result = value

    @property
    def is_in_place_rotation(self):
        """Message field 'is_in_place_rotation'."""
        return self._is_in_place_rotation

    @is_in_place_rotation.setter
    def is_in_place_rotation(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'is_in_place_rotation' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'is_in_place_rotation' field must be an unsigned integer in [0, 255]"
        self._is_in_place_rotation = value
