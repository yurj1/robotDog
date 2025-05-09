# generated from rosidl_generator_py/resource/_idl.py.em
# with input from perception_msgs:srv/DogRecordBag.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_DogRecordBag_Request(type):
    """Metaclass of message 'DogRecordBag_Request'."""

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
                'perception_msgs.srv.DogRecordBag_Request')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__dog_record_bag__request
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__dog_record_bag__request
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__dog_record_bag__request
            cls._TYPE_SUPPORT = module.type_support_msg__srv__dog_record_bag__request
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__dog_record_bag__request

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DogRecordBag_Request(metaclass=Metaclass_DogRecordBag_Request):
    """Message class 'DogRecordBag_Request'."""

    __slots__ = [
        '_bag_mode',
        '_bag_name',
        '_topics',
        '_bash_name',
    ]

    _fields_and_field_types = {
        'bag_mode': 'uint8',
        'bag_name': 'string',
        'topics': 'sequence<string>',
        'bash_name': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.UnboundedSequence(rosidl_parser.definition.UnboundedString()),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.bag_mode = kwargs.get('bag_mode', int())
        self.bag_name = kwargs.get('bag_name', str())
        self.topics = kwargs.get('topics', [])
        self.bash_name = kwargs.get('bash_name', str())

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
        if self.bag_mode != other.bag_mode:
            return False
        if self.bag_name != other.bag_name:
            return False
        if self.topics != other.topics:
            return False
        if self.bash_name != other.bash_name:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def bag_mode(self):
        """Message field 'bag_mode'."""
        return self._bag_mode

    @bag_mode.setter
    def bag_mode(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'bag_mode' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'bag_mode' field must be an unsigned integer in [0, 255]"
        self._bag_mode = value

    @property
    def bag_name(self):
        """Message field 'bag_name'."""
        return self._bag_name

    @bag_name.setter
    def bag_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'bag_name' field must be of type 'str'"
        self._bag_name = value

    @property
    def topics(self):
        """Message field 'topics'."""
        return self._topics

    @topics.setter
    def topics(self, value):
        if __debug__:
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
                 all(isinstance(v, str) for v in value) and
                 True), \
                "The 'topics' field must be a set or sequence and each value of type 'str'"
        self._topics = value

    @property
    def bash_name(self):
        """Message field 'bash_name'."""
        return self._bash_name

    @bash_name.setter
    def bash_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'bash_name' field must be of type 'str'"
        self._bash_name = value


# Import statements for member types

# already imported above
# import rosidl_parser.definition


class Metaclass_DogRecordBag_Response(type):
    """Metaclass of message 'DogRecordBag_Response'."""

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
                'perception_msgs.srv.DogRecordBag_Response')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__srv__dog_record_bag__response
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__srv__dog_record_bag__response
            cls._CONVERT_TO_PY = module.convert_to_py_msg__srv__dog_record_bag__response
            cls._TYPE_SUPPORT = module.type_support_msg__srv__dog_record_bag__response
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__srv__dog_record_bag__response

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class DogRecordBag_Response(metaclass=Metaclass_DogRecordBag_Response):
    """Message class 'DogRecordBag_Response'."""

    __slots__ = [
        '_success',
        '_error_info',
    ]

    _fields_and_field_types = {
        'success': 'boolean',
        'error_info': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('boolean'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.success = kwargs.get('success', bool())
        self.error_info = kwargs.get('error_info', str())

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
        if self.success != other.success:
            return False
        if self.error_info != other.error_info:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def success(self):
        """Message field 'success'."""
        return self._success

    @success.setter
    def success(self, value):
        if __debug__:
            assert \
                isinstance(value, bool), \
                "The 'success' field must be of type 'bool'"
        self._success = value

    @property
    def error_info(self):
        """Message field 'error_info'."""
        return self._error_info

    @error_info.setter
    def error_info(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'error_info' field must be of type 'str'"
        self._error_info = value


class Metaclass_DogRecordBag(type):
    """Metaclass of service 'DogRecordBag'."""

    _TYPE_SUPPORT = None

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('perception_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'perception_msgs.srv.DogRecordBag')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._TYPE_SUPPORT = module.type_support_srv__srv__dog_record_bag

            from perception_msgs.srv import _dog_record_bag
            if _dog_record_bag.Metaclass_DogRecordBag_Request._TYPE_SUPPORT is None:
                _dog_record_bag.Metaclass_DogRecordBag_Request.__import_type_support__()
            if _dog_record_bag.Metaclass_DogRecordBag_Response._TYPE_SUPPORT is None:
                _dog_record_bag.Metaclass_DogRecordBag_Response.__import_type_support__()


class DogRecordBag(metaclass=Metaclass_DogRecordBag):
    from perception_msgs.srv._dog_record_bag import DogRecordBag_Request as Request
    from perception_msgs.srv._dog_record_bag import DogRecordBag_Response as Response

    def __init__(self):
        raise NotImplementedError('Service classes can not be instantiated')
