// Auto-generated. Do not edit!

// (in-package ros_interface.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let Point3D = require('./Point3D.js');
let Polygon3D = require('./Polygon3D.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class HMIParkingInfo {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.parking_space_id = null;
      this.parking_type = null;
      this.parking_status = null;
      this.center_point_of_parking = null;
      this.theta = null;
      this.width = null;
      this.length = null;
      this.is_custom_parking = null;
      this.polygon = null;
      this.parking_source_type = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('parking_space_id')) {
        this.parking_space_id = initObj.parking_space_id
      }
      else {
        this.parking_space_id = 0;
      }
      if (initObj.hasOwnProperty('parking_type')) {
        this.parking_type = initObj.parking_type
      }
      else {
        this.parking_type = 0;
      }
      if (initObj.hasOwnProperty('parking_status')) {
        this.parking_status = initObj.parking_status
      }
      else {
        this.parking_status = 0;
      }
      if (initObj.hasOwnProperty('center_point_of_parking')) {
        this.center_point_of_parking = initObj.center_point_of_parking
      }
      else {
        this.center_point_of_parking = new Point3D();
      }
      if (initObj.hasOwnProperty('theta')) {
        this.theta = initObj.theta
      }
      else {
        this.theta = 0.0;
      }
      if (initObj.hasOwnProperty('width')) {
        this.width = initObj.width
      }
      else {
        this.width = 0.0;
      }
      if (initObj.hasOwnProperty('length')) {
        this.length = initObj.length
      }
      else {
        this.length = 0.0;
      }
      if (initObj.hasOwnProperty('is_custom_parking')) {
        this.is_custom_parking = initObj.is_custom_parking
      }
      else {
        this.is_custom_parking = false;
      }
      if (initObj.hasOwnProperty('polygon')) {
        this.polygon = initObj.polygon
      }
      else {
        this.polygon = new Polygon3D();
      }
      if (initObj.hasOwnProperty('parking_source_type')) {
        this.parking_source_type = initObj.parking_source_type
      }
      else {
        this.parking_source_type = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type HMIParkingInfo
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [parking_space_id]
    bufferOffset = _serializer.int32(obj.parking_space_id, buffer, bufferOffset);
    // Serialize message field [parking_type]
    bufferOffset = _serializer.int32(obj.parking_type, buffer, bufferOffset);
    // Serialize message field [parking_status]
    bufferOffset = _serializer.int32(obj.parking_status, buffer, bufferOffset);
    // Serialize message field [center_point_of_parking]
    bufferOffset = Point3D.serialize(obj.center_point_of_parking, buffer, bufferOffset);
    // Serialize message field [theta]
    bufferOffset = _serializer.float64(obj.theta, buffer, bufferOffset);
    // Serialize message field [width]
    bufferOffset = _serializer.float64(obj.width, buffer, bufferOffset);
    // Serialize message field [length]
    bufferOffset = _serializer.float64(obj.length, buffer, bufferOffset);
    // Serialize message field [is_custom_parking]
    bufferOffset = _serializer.bool(obj.is_custom_parking, buffer, bufferOffset);
    // Serialize message field [polygon]
    bufferOffset = Polygon3D.serialize(obj.polygon, buffer, bufferOffset);
    // Serialize message field [parking_source_type]
    bufferOffset = _serializer.int32(obj.parking_source_type, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type HMIParkingInfo
    let len;
    let data = new HMIParkingInfo(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [parking_space_id]
    data.parking_space_id = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [parking_type]
    data.parking_type = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [parking_status]
    data.parking_status = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [center_point_of_parking]
    data.center_point_of_parking = Point3D.deserialize(buffer, bufferOffset);
    // Deserialize message field [theta]
    data.theta = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [width]
    data.width = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [length]
    data.length = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [is_custom_parking]
    data.is_custom_parking = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [polygon]
    data.polygon = Polygon3D.deserialize(buffer, bufferOffset);
    // Deserialize message field [parking_source_type]
    data.parking_source_type = _deserializer.int32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += Polygon3D.getMessageSize(object.polygon);
    return length + 65;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ros_interface/HMIParkingInfo';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e289531f8277ce0296a442820fcf7b40';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new HMIParkingInfo(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.parking_space_id !== undefined) {
      resolved.parking_space_id = msg.parking_space_id;
    }
    else {
      resolved.parking_space_id = 0
    }

    if (msg.parking_type !== undefined) {
      resolved.parking_type = msg.parking_type;
    }
    else {
      resolved.parking_type = 0
    }

    if (msg.parking_status !== undefined) {
      resolved.parking_status = msg.parking_status;
    }
    else {
      resolved.parking_status = 0
    }

    if (msg.center_point_of_parking !== undefined) {
      resolved.center_point_of_parking = Point3D.Resolve(msg.center_point_of_parking)
    }
    else {
      resolved.center_point_of_parking = new Point3D()
    }

    if (msg.theta !== undefined) {
      resolved.theta = msg.theta;
    }
    else {
      resolved.theta = 0.0
    }

    if (msg.width !== undefined) {
      resolved.width = msg.width;
    }
    else {
      resolved.width = 0.0
    }

    if (msg.length !== undefined) {
      resolved.length = msg.length;
    }
    else {
      resolved.length = 0.0
    }

    if (msg.is_custom_parking !== undefined) {
      resolved.is_custom_parking = msg.is_custom_parking;
    }
    else {
      resolved.is_custom_parking = false
    }

    if (msg.polygon !== undefined) {
      resolved.polygon = Polygon3D.Resolve(msg.polygon)
    }
    else {
      resolved.polygon = new Polygon3D()
    }

    if (msg.parking_source_type !== undefined) {
      resolved.parking_source_type = msg.parking_source_type;
    }
    else {
      resolved.parking_source_type = 0
    }

    return resolved;
    }
};

module.exports = HMIParkingInfo;
