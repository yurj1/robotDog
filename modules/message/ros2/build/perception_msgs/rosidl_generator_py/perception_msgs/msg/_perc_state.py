# generated from rosidl_generator_py/resource/_idl.py.em
# with input from perception_msgs:msg/PercState.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PercState(type):
    """Metaclass of message 'PercState'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
        'ACTION_IDLE': 0,
        'ACTION_RUNNING': 1,
        'ACTION_DONE': 2,
        'ACTION_NONE': 0,
        'ACTION_SUCCESS': 1,
        'ACTION_FAIL': 2,
        'ACTION_ERR_NONE': 0,
        'ACTION_ERR_NOWORK': 1,
        'PERC_DEST': 1,
        'PERC_ABS': 2,
        'PERC_REL': 3,
        'PERC_AUTO_CHARGING': 20,
        'PERC_CHECK_ENV': 21,
        'PERC_AUTO_MAPPING': 22,
        'PERC_FOLLOW': 30,
        'PERC_STRANGER_WELCOME': 31,
        'PERC_OWNER_WELCOME': 32,
        'PERC_BEHAVIOR_INTERACTION': 33,
        'PERC_HANDSHAKE': 34,
        'PERC_STANDBY_ACCOMPANY': 35,
        'PERC_HAPPY_ACCOMPANY': 36,
        'PERC_WORK_ACCOMPANY': 37,
        'PERC_POSITIVE_ACCOMPANY': 38,
        'PERC_NEGATIVE_ACCOMPANY': 39,
        'PERC_CHILD_WATCH': 40,
        'PERC_OLDER_WATCH': 41,
        'PERC_DANGER_REMINDER': 42,
        'PERC_EVENT_REMINDER': 43,
        'PERC_CATWALK_START': 44,
        'PERC_CATWALK_ACT': 45,
        'PERC_CATWALK_SHOW': 46,
        'PERC_CATWALK_BACK': 47,
        'PERC_FREE_TIME': 50,
        'PERC_SOCIALIZE': 51,
        'PERC_DANGER_INFO': 60,
        'PERC_WELCOME_DEMO': 70,
        'PERC_CANCEL': 100,
        'PERC_NODE_CLOSE': 200,
        'PERC_NODE_START': 201,
        'PERC_NODE_RESET': 202,
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
                'perception_msgs.msg.PercState')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__perc_state
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__perc_state
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__perc_state
            cls._TYPE_SUPPORT = module.type_support_msg__msg__perc_state
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__perc_state

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
            'ACTION_IDLE': cls.__constants['ACTION_IDLE'],
            'ACTION_RUNNING': cls.__constants['ACTION_RUNNING'],
            'ACTION_DONE': cls.__constants['ACTION_DONE'],
            'ACTION_NONE': cls.__constants['ACTION_NONE'],
            'ACTION_SUCCESS': cls.__constants['ACTION_SUCCESS'],
            'ACTION_FAIL': cls.__constants['ACTION_FAIL'],
            'ACTION_ERR_NONE': cls.__constants['ACTION_ERR_NONE'],
            'ACTION_ERR_NOWORK': cls.__constants['ACTION_ERR_NOWORK'],
            'PERC_DEST': cls.__constants['PERC_DEST'],
            'PERC_ABS': cls.__constants['PERC_ABS'],
            'PERC_REL': cls.__constants['PERC_REL'],
            'PERC_AUTO_CHARGING': cls.__constants['PERC_AUTO_CHARGING'],
            'PERC_CHECK_ENV': cls.__constants['PERC_CHECK_ENV'],
            'PERC_AUTO_MAPPING': cls.__constants['PERC_AUTO_MAPPING'],
            'PERC_FOLLOW': cls.__constants['PERC_FOLLOW'],
            'PERC_STRANGER_WELCOME': cls.__constants['PERC_STRANGER_WELCOME'],
            'PERC_OWNER_WELCOME': cls.__constants['PERC_OWNER_WELCOME'],
            'PERC_BEHAVIOR_INTERACTION': cls.__constants['PERC_BEHAVIOR_INTERACTION'],
            'PERC_HANDSHAKE': cls.__constants['PERC_HANDSHAKE'],
            'PERC_STANDBY_ACCOMPANY': cls.__constants['PERC_STANDBY_ACCOMPANY'],
            'PERC_HAPPY_ACCOMPANY': cls.__constants['PERC_HAPPY_ACCOMPANY'],
            'PERC_WORK_ACCOMPANY': cls.__constants['PERC_WORK_ACCOMPANY'],
            'PERC_POSITIVE_ACCOMPANY': cls.__constants['PERC_POSITIVE_ACCOMPANY'],
            'PERC_NEGATIVE_ACCOMPANY': cls.__constants['PERC_NEGATIVE_ACCOMPANY'],
            'PERC_CHILD_WATCH': cls.__constants['PERC_CHILD_WATCH'],
            'PERC_OLDER_WATCH': cls.__constants['PERC_OLDER_WATCH'],
            'PERC_DANGER_REMINDER': cls.__constants['PERC_DANGER_REMINDER'],
            'PERC_EVENT_REMINDER': cls.__constants['PERC_EVENT_REMINDER'],
            'PERC_CATWALK_START': cls.__constants['PERC_CATWALK_START'],
            'PERC_CATWALK_ACT': cls.__constants['PERC_CATWALK_ACT'],
            'PERC_CATWALK_SHOW': cls.__constants['PERC_CATWALK_SHOW'],
            'PERC_CATWALK_BACK': cls.__constants['PERC_CATWALK_BACK'],
            'PERC_FREE_TIME': cls.__constants['PERC_FREE_TIME'],
            'PERC_SOCIALIZE': cls.__constants['PERC_SOCIALIZE'],
            'PERC_DANGER_INFO': cls.__constants['PERC_DANGER_INFO'],
            'PERC_WELCOME_DEMO': cls.__constants['PERC_WELCOME_DEMO'],
            'PERC_CANCEL': cls.__constants['PERC_CANCEL'],
            'PERC_NODE_CLOSE': cls.__constants['PERC_NODE_CLOSE'],
            'PERC_NODE_START': cls.__constants['PERC_NODE_START'],
            'PERC_NODE_RESET': cls.__constants['PERC_NODE_RESET'],
        }

    @property
    def ACTION_IDLE(self):
        """Message constant 'ACTION_IDLE'."""
        return Metaclass_PercState.__constants['ACTION_IDLE']

    @property
    def ACTION_RUNNING(self):
        """Message constant 'ACTION_RUNNING'."""
        return Metaclass_PercState.__constants['ACTION_RUNNING']

    @property
    def ACTION_DONE(self):
        """Message constant 'ACTION_DONE'."""
        return Metaclass_PercState.__constants['ACTION_DONE']

    @property
    def ACTION_NONE(self):
        """Message constant 'ACTION_NONE'."""
        return Metaclass_PercState.__constants['ACTION_NONE']

    @property
    def ACTION_SUCCESS(self):
        """Message constant 'ACTION_SUCCESS'."""
        return Metaclass_PercState.__constants['ACTION_SUCCESS']

    @property
    def ACTION_FAIL(self):
        """Message constant 'ACTION_FAIL'."""
        return Metaclass_PercState.__constants['ACTION_FAIL']

    @property
    def ACTION_ERR_NONE(self):
        """Message constant 'ACTION_ERR_NONE'."""
        return Metaclass_PercState.__constants['ACTION_ERR_NONE']

    @property
    def ACTION_ERR_NOWORK(self):
        """Message constant 'ACTION_ERR_NOWORK'."""
        return Metaclass_PercState.__constants['ACTION_ERR_NOWORK']

    @property
    def PERC_DEST(self):
        """Message constant 'PERC_DEST'."""
        return Metaclass_PercState.__constants['PERC_DEST']

    @property
    def PERC_ABS(self):
        """Message constant 'PERC_ABS'."""
        return Metaclass_PercState.__constants['PERC_ABS']

    @property
    def PERC_REL(self):
        """Message constant 'PERC_REL'."""
        return Metaclass_PercState.__constants['PERC_REL']

    @property
    def PERC_AUTO_CHARGING(self):
        """Message constant 'PERC_AUTO_CHARGING'."""
        return Metaclass_PercState.__constants['PERC_AUTO_CHARGING']

    @property
    def PERC_CHECK_ENV(self):
        """Message constant 'PERC_CHECK_ENV'."""
        return Metaclass_PercState.__constants['PERC_CHECK_ENV']

    @property
    def PERC_AUTO_MAPPING(self):
        """Message constant 'PERC_AUTO_MAPPING'."""
        return Metaclass_PercState.__constants['PERC_AUTO_MAPPING']

    @property
    def PERC_FOLLOW(self):
        """Message constant 'PERC_FOLLOW'."""
        return Metaclass_PercState.__constants['PERC_FOLLOW']

    @property
    def PERC_STRANGER_WELCOME(self):
        """Message constant 'PERC_STRANGER_WELCOME'."""
        return Metaclass_PercState.__constants['PERC_STRANGER_WELCOME']

    @property
    def PERC_OWNER_WELCOME(self):
        """Message constant 'PERC_OWNER_WELCOME'."""
        return Metaclass_PercState.__constants['PERC_OWNER_WELCOME']

    @property
    def PERC_BEHAVIOR_INTERACTION(self):
        """Message constant 'PERC_BEHAVIOR_INTERACTION'."""
        return Metaclass_PercState.__constants['PERC_BEHAVIOR_INTERACTION']

    @property
    def PERC_HANDSHAKE(self):
        """Message constant 'PERC_HANDSHAKE'."""
        return Metaclass_PercState.__constants['PERC_HANDSHAKE']

    @property
    def PERC_STANDBY_ACCOMPANY(self):
        """Message constant 'PERC_STANDBY_ACCOMPANY'."""
        return Metaclass_PercState.__constants['PERC_STANDBY_ACCOMPANY']

    @property
    def PERC_HAPPY_ACCOMPANY(self):
        """Message constant 'PERC_HAPPY_ACCOMPANY'."""
        return Metaclass_PercState.__constants['PERC_HAPPY_ACCOMPANY']

    @property
    def PERC_WORK_ACCOMPANY(self):
        """Message constant 'PERC_WORK_ACCOMPANY'."""
        return Metaclass_PercState.__constants['PERC_WORK_ACCOMPANY']

    @property
    def PERC_POSITIVE_ACCOMPANY(self):
        """Message constant 'PERC_POSITIVE_ACCOMPANY'."""
        return Metaclass_PercState.__constants['PERC_POSITIVE_ACCOMPANY']

    @property
    def PERC_NEGATIVE_ACCOMPANY(self):
        """Message constant 'PERC_NEGATIVE_ACCOMPANY'."""
        return Metaclass_PercState.__constants['PERC_NEGATIVE_ACCOMPANY']

    @property
    def PERC_CHILD_WATCH(self):
        """Message constant 'PERC_CHILD_WATCH'."""
        return Metaclass_PercState.__constants['PERC_CHILD_WATCH']

    @property
    def PERC_OLDER_WATCH(self):
        """Message constant 'PERC_OLDER_WATCH'."""
        return Metaclass_PercState.__constants['PERC_OLDER_WATCH']

    @property
    def PERC_DANGER_REMINDER(self):
        """Message constant 'PERC_DANGER_REMINDER'."""
        return Metaclass_PercState.__constants['PERC_DANGER_REMINDER']

    @property
    def PERC_EVENT_REMINDER(self):
        """Message constant 'PERC_EVENT_REMINDER'."""
        return Metaclass_PercState.__constants['PERC_EVENT_REMINDER']

    @property
    def PERC_CATWALK_START(self):
        """Message constant 'PERC_CATWALK_START'."""
        return Metaclass_PercState.__constants['PERC_CATWALK_START']

    @property
    def PERC_CATWALK_ACT(self):
        """Message constant 'PERC_CATWALK_ACT'."""
        return Metaclass_PercState.__constants['PERC_CATWALK_ACT']

    @property
    def PERC_CATWALK_SHOW(self):
        """Message constant 'PERC_CATWALK_SHOW'."""
        return Metaclass_PercState.__constants['PERC_CATWALK_SHOW']

    @property
    def PERC_CATWALK_BACK(self):
        """Message constant 'PERC_CATWALK_BACK'."""
        return Metaclass_PercState.__constants['PERC_CATWALK_BACK']

    @property
    def PERC_FREE_TIME(self):
        """Message constant 'PERC_FREE_TIME'."""
        return Metaclass_PercState.__constants['PERC_FREE_TIME']

    @property
    def PERC_SOCIALIZE(self):
        """Message constant 'PERC_SOCIALIZE'."""
        return Metaclass_PercState.__constants['PERC_SOCIALIZE']

    @property
    def PERC_DANGER_INFO(self):
        """Message constant 'PERC_DANGER_INFO'."""
        return Metaclass_PercState.__constants['PERC_DANGER_INFO']

    @property
    def PERC_WELCOME_DEMO(self):
        """Message constant 'PERC_WELCOME_DEMO'."""
        return Metaclass_PercState.__constants['PERC_WELCOME_DEMO']

    @property
    def PERC_CANCEL(self):
        """Message constant 'PERC_CANCEL'."""
        return Metaclass_PercState.__constants['PERC_CANCEL']

    @property
    def PERC_NODE_CLOSE(self):
        """Message constant 'PERC_NODE_CLOSE'."""
        return Metaclass_PercState.__constants['PERC_NODE_CLOSE']

    @property
    def PERC_NODE_START(self):
        """Message constant 'PERC_NODE_START'."""
        return Metaclass_PercState.__constants['PERC_NODE_START']

    @property
    def PERC_NODE_RESET(self):
        """Message constant 'PERC_NODE_RESET'."""
        return Metaclass_PercState.__constants['PERC_NODE_RESET']


class PercState(metaclass=Metaclass_PercState):
    """
    Message class 'PercState'.

    Constants:
      ACTION_IDLE
      ACTION_RUNNING
      ACTION_DONE
      ACTION_NONE
      ACTION_SUCCESS
      ACTION_FAIL
      ACTION_ERR_NONE
      ACTION_ERR_NOWORK
      PERC_DEST
      PERC_ABS
      PERC_REL
      PERC_AUTO_CHARGING
      PERC_CHECK_ENV
      PERC_AUTO_MAPPING
      PERC_FOLLOW
      PERC_STRANGER_WELCOME
      PERC_OWNER_WELCOME
      PERC_BEHAVIOR_INTERACTION
      PERC_HANDSHAKE
      PERC_STANDBY_ACCOMPANY
      PERC_HAPPY_ACCOMPANY
      PERC_WORK_ACCOMPANY
      PERC_POSITIVE_ACCOMPANY
      PERC_NEGATIVE_ACCOMPANY
      PERC_CHILD_WATCH
      PERC_OLDER_WATCH
      PERC_DANGER_REMINDER
      PERC_EVENT_REMINDER
      PERC_CATWALK_START
      PERC_CATWALK_ACT
      PERC_CATWALK_SHOW
      PERC_CATWALK_BACK
      PERC_FREE_TIME
      PERC_SOCIALIZE
      PERC_DANGER_INFO
      PERC_WELCOME_DEMO
      PERC_CANCEL
      PERC_NODE_CLOSE
      PERC_NODE_START
      PERC_NODE_RESET
    """

    __slots__ = [
        '_header',
        '_action_id',
        '_perc_kind',
        '_exe_state',
        '_exe_result',
        '_err_code',
        '_err_info',
        '_wait_for_millisec',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'action_id': 'uint64',
        'perc_kind': 'uint32',
        'exe_state': 'uint8',
        'exe_result': 'uint8',
        'err_code': 'uint16',
        'err_info': 'string',
        'wait_for_millisec': 'uint64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint8'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint16'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.action_id = kwargs.get('action_id', int())
        self.perc_kind = kwargs.get('perc_kind', int())
        self.exe_state = kwargs.get('exe_state', int())
        self.exe_result = kwargs.get('exe_result', int())
        self.err_code = kwargs.get('err_code', int())
        self.err_info = kwargs.get('err_info', str())
        self.wait_for_millisec = kwargs.get('wait_for_millisec', int())

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
        if self.header != other.header:
            return False
        if self.action_id != other.action_id:
            return False
        if self.perc_kind != other.perc_kind:
            return False
        if self.exe_state != other.exe_state:
            return False
        if self.exe_result != other.exe_result:
            return False
        if self.err_code != other.err_code:
            return False
        if self.err_info != other.err_info:
            return False
        if self.wait_for_millisec != other.wait_for_millisec:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @property
    def action_id(self):
        """Message field 'action_id'."""
        return self._action_id

    @action_id.setter
    def action_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'action_id' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'action_id' field must be an unsigned integer in [0, 18446744073709551615]"
        self._action_id = value

    @property
    def perc_kind(self):
        """Message field 'perc_kind'."""
        return self._perc_kind

    @perc_kind.setter
    def perc_kind(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'perc_kind' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'perc_kind' field must be an unsigned integer in [0, 4294967295]"
        self._perc_kind = value

    @property
    def exe_state(self):
        """Message field 'exe_state'."""
        return self._exe_state

    @exe_state.setter
    def exe_state(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'exe_state' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'exe_state' field must be an unsigned integer in [0, 255]"
        self._exe_state = value

    @property
    def exe_result(self):
        """Message field 'exe_result'."""
        return self._exe_result

    @exe_result.setter
    def exe_result(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'exe_result' field must be of type 'int'"
            assert value >= 0 and value < 256, \
                "The 'exe_result' field must be an unsigned integer in [0, 255]"
        self._exe_result = value

    @property
    def err_code(self):
        """Message field 'err_code'."""
        return self._err_code

    @err_code.setter
    def err_code(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'err_code' field must be of type 'int'"
            assert value >= 0 and value < 65536, \
                "The 'err_code' field must be an unsigned integer in [0, 65535]"
        self._err_code = value

    @property
    def err_info(self):
        """Message field 'err_info'."""
        return self._err_info

    @err_info.setter
    def err_info(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'err_info' field must be of type 'str'"
        self._err_info = value

    @property
    def wait_for_millisec(self):
        """Message field 'wait_for_millisec'."""
        return self._wait_for_millisec

    @wait_for_millisec.setter
    def wait_for_millisec(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'wait_for_millisec' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'wait_for_millisec' field must be an unsigned integer in [0, 18446744073709551615]"
        self._wait_for_millisec = value
