// Auto-generated. Do not edit!

// (in-package ros_interface.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class PathPoint {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.x = null;
      this.y = null;
      this.z = null;
      this.theta = null;
      this.kappa = null;
      this.s = null;
      this.dkappa = null;
      this.ddkappa = null;
      this.lane_id = null;
      this.x_derivative = null;
      this.y_derivative = null;
    }
    else {
      if (initObj.hasOwnProperty('x')) {
        this.x = initObj.x
      }
      else {
        this.x = 0.0;
      }
      if (initObj.hasOwnProperty('y')) {
        this.y = initObj.y
      }
      else {
        this.y = 0.0;
      }
      if (initObj.hasOwnProperty('z')) {
        this.z = initObj.z
      }
      else {
        this.z = 0.0;
      }
      if (initObj.hasOwnProperty('theta')) {
        this.theta = initObj.theta
      }
      else {
        this.theta = 0.0;
      }
      if (initObj.hasOwnProperty('kappa')) {
        this.kappa = initObj.kappa
      }
      else {
        this.kappa = 0.0;
      }
      if (initObj.hasOwnProperty('s')) {
        this.s = initObj.s
      }
      else {
        this.s = 0.0;
      }
      if (initObj.hasOwnProperty('dkappa')) {
        this.dkappa = initObj.dkappa
      }
      else {
        this.dkappa = 0.0;
      }
      if (initObj.hasOwnProperty('ddkappa')) {
        this.ddkappa = initObj.ddkappa
      }
      else {
        this.ddkappa = 0.0;
      }
      if (initObj.hasOwnProperty('lane_id')) {
        this.lane_id = initObj.lane_id
      }
      else {
        this.lane_id = 0.0;
      }
      if (initObj.hasOwnProperty('x_derivative')) {
        this.x_derivative = initObj.x_derivative
      }
      else {
        this.x_derivative = 0.0;
      }
      if (initObj.hasOwnProperty('y_derivative')) {
        this.y_derivative = initObj.y_derivative
      }
      else {
        this.y_derivative = 0.0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type PathPoint
    // Serialize message field [x]
    bufferOffset = _serializer.float64(obj.x, buffer, bufferOffset);
    // Serialize message field [y]
    bufferOffset = _serializer.float64(obj.y, buffer, bufferOffset);
    // Serialize message field [z]
    bufferOffset = _serializer.float64(obj.z, buffer, bufferOffset);
    // Serialize message field [theta]
    bufferOffset = _serializer.float64(obj.theta, buffer, bufferOffset);
    // Serialize message field [kappa]
    bufferOffset = _serializer.float64(obj.kappa, buffer, bufferOffset);
    // Serialize message field [s]
    bufferOffset = _serializer.float64(obj.s, buffer, bufferOffset);
    // Serialize message field [dkappa]
    bufferOffset = _serializer.float64(obj.dkappa, buffer, bufferOffset);
    // Serialize message field [ddkappa]
    bufferOffset = _serializer.float64(obj.ddkappa, buffer, bufferOffset);
    // Serialize message field [lane_id]
    bufferOffset = _serializer.float64(obj.lane_id, buffer, bufferOffset);
    // Serialize message field [x_derivative]
    bufferOffset = _serializer.float64(obj.x_derivative, buffer, bufferOffset);
    // Serialize message field [y_derivative]
    bufferOffset = _serializer.float64(obj.y_derivative, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type PathPoint
    let len;
    let data = new PathPoint(null);
    // Deserialize message field [x]
    data.x = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [y]
    data.y = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [z]
    data.z = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [theta]
    data.theta = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [kappa]
    data.kappa = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [s]
    data.s = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [dkappa]
    data.dkappa = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [ddkappa]
    data.ddkappa = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [lane_id]
    data.lane_id = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [x_derivative]
    data.x_derivative = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [y_derivative]
    data.y_derivative = _deserializer.float64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    return 88;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ros_interface/PathPoint';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '6d7f4ed096293a13bafb904c75b6c36b';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    float64   x     # coordinates x
    float64   y     # coordinates y
    float64   z     # coordinates z
    float64   theta     # direction on the x-y plane
    float64   kappa     # curvature on the x-y planning
    float64   s     # accumulated distance from beginning of the path
    float64   dkappa     # derivative of kappa w.r.t s.
    float64   ddkappa     # derivative of derivative of kappa w.r.t s.
    float64   lane_id     # The lane ID where the path point is on
    float64   x_derivative     # derivative of x w.r.t parametric parameter t in CosThetareferenceline
    float64   y_derivative     # derivative of y w.r.t parametric parameter t in CosThetareferenceline
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new PathPoint(null);
    if (msg.x !== undefined) {
      resolved.x = msg.x;
    }
    else {
      resolved.x = 0.0
    }

    if (msg.y !== undefined) {
      resolved.y = msg.y;
    }
    else {
      resolved.y = 0.0
    }

    if (msg.z !== undefined) {
      resolved.z = msg.z;
    }
    else {
      resolved.z = 0.0
    }

    if (msg.theta !== undefined) {
      resolved.theta = msg.theta;
    }
    else {
      resolved.theta = 0.0
    }

    if (msg.kappa !== undefined) {
      resolved.kappa = msg.kappa;
    }
    else {
      resolved.kappa = 0.0
    }

    if (msg.s !== undefined) {
      resolved.s = msg.s;
    }
    else {
      resolved.s = 0.0
    }

    if (msg.dkappa !== undefined) {
      resolved.dkappa = msg.dkappa;
    }
    else {
      resolved.dkappa = 0.0
    }

    if (msg.ddkappa !== undefined) {
      resolved.ddkappa = msg.ddkappa;
    }
    else {
      resolved.ddkappa = 0.0
    }

    if (msg.lane_id !== undefined) {
      resolved.lane_id = msg.lane_id;
    }
    else {
      resolved.lane_id = 0.0
    }

    if (msg.x_derivative !== undefined) {
      resolved.x_derivative = msg.x_derivative;
    }
    else {
      resolved.x_derivative = 0.0
    }

    if (msg.y_derivative !== undefined) {
      resolved.y_derivative = msg.y_derivative;
    }
    else {
      resolved.y_derivative = 0.0
    }

    return resolved;
    }
};

module.exports = PathPoint;
