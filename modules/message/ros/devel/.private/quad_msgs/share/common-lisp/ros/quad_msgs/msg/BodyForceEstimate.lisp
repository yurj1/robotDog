; Auto-generated. Do not edit!


(cl:in-package quad_msgs-msg)


;//! \htmlinclude BodyForceEstimate.msg.html

(cl:defclass <BodyForceEstimate> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (joint_torques
    :reader joint_torques
    :initarg :joint_torques
    :type (cl:vector cl:float)
   :initform (cl:make-array 0 :element-type 'cl:float :initial-element 0.0)))
)

(cl:defclass BodyForceEstimate (<BodyForceEstimate>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <BodyForceEstimate>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'BodyForceEstimate)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name quad_msgs-msg:<BodyForceEstimate> is deprecated: use quad_msgs-msg:BodyForceEstimate instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <BodyForceEstimate>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:header-val is deprecated.  Use quad_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'joint_torques-val :lambda-list '(m))
(cl:defmethod joint_torques-val ((m <BodyForceEstimate>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:joint_torques-val is deprecated.  Use quad_msgs-msg:joint_torques instead.")
  (joint_torques m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <BodyForceEstimate>) ostream)
  "Serializes a message object of type '<BodyForceEstimate>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'joint_torques))))
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
   (cl:slot-value msg 'joint_torques))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <BodyForceEstimate>) istream)
  "Deserializes a message object of type '<BodyForceEstimate>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'joint_torques) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'joint_torques)))
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<BodyForceEstimate>)))
  "Returns string type for a message object of type '<BodyForceEstimate>"
  "quad_msgs/BodyForceEstimate")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'BodyForceEstimate)))
  "Returns string type for a message object of type 'BodyForceEstimate"
  "quad_msgs/BodyForceEstimate")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<BodyForceEstimate>)))
  "Returns md5sum for a message object of type '<BodyForceEstimate>"
  "ef120516450a16904de7fd214a0b2b2e")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'BodyForceEstimate)))
  "Returns md5sum for a message object of type 'BodyForceEstimate"
  "ef120516450a16904de7fd214a0b2b2e")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<BodyForceEstimate>)))
  "Returns full string definition for message of type '<BodyForceEstimate>"
  (cl:format cl:nil "# This is a message to hold a body contact force estimate~%#~%# The body contact force vector holds the estimated external torques acting on each of the 12 joints.~%# Accurate timing information is stored in the header~%~%Header header~%~%float64[] joint_torques~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'BodyForceEstimate)))
  "Returns full string definition for message of type 'BodyForceEstimate"
  (cl:format cl:nil "# This is a message to hold a body contact force estimate~%#~%# The body contact force vector holds the estimated external torques acting on each of the 12 joints.~%# Accurate timing information is stored in the header~%~%Header header~%~%float64[] joint_torques~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <BodyForceEstimate>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'joint_torques) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 8)))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <BodyForceEstimate>))
  "Converts a ROS message object to a list"
  (cl:list 'BodyForceEstimate
    (cl:cons ':header (header msg))
    (cl:cons ':joint_torques (joint_torques msg))
))
