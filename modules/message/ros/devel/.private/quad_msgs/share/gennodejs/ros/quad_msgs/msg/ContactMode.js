// Auto-generated. Do not edit!

// (in-package quad_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let LegContactMode = require('./LegContactMode.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class ContactMode {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.leg_contacts = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('leg_contacts')) {
        this.leg_contacts = initObj.leg_contacts
      }
      else {
        this.leg_contacts = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type ContactMode
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [leg_contacts]
    // Serialize the length for message field [leg_contacts]
    bufferOffset = _serializer.uint32(obj.leg_contacts.length, buffer, bufferOffset);
    obj.leg_contacts.forEach((val) => {
      bufferOffset = LegContactMode.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type ContactMode
    let len;
    let data = new ContactMode(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [leg_contacts]
    // Deserialize array length for message field [leg_contacts]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.leg_contacts = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.leg_contacts[i] = LegContactMode.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    object.leg_contacts.forEach((val) => {
      length += LegContactMode.getMessageSize(val);
    });
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'quad_msgs/ContactMode';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '26ebde1d6ad14a11545e27eb1d085e28';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # This is a message to hold contact states of the robot
    Header header
    
    LegContactMode[] leg_contacts # FL Bl FR BR
    
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
    MSG: quad_msgs/LegContactMode
    # This is a message to hold contact mode of one leg
    Header header
    
    float32 contact_prob
    bool contact_state
    geometry_msgs/Vector3 contact_forces #fx,fy,fz
    
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
    const resolved = new ContactMode(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.leg_contacts !== undefined) {
      resolved.leg_contacts = new Array(msg.leg_contacts.length);
      for (let i = 0; i < resolved.leg_contacts.length; ++i) {
        resolved.leg_contacts[i] = LegContactMode.Resolve(msg.leg_contacts[i]);
      }
    }
    else {
      resolved.leg_contacts = []
    }

    return resolved;
    }
};

module.exports = ContactMode;
