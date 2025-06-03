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
let geometry_msgs = _finder('geometry_msgs');

//-----------------------------------------------------------

class LegContactMode {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.contact_prob = null;
      this.contact_state = null;
      this.contact_forces = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('contact_prob')) {
        this.contact_prob = initObj.contact_prob
      }
      else {
        this.contact_prob = 0.0;
      }
      if (initObj.hasOwnProperty('contact_state')) {
        this.contact_state = initObj.contact_state
      }
      else {
        this.contact_state = false;
      }
      if (initObj.hasOwnProperty('contact_forces')) {
        this.contact_forces = initObj.contact_forces
      }
      else {
        this.contact_forces = new geometry_msgs.msg.Vector3();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type LegContactMode
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [contact_prob]
    bufferOffset = _serializer.float32(obj.contact_prob, buffer, bufferOffset);
    // Serialize message field [contact_state]
    bufferOffset = _serializer.bool(obj.contact_state, buffer, bufferOffset);
    // Serialize message field [contact_forces]
    bufferOffset = geometry_msgs.msg.Vector3.serialize(obj.contact_forces, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type LegContactMode
    let len;
    let data = new LegContactMode(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [contact_prob]
    data.contact_prob = _deserializer.float32(buffer, bufferOffset);
    // Deserialize message field [contact_state]
    data.contact_state = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [contact_forces]
    data.contact_forces = geometry_msgs.msg.Vector3.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    return length + 29;
  }

  static datatype() {
    // Returns string type for a message object
    return 'quad_msgs/LegContactMode';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '46ad19315dce64937e892556c64f6977';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # This is a message to hold contact mode of one leg
    Header header
    
    float32 contact_prob
    bool contact_state
    geometry_msgs/Vector3 contact_forces #fx,fy,fz
    
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
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new LegContactMode(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.contact_prob !== undefined) {
      resolved.contact_prob = msg.contact_prob;
    }
    else {
      resolved.contact_prob = 0.0
    }

    if (msg.contact_state !== undefined) {
      resolved.contact_state = msg.contact_state;
    }
    else {
      resolved.contact_state = false
    }

    if (msg.contact_forces !== undefined) {
      resolved.contact_forces = geometry_msgs.msg.Vector3.Resolve(msg.contact_forces)
    }
    else {
      resolved.contact_forces = new geometry_msgs.msg.Vector3()
    }

    return resolved;
    }
};

module.exports = LegContactMode;
