# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ros_interface/HolisticPathPrediction.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct

import ros_interface.msg

class HolisticPathPrediction(genpy.Message):
  _md5sum = "4a3802277f8181f1f0dd82eebaecee41"
  _type = "ros_interface/HolisticPathPrediction"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """LaneLineCubicCurve   hpp     # 行驶路径预测： 1、针对没有车道线等特殊路段如：收费站附近、进出匝道附近、 维修区域附近，可以虚拟出可行驶路径预测； 2、针对车辆遮挡的区域，可以虚拟出可行驶路径预测；
int32   planning_source     # 规划路径来源:  0 - invalid,  1 - 双侧车道线,  2 - 左侧车道线,  3 - 右侧车道线, 4 - 左侧路沿，  5 - 右侧路沿， 6 - 前车轨迹，  7 - freespace, 8 - 本车轨迹预测
float64   ego_lane_width     # 自车道宽度
float64   confidence     # 置信度[0 - 1]

================================================================================
MSG: ros_interface/LaneLineCubicCurve
float64   start_x     # 车道线起始位置
float64   end_x     # 车道线结束位置
float64   a     # 三次曲线系数
float64   b     #  
float64   c     #  
float64   d     #  
"""
  __slots__ = ['hpp','planning_source','ego_lane_width','confidence']
  _slot_types = ['ros_interface/LaneLineCubicCurve','int32','float64','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       hpp,planning_source,ego_lane_width,confidence

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(HolisticPathPrediction, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.hpp is None:
        self.hpp = ros_interface.msg.LaneLineCubicCurve()
      if self.planning_source is None:
        self.planning_source = 0
      if self.ego_lane_width is None:
        self.ego_lane_width = 0.
      if self.confidence is None:
        self.confidence = 0.
    else:
      self.hpp = ros_interface.msg.LaneLineCubicCurve()
      self.planning_source = 0
      self.ego_lane_width = 0.
      self.confidence = 0.

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
      buff.write(_get_struct_6di2d().pack(_x.hpp.start_x, _x.hpp.end_x, _x.hpp.a, _x.hpp.b, _x.hpp.c, _x.hpp.d, _x.planning_source, _x.ego_lane_width, _x.confidence))
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
      if self.hpp is None:
        self.hpp = ros_interface.msg.LaneLineCubicCurve()
      end = 0
      _x = self
      start = end
      end += 68
      (_x.hpp.start_x, _x.hpp.end_x, _x.hpp.a, _x.hpp.b, _x.hpp.c, _x.hpp.d, _x.planning_source, _x.ego_lane_width, _x.confidence,) = _get_struct_6di2d().unpack(str[start:end])
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
      buff.write(_get_struct_6di2d().pack(_x.hpp.start_x, _x.hpp.end_x, _x.hpp.a, _x.hpp.b, _x.hpp.c, _x.hpp.d, _x.planning_source, _x.ego_lane_width, _x.confidence))
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
      if self.hpp is None:
        self.hpp = ros_interface.msg.LaneLineCubicCurve()
      end = 0
      _x = self
      start = end
      end += 68
      (_x.hpp.start_x, _x.hpp.end_x, _x.hpp.a, _x.hpp.b, _x.hpp.c, _x.hpp.d, _x.planning_source, _x.ego_lane_width, _x.confidence,) = _get_struct_6di2d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_6di2d = None
def _get_struct_6di2d():
    global _struct_6di2d
    if _struct_6di2d is None:
        _struct_6di2d = struct.Struct("<6di2d")
    return _struct_6di2d
