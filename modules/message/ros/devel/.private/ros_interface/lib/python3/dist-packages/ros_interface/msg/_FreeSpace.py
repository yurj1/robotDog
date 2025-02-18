# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ros_interface/FreeSpace.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import ros_interface.msg
import std_msgs.msg

class FreeSpace(genpy.Message):
  _md5sum = "86e4a72c19135f501d4833fae261dd9b"
  _type = "ros_interface/FreeSpace"
  _has_header = True  # flag to mark the presence of a Header object
  _full_text = """Header   header     # timestamp is included in header
int32   sensor_id     # 安装的传感器id(camera,lidar,radar) ' 相机id: 0-front_center相机 1-front_left相机 2-front_right相机 3-left_front相机 4-left_back右后相机 5-right_front相机 6-right_back相机 7-back相机'  8-相机融合
Polygon2D[] freespace_region # freespace轮廓图像坐标
int32   error_code     # 错误码（default = OK）
bool   is_valid     # 障碍物数据是否合法

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: ros_interface/Polygon2D
int32   coordinate_system     # 坐标系
Point2D[] points # 二维点集

================================================================================
MSG: ros_interface/Point2D
float64   x     # 位置坐标x
float64   y     # 位置坐标y
"""
  __slots__ = ['header','sensor_id','freespace_region','error_code','is_valid']
  _slot_types = ['std_msgs/Header','int32','ros_interface/Polygon2D[]','int32','bool']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       header,sensor_id,freespace_region,error_code,is_valid

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(FreeSpace, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.sensor_id is None:
        self.sensor_id = 0
      if self.freespace_region is None:
        self.freespace_region = []
      if self.error_code is None:
        self.error_code = 0
      if self.is_valid is None:
        self.is_valid = False
    else:
      self.header = std_msgs.msg.Header()
      self.sensor_id = 0
      self.freespace_region = []
      self.error_code = 0
      self.is_valid = False

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
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self.sensor_id
      buff.write(_get_struct_i().pack(_x))
      length = len(self.freespace_region)
      buff.write(_struct_I.pack(length))
      for val1 in self.freespace_region:
        _x = val1.coordinate_system
        buff.write(_get_struct_i().pack(_x))
        length = len(val1.points)
        buff.write(_struct_I.pack(length))
        for val2 in val1.points:
          _x = val2
          buff.write(_get_struct_2d().pack(_x.x, _x.y))
      _x = self
      buff.write(_get_struct_iB().pack(_x.error_code, _x.is_valid))
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
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.freespace_region is None:
        self.freespace_region = None
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.header.frame_id = str[start:end]
      start = end
      end += 4
      (self.sensor_id,) = _get_struct_i().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.freespace_region = []
      for i in range(0, length):
        val1 = ros_interface.msg.Polygon2D()
        start = end
        end += 4
        (val1.coordinate_system,) = _get_struct_i().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        val1.points = []
        for i in range(0, length):
          val2 = ros_interface.msg.Point2D()
          _x = val2
          start = end
          end += 16
          (_x.x, _x.y,) = _get_struct_2d().unpack(str[start:end])
          val1.points.append(val2)
        self.freespace_region.append(val1)
      _x = self
      start = end
      end += 5
      (_x.error_code, _x.is_valid,) = _get_struct_iB().unpack(str[start:end])
      self.is_valid = bool(self.is_valid)
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
      buff.write(_get_struct_3I().pack(_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs))
      _x = self.header.frame_id
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self.sensor_id
      buff.write(_get_struct_i().pack(_x))
      length = len(self.freespace_region)
      buff.write(_struct_I.pack(length))
      for val1 in self.freespace_region:
        _x = val1.coordinate_system
        buff.write(_get_struct_i().pack(_x))
        length = len(val1.points)
        buff.write(_struct_I.pack(length))
        for val2 in val1.points:
          _x = val2
          buff.write(_get_struct_2d().pack(_x.x, _x.y))
      _x = self
      buff.write(_get_struct_iB().pack(_x.error_code, _x.is_valid))
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
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.freespace_region is None:
        self.freespace_region = None
      end = 0
      _x = self
      start = end
      end += 12
      (_x.header.seq, _x.header.stamp.secs, _x.header.stamp.nsecs,) = _get_struct_3I().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.header.frame_id = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.header.frame_id = str[start:end]
      start = end
      end += 4
      (self.sensor_id,) = _get_struct_i().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.freespace_region = []
      for i in range(0, length):
        val1 = ros_interface.msg.Polygon2D()
        start = end
        end += 4
        (val1.coordinate_system,) = _get_struct_i().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        val1.points = []
        for i in range(0, length):
          val2 = ros_interface.msg.Point2D()
          _x = val2
          start = end
          end += 16
          (_x.x, _x.y,) = _get_struct_2d().unpack(str[start:end])
          val1.points.append(val2)
        self.freespace_region.append(val1)
      _x = self
      start = end
      end += 5
      (_x.error_code, _x.is_valid,) = _get_struct_iB().unpack(str[start:end])
      self.is_valid = bool(self.is_valid)
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
_struct_3I = None
def _get_struct_3I():
    global _struct_3I
    if _struct_3I is None:
        _struct_3I = struct.Struct("<3I")
    return _struct_3I
_struct_i = None
def _get_struct_i():
    global _struct_i
    if _struct_i is None:
        _struct_i = struct.Struct("<i")
    return _struct_i
_struct_iB = None
def _get_struct_iB():
    global _struct_iB
    if _struct_iB is None:
        _struct_iB = struct.Struct("<iB")
    return _struct_iB
