# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ros_interface/SLBoundary.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import ros_interface.msg

class SLBoundary(genpy.Message):
  _md5sum = "f10f98a43d7c56cfaed470a969316c95"
  _type = "ros_interface/SLBoundary"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """float64   start_s     # 起始点纵向位移
float64   end_s     # 终止点纵向位移
float64   start_l     # 起始点横向位移
float64   end_l     # 终止点横向位移
SLPoint[] boundary_point # sl点集

================================================================================
MSG: ros_interface/SLPoint
float64   s     # 纵向位移
float64   l     # 横向位移
"""
  __slots__ = ['start_s','end_s','start_l','end_l','boundary_point']
  _slot_types = ['float64','float64','float64','float64','ros_interface/SLPoint[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       start_s,end_s,start_l,end_l,boundary_point

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(SLBoundary, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.start_s is None:
        self.start_s = 0.
      if self.end_s is None:
        self.end_s = 0.
      if self.start_l is None:
        self.start_l = 0.
      if self.end_l is None:
        self.end_l = 0.
      if self.boundary_point is None:
        self.boundary_point = []
    else:
      self.start_s = 0.
      self.end_s = 0.
      self.start_l = 0.
      self.end_l = 0.
      self.boundary_point = []

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
      buff.write(_get_struct_4d().pack(_x.start_s, _x.end_s, _x.start_l, _x.end_l))
      length = len(self.boundary_point)
      buff.write(_struct_I.pack(length))
      for val1 in self.boundary_point:
        _x = val1
        buff.write(_get_struct_2d().pack(_x.s, _x.l))
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
      if self.boundary_point is None:
        self.boundary_point = None
      end = 0
      _x = self
      start = end
      end += 32
      (_x.start_s, _x.end_s, _x.start_l, _x.end_l,) = _get_struct_4d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.boundary_point = []
      for i in range(0, length):
        val1 = ros_interface.msg.SLPoint()
        _x = val1
        start = end
        end += 16
        (_x.s, _x.l,) = _get_struct_2d().unpack(str[start:end])
        self.boundary_point.append(val1)
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
      buff.write(_get_struct_4d().pack(_x.start_s, _x.end_s, _x.start_l, _x.end_l))
      length = len(self.boundary_point)
      buff.write(_struct_I.pack(length))
      for val1 in self.boundary_point:
        _x = val1
        buff.write(_get_struct_2d().pack(_x.s, _x.l))
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
      if self.boundary_point is None:
        self.boundary_point = None
      end = 0
      _x = self
      start = end
      end += 32
      (_x.start_s, _x.end_s, _x.start_l, _x.end_l,) = _get_struct_4d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.boundary_point = []
      for i in range(0, length):
        val1 = ros_interface.msg.SLPoint()
        _x = val1
        start = end
        end += 16
        (_x.s, _x.l,) = _get_struct_2d().unpack(str[start:end])
        self.boundary_point.append(val1)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_2d = None
def _get_struct_2d():
    global _struct_2d
    if _struct_2d is None:
        _struct_2d = struct.Struct("<2d")
    return _struct_2d
_struct_4d = None
def _get_struct_4d():
    global _struct_4d
    if _struct_4d is None:
        _struct_4d = struct.Struct("<4d")
    return _struct_4d
