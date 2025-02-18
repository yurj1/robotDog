# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ros_interface/RoutingResponse.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import ros_interface.msg
import std_msgs.msg

class RoutingResponse(genpy.Message):
  _md5sum = "15cd52a06ebf7f4a70dca47308a3032d"
  _type = "ros_interface/RoutingResponse"
  _has_header = True  # flag to mark the presence of a Header object
  _full_text = """Header   header     # timestamp is included in header
int32   plan_status     # 规划结果状态
int32   replan_flag     # REPLAN_FLAG_NONE=0  //不需要重规划 REPLAN_FLAG_NAVI=1 //网络层重规划 REPLAN_FLAG_HUMAN=2 //人为重规划
int32   route_reason     # 规划原因 ROUTE_REASON_HMI = 0 //hmi上触发规划 ROUTE_REASON_PLATOON_HEADER = 1 //车队头车下发规划 ROUTE_REASON_PLATOON_OTHER = 2 //车队其他车辆下发规划
LaneInfo[] lane_list # 分段路径规划结果

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
MSG: ros_interface/LaneInfo
int8   priority     # 道路优先级
int8   global_id     # 道路全局id（从左至右，从0开始）
int8   predecessor_id     # 上一车道id
int8   successor_id     # 下一车道id
int8   left_neighbor_id     # 左边相邻车道id
int8   right_neighbor_id     # 右边相邻车道id
int8   type     # 类型（预留）
LanePoint[] lane_points # 道路参考线（z）

================================================================================
MSG: ros_interface/LanePoint
Point3D   point     # 点xyz
float64   theta     # 方向（与东方向夹角，逆时针方向为正，单位为弧度）
float64   mileage     # 总体里程
float64   limit_speed     # 地图限速（单位m/s）
float64   left_road_width     # 左边车道宽
float64   right_road_width     # 右边车道宽
int32   left_line_type     # 左边车线线型
int32   right_line_type     # 右边车线线型

================================================================================
MSG: ros_interface/Point3D
float64   x     # 位置坐标x
float64   y     # 位置坐标y
float64   z     # 位置坐标z
"""
  __slots__ = ['header','plan_status','replan_flag','route_reason','lane_list']
  _slot_types = ['std_msgs/Header','int32','int32','int32','ros_interface/LaneInfo[]']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       header,plan_status,replan_flag,route_reason,lane_list

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(RoutingResponse, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.header is None:
        self.header = std_msgs.msg.Header()
      if self.plan_status is None:
        self.plan_status = 0
      if self.replan_flag is None:
        self.replan_flag = 0
      if self.route_reason is None:
        self.route_reason = 0
      if self.lane_list is None:
        self.lane_list = []
    else:
      self.header = std_msgs.msg.Header()
      self.plan_status = 0
      self.replan_flag = 0
      self.route_reason = 0
      self.lane_list = []

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
      buff.write(_get_struct_3i().pack(_x.plan_status, _x.replan_flag, _x.route_reason))
      length = len(self.lane_list)
      buff.write(_struct_I.pack(length))
      for val1 in self.lane_list:
        _x = val1
        buff.write(_get_struct_7b().pack(_x.priority, _x.global_id, _x.predecessor_id, _x.successor_id, _x.left_neighbor_id, _x.right_neighbor_id, _x.type))
        length = len(val1.lane_points)
        buff.write(_struct_I.pack(length))
        for val2 in val1.lane_points:
          _v1 = val2.point
          _x = _v1
          buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
          _x = val2
          buff.write(_get_struct_5d2i().pack(_x.theta, _x.mileage, _x.limit_speed, _x.left_road_width, _x.right_road_width, _x.left_line_type, _x.right_line_type))
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
      if self.lane_list is None:
        self.lane_list = None
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
      end += 12
      (_x.plan_status, _x.replan_flag, _x.route_reason,) = _get_struct_3i().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.lane_list = []
      for i in range(0, length):
        val1 = ros_interface.msg.LaneInfo()
        _x = val1
        start = end
        end += 7
        (_x.priority, _x.global_id, _x.predecessor_id, _x.successor_id, _x.left_neighbor_id, _x.right_neighbor_id, _x.type,) = _get_struct_7b().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        val1.lane_points = []
        for i in range(0, length):
          val2 = ros_interface.msg.LanePoint()
          _v2 = val2.point
          _x = _v2
          start = end
          end += 24
          (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
          _x = val2
          start = end
          end += 48
          (_x.theta, _x.mileage, _x.limit_speed, _x.left_road_width, _x.right_road_width, _x.left_line_type, _x.right_line_type,) = _get_struct_5d2i().unpack(str[start:end])
          val1.lane_points.append(val2)
        self.lane_list.append(val1)
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
      buff.write(_get_struct_3i().pack(_x.plan_status, _x.replan_flag, _x.route_reason))
      length = len(self.lane_list)
      buff.write(_struct_I.pack(length))
      for val1 in self.lane_list:
        _x = val1
        buff.write(_get_struct_7b().pack(_x.priority, _x.global_id, _x.predecessor_id, _x.successor_id, _x.left_neighbor_id, _x.right_neighbor_id, _x.type))
        length = len(val1.lane_points)
        buff.write(_struct_I.pack(length))
        for val2 in val1.lane_points:
          _v3 = val2.point
          _x = _v3
          buff.write(_get_struct_3d().pack(_x.x, _x.y, _x.z))
          _x = val2
          buff.write(_get_struct_5d2i().pack(_x.theta, _x.mileage, _x.limit_speed, _x.left_road_width, _x.right_road_width, _x.left_line_type, _x.right_line_type))
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
      if self.lane_list is None:
        self.lane_list = None
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
      end += 12
      (_x.plan_status, _x.replan_flag, _x.route_reason,) = _get_struct_3i().unpack(str[start:end])
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      self.lane_list = []
      for i in range(0, length):
        val1 = ros_interface.msg.LaneInfo()
        _x = val1
        start = end
        end += 7
        (_x.priority, _x.global_id, _x.predecessor_id, _x.successor_id, _x.left_neighbor_id, _x.right_neighbor_id, _x.type,) = _get_struct_7b().unpack(str[start:end])
        start = end
        end += 4
        (length,) = _struct_I.unpack(str[start:end])
        val1.lane_points = []
        for i in range(0, length):
          val2 = ros_interface.msg.LanePoint()
          _v4 = val2.point
          _x = _v4
          start = end
          end += 24
          (_x.x, _x.y, _x.z,) = _get_struct_3d().unpack(str[start:end])
          _x = val2
          start = end
          end += 48
          (_x.theta, _x.mileage, _x.limit_speed, _x.left_road_width, _x.right_road_width, _x.left_line_type, _x.right_line_type,) = _get_struct_5d2i().unpack(str[start:end])
          val1.lane_points.append(val2)
        self.lane_list.append(val1)
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
_struct_3i = None
def _get_struct_3i():
    global _struct_3i
    if _struct_3i is None:
        _struct_3i = struct.Struct("<3i")
    return _struct_3i
_struct_5d2i = None
def _get_struct_5d2i():
    global _struct_5d2i
    if _struct_5d2i is None:
        _struct_5d2i = struct.Struct("<5d2i")
    return _struct_5d2i
_struct_7b = None
def _get_struct_7b():
    global _struct_7b
    if _struct_7b is None:
        _struct_7b = struct.Struct("<7b")
    return _struct_7b
