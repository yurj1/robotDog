# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ros_interface/TrajectoryPoint.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import ros_interface.msg

class TrajectoryPoint(genpy.Message):
  _md5sum = "cf4c0f33e36ba1646317dfc847d34f16"
  _type = "ros_interface/TrajectoryPoint"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """PathPoint   path_point     # path point
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
  __slots__ = ['path_point','v','a','relative_time','da','is_steer_valid','front_steer','rear_steer','gear']
  _slot_types = ['ros_interface/PathPoint','float64','float64','float64','float64','bool','float64','float64','int32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       path_point,v,a,relative_time,da,is_steer_valid,front_steer,rear_steer,gear

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(TrajectoryPoint, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.path_point is None:
        self.path_point = ros_interface.msg.PathPoint()
      if self.v is None:
        self.v = 0.
      if self.a is None:
        self.a = 0.
      if self.relative_time is None:
        self.relative_time = 0.
      if self.da is None:
        self.da = 0.
      if self.is_steer_valid is None:
        self.is_steer_valid = False
      if self.front_steer is None:
        self.front_steer = 0.
      if self.rear_steer is None:
        self.rear_steer = 0.
      if self.gear is None:
        self.gear = 0
    else:
      self.path_point = ros_interface.msg.PathPoint()
      self.v = 0.
      self.a = 0.
      self.relative_time = 0.
      self.da = 0.
      self.is_steer_valid = False
      self.front_steer = 0.
      self.rear_steer = 0.
      self.gear = 0

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
      _x = self
      buff.write(_get_struct_15dB2di().pack(_x.path_point.x, _x.path_point.y, _x.path_point.z, _x.path_point.theta, _x.path_point.kappa, _x.path_point.s, _x.path_point.dkappa, _x.path_point.ddkappa, _x.path_point.lane_id, _x.path_point.x_derivative, _x.path_point.y_derivative, _x.v, _x.a, _x.relative_time, _x.da, _x.is_steer_valid, _x.front_steer, _x.rear_steer, _x.gear))
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
      if self.path_point is None:
        self.path_point = ros_interface.msg.PathPoint()
      end = 0
      _x = self
      start = end
      end += 141
      (_x.path_point.x, _x.path_point.y, _x.path_point.z, _x.path_point.theta, _x.path_point.kappa, _x.path_point.s, _x.path_point.dkappa, _x.path_point.ddkappa, _x.path_point.lane_id, _x.path_point.x_derivative, _x.path_point.y_derivative, _x.v, _x.a, _x.relative_time, _x.da, _x.is_steer_valid, _x.front_steer, _x.rear_steer, _x.gear,) = _get_struct_15dB2di().unpack(str[start:end])
      self.is_steer_valid = bool(self.is_steer_valid)
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
      _x = self
      buff.write(_get_struct_15dB2di().pack(_x.path_point.x, _x.path_point.y, _x.path_point.z, _x.path_point.theta, _x.path_point.kappa, _x.path_point.s, _x.path_point.dkappa, _x.path_point.ddkappa, _x.path_point.lane_id, _x.path_point.x_derivative, _x.path_point.y_derivative, _x.v, _x.a, _x.relative_time, _x.da, _x.is_steer_valid, _x.front_steer, _x.rear_steer, _x.gear))
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
      if self.path_point is None:
        self.path_point = ros_interface.msg.PathPoint()
      end = 0
      _x = self
      start = end
      end += 141
      (_x.path_point.x, _x.path_point.y, _x.path_point.z, _x.path_point.theta, _x.path_point.kappa, _x.path_point.s, _x.path_point.dkappa, _x.path_point.ddkappa, _x.path_point.lane_id, _x.path_point.x_derivative, _x.path_point.y_derivative, _x.v, _x.a, _x.relative_time, _x.da, _x.is_steer_valid, _x.front_steer, _x.rear_steer, _x.gear,) = _get_struct_15dB2di().unpack(str[start:end])
      self.is_steer_valid = bool(self.is_steer_valid)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_15dB2di = None
def _get_struct_15dB2di():
    global _struct_15dB2di
    if _struct_15dB2di is None:
        _struct_15dB2di = struct.Struct("<15dB2di")
    return _struct_15dB2di
