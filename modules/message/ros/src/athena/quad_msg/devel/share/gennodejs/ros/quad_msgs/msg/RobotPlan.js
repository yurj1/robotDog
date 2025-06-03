// Auto-generated. Do not edit!

// (in-package quad_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let RobotState = require('./RobotState.js');
let GRFArray = require('./GRFArray.js');
let RobotPlanDiagnostics = require('./RobotPlanDiagnostics.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class RobotPlan {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.global_plan_timestamp = null;
      this.state_timestamp = null;
      this.states = null;
      this.grfs = null;
      this.plan_indices = null;
      this.primitive_ids = null;
      this.compute_time = null;
      this.diagnostics = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('global_plan_timestamp')) {
        this.global_plan_timestamp = initObj.global_plan_timestamp
      }
      else {
        this.global_plan_timestamp = {secs: 0, nsecs: 0};
      }
      if (initObj.hasOwnProperty('state_timestamp')) {
        this.state_timestamp = initObj.state_timestamp
      }
      else {
        this.state_timestamp = {secs: 0, nsecs: 0};
      }
      if (initObj.hasOwnProperty('states')) {
        this.states = initObj.states
      }
      else {
        this.states = [];
      }
      if (initObj.hasOwnProperty('grfs')) {
        this.grfs = initObj.grfs
      }
      else {
        this.grfs = [];
      }
      if (initObj.hasOwnProperty('plan_indices')) {
        this.plan_indices = initObj.plan_indices
      }
      else {
        this.plan_indices = [];
      }
      if (initObj.hasOwnProperty('primitive_ids')) {
        this.primitive_ids = initObj.primitive_ids
      }
      else {
        this.primitive_ids = [];
      }
      if (initObj.hasOwnProperty('compute_time')) {
        this.compute_time = initObj.compute_time
      }
      else {
        this.compute_time = 0.0;
      }
      if (initObj.hasOwnProperty('diagnostics')) {
        this.diagnostics = initObj.diagnostics
      }
      else {
        this.diagnostics = new RobotPlanDiagnostics();
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type RobotPlan
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [global_plan_timestamp]
    bufferOffset = _serializer.time(obj.global_plan_timestamp, buffer, bufferOffset);
    // Serialize message field [state_timestamp]
    bufferOffset = _serializer.time(obj.state_timestamp, buffer, bufferOffset);
    // Serialize message field [states]
    // Serialize the length for message field [states]
    bufferOffset = _serializer.uint32(obj.states.length, buffer, bufferOffset);
    obj.states.forEach((val) => {
      bufferOffset = RobotState.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [grfs]
    // Serialize the length for message field [grfs]
    bufferOffset = _serializer.uint32(obj.grfs.length, buffer, bufferOffset);
    obj.grfs.forEach((val) => {
      bufferOffset = GRFArray.serialize(val, buffer, bufferOffset);
    });
    // Serialize message field [plan_indices]
    bufferOffset = _arraySerializer.uint32(obj.plan_indices, buffer, bufferOffset, null);
    // Serialize message field [primitive_ids]
    bufferOffset = _arraySerializer.uint32(obj.primitive_ids, buffer, bufferOffset, null);
    // Serialize message field [compute_time]
    bufferOffset = _serializer.float64(obj.compute_time, buffer, bufferOffset);
    // Serialize message field [diagnostics]
    bufferOffset = RobotPlanDiagnostics.serialize(obj.diagnostics, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type RobotPlan
    let len;
    let data = new RobotPlan(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [global_plan_timestamp]
    data.global_plan_timestamp = _deserializer.time(buffer, bufferOffset);
    // Deserialize message field [state_timestamp]
    data.state_timestamp = _deserializer.time(buffer, bufferOffset);
    // Deserialize message field [states]
    // Deserialize array length for message field [states]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.states = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.states[i] = RobotState.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [grfs]
    // Deserialize array length for message field [grfs]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.grfs = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.grfs[i] = GRFArray.deserialize(buffer, bufferOffset)
    }
    // Deserialize message field [plan_indices]
    data.plan_indices = _arrayDeserializer.uint32(buffer, bufferOffset, null)
    // Deserialize message field [primitive_ids]
    data.primitive_ids = _arrayDeserializer.uint32(buffer, bufferOffset, null)
    // Deserialize message field [compute_time]
    data.compute_time = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [diagnostics]
    data.diagnostics = RobotPlanDiagnostics.deserialize(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    object.states.forEach((val) => {
      length += RobotState.getMessageSize(val);
    });
    object.grfs.forEach((val) => {
      length += GRFArray.getMessageSize(val);
    });
    length += 4 * object.plan_indices.length;
    length += 4 * object.primitive_ids.length;
    length += RobotPlanDiagnostics.getMessageSize(object.diagnostics);
    return length + 40;
  }

  static datatype() {
    // Returns string type for a message object
    return 'quad_msgs/RobotPlan';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '8de5642b258cdd451a16eb8e7e249612';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    # This is a message to hold a robot plan
    #
    # The plan is defined as an array of odometry messages.
    # Accurate timing information for localization is stored in the header.
    # This should match the first state in the states vector.
    
    Header header
    time global_plan_timestamp
    time state_timestamp
    quad_msgs/RobotState[] states
    quad_msgs/GRFArray[] grfs
    uint32[] plan_indices
    uint32[] primitive_ids
    float64 compute_time
    quad_msgs/RobotPlanDiagnostics diagnostics
    
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
    MSG: quad_msgs/RobotState
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
    ================================================================================
    MSG: quad_msgs/GRFArray
    # This is a message to hold an array of ground reaction forces and their points of application
    #
    # Accurate timing information is stored in the header.
    
    Header header
    geometry_msgs/Vector3[] vectors
    geometry_msgs/Point[] points
    bool[] contact_states
    uint32 traj_index
    ================================================================================
    MSG: quad_msgs/RobotPlanDiagnostics
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
    const resolved = new RobotPlan(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.global_plan_timestamp !== undefined) {
      resolved.global_plan_timestamp = msg.global_plan_timestamp;
    }
    else {
      resolved.global_plan_timestamp = {secs: 0, nsecs: 0}
    }

    if (msg.state_timestamp !== undefined) {
      resolved.state_timestamp = msg.state_timestamp;
    }
    else {
      resolved.state_timestamp = {secs: 0, nsecs: 0}
    }

    if (msg.states !== undefined) {
      resolved.states = new Array(msg.states.length);
      for (let i = 0; i < resolved.states.length; ++i) {
        resolved.states[i] = RobotState.Resolve(msg.states[i]);
      }
    }
    else {
      resolved.states = []
    }

    if (msg.grfs !== undefined) {
      resolved.grfs = new Array(msg.grfs.length);
      for (let i = 0; i < resolved.grfs.length; ++i) {
        resolved.grfs[i] = GRFArray.Resolve(msg.grfs[i]);
      }
    }
    else {
      resolved.grfs = []
    }

    if (msg.plan_indices !== undefined) {
      resolved.plan_indices = msg.plan_indices;
    }
    else {
      resolved.plan_indices = []
    }

    if (msg.primitive_ids !== undefined) {
      resolved.primitive_ids = msg.primitive_ids;
    }
    else {
      resolved.primitive_ids = []
    }

    if (msg.compute_time !== undefined) {
      resolved.compute_time = msg.compute_time;
    }
    else {
      resolved.compute_time = 0.0
    }

    if (msg.diagnostics !== undefined) {
      resolved.diagnostics = RobotPlanDiagnostics.Resolve(msg.diagnostics)
    }
    else {
      resolved.diagnostics = new RobotPlanDiagnostics()
    }

    return resolved;
    }
};

module.exports = RobotPlan;
