# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ros_interface/CameraParkingInfoList.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import ros_interface.msg
import std_msgs.msg

class CameraParkingInfoList(genpy.Message):
  _md5sum = "d4caa94d6814e1d645bcbe41c8c0b57d"
  _type = "ros_interface/CameraParkingInfoList"
  _has_header = True  # flag to mark the presence of a Header object
  _full_text = """Header   header     # 消息头，时间戳使用接收的图像的时间戳
int32   sensor_id     # 安装的传感器id(camera,lidar,radar) ' 相机id: 0-front_center相机 1-front_left相机 2-front_right相机 3-left_front相机 4-left_back右后相机 5-right_front相机 6-right_back相机 7-back相机'  8-相机融合
CameraParkingInfo[] camera_parking # 检测出的障碍物数组
CameraParkingStopper[] camera_parking_stoppers # 检测出的限位器数组
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
MSG: ros_interface/CameraParkingInfo
Header   header     # timestamp is  included in header
int32   parking_space_id     # 停车位id
int32   parking_type     # PARKING_TYPE=0//无效泊车 PARKING_TYPE=1//垂直泊车 PARKING_TYPE=2//水平泊车 PARKING_TYPE=3//倾斜泊车
bool   is_parking_enable     # PARKING_ENABLE=0//不可泊入 PARKING_ENABLE=1//可泊入
float64   confidence     # 停车位置信度
Point3D   center_point_of_parking     # 车辆坐标系的停车位中心点
float64   theta     # 车辆坐标系下停车位的朝向
float64   width     # 停车位宽
float64   length     # 停车位长
float64   yaw_offset     # 停车位角度偏移量（倾斜车位），倾斜车位与道路边线夹角
ImageKeyPoint[] parking_points_in_image # 图像坐标系下停车位关键点，顺时针方向

================================================================================
MSG: ros_interface/Point3D
float64   x     # 位置坐标x
float64   y     # 位置坐标y
float64   z     # 位置坐标z

================================================================================
MSG: ros_interface/ImageKeyPoint
float64   x     # 车位图像关键点x坐标
float64   y     # 车位图像关键点y坐标
float64   confidence     # 置信度

================================================================================
MSG: ros_interface/CameraParkingStopper
Header   header     # timestamp is  included in header
BBox2D   bbox2d     # 限位器图像框

================================================================================
MSG: ros_interface/BBox2D
int16   xmin     # 图像框左上角的x坐标
int16   ymin     # 图像框左上角的y坐标
int16   xmax     # 图像框右下角的x坐标
int16   ymax     # 图像框右下角的y坐标
"""
  __slots__ = ['header','sensor_id','camera_parking','camera_parking_stoppers','error_code','is_valid']
  _slot_types = ['std_msgs/Header','int32','ros_interface/CameraParkingInfo[]','ros_interface/CameraParkingStopper[]','int32','bool']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       header,sensor_id,camera_parking,camera_parking_stoppers,error_code,is_valid

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(CameraParkingInfoList, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.sensor_id is None:
        self.sensor_id = 0
      if self.camera_parking is None:
        self.camera_parking = []
      if self.camera_parking_stoppers is None:
        self.camera_parking_stoppers = []
      if self.error_code is None:
        self.error_code = 0
      if self.is_valid is None:
        self.is_valid = False
    else:
      self.header = std_msgs.msg.Header()
      self.sensor_id = 0
      self.camera_parking = []
      self.camera_parking_stoppers = []
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
      length = len(self.camera_parking)
      buff.write(_struct_I.pack(length))
      for val1 in self.camera_parking:
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
        buff.write(_get_struct_2iBd().pack(_x.parking_space_id, _x.parking_type, _x.is_parking_enable, _x.confidence))
        _v3 = val1.center_point_of_parking
        _x = _v3
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        _x = val1
        buff.write(_get_struct_4d().pack(_x.theta, _x.width, _x.length, _x.yaw_offset))
        length = len(val1.parking_points_in_image)
        buff.write(_struct_I.pack(length))
        for val2 in val1.parking_points_in_image:
          _x = val2
          buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.confidence))
      length = len(self.camera_parking_stoppers)
      buff.write(_struct_I.pack(length))
      for val1 in self.camera_parking_stoppers:
        _v4 = val1.header
        _x = _v4.seq
        buff.write(_get_struct_I().pack(_x))
        _v5 = _v4.stamp
        _x = _v5
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = _v4.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
        _v6 = val1.bbox2d
        _x = _v6
        buff.write(_get_struct_4h().pack(_x.xmin, _x.ymin, _x.xmax, _x.ymax))
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
      if self.camera_parking is None:
        self.camera_parking = None
      if self.camera_parking_stoppers is None:
        self.camera_parking_stoppers = None
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
      self.camera_parking = []
      for i in range(0, length):
        val1 = ros_interface.msg.CameraParkingInfo()
        _v7 = val1.header
        start = end
        end += 4
        (_v7.seq,) = _get_struct_I().unpack(str[start:end])
        _v8 = _v7.stamp
        _x = _v8
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v7.frame_id = str[start:end].decode('utf-8', 'rosmsg')
        else:
          _v7.frame_id = str[start:end]
        _x = val1
        start = end
        end += 17
        (_x.parking_space_id, _x.parking_type, _x.is_parking_enable, _x.confidence,) = _get_struct_2iBd().unpack(str[start:end])
        val1.is_parking_enable = bool(val1.is_parking_enable)
        _v9 = val1.center_point_of_parking
        _x = _v9
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        _x = val1
        start = end
        end += 32
        (_x.theta, _x.width, _x.length, _x.yaw_offset,) = _get_struct_4d().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        val1.parking_points_in_image = []
        for i in range(0, length):
          val2 = ros_interface.msg.ImageKeyPoint()
          _x = val2
          start = end
          end += 24
          (_x.x, _x.y, _x.confidence,) = _get_struct_3d().unpack(str[start:end])
          val1.parking_points_in_image.append(val2)
        self.camera_parking.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.camera_parking_stoppers = []
      for i in range(0, length):
        val1 = ros_interface.msg.CameraParkingStopper()
        _v10 = val1.header
        start = end
        end += 4
        (_v10.seq,) = _get_struct_I().unpack(str[start:end])
        _v11 = _v10.stamp
        _x = _v11
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v10.frame_id = str[start:end].decode('utf-8', 'rosmsg')
        else:
          _v10.frame_id = str[start:end]
        _v12 = val1.bbox2d
        _x = _v12
        start = end
        end += 8
        (_x.xmin, _x.ymin, _x.xmax, _x.ymax,) = _get_struct_4h().unpack(str[start:end])
        self.camera_parking_stoppers.append(val1)
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
      length = len(self.camera_parking)
      buff.write(_struct_I.pack(length))
      for val1 in self.camera_parking:
        _v13 = val1.header
        _x = _v13.seq
        buff.write(_get_struct_I().pack(_x))
        _v14 = _v13.stamp
        _x = _v14
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = _v13.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
        _x = val1
        buff.write(_get_struct_2iBd().pack(_x.parking_space_id, _x.parking_type, _x.is_parking_enable, _x.confidence))
        _v15 = val1.center_point_of_parking
        _x = _v15
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
        _x = val1
        buff.write(_get_struct_4d().pack(_x.theta, _x.width, _x.length, _x.yaw_offset))
        length = len(val1.parking_points_in_image)
        buff.write(_struct_I.pack(length))
        for val2 in val1.parking_points_in_image:
          _x = val2
          buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.confidence))
      length = len(self.camera_parking_stoppers)
      buff.write(_struct_I.pack(length))
      for val1 in self.camera_parking_stoppers:
        _v16 = val1.header
        _x = _v16.seq
        buff.write(_get_struct_I().pack(_x))
        _v17 = _v16.stamp
        _x = _v17
        buff.write(_get_struct_2I().pack(_x.secs, _x.nsecs))
        _x = _v16.frame_id
        length = len(_x)
        if python3 or type(_x) == unicode:
          _x = _x.encode('utf-8')
          length = len(_x)
        buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
        _v18 = val1.bbox2d
        _x = _v18
        buff.write(_get_struct_4h().pack(_x.xmin, _x.ymin, _x.xmax, _x.ymax))
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
      if self.camera_parking is None:
        self.camera_parking = None
      if self.camera_parking_stoppers is None:
        self.camera_parking_stoppers = None
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
      self.camera_parking = []
      for i in range(0, length):
        val1 = ros_interface.msg.CameraParkingInfo()
        _v19 = val1.header
        start = end
        end += 4
        (_v19.seq,) = _get_struct_I().unpack(str[start:end])
        _v20 = _v19.stamp
        _x = _v20
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v19.frame_id = str[start:end].decode('utf-8', 'rosmsg')
        else:
          _v19.frame_id = str[start:end]
        _x = val1
        start = end
        end += 17
        (_x.parking_space_id, _x.parking_type, _x.is_parking_enable, _x.confidence,) = _get_struct_2iBd().unpack(str[start:end])
        val1.is_parking_enable = bool(val1.is_parking_enable)
        _v21 = val1.center_point_of_parking
        _x = _v21
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        _x = val1
        start = end
        end += 32
        (_x.theta, _x.width, _x.length, _x.yaw_offset,) = _get_struct_4d().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        val1.parking_points_in_image = []
        for i in range(0, length):
          val2 = ros_interface.msg.ImageKeyPoint()
          _x = val2
          start = end
          end += 24
          (_x.x, _x.y, _x.confidence,) = _get_struct_3d().unpack(str[start:end])
          val1.parking_points_in_image.append(val2)
        self.camera_parking.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.camera_parking_stoppers = []
      for i in range(0, length):
        val1 = ros_interface.msg.CameraParkingStopper()
        _v22 = val1.header
        start = end
        end += 4
        (_v22.seq,) = _get_struct_I().unpack(str[start:end])
        _v23 = _v22.stamp
        _x = _v23
        start = end
        end += 8
        (_x.secs, _x.nsecs,) = _get_struct_2I().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        start = end
        end += length
        if python3:
          _v22.frame_id = str[start:end].decode('utf-8', 'rosmsg')
        else:
          _v22.frame_id = str[start:end]
        _v24 = val1.bbox2d
        _x = _v24
        start = end
        end += 8
        (_x.xmin, _x.ymin, _x.xmax, _x.ymax,) = _get_struct_4h().unpack(str[start:end])
        self.camera_parking_stoppers.append(val1)
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
_struct_2I = None
def _get_struct_2I():
    global _struct_2I
    if _struct_2I is None:
        _struct_2I = struct.Struct("<2I")
    return _struct_2I
_struct_2iBd = None
def _get_struct_2iBd():
    global _struct_2iBd
    if _struct_2iBd is None:
        _struct_2iBd = struct.Struct("<2iBd")
    return _struct_2iBd
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
_struct_4d = None
def _get_struct_4d():
    global _struct_4d
    if _struct_4d is None:
        _struct_4d = struct.Struct("<4d")
    return _struct_4d
_struct_4h = None
def _get_struct_4h():
    global _struct_4h
    if _struct_4h is None:
        _struct_4h = struct.Struct("<4h")
    return _struct_4h
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
