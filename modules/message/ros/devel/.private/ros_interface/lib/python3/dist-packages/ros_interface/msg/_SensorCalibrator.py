# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ros_interface/SensorCalibrator.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import ros_interface.msg

class SensorCalibrator(genpy.Message):
  _md5sum = "8973a94a8ceb6b4c6fa358ef1bfb5314"
  _type = "ros_interface/SensorCalibrator"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """Point3D   pose     # 传感器安装位置(相对于后轴中心点)
Point3D   angle     # 传感器安装角度(车体坐标系)

================================================================================
MSG: ros_interface/Point3D
float64   x     # 位置坐标x
float64   y     # 位置坐标y
float64   z     # 位置坐标z
"""
  __slots__ = ['pose','angle']
  _slot_types = ['ros_interface/Point3D','ros_interface/Point3D']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       pose,angle

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(SensorCalibrator, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.pose is None:
        self.pose = ros_interface.msg.Point3D()
      if self.angle is None:
        self.angle = ros_interface.msg.Point3D()
    else:
      self.pose = ros_interface.msg.Point3D()
      self.angle = ros_interface.msg.Point3D()

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
      buff.write(_get_struct_6d().pack(_x.pose.x, _x.pose.y, _x.pose.z, _x.angle.x, _x.angle.y, _x.angle.z))
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
      if self.pose is None:
        self.pose = ros_interface.msg.Point3D()
      if self.angle is None:
        self.angle = ros_interface.msg.Point3D()
      end = 0
      _x = self
      start = end
      end += 48
      (_x.pose.x, _x.pose.y, _x.pose.z, _x.angle.x, _x.angle.y, _x.angle.z,) = _get_struct_6d().unpack(str[start:end])
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
      buff.write(_get_struct_6d().pack(_x.pose.x, _x.pose.y, _x.pose.z, _x.angle.x, _x.angle.y, _x.angle.z))
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
      if self.pose is None:
        self.pose = ros_interface.msg.Point3D()
      if self.angle is None:
        self.angle = ros_interface.msg.Point3D()
      end = 0
      _x = self
      start = end
      end += 48
      (_x.pose.x, _x.pose.y, _x.pose.z, _x.angle.x, _x.angle.y, _x.angle.z,) = _get_struct_6d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_6d = None
def _get_struct_6d():
    global _struct_6d
    if _struct_6d is None:
        _struct_6d = struct.Struct("<6d")
    return _struct_6d
