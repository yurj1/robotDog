; Auto-generated. Do not edit!


(cl:in-package quad_msgs-msg)


;//! \htmlinclude LegContactMode.msg.html

(cl:defclass <LegContactMode> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (contact_prob
    :reader contact_prob
    :initarg :contact_prob
    :type cl:float
    :initform 0.0)
   (contact_state
    :reader contact_state
    :initarg :contact_state
    :type cl:boolean
    :initform cl:nil)
   (contact_forces
    :reader contact_forces
    :initarg :contact_forces
    :type geometry_msgs-msg:Vector3
    :initform (cl:make-instance 'geometry_msgs-msg:Vector3)))
)

(cl:defclass LegContactMode (<LegContactMode>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <LegContactMode>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'LegContactMode)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name quad_msgs-msg:<LegContactMode> is deprecated: use quad_msgs-msg:LegContactMode instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <LegContactMode>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:header-val is deprecated.  Use quad_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'contact_prob-val :lambda-list '(m))
(cl:defmethod contact_prob-val ((m <LegContactMode>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:contact_prob-val is deprecated.  Use quad_msgs-msg:contact_prob instead.")
  (contact_prob m))

(cl:ensure-generic-function 'contact_state-val :lambda-list '(m))
(cl:defmethod contact_state-val ((m <LegContactMode>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:contact_state-val is deprecated.  Use quad_msgs-msg:contact_state instead.")
  (contact_state m))

(cl:ensure-generic-function 'contact_forces-val :lambda-list '(m))
(cl:defmethod contact_forces-val ((m <LegContactMode>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:contact_forces-val is deprecated.  Use quad_msgs-msg:contact_forces instead.")
  (contact_forces m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <LegContactMode>) ostream)
  "Serializes a message object of type '<LegContactMode>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-single-float-bits (cl:slot-value msg 'contact_prob))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'contact_state) 1 0)) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'contact_forces) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <LegContactMode>) istream)
  "Deserializes a message object of type '<LegContactMode>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'contact_prob) (roslisp-utils:decode-single-float-bits bits)))
    (cl:setf (cl:slot-value msg 'contact_state) (cl:not (cl:zerop (cl:read-byte istream))))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'contact_forces) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<LegContactMode>)))
  "Returns string type for a message object of type '<LegContactMode>"
  "quad_msgs/LegContactMode")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'LegContactMode)))
  "Returns string type for a message object of type 'LegContactMode"
  "quad_msgs/LegContactMode")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<LegContactMode>)))
  "Returns md5sum for a message object of type '<LegContactMode>"
  "46ad19315dce64937e892556c64f6977")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'LegContactMode)))
  "Returns md5sum for a message object of type 'LegContactMode"
  "46ad19315dce64937e892556c64f6977")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<LegContactMode>)))
  "Returns full string definition for message of type '<LegContactMode>"
  (cl:format cl:nil "# This is a message to hold contact mode of one leg~%Header header~%~%float32 contact_prob~%bool contact_state~%geometry_msgs/Vector3 contact_forces #fx,fy,fz~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'LegContactMode)))
  "Returns full string definition for message of type 'LegContactMode"
  (cl:format cl:nil "# This is a message to hold contact mode of one leg~%Header header~%~%float32 contact_prob~%bool contact_state~%geometry_msgs/Vector3 contact_forces #fx,fy,fz~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <LegContactMode>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4
     1
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'contact_forces))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <LegContactMode>))
  "Converts a ROS message object to a list"
  (cl:list 'LegContactMode
    (cl:cons ':header (header msg))
    (cl:cons ':contact_prob (contact_prob msg))
    (cl:cons ':contact_state (contact_state msg))
    (cl:cons ':contact_forces (contact_forces msg))
))
