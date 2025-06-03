// Auto-generated. Do not edit!

// (in-package quad_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let LegCommand = require('./LegCommand.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class LegCommandArray {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.leg_commands = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('leg_commands')) {
        this.leg_commands = initObj.leg_commands
      }
      else {
        this.leg_commands = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type LegCommandArray
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [leg_commands]
    // Serialize the length for message field [leg_commands]
    bufferOffset = _serializer.uint32(obj.leg_commands.length, buffer, bufferOffset);
    obj.leg_commands.forEach((val) => {
      bufferOffset = LegCommand.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type LegCommandArray
    let len;
    let data = new LegCommandArray(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [leg_commands]
    // Deserialize array length for message field [leg_commands]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.leg_commands = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.leg_commands[i] = LegCommand.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    object.leg_commands.forEach((val) => {
      length += LegCommand.getMessageSize(val);
    });
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'quad_msgs/LegCommandArray';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '021ecb87d231eeb30d1c10093fda1cef';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # This is a message of leg commands for each leg on quad. The order is in FL, BL, FR, BR.
    #
    # Accurate timing information is stored in the header
    
    Header header
    
    LegCommand[] leg_commands # FL, BL, FR, BR
    
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
    MSG: quad_msgs/LegCommand
    # This is a message of motor commands for each joint on a quad leg.
    #
    # Accurate timing information is stored in the header
    
    Header header
    
    MotorCommand[] motor_commands # Stored as Abd, Hip, Knee
    
    ================================================================================
    MSG: quad_msgs/MotorCommand
    # This is a message to hold the desired position, desired velocity, feedforward torques and control gains for a single joint on Quad
    #
    # Accurate timing information is stored in the header
    
    Header header
    
    # Commands
    float64 pos_setpoint # Position command
    float64 vel_setpoint # Velocity command
    float32 kp # Position setpoint gain
    float32 kd # Derivative setpoint gain
    float64 torque_ff # Feedforward torque
    
    # Diagnostics
    float64 pos_component # Feedback position component
    float64 vel_component # Feedback velocity component
    float64 fb_component # Feedback total component
    float64 effort # Total effort
    float64 fb_ratio # Feedback to total ratio
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new LegCommandArray(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.leg_commands !== undefined) {
      resolved.leg_commands = new Array(msg.leg_commands.length);
      for (let i = 0; i < resolved.leg_commands.length; ++i) {
        resolved.leg_commands[i] = LegCommand.Resolve(msg.leg_commands[i]);
      }
    }
    else {
      resolved.leg_commands = []
    }

    return resolved;
    }
};

module.exports = LegCommandArray;
