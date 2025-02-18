# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ros_interface/HMIParkingInfo.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import ros_interface.msg
import std_msgs.msg

class HMIParkingInfo(genpy.Message):
  _md5sum = "e289531f8277ce0296a442820fcf7b40"
  _type = "ros_interface/HMIParkingInfo"
  _has_header = True  # flag to mark the presence of a Header object
  _full_text = """Header   header     # timestamp is  included in header
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
MSG: ros_interface/Point3D
float64   x     # 位置坐标x
float64   y     # 位置坐标y
float64   z     # 位置坐标z

================================================================================
MSG: ros_interface/Polygon3D
int32   coordinate_system     # 坐标系
Point3D[] points # 三维点集
"""
  __slots__ = ['header','parking_space_id','parking_type','parking_status','center_point_of_parking','theta','width','length','is_custom_parking','polygon','parking_source_type']
  _slot_types = ['std_msgs/Header','int32','int32','int32','ros_interface/Point3D','float64','float64','float64','bool','ros_interface/Polygon3D','int32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       header,parking_space_id,parking_type,parking_status,center_point_of_parking,theta,width,length,is_custom_parking,polygon,parking_source_type

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(HMIParkingInfo, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.parking_space_id is None:
        self.parking_space_id = 0
      if self.parking_type is None:
        self.parking_type = 0
      if self.parking_status is None:
        self.parking_status = 0
      if self.center_point_of_parking is None:
        self.center_point_of_parking = ros_interface.msg.Point3D()
      if self.theta is None:
        self.theta = 0.
      if self.width is None:
        self.width = 0.
      if self.length is None:
        self.length = 0.
      if self.is_custom_parking is None:
        self.is_custom_parking = False
      if self.polygon is None:
        self.polygon = ros_interface.msg.Polygon3D()
      if self.parking_source_type is None:
        self.parking_source_type = 0
    else:
      self.header = std_msgs.msg.Header()
      self.parking_space_id = 0
      self.parking_type = 0
      self.parking_status = 0
      self.center_point_of_parking = ros_interface.msg.Point3D()
      self.theta = 0.
      self.width = 0.
      self.length = 0.
      self.is_custom_parking = False
      self.polygon = ros_interface.msg.Polygon3D()
      self.parking_source_type = 0

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
      _x = self
      buff.write(_get_struct_3i6dBi().pack(_x.parking_space_id, _x.parking_type, _x.parking_status, _x.center_point_of_parking.x, _x.center_point_of_parking.y, _x.center_point_of_parking.z, _x.theta, _x.width, _x.length, _x.is_custom_parking, _x.polygon.coordinate_system))
      length = len(self.polygon.points)
      buff.write(_struct_I.pack(length))
      for val1 in self.polygon.points:
        _x = val1
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
      _x = self.parking_source_type
      buff.write(_get_struct_i().pack(_x))
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
      if self.center_point_of_parking is None:
        self.center_point_of_parking = ros_interface.msg.Point3D()
      if self.polygon is None:
        self.polygon = ros_interface.msg.Polygon3D()
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
      _x = self
      start = end
      end += 65
      (_x.parking_space_id, _x.parking_type, _x.parking_status, _x.center_point_of_parking.x, _x.center_point_of_parking.y, _x.center_point_of_parking.z, _x.theta, _x.width, _x.length, _x.is_custom_parking, _x.polygon.coordinate_system,) = _get_struct_3i6dBi().unpack(str[start:end])
      self.is_custom_parking = bool(self.is_custom_parking)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.polygon.points = []
      for i in range(0, length):
        val1 = ros_interface.msg.Point3D()
        _x = val1
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        self.polygon.points.append(val1)
      start = end
      end += 4
      (self.parking_source_type,) = _get_struct_i().unpack(str[start:end])
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
      _x = self
      buff.write(_get_struct_3i6dBi().pack(_x.parking_space_id, _x.parking_type, _x.parking_status, _x.center_point_of_parking.x, _x.center_point_of_parking.y, _x.center_point_of_parking.z, _x.theta, _x.width, _x.length, _x.is_custom_parking, _x.polygon.coordinate_system))
      length = len(self.polygon.points)
      buff.write(_struct_I.pack(length))
      for val1 in self.polygon.points:
        _x = val1
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
      _x = self.parking_source_type
      buff.write(_get_struct_i().pack(_x))
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
      if self.center_point_of_parking is None:
        self.center_point_of_parking = ros_interface.msg.Point3D()
      if self.polygon is None:
        self.polygon = ros_interface.msg.Polygon3D()
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
      _x = self
      start = end
      end += 65
      (_x.parking_space_id, _x.parking_type, _x.parking_status, _x.center_point_of_parking.x, _x.center_point_of_parking.y, _x.center_point_of_parking.z, _x.theta, _x.width, _x.length, _x.is_custom_parking, _x.polygon.coordinate_system,) = _get_struct_3i6dBi().unpack(str[start:end])
      self.is_custom_parking = bool(self.is_custom_parking)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.polygon.points = []
      for i in range(0, length):
        val1 = ros_interface.msg.Point3D()
        _x = val1
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        self.polygon.points.append(val1)
      start = end
      end += 4
      (self.parking_source_type,) = _get_struct_i().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
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
_struct_3i6dBi = None
def _get_struct_3i6dBi():
    global _struct_3i6dBi
    if _struct_3i6dBi is None:
        _struct_3i6dBi = struct.Struct("<3i6dBi")
    return _struct_3i6dBi
_struct_i = None
def _get_struct_i():
    global _struct_i
    if _struct_i is None:
        _struct_i = struct.Struct("<i")
    return _struct_i
