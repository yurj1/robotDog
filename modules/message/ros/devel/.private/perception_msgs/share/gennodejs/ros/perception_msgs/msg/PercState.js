// Auto-generated. Do not edit!

// (in-package perception_msgs.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;
let std_msgs = _finder('std_msgs');

//-----------------------------------------------------------

class PercState {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.header = null;
      this.action_id = null;
      this.perc_kind = null;
      this.exe_state = null;
      this.exe_result = null;
      this.err_code = null;
      this.err_info = null;
      this.wait_for_millisec = null;
    }
    else {
      if (initObj.hasOwnProperty('header')) {
        this.header = initObj.header
      }
      else {
        this.header = new std_msgs.msg.Header();
      }
      if (initObj.hasOwnProperty('action_id')) {
        this.action_id = initObj.action_id
      }
      else {
        this.action_id = 0;
      }
      if (initObj.hasOwnProperty('perc_kind')) {
        this.perc_kind = initObj.perc_kind
      }
      else {
        this.perc_kind = 0;
      }
      if (initObj.hasOwnProperty('exe_state')) {
        this.exe_state = initObj.exe_state
      }
      else {
        this.exe_state = 0;
      }
      if (initObj.hasOwnProperty('exe_result')) {
        this.exe_result = initObj.exe_result
      }
      else {
        this.exe_result = 0;
      }
      if (initObj.hasOwnProperty('err_code')) {
        this.err_code = initObj.err_code
      }
      else {
        this.err_code = 0;
      }
      if (initObj.hasOwnProperty('err_info')) {
        this.err_info = initObj.err_info
      }
      else {
        this.err_info = '';
      }
      if (initObj.hasOwnProperty('wait_for_millisec')) {
        this.wait_for_millisec = initObj.wait_for_millisec
      }
      else {
        this.wait_for_millisec = 0;
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type PercState
    // Serialize message field [header]
    bufferOffset = std_msgs.msg.Header.serialize(obj.header, buffer, bufferOffset);
    // Serialize message field [action_id]
    bufferOffset = _serializer.uint64(obj.action_id, buffer, bufferOffset);
    // Serialize message field [perc_kind]
    bufferOffset = _serializer.uint32(obj.perc_kind, buffer, bufferOffset);
    // Serialize message field [exe_state]
    bufferOffset = _serializer.uint8(obj.exe_state, buffer, bufferOffset);
    // Serialize message field [exe_result]
    bufferOffset = _serializer.uint8(obj.exe_result, buffer, bufferOffset);
    // Serialize message field [err_code]
    bufferOffset = _serializer.uint16(obj.err_code, buffer, bufferOffset);
    // Serialize message field [err_info]
    bufferOffset = _serializer.string(obj.err_info, buffer, bufferOffset);
    // Serialize message field [wait_for_millisec]
    bufferOffset = _serializer.uint64(obj.wait_for_millisec, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type PercState
    let len;
    let data = new PercState(null);
    // Deserialize message field [header]
    data.header = std_msgs.msg.Header.deserialize(buffer, bufferOffset);
    // Deserialize message field [action_id]
    data.action_id = _deserializer.uint64(buffer, bufferOffset);
    // Deserialize message field [perc_kind]
    data.perc_kind = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [exe_state]
    data.exe_state = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [exe_result]
    data.exe_result = _deserializer.uint8(buffer, bufferOffset);
    // Deserialize message field [err_code]
    data.err_code = _deserializer.uint16(buffer, bufferOffset);
    // Deserialize message field [err_info]
    data.err_info = _deserializer.string(buffer, bufferOffset);
    // Deserialize message field [wait_for_millisec]
    data.wait_for_millisec = _deserializer.uint64(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += std_msgs.msg.Header.getMessageSize(object.header);
    length += _getByteLength(object.err_info);
    return length + 28;
  }

  static datatype() {
    // Returns string type for a message object
    return 'perception_msgs/PercState';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return '54333f0d38bd18fb2d888adabbf15a33';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    std_msgs/Header header
    
    # ActionState
    uint8 ACTION_IDLE = 0
    uint8 ACTION_RUNNING = 1
    uint8 ACTION_DONE = 2
    
    # ActionResult
    uint8 ACTION_NONE = 0
    uint8 ACTION_SUCCESS = 1
    uint8 ACTION_FAIL = 2
    
    # ErrCode
    uint16 ACTION_ERR_NONE = 0
    uint16 ACTION_ERR_NOWORK = 1
    
    # 当前执行的id
    uint64 action_id
    
    
    # Perceive Kind
    uint32 PERC_DEST                 = 1
    uint32 PERC_ABS                  = 2
    uint32 PERC_REL                  = 3
    
    # 自动充电
    uint32 PERC_AUTO_CHARGING        = 20
    # 环境查看
    uint32 PERC_CHECK_ENV            = 21
    # 自动建图
    uint32 PERC_AUTO_MAPPING         = 22
    
    # 跟随模式
    uint32 PERC_FOLLOW               = 30
    # 陌生人迎接
    uint32 PERC_STRANGER_WELCOME     = 31
    # 主人迎接
    uint32 PERC_OWNER_WELCOME        = 32
    # 行为互动
    uint32 PERC_BEHAVIOR_INTERACTION = 33
    # 握手动作
    uint32 PERC_HANDSHAKE            = 34
    
    # 待机陪伴
    uint32 PERC_STANDBY_ACCOMPANY    = 35
    # 娱乐陪伴
    uint32 PERC_HAPPY_ACCOMPANY      = 36
    # 工作陪伴
    uint32 PERC_WORK_ACCOMPANY       = 37
    # 积极陪伴
    uint32 PERC_POSITIVE_ACCOMPANY   = 38
    # 消极陪伴
    uint32 PERC_NEGATIVE_ACCOMPANY   = 39
    
    # 小孩看护
    uint32 PERC_CHILD_WATCH          = 40
    # 老人看护
    uint32 PERC_OLDER_WATCH          = 41
    # 危险提醒
    uint32 PERC_DANGER_REMINDER      = 42
    # 事件提醒
    uint32 PERC_EVENT_REMINDER       = 43
    # 开始走秀（语言下方，不需要感知）
    uint32 PERC_CATWALK_START        = 44
    # 走秀互动
    uint32 PERC_CATWALK_ACT          = 45
    # 走秀展示
    uint32 PERC_CATWALK_SHOW         = 46
    # 走秀返回
    uint32 PERC_CATWALK_BACK         = 47
    
    # 自由活动
    uint32 PERC_FREE_TIME            = 50
    # 社交模式
    uint32 PERC_SOCIALIZE            = 51
    
    # 上报危险信息（不需要请求）
    uint32 PERC_DANGER_INFO          = 60
    # 欢迎模式
    uint32 PERC_WELCOME_DEMO         = 70
    
    # 任务取消（不需要请求）
    uint32 PERC_CANCEL               = 100
    
    uint32 PERC_NODE_CLOSE           = 200
    uint32 PERC_NODE_START           = 201
    uint32 PERC_NODE_RESET           = 202
    
    # 感知类型
    uint32 perc_kind
    # 执行状态：空闲/正在执行/执行完成
    uint8 exe_state
    # 执行结果：无效/成功/失败
    uint8 exe_result
    
    # 错误码
    uint16 err_code
    # 错误消息
    string err_info
    # 剩余执行时间
    uint64 wait_for_millisec
    
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
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new PercState(null);
    if (msg.header !== undefined) {
      resolved.header = std_msgs.msg.Header.Resolve(msg.header)
    }
    else {
      resolved.header = new std_msgs.msg.Header()
    }

    if (msg.action_id !== undefined) {
      resolved.action_id = msg.action_id;
    }
    else {
      resolved.action_id = 0
    }

    if (msg.perc_kind !== undefined) {
      resolved.perc_kind = msg.perc_kind;
    }
    else {
      resolved.perc_kind = 0
    }

    if (msg.exe_state !== undefined) {
      resolved.exe_state = msg.exe_state;
    }
    else {
      resolved.exe_state = 0
    }

    if (msg.exe_result !== undefined) {
      resolved.exe_result = msg.exe_result;
    }
    else {
      resolved.exe_result = 0
    }

    if (msg.err_code !== undefined) {
      resolved.err_code = msg.err_code;
    }
    else {
      resolved.err_code = 0
    }

    if (msg.err_info !== undefined) {
      resolved.err_info = msg.err_info;
    }
    else {
      resolved.err_info = ''
    }

    if (msg.wait_for_millisec !== undefined) {
      resolved.wait_for_millisec = msg.wait_for_millisec;
    }
    else {
      resolved.wait_for_millisec = 0
    }

    return resolved;
    }
};

// Constants for message
PercState.Constants = {
  ACTION_IDLE: 0,
  ACTION_RUNNING: 1,
  ACTION_DONE: 2,
  ACTION_NONE: 0,
  ACTION_SUCCESS: 1,
  ACTION_FAIL: 2,
  ACTION_ERR_NONE: 0,
  ACTION_ERR_NOWORK: 1,
  PERC_DEST: 1,
  PERC_ABS: 2,
  PERC_REL: 3,
  PERC_AUTO_CHARGING: 20,
  PERC_CHECK_ENV: 21,
  PERC_AUTO_MAPPING: 22,
  PERC_FOLLOW: 30,
  PERC_STRANGER_WELCOME: 31,
  PERC_OWNER_WELCOME: 32,
  PERC_BEHAVIOR_INTERACTION: 33,
  PERC_HANDSHAKE: 34,
  PERC_STANDBY_ACCOMPANY: 35,
  PERC_HAPPY_ACCOMPANY: 36,
  PERC_WORK_ACCOMPANY: 37,
  PERC_POSITIVE_ACCOMPANY: 38,
  PERC_NEGATIVE_ACCOMPANY: 39,
  PERC_CHILD_WATCH: 40,
  PERC_OLDER_WATCH: 41,
  PERC_DANGER_REMINDER: 42,
  PERC_EVENT_REMINDER: 43,
  PERC_CATWALK_START: 44,
  PERC_CATWALK_ACT: 45,
  PERC_CATWALK_SHOW: 46,
  PERC_CATWALK_BACK: 47,
  PERC_FREE_TIME: 50,
  PERC_SOCIALIZE: 51,
  PERC_DANGER_INFO: 60,
  PERC_WELCOME_DEMO: 70,
  PERC_CANCEL: 100,
  PERC_NODE_CLOSE: 200,
  PERC_NODE_START: 201,
  PERC_NODE_RESET: 202,
}

module.exports = PercState;
