# generated from rosidl_generator_py/resource/_idl.py.em
# with input from perception_msgs:msg/PercCmd.idl
# generated code does not contain a copyright notice


# Import statements for member types

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_PercCmd(type):
    """Metaclass of message 'PercCmd'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
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
        'PERC_SPECT_PERFORM': 55,
        'PERC_FACE_DETCTION': 56,
        'PERC_DANGER_INFO': 60,
        'PERC_WELCOME_DEMO': 61,
        'PERC_LOBBY_DEMO': 62,
        'PERC_CANCEL': 100,
        'PERC_NODE_CLOSE': 200,
        'PERC_NODE_START': 201,
        'PERC_NODE_RESET': 202,
        'FOLLOW_ON': 1,
        'FOLLOW_OFF': 2,
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
                'perception_msgs.msg.PercCmd')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__perc_cmd
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__perc_cmd
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__perc_cmd
            cls._TYPE_SUPPORT = module.type_support_msg__msg__perc_cmd
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__perc_cmd

            from geometry_msgs.msg import Point
            if Point.__class__._TYPE_SUPPORT is None:
                Point.__class__.__import_type_support__()

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
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
            'PERC_SPECT_PERFORM': cls.__constants['PERC_SPECT_PERFORM'],
            'PERC_FACE_DETCTION': cls.__constants['PERC_FACE_DETCTION'],
            'PERC_DANGER_INFO': cls.__constants['PERC_DANGER_INFO'],
            'PERC_WELCOME_DEMO': cls.__constants['PERC_WELCOME_DEMO'],
            'PERC_LOBBY_DEMO': cls.__constants['PERC_LOBBY_DEMO'],
            'PERC_CANCEL': cls.__constants['PERC_CANCEL'],
            'PERC_NODE_CLOSE': cls.__constants['PERC_NODE_CLOSE'],
            'PERC_NODE_START': cls.__constants['PERC_NODE_START'],
            'PERC_NODE_RESET': cls.__constants['PERC_NODE_RESET'],
            'FOLLOW_ON': cls.__constants['FOLLOW_ON'],
            'FOLLOW_OFF': cls.__constants['FOLLOW_OFF'],
        }

    @property
    def PERC_DEST(self):
        """Message constant 'PERC_DEST'."""
        return Metaclass_PercCmd.__constants['PERC_DEST']

    @property
    def PERC_ABS(self):
        """Message constant 'PERC_ABS'."""
        return Metaclass_PercCmd.__constants['PERC_ABS']

    @property
    def PERC_REL(self):
        """Message constant 'PERC_REL'."""
        return Metaclass_PercCmd.__constants['PERC_REL']

    @property
    def PERC_AUTO_CHARGING(self):
        """Message constant 'PERC_AUTO_CHARGING'."""
        return Metaclass_PercCmd.__constants['PERC_AUTO_CHARGING']

    @property
    def PERC_CHECK_ENV(self):
        """Message constant 'PERC_CHECK_ENV'."""
        return Metaclass_PercCmd.__constants['PERC_CHECK_ENV']

    @property
    def PERC_AUTO_MAPPING(self):
        """Message constant 'PERC_AUTO_MAPPING'."""
        return Metaclass_PercCmd.__constants['PERC_AUTO_MAPPING']

    @property
    def PERC_FOLLOW(self):
        """Message constant 'PERC_FOLLOW'."""
        return Metaclass_PercCmd.__constants['PERC_FOLLOW']

    @property
    def PERC_STRANGER_WELCOME(self):
        """Message constant 'PERC_STRANGER_WELCOME'."""
        return Metaclass_PercCmd.__constants['PERC_STRANGER_WELCOME']

    @property
    def PERC_OWNER_WELCOME(self):
        """Message constant 'PERC_OWNER_WELCOME'."""
        return Metaclass_PercCmd.__constants['PERC_OWNER_WELCOME']

    @property
    def PERC_BEHAVIOR_INTERACTION(self):
        """Message constant 'PERC_BEHAVIOR_INTERACTION'."""
        return Metaclass_PercCmd.__constants['PERC_BEHAVIOR_INTERACTION']

    @property
    def PERC_HANDSHAKE(self):
        """Message constant 'PERC_HANDSHAKE'."""
        return Metaclass_PercCmd.__constants['PERC_HANDSHAKE']

    @property
    def PERC_STANDBY_ACCOMPANY(self):
        """Message constant 'PERC_STANDBY_ACCOMPANY'."""
        return Metaclass_PercCmd.__constants['PERC_STANDBY_ACCOMPANY']

    @property
    def PERC_HAPPY_ACCOMPANY(self):
        """Message constant 'PERC_HAPPY_ACCOMPANY'."""
        return Metaclass_PercCmd.__constants['PERC_HAPPY_ACCOMPANY']

    @property
    def PERC_WORK_ACCOMPANY(self):
        """Message constant 'PERC_WORK_ACCOMPANY'."""
        return Metaclass_PercCmd.__constants['PERC_WORK_ACCOMPANY']

    @property
    def PERC_POSITIVE_ACCOMPANY(self):
        """Message constant 'PERC_POSITIVE_ACCOMPANY'."""
        return Metaclass_PercCmd.__constants['PERC_POSITIVE_ACCOMPANY']

    @property
    def PERC_NEGATIVE_ACCOMPANY(self):
        """Message constant 'PERC_NEGATIVE_ACCOMPANY'."""
        return Metaclass_PercCmd.__constants['PERC_NEGATIVE_ACCOMPANY']

    @property
    def PERC_CHILD_WATCH(self):
        """Message constant 'PERC_CHILD_WATCH'."""
        return Metaclass_PercCmd.__constants['PERC_CHILD_WATCH']

    @property
    def PERC_OLDER_WATCH(self):
        """Message constant 'PERC_OLDER_WATCH'."""
        return Metaclass_PercCmd.__constants['PERC_OLDER_WATCH']

    @property
    def PERC_DANGER_REMINDER(self):
        """Message constant 'PERC_DANGER_REMINDER'."""
        return Metaclass_PercCmd.__constants['PERC_DANGER_REMINDER']

    @property
    def PERC_EVENT_REMINDER(self):
        """Message constant 'PERC_EVENT_REMINDER'."""
        return Metaclass_PercCmd.__constants['PERC_EVENT_REMINDER']

    @property
    def PERC_CATWALK_START(self):
        """Message constant 'PERC_CATWALK_START'."""
        return Metaclass_PercCmd.__constants['PERC_CATWALK_START']

    @property
    def PERC_CATWALK_ACT(self):
        """Message constant 'PERC_CATWALK_ACT'."""
        return Metaclass_PercCmd.__constants['PERC_CATWALK_ACT']

    @property
    def PERC_CATWALK_SHOW(self):
        """Message constant 'PERC_CATWALK_SHOW'."""
        return Metaclass_PercCmd.__constants['PERC_CATWALK_SHOW']

    @property
    def PERC_CATWALK_BACK(self):
        """Message constant 'PERC_CATWALK_BACK'."""
        return Metaclass_PercCmd.__constants['PERC_CATWALK_BACK']

    @property
    def PERC_FREE_TIME(self):
        """Message constant 'PERC_FREE_TIME'."""
        return Metaclass_PercCmd.__constants['PERC_FREE_TIME']

    @property
    def PERC_SOCIALIZE(self):
        """Message constant 'PERC_SOCIALIZE'."""
        return Metaclass_PercCmd.__constants['PERC_SOCIALIZE']

    @property
    def PERC_SPECT_PERFORM(self):
        """Message constant 'PERC_SPECT_PERFORM'."""
        return Metaclass_PercCmd.__constants['PERC_SPECT_PERFORM']

    @property
    def PERC_FACE_DETCTION(self):
        """Message constant 'PERC_FACE_DETCTION'."""
        return Metaclass_PercCmd.__constants['PERC_FACE_DETCTION']

    @property
    def PERC_DANGER_INFO(self):
        """Message constant 'PERC_DANGER_INFO'."""
        return Metaclass_PercCmd.__constants['PERC_DANGER_INFO']

    @property
    def PERC_WELCOME_DEMO(self):
        """Message constant 'PERC_WELCOME_DEMO'."""
        return Metaclass_PercCmd.__constants['PERC_WELCOME_DEMO']

    @property
    def PERC_LOBBY_DEMO(self):
        """Message constant 'PERC_LOBBY_DEMO'."""
        return Metaclass_PercCmd.__constants['PERC_LOBBY_DEMO']

    @property
    def PERC_CANCEL(self):
        """Message constant 'PERC_CANCEL'."""
        return Metaclass_PercCmd.__constants['PERC_CANCEL']

    @property
    def PERC_NODE_CLOSE(self):
        """Message constant 'PERC_NODE_CLOSE'."""
        return Metaclass_PercCmd.__constants['PERC_NODE_CLOSE']

    @property
    def PERC_NODE_START(self):
        """Message constant 'PERC_NODE_START'."""
        return Metaclass_PercCmd.__constants['PERC_NODE_START']

    @property
    def PERC_NODE_RESET(self):
        """Message constant 'PERC_NODE_RESET'."""
        return Metaclass_PercCmd.__constants['PERC_NODE_RESET']

    @property
    def FOLLOW_ON(self):
        """Message constant 'FOLLOW_ON'."""
        return Metaclass_PercCmd.__constants['FOLLOW_ON']

    @property
    def FOLLOW_OFF(self):
        """Message constant 'FOLLOW_OFF'."""
        return Metaclass_PercCmd.__constants['FOLLOW_OFF']


class PercCmd(metaclass=Metaclass_PercCmd):
    """
    Message class 'PercCmd'.

    Constants:
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
      PERC_SPECT_PERFORM
      PERC_FACE_DETCTION
      PERC_DANGER_INFO
      PERC_WELCOME_DEMO
      PERC_LOBBY_DEMO
      PERC_CANCEL
      PERC_NODE_CLOSE
      PERC_NODE_START
      PERC_NODE_RESET
      FOLLOW_ON
      FOLLOW_OFF
    """

    __slots__ = [
        '_header',
        '_action_id',
        '_perc_kind',
        '_req_id',
        '_on_off',
        '_follow_name',
        '_angle',
        '_point_name',
        '_point',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'action_id': 'uint64',
        'perc_kind': 'uint32',
        'req_id': 'uint64',
        'on_off': 'uint32',
        'follow_name': 'string',
        'angle': 'double',
        'point_name': 'string',
        'point': 'geometry_msgs/Point',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint32'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('double'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.NamespacedType(['geometry_msgs', 'msg'], 'Point'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.action_id = kwargs.get('action_id', int())
        self.perc_kind = kwargs.get('perc_kind', int())
        self.req_id = kwargs.get('req_id', int())
        self.on_off = kwargs.get('on_off', int())
        self.follow_name = kwargs.get('follow_name', str())
        self.angle = kwargs.get('angle', float())
        self.point_name = kwargs.get('point_name', str())
        from geometry_msgs.msg import Point
        self.point = kwargs.get('point', Point())

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
        if self.req_id != other.req_id:
            return False
        if self.on_off != other.on_off:
            return False
        if self.follow_name != other.follow_name:
            return False
        if self.angle != other.angle:
            return False
        if self.point_name != other.point_name:
            return False
        if self.point != other.point:
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
    def on_off(self):
        """Message field 'on_off'."""
        return self._on_off

    @on_off.setter
    def on_off(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'on_off' field must be of type 'int'"
            assert value >= 0 and value < 4294967296, \
                "The 'on_off' field must be an unsigned integer in [0, 4294967295]"
        self._on_off = value

    @property
    def follow_name(self):
        """Message field 'follow_name'."""
        return self._follow_name

    @follow_name.setter
    def follow_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'follow_name' field must be of type 'str'"
        self._follow_name = value

    @property
    def angle(self):
        """Message field 'angle'."""
        return self._angle

    @angle.setter
    def angle(self, value):
        if __debug__:
            assert \
                isinstance(value, float), \
                "The 'angle' field must be of type 'float'"
        self._angle = value

    @property
    def point_name(self):
        """Message field 'point_name'."""
        return self._point_name

    @point_name.setter
    def point_name(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'point_name' field must be of type 'str'"
        self._point_name = value

    @property
    def point(self):
        """Message field 'point'."""
        return self._point

    @point.setter
    def point(self, value):
        if __debug__:
            from geometry_msgs.msg import Point
            assert \
                isinstance(value, Point), \
                "The 'point' field must be a sub message of type 'Point'"
        self._point = value
