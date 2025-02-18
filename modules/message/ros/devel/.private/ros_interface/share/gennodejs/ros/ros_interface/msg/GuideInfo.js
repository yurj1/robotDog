// Auto-generated. Do not edit!

// (in-package ros_interface.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let GuideRoad = require('./GuideRoad.js');
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class GuideInfo {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.next_dis = null;
      this.current_road = null;
      this.next_road = null;
      this.round_status = null;
      this.intersection_status = null;
      this.roads_status = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('next_dis')) {
        this.next_dis = initObj.next_dis
      }
      else {
        this.next_dis = 0.0;
      }
      if (initObj.hasOwnProperty('current_road')) {
        this.current_road = initObj.current_road
      }
      else {
        this.current_road = new GuideRoad();
      }
      if (initObj.hasOwnProperty('next_road')) {
        this.next_road = initObj.next_road
      }
      else {
        this.next_road = new GuideRoad();
      }
      if (initObj.hasOwnProperty('round_status')) {
        this.round_status = initObj.round_status
      }
      else {
        this.round_status = 0;
      }
      if (initObj.hasOwnProperty('intersection_status')) {
        this.intersection_status = initObj.intersection_status
      }
      else {
        this.intersection_status = 0;
      }
      if (initObj.hasOwnProperty('roads_status')) {
        this.roads_status = initObj.roads_status
      }
      else {
        this.roads_status = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GuideInfo
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [next_dis]
    bufferOffset = _serializer.float64(obj.next_dis, buffer, bufferOffset);
    // Serialize message field [current_road]
    bufferOffset = GuideRoad.serialize(obj.current_road, buffer, bufferOffset);
    // Serialize message field [next_road]
    bufferOffset = GuideRoad.serialize(obj.next_road, buffer, bufferOffset);
    // Serialize message field [round_status]
    bufferOffset = _serializer.int8(obj.round_status, buffer, bufferOffset);
    // Serialize message field [intersection_status]
    bufferOffset = _serializer.int8(obj.intersection_status, buffer, bufferOffset);
    // Serialize message field [roads_status]
    bufferOffset = _serializer.int8(obj.roads_status, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GuideInfo
    let len;
    let data = new GuideInfo(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [next_dis]
    data.next_dis = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [current_road]
    data.current_road = GuideRoad.deserialize(buffer, bufferOffset);
    // Deserialize message field [next_road]
    data.next_road = GuideRoad.deserialize(buffer, bufferOffset);
    // Deserialize message field [round_status]
    data.round_status = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [intersection_status]
    data.intersection_status = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [roads_status]
    data.roads_status = _deserializer.int8(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += GuideRoad.getMessageSize(object.current_road);
    length += GuideRoad.getMessageSize(object.next_road);
    return length + 11;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ros_interface/GuideInfo';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'aa74d1653e11a6cb191e3ce919a1654f';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    Header   header     # 头部信息
    float64   next_dis     # 下一条规划路线上道路的距离
    GuideRoad   current_road     # 当前道路的引导信息
    GuideRoad   next_road     # 下一条规划道路的引导信息
    int8   round_status     # 环岛状态: 0：未知或非环岛状态 1：当前为非环岛道路并且规划路线即将驶入环岛主路 2：当前道路类型是环岛并且规划路线还是在环岛主路中行驶 3：当前道路类型是环岛并且规划路线即将驶出环岛主路
    int8   intersection_status     # 交叉路口状态: 0：未知 1：非交叉路口状态 2：交叉路口通行状态
    int8   roads_status     # 主辅路状态： 0：未知或非主辅路状态 1：当前道路类型是辅路下一条道路类型是主路  2：当前道路类型是主路下一条道路类型是辅路
    
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
    MSG: ros_interface/GuideRoad
    int64   road_id     # 道路的id
    int8   road_type     # 道路的类型: 0：未知或一般道路  1：环岛 2：交叉路口 3：主路 4：辅路
    int8   turn_type     # 规划路线上道路的转向信息 1：左转 2：直行 3：右转
    float64   avg_curvature     # 道路的平均曲率
    int32   curvature_size     # 道路中心线上点(曲率)数量
    CurvatureInfo[] curvature # 道路曲率信息数组
    
    ================================================================================
    MSG: ros_interface/CurvatureInfo
    float64   offset     # 道路中心线上点位于该道路的位置（与道路起点的距离）
    float64   value     # 道路中心线上点的曲率值
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new GuideInfo(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.next_dis !== undefined) {
      resolved.next_dis = msg.next_dis;
    }
    else {
      resolved.next_dis = 0.0
    }

    if (msg.current_road !== undefined) {
      resolved.current_road = GuideRoad.Resolve(msg.current_road)
    }
    else {
      resolved.current_road = new GuideRoad()
    }

    if (msg.next_road !== undefined) {
      resolved.next_road = GuideRoad.Resolve(msg.next_road)
    }
    else {
      resolved.next_road = new GuideRoad()
    }

    if (msg.round_status !== undefined) {
      resolved.round_status = msg.round_status;
    }
    else {
      resolved.round_status = 0
    }

    if (msg.intersection_status !== undefined) {
      resolved.intersection_status = msg.intersection_status;
    }
    else {
      resolved.intersection_status = 0
    }

    if (msg.roads_status !== undefined) {
      resolved.roads_status = msg.roads_status;
    }
    else {
      resolved.roads_status = 0
    }

    return resolved;
    }
};

module.exports = GuideInfo;
