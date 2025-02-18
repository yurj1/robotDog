# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ros_interface/LanePoint.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import ros_interface.msg

class LanePoint(genpy.Message):
  _md5sum = "b86492a98e6209595aa1050feb0e5d3b"
  _type = "ros_interface/LanePoint"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """Point3D   point     # 点xyz
float64   theta     # 方向（与东方向夹角，逆时针方向为正，单位为弧度）
float64   mileage     # 总体里程
float64   limit_speed     # 地图限速（单位m/s）
float64   left_road_width     # 左边车道宽
float64   right_road_width     # 右边车道宽
int32   left_line_type     # 左边车线线型
int32   right_line_type     # 右边车线线型

================================================================================
MSG: ros_interface/Point3D
float64   x     # 位置坐标x
float64   y     # 位置坐标y
float64   z     # 位置坐标z
"""
  __slots__ = ['point','theta','mileage','limit_speed','left_road_width','right_road_width','left_line_type','right_line_type']
  _slot_types = ['ros_interface/Point3D','float64','float64','float64','float64','float64','int32','int32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       point,theta,mileage,limit_speed,left_road_width,right_road_width,left_line_type,right_line_type

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(LanePoint, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.point is None:
        self.point = ros_interface.msg.Point3D()
      if self.theta is None:
        self.theta = 0.
      if self.mileage is None:
        self.mileage = 0.
      if self.limit_speed is None:
        self.limit_speed = 0.
      if self.left_road_width is None:
        self.left_road_width = 0.
      if self.right_road_width is None:
        self.right_road_width = 0.
      if self.left_line_type is None:
        self.left_line_type = 0
      if self.right_line_type is None:
        self.right_line_type = 0
    else:
      self.point = ros_interface.msg.Point3D()
      self.theta = 0.
      self.mileage = 0.
      self.limit_speed = 0.
      self.left_road_width = 0.
      self.right_road_width = 0.
      self.left_line_type = 0
      self.right_line_type = 0

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
      buff.write(_get_struct_8d2i().pack(_x.point.x, _x.point.y, _x.point.z, _x.theta, _x.mileage, _x.limit_speed, _x.left_road_width, _x.right_road_width, _x.left_line_type, _x.right_line_type))
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
      if self.point is None:
        self.point = ros_interface.msg.Point3D()
      end = 0
      _x = self
      start = end
      end += 72
      (_x.point.x, _x.point.y, _x.point.z, _x.theta, _x.mileage, _x.limit_speed, _x.left_road_width, _x.right_road_width, _x.left_line_type, _x.right_line_type,) = _get_struct_8d2i().unpack(str[start:end])
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
      buff.write(_get_struct_8d2i().pack(_x.point.x, _x.point.y, _x.point.z, _x.theta, _x.mileage, _x.limit_speed, _x.left_road_width, _x.right_road_width, _x.left_line_type, _x.right_line_type))
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
      if self.point is None:
        self.point = ros_interface.msg.Point3D()
      end = 0
      _x = self
      start = end
      end += 72
      (_x.point.x, _x.point.y, _x.point.z, _x.theta, _x.mileage, _x.limit_speed, _x.left_road_width, _x.right_road_width, _x.left_line_type, _x.right_line_type,) = _get_struct_8d2i().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_8d2i = None
def _get_struct_8d2i():
    global _struct_8d2i
    if _struct_8d2i is None:
        _struct_8d2i = struct.Struct("<8d2i")
    return _struct_8d2i
