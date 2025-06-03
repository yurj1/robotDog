// Auto-generated. Do not edit!

// (in-package quad_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class RobotPlanDiagnostics {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.compute_time = null;
      this.cost = null;
      this.iterations = null;
      this.horizon_length = null;
      this.complexity_schedule = null;
      this.element_times = null;
    }
    else {
      if (initObj.hasOwnProperty('compute_time')) {
        this.compute_time = initObj.compute_time
      }
      else {
        this.compute_time = 0.0;
      }
      if (initObj.hasOwnProperty('cost')) {
        this.cost = initObj.cost
      }
      else {
        this.cost = 0.0;
      }
      if (initObj.hasOwnProperty('iterations')) {
        this.iterations = initObj.iterations
      }
      else {
        this.iterations = 0;
      }
      if (initObj.hasOwnProperty('horizon_length')) {
        this.horizon_length = initObj.horizon_length
      }
      else {
        this.horizon_length = 0;
      }
      if (initObj.hasOwnProperty('complexity_schedule')) {
        this.complexity_schedule = initObj.complexity_schedule
      }
      else {
        this.complexity_schedule = [];
      }
      if (initObj.hasOwnProperty('element_times')) {
        this.element_times = initObj.element_times
      }
      else {
        this.element_times = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type RobotPlanDiagnostics
    // Serialize message field [compute_time]
    bufferOffset = _serializer.float64(obj.compute_time, buffer, bufferOffset);
    // Serialize message field [cost]
    bufferOffset = _serializer.float64(obj.cost, buffer, bufferOffset);
    // Serialize message field [iterations]
    bufferOffset = _serializer.uint32(obj.iterations, buffer, bufferOffset);
    // Serialize message field [horizon_length]
    bufferOffset = _serializer.uint32(obj.horizon_length, buffer, bufferOffset);
    // Serialize message field [complexity_schedule]
    bufferOffset = _arraySerializer.uint32(obj.complexity_schedule, buffer, bufferOffset, null);
    // Serialize message field [element_times]
    bufferOffset = _arraySerializer.float64(obj.element_times, buffer, bufferOffset, null);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type RobotPlanDiagnostics
    let len;
    let data = new RobotPlanDiagnostics(null);
    // Deserialize message field [compute_time]
    data.compute_time = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [cost]
    data.cost = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [iterations]
    data.iterations = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [horizon_length]
    data.horizon_length = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [complexity_schedule]
    data.complexity_schedule = _arrayDeserializer.uint32(buffer, bufferOffset, null)
    // Deserialize message field [element_times]
    data.element_times = _arrayDeserializer.float64(buffer, bufferOffset, null)
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 4 * object.complexity_schedule.length;
    length += 8 * object.element_times.length;
    return length + 32;
  }

  static datatype() {
    // Returns string type for a message object
    return 'quad_msgs/RobotPlanDiagnostics';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '4ba495ddc8d93cb86ca454812d102149';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # This is a message to hold local plan diagnostics
    
    float64 compute_time
    float64 cost
    uint32 iterations
    uint32 horizon_length
    uint32[] complexity_schedule
    float64[] element_times
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new RobotPlanDiagnostics(null);
    if (msg.compute_time !== undefined) {
      resolved.compute_time = msg.compute_time;
    }
    else {
      resolved.compute_time = 0.0
    }

    if (msg.cost !== undefined) {
      resolved.cost = msg.cost;
    }
    else {
      resolved.cost = 0.0
    }

    if (msg.iterations !== undefined) {
      resolved.iterations = msg.iterations;
    }
    else {
      resolved.iterations = 0
    }

    if (msg.horizon_length !== undefined) {
      resolved.horizon_length = msg.horizon_length;
    }
    else {
      resolved.horizon_length = 0
    }

    if (msg.complexity_schedule !== undefined) {
      resolved.complexity_schedule = msg.complexity_schedule;
    }
    else {
      resolved.complexity_schedule = []
    }

    if (msg.element_times !== undefined) {
      resolved.element_times = msg.element_times;
    }
    else {
      resolved.element_times = []
    }

    return resolved;
    }
};

module.exports = RobotPlanDiagnostics;
