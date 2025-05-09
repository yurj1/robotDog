# generated from rosidl_generator_py/resource/_idl.py.em
# with input from perception_msgs:msg/DogState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DogState(type):
    """Metaclass of message 'DogState'."""

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
                'perception_msgs.msg.DogState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__dog_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__dog_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__dog_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__dog_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__dog_state

            from geometry_msgs.msg import Pose
            if Pose.__class__._TYPE_SUPPORT is None:
                Pose.__class__.__import_type_support__()

            from perception_msgs.msg import AlarmEntry
            if AlarmEntry.__class__._TYPE_SUPPORT is None:
                AlarmEntry.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DogState(metaclass=Metaclass_DogState):
    """Message class 'DogState'."""

    __slots__ = [
        '_battery',
        '_charging_state',
        '_gesture',
        '_speed',
        '_person_state',
        '_target_position',
        '_alarm_info',
    ]

    _fields_and_field_types = {
        'battery': 'double',
        'charging_state': 'uint8',
        'gesture': 'uint8',
        'speed': 'double',
        'person_state': 'uint8',
        'target_position': 'geometry_msgs/Pose',
        'alarm_info': 'sequence<perception_msgs/AlarmEntry>',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Pose'),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.NamespacedType(['perception_msgs', 'msg'], 'AlarmEntry')),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.battery = kwargs.get('battery', float())
        self.charging_state = kwargs.get('charging_state', int())
        self.gesture = kwargs.get('gesture', int())
        self.speed = kwargs.get('speed', float())
        self.person_state = kwargs.get('person_state', int())
        from geometry_msgs.msg import Pose
        self.target_position = kwargs.get('target_position', Pose())
        self.alarm_info = kwargs.get('alarm_info', [])

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
        if self.battery != other.battery:
            return False
        if self.charging_state != other.charging_state:
            return False
        if self.gesture != other.gesture:
            return False
        if self.speed != other.speed:
            return False
        if self.person_state != other.person_state:
            return False
        if self.target_position != other.target_position:
            return False
        if self.alarm_info != other.alarm_info:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def battery(self):
        """Message field 'battery'."""
        return self._battery

    @battery.setter
    def battery(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'battery' field must be of type 'float'"
        self._battery = value

    @property
    def charging_state(self):
        """Message field 'charging_state'."""
        return self._charging_state

    @charging_state.setter
    def charging_state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'charging_state' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'charging_state' field must be an unsigned integer in [0, 255]"
        self._charging_state = value

    @property
    def gesture(self):
        """Message field 'gesture'."""
        return self._gesture

    @gesture.setter
    def gesture(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'gesture' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'gesture' field must be an unsigned integer in [0, 255]"
        self._gesture = value

    @property
    def speed(self):
        """Message field 'speed'."""
        return self._speed

    @speed.setter
    def speed(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'speed' field must be of type 'float'"
        self._speed = value

    @property
    def person_state(self):
        """Message field 'person_state'."""
        return self._person_state

    @person_state.setter
    def person_state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'person_state' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'person_state' field must be an unsigned integer in [0, 255]"
        self._person_state = value

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
    def alarm_info(self):
        """Message field 'alarm_info'."""
        return self._alarm_info

    @alarm_info.setter
    def alarm_info(self, value):
        if __debug__:
            from perception_msgs.msg import AlarmEntry
            from collections.abc import Sequence
            from collections.abc import Set
            from collections import UserList
            from collections import UserString
            assert \
                ((isinstance(value, Sequence) or
                  isinstance(value, Set) or
                  isinstance(value, UserList)) and
                 not isinstance(value, str) and
                 not isinstance(value, UserString) and
                 all(isinstance(v, AlarmEntry) for v in value) and
                 True), \
                "The 'alarm_info' field must be a set or sequence and each value of type 'AlarmEntry'"
        self._alarm_info = value
