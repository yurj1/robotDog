# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ros_interface/VehicleSignal.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class VehicleSignal(genpy.Message):
  _md5sum = "47860a6c8e7e3e428751d2354cd4426d"
  _type = "ros_interface/VehicleSignal"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """int32   turn_signal     # 转向信号
bool   high_beam     # high beam
bool   low_beam     # low beam
bool   horn     # horn
bool   emergency_light     # emergency light
"""
  __slots__ = ['turn_signal','high_beam','low_beam','horn','emergency_light']
  _slot_types = ['int32','bool','bool','bool','bool']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       turn_signal,high_beam,low_beam,horn,emergency_light

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(VehicleSignal, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.turn_signal is None:
        self.turn_signal = 0
      if self.high_beam is None:
        self.high_beam = False
      if self.low_beam is None:
        self.low_beam = False
      if self.horn is None:
        self.horn = False
      if self.emergency_light is None:
        self.emergency_light = False
    else:
      self.turn_signal = 0
      self.high_beam = False
      self.low_beam = False
      self.horn = False
      self.emergency_light = False

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
      buff.write(_get_struct_i4B().pack(_x.turn_signal, _x.high_beam, _x.low_beam, _x.horn, _x.emergency_light))
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
      end += 8
      (_x.turn_signal, _x.high_beam, _x.low_beam, _x.horn, _x.emergency_light,) = _get_struct_i4B().unpack(str[start:end])
      self.high_beam = bool(self.high_beam)
      self.low_beam = bool(self.low_beam)
      self.horn = bool(self.horn)
      self.emergency_light = bool(self.emergency_light)
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
      buff.write(_get_struct_i4B().pack(_x.turn_signal, _x.high_beam, _x.low_beam, _x.horn, _x.emergency_light))
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
      end += 8
      (_x.turn_signal, _x.high_beam, _x.low_beam, _x.horn, _x.emergency_light,) = _get_struct_i4B().unpack(str[start:end])
      self.high_beam = bool(self.high_beam)
      self.low_beam = bool(self.low_beam)
      self.horn = bool(self.horn)
      self.emergency_light = bool(self.emergency_light)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_i4B = None
def _get_struct_i4B():
    global _struct_i4B
    if _struct_i4B is None:
        _struct_i4B = struct.Struct("<i4B")
    return _struct_i4B
