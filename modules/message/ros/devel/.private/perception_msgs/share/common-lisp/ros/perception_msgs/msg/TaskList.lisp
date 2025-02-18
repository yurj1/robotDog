; Auto-generated. Do not edit!


(cl:in-package perception_msgs-msg)


;//! \htmlinclude TaskList.msg.html

(cl:defclass <TaskList> (roslisp-msg-protocol:ros-message)
  ((task_id
    :reader task_id
    :initarg :task_id
    :type cl:integer
    :initform 0)
   (task_type
    :reader task_type
    :initarg :task_type
    :type cl:integer
    :initform 0)
   (target_position
    :reader target_position
    :initarg :target_position
    :type geometry_msgs-msg:Pose
    :initform (cl:make-instance 'geometry_msgs-msg:Pose))
   (target_object
    :reader target_object
    :initarg :target_object
    :type cl:string
    :initform "")
   (task_state
    :reader task_state
    :initarg :task_state
    :type cl:fixnum
    :initform 0)
   (task_result
    :reader task_result
    :initarg :task_result
    :type cl:fixnum
    :initform 0)
   (isInPlaceRotation
    :reader isInPlaceRotation
    :initarg :isInPlaceRotation
    :type cl:fixnum
    :initform 0))
)

(cl:defclass TaskList (<TaskList>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <TaskList>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'TaskList)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name perception_msgs-msg:<TaskList> is deprecated: use perception_msgs-msg:TaskList instead.")))

(cl:ensure-generic-function 'task_id-val :lambda-list '(m))
(cl:defmethod task_id-val ((m <TaskList>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:task_id-val is deprecated.  Use perception_msgs-msg:task_id instead.")
  (task_id m))

(cl:ensure-generic-function 'task_type-val :lambda-list '(m))
(cl:defmethod task_type-val ((m <TaskList>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:task_type-val is deprecated.  Use perception_msgs-msg:task_type instead.")
  (task_type m))

(cl:ensure-generic-function 'target_position-val :lambda-list '(m))
(cl:defmethod target_position-val ((m <TaskList>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:target_position-val is deprecated.  Use perception_msgs-msg:target_position instead.")
  (target_position m))

(cl:ensure-generic-function 'target_object-val :lambda-list '(m))
(cl:defmethod target_object-val ((m <TaskList>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:target_object-val is deprecated.  Use perception_msgs-msg:target_object instead.")
  (target_object m))

(cl:ensure-generic-function 'task_state-val :lambda-list '(m))
(cl:defmethod task_state-val ((m <TaskList>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:task_state-val is deprecated.  Use perception_msgs-msg:task_state instead.")
  (task_state m))

(cl:ensure-generic-function 'task_result-val :lambda-list '(m))
(cl:defmethod task_result-val ((m <TaskList>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:task_result-val is deprecated.  Use perception_msgs-msg:task_result instead.")
  (task_result m))

(cl:ensure-generic-function 'isInPlaceRotation-val :lambda-list '(m))
(cl:defmethod isInPlaceRotation-val ((m <TaskList>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-msg:isInPlaceRotation-val is deprecated.  Use perception_msgs-msg:isInPlaceRotation instead.")
  (isInPlaceRotation m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <TaskList>) ostream)
  "Serializes a message object of type '<TaskList>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'task_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'task_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'task_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'task_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'task_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'task_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'task_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'task_id)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'task_type)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'task_type)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'task_type)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'task_type)) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'target_position) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'target_object))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'target_object))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'task_state)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'task_result)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'isInPlaceRotation)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <TaskList>) istream)
  "Deserializes a message object of type '<TaskList>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'task_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'task_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'task_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'task_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 32) (cl:slot-value msg 'task_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 40) (cl:slot-value msg 'task_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 48) (cl:slot-value msg 'task_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 56) (cl:slot-value msg 'task_id)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'task_type)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'task_type)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'task_type)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'task_type)) (cl:read-byte istream))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'target_position) istream)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'target_object) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'target_object) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'task_state)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'task_result)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'isInPlaceRotation)) (cl:read-byte istream))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<TaskList>)))
  "Returns string type for a message object of type '<TaskList>"
  "perception_msgs/TaskList")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'TaskList)))
  "Returns string type for a message object of type 'TaskList"
  "perception_msgs/TaskList")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<TaskList>)))
  "Returns md5sum for a message object of type '<TaskList>"
  "72dfea7a02287e1a585c8d273011f6e9")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'TaskList)))
  "Returns md5sum for a message object of type 'TaskList"
  "72dfea7a02287e1a585c8d273011f6e9")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<TaskList>)))
  "Returns full string definition for message of type '<TaskList>"
  (cl:format cl:nil "# Task Id~%uint64 task_id~%~%# Task Type~%uint32 task_type~%~%# Target Position~%geometry_msgs/Pose target_position~%~%# Target Object~%string target_object~%~%# Task State~%uint8 task_state~%~%# Task Result~%uint8 task_result~%~%# 到达终点是否原地打转~%uint8 isInPlaceRotation ~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'TaskList)))
  "Returns full string definition for message of type 'TaskList"
  (cl:format cl:nil "# Task Id~%uint64 task_id~%~%# Task Type~%uint32 task_type~%~%# Target Position~%geometry_msgs/Pose target_position~%~%# Target Object~%string target_object~%~%# Task State~%uint8 task_state~%~%# Task Result~%uint8 task_result~%~%# 到达终点是否原地打转~%uint8 isInPlaceRotation ~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <TaskList>))
  (cl:+ 0
     8
     4
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'target_position))
     4 (cl:length (cl:slot-value msg 'target_object))
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <TaskList>))
  "Converts a ROS message object to a list"
  (cl:list 'TaskList
    (cl:cons ':task_id (task_id msg))
    (cl:cons ':task_type (task_type msg))
    (cl:cons ':target_position (target_position msg))
    (cl:cons ':target_object (target_object msg))
    (cl:cons ':task_state (task_state msg))
    (cl:cons ':task_result (task_result msg))
    (cl:cons ':isInPlaceRotation (isInPlaceRotation msg))
))
