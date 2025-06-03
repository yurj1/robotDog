; Auto-generated. Do not edit!


(cl:in-package quad_msgs-msg)


;//! \htmlinclude RobotPlanDiagnostics.msg.html

(cl:defclass <RobotPlanDiagnostics> (roslisp-msg-protocol:ros-message)
  ((compute_time
    :reader compute_time
    :initarg :compute_time
    :type cl:float
    :initform 0.0)
   (cost
    :reader cost
    :initarg :cost
    :type cl:float
    :initform 0.0)
   (iterations
    :reader iterations
    :initarg :iterations
    :type cl:integer
    :initform 0)
   (horizon_length
    :reader horizon_length
    :initarg :horizon_length
    :type cl:integer
    :initform 0)
   (complexity_schedule
    :reader complexity_schedule
    :initarg :complexity_schedule
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0))
   (element_times
    :reader element_times
    :initarg :element_times
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass RobotPlanDiagnostics (<RobotPlanDiagnostics>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RobotPlanDiagnostics>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RobotPlanDiagnostics)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name quad_msgs-msg:<RobotPlanDiagnostics> is deprecated: use quad_msgs-msg:RobotPlanDiagnostics instead.")))

(cl:ensure-generic-function 'compute_time-val :lambda-list '(m))
(cl:defmethod compute_time-val ((m <RobotPlanDiagnostics>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:compute_time-val is deprecated.  Use quad_msgs-msg:compute_time instead.")
  (compute_time m))

(cl:ensure-generic-function 'cost-val :lambda-list '(m))
(cl:defmethod cost-val ((m <RobotPlanDiagnostics>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:cost-val is deprecated.  Use quad_msgs-msg:cost instead.")
  (cost m))

(cl:ensure-generic-function 'iterations-val :lambda-list '(m))
(cl:defmethod iterations-val ((m <RobotPlanDiagnostics>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:iterations-val is deprecated.  Use quad_msgs-msg:iterations instead.")
  (iterations m))

(cl:ensure-generic-function 'horizon_length-val :lambda-list '(m))
(cl:defmethod horizon_length-val ((m <RobotPlanDiagnostics>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:horizon_length-val is deprecated.  Use quad_msgs-msg:horizon_length instead.")
  (horizon_length m))

(cl:ensure-generic-function 'complexity_schedule-val :lambda-list '(m))
(cl:defmethod complexity_schedule-val ((m <RobotPlanDiagnostics>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:complexity_schedule-val is deprecated.  Use quad_msgs-msg:complexity_schedule instead.")
  (complexity_schedule m))

(cl:ensure-generic-function 'element_times-val :lambda-list '(m))
(cl:defmethod element_times-val ((m <RobotPlanDiagnostics>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:element_times-val is deprecated.  Use quad_msgs-msg:element_times instead.")
  (element_times m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RobotPlanDiagnostics>) ostream)
  "Serializes a message object of type '<RobotPlanDiagnostics>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'compute_time))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'cost))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'iterations)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'iterations)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'iterations)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'iterations)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'horizon_length)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'horizon_length)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'horizon_length)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'horizon_length)) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'complexity_schedule))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) ele) ostream))
   (cl:slot-value msg 'complexity_schedule))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'element_times))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((bits (roslisp-utils:encode-double-float-bits ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream)))
   (cl:slot-value msg 'element_times))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RobotPlanDiagnostics>) istream)
  "Deserializes a message object of type '<RobotPlanDiagnostics>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'compute_time) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'cost) (roslisp-utils:decode-double-float-bits bits)))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'iterations)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'iterations)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'iterations)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'iterations)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'horizon_length)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'horizon_length)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'horizon_length)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'horizon_length)) (cl:read-byte istream))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'complexity_schedule) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'complexity_schedule)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:aref vals i)) (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'element_times) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'element_times)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:aref vals i) (roslisp-utils:decode-double-float-bits bits))))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RobotPlanDiagnostics>)))
  "Returns string type for a message object of type '<RobotPlanDiagnostics>"
  "quad_msgs/RobotPlanDiagnostics")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RobotPlanDiagnostics)))
  "Returns string type for a message object of type 'RobotPlanDiagnostics"
  "quad_msgs/RobotPlanDiagnostics")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RobotPlanDiagnostics>)))
  "Returns md5sum for a message object of type '<RobotPlanDiagnostics>"
  "4ba495ddc8d93cb86ca454812d102149")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RobotPlanDiagnostics)))
  "Returns md5sum for a message object of type 'RobotPlanDiagnostics"
  "4ba495ddc8d93cb86ca454812d102149")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RobotPlanDiagnostics>)))
  "Returns full string definition for message of type '<RobotPlanDiagnostics>"
  (cl:format cl:nil "# This is a message to hold local plan diagnostics~%~%float64 compute_time~%float64 cost~%uint32 iterations~%uint32 horizon_length~%uint32[] complexity_schedule~%float64[] element_times~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RobotPlanDiagnostics)))
  "Returns full string definition for message of type 'RobotPlanDiagnostics"
  (cl:format cl:nil "# This is a message to hold local plan diagnostics~%~%float64 compute_time~%float64 cost~%uint32 iterations~%uint32 horizon_length~%uint32[] complexity_schedule~%float64[] element_times~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RobotPlanDiagnostics>))
  (cl:+ 0
     8
     8
     4
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'complexity_schedule) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'element_times) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RobotPlanDiagnostics>))
  "Converts a ROS message object to a list"
  (cl:list 'RobotPlanDiagnostics
    (cl:cons ':compute_time (compute_time msg))
    (cl:cons ':cost (cost msg))
    (cl:cons ':iterations (iterations msg))
    (cl:cons ':horizon_length (horizon_length msg))
    (cl:cons ':complexity_schedule (complexity_schedule msg))
    (cl:cons ':element_times (element_times msg))
))
