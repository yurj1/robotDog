; Auto-generated. Do not edit!


(cl:in-package quad_msgs-msg)


;//! \htmlinclude LegCommandArray.msg.html

(cl:defclass <LegCommandArray> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (leg_commands
    :reader leg_commands
    :initarg :leg_commands
    :type (cl:vector quad_msgs-msg:LegCommand)
   :initform (cl:make-array 0 :element-type 'quad_msgs-msg:LegCommand :initial-element (cl:make-instance 'quad_msgs-msg:LegCommand))))
)

(cl:defclass LegCommandArray (<LegCommandArray>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LegCommandArray>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LegCommandArray)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name quad_msgs-msg:<LegCommandArray> is deprecated: use quad_msgs-msg:LegCommandArray instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <LegCommandArray>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:header-val is deprecated.  Use quad_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'leg_commands-val :lambda-list '(m))
(cl:defmethod leg_commands-val ((m <LegCommandArray>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:leg_commands-val is deprecated.  Use quad_msgs-msg:leg_commands instead.")
  (leg_commands m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LegCommandArray>) ostream)
  "Serializes a message object of type '<LegCommandArray>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'leg_commands))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'leg_commands))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LegCommandArray>) istream)
  "Deserializes a message object of type '<LegCommandArray>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'leg_commands) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'leg_commands)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'quad_msgs-msg:LegCommand))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LegCommandArray>)))
  "Returns string type for a message object of type '<LegCommandArray>"
  "quad_msgs/LegCommandArray")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LegCommandArray)))
  "Returns string type for a message object of type 'LegCommandArray"
  "quad_msgs/LegCommandArray")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LegCommandArray>)))
  "Returns md5sum for a message object of type '<LegCommandArray>"
  "021ecb87d231eeb30d1c10093fda1cef")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LegCommandArray)))
  "Returns md5sum for a message object of type 'LegCommandArray"
  "021ecb87d231eeb30d1c10093fda1cef")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LegCommandArray>)))
  "Returns full string definition for message of type '<LegCommandArray>"
  (cl:format cl:nil "# This is a message of leg commands for each leg on quad. The order is in FL, BL, FR, BR.~%#~%# Accurate timing information is stored in the header~%~%Header header~%~%LegCommand[] leg_commands # FL, BL, FR, BR~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: quad_msgs/LegCommand~%# This is a message of motor commands for each joint on a quad leg.~%#~%# Accurate timing information is stored in the header~%~%Header header~%~%MotorCommand[] motor_commands # Stored as Abd, Hip, Knee~%~%================================================================================~%MSG: quad_msgs/MotorCommand~%# This is a message to hold the desired position, desired velocity, feedforward torques and control gains for a single joint on Quad~%#~%# Accurate timing information is stored in the header~%~%Header header~%~%# Commands~%float64 pos_setpoint # Position command~%float64 vel_setpoint # Velocity command~%float32 kp # Position setpoint gain~%float32 kd # Derivative setpoint gain~%float64 torque_ff # Feedforward torque~%~%# Diagnostics~%float64 pos_component # Feedback position component~%float64 vel_component # Feedback velocity component~%float64 fb_component # Feedback total component~%float64 effort # Total effort~%float64 fb_ratio # Feedback to total ratio~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LegCommandArray)))
  "Returns full string definition for message of type 'LegCommandArray"
  (cl:format cl:nil "# This is a message of leg commands for each leg on quad. The order is in FL, BL, FR, BR.~%#~%# Accurate timing information is stored in the header~%~%Header header~%~%LegCommand[] leg_commands # FL, BL, FR, BR~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: quad_msgs/LegCommand~%# This is a message of motor commands for each joint on a quad leg.~%#~%# Accurate timing information is stored in the header~%~%Header header~%~%MotorCommand[] motor_commands # Stored as Abd, Hip, Knee~%~%================================================================================~%MSG: quad_msgs/MotorCommand~%# This is a message to hold the desired position, desired velocity, feedforward torques and control gains for a single joint on Quad~%#~%# Accurate timing information is stored in the header~%~%Header header~%~%# Commands~%float64 pos_setpoint # Position command~%float64 vel_setpoint # Velocity command~%float32 kp # Position setpoint gain~%float32 kd # Derivative setpoint gain~%float64 torque_ff # Feedforward torque~%~%# Diagnostics~%float64 pos_component # Feedback position component~%float64 vel_component # Feedback velocity component~%float64 fb_component # Feedback total component~%float64 effort # Total effort~%float64 fb_ratio # Feedback to total ratio~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LegCommandArray>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'leg_commands) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LegCommandArray>))
  "Converts a ROS message object to a list"
  (cl:list 'LegCommandArray
    (cl:cons ':header (header msg))
    (cl:cons ':leg_commands (leg_commands msg))
))
