; Auto-generated. Do not edit!


(cl:in-package perception_msgs-msg)


;//! \htmlinclude PercState.msg.html

(cl:defclass <PercState> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (action_id
    :reader action_id
    :initarg :action_id
    :type cl:integer
    :initform 0)
   (perc_kind
    :reader perc_kind
    :initarg :perc_kind
    :type cl:integer
    :initform 0)
   (exe_state
    :reader exe_state
    :initarg :exe_state
    :type cl:fixnum
    :initform 0)
   (exe_result
    :reader exe_result
    :initarg :exe_result
    :type cl:fixnum
    :initform 0)
   (err_code
    :reader err_code
    :initarg :err_code
    :type cl:fixnum
    :initform 0)
   (err_info
    :reader err_info
    :initarg :err_info
    :type cl:string
    :initform "")
   (wait_for_millisec
    :reader wait_for_millisec
    :initarg :wait_for_millisec
    :type cl:integer
    :initform 0))
)

(cl:defclass PercState (<PercState>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <PercState>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'PercState)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name perception_msgs-msg:<PercState> is deprecated: use perception_msgs-msg:PercState instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <PercState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:header-val is deprecated.  Use perception_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'action_id-val :lambda-list '(m))
(cl:defmethod action_id-val ((m <PercState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:action_id-val is deprecated.  Use perception_msgs-msg:action_id instead.")
  (action_id m))

(cl:ensure-generic-function 'perc_kind-val :lambda-list '(m))
(cl:defmethod perc_kind-val ((m <PercState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:perc_kind-val is deprecated.  Use perception_msgs-msg:perc_kind instead.")
  (perc_kind m))

(cl:ensure-generic-function 'exe_state-val :lambda-list '(m))
(cl:defmethod exe_state-val ((m <PercState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:exe_state-val is deprecated.  Use perception_msgs-msg:exe_state instead.")
  (exe_state m))

(cl:ensure-generic-function 'exe_result-val :lambda-list '(m))
(cl:defmethod exe_result-val ((m <PercState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:exe_result-val is deprecated.  Use perception_msgs-msg:exe_result instead.")
  (exe_result m))

(cl:ensure-generic-function 'err_code-val :lambda-list '(m))
(cl:defmethod err_code-val ((m <PercState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:err_code-val is deprecated.  Use perception_msgs-msg:err_code instead.")
  (err_code m))

(cl:ensure-generic-function 'err_info-val :lambda-list '(m))
(cl:defmethod err_info-val ((m <PercState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:err_info-val is deprecated.  Use perception_msgs-msg:err_info instead.")
  (err_info m))

(cl:ensure-generic-function 'wait_for_millisec-val :lambda-list '(m))
(cl:defmethod wait_for_millisec-val ((m <PercState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:wait_for_millisec-val is deprecated.  Use perception_msgs-msg:wait_for_millisec instead.")
  (wait_for_millisec m))
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql '<PercState>)))
    "Constants for message type '<PercState>"
  '((:ACTION_IDLE . 0)
    (:ACTION_RUNNING . 1)
    (:ACTION_DONE . 2)
    (:ACTION_NONE . 0)
    (:ACTION_SUCCESS . 1)
    (:ACTION_FAIL . 2)
    (:ACTION_ERR_NONE . 0)
    (:ACTION_ERR_NOWORK . 1)
    (:PERC_DEST . 1)
    (:PERC_ABS . 2)
    (:PERC_REL . 3)
    (:PERC_AUTO_CHARGING . 20)
    (:PERC_CHECK_ENV . 21)
    (:PERC_AUTO_MAPPING . 22)
    (:PERC_FOLLOW . 30)
    (:PERC_STRANGER_WELCOME . 31)
    (:PERC_OWNER_WELCOME . 32)
    (:PERC_BEHAVIOR_INTERACTION . 33)
    (:PERC_HANDSHAKE . 34)
    (:PERC_STANDBY_ACCOMPANY . 35)
    (:PERC_HAPPY_ACCOMPANY . 36)
    (:PERC_WORK_ACCOMPANY . 37)
    (:PERC_POSITIVE_ACCOMPANY . 38)
    (:PERC_NEGATIVE_ACCOMPANY . 39)
    (:PERC_CHILD_WATCH . 40)
    (:PERC_OLDER_WATCH . 41)
    (:PERC_DANGER_REMINDER . 42)
    (:PERC_EVENT_REMINDER . 43)
    (:PERC_CATWALK_START . 44)
    (:PERC_CATWALK_ACT . 45)
    (:PERC_CATWALK_SHOW . 46)
    (:PERC_CATWALK_BACK . 47)
    (:PERC_FREE_TIME . 50)
    (:PERC_SOCIALIZE . 51)
    (:PERC_DANGER_INFO . 60)
    (:PERC_WELCOME_DEMO . 70)
    (:PERC_CANCEL . 100)
    (:PERC_NODE_CLOSE . 200)
    (:PERC_NODE_START . 201)
    (:PERC_NODE_RESET . 202))
)
(cl:defmethod roslisp-msg-protocol:symbol-codes ((msg-type (cl:eql 'PercState)))
    "Constants for message type 'PercState"
  '((:ACTION_IDLE . 0)
    (:ACTION_RUNNING . 1)
    (:ACTION_DONE . 2)
    (:ACTION_NONE . 0)
    (:ACTION_SUCCESS . 1)
    (:ACTION_FAIL . 2)
    (:ACTION_ERR_NONE . 0)
    (:ACTION_ERR_NOWORK . 1)
    (:PERC_DEST . 1)
    (:PERC_ABS . 2)
    (:PERC_REL . 3)
    (:PERC_AUTO_CHARGING . 20)
    (:PERC_CHECK_ENV . 21)
    (:PERC_AUTO_MAPPING . 22)
    (:PERC_FOLLOW . 30)
    (:PERC_STRANGER_WELCOME . 31)
    (:PERC_OWNER_WELCOME . 32)
    (:PERC_BEHAVIOR_INTERACTION . 33)
    (:PERC_HANDSHAKE . 34)
    (:PERC_STANDBY_ACCOMPANY . 35)
    (:PERC_HAPPY_ACCOMPANY . 36)
    (:PERC_WORK_ACCOMPANY . 37)
    (:PERC_POSITIVE_ACCOMPANY . 38)
    (:PERC_NEGATIVE_ACCOMPANY . 39)
    (:PERC_CHILD_WATCH . 40)
    (:PERC_OLDER_WATCH . 41)
    (:PERC_DANGER_REMINDER . 42)
    (:PERC_EVENT_REMINDER . 43)
    (:PERC_CATWALK_START . 44)
    (:PERC_CATWALK_ACT . 45)
    (:PERC_CATWALK_SHOW . 46)
    (:PERC_CATWALK_BACK . 47)
    (:PERC_FREE_TIME . 50)
    (:PERC_SOCIALIZE . 51)
    (:PERC_DANGER_INFO . 60)
    (:PERC_WELCOME_DEMO . 70)
    (:PERC_CANCEL . 100)
    (:PERC_NODE_CLOSE . 200)
    (:PERC_NODE_START . 201)
    (:PERC_NODE_RESET . 202))
)
(cl:defmethod roslisp-msg-protocol:serialize ((msg <PercState>) ostream)
  "Serializes a message object of type '<PercState>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'action_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'action_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'action_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'action_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'action_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'action_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'action_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'action_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'perc_kind)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'perc_kind)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'perc_kind)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'perc_kind)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'exe_state)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'exe_result)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'err_code)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'err_code)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'err_info))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'err_info))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'wait_for_millisec)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'wait_for_millisec)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'wait_for_millisec)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'wait_for_millisec)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'wait_for_millisec)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'wait_for_millisec)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'wait_for_millisec)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'wait_for_millisec)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <PercState>) istream)
  "Deserializes a message object of type '<PercState>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'action_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'action_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'action_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'action_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'action_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'action_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'action_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'action_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'perc_kind)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'perc_kind)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'perc_kind)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'perc_kind)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'exe_state)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'exe_result)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'err_code)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'err_code)) (cl:read-byte istream))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'err_info) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'err_info) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'wait_for_millisec)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'wait_for_millisec)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'wait_for_millisec)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'wait_for_millisec)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'wait_for_millisec)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'wait_for_millisec)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'wait_for_millisec)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'wait_for_millisec)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<PercState>)))
  "Returns string type for a message object of type '<PercState>"
  "perception_msgs/PercState")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'PercState)))
  "Returns string type for a message object of type 'PercState"
  "perception_msgs/PercState")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<PercState>)))
  "Returns md5sum for a message object of type '<PercState>"
  "54333f0d38bd18fb2d888adabbf15a33")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'PercState)))
  "Returns md5sum for a message object of type 'PercState"
  "54333f0d38bd18fb2d888adabbf15a33")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<PercState>)))
  "Returns full string definition for message of type '<PercState>"
  (cl:format cl:nil "std_msgs/Header header~%~%# ActionState~%uint8 ACTION_IDLE = 0~%uint8 ACTION_RUNNING = 1~%uint8 ACTION_DONE = 2~%~%# ActionResult~%uint8 ACTION_NONE = 0~%uint8 ACTION_SUCCESS = 1~%uint8 ACTION_FAIL = 2~%~%# ErrCode~%uint16 ACTION_ERR_NONE = 0~%uint16 ACTION_ERR_NOWORK = 1~%~%# 当前执行的id~%uint64 action_id~%~%~%# Perceive Kind~%uint32 PERC_DEST                 = 1~%uint32 PERC_ABS                  = 2~%uint32 PERC_REL                  = 3~%~%# 自动充电~%uint32 PERC_AUTO_CHARGING        = 20~%# 环境查看~%uint32 PERC_CHECK_ENV            = 21~%# 自动建图~%uint32 PERC_AUTO_MAPPING         = 22~%~%# 跟随模式~%uint32 PERC_FOLLOW               = 30~%# 陌生人迎接~%uint32 PERC_STRANGER_WELCOME     = 31~%# 主人迎接~%uint32 PERC_OWNER_WELCOME        = 32~%# 行为互动~%uint32 PERC_BEHAVIOR_INTERACTION = 33~%# 握手动作~%uint32 PERC_HANDSHAKE            = 34~%~%# 待机陪伴~%uint32 PERC_STANDBY_ACCOMPANY    = 35~%# 娱乐陪伴~%uint32 PERC_HAPPY_ACCOMPANY      = 36~%# 工作陪伴~%uint32 PERC_WORK_ACCOMPANY       = 37~%# 积极陪伴~%uint32 PERC_POSITIVE_ACCOMPANY   = 38~%# 消极陪伴~%uint32 PERC_NEGATIVE_ACCOMPANY   = 39~%~%# 小孩看护~%uint32 PERC_CHILD_WATCH          = 40~%# 老人看护~%uint32 PERC_OLDER_WATCH          = 41~%# 危险提醒~%uint32 PERC_DANGER_REMINDER      = 42~%# 事件提醒~%uint32 PERC_EVENT_REMINDER       = 43~%# 开始走秀（语言下方，不需要感知）~%uint32 PERC_CATWALK_START        = 44~%# 走秀互动~%uint32 PERC_CATWALK_ACT          = 45~%# 走秀展示~%uint32 PERC_CATWALK_SHOW         = 46~%# 走秀返回~%uint32 PERC_CATWALK_BACK         = 47~%~%# 自由活动~%uint32 PERC_FREE_TIME            = 50~%# 社交模式~%uint32 PERC_SOCIALIZE            = 51~%~%# 上报危险信息（不需要请求）~%uint32 PERC_DANGER_INFO          = 60~%# 欢迎模式~%uint32 PERC_WELCOME_DEMO         = 70~%~%# 任务取消（不需要请求）~%uint32 PERC_CANCEL               = 100~%~%uint32 PERC_NODE_CLOSE           = 200~%uint32 PERC_NODE_START           = 201~%uint32 PERC_NODE_RESET           = 202~%~%# 感知类型~%uint32 perc_kind~%# 执行状态：空闲/正在执行/执行完成~%uint8 exe_state~%# 执行结果：无效/成功/失败~%uint8 exe_result~%~%# 错误码~%uint16 err_code~%# 错误消息~%string err_info~%# 剩余执行时间~%uint64 wait_for_millisec~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'PercState)))
  "Returns full string definition for message of type 'PercState"
  (cl:format cl:nil "std_msgs/Header header~%~%# ActionState~%uint8 ACTION_IDLE = 0~%uint8 ACTION_RUNNING = 1~%uint8 ACTION_DONE = 2~%~%# ActionResult~%uint8 ACTION_NONE = 0~%uint8 ACTION_SUCCESS = 1~%uint8 ACTION_FAIL = 2~%~%# ErrCode~%uint16 ACTION_ERR_NONE = 0~%uint16 ACTION_ERR_NOWORK = 1~%~%# 当前执行的id~%uint64 action_id~%~%~%# Perceive Kind~%uint32 PERC_DEST                 = 1~%uint32 PERC_ABS                  = 2~%uint32 PERC_REL                  = 3~%~%# 自动充电~%uint32 PERC_AUTO_CHARGING        = 20~%# 环境查看~%uint32 PERC_CHECK_ENV            = 21~%# 自动建图~%uint32 PERC_AUTO_MAPPING         = 22~%~%# 跟随模式~%uint32 PERC_FOLLOW               = 30~%# 陌生人迎接~%uint32 PERC_STRANGER_WELCOME     = 31~%# 主人迎接~%uint32 PERC_OWNER_WELCOME        = 32~%# 行为互动~%uint32 PERC_BEHAVIOR_INTERACTION = 33~%# 握手动作~%uint32 PERC_HANDSHAKE            = 34~%~%# 待机陪伴~%uint32 PERC_STANDBY_ACCOMPANY    = 35~%# 娱乐陪伴~%uint32 PERC_HAPPY_ACCOMPANY      = 36~%# 工作陪伴~%uint32 PERC_WORK_ACCOMPANY       = 37~%# 积极陪伴~%uint32 PERC_POSITIVE_ACCOMPANY   = 38~%# 消极陪伴~%uint32 PERC_NEGATIVE_ACCOMPANY   = 39~%~%# 小孩看护~%uint32 PERC_CHILD_WATCH          = 40~%# 老人看护~%uint32 PERC_OLDER_WATCH          = 41~%# 危险提醒~%uint32 PERC_DANGER_REMINDER      = 42~%# 事件提醒~%uint32 PERC_EVENT_REMINDER       = 43~%# 开始走秀（语言下方，不需要感知）~%uint32 PERC_CATWALK_START        = 44~%# 走秀互动~%uint32 PERC_CATWALK_ACT          = 45~%# 走秀展示~%uint32 PERC_CATWALK_SHOW         = 46~%# 走秀返回~%uint32 PERC_CATWALK_BACK         = 47~%~%# 自由活动~%uint32 PERC_FREE_TIME            = 50~%# 社交模式~%uint32 PERC_SOCIALIZE            = 51~%~%# 上报危险信息（不需要请求）~%uint32 PERC_DANGER_INFO          = 60~%# 欢迎模式~%uint32 PERC_WELCOME_DEMO         = 70~%~%# 任务取消（不需要请求）~%uint32 PERC_CANCEL               = 100~%~%uint32 PERC_NODE_CLOSE           = 200~%uint32 PERC_NODE_START           = 201~%uint32 PERC_NODE_RESET           = 202~%~%# 感知类型~%uint32 perc_kind~%# 执行状态：空闲/正在执行/执行完成~%uint8 exe_state~%# 执行结果：无效/成功/失败~%uint8 exe_result~%~%# 错误码~%uint16 err_code~%# 错误消息~%string err_info~%# 剩余执行时间~%uint64 wait_for_millisec~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <PercState>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     8
     4
     1
     1
     2
     4 (cl:length (cl:slot-value msg 'err_info))
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <PercState>))
  "Converts a ROS message object to a list"
  (cl:list 'PercState
    (cl:cons ':header (header msg))
    (cl:cons ':action_id (action_id msg))
    (cl:cons ':perc_kind (perc_kind msg))
    (cl:cons ':exe_state (exe_state msg))
    (cl:cons ':exe_result (exe_result msg))
    (cl:cons ':err_code (err_code msg))
    (cl:cons ':err_info (err_info msg))
    (cl:cons ':wait_for_millisec (wait_for_millisec msg))
))
