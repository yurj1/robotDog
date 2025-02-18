# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ros_interface/HMIParkingInfoList.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import ros_interface.msg
import std_msgs.msg

class HMIParkingInfoList(genpy.Message):
  _md5sum = "7cbae677879688d63792c9944bad37ba"
  _type = "ros_interface/HMIParkingInfoList"
  _has_header = True  # flag to mark the presence of a Header object
  _full_text = """Header   header     # timestamp is  included in header
HMIParkingInfo[] parking_info #  
bool   parking_out_enable     #  
int32   parking_out_direction     #  
int32   parking_out_id     #  

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
MSG: ros_interface/HMIParkingInfo
Header   header     # timestamp is  included in header
int32   parking_space_id     # // 停车位id
int32   parking_type     # // PARKING_TYPE=0 //无效泊车 PARKING_TYPE=1 //水平泊车 PARKING_TYPE=2 //垂直泊车 PARKING_TYPE=3 //倾斜泊车
int32   parking_status     # PARKING_ENABLE=0//可泊 PARKING_DISENABLE=1//不可泊 PARKING_NONOPTIONAL=2//不可选
Point3D   center_point_of_parking     # // 世界坐标系下停车位中心点
float64   theta     # // 世界坐标系下的夹角（单位rad），车位出口与正东方向夹角
float64   width     # // 停车位宽（单位m）
float64   length     # // 停车位长单位m）
bool   is_custom_parking     # // 是否是自定义车位
Polygon3D   polygon     # 世界坐标系下的车位多边形
int32   parking_source_type     # 0-线车位， 1-空间车位， 2-融合车位

================================================================================
MSG: ros_interface/Point3D
float64   x     # 位置坐标x
float64   y     # 位置坐标y
float64   z     # 位置坐标z

================================================================================
MSG: ros_interface/Polygon3D
int32   coordinate_system     # 坐标系
Point3D[] points # 三维点集
"""
  __slots__ = ['header','parking_info','parking_out_enable','parking_out_direction','parking_out_id']
  _slot_types = ['std_msgs/Header','ros_interface/HMIParkingInfo[]','bool','int32','int32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       header,parking_info,parking_out_enable,parking_out_direction,parking_out_id

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(HMIParkingInfoList, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.parking_info is None:
        self.parking_info = []
      if self.parking_out_enable is None:
        self.parking_out_enable = False
      if self.parking_out_direction is None:
        self.parking_out_direction = 0
      if self.parking_out_id is None:
        self.parking_out_id = 0
    else:
      self.header = std_msgs.msg.Header()
      self.parking_info = []
      self.parking_out_enable = False
      self.parking_out_direction = 0
      self.parking_out_id = 0

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
      length = len(self.parking_info)
      buff.write(_struct_I.pack(length))
      for val1 in self.parking_info:
        _v1 = val1.header
        _x = _v1.seq
        buff.write(_get_struct_I().pack(_x))
        _v2 = _v1.stamp
        _x = _v2
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = _v1.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
        _x = val1
        buff.write(_get_struct_3i().pack(_x.parking_space_id, _x.parking_type, _x.parking_status))
        _v3 = val1.center_point_of_parking
        _x = _v3
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        _x = val1
        buff.write(_get_struct_3dB().pack(_x.theta, _x.width, _x.length, _x.is_custom_parking))
        _v4 = val1.polygon
        _x = _v4.coordinate_system
        buff.write(_get_struct_i().pack(_x))
        length = len(_v4.points)
        buff.write(_struct_I.pack(length))
        for val3 in _v4.points:
          _x = val3
          buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        _x = val1.parking_source_type
        buff.write(_get_struct_i().pack(_x))
      _x = self
      buff.write(_get_struct_B2i().pack(_x.parking_out_enable, _x.parking_out_direction, _x.parking_out_id))
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
      if self.parking_info is None:
        self.parking_info = None
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
      (length,) = _struct_I.unpack(str[start:end])
      self.parking_info = []
      for i in range(0, length):
        val1 = ros_interface.msg.HMIParkingInfo()
        _v5 = val1.header
        start = end
        end += 4
        (_v5.seq,) = _get_struct_I().unpack(str[start:end])
        _v6 = _v5.stamp
        _x = _v6
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v5.frame_id = str[start:end].decode('utf-8', 'rosmsg')
        else:
          _v5.frame_id = str[start:end]
        _x = val1
        start = end
        end += 12
        (_x.parking_space_id, _x.parking_type, _x.parking_status,) = _get_struct_3i().unpack(str[start:end])
        _v7 = val1.center_point_of_parking
        _x = _v7
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        _x = val1
        start = end
        end += 25
        (_x.theta, _x.width, _x.length, _x.is_custom_parking,) = _get_struct_3dB().unpack(str[start:end])
        val1.is_custom_parking = bool(val1.is_custom_parking)
        _v8 = val1.polygon
        start = end
        end += 4
        (_v8.coordinate_system,) = _get_struct_i().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        _v8.points = []
        for i in range(0, length):
          val3 = ros_interface.msg.Point3D()
          _x = val3
          start = end
          end += 24
          (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
          _v8.points.append(val3)
        start = end
        end += 4
        (val1.parking_source_type,) = _get_struct_i().unpack(str[start:end])
        self.parking_info.append(val1)
      _x = self
      start = end
      end += 9
      (_x.parking_out_enable, _x.parking_out_direction, _x.parking_out_id,) = _get_struct_B2i().unpack(str[start:end])
      self.parking_out_enable = bool(self.parking_out_enable)
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
      length = len(self.parking_info)
      buff.write(_struct_I.pack(length))
      for val1 in self.parking_info:
        _v9 = val1.header
        _x = _v9.seq
        buff.write(_get_struct_I().pack(_x))
        _v10 = _v9.stamp
        _x = _v10
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = _v9.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
        _x = val1
        buff.write(_get_struct_3i().pack(_x.parking_space_id, _x.parking_type, _x.parking_status))
        _v11 = val1.center_point_of_parking
        _x = _v11
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        _x = val1
        buff.write(_get_struct_3dB().pack(_x.theta, _x.width, _x.length, _x.is_custom_parking))
        _v12 = val1.polygon
        _x = _v12.coordinate_system
        buff.write(_get_struct_i().pack(_x))
        length = len(_v12.points)
        buff.write(_struct_I.pack(length))
        for val3 in _v12.points:
          _x = val3
          buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        _x = val1.parking_source_type
        buff.write(_get_struct_i().pack(_x))
      _x = self
      buff.write(_get_struct_B2i().pack(_x.parking_out_enable, _x.parking_out_direction, _x.parking_out_id))
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
      if self.parking_info is None:
        self.parking_info = None
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
      (length,) = _struct_I.unpack(str[start:end])
      self.parking_info = []
      for i in range(0, length):
        val1 = ros_interface.msg.HMIParkingInfo()
        _v13 = val1.header
        start = end
        end += 4
        (_v13.seq,) = _get_struct_I().unpack(str[start:end])
        _v14 = _v13.stamp
        _x = _v14
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v13.frame_id = str[start:end].decode('utf-8', 'rosmsg')
        else:
          _v13.frame_id = str[start:end]
        _x = val1
        start = end
        end += 12
        (_x.parking_space_id, _x.parking_type, _x.parking_status,) = _get_struct_3i().unpack(str[start:end])
        _v15 = val1.center_point_of_parking
        _x = _v15
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        _x = val1
        start = end
        end += 25
        (_x.theta, _x.width, _x.length, _x.is_custom_parking,) = _get_struct_3dB().unpack(str[start:end])
        val1.is_custom_parking = bool(val1.is_custom_parking)
        _v16 = val1.polygon
        start = end
        end += 4
        (_v16.coordinate_system,) = _get_struct_i().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        _v16.points = []
        for i in range(0, length):
          val3 = ros_interface.msg.Point3D()
          _x = val3
          start = end
          end += 24
          (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
          _v16.points.append(val3)
        start = end
        end += 4
        (val1.parking_source_type,) = _get_struct_i().unpack(str[start:end])
        self.parking_info.append(val1)
      _x = self
      start = end
      end += 9
      (_x.parking_out_enable, _x.parking_out_direction, _x.parking_out_id,) = _get_struct_B2i().unpack(str[start:end])
      self.parking_out_enable = bool(self.parking_out_enable)
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_2I = None
def _get_struct_2I():
    global _struct_2I
    if _struct_2I is None:
        _struct_2I = struct.Struct("<2I")
    return _struct_2I
_struct_3I = None
def _get_struct_3I():
    global _struct_3I
    if _struct_3I is None:
        _struct_3I = struct.Struct("<3I")
    return _struct_3I
_struct_3d = None
def _get_struct_3d():
    global _struct_3d
    if _struct_3d is None:
        _struct_3d = struct.Struct("<3d")
    return _struct_3d
_struct_3dB = None
def _get_struct_3dB():
    global _struct_3dB
    if _struct_3dB is None:
        _struct_3dB = struct.Struct("<3dB")
    return _struct_3dB
_struct_3i = None
def _get_struct_3i():
    global _struct_3i
    if _struct_3i is None:
        _struct_3i = struct.Struct("<3i")
    return _struct_3i
_struct_B2i = None
def _get_struct_B2i():
    global _struct_B2i
    if _struct_B2i is None:
        _struct_B2i = struct.Struct("<B2i")
    return _struct_B2i
_struct_i = None
def _get_struct_i():
    global _struct_i
    if _struct_i is None:
        _struct_i = struct.Struct("<i")
    return _struct_i
