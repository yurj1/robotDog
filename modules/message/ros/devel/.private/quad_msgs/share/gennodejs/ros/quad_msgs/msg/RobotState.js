// Auto-generated. Do not edit!

// (in-package quad_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let BodyState = require('./BodyState.js');
let MultiFootState = require('./MultiFootState.js');
let sensor_msgs = _finder('sensor_msgs');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class RobotState {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.traj_index = null;
      this.body = null;
      this.joints = null;
      this.feet = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('traj_index')) {
        this.traj_index = initObj.traj_index
      }
      else {
        this.traj_index = 0;
      }
      if (initObj.hasOwnProperty('body')) {
        this.body = initObj.body
      }
      else {
        this.body = new BodyState();
      }
      if (initObj.hasOwnProperty('joints')) {
        this.joints = initObj.joints
      }
      else {
        this.joints = new sensor_msgs.msg.JointState();
      }
      if (initObj.hasOwnProperty('feet')) {
        this.feet = initObj.feet
      }
      else {
        this.feet = new MultiFootState();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type RobotState
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [traj_index]
    bufferOffset = _serializer.uint32(obj.traj_index, buffer, bufferOffset);
    // Serialize message field [body]
    bufferOffset = BodyState.serialize(obj.body, buffer, bufferOffset);
    // Serialize message field [joints]
    bufferOffset = sensor_msgs.msg.JointState.serialize(obj.joints, buffer, bufferOffset);
    // Serialize message field [feet]
    bufferOffset = MultiFootState.serialize(obj.feet, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type RobotState
    let len;
    let data = new RobotState(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [traj_index]
    data.traj_index = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [body]
    data.body = BodyState.deserialize(buffer, bufferOffset);
    // Deserialize message field [joints]
    data.joints = sensor_msgs.msg.JointState.deserialize(buffer, bufferOffset);
    // Deserialize message field [feet]
    data.feet = MultiFootState.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += BodyState.getMessageSize(object.body);
    length += sensor_msgs.msg.JointState.getMessageSize(object.joints);
    length += MultiFootState.getMessageSize(object.feet);
    return length + 4;
  }

  static datatype() {
    // Returns string type for a message object
    return 'quad_msgs/RobotState';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '574a4aa128f06841e7a15be99c32c86c';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # This is a message to hold a robot state
    #
    # The state is defined as an Odometry message with the body odometry, and a JointState message with joint positions and velocities
    # Accurate timing information is stored in the header
    
    Header header
    uint32 traj_index
    quad_msgs/BodyState body
    sensor_msgs/JointState joints
    quad_msgs/MultiFootState feet
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
    MSG: quad_msgs/BodyState
    # This is a message to hold a robot body state
    #
    # The body state is defined as an pose and twist messages
    # Accurate timing information is stored in the header
    
    Header header
    uint32 traj_index
    geometry_msgs/Pose pose
    geometry_msgs/Twist twist
    
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
    MSG: geometry_msgs/Twist
    # This expresses velocity in free space broken into its linear and angular parts.
    Vector3  linear
    Vector3  angular
    
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
    MSG: sensor_msgs/JointState
    # This is a message that holds data to describe the state of a set of torque controlled joints. 
    #
    # The state of each joint (revolute or prismatic) is defined by:
    #  * the position of the joint (rad or m),
    #  * the velocity of the joint (rad/s or m/s) and 
    #  * the effort that is applied in the joint (Nm or N).
    #
    # Each joint is uniquely identified by its name
    # The header specifies the time at which the joint states were recorded. All the joint states
    # in one message have to be recorded at the same time.
    #
    # This message consists of a multiple arrays, one for each part of the joint state. 
    # The goal is to make each of the fields optional. When e.g. your joints have no
    # effort associated with them, you can leave the effort array empty. 
    #
    # All arrays in this message should have the same size, or be empty.
    # This is the only way to uniquely associate the joint name with the correct
    # states.
    
    
    Header header
    
    string[] name
    float64[] position
    float64[] velocity
    float64[] effort
    
    ================================================================================
    MSG: quad_msgs/MultiFootState
    # This is a message to hold the state of all feet of a legged robot
    #
    # The states of each foot are stored in a vector of FootState messages
    # (0 = front left, 1 = back left, 2 = front right, 3 = back right).
    # Accurate timing information is stored in the header
    
    Header header
    uint32 traj_index
    quad_msgs/FootState[] feet
    ================================================================================
    MSG: quad_msgs/FootState
    # This is a message to hold the state of a single foot of a legged robot
    #
    # The states of each foot are stored in a vector of FootState messages
    # Accurate timing information is stored in the header
    
    Header header
    uint32 traj_index
    geometry_msgs/Vector3 position
    geometry_msgs/Vector3 velocity
    geometry_msgs/Vector3 acceleration
    bool contact
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new RobotState(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.traj_index !== undefined) {
      resolved.traj_index = msg.traj_index;
    }
    else {
      resolved.traj_index = 0
    }

    if (msg.body !== undefined) {
      resolved.body = BodyState.Resolve(msg.body)
    }
    else {
      resolved.body = new BodyState()
    }

    if (msg.joints !== undefined) {
      resolved.joints = sensor_msgs.msg.JointState.Resolve(msg.joints)
    }
    else {
      resolved.joints = new sensor_msgs.msg.JointState()
    }

    if (msg.feet !== undefined) {
      resolved.feet = MultiFootState.Resolve(msg.feet)
    }
    else {
      resolved.feet = new MultiFootState()
    }

    return resolved;
    }
};

module.exports = RobotState;
