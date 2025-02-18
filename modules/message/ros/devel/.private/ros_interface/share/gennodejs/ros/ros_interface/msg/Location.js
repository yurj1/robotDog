// Auto-generated. Do not edit!

// (in-package ros_interface.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let PointLLH = require('./PointLLH.js');
let Point3D = require('./Point3D.js');
let PointENU = require('./PointENU.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class Location {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.position = null;
      this.pitch = null;
      this.roll = null;
      this.heading = null;
      this.linear_velocity = null;
      this.linear_acceleration = null;
      this.angular_velocity = null;
      this.rtk_flag = null;
      this.odom_type = null;
      this.auxiliary_type = null;
      this.location_valid_flag = null;
      this.origin_lat = null;
      this.origin_lon = null;
      this.utm_position = null;
      this.change_origin_flag = null;
      this.utm_position_next = null;
      this.position_std_dev = null;
      this.orientation_std_dev = null;
      this.linear_velocity_std_dev = null;
      this.linear_acceleration_std_dev = null;
      this.angular_velocity_std_dev = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('position')) {
        this.position = initObj.position
      }
      else {
        this.position = new PointLLH();
      }
      if (initObj.hasOwnProperty('pitch')) {
        this.pitch = initObj.pitch
      }
      else {
        this.pitch = 0.0;
      }
      if (initObj.hasOwnProperty('roll')) {
        this.roll = initObj.roll
      }
      else {
        this.roll = 0.0;
      }
      if (initObj.hasOwnProperty('heading')) {
        this.heading = initObj.heading
      }
      else {
        this.heading = 0.0;
      }
      if (initObj.hasOwnProperty('linear_velocity')) {
        this.linear_velocity = initObj.linear_velocity
      }
      else {
        this.linear_velocity = new Point3D();
      }
      if (initObj.hasOwnProperty('linear_acceleration')) {
        this.linear_acceleration = initObj.linear_acceleration
      }
      else {
        this.linear_acceleration = new Point3D();
      }
      if (initObj.hasOwnProperty('angular_velocity')) {
        this.angular_velocity = initObj.angular_velocity
      }
      else {
        this.angular_velocity = new Point3D();
      }
      if (initObj.hasOwnProperty('rtk_flag')) {
        this.rtk_flag = initObj.rtk_flag
      }
      else {
        this.rtk_flag = 0;
      }
      if (initObj.hasOwnProperty('odom_type')) {
        this.odom_type = initObj.odom_type
      }
      else {
        this.odom_type = 0;
      }
      if (initObj.hasOwnProperty('auxiliary_type')) {
        this.auxiliary_type = initObj.auxiliary_type
      }
      else {
        this.auxiliary_type = 0;
      }
      if (initObj.hasOwnProperty('location_valid_flag')) {
        this.location_valid_flag = initObj.location_valid_flag
      }
      else {
        this.location_valid_flag = 0;
      }
      if (initObj.hasOwnProperty('origin_lat')) {
        this.origin_lat = initObj.origin_lat
      }
      else {
        this.origin_lat = 0.0;
      }
      if (initObj.hasOwnProperty('origin_lon')) {
        this.origin_lon = initObj.origin_lon
      }
      else {
        this.origin_lon = 0.0;
      }
      if (initObj.hasOwnProperty('utm_position')) {
        this.utm_position = initObj.utm_position
      }
      else {
        this.utm_position = new PointENU();
      }
      if (initObj.hasOwnProperty('change_origin_flag')) {
        this.change_origin_flag = initObj.change_origin_flag
      }
      else {
        this.change_origin_flag = 0;
      }
      if (initObj.hasOwnProperty('utm_position_next')) {
        this.utm_position_next = initObj.utm_position_next
      }
      else {
        this.utm_position_next = new PointENU();
      }
      if (initObj.hasOwnProperty('position_std_dev')) {
        this.position_std_dev = initObj.position_std_dev
      }
      else {
        this.position_std_dev = new Point3D();
      }
      if (initObj.hasOwnProperty('orientation_std_dev')) {
        this.orientation_std_dev = initObj.orientation_std_dev
      }
      else {
        this.orientation_std_dev = new Point3D();
      }
      if (initObj.hasOwnProperty('linear_velocity_std_dev')) {
        this.linear_velocity_std_dev = initObj.linear_velocity_std_dev
      }
      else {
        this.linear_velocity_std_dev = new Point3D();
      }
      if (initObj.hasOwnProperty('linear_acceleration_std_dev')) {
        this.linear_acceleration_std_dev = initObj.linear_acceleration_std_dev
      }
      else {
        this.linear_acceleration_std_dev = new Point3D();
      }
      if (initObj.hasOwnProperty('angular_velocity_std_dev')) {
        this.angular_velocity_std_dev = initObj.angular_velocity_std_dev
      }
      else {
        this.angular_velocity_std_dev = new Point3D();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Location
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [position]
    bufferOffset = PointLLH.serialize(obj.position, buffer, bufferOffset);
    // Serialize message field [pitch]
    bufferOffset = _serializer.float64(obj.pitch, buffer, bufferOffset);
    // Serialize message field [roll]
    bufferOffset = _serializer.float64(obj.roll, buffer, bufferOffset);
    // Serialize message field [heading]
    bufferOffset = _serializer.float64(obj.heading, buffer, bufferOffset);
    // Serialize message field [linear_velocity]
    bufferOffset = Point3D.serialize(obj.linear_velocity, buffer, bufferOffset);
    // Serialize message field [linear_acceleration]
    bufferOffset = Point3D.serialize(obj.linear_acceleration, buffer, bufferOffset);
    // Serialize message field [angular_velocity]
    bufferOffset = Point3D.serialize(obj.angular_velocity, buffer, bufferOffset);
    // Serialize message field [rtk_flag]
    bufferOffset = _serializer.int32(obj.rtk_flag, buffer, bufferOffset);
    // Serialize message field [odom_type]
    bufferOffset = _serializer.int32(obj.odom_type, buffer, bufferOffset);
    // Serialize message field [auxiliary_type]
    bufferOffset = _serializer.int32(obj.auxiliary_type, buffer, bufferOffset);
    // Serialize message field [location_valid_flag]
    bufferOffset = _serializer.int32(obj.location_valid_flag, buffer, bufferOffset);
    // Serialize message field [origin_lat]
    bufferOffset = _serializer.float64(obj.origin_lat, buffer, bufferOffset);
    // Serialize message field [origin_lon]
    bufferOffset = _serializer.float64(obj.origin_lon, buffer, bufferOffset);
    // Serialize message field [utm_position]
    bufferOffset = PointENU.serialize(obj.utm_position, buffer, bufferOffset);
    // Serialize message field [change_origin_flag]
    bufferOffset = _serializer.int32(obj.change_origin_flag, buffer, bufferOffset);
    // Serialize message field [utm_position_next]
    bufferOffset = PointENU.serialize(obj.utm_position_next, buffer, bufferOffset);
    // Serialize message field [position_std_dev]
    bufferOffset = Point3D.serialize(obj.position_std_dev, buffer, bufferOffset);
    // Serialize message field [orientation_std_dev]
    bufferOffset = Point3D.serialize(obj.orientation_std_dev, buffer, bufferOffset);
    // Serialize message field [linear_velocity_std_dev]
    bufferOffset = Point3D.serialize(obj.linear_velocity_std_dev, buffer, bufferOffset);
    // Serialize message field [linear_acceleration_std_dev]
    bufferOffset = Point3D.serialize(obj.linear_acceleration_std_dev, buffer, bufferOffset);
    // Serialize message field [angular_velocity_std_dev]
    bufferOffset = Point3D.serialize(obj.angular_velocity_std_dev, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Location
    let len;
    let data = new Location(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [position]
    data.position = PointLLH.deserialize(buffer, bufferOffset);
    // Deserialize message field [pitch]
    data.pitch = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [roll]
    data.roll = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [heading]
    data.heading = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [linear_velocity]
    data.linear_velocity = Point3D.deserialize(buffer, bufferOffset);
    // Deserialize message field [linear_acceleration]
    data.linear_acceleration = Point3D.deserialize(buffer, bufferOffset);
    // Deserialize message field [angular_velocity]
    data.angular_velocity = Point3D.deserialize(buffer, bufferOffset);
    // Deserialize message field [rtk_flag]
    data.rtk_flag = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [odom_type]
    data.odom_type = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [auxiliary_type]
    data.auxiliary_type = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [location_valid_flag]
    data.location_valid_flag = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [origin_lat]
    data.origin_lat = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [origin_lon]
    data.origin_lon = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [utm_position]
    data.utm_position = PointENU.deserialize(buffer, bufferOffset);
    // Deserialize message field [change_origin_flag]
    data.change_origin_flag = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [utm_position_next]
    data.utm_position_next = PointENU.deserialize(buffer, bufferOffset);
    // Deserialize message field [position_std_dev]
    data.position_std_dev = Point3D.deserialize(buffer, bufferOffset);
    // Deserialize message field [orientation_std_dev]
    data.orientation_std_dev = Point3D.deserialize(buffer, bufferOffset);
    // Deserialize message field [linear_velocity_std_dev]
    data.linear_velocity_std_dev = Point3D.deserialize(buffer, bufferOffset);
    // Deserialize message field [linear_acceleration_std_dev]
    data.linear_acceleration_std_dev = Point3D.deserialize(buffer, bufferOffset);
    // Deserialize message field [angular_velocity_std_dev]
    data.angular_velocity_std_dev = Point3D.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 324;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ros_interface/Location';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6b25c2b9af6ab35d68c43d9abb43d342';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header   header     # 消息头
    PointLLH   position     # 经纬度高程
    float64   pitch     # 方向(单位弧度，-π～π,正东:0, 逆时针。都满足右手定则)
    float64   roll     #  
    float64   heading     #  
    Point3D   linear_velocity     # 线速度（m/s，北东地坐标系）
    Point3D   linear_acceleration     # 线加速度（m/s2，前右下坐标系）
    Point3D   angular_velocity     # 角速度（度/s，前右下，满足右手定则）
    int32   rtk_flag     # RTK标志值
    int32   odom_type     # 融合标志:0-(纯ins) 1-(纯轮速) 2-(泊车递推) 3-(无) 4-(orb匹配定位)
    int32   auxiliary_type     # 辅助方式:0-NULL(无辅助方式) 1-laneliine_map(车道线/标识牌)2-feature_map(lidar)3-feature_map(lidar_camera)
    int32   location_valid_flag     # Location有效性标志位0: invalid； 1: valid
    float64   origin_lat     # 参考点纬度 GCJ-02格式
    float64   origin_lon     # 参考点经度 GCJ-02格式
    PointENU   utm_position     # 相对参考点xyz坐标
    int32   change_origin_flag     # 0::无坐标系切换 1:坐标系切换成功2:坐标系切换中3:坐标系切换故障
    PointENU   utm_position_next     # 相对参考点坐标(切换状态下，为新的原点坐标系下)
    Point3D   position_std_dev     # 位置标准差
    Point3D   orientation_std_dev     # 方向标准差
    Point3D   linear_velocity_std_dev     # 速度标准差
    Point3D   linear_acceleration_std_dev     # 加速度标准差
    Point3D   angular_velocity_std_dev     # 角速度标准差
    
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
    MSG: ros_interface/PointLLH
    float64   lon     # Longitude in degrees, ranging from -180 to 180.
    float64   lat     # Latitude in degrees, ranging from -90 to 90.
    float64   height     # WGS-84 ellipsoid height in meters.
    
    ================================================================================
    MSG: ros_interface/Point3D
    float64   x     # 位置坐标x
    float64   y     # 位置坐标y
    float64   z     # 位置坐标z
    
    ================================================================================
    MSG: ros_interface/PointENU
    float64   x     # East from the origin, in meters.
    float64   y     # North from the origin, in meters.
    float64   z     # Up from the WGS-84 ellipsoid, in meters.
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Location(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.position !== undefined) {
      resolved.position = PointLLH.Resolve(msg.position)
    }
    else {
      resolved.position = new PointLLH()
    }

    if (msg.pitch !== undefined) {
      resolved.pitch = msg.pitch;
    }
    else {
      resolved.pitch = 0.0
    }

    if (msg.roll !== undefined) {
      resolved.roll = msg.roll;
    }
    else {
      resolved.roll = 0.0
    }

    if (msg.heading !== undefined) {
      resolved.heading = msg.heading;
    }
    else {
      resolved.heading = 0.0
    }

    if (msg.linear_velocity !== undefined) {
      resolved.linear_velocity = Point3D.Resolve(msg.linear_velocity)
    }
    else {
      resolved.linear_velocity = new Point3D()
    }

    if (msg.linear_acceleration !== undefined) {
      resolved.linear_acceleration = Point3D.Resolve(msg.linear_acceleration)
    }
    else {
      resolved.linear_acceleration = new Point3D()
    }

    if (msg.angular_velocity !== undefined) {
      resolved.angular_velocity = Point3D.Resolve(msg.angular_velocity)
    }
    else {
      resolved.angular_velocity = new Point3D()
    }

    if (msg.rtk_flag !== undefined) {
      resolved.rtk_flag = msg.rtk_flag;
    }
    else {
      resolved.rtk_flag = 0
    }

    if (msg.odom_type !== undefined) {
      resolved.odom_type = msg.odom_type;
    }
    else {
      resolved.odom_type = 0
    }

    if (msg.auxiliary_type !== undefined) {
      resolved.auxiliary_type = msg.auxiliary_type;
    }
    else {
      resolved.auxiliary_type = 0
    }

    if (msg.location_valid_flag !== undefined) {
      resolved.location_valid_flag = msg.location_valid_flag;
    }
    else {
      resolved.location_valid_flag = 0
    }

    if (msg.origin_lat !== undefined) {
      resolved.origin_lat = msg.origin_lat;
    }
    else {
      resolved.origin_lat = 0.0
    }

    if (msg.origin_lon !== undefined) {
      resolved.origin_lon = msg.origin_lon;
    }
    else {
      resolved.origin_lon = 0.0
    }

    if (msg.utm_position !== undefined) {
      resolved.utm_position = PointENU.Resolve(msg.utm_position)
    }
    else {
      resolved.utm_position = new PointENU()
    }

    if (msg.change_origin_flag !== undefined) {
      resolved.change_origin_flag = msg.change_origin_flag;
    }
    else {
      resolved.change_origin_flag = 0
    }

    if (msg.utm_position_next !== undefined) {
      resolved.utm_position_next = PointENU.Resolve(msg.utm_position_next)
    }
    else {
      resolved.utm_position_next = new PointENU()
    }

    if (msg.position_std_dev !== undefined) {
      resolved.position_std_dev = Point3D.Resolve(msg.position_std_dev)
    }
    else {
      resolved.position_std_dev = new Point3D()
    }

    if (msg.orientation_std_dev !== undefined) {
      resolved.orientation_std_dev = Point3D.Resolve(msg.orientation_std_dev)
    }
    else {
      resolved.orientation_std_dev = new Point3D()
    }

    if (msg.linear_velocity_std_dev !== undefined) {
      resolved.linear_velocity_std_dev = Point3D.Resolve(msg.linear_velocity_std_dev)
    }
    else {
      resolved.linear_velocity_std_dev = new Point3D()
    }

    if (msg.linear_acceleration_std_dev !== undefined) {
      resolved.linear_acceleration_std_dev = Point3D.Resolve(msg.linear_acceleration_std_dev)
    }
    else {
      resolved.linear_acceleration_std_dev = new Point3D()
    }

    if (msg.angular_velocity_std_dev !== undefined) {
      resolved.angular_velocity_std_dev = Point3D.Resolve(msg.angular_velocity_std_dev)
    }
    else {
      resolved.angular_velocity_std_dev = new Point3D()
    }

    return resolved;
    }
};

module.exports = Location;
