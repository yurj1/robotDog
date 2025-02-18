// Auto-generated. Do not edit!

// (in-package perception_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class TaskList {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.task_id = null;
      this.task_type = null;
      this.target_position = null;
      this.target_object = null;
      this.task_state = null;
      this.task_result = null;
      this.isInPlaceRotation = null;
    }
    else {
      if (initObj.hasOwnProperty('task_id')) {
        this.task_id = initObj.task_id
      }
      else {
        this.task_id = 0;
      }
      if (initObj.hasOwnProperty('task_type')) {
        this.task_type = initObj.task_type
      }
      else {
        this.task_type = 0;
      }
      if (initObj.hasOwnProperty('target_position')) {
        this.target_position = initObj.target_position
      }
      else {
        this.target_position = new geometry_msgs.msg.Pose();
      }
      if (initObj.hasOwnProperty('target_object')) {
        this.target_object = initObj.target_object
      }
      else {
        this.target_object = '';
      }
      if (initObj.hasOwnProperty('task_state')) {
        this.task_state = initObj.task_state
      }
      else {
        this.task_state = 0;
      }
      if (initObj.hasOwnProperty('task_result')) {
        this.task_result = initObj.task_result
      }
      else {
        this.task_result = 0;
      }
      if (initObj.hasOwnProperty('isInPlaceRotation')) {
        this.isInPlaceRotation = initObj.isInPlaceRotation
      }
      else {
        this.isInPlaceRotation = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type TaskList
    // Serialize message field [task_id]
    bufferOffset = _serializer.uint64(obj.task_id, buffer, bufferOffset);
    // Serialize message field [task_type]
    bufferOffset = _serializer.uint32(obj.task_type, buffer, bufferOffset);
    // Serialize message field [target_position]
    bufferOffset = geometry_msgs.msg.Pose.serialize(obj.target_position, buffer, bufferOffset);
    // Serialize message field [target_object]
    bufferOffset = _serializer.string(obj.target_object, buffer, bufferOffset);
    // Serialize message field [task_state]
    bufferOffset = _serializer.uint8(obj.task_state, buffer, bufferOffset);
    // Serialize message field [task_result]
    bufferOffset = _serializer.uint8(obj.task_result, buffer, bufferOffset);
    // Serialize message field [isInPlaceRotation]
    bufferOffset = _serializer.uint8(obj.isInPlaceRotation, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type TaskList
    let len;
    let data = new TaskList(null);
    // Deserialize message field [task_id]
    data.task_id = _deserializer.uint64(buffer, bufferOffset);
    // Deserialize message field [task_type]
    data.task_type = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [target_position]
    data.target_position = geometry_msgs.msg.Pose.deserialize(buffer, bufferOffset);
    // Deserialize message field [target_object]
    data.target_object = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [task_state]
    data.task_state = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [task_result]
    data.task_result = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [isInPlaceRotation]
    data.isInPlaceRotation = _deserializer.uint8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.target_object);
    return length + 75;
  }

  static datatype() {
    // Returns string type for a message object
    return 'perception_msgs/TaskList';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '72dfea7a02287e1a585c8d273011f6e9';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # Task Id
    uint64 task_id
    
    # Task Type
    uint32 task_type
    
    # Target Position
    geometry_msgs/Pose target_position
    
    # Target Object
    string target_object
    
    # Task State
    uint8 task_state
    
    # Task Result
    uint8 task_result
    
    # 到达终点是否原地打转
    uint8 isInPlaceRotation 
    
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new TaskList(null);
    if (msg.task_id !== undefined) {
      resolved.task_id = msg.task_id;
    }
    else {
      resolved.task_id = 0
    }

    if (msg.task_type !== undefined) {
      resolved.task_type = msg.task_type;
    }
    else {
      resolved.task_type = 0
    }

    if (msg.target_position !== undefined) {
      resolved.target_position = geometry_msgs.msg.Pose.Resolve(msg.target_position)
    }
    else {
      resolved.target_position = new geometry_msgs.msg.Pose()
    }

    if (msg.target_object !== undefined) {
      resolved.target_object = msg.target_object;
    }
    else {
      resolved.target_object = ''
    }

    if (msg.task_state !== undefined) {
      resolved.task_state = msg.task_state;
    }
    else {
      resolved.task_state = 0
    }

    if (msg.task_result !== undefined) {
      resolved.task_result = msg.task_result;
    }
    else {
      resolved.task_result = 0
    }

    if (msg.isInPlaceRotation !== undefined) {
      resolved.isInPlaceRotation = msg.isInPlaceRotation;
    }
    else {
      resolved.isInPlaceRotation = 0
    }

    return resolved;
    }
};

module.exports = TaskList;
