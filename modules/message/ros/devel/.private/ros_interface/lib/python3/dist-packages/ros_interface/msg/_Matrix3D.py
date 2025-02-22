# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ros_interface/Matrix3D.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class Matrix3D(genpy.Message):
  _md5sum = "df2f48490b2be1b3dcfbc7fadaa3db94"
  _type = "ros_interface/Matrix3D"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """float64   a00     # 第一行第一列元素
float64   a01     # 第一行第二列元素
float64   a02     # 第一行第三列元素
float64   a10     # 第二行第一列元素
float64   a11     # 第二行第二列元素
float64   a12     # 第二行第三列元素
float64   a20     # 第三行第一列元素
float64   a21     # 第三行第二列元素
float64   a22     # 第三行第三列元素
"""
  __slots__ = ['a00','a01','a02','a10','a11','a12','a20','a21','a22']
  _slot_types = ['float64','float64','float64','float64','float64','float64','float64','float64','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       a00,a01,a02,a10,a11,a12,a20,a21,a22

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(Matrix3D, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.a00 is None:
        self.a00 = 0.
      if self.a01 is None:
        self.a01 = 0.
      if self.a02 is None:
        self.a02 = 0.
      if self.a10 is None:
        self.a10 = 0.
      if self.a11 is None:
        self.a11 = 0.
      if self.a12 is None:
        self.a12 = 0.
      if self.a20 is None:
        self.a20 = 0.
      if self.a21 is None:
        self.a21 = 0.
      if self.a22 is None:
        self.a22 = 0.
    else:
      self.a00 = 0.
      self.a01 = 0.
      self.a02 = 0.
      self.a10 = 0.
      self.a11 = 0.
      self.a12 = 0.
      self.a20 = 0.
      self.a21 = 0.
      self.a22 = 0.

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
      buff.write(_get_struct_9d().pack(_x.a00, _x.a01, _x.a02, _x.a10, _x.a11, _x.a12, _x.a20, _x.a21, _x.a22))
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
      end = 0
      _x = self
      start = end
      end += 72
      (_x.a00, _x.a01, _x.a02, _x.a10, _x.a11, _x.a12, _x.a20, _x.a21, _x.a22,) = _get_struct_9d().unpack(str[start:end])
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
      buff.write(_get_struct_9d().pack(_x.a00, _x.a01, _x.a02, _x.a10, _x.a11, _x.a12, _x.a20, _x.a21, _x.a22))
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
      end = 0
      _x = self
      start = end
      end += 72
      (_x.a00, _x.a01, _x.a02, _x.a10, _x.a11, _x.a12, _x.a20, _x.a21, _x.a22,) = _get_struct_9d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_9d = None
def _get_struct_9d():
    global _struct_9d
    if _struct_9d is None:
        _struct_9d = struct.Struct("<9d")
    return _struct_9d
