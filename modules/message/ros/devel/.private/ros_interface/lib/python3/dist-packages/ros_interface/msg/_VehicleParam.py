# This Python file uses the following encoding: utf-8
"""autogenerated by genpy from ros_interface/VehicleParam.msg. Do not edit."""
import codecs
import sys
python3 = True if sys.hexversion > 0x03000000 else False
import genpy
import struct


class VehicleParam(genpy.Message):
  _md5sum = "af312f82f3e9c18a66abf5e713a2f676"
  _type = "ros_interface/VehicleParam"
  _has_header = False  # flag to mark the presence of a Header object
  _full_text = """string   brand     #  
int32   steer_mode     #  
float64   length     #  
float64   width     #  
float64   height     #  
float64   mass_fl     #  
float64   mass_fr     #  
float64   mass_rl     #  
float64   mass_rr     #  
float64   wheel_radius     #  
float64   wheelbase     #  
float64   front_edge_to_center     #  
float64   back_edge_to_center     #  
float64   lf     #  
float64   lr     #  
float64   cf     #  
float64   cr     #  
float64   steer_ratio     #  
float64   rolling_coefficient     #  
float64   air_density     #  
float64   air_damping_coefficient     #  
float64   max_front_steer_angle     #  
float64   min_front_steer_angle     #  
float64   max_rear_steer_angle     #  
float64   min_rear_steer_angle     #  
float64   speed_limit     #  
float64   max_brake_value     #  
float64   min_brake_value     #  
float64   max_accel_value     #  
float64   min_accel_value     #  
float64   speed_deadzone     #  
float64   standstill_acceleration     #  
float64   max_front_steer_angle_rate     #  
float64   max_rear_steer_angle_rate     #  
float64   max_abs_speed_when_stopped     #  
float64   max_abs_speed_when_stopped_duration     #  
float64   brake_value_when_gear_transitioning     #  
float64   accel_deadzone     #  
float64   brake_deadzone     #  
float64   acceleration_in_idle     #  
float64   deceleration_in_idle     #  
float64   max_acceleration_jerk     #  
float64   max_acceleration     #  
float64   max_deceleration     #  
float64   min_turning_radius     #  
"""
  __slots__ = ['brand','steer_mode','length','width','height','mass_fl','mass_fr','mass_rl','mass_rr','wheel_radius','wheelbase','front_edge_to_center','back_edge_to_center','lf','lr','cf','cr','steer_ratio','rolling_coefficient','air_density','air_damping_coefficient','max_front_steer_angle','min_front_steer_angle','max_rear_steer_angle','min_rear_steer_angle','speed_limit','max_brake_value','min_brake_value','max_accel_value','min_accel_value','speed_deadzone','standstill_acceleration','max_front_steer_angle_rate','max_rear_steer_angle_rate','max_abs_speed_when_stopped','max_abs_speed_when_stopped_duration','brake_value_when_gear_transitioning','accel_deadzone','brake_deadzone','acceleration_in_idle','deceleration_in_idle','max_acceleration_jerk','max_acceleration','max_deceleration','min_turning_radius']
  _slot_types = ['string','int32','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64','float64']

  def __init__(self, *args, **kwds):
    """
    Constructor. Any message fields that are implicitly/explicitly
    set to None will be assigned a default value. The recommend
    use is keyword arguments as this is more robust to future message
    changes.  You cannot mix in-order arguments and keyword arguments.

    The available fields are:
       brand,steer_mode,length,width,height,mass_fl,mass_fr,mass_rl,mass_rr,wheel_radius,wheelbase,front_edge_to_center,back_edge_to_center,lf,lr,cf,cr,steer_ratio,rolling_coefficient,air_density,air_damping_coefficient,max_front_steer_angle,min_front_steer_angle,max_rear_steer_angle,min_rear_steer_angle,speed_limit,max_brake_value,min_brake_value,max_accel_value,min_accel_value,speed_deadzone,standstill_acceleration,max_front_steer_angle_rate,max_rear_steer_angle_rate,max_abs_speed_when_stopped,max_abs_speed_when_stopped_duration,brake_value_when_gear_transitioning,accel_deadzone,brake_deadzone,acceleration_in_idle,deceleration_in_idle,max_acceleration_jerk,max_acceleration,max_deceleration,min_turning_radius

    :param args: complete set of field values, in .msg order
    :param kwds: use keyword arguments corresponding to message field names
    to set specific fields.
    """
    if args or kwds:
      super(VehicleParam, self).__init__(*args, **kwds)
      # message fields cannot be None, assign default values for those that are
      if self.brand is None:
        self.brand = ''
      if self.steer_mode is None:
        self.steer_mode = 0
      if self.length is None:
        self.length = 0.
      if self.width is None:
        self.width = 0.
      if self.height is None:
        self.height = 0.
      if self.mass_fl is None:
        self.mass_fl = 0.
      if self.mass_fr is None:
        self.mass_fr = 0.
      if self.mass_rl is None:
        self.mass_rl = 0.
      if self.mass_rr is None:
        self.mass_rr = 0.
      if self.wheel_radius is None:
        self.wheel_radius = 0.
      if self.wheelbase is None:
        self.wheelbase = 0.
      if self.front_edge_to_center is None:
        self.front_edge_to_center = 0.
      if self.back_edge_to_center is None:
        self.back_edge_to_center = 0.
      if self.lf is None:
        self.lf = 0.
      if self.lr is None:
        self.lr = 0.
      if self.cf is None:
        self.cf = 0.
      if self.cr is None:
        self.cr = 0.
      if self.steer_ratio is None:
        self.steer_ratio = 0.
      if self.rolling_coefficient is None:
        self.rolling_coefficient = 0.
      if self.air_density is None:
        self.air_density = 0.
      if self.air_damping_coefficient is None:
        self.air_damping_coefficient = 0.
      if self.max_front_steer_angle is None:
        self.max_front_steer_angle = 0.
      if self.min_front_steer_angle is None:
        self.min_front_steer_angle = 0.
      if self.max_rear_steer_angle is None:
        self.max_rear_steer_angle = 0.
      if self.min_rear_steer_angle is None:
        self.min_rear_steer_angle = 0.
      if self.speed_limit is None:
        self.speed_limit = 0.
      if self.max_brake_value is None:
        self.max_brake_value = 0.
      if self.min_brake_value is None:
        self.min_brake_value = 0.
      if self.max_accel_value is None:
        self.max_accel_value = 0.
      if self.min_accel_value is None:
        self.min_accel_value = 0.
      if self.speed_deadzone is None:
        self.speed_deadzone = 0.
      if self.standstill_acceleration is None:
        self.standstill_acceleration = 0.
      if self.max_front_steer_angle_rate is None:
        self.max_front_steer_angle_rate = 0.
      if self.max_rear_steer_angle_rate is None:
        self.max_rear_steer_angle_rate = 0.
      if self.max_abs_speed_when_stopped is None:
        self.max_abs_speed_when_stopped = 0.
      if self.max_abs_speed_when_stopped_duration is None:
        self.max_abs_speed_when_stopped_duration = 0.
      if self.brake_value_when_gear_transitioning is None:
        self.brake_value_when_gear_transitioning = 0.
      if self.accel_deadzone is None:
        self.accel_deadzone = 0.
      if self.brake_deadzone is None:
        self.brake_deadzone = 0.
      if self.acceleration_in_idle is None:
        self.acceleration_in_idle = 0.
      if self.deceleration_in_idle is None:
        self.deceleration_in_idle = 0.
      if self.max_acceleration_jerk is None:
        self.max_acceleration_jerk = 0.
      if self.max_acceleration is None:
        self.max_acceleration = 0.
      if self.max_deceleration is None:
        self.max_deceleration = 0.
      if self.min_turning_radius is None:
        self.min_turning_radius = 0.
    else:
      self.brand = ''
      self.steer_mode = 0
      self.length = 0.
      self.width = 0.
      self.height = 0.
      self.mass_fl = 0.
      self.mass_fr = 0.
      self.mass_rl = 0.
      self.mass_rr = 0.
      self.wheel_radius = 0.
      self.wheelbase = 0.
      self.front_edge_to_center = 0.
      self.back_edge_to_center = 0.
      self.lf = 0.
      self.lr = 0.
      self.cf = 0.
      self.cr = 0.
      self.steer_ratio = 0.
      self.rolling_coefficient = 0.
      self.air_density = 0.
      self.air_damping_coefficient = 0.
      self.max_front_steer_angle = 0.
      self.min_front_steer_angle = 0.
      self.max_rear_steer_angle = 0.
      self.min_rear_steer_angle = 0.
      self.speed_limit = 0.
      self.max_brake_value = 0.
      self.min_brake_value = 0.
      self.max_accel_value = 0.
      self.min_accel_value = 0.
      self.speed_deadzone = 0.
      self.standstill_acceleration = 0.
      self.max_front_steer_angle_rate = 0.
      self.max_rear_steer_angle_rate = 0.
      self.max_abs_speed_when_stopped = 0.
      self.max_abs_speed_when_stopped_duration = 0.
      self.brake_value_when_gear_transitioning = 0.
      self.accel_deadzone = 0.
      self.brake_deadzone = 0.
      self.acceleration_in_idle = 0.
      self.deceleration_in_idle = 0.
      self.max_acceleration_jerk = 0.
      self.max_acceleration = 0.
      self.max_deceleration = 0.
      self.min_turning_radius = 0.

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
      _x = self.brand
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_i43d().pack(_x.steer_mode, _x.length, _x.width, _x.height, _x.mass_fl, _x.mass_fr, _x.mass_rl, _x.mass_rr, _x.wheel_radius, _x.wheelbase, _x.front_edge_to_center, _x.back_edge_to_center, _x.lf, _x.lr, _x.cf, _x.cr, _x.steer_ratio, _x.rolling_coefficient, _x.air_density, _x.air_damping_coefficient, _x.max_front_steer_angle, _x.min_front_steer_angle, _x.max_rear_steer_angle, _x.min_rear_steer_angle, _x.speed_limit, _x.max_brake_value, _x.min_brake_value, _x.max_accel_value, _x.min_accel_value, _x.speed_deadzone, _x.standstill_acceleration, _x.max_front_steer_angle_rate, _x.max_rear_steer_angle_rate, _x.max_abs_speed_when_stopped, _x.max_abs_speed_when_stopped_duration, _x.brake_value_when_gear_transitioning, _x.accel_deadzone, _x.brake_deadzone, _x.acceleration_in_idle, _x.deceleration_in_idle, _x.max_acceleration_jerk, _x.max_acceleration, _x.max_deceleration, _x.min_turning_radius))
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
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.brand = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.brand = str[start:end]
      _x = self
      start = end
      end += 348
      (_x.steer_mode, _x.length, _x.width, _x.height, _x.mass_fl, _x.mass_fr, _x.mass_rl, _x.mass_rr, _x.wheel_radius, _x.wheelbase, _x.front_edge_to_center, _x.back_edge_to_center, _x.lf, _x.lr, _x.cf, _x.cr, _x.steer_ratio, _x.rolling_coefficient, _x.air_density, _x.air_damping_coefficient, _x.max_front_steer_angle, _x.min_front_steer_angle, _x.max_rear_steer_angle, _x.min_rear_steer_angle, _x.speed_limit, _x.max_brake_value, _x.min_brake_value, _x.max_accel_value, _x.min_accel_value, _x.speed_deadzone, _x.standstill_acceleration, _x.max_front_steer_angle_rate, _x.max_rear_steer_angle_rate, _x.max_abs_speed_when_stopped, _x.max_abs_speed_when_stopped_duration, _x.brake_value_when_gear_transitioning, _x.accel_deadzone, _x.brake_deadzone, _x.acceleration_in_idle, _x.deceleration_in_idle, _x.max_acceleration_jerk, _x.max_acceleration, _x.max_deceleration, _x.min_turning_radius,) = _get_struct_i43d().unpack(str[start:end])
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
      _x = self.brand
      length = len(_x)
      if python3 or type(_x) == unicode:
        _x = _x.encode('utf-8')
        length = len(_x)
      buff.write(struct.Struct('<I%ss'%length).pack(length, _x))
      _x = self
      buff.write(_get_struct_i43d().pack(_x.steer_mode, _x.length, _x.width, _x.height, _x.mass_fl, _x.mass_fr, _x.mass_rl, _x.mass_rr, _x.wheel_radius, _x.wheelbase, _x.front_edge_to_center, _x.back_edge_to_center, _x.lf, _x.lr, _x.cf, _x.cr, _x.steer_ratio, _x.rolling_coefficient, _x.air_density, _x.air_damping_coefficient, _x.max_front_steer_angle, _x.min_front_steer_angle, _x.max_rear_steer_angle, _x.min_rear_steer_angle, _x.speed_limit, _x.max_brake_value, _x.min_brake_value, _x.max_accel_value, _x.min_accel_value, _x.speed_deadzone, _x.standstill_acceleration, _x.max_front_steer_angle_rate, _x.max_rear_steer_angle_rate, _x.max_abs_speed_when_stopped, _x.max_abs_speed_when_stopped_duration, _x.brake_value_when_gear_transitioning, _x.accel_deadzone, _x.brake_deadzone, _x.acceleration_in_idle, _x.deceleration_in_idle, _x.max_acceleration_jerk, _x.max_acceleration, _x.max_deceleration, _x.min_turning_radius))
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
      start = end
      end += 4
      (length,) = _struct_I.unpack(str[start:end])
      start = end
      end += length
      if python3:
        self.brand = str[start:end].decode('utf-8', 'rosmsg')
      else:
        self.brand = str[start:end]
      _x = self
      start = end
      end += 348
      (_x.steer_mode, _x.length, _x.width, _x.height, _x.mass_fl, _x.mass_fr, _x.mass_rl, _x.mass_rr, _x.wheel_radius, _x.wheelbase, _x.front_edge_to_center, _x.back_edge_to_center, _x.lf, _x.lr, _x.cf, _x.cr, _x.steer_ratio, _x.rolling_coefficient, _x.air_density, _x.air_damping_coefficient, _x.max_front_steer_angle, _x.min_front_steer_angle, _x.max_rear_steer_angle, _x.min_rear_steer_angle, _x.speed_limit, _x.max_brake_value, _x.min_brake_value, _x.max_accel_value, _x.min_accel_value, _x.speed_deadzone, _x.standstill_acceleration, _x.max_front_steer_angle_rate, _x.max_rear_steer_angle_rate, _x.max_abs_speed_when_stopped, _x.max_abs_speed_when_stopped_duration, _x.brake_value_when_gear_transitioning, _x.accel_deadzone, _x.brake_deadzone, _x.acceleration_in_idle, _x.deceleration_in_idle, _x.max_acceleration_jerk, _x.max_acceleration, _x.max_deceleration, _x.min_turning_radius,) = _get_struct_i43d().unpack(str[start:end])
      return self
    except struct.error as e:
      raise genpy.DeserializationError(e)  # most likely buffer underfill

_struct_I = genpy.struct_I
def _get_struct_I():
    global _struct_I
    return _struct_I
_struct_i43d = None
def _get_struct_i43d():
    global _struct_i43d
    if _struct_i43d is None:
        _struct_i43d = struct.Struct("<i43d")
    return _struct_i43d
