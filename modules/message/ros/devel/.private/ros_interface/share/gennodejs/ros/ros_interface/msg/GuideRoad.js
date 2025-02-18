// Auto-generated. Do not edit!

// (in-package ros_interface.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let CurvatureInfo = require('./CurvatureInfo.js');

//-----------------------------------------------------------

class GuideRoad {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.road_id = null;
      this.road_type = null;
      this.turn_type = null;
      this.avg_curvature = null;
      this.curvature_size = null;
      this.curvature = null;
    }
    else {
      if (initObj.hasOwnProperty('road_id')) {
        this.road_id = initObj.road_id
      }
      else {
        this.road_id = 0;
      }
      if (initObj.hasOwnProperty('road_type')) {
        this.road_type = initObj.road_type
      }
      else {
        this.road_type = 0;
      }
      if (initObj.hasOwnProperty('turn_type')) {
        this.turn_type = initObj.turn_type
      }
      else {
        this.turn_type = 0;
      }
      if (initObj.hasOwnProperty('avg_curvature')) {
        this.avg_curvature = initObj.avg_curvature
      }
      else {
        this.avg_curvature = 0.0;
      }
      if (initObj.hasOwnProperty('curvature_size')) {
        this.curvature_size = initObj.curvature_size
      }
      else {
        this.curvature_size = 0;
      }
      if (initObj.hasOwnProperty('curvature')) {
        this.curvature = initObj.curvature
      }
      else {
        this.curvature = [];
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type GuideRoad
    // Serialize message field [road_id]
    bufferOffset = _serializer.int64(obj.road_id, buffer, bufferOffset);
    // Serialize message field [road_type]
    bufferOffset = _serializer.int8(obj.road_type, buffer, bufferOffset);
    // Serialize message field [turn_type]
    bufferOffset = _serializer.int8(obj.turn_type, buffer, bufferOffset);
    // Serialize message field [avg_curvature]
    bufferOffset = _serializer.float64(obj.avg_curvature, buffer, bufferOffset);
    // Serialize message field [curvature_size]
    bufferOffset = _serializer.int32(obj.curvature_size, buffer, bufferOffset);
    // Serialize message field [curvature]
    // Serialize the length for message field [curvature]
    bufferOffset = _serializer.uint32(obj.curvature.length, buffer, bufferOffset);
    obj.curvature.forEach((val) => {
      bufferOffset = CurvatureInfo.serialize(val, buffer, bufferOffset);
    });
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type GuideRoad
    let len;
    let data = new GuideRoad(null);
    // Deserialize message field [road_id]
    data.road_id = _deserializer.int64(buffer, bufferOffset);
    // Deserialize message field [road_type]
    data.road_type = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [turn_type]
    data.turn_type = _deserializer.int8(buffer, bufferOffset);
    // Deserialize message field [avg_curvature]
    data.avg_curvature = _deserializer.float64(buffer, bufferOffset);
    // Deserialize message field [curvature_size]
    data.curvature_size = _deserializer.int32(buffer, bufferOffset);
    // Deserialize message field [curvature]
    // Deserialize array length for message field [curvature]
    len = _deserializer.uint32(buffer, bufferOffset);
    data.curvature = new Array(len);
    for (let i = 0; i < len; ++i) {
      data.curvature[i] = CurvatureInfo.deserialize(buffer, bufferOffset)
    }
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += 16 * object.curvature.length;
    return length + 26;
  }

  static datatype() {
    // Returns string type for a message object
    return 'ros_interface/GuideRoad';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '2111a81fc9be87fa69598a4bd29fcca4';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
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
    const resolved = new GuideRoad(null);
    if (msg.road_id !== undefined) {
      resolved.road_id = msg.road_id;
    }
    else {
      resolved.road_id = 0
    }

    if (msg.road_type !== undefined) {
      resolved.road_type = msg.road_type;
    }
    else {
      resolved.road_type = 0
    }

    if (msg.turn_type !== undefined) {
      resolved.turn_type = msg.turn_type;
    }
    else {
      resolved.turn_type = 0
    }

    if (msg.avg_curvature !== undefined) {
      resolved.avg_curvature = msg.avg_curvature;
    }
    else {
      resolved.avg_curvature = 0.0
    }

    if (msg.curvature_size !== undefined) {
      resolved.curvature_size = msg.curvature_size;
    }
    else {
      resolved.curvature_size = 0
    }

    if (msg.curvature !== undefined) {
      resolved.curvature = new Array(msg.curvature.length);
      for (let i = 0; i < resolved.curvature.length; ++i) {
        resolved.curvature[i] = CurvatureInfo.Resolve(msg.curvature[i]);
      }
    }
    else {
      resolved.curvature = []
    }

    return resolved;
    }
};

module.exports = GuideRoad;
