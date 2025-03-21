; Auto-generated. Do not edit!


(cl:in-package perception_msgs-msg)


;//! \htmlinclude DogState.msg.html

(cl:defclass <DogState> (roslisp-msg-protocol:ros-message)
  ((battery
    :reader battery
    :initarg :battery
    :type cl:float
    :initform 0.0)
   (chargingState
    :reader chargingState
    :initarg :chargingState
    :type cl:fixnum
    :initform 0)
   (gesture
    :reader gesture
    :initarg :gesture
    :type cl:fixnum
    :initform 0)
   (speed
    :reader speed
    :initarg :speed
    :type cl:float
    :initform 0.0)
   (person_state
    :reader person_state
    :initarg :person_state
    :type cl:fixnum
    :initform 0)
   (target_position
    :reader target_position
    :initarg :target_position
    :type geometry_msgs-msg:Pose
    :initform (cl:make-instance 'geometry_msgs-msg:Pose))
   (alarmInfo
    :reader alarmInfo
    :initarg :alarmInfo
    :type (cl:vector perception_msgs-msg:AlarmEntry)
   :initform (cl:make-array 0 :element-type 'perception_msgs-msg:AlarmEntry :initial-element (cl:make-instance 'perception_msgs-msg:AlarmEntry))))
)

(cl:defclass DogState (<DogState>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DogState>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DogState)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name perception_msgs-msg:<DogState> is deprecated: use perception_msgs-msg:DogState instead.")))

(cl:ensure-generic-function 'battery-val :lambda-list '(m))
(cl:defmethod battery-val ((m <DogState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:battery-val is deprecated.  Use perception_msgs-msg:battery instead.")
  (battery m))

(cl:ensure-generic-function 'chargingState-val :lambda-list '(m))
(cl:defmethod chargingState-val ((m <DogState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:chargingState-val is deprecated.  Use perception_msgs-msg:chargingState instead.")
  (chargingState m))

(cl:ensure-generic-function 'gesture-val :lambda-list '(m))
(cl:defmethod gesture-val ((m <DogState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:gesture-val is deprecated.  Use perception_msgs-msg:gesture instead.")
  (gesture m))

(cl:ensure-generic-function 'speed-val :lambda-list '(m))
(cl:defmethod speed-val ((m <DogState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:speed-val is deprecated.  Use perception_msgs-msg:speed instead.")
  (speed m))

(cl:ensure-generic-function 'person_state-val :lambda-list '(m))
(cl:defmethod person_state-val ((m <DogState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:person_state-val is deprecated.  Use perception_msgs-msg:person_state instead.")
  (person_state m))

(cl:ensure-generic-function 'target_position-val :lambda-list '(m))
(cl:defmethod target_position-val ((m <DogState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:target_position-val is deprecated.  Use perception_msgs-msg:target_position instead.")
  (target_position m))

(cl:ensure-generic-function 'alarmInfo-val :lambda-list '(m))
(cl:defmethod alarmInfo-val ((m <DogState>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:alarmInfo-val is deprecated.  Use perception_msgs-msg:alarmInfo instead.")
  (alarmInfo m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DogState>) ostream)
  "Serializes a message object of type '<DogState>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'battery))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'chargingState)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'gesture)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'speed))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'person_state)) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'target_position) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'alarmInfo))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'alarmInfo))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DogState>) istream)
  "Deserializes a message object of type '<DogState>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'battery) (roslisp-utils:decode-double-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'chargingState)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'gesture)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'speed) (roslisp-utils:decode-double-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'person_state)) (cl:read-byte istream))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'target_position) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'alarmInfo) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'alarmInfo)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'perception_msgs-msg:AlarmEntry))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DogState>)))
  "Returns string type for a message object of type '<DogState>"
  "perception_msgs/DogState")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DogState)))
  "Returns string type for a message object of type 'DogState"
  "perception_msgs/DogState")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DogState>)))
  "Returns md5sum for a message object of type '<DogState>"
  "37a76525c34080656fe716b1e4427824")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DogState)))
  "Returns md5sum for a message object of type 'DogState"
  "37a76525c34080656fe716b1e4427824")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DogState>)))
  "Returns full string definition for message of type '<DogState>"
  (cl:format cl:nil "# 电量~%float64 battery~%#充电状态   0：空闲 1: 准备充电 2：充电中 ~%uint8 chargingState~%#手势~%uint8 gesture~%#速度 ~%float64 speed~%#主人识别状态~%uint8 person_state~%# 目标点~%geometry_msgs/Pose target_position~%#报警信息~%AlarmEntry[] alarmInfo~%#动作信息~%#ActionEntry[] actions~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: perception_msgs/AlarmEntry~%int32  id~%int32  source~%int32  level~%int32  status~%string message~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DogState)))
  "Returns full string definition for message of type 'DogState"
  (cl:format cl:nil "# 电量~%float64 battery~%#充电状态   0：空闲 1: 准备充电 2：充电中 ~%uint8 chargingState~%#手势~%uint8 gesture~%#速度 ~%float64 speed~%#主人识别状态~%uint8 person_state~%# 目标点~%geometry_msgs/Pose target_position~%#报警信息~%AlarmEntry[] alarmInfo~%#动作信息~%#ActionEntry[] actions~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: perception_msgs/AlarmEntry~%int32  id~%int32  source~%int32  level~%int32  status~%string message~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DogState>))
  (cl:+ 0
     8
     1
     1
     8
     1
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'target_position))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'alarmInfo) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DogState>))
  "Converts a ROS message object to a list"
  (cl:list 'DogState
    (cl:cons ':battery (battery msg))
    (cl:cons ':chargingState (chargingState msg))
    (cl:cons ':gesture (gesture msg))
    (cl:cons ':speed (speed msg))
    (cl:cons ':person_state (person_state msg))
    (cl:cons ':target_position (target_position msg))
    (cl:cons ':alarmInfo (alarmInfo msg))
))
