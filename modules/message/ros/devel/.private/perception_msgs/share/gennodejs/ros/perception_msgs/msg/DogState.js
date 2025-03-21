// Auto-generated. Do not edit!

// (in-package perception_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let AlarmEntry = require('./AlarmEntry.js');
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class DogState {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.battery = null;
      this.chargingState = null;
      this.gesture = null;
      this.speed = null;
      this.person_state = null;
      this.target_position = null;
      this.alarmInfo = null;
    }
    else {
      if (initObj.hasOwnProperty('battery')) {
        this.battery = initObj.battery
      }
      else {
        this.battery = 0.0;
      }
      if (initObj.hasOwnProperty('chargingState')) {
        this.chargingState = initObj.chargingState
      }
      else {
        this.chargingState = 0;
      }
      if (initObj.hasOwnProperty('gesture')) {
        this.gesture = initObj.gesture
      }
      else {
        this.gesture = 0;
      }
      if (initObj.hasOwnProperty('speed')) {
        this.speed = initObj.speed
      }
      else {
        this.speed = 0.0;
      }
      if (initObj.hasOwnProperty('person_state')) {
        this.person_state = initObj.person_state
      }
      else {
        this.person_state = 0;
      }
      if (initObj.hasOwnProperty('target_position')) {
        this.target_position = initObj.target_position
      }
      else {
        this.target_position = new geometry_msgs.msg.Pose();
      }
      if (initObj.hasOwnProperty('alarmInfo')) {
        this.alarmInfo = initObj.alarmInfo
      }
      else {
        this.alarmInfo = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type DogState
    // Serialize message field [battery]
    bufferOffset = _serializer.float64(obj.battery, buffer, bufferOffset);
    // Serialize message field [chargingState]
    bufferOffset = _serializer.uint8(obj.chargingState, buffer, bufferOffset);
    // Serialize message field [gesture]
    bufferOffset = _serializer.uint8(obj.gesture, buffer, bufferOffset);
    // Serialize message field [speed]
    bufferOffset = _serializer.float64(obj.speed, buffer, bufferOffset);
    // Serialize message field [person_state]
    bufferOffset = _serializer.uint8(obj.person_state, buffer, bufferOffset);
    // Serialize message field [target_position]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.target_position, buffer, bufferOffset);
    // Serialize message field [alarmInfo]
    // Serialize the length for message field [alarmInfo]
    bufferOffset = _serializer.uint32(obj.alarmInfo.length, buffer, bufferOffset);
    obj.alarmInfo.forEach((val) => {
      bufferOffset = AlarmEntry.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type DogState
    let len;
    let data = new DogState(null);
    // Deserialize message field [battery]
    data.battery = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [chargingState]
    data.chargingState = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [gesture]
    data.gesture = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [speed]
    data.speed = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [person_state]
    data.person_state = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [target_position]
    data.target_position = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    // Deserialize message field [alarmInfo]
    // Deserialize array length for message field [alarmInfo]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.alarmInfo = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.alarmInfo[i] = AlarmEntry.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    object.alarmInfo.forEach((val) => {
      length += AlarmEntry.getMessageSize(val);
    });
    return length + 79;
  }

  static datatype() {
    // Returns string type for a message object
    return 'perception_msgs/DogState';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '37a76525c34080656fe716b1e4427824';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # 电量
    float64 battery
    #充电状态   0：空闲 1: 准备充电 2：充电中 
    uint8 chargingState
    #手势
    uint8 gesture
    #速度 
    float64 speed
    #主人识别状态
    uint8 person_state
    # 目标点
    geometry_msgs/Pose target_position
    #报警信息
    AlarmEntry[] alarmInfo
    #动作信息
    #ActionEntry[] actions
    
    ================================================================================
    MSG: geometry_msgs/Pose
    # A representation of pose in free space, composed of position and orientation. 
    Point position
    Quaternion orientation
    
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    ================================================================================
    MSG: geometry_msgs/Quaternion
    # This represents an orientation in free space in quaternion form.
    
    float64 x
    float64 y
    float64 z
    float64 w
    
    ================================================================================
    MSG: perception_msgs/AlarmEntry
    int32  id
    int32  source
    int32  level
    int32  status
    string message
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new DogState(null);
    if (msg.battery !== undefined) {
      resolved.battery = msg.battery;
    }
    else {
      resolved.battery = 0.0
    }

    if (msg.chargingState !== undefined) {
      resolved.chargingState = msg.chargingState;
    }
    else {
      resolved.chargingState = 0
    }

    if (msg.gesture !== undefined) {
      resolved.gesture = msg.gesture;
    }
    else {
      resolved.gesture = 0
    }

    if (msg.speed !== undefined) {
      resolved.speed = msg.speed;
    }
    else {
      resolved.speed = 0.0
    }

    if (msg.person_state !== undefined) {
      resolved.person_state = msg.person_state;
    }
    else {
      resolved.person_state = 0
    }

    if (msg.target_position !== undefined) {
      resolved.target_position = geometry_msgs.msg.Pose.Resolve(msg.target_position)
    }
    else {
      resolved.target_position = new geometry_msgs.msg.Pose()
    }

    if (msg.alarmInfo !== undefined) {
      resolved.alarmInfo = new Array(msg.alarmInfo.length);
      for (let i = 0; i < resolved.alarmInfo.length; ++i) {
        resolved.alarmInfo[i] = AlarmEntry.Resolve(msg.alarmInfo[i]);
      }
    }
    else {
      resolved.alarmInfo = []
    }

    return resolved;
    }
};

module.exports = DogState;
