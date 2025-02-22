# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ros_interface/TrajectoryInPrediction.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import ros_interface.msg

class TrajectoryInPrediction(genpy.Message):
  _md5sum = "320d82f2697ffe59ea83bdf0ca52632f"
  _type = "ros_interface/TrajectoryInPrediction"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """float64   probability     # probability of this trajectory
TrajectoryPoint[] trajectory_points #  

================================================================================
MSG: ros_interface/TrajectoryPoint
PathPoint   path_point     # path point
float64   v     # linear velocity
float64   a     # linear acceleration
float64   relative_time     # relative time from beginning of the trajectory
float64   da     # longitudinal jerk
bool   is_steer_valid     # 转向是否有效
float64   front_steer     # The angle between vehicle front wheel and vehicle longitudinal axis
float64   rear_steer     # 后轮转角
int32   gear     # 档位

================================================================================
MSG: ros_interface/PathPoint
float64   x     # coordinates x
float64   y     # coordinates y
float64   z     # coordinates z
float64   theta     # direction on the x-y plane
float64   kappa     # curvature on the x-y planning
float64   s     # accumulated distance from beginning of the path
float64   dkappa     # derivative of kappa w.r.t s.
float64   ddkappa     # derivative of derivative of kappa w.r.t s.
float64   lane_id     # The lane ID where the path point is on
float64   x_derivative     # derivative of x w.r.t parametric parameter t in CosThetareferenceline
float64   y_derivative     # derivative of y w.r.t parametric parameter t in CosThetareferenceline
"""
  __slots__ = ['probability','trajectory_points']
  _slot_types = ['float64','ros_interface/TrajectoryPoint[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       probability,trajectory_points

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(TrajectoryInPrediction, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.probability is None:
        self.probability = 0.
      if self.trajectory_points is None:
        self.trajectory_points = []
    else:
      self.probability = 0.
      self.trajectory_points = []

  def _get_types(self):
    """
    internal API method
    """
    return self._slot_types

  def serialize(self, buff):
    """
    serialize message into buffer
    :param buff: buffer, ``StringIO``
    """
    try:
      _x = self.probability
      buff.write(_get_struct_d().pack(_x))
      length = len(self.trajectory_points)
      buff.write(_struct_I.pack(length))
      for val1 in self.trajectory_points:
        _v1 = val1.path_point
        _x = _v1
        buff.write(_get_struct_11d().pack(_x.x, _x.y, _x.z, _x.theta, _x.kappa, _x.s, _x.dkappa, _x.ddkappa, _x.lane_id, _x.x_derivative, _x.y_derivative))
        _x = val1
        buff.write(_get_struct_4dB2di().pack(_x.v, _x.a, _x.relative_time, _x.da, _x.is_steer_valid, _x.front_steer, _x.rear_steer, _x.gear))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize(self, str):
    """
    unpack serialized message in str into this message instance
    :param str: byte array of serialized message, ``str``
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.trajectory_points is None:
        self.trajectory_points = None
      end = 0
      start = end
      end += 8
      (self.probability,) = _get_struct_d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.trajectory_points = []
      for i in range(0, length):
        val1 = ros_interface.msg.TrajectoryPoint()
        _v2 = val1.path_point
        _x = _v2
        start = end
        end += 88
        (_x.x, _x.y, _x.z, _x.theta, _x.kappa, _x.s, _x.dkappa, _x.ddkappa, _x.lane_id, _x.x_derivative, _x.y_derivative,) = _get_struct_11d().unpack(str[start:end])
        _x = val1
        start = end
        end += 53
        (_x.v, _x.a, _x.relative_time, _x.da, _x.is_steer_valid, _x.front_steer, _x.rear_steer, _x.gear,) = _get_struct_4dB2di().unpack(str[start:end])
        val1.is_steer_valid = bool(val1.is_steer_valid)
        self.trajectory_points.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill


  def serialize_numpy(self, buff, numpy):
    """
    serialize message with numpy array types into buffer
    :param buff: buffer, ``StringIO``
    :param numpy: numpy python module
    """
    try:
      _x = self.probability
      buff.write(_get_struct_d().pack(_x))
      length = len(self.trajectory_points)
      buff.write(_struct_I.pack(length))
      for val1 in self.trajectory_points:
        _v3 = val1.path_point
        _x = _v3
        buff.write(_get_struct_11d().pack(_x.x, _x.y, _x.z, _x.theta, _x.kappa, _x.s, _x.dkappa, _x.ddkappa, _x.lane_id, _x.x_derivative, _x.y_derivative))
        _x = val1
        buff.write(_get_struct_4dB2di().pack(_x.v, _x.a, _x.relative_time, _x.da, _x.is_steer_valid, _x.front_steer, _x.rear_steer, _x.gear))
    except struct.error as se: self._check_types(struct.error("%s: '%s' when writing '%s'" % (type(se), str(se), str(locals().get('_x', self)))))
    except TypeError as te: self._check_types(ValueError("%s: '%s' when writing '%s'" % (type(te), str(te), str(locals().get('_x', self)))))

  def deserialize_numpy(self, str, numpy):
    """
    unpack serialized message in str into this message instance using numpy for array types
    :param str: byte array of serialized message, ``str``
    :param numpy: numpy python module
    """
    if python3:
      codecs.lookup_error("rosmsg").msg_type = self._type
    try:
      if self.trajectory_points is None:
        self.trajectory_points = None
      end = 0
      start = end
      end += 8
      (self.probability,) = _get_struct_d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.trajectory_points = []
      for i in range(0, length):
        val1 = ros_interface.msg.TrajectoryPoint()
        _v4 = val1.path_point
        _x = _v4
        start = end
        end += 88
        (_x.x, _x.y, _x.z, _x.theta, _x.kappa, _x.s, _x.dkappa, _x.ddkappa, _x.lane_id, _x.x_derivative, _x.y_derivative,) = _get_struct_11d().unpack(str[start:end])
        _x = val1
        start = end
        end += 53
        (_x.v, _x.a, _x.relative_time, _x.da, _x.is_steer_valid, _x.front_steer, _x.rear_steer, _x.gear,) = _get_struct_4dB2di().unpack(str[start:end])
        val1.is_steer_valid = bool(val1.is_steer_valid)
        self.trajectory_points.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_11d = None
def _get_struct_11d():
    global _struct_11d
    if _struct_11d is None:
        _struct_11d = struct.Struct("<11d")
    return _struct_11d
_struct_4dB2di = None
def _get_struct_4dB2di():
    global _struct_4dB2di
    if _struct_4dB2di is None:
        _struct_4dB2di = struct.Struct("<4dB2di")
    return _struct_4dB2di
_struct_d = None
def _get_struct_d():
    global _struct_d
    if _struct_d is None:
        _struct_d = struct.Struct("<d")
    return _struct_d
