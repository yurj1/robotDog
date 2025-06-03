// Auto-generated. Do not edit!

// (in-package quad_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class MotorCommand {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.pos_setpoint = null;
      this.vel_setpoint = null;
      this.kp = null;
      this.kd = null;
      this.torque_ff = null;
      this.pos_component = null;
      this.vel_component = null;
      this.fb_component = null;
      this.effort = null;
      this.fb_ratio = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('pos_setpoint')) {
        this.pos_setpoint = initObj.pos_setpoint
      }
      else {
        this.pos_setpoint = 0.0;
      }
      if (initObj.hasOwnProperty('vel_setpoint')) {
        this.vel_setpoint = initObj.vel_setpoint
      }
      else {
        this.vel_setpoint = 0.0;
      }
      if (initObj.hasOwnProperty('kp')) {
        this.kp = initObj.kp
      }
      else {
        this.kp = 0.0;
      }
      if (initObj.hasOwnProperty('kd')) {
        this.kd = initObj.kd
      }
      else {
        this.kd = 0.0;
      }
      if (initObj.hasOwnProperty('torque_ff')) {
        this.torque_ff = initObj.torque_ff
      }
      else {
        this.torque_ff = 0.0;
      }
      if (initObj.hasOwnProperty('pos_component')) {
        this.pos_component = initObj.pos_component
      }
      else {
        this.pos_component = 0.0;
      }
      if (initObj.hasOwnProperty('vel_component')) {
        this.vel_component = initObj.vel_component
      }
      else {
        this.vel_component = 0.0;
      }
      if (initObj.hasOwnProperty('fb_component')) {
        this.fb_component = initObj.fb_component
      }
      else {
        this.fb_component = 0.0;
      }
      if (initObj.hasOwnProperty('effort')) {
        this.effort = initObj.effort
      }
      else {
        this.effort = 0.0;
      }
      if (initObj.hasOwnProperty('fb_ratio')) {
        this.fb_ratio = initObj.fb_ratio
      }
      else {
        this.fb_ratio = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type MotorCommand
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [pos_setpoint]
    bufferOffset = _serializer.float64(obj.pos_setpoint, buffer, bufferOffset);
    // Serialize message field [vel_setpoint]
    bufferOffset = _serializer.float64(obj.vel_setpoint, buffer, bufferOffset);
    // Serialize message field [kp]
    bufferOffset = _serializer.float32(obj.kp, buffer, bufferOffset);
    // Serialize message field [kd]
    bufferOffset = _serializer.float32(obj.kd, buffer, bufferOffset);
    // Serialize message field [torque_ff]
    bufferOffset = _serializer.float64(obj.torque_ff, buffer, bufferOffset);
    // Serialize message field [pos_component]
    bufferOffset = _serializer.float64(obj.pos_component, buffer, bufferOffset);
    // Serialize message field [vel_component]
    bufferOffset = _serializer.float64(obj.vel_component, buffer, bufferOffset);
    // Serialize message field [fb_component]
    bufferOffset = _serializer.float64(obj.fb_component, buffer, bufferOffset);
    // Serialize message field [effort]
    bufferOffset = _serializer.float64(obj.effort, buffer, bufferOffset);
    // Serialize message field [fb_ratio]
    bufferOffset = _serializer.float64(obj.fb_ratio, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type MotorCommand
    let len;
    let data = new MotorCommand(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [pos_setpoint]
    data.pos_setpoint = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [vel_setpoint]
    data.vel_setpoint = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [kp]
    data.kp = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [kd]
    data.kd = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [torque_ff]
    data.torque_ff = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [pos_component]
    data.pos_component = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [vel_component]
    data.vel_component = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [fb_component]
    data.fb_component = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [effort]
    data.effort = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [fb_ratio]
    data.fb_ratio = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 72;
  }

  static datatype() {
    // Returns string type for a message object
    return 'quad_msgs/MotorCommand';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e200217cec0ef4e0862655a028b63ff2';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new MotorCommand(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.pos_setpoint !== undefined) {
      resolved.pos_setpoint = msg.pos_setpoint;
    }
    else {
      resolved.pos_setpoint = 0.0
    }

    if (msg.vel_setpoint !== undefined) {
      resolved.vel_setpoint = msg.vel_setpoint;
    }
    else {
      resolved.vel_setpoint = 0.0
    }

    if (msg.kp !== undefined) {
      resolved.kp = msg.kp;
    }
    else {
      resolved.kp = 0.0
    }

    if (msg.kd !== undefined) {
      resolved.kd = msg.kd;
    }
    else {
      resolved.kd = 0.0
    }

    if (msg.torque_ff !== undefined) {
      resolved.torque_ff = msg.torque_ff;
    }
    else {
      resolved.torque_ff = 0.0
    }

    if (msg.pos_component !== undefined) {
      resolved.pos_component = msg.pos_component;
    }
    else {
      resolved.pos_component = 0.0
    }

    if (msg.vel_component !== undefined) {
      resolved.vel_component = msg.vel_component;
    }
    else {
      resolved.vel_component = 0.0
    }

    if (msg.fb_component !== undefined) {
      resolved.fb_component = msg.fb_component;
    }
    else {
      resolved.fb_component = 0.0
    }

    if (msg.effort !== undefined) {
      resolved.effort = msg.effort;
    }
    else {
      resolved.effort = 0.0
    }

    if (msg.fb_ratio !== undefined) {
      resolved.fb_ratio = msg.fb_ratio;
    }
    else {
      resolved.fb_ratio = 0.0
    }

    return resolved;
    }
};

module.exports = MotorCommand;
