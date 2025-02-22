# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ros_interface/Obstacle.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import ros_interface.msg

class Obstacle(genpy.Message):
  _md5sum = "540c5953bd92bdf84eafae61ed094918"
  _type = "ros_interface/Obstacle"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """Time   timestamp     # 时间戳
int32   id     # 障碍物id
float64   existence_prob     # 障碍物存在的概率
Time   create_time     # 障碍物被识别的时间戳
Time   last_updated_time     # 障碍物上一次更新的时间
Point3D   center_pos_vehicle     # 车辆坐标系下障碍物的中心位置
Point3D   center_pos_abs     # 世界坐标系下障碍物的中心位置
float64   theta_vehicle     # 车辆坐标系下障碍物的朝向
float64   theta_abs     # 世界坐标系下障碍物的朝向
Point3D   velocity_vehicle     # 车辆坐标系下障碍物的速度
Point3D   velocity_abs     # 世界坐标系下障碍物的速度
float64   length     # 障碍物长度
float64   width     # 障碍物宽度
float64   height     # 障碍物高度
ImageKeyPoint[] image_key_points # 图像坐标系下障碍物多边形
Point3D[] polygon_point_abs # 世界坐标系下障碍物多边形
Point3D[] polygon_point_vehicle # 车辆坐标系下障碍物多边形
float64   tracking_time     # 障碍物被追踪的时间
int32   type     # 障碍物类别： UNKNOWN = 0; UNKNOWN_MOVABLE = 1; UNKNOWN_UNMOVABLE = 2; PEDESTRIAN = 3; BICYCLE = 4; VEHICLE = 5;
float64   confidence     # 障碍物类别置信度
int32   confidence_type     # 障碍物置信度类别： CONFIDENCE_UNKNOWN = 0; CONFIDENCE_CNN = 1; CONFIDENCE_RADAR = 2;
Point3D[] drops # 障碍物轨迹点
Point3D   acceleration_vehicle     # 车辆坐标系下障碍物的加速度
Point3D   acceleration_abs     # 世界坐标系下障碍物的加速度
Point2D   anchor_point_image     # 障碍物尾框中心点(图像坐标系)
Point3D   anchor_point_vehicle     # 障碍物尾框中心点(车辆坐标系)
Point3D   anchor_point_abs     # 障碍物尾框中心点(世界坐标系)
BBox2D   bbox2d     # 障碍物图像框
BBox2D   bbox2d_rear     # 障碍物图像尾框
int32   sub_type     # 障碍物类别： ST_UNKNOWN = 0; ST_UNKNOWN_MOVABLE = 1; ST_UNKNOWN_UNMOVABLE = 2; ST_CAR = 3; ST_VAN = 4; ST_TRUCK = 5; ST_BUS = 6; ST_CYCLIST = 7; ST_MOTORCYCLIST = 8; ST_TRICYCLIST = 9; ST_PEDESTRIAN = 10; ST_TRAFFICCONE = 11; ST_PILLAR = 12; ST_SPEED_BUMP = 13;
float64   height_above_ground     # 障碍物近地点到地面的高度
float64[] position_abs_covariance # 世界坐标系下障碍物中心位置的协方差矩阵
float64[] velocity_abs_covariance # 世界坐标系下障碍物速度的协方差矩阵
float64[] acceleration_abs_covariance # 世界坐标系下障碍物加速度的协方差矩阵
float64   theta_abs_covariance     # 世界坐标系下障碍物朝向的协方差矩阵
float64[] position_vehicle_covariance # 车辆坐标系下障碍物中心位置的协方差矩阵
float64[] velocity_vehicle_covariance # 车辆坐标系下障碍物速度的协方差矩阵
float64[] acceleration_vehicle_covariance # 车辆坐标系下障碍物加速度的协方差矩阵
float64   theta_vehicle_covariance     # 车辆坐标系下障碍物朝向的协方差矩阵
SensorCalibrator   sensor_calibrator     # 传感器标定参数
uint8   cipv_flag     # 障碍物状态标志（0-CIPV 1-CIPS 2-LPIHP 3-RPIHP 4-NONE）
int32   lane_position     # 车道线位置 -2-NEXT_LEFT_LANE -1-LEFT_LANE 0-EGO_LANE 1-RIGHT_LANE 2-NEXT_RIGHT_LANE 3-OTHERS 4-UNKNOWN
float64   pihp_percentage     # 临车道车辆压线比例
int32   blinker_flag     # 障碍物车辆信号灯状态： 0-OFF 1-LEFT_TURN_VISIBLE 2-LEFT_TURN_ON 3-RIGHT_TURN_VISIBLE 4-RIGHT_TURN_ON 5-BRAKE_VISIBLE 6-BRAKE_ON 7-UNKNOWN
int32   fusion_type     # 融合障碍物类型 0-CAMERA 1-RADAR 2-LIDAR 3-ULTRASONIC 4-FUSED 5-UNKNOWN

================================================================================
MSG: ros_interface/Time
uint32   sec     # 秒
uint32   nsec     # 纳秒

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
MSG: ros_interface/Point2D
float64   x     # 位置坐标x
float64   y     # 位置坐标y

================================================================================
MSG: ros_interface/BBox2D
int16   xmin     # 图像框左上角的x坐标
int16   ymin     # 图像框左上角的y坐标
int16   xmax     # 图像框右下角的x坐标
int16   ymax     # 图像框右下角的y坐标

================================================================================
MSG: ros_interface/SensorCalibrator
Point3D   pose     # 传感器安装位置(相对于后轴中心点)
Point3D   angle     # 传感器安装角度(车体坐标系)
"""
  __slots__ = ['timestamp','id','existence_prob','create_time','last_updated_time','center_pos_vehicle','center_pos_abs','theta_vehicle','theta_abs','velocity_vehicle','velocity_abs','length','width','height','image_key_points','polygon_point_abs','polygon_point_vehicle','tracking_time','type','confidence','confidence_type','drops','acceleration_vehicle','acceleration_abs','anchor_point_image','anchor_point_vehicle','anchor_point_abs','bbox2d','bbox2d_rear','sub_type','height_above_ground','position_abs_covariance','velocity_abs_covariance','acceleration_abs_covariance','theta_abs_covariance','position_vehicle_covariance','velocity_vehicle_covariance','acceleration_vehicle_covariance','theta_vehicle_covariance','sensor_calibrator','cipv_flag','lane_position','pihp_percentage','blinker_flag','fusion_type']
  _slot_types = ['ros_interface/Time','int32','float64','ros_interface/Time','ros_interface/Time','ros_interface/Point3D','ros_interface/Point3D','float64','float64','ros_interface/Point3D','ros_interface/Point3D','float64','float64','float64','ros_interface/ImageKeyPoint[]','ros_interface/Point3D[]','ros_interface/Point3D[]','float64','int32','float64','int32','ros_interface/Point3D[]','ros_interface/Point3D','ros_interface/Point3D','ros_interface/Point2D','ros_interface/Point3D','ros_interface/Point3D','ros_interface/BBox2D','ros_interface/BBox2D','int32','float64','float64[]','float64[]','float64[]','float64','float64[]','float64[]','float64[]','float64','ros_interface/SensorCalibrator','uint8','int32','float64','int32','int32']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       timestamp,id,existence_prob,create_time,last_updated_time,center_pos_vehicle,center_pos_abs,theta_vehicle,theta_abs,velocity_vehicle,velocity_abs,length,width,height,image_key_points,polygon_point_abs,polygon_point_vehicle,tracking_time,type,confidence,confidence_type,drops,acceleration_vehicle,acceleration_abs,anchor_point_image,anchor_point_vehicle,anchor_point_abs,bbox2d,bbox2d_rear,sub_type,height_above_ground,position_abs_covariance,velocity_abs_covariance,acceleration_abs_covariance,theta_abs_covariance,position_vehicle_covariance,velocity_vehicle_covariance,acceleration_vehicle_covariance,theta_vehicle_covariance,sensor_calibrator,cipv_flag,lane_position,pihp_percentage,blinker_flag,fusion_type

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(Obstacle, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.timestamp is None:
        self.timestamp = ros_interface.msg.Time()
      if self.id is None:
        self.id = 0
      if self.existence_prob is None:
        self.existence_prob = 0.
      if self.create_time is None:
        self.create_time = ros_interface.msg.Time()
      if self.last_updated_time is None:
        self.last_updated_time = ros_interface.msg.Time()
      if self.center_pos_vehicle is None:
        self.center_pos_vehicle = ros_interface.msg.Point3D()
      if self.center_pos_abs is None:
        self.center_pos_abs = ros_interface.msg.Point3D()
      if self.theta_vehicle is None:
        self.theta_vehicle = 0.
      if self.theta_abs is None:
        self.theta_abs = 0.
      if self.velocity_vehicle is None:
        self.velocity_vehicle = ros_interface.msg.Point3D()
      if self.velocity_abs is None:
        self.velocity_abs = ros_interface.msg.Point3D()
      if self.length is None:
        self.length = 0.
      if self.width is None:
        self.width = 0.
      if self.height is None:
        self.height = 0.
      if self.image_key_points is None:
        self.image_key_points = []
      if self.polygon_point_abs is None:
        self.polygon_point_abs = []
      if self.polygon_point_vehicle is None:
        self.polygon_point_vehicle = []
      if self.tracking_time is None:
        self.tracking_time = 0.
      if self.type is None:
        self.type = 0
      if self.confidence is None:
        self.confidence = 0.
      if self.confidence_type is None:
        self.confidence_type = 0
      if self.drops is None:
        self.drops = []
      if self.acceleration_vehicle is None:
        self.acceleration_vehicle = ros_interface.msg.Point3D()
      if self.acceleration_abs is None:
        self.acceleration_abs = ros_interface.msg.Point3D()
      if self.anchor_point_image is None:
        self.anchor_point_image = ros_interface.msg.Point2D()
      if self.anchor_point_vehicle is None:
        self.anchor_point_vehicle = ros_interface.msg.Point3D()
      if self.anchor_point_abs is None:
        self.anchor_point_abs = ros_interface.msg.Point3D()
      if self.bbox2d is None:
        self.bbox2d = ros_interface.msg.BBox2D()
      if self.bbox2d_rear is None:
        self.bbox2d_rear = ros_interface.msg.BBox2D()
      if self.sub_type is None:
        self.sub_type = 0
      if self.height_above_ground is None:
        self.height_above_ground = 0.
      if self.position_abs_covariance is None:
        self.position_abs_covariance = []
      if self.velocity_abs_covariance is None:
        self.velocity_abs_covariance = []
      if self.acceleration_abs_covariance is None:
        self.acceleration_abs_covariance = []
      if self.theta_abs_covariance is None:
        self.theta_abs_covariance = 0.
      if self.position_vehicle_covariance is None:
        self.position_vehicle_covariance = []
      if self.velocity_vehicle_covariance is None:
        self.velocity_vehicle_covariance = []
      if self.acceleration_vehicle_covariance is None:
        self.acceleration_vehicle_covariance = []
      if self.theta_vehicle_covariance is None:
        self.theta_vehicle_covariance = 0.
      if self.sensor_calibrator is None:
        self.sensor_calibrator = ros_interface.msg.SensorCalibrator()
      if self.cipv_flag is None:
        self.cipv_flag = 0
      if self.lane_position is None:
        self.lane_position = 0
      if self.pihp_percentage is None:
        self.pihp_percentage = 0.
      if self.blinker_flag is None:
        self.blinker_flag = 0
      if self.fusion_type is None:
        self.fusion_type = 0
    else:
      self.timestamp = ros_interface.msg.Time()
      self.id = 0
      self.existence_prob = 0.
      self.create_time = ros_interface.msg.Time()
      self.last_updated_time = ros_interface.msg.Time()
      self.center_pos_vehicle = ros_interface.msg.Point3D()
      self.center_pos_abs = ros_interface.msg.Point3D()
      self.theta_vehicle = 0.
      self.theta_abs = 0.
      self.velocity_vehicle = ros_interface.msg.Point3D()
      self.velocity_abs = ros_interface.msg.Point3D()
      self.length = 0.
      self.width = 0.
      self.height = 0.
      self.image_key_points = []
      self.polygon_point_abs = []
      self.polygon_point_vehicle = []
      self.tracking_time = 0.
      self.type = 0
      self.confidence = 0.
      self.confidence_type = 0
      self.drops = []
      self.acceleration_vehicle = ros_interface.msg.Point3D()
      self.acceleration_abs = ros_interface.msg.Point3D()
      self.anchor_point_image = ros_interface.msg.Point2D()
      self.anchor_point_vehicle = ros_interface.msg.Point3D()
      self.anchor_point_abs = ros_interface.msg.Point3D()
      self.bbox2d = ros_interface.msg.BBox2D()
      self.bbox2d_rear = ros_interface.msg.BBox2D()
      self.sub_type = 0
      self.height_above_ground = 0.
      self.position_abs_covariance = []
      self.velocity_abs_covariance = []
      self.acceleration_abs_covariance = []
      self.theta_abs_covariance = 0.
      self.position_vehicle_covariance = []
      self.velocity_vehicle_covariance = []
      self.acceleration_vehicle_covariance = []
      self.theta_vehicle_covariance = 0.
      self.sensor_calibrator = ros_interface.msg.SensorCalibrator()
      self.cipv_flag = 0
      self.lane_position = 0
      self.pihp_percentage = 0.
      self.blinker_flag = 0
      self.fusion_type = 0

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
      buff.write(_get_struct_2Iid4I17d().pack(_x.timestamp.sec, _x.timestamp.nsec, _x.id, _x.existence_prob, _x.create_time.sec, _x.create_time.nsec, _x.last_updated_time.sec, _x.last_updated_time.nsec, _x.center_pos_vehicle.x, _x.center_pos_vehicle.y, _x.center_pos_vehicle.z, _x.center_pos_abs.x, _x.center_pos_abs.y, _x.center_pos_abs.z, _x.theta_vehicle, _x.theta_abs, _x.velocity_vehicle.x, _x.velocity_vehicle.y, _x.velocity_vehicle.z, _x.velocity_abs.x, _x.velocity_abs.y, _x.velocity_abs.z, _x.length, _x.width, _x.height))
      length = len(self.image_key_points)
      buff.write(_struct_I.pack(length))
      for val1 in self.image_key_points:
        _x = val1
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.confidence))
      length = len(self.polygon_point_abs)
      buff.write(_struct_I.pack(length))
      for val1 in self.polygon_point_abs:
        _x = val1
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
      length = len(self.polygon_point_vehicle)
      buff.write(_struct_I.pack(length))
      for val1 in self.polygon_point_vehicle:
        _x = val1
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
      _x = self
      buff.write(_get_struct_didi().pack(_x.tracking_time, _x.type, _x.confidence, _x.confidence_type))
      length = len(self.drops)
      buff.write(_struct_I.pack(length))
      for val1 in self.drops:
        _x = val1
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
      _x = self
      buff.write(_get_struct_14d8hid().pack(_x.acceleration_vehicle.x, _x.acceleration_vehicle.y, _x.acceleration_vehicle.z, _x.acceleration_abs.x, _x.acceleration_abs.y, _x.acceleration_abs.z, _x.anchor_point_image.x, _x.anchor_point_image.y, _x.anchor_point_vehicle.x, _x.anchor_point_vehicle.y, _x.anchor_point_vehicle.z, _x.anchor_point_abs.x, _x.anchor_point_abs.y, _x.anchor_point_abs.z, _x.bbox2d.xmin, _x.bbox2d.ymin, _x.bbox2d.xmax, _x.bbox2d.ymax, _x.bbox2d_rear.xmin, _x.bbox2d_rear.ymin, _x.bbox2d_rear.xmax, _x.bbox2d_rear.ymax, _x.sub_type, _x.height_above_ground))
      length = len(self.position_abs_covariance)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(struct.Struct(pattern).pack(*self.position_abs_covariance))
      length = len(self.velocity_abs_covariance)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(struct.Struct(pattern).pack(*self.velocity_abs_covariance))
      length = len(self.acceleration_abs_covariance)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(struct.Struct(pattern).pack(*self.acceleration_abs_covariance))
      _x = self.theta_abs_covariance
      buff.write(_get_struct_d().pack(_x))
      length = len(self.position_vehicle_covariance)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(struct.Struct(pattern).pack(*self.position_vehicle_covariance))
      length = len(self.velocity_vehicle_covariance)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(struct.Struct(pattern).pack(*self.velocity_vehicle_covariance))
      length = len(self.acceleration_vehicle_covariance)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(struct.Struct(pattern).pack(*self.acceleration_vehicle_covariance))
      _x = self
      buff.write(_get_struct_7dBid2i().pack(_x.theta_vehicle_covariance, _x.sensor_calibrator.pose.x, _x.sensor_calibrator.pose.y, _x.sensor_calibrator.pose.z, _x.sensor_calibrator.angle.x, _x.sensor_calibrator.angle.y, _x.sensor_calibrator.angle.z, _x.cipv_flag, _x.lane_position, _x.pihp_percentage, _x.blinker_flag, _x.fusion_type))
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
      if self.timestamp is None:
        self.timestamp = ros_interface.msg.Time()
      if self.create_time is None:
        self.create_time = ros_interface.msg.Time()
      if self.last_updated_time is None:
        self.last_updated_time = ros_interface.msg.Time()
      if self.center_pos_vehicle is None:
        self.center_pos_vehicle = ros_interface.msg.Point3D()
      if self.center_pos_abs is None:
        self.center_pos_abs = ros_interface.msg.Point3D()
      if self.velocity_vehicle is None:
        self.velocity_vehicle = ros_interface.msg.Point3D()
      if self.velocity_abs is None:
        self.velocity_abs = ros_interface.msg.Point3D()
      if self.image_key_points is None:
        self.image_key_points = None
      if self.polygon_point_abs is None:
        self.polygon_point_abs = None
      if self.polygon_point_vehicle is None:
        self.polygon_point_vehicle = None
      if self.drops is None:
        self.drops = None
      if self.acceleration_vehicle is None:
        self.acceleration_vehicle = ros_interface.msg.Point3D()
      if self.acceleration_abs is None:
        self.acceleration_abs = ros_interface.msg.Point3D()
      if self.anchor_point_image is None:
        self.anchor_point_image = ros_interface.msg.Point2D()
      if self.anchor_point_vehicle is None:
        self.anchor_point_vehicle = ros_interface.msg.Point3D()
      if self.anchor_point_abs is None:
        self.anchor_point_abs = ros_interface.msg.Point3D()
      if self.bbox2d is None:
        self.bbox2d = ros_interface.msg.BBox2D()
      if self.bbox2d_rear is None:
        self.bbox2d_rear = ros_interface.msg.BBox2D()
      if self.sensor_calibrator is None:
        self.sensor_calibrator = ros_interface.msg.SensorCalibrator()
      end = 0
      _x = self
      start = end
      end += 172
      (_x.timestamp.sec, _x.timestamp.nsec, _x.id, _x.existence_prob, _x.create_time.sec, _x.create_time.nsec, _x.last_updated_time.sec, _x.last_updated_time.nsec, _x.center_pos_vehicle.x, _x.center_pos_vehicle.y, _x.center_pos_vehicle.z, _x.center_pos_abs.x, _x.center_pos_abs.y, _x.center_pos_abs.z, _x.theta_vehicle, _x.theta_abs, _x.velocity_vehicle.x, _x.velocity_vehicle.y, _x.velocity_vehicle.z, _x.velocity_abs.x, _x.velocity_abs.y, _x.velocity_abs.z, _x.length, _x.width, _x.height,) = _get_struct_2Iid4I17d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.image_key_points = []
      for i in range(0, length):
        val1 = ros_interface.msg.ImageKeyPoint()
        _x = val1
        start = end
        end += 24
        (_x.x, _x.y, _x.confidence,) = _get_struct_3d().unpack(str[start:end])
        self.image_key_points.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.polygon_point_abs = []
      for i in range(0, length):
        val1 = ros_interface.msg.Point3D()
        _x = val1
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        self.polygon_point_abs.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.polygon_point_vehicle = []
      for i in range(0, length):
        val1 = ros_interface.msg.Point3D()
        _x = val1
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        self.polygon_point_vehicle.append(val1)
      _x = self
      start = end
      end += 24
      (_x.tracking_time, _x.type, _x.confidence, _x.confidence_type,) = _get_struct_didi().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.drops = []
      for i in range(0, length):
        val1 = ros_interface.msg.Point3D()
        _x = val1
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        self.drops.append(val1)
      _x = self
      start = end
      end += 140
      (_x.acceleration_vehicle.x, _x.acceleration_vehicle.y, _x.acceleration_vehicle.z, _x.acceleration_abs.x, _x.acceleration_abs.y, _x.acceleration_abs.z, _x.anchor_point_image.x, _x.anchor_point_image.y, _x.anchor_point_vehicle.x, _x.anchor_point_vehicle.y, _x.anchor_point_vehicle.z, _x.anchor_point_abs.x, _x.anchor_point_abs.y, _x.anchor_point_abs.z, _x.bbox2d.xmin, _x.bbox2d.ymin, _x.bbox2d.xmax, _x.bbox2d.ymax, _x.bbox2d_rear.xmin, _x.bbox2d_rear.ymin, _x.bbox2d_rear.xmax, _x.bbox2d_rear.ymax, _x.sub_type, _x.height_above_ground,) = _get_struct_14d8hid().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      s = struct.Struct(pattern)
      end += s.size
      self.position_abs_covariance = s.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      s = struct.Struct(pattern)
      end += s.size
      self.velocity_abs_covariance = s.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      s = struct.Struct(pattern)
      end += s.size
      self.acceleration_abs_covariance = s.unpack(str[start:end])
      start = end
      end += 8
      (self.theta_abs_covariance,) = _get_struct_d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      s = struct.Struct(pattern)
      end += s.size
      self.position_vehicle_covariance = s.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      s = struct.Struct(pattern)
      end += s.size
      self.velocity_vehicle_covariance = s.unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      s = struct.Struct(pattern)
      end += s.size
      self.acceleration_vehicle_covariance = s.unpack(str[start:end])
      _x = self
      start = end
      end += 77
      (_x.theta_vehicle_covariance, _x.sensor_calibrator.pose.x, _x.sensor_calibrator.pose.y, _x.sensor_calibrator.pose.z, _x.sensor_calibrator.angle.x, _x.sensor_calibrator.angle.y, _x.sensor_calibrator.angle.z, _x.cipv_flag, _x.lane_position, _x.pihp_percentage, _x.blinker_flag, _x.fusion_type,) = _get_struct_7dBid2i().unpack(str[start:end])
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
      buff.write(_get_struct_2Iid4I17d().pack(_x.timestamp.sec, _x.timestamp.nsec, _x.id, _x.existence_prob, _x.create_time.sec, _x.create_time.nsec, _x.last_updated_time.sec, _x.last_updated_time.nsec, _x.center_pos_vehicle.x, _x.center_pos_vehicle.y, _x.center_pos_vehicle.z, _x.center_pos_abs.x, _x.center_pos_abs.y, _x.center_pos_abs.z, _x.theta_vehicle, _x.theta_abs, _x.velocity_vehicle.x, _x.velocity_vehicle.y, _x.velocity_vehicle.z, _x.velocity_abs.x, _x.velocity_abs.y, _x.velocity_abs.z, _x.length, _x.width, _x.height))
      length = len(self.image_key_points)
      buff.write(_struct_I.pack(length))
      for val1 in self.image_key_points:
        _x = val1
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.confidence))
      length = len(self.polygon_point_abs)
      buff.write(_struct_I.pack(length))
      for val1 in self.polygon_point_abs:
        _x = val1
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
      length = len(self.polygon_point_vehicle)
      buff.write(_struct_I.pack(length))
      for val1 in self.polygon_point_vehicle:
        _x = val1
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
      _x = self
      buff.write(_get_struct_didi().pack(_x.tracking_time, _x.type, _x.confidence, _x.confidence_type))
      length = len(self.drops)
      buff.write(_struct_I.pack(length))
      for val1 in self.drops:
        _x = val1
        buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
      _x = self
      buff.write(_get_struct_14d8hid().pack(_x.acceleration_vehicle.x, _x.acceleration_vehicle.y, _x.acceleration_vehicle.z, _x.acceleration_abs.x, _x.acceleration_abs.y, _x.acceleration_abs.z, _x.anchor_point_image.x, _x.anchor_point_image.y, _x.anchor_point_vehicle.x, _x.anchor_point_vehicle.y, _x.anchor_point_vehicle.z, _x.anchor_point_abs.x, _x.anchor_point_abs.y, _x.anchor_point_abs.z, _x.bbox2d.xmin, _x.bbox2d.ymin, _x.bbox2d.xmax, _x.bbox2d.ymax, _x.bbox2d_rear.xmin, _x.bbox2d_rear.ymin, _x.bbox2d_rear.xmax, _x.bbox2d_rear.ymax, _x.sub_type, _x.height_above_ground))
      length = len(self.position_abs_covariance)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(self.position_abs_covariance.tostring())
      length = len(self.velocity_abs_covariance)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(self.velocity_abs_covariance.tostring())
      length = len(self.acceleration_abs_covariance)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(self.acceleration_abs_covariance.tostring())
      _x = self.theta_abs_covariance
      buff.write(_get_struct_d().pack(_x))
      length = len(self.position_vehicle_covariance)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(self.position_vehicle_covariance.tostring())
      length = len(self.velocity_vehicle_covariance)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(self.velocity_vehicle_covariance.tostring())
      length = len(self.acceleration_vehicle_covariance)
      buff.write(_struct_I.pack(length))
      pattern = '<%sd'%length
      buff.write(self.acceleration_vehicle_covariance.tostring())
      _x = self
      buff.write(_get_struct_7dBid2i().pack(_x.theta_vehicle_covariance, _x.sensor_calibrator.pose.x, _x.sensor_calibrator.pose.y, _x.sensor_calibrator.pose.z, _x.sensor_calibrator.angle.x, _x.sensor_calibrator.angle.y, _x.sensor_calibrator.angle.z, _x.cipv_flag, _x.lane_position, _x.pihp_percentage, _x.blinker_flag, _x.fusion_type))
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
      if self.timestamp is None:
        self.timestamp = ros_interface.msg.Time()
      if self.create_time is None:
        self.create_time = ros_interface.msg.Time()
      if self.last_updated_time is None:
        self.last_updated_time = ros_interface.msg.Time()
      if self.center_pos_vehicle is None:
        self.center_pos_vehicle = ros_interface.msg.Point3D()
      if self.center_pos_abs is None:
        self.center_pos_abs = ros_interface.msg.Point3D()
      if self.velocity_vehicle is None:
        self.velocity_vehicle = ros_interface.msg.Point3D()
      if self.velocity_abs is None:
        self.velocity_abs = ros_interface.msg.Point3D()
      if self.image_key_points is None:
        self.image_key_points = None
      if self.polygon_point_abs is None:
        self.polygon_point_abs = None
      if self.polygon_point_vehicle is None:
        self.polygon_point_vehicle = None
      if self.drops is None:
        self.drops = None
      if self.acceleration_vehicle is None:
        self.acceleration_vehicle = ros_interface.msg.Point3D()
      if self.acceleration_abs is None:
        self.acceleration_abs = ros_interface.msg.Point3D()
      if self.anchor_point_image is None:
        self.anchor_point_image = ros_interface.msg.Point2D()
      if self.anchor_point_vehicle is None:
        self.anchor_point_vehicle = ros_interface.msg.Point3D()
      if self.anchor_point_abs is None:
        self.anchor_point_abs = ros_interface.msg.Point3D()
      if self.bbox2d is None:
        self.bbox2d = ros_interface.msg.BBox2D()
      if self.bbox2d_rear is None:
        self.bbox2d_rear = ros_interface.msg.BBox2D()
      if self.sensor_calibrator is None:
        self.sensor_calibrator = ros_interface.msg.SensorCalibrator()
      end = 0
      _x = self
      start = end
      end += 172
      (_x.timestamp.sec, _x.timestamp.nsec, _x.id, _x.existence_prob, _x.create_time.sec, _x.create_time.nsec, _x.last_updated_time.sec, _x.last_updated_time.nsec, _x.center_pos_vehicle.x, _x.center_pos_vehicle.y, _x.center_pos_vehicle.z, _x.center_pos_abs.x, _x.center_pos_abs.y, _x.center_pos_abs.z, _x.theta_vehicle, _x.theta_abs, _x.velocity_vehicle.x, _x.velocity_vehicle.y, _x.velocity_vehicle.z, _x.velocity_abs.x, _x.velocity_abs.y, _x.velocity_abs.z, _x.length, _x.width, _x.height,) = _get_struct_2Iid4I17d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.image_key_points = []
      for i in range(0, length):
        val1 = ros_interface.msg.ImageKeyPoint()
        _x = val1
        start = end
        end += 24
        (_x.x, _x.y, _x.confidence,) = _get_struct_3d().unpack(str[start:end])
        self.image_key_points.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.polygon_point_abs = []
      for i in range(0, length):
        val1 = ros_interface.msg.Point3D()
        _x = val1
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        self.polygon_point_abs.append(val1)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.polygon_point_vehicle = []
      for i in range(0, length):
        val1 = ros_interface.msg.Point3D()
        _x = val1
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        self.polygon_point_vehicle.append(val1)
      _x = self
      start = end
      end += 24
      (_x.tracking_time, _x.type, _x.confidence, _x.confidence_type,) = _get_struct_didi().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.drops = []
      for i in range(0, length):
        val1 = ros_interface.msg.Point3D()
        _x = val1
        start = end
        end += 24
        (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
        self.drops.append(val1)
      _x = self
      start = end
      end += 140
      (_x.acceleration_vehicle.x, _x.acceleration_vehicle.y, _x.acceleration_vehicle.z, _x.acceleration_abs.x, _x.acceleration_abs.y, _x.acceleration_abs.z, _x.anchor_point_image.x, _x.anchor_point_image.y, _x.anchor_point_vehicle.x, _x.anchor_point_vehicle.y, _x.anchor_point_vehicle.z, _x.anchor_point_abs.x, _x.anchor_point_abs.y, _x.anchor_point_abs.z, _x.bbox2d.xmin, _x.bbox2d.ymin, _x.bbox2d.xmax, _x.bbox2d.ymax, _x.bbox2d_rear.xmin, _x.bbox2d_rear.ymin, _x.bbox2d_rear.xmax, _x.bbox2d_rear.ymax, _x.sub_type, _x.height_above_ground,) = _get_struct_14d8hid().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      s = struct.Struct(pattern)
      end += s.size
      self.position_abs_covariance = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=length)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      s = struct.Struct(pattern)
      end += s.size
      self.velocity_abs_covariance = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=length)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      s = struct.Struct(pattern)
      end += s.size
      self.acceleration_abs_covariance = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=length)
      start = end
      end += 8
      (self.theta_abs_covariance,) = _get_struct_d().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      s = struct.Struct(pattern)
      end += s.size
      self.position_vehicle_covariance = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=length)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      s = struct.Struct(pattern)
      end += s.size
      self.velocity_vehicle_covariance = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=length)
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      pattern = '<%sd'%length
      start = end
      s = struct.Struct(pattern)
      end += s.size
      self.acceleration_vehicle_covariance = numpy.frombuffer(str[start:end], dtype=numpy.float64, count=length)
      _x = self
      start = end
      end += 77
      (_x.theta_vehicle_covariance, _x.sensor_calibrator.pose.x, _x.sensor_calibrator.pose.y, _x.sensor_calibrator.pose.z, _x.sensor_calibrator.angle.x, _x.sensor_calibrator.angle.y, _x.sensor_calibrator.angle.z, _x.cipv_flag, _x.lane_position, _x.pihp_percentage, _x.blinker_flag, _x.fusion_type,) = _get_struct_7dBid2i().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_14d8hid = None
def _get_struct_14d8hid():
    global _struct_14d8hid
    if _struct_14d8hid is None:
        _struct_14d8hid = struct.Struct("<14d8hid")
    return _struct_14d8hid
_struct_2Iid4I17d = None
def _get_struct_2Iid4I17d():
    global _struct_2Iid4I17d
    if _struct_2Iid4I17d is None:
        _struct_2Iid4I17d = struct.Struct("<2Iid4I17d")
    return _struct_2Iid4I17d
_struct_3d = None
def _get_struct_3d():
    global _struct_3d
    if _struct_3d is None:
        _struct_3d = struct.Struct("<3d")
    return _struct_3d
_struct_7dBid2i = None
def _get_struct_7dBid2i():
    global _struct_7dBid2i
    if _struct_7dBid2i is None:
        _struct_7dBid2i = struct.Struct("<7dBid2i")
    return _struct_7dBid2i
_struct_d = None
def _get_struct_d():
    global _struct_d
    if _struct_d is None:
        _struct_d = struct.Struct("<d")
    return _struct_d
_struct_didi = None
def _get_struct_didi():
    global _struct_didi
    if _struct_didi is None:
        _struct_didi = struct.Struct("<didi")
    return _struct_didi
