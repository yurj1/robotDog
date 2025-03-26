// Auto-generated. Do not edit!

// (in-package perception_msgs.srv)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------


//-----------------------------------------------------------

class RecordBagRequest {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.bagMode = null;
      this.bagName = null;
      this.topics = null;
      this.bashName = null;
    }
    else {
      if (initObj.hasOwnProperty('bagMode')) {
        this.bagMode = initObj.bagMode
      }
      else {
        this.bagMode = 0;
      }
      if (initObj.hasOwnProperty('bagName')) {
        this.bagName = initObj.bagName
      }
      else {
        this.bagName = '';
      }
      if (initObj.hasOwnProperty('topics')) {
        this.topics = initObj.topics
      }
      else {
        this.topics = [];
      }
      if (initObj.hasOwnProperty('bashName')) {
        this.bashName = initObj.bashName
      }
      else {
        this.bashName = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type RecordBagRequest
    // Serialize message field [bagMode]
    bufferOffset = _serializer.uint8(obj.bagMode, buffer, bufferOffset);
    // Serialize message field [bagName]
    bufferOffset = _serializer.string(obj.bagName, buffer, bufferOffset);
    // Serialize message field [topics]
    bufferOffset = _arraySerializer.string(obj.topics, buffer, bufferOffset, null);
    // Serialize message field [bashName]
    bufferOffset = _serializer.string(obj.bashName, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type RecordBagRequest
    let len;
    let data = new RecordBagRequest(null);
    // Deserialize message field [bagMode]
    data.bagMode = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [bagName]
    data.bagName = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [topics]
    data.topics = _arrayDeserializer.string(buffer, bufferOffset, null)
    // Deserialize message field [bashName]
    data.bashName = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.bagName);
    object.topics.forEach((val) => {
      length += 4 + _getByteLength(val);
    });
    length += _getByteLength(object.bashName);
    return length + 13;
  }

  static datatype() {
    // Returns string type for a service object
    return 'perception_msgs/RecordBagRequest';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '435df60b084d02339cae3ad06a32a529';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint8 bagMode #0: 结束  1: 自定义录包 2： 执行脚本录包
    # type1 
    string bagName #包名
    string[] topics #录制的所有话题
    # type2
    string bashName #脚本名
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new RecordBagRequest(null);
    if (msg.bagMode !== undefined) {
      resolved.bagMode = msg.bagMode;
    }
    else {
      resolved.bagMode = 0
    }

    if (msg.bagName !== undefined) {
      resolved.bagName = msg.bagName;
    }
    else {
      resolved.bagName = ''
    }

    if (msg.topics !== undefined) {
      resolved.topics = msg.topics;
    }
    else {
      resolved.topics = []
    }

    if (msg.bashName !== undefined) {
      resolved.bashName = msg.bashName;
    }
    else {
      resolved.bashName = ''
    }

    return resolved;
    }
};

class RecordBagResponse {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.success = null;
      this.errorInfo = null;
    }
    else {
      if (initObj.hasOwnProperty('success')) {
        this.success = initObj.success
      }
      else {
        this.success = false;
      }
      if (initObj.hasOwnProperty('errorInfo')) {
        this.errorInfo = initObj.errorInfo
      }
      else {
        this.errorInfo = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type RecordBagResponse
    // Serialize message field [success]
    bufferOffset = _serializer.bool(obj.success, buffer, bufferOffset);
    // Serialize message field [errorInfo]
    bufferOffset = _serializer.string(obj.errorInfo, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type RecordBagResponse
    let len;
    let data = new RecordBagResponse(null);
    // Deserialize message field [success]
    data.success = _deserializer.bool(buffer, bufferOffset);
    // Deserialize message field [errorInfo]
    data.errorInfo = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.errorInfo);
    return length + 5;
  }

  static datatype() {
    // Returns string type for a service object
    return 'perception_msgs/RecordBagResponse';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c788a6db5b022104b38e4d448cc93ef8';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    bool success
    string errorInfo
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new RecordBagResponse(null);
    if (msg.success !== undefined) {
      resolved.success = msg.success;
    }
    else {
      resolved.success = false
    }

    if (msg.errorInfo !== undefined) {
      resolved.errorInfo = msg.errorInfo;
    }
    else {
      resolved.errorInfo = ''
    }

    return resolved;
    }
};

module.exports = {
  Request: RecordBagRequest,
  Response: RecordBagResponse,
  md5sum() { return '0e3c6c8f89a4078d1c2279ef76b31bf7'; },
  datatype() { return 'perception_msgs/RecordBag'; }
};
