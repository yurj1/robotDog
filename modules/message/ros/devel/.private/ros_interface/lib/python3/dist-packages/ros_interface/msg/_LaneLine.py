# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ros_interface/LaneLine.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import ros_interface.msg

class LaneLine(genpy.Message):
  _md5sum = "7984d3674f6a82d78f7d9d8a60ded1b8"
  _type = "ros_interface/LaneLine"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """int32   lane_type     #  车道线类型：   SOLID = 0;   DASHED = 1;   ROAD_DELIMITER = 2;   NONE = 3;   UNKNOWN = 4;
int32   lane_color     #  车道线颜色：   WHITE = 0;   YELLOW = 1;   OTHERS = 2;   UNKNOWN = 3;
int32   pos_type     # 车道线位置类别：    BOLLARD_LEFT = -5;   FOURTH_LEFT = -4;   THIRD_LEFT = -3;   ADJACENT_LEFT = -2;  //!< lane marking on the left side next to ego lane   EGO_LEFT = -1;       //!< left lane marking of the ego lane   EGO_RIGHT = 1;       //!< right lane marking of the ego lane   ADJACENT_RIGHT = 2;  //!< lane marking on the right side next to ego lane   THIRD_RIGHT = 3;   FOURTH_RIGHT = 4;   BOLLARD_RIGHT = 5;   OTHER = 6;    //!< other types of lane   UNKNOWN = 7;  //!< background
LaneLineCubicCurve   curve_vehicle     # 车辆坐标系车道线三次曲线系数
LaneLineCubicCurve   curve_image     # 图像坐标系车道线三次曲线系数
LaneLineCubicCurve   curve_abs     # 世界坐标系车道线三次曲线系数
Point3D[] pts_vehicle # 车辆坐标系车道线点集
Point2D[] pts_image # 图像坐标系车道线点集
Point3D[] pts_abs # 世界坐标系车道线点集
EndPoints   image_end_point     # 车道线上顶点与下顶点
Point2D[] pts_key # 车道线关键点数组
uint8   hd_lane_id     # 高精车道线id
float64   confidence     # 车道线置信度
int32   lane_quality     #   车道线质量：   VERY_LOW = 0;   LOW = 1;   HIGH = 2;   VERY_HIGH = 3;
int32   fused_lane_type     #   融合车道线类别：   CAMERA = 0;   HD = 1;   FUSED = 2;   UNKNOWN = 3;   if value is 1, lane_quality = 3
float64[] homography_mat # 透视变换矩阵
float64[] homography_mat_inv # 透视变换逆矩阵
int32   lane_coordinate_type     #   坐标系类别：   FRAME = 0;   IMAGE = 1;   CAMERA = 2;   VEHICLE = 3;   ABSOLUTE = 4;
int32   use_type     #   使用类别：   REAL = 0;   VIRTUAL = 1;
Time   create_time     # 车道线被识别的时间戳

================================================================================
MSG: ros_interface/LaneLineCubicCurve
float64   start_x     # 车道线起始位置
float64   end_x     # 车道线结束位置
float64   a     # 三次曲线系数
float64   b     #  
float64   c     #  
float64   d     #  

================================================================================
MSG: ros_interface/Point3D
float64   x     # 位置坐标x
float64   y     # 位置坐标y
float64   z     # 位置坐标z

================================================================================
MSG: ros_interface/Point2D
float64   x     # 位置坐标x
float64   y     # 位置坐标y

================================================================================
MSG: ros_interface/EndPoints
Point2D   start     # 车道线上顶点
Point2D   end     # 车道线下顶点

================================================================================
MSG: ros_interface/Time
uint32   sec     # 秒
uint32   nsec     # 纳秒
"""
  __slots__ = ['lane_type','lane_color','pos_type','curve_vehicle','curve_image','curve_abs','pts_vehicle','pts_image','pts_abs','image_end_point','pts_key','hd_lane_id','confidence','lane_quality','fused_lane_type','homography_mat','homography_mat_inv','lane_coordinate_type','use_type','create_time']
  _slot_types = ['int32','int32','int32','ros_interface/LaneLineCubicCurve','ros_interface/LaneLineCubicCurve','ros_interface/LaneLineCubicCurve','ros_interface/Point3D[]','ros_interface/Point2D[]','ros_interface/Point3D[]','ros_interface/EndPoints','ros_interface/Point2D[]','uint8','float64','int32','int32','float64[]','float64[]','int32','int32','ros_interface/Time']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       lane_type,lane_color,pos_type,curve_vehicle,curve_image,curve_abs,pts_vehicle,pts_image,pts_abs,image_end_point,pts_key,hd_lane_id,confidence,lane_quality,fused_lane_type,homography_mat,homography_mat_inv,lane_coordinate_type,use_type,create_time

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(LaneLine, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.lane_type is None:
        self.lane_type = 0
      if self.lane_color is None:
        self.lane_color = 0
      if self.pos_type is None:
        self.pos_type = 0
      if self.curve_vehicle is None:
        self.curve_vehicle = ros_interface.msg.LaneLineCubicCurve()
      if self.curve_image is None:
        self.curve_image = ros_interface.msg.LaneLineCubicCurve()
      if self.curve_abs is None:
        self.curve_abs = ros_interface.msg.LaneLineCubicCurve()
      if self.pts_vehicle is None:
        self.pts_vehicle = []
      if self.pts_image is None:
        self.pts_image = []
      if self.pts_abs is None:
        self.pts_abs = []
      if self.image_end_point is None:
        self.image_end_point = ros_interface.msg.EndPoints()
      if self.pts_key is None:
        self.pts_key = []
      if self.hd_lane_id is None:
        self.hd_lane_id = 0
      if self.confidence is None:
        self.confidence = 0.
      if self.lane_quality is None:
        self.lane_quality = 0
      if self.fused_lane_type is None:
        self.fused_lane_type = 0
      if self.homography_mat is None:
        self.homography_mat = []
      if self.homography_mat_inv is None:
        self.homography_mat_inv = []
      if self.lane_coordinate_type is None:
        self.lane_coordinate_type = 0
      if self.use_type is None:
        self.use_type = 0
      if self.create_time is None:
        self.create_time = ros_interface.msg.Time()
    else:
      self.lane_type = 0
      self.lane_color = 0
      self.pos_type = 0
      self.curve_vehicle = ros_interface.msg.LaneLineCubicCurve()
      self.curve_image = ros_interface.msg.LaneLineCubicCurve()
      self.curve_abs = ros_interface.msg.LaneLineCubicCurve()
      self.pts_vehicle = []
      self.pts_image = []
      self.pts_abs = []
      self.image_end_point = ros_interface.msg.EndPoints()
      self.pts_key = []
      self.hd_lane_id = 0
      self.confidence = 0.
      self.lane_quality = 0
      self.fused_lane_type = 0
      self.homography_mat = []
      self.homography_mat_inv = []
      self.lane_coordinate_type = 0
      self.use_type = 0
      self.create_time = ros_interface.msg.Time()

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
      buff.write(_get_struct_3i18d().pack(_x.lane_type, _x.lane_color, _x.pos_type, _x.curve_vehicle.start_x, _x.curve_vehicle.end_x, _x.curve_vehicle.a, _x.curve_vehicle.b, _x.curve_vehicle.c, _x.curve_vehicle.d, _x.curve_image.start_x, _x.curve_image.end_x, _x.curve_image.a, _x.curve_image.b, _x.curve_image.c, _x.curve_image.d, _x.curve_abs.start_x, _x.curve_abs.end_x, _x.curve_abs.a, _x.curve_abs.b, _x.curve_abs.c, _x.curve_abs.d))
      length = len(self.pts_vehicle)
      buff.write(_struct_I.pack(length))
      for val1 in self.pts_vehicle:
        _x = val1
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
      length = len(self.pts_image)
      buff.write(_struct_I.pack(length))
      for val1 in self.pts_image:
        _x = val1
        buff.write(_get_struct_2d().pack(_x.x, _x.y))
      length = len(self.pts_abs)
      buff.write(_struct_I.pack(length))
      for val1 in self.pts_abs:
        _x = val1
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
      _x = self
      buff.write(_get_struct_4d().pack(_x.image_end_point.start.x, _x.image_end_point.start.y, _x.image_end_point.end.x, _x.image_end_point.end.y))
      length = len(self.pts_key)
      buff.write(_struct_I.pack(length))
      for val1 in self.pts_key:
        _x = val1
        buff.write(_get_struct_2d().pack(_x.x, _x.y))
      _x = self
      buff.write(_get_struct_Bd2i().pack(_x.hd_lane_id, _x.confidence, _x.lane_quality, _x.fused_lane_type))
      length = len(self.homography_mat)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(struct.Struct(pattern).pack(*self.homography_mat))
      length = len(self.homography_mat_inv)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(struct.Struct(pattern).pack(*self.homography_mat_inv))
      _x = self
      buff.write(_get_struct_2i2I().pack(_x.lane_coordinate_type, _x.use_type, _x.create_time.sec, _x.create_time.nsec))
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
      if self.curve_vehicle is None:
        self.curve_vehicle = ros_interface.msg.LaneLineCubicCurve()
      if self.curve_image is None:
        self.curve_image = ros_interface.msg.LaneLineCubicCurve()
      if self.curve_abs is None:
        self.curve_abs = ros_interface.msg.LaneLineCubicCurve()
      if self.pts_vehicle is None:
        self.pts_vehicle = None
      if self.pts_image is None:
        self.pts_image = None
      if self.pts_abs is None:
        self.pts_abs = None
      if self.image_end_point is None:
        self.image_end_point = ros_interface.msg.EndPoints()
      if self.pts_key is None:
        self.pts_key = None
      if self.create_time is None:
        self.create_time = ros_interface.msg.Time()
      end = 0
      _x = self
      start = end
      end += 156
      (_x.lane_type, _x.lane_color, _x.pos_type, _x.curve_vehicle.start_x, _x.curve_vehicle.end_x, _x.curve_vehicle.a, _x.curve_vehicle.b, _x.curve_vehicle.c, _x.curve_vehicle.d, _x.curve_image.start_x, _x.curve_image.end_x, _x.curve_image.a, _x.curve_image.b, _x.curve_image.c, _x.curve_image.d, _x.curve_abs.start_x, _x.curve_abs.end_x, _x.curve_abs.a, _x.curve_abs.b, _x.curve_abs.c, _x.curve_abs.d,) = _get_struct_3i18d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.pts_vehicle = []
      for i in range(0, length):
        val1 = ros_interface.msg.Point3D()
        _x = val1
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        self.pts_vehicle.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.pts_image = []
      for i in range(0, length):
        val1 = ros_interface.msg.Point2D()
        _x = val1
        start = end
        end += 16
        (_x.x, _x.y,) = _get_struct_2d().unpack(str[start:end])
        self.pts_image.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.pts_abs = []
      for i in range(0, length):
        val1 = ros_interface.msg.Point3D()
        _x = val1
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        self.pts_abs.append(val1)
      _x = self
      start = end
      end += 32
      (_x.image_end_point.start.x, _x.image_end_point.start.y, _x.image_end_point.end.x, _x.image_end_point.end.y,) = _get_struct_4d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.pts_key = []
      for i in range(0, length):
        val1 = ros_interface.msg.Point2D()
        _x = val1
        start = end
        end += 16
        (_x.x, _x.y,) = _get_struct_2d().unpack(str[start:end])
        self.pts_key.append(val1)
      _x = self
      start = end
      end += 17
      (_x.hd_lane_id, _x.confidence, _x.lane_quality, _x.fused_lane_type,) = _get_struct_Bd2i().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      s = struct.Struct(pattern)
      end += s.size
      self.homography_mat = s.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      s = struct.Struct(pattern)
      end += s.size
      self.homography_mat_inv = s.unpack(str[start:end])
      _x = self
      start = end
      end += 16
      (_x.lane_coordinate_type, _x.use_type, _x.create_time.sec, _x.create_time.nsec,) = _get_struct_2i2I().unpack(str[start:end])
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
      buff.write(_get_struct_3i18d().pack(_x.lane_type, _x.lane_color, _x.pos_type, _x.curve_vehicle.start_x, _x.curve_vehicle.end_x, _x.curve_vehicle.a, _x.curve_vehicle.b, _x.curve_vehicle.c, _x.curve_vehicle.d, _x.curve_image.start_x, _x.curve_image.end_x, _x.curve_image.a, _x.curve_image.b, _x.curve_image.c, _x.curve_image.d, _x.curve_abs.start_x, _x.curve_abs.end_x, _x.curve_abs.a, _x.curve_abs.b, _x.curve_abs.c, _x.curve_abs.d))
      length = len(self.pts_vehicle)
      buff.write(_struct_I.pack(length))
      for val1 in self.pts_vehicle:
        _x = val1
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
      length = len(self.pts_image)
      buff.write(_struct_I.pack(length))
      for val1 in self.pts_image:
        _x = val1
        buff.write(_get_struct_2d().pack(_x.x, _x.y))
      length = len(self.pts_abs)
      buff.write(_struct_I.pack(length))
      for val1 in self.pts_abs:
        _x = val1
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
      _x = self
      buff.write(_get_struct_4d().pack(_x.image_end_point.start.x, _x.image_end_point.start.y, _x.image_end_point.end.x, _x.image_end_point.end.y))
      length = len(self.pts_key)
      buff.write(_struct_I.pack(length))
      for val1 in self.pts_key:
        _x = val1
        buff.write(_get_struct_2d().pack(_x.x, _x.y))
      _x = self
      buff.write(_get_struct_Bd2i().pack(_x.hd_lane_id, _x.confidence, _x.lane_quality, _x.fused_lane_type))
      length = len(self.homography_mat)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(self.homography_mat.tostring())
      length = len(self.homography_mat_inv)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(self.homography_mat_inv.tostring())
      _x = self
      buff.write(_get_struct_2i2I().pack(_x.lane_coordinate_type, _x.use_type, _x.create_time.sec, _x.create_time.nsec))
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
      if self.curve_vehicle is None:
        self.curve_vehicle = ros_interface.msg.LaneLineCubicCurve()
      if self.curve_image is None:
        self.curve_image = ros_interface.msg.LaneLineCubicCurve()
      if self.curve_abs is None:
        self.curve_abs = ros_interface.msg.LaneLineCubicCurve()
      if self.pts_vehicle is None:
        self.pts_vehicle = None
      if self.pts_image is None:
        self.pts_image = None
      if self.pts_abs is None:
        self.pts_abs = None
      if self.image_end_point is None:
        self.image_end_point = ros_interface.msg.EndPoints()
      if self.pts_key is None:
        self.pts_key = None
      if self.create_time is None:
        self.create_time = ros_interface.msg.Time()
      end = 0
      _x = self
      start = end
      end += 156
      (_x.lane_type, _x.lane_color, _x.pos_type, _x.curve_vehicle.start_x, _x.curve_vehicle.end_x, _x.curve_vehicle.a, _x.curve_vehicle.b, _x.curve_vehicle.c, _x.curve_vehicle.d, _x.curve_image.start_x, _x.curve_image.end_x, _x.curve_image.a, _x.curve_image.b, _x.curve_image.c, _x.curve_image.d, _x.curve_abs.start_x, _x.curve_abs.end_x, _x.curve_abs.a, _x.curve_abs.b, _x.curve_abs.c, _x.curve_abs.d,) = _get_struct_3i18d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.pts_vehicle = []
      for i in range(0, length):
        val1 = ros_interface.msg.Point3D()
        _x = val1
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        self.pts_vehicle.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.pts_image = []
      for i in range(0, length):
        val1 = ros_interface.msg.Point2D()
        _x = val1
        start = end
        end += 16
        (_x.x, _x.y,) = _get_struct_2d().unpack(str[start:end])
        self.pts_image.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.pts_abs = []
      for i in range(0, length):
        val1 = ros_interface.msg.Point3D()
        _x = val1
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        self.pts_abs.append(val1)
      _x = self
      start = end
      end += 32
      (_x.image_end_point.start.x, _x.image_end_point.start.y, _x.image_end_point.end.x, _x.image_end_point.end.y,) = _get_struct_4d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.pts_key = []
      for i in range(0, length):
        val1 = ros_interface.msg.Point2D()
        _x = val1
        start = end
        end += 16
        (_x.x, _x.y,) = _get_struct_2d().unpack(str[start:end])
        self.pts_key.append(val1)
      _x = self
      start = end
      end += 17
      (_x.hd_lane_id, _x.confidence, _x.lane_quality, _x.fused_lane_type,) = _get_struct_Bd2i().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      s = struct.Struct(pattern)
      end += s.size
      self.homography_mat = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=length)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      s = struct.Struct(pattern)
      end += s.size
      self.homography_mat_inv = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=length)
      _x = self
      start = end
      end += 16
      (_x.lane_coordinate_type, _x.use_type, _x.create_time.sec, _x.create_time.nsec,) = _get_struct_2i2I().unpack(str[start:end])
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
_struct_2i2I = None
def _get_struct_2i2I():
    global _struct_2i2I
    if _struct_2i2I is None:
        _struct_2i2I = struct.Struct("<2i2I")
    return _struct_2i2I
_struct_3d = None
def _get_struct_3d():
    global _struct_3d
    if _struct_3d is None:
        _struct_3d = struct.Struct("<3d")
    return _struct_3d
_struct_3i18d = None
def _get_struct_3i18d():
    global _struct_3i18d
    if _struct_3i18d is None:
        _struct_3i18d = struct.Struct("<3i18d")
    return _struct_3i18d
_struct_4d = None
def _get_struct_4d():
    global _struct_4d
    if _struct_4d is None:
        _struct_4d = struct.Struct("<4d")
    return _struct_4d
_struct_Bd2i = None
def _get_struct_Bd2i():
    global _struct_Bd2i
    if _struct_Bd2i is None:
        _struct_Bd2i = struct.Struct("<Bd2i")
    return _struct_Bd2i
