// Auto-generated. Do not edit!

// (in-package quad_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let geometry_msgs = _finder('geometry_msgs');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class GRFArray {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.vectors = null;
      this.points = null;
      this.contact_states = null;
      this.traj_index = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('vectors')) {
        this.vectors = initObj.vectors
      }
      else {
        this.vectors = [];
      }
      if (initObj.hasOwnProperty('points')) {
        this.points = initObj.points
      }
      else {
        this.points = [];
      }
      if (initObj.hasOwnProperty('contact_states')) {
        this.contact_states = initObj.contact_states
      }
      else {
        this.contact_states = [];
      }
      if (initObj.hasOwnProperty('traj_index')) {
        this.traj_index = initObj.traj_index
      }
      else {
        this.traj_index = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GRFArray
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [vectors]
    // Serialize the length for message field [vectors]
    bufferOffset = _serializer.uint32(obj.vectors.length, buffer, bufferOffset);
    obj.vectors.forEach((val) => {
      bufferOffset = geometry_msgs.msg.Vector3.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [points]
    // Serialize the length for message field [points]
    bufferOffset = _serializer.uint32(obj.points.length, buffer, bufferOffset);
    obj.points.forEach((val) => {
      bufferOffset = geometry_msgs.msg.Point.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [contact_states]
    bufferOffset = _arraySerializer.bool(obj.contact_states, buffer, bufferOffset, null);
    // Serialize message field [traj_index]
    bufferOffset = _serializer.uint32(obj.traj_index, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GRFArray
    let len;
    let data = new GRFArray(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [vectors]
    // Deserialize array length for message field [vectors]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.vectors = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.vectors[i] = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [points]
    // Deserialize array length for message field [points]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.points = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.points[i] = geometry_msgs.msg.Point.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [contact_states]
    data.contact_states = _arrayDeserializer.bool(buffer, bufferOffset, null)
    // Deserialize message field [traj_index]
    data.traj_index = _deserializer.uint32(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += 24 * object.vectors.length;
    length += 24 * object.points.length;
    length += object.contact_states.length;
    return length + 16;
  }

  static datatype() {
    // Returns string type for a message object
    return 'quad_msgs/GRFArray';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'e3a7d93ab37eb491eee31b8dde628447';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # This is a message to hold an array of ground reaction forces and their points of application
    #
    # Accurate timing information is stored in the header.
    
    Header header
    geometry_msgs/Vector3[] vectors
    geometry_msgs/Point[] points
    bool[] contact_states
    uint32 traj_index
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
    MSG: geometry_msgs/Vector3
    # This represents a vector in free space. 
    # It is only meant to represent a direction. Therefore, it does not
    # make sense to apply a translation to it (e.g., when applying a 
    # generic rigid transformation to a Vector3, tf2 will only apply the
    # rotation). If you want your data to be translatable too, use the
    # geometry_msgs/Point message instead.
    
    float64 x
    float64 y
    float64 z
    ================================================================================
    MSG: geometry_msgs/Point
    # This contains the position of a point in free space
    float64 x
    float64 y
    float64 z
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GRFArray(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.vectors !== undefined) {
      resolved.vectors = new Array(msg.vectors.length);
      for (let i = 0; i < resolved.vectors.length; ++i) {
        resolved.vectors[i] = geometry_msgs.msg.Vector3.Resolve(msg.vectors[i]);
      }
    }
    else {
      resolved.vectors = []
    }

    if (msg.points !== undefined) {
      resolved.points = new Array(msg.points.length);
      for (let i = 0; i < resolved.points.length; ++i) {
        resolved.points[i] = geometry_msgs.msg.Point.Resolve(msg.points[i]);
      }
    }
    else {
      resolved.points = []
    }

    if (msg.contact_states !== undefined) {
      resolved.contact_states = msg.contact_states;
    }
    else {
      resolved.contact_states = []
    }

    if (msg.traj_index !== undefined) {
      resolved.traj_index = msg.traj_index;
    }
    else {
      resolved.traj_index = 0
    }

    return resolved;
    }
};

module.exports = GRFArray;
