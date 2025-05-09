# generated from rosidl_generator_py/resource/_idl.py.em
# with input from perception_msgs:msg/PercReq.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PercReq(type):
    """Metaclass of message 'PercReq'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
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
        'PERC_SPECT_PERFORM': 55,
        'PERC_FACE_DETCTION': 56,
        'PERC_DANGER_INFO': 60,
        'PERC_HAND_OK': 70,
        'PERC_HAND_V': 71,
        'PERC_HAND_SHAKE': 72,
        'PERC_HAND_COME': 73,
        'PERC_HAND_WAVE': 74,
        'PERC_CAMERA_DEMO': 80,
        'PERC_CANCEL': 100,
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
                'perception_msgs.msg.PercReq')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__perc_req
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__perc_req
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__perc_req
            cls._TYPE_SUPPORT = module.type_support_msg__msg__perc_req
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__perc_req

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
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
            'PERC_SPECT_PERFORM': cls.__constants['PERC_SPECT_PERFORM'],
            'PERC_FACE_DETCTION': cls.__constants['PERC_FACE_DETCTION'],
            'PERC_DANGER_INFO': cls.__constants['PERC_DANGER_INFO'],
            'PERC_HAND_OK': cls.__constants['PERC_HAND_OK'],
            'PERC_HAND_V': cls.__constants['PERC_HAND_V'],
            'PERC_HAND_SHAKE': cls.__constants['PERC_HAND_SHAKE'],
            'PERC_HAND_COME': cls.__constants['PERC_HAND_COME'],
            'PERC_HAND_WAVE': cls.__constants['PERC_HAND_WAVE'],
            'PERC_CAMERA_DEMO': cls.__constants['PERC_CAMERA_DEMO'],
            'PERC_CANCEL': cls.__constants['PERC_CANCEL'],
        }

    @property
    def PERC_AUTO_CHARGING(self):
        """Message constant 'PERC_AUTO_CHARGING'."""
        return Metaclass_PercReq.__constants['PERC_AUTO_CHARGING']

    @property
    def PERC_CHECK_ENV(self):
        """Message constant 'PERC_CHECK_ENV'."""
        return Metaclass_PercReq.__constants['PERC_CHECK_ENV']

    @property
    def PERC_AUTO_MAPPING(self):
        """Message constant 'PERC_AUTO_MAPPING'."""
        return Metaclass_PercReq.__constants['PERC_AUTO_MAPPING']

    @property
    def PERC_FOLLOW(self):
        """Message constant 'PERC_FOLLOW'."""
        return Metaclass_PercReq.__constants['PERC_FOLLOW']

    @property
    def PERC_STRANGER_WELCOME(self):
        """Message constant 'PERC_STRANGER_WELCOME'."""
        return Metaclass_PercReq.__constants['PERC_STRANGER_WELCOME']

    @property
    def PERC_OWNER_WELCOME(self):
        """Message constant 'PERC_OWNER_WELCOME'."""
        return Metaclass_PercReq.__constants['PERC_OWNER_WELCOME']

    @property
    def PERC_BEHAVIOR_INTERACTION(self):
        """Message constant 'PERC_BEHAVIOR_INTERACTION'."""
        return Metaclass_PercReq.__constants['PERC_BEHAVIOR_INTERACTION']

    @property
    def PERC_HANDSHAKE(self):
        """Message constant 'PERC_HANDSHAKE'."""
        return Metaclass_PercReq.__constants['PERC_HANDSHAKE']

    @property
    def PERC_STANDBY_ACCOMPANY(self):
        """Message constant 'PERC_STANDBY_ACCOMPANY'."""
        return Metaclass_PercReq.__constants['PERC_STANDBY_ACCOMPANY']

    @property
    def PERC_HAPPY_ACCOMPANY(self):
        """Message constant 'PERC_HAPPY_ACCOMPANY'."""
        return Metaclass_PercReq.__constants['PERC_HAPPY_ACCOMPANY']

    @property
    def PERC_WORK_ACCOMPANY(self):
        """Message constant 'PERC_WORK_ACCOMPANY'."""
        return Metaclass_PercReq.__constants['PERC_WORK_ACCOMPANY']

    @property
    def PERC_POSITIVE_ACCOMPANY(self):
        """Message constant 'PERC_POSITIVE_ACCOMPANY'."""
        return Metaclass_PercReq.__constants['PERC_POSITIVE_ACCOMPANY']

    @property
    def PERC_NEGATIVE_ACCOMPANY(self):
        """Message constant 'PERC_NEGATIVE_ACCOMPANY'."""
        return Metaclass_PercReq.__constants['PERC_NEGATIVE_ACCOMPANY']

    @property
    def PERC_CHILD_WATCH(self):
        """Message constant 'PERC_CHILD_WATCH'."""
        return Metaclass_PercReq.__constants['PERC_CHILD_WATCH']

    @property
    def PERC_OLDER_WATCH(self):
        """Message constant 'PERC_OLDER_WATCH'."""
        return Metaclass_PercReq.__constants['PERC_OLDER_WATCH']

    @property
    def PERC_DANGER_REMINDER(self):
        """Message constant 'PERC_DANGER_REMINDER'."""
        return Metaclass_PercReq.__constants['PERC_DANGER_REMINDER']

    @property
    def PERC_EVENT_REMINDER(self):
        """Message constant 'PERC_EVENT_REMINDER'."""
        return Metaclass_PercReq.__constants['PERC_EVENT_REMINDER']

    @property
    def PERC_CATWALK_START(self):
        """Message constant 'PERC_CATWALK_START'."""
        return Metaclass_PercReq.__constants['PERC_CATWALK_START']

    @property
    def PERC_CATWALK_ACT(self):
        """Message constant 'PERC_CATWALK_ACT'."""
        return Metaclass_PercReq.__constants['PERC_CATWALK_ACT']

    @property
    def PERC_CATWALK_SHOW(self):
        """Message constant 'PERC_CATWALK_SHOW'."""
        return Metaclass_PercReq.__constants['PERC_CATWALK_SHOW']

    @property
    def PERC_CATWALK_BACK(self):
        """Message constant 'PERC_CATWALK_BACK'."""
        return Metaclass_PercReq.__constants['PERC_CATWALK_BACK']

    @property
    def PERC_FREE_TIME(self):
        """Message constant 'PERC_FREE_TIME'."""
        return Metaclass_PercReq.__constants['PERC_FREE_TIME']

    @property
    def PERC_SOCIALIZE(self):
        """Message constant 'PERC_SOCIALIZE'."""
        return Metaclass_PercReq.__constants['PERC_SOCIALIZE']

    @property
    def PERC_SPECT_PERFORM(self):
        """Message constant 'PERC_SPECT_PERFORM'."""
        return Metaclass_PercReq.__constants['PERC_SPECT_PERFORM']

    @property
    def PERC_FACE_DETCTION(self):
        """Message constant 'PERC_FACE_DETCTION'."""
        return Metaclass_PercReq.__constants['PERC_FACE_DETCTION']

    @property
    def PERC_DANGER_INFO(self):
        """Message constant 'PERC_DANGER_INFO'."""
        return Metaclass_PercReq.__constants['PERC_DANGER_INFO']

    @property
    def PERC_HAND_OK(self):
        """Message constant 'PERC_HAND_OK'."""
        return Metaclass_PercReq.__constants['PERC_HAND_OK']

    @property
    def PERC_HAND_V(self):
        """Message constant 'PERC_HAND_V'."""
        return Metaclass_PercReq.__constants['PERC_HAND_V']

    @property
    def PERC_HAND_SHAKE(self):
        """Message constant 'PERC_HAND_SHAKE'."""
        return Metaclass_PercReq.__constants['PERC_HAND_SHAKE']

    @property
    def PERC_HAND_COME(self):
        """Message constant 'PERC_HAND_COME'."""
        return Metaclass_PercReq.__constants['PERC_HAND_COME']

    @property
    def PERC_HAND_WAVE(self):
        """Message constant 'PERC_HAND_WAVE'."""
        return Metaclass_PercReq.__constants['PERC_HAND_WAVE']

    @property
    def PERC_CAMERA_DEMO(self):
        """Message constant 'PERC_CAMERA_DEMO'."""
        return Metaclass_PercReq.__constants['PERC_CAMERA_DEMO']

    @property
    def PERC_CANCEL(self):
        """Message constant 'PERC_CANCEL'."""
        return Metaclass_PercReq.__constants['PERC_CANCEL']


class PercReq(metaclass=Metaclass_PercReq):
    """
    Message class 'PercReq'.

    Constants:
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
      PERC_SPECT_PERFORM
      PERC_FACE_DETCTION
      PERC_DANGER_INFO
      PERC_HAND_OK
      PERC_HAND_V
      PERC_HAND_SHAKE
      PERC_HAND_COME
      PERC_HAND_WAVE
      PERC_CAMERA_DEMO
      PERC_CANCEL
    """

    __slots__ = [
        '_req_id',
        '_perc_kind',
        '_danger_info',
    ]

    _fields_and_field_types = {
        'req_id': 'uint64',
        'perc_kind': 'uint32',
        'danger_info': 'string',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        self.req_id = kwargs.get('req_id', int())
        self.perc_kind = kwargs.get('perc_kind', int())
        self.danger_info = kwargs.get('danger_info', str())

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
        if self.req_id != other.req_id:
            return False
        if self.perc_kind != other.perc_kind:
            return False
        if self.danger_info != other.danger_info:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @property
    def req_id(self):
        """Message field 'req_id'."""
        return self._req_id

    @req_id.setter
    def req_id(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'req_id' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'req_id' field must be an unsigned integer in [0, 18446744073709551615]"
        self._req_id = value

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
    def danger_info(self):
        """Message field 'danger_info'."""
        return self._danger_info

    @danger_info.setter
    def danger_info(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'danger_info' field must be of type 'str'"
        self._danger_info = value
