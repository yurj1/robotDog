; Auto-generated. Do not edit!


(cl:in-package quad_msgs-msg)


;//! \htmlinclude ContactMode.msg.html

(cl:defclass <ContactMode> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (leg_contacts
    :reader leg_contacts
    :initarg :leg_contacts
    :type (cl:vector quad_msgs-msg:LegContactMode)
   :initform (cl:make-array 0 :element-type 'quad_msgs-msg:LegContactMode :initial-element (cl:make-instance 'quad_msgs-msg:LegContactMode))))
)

(cl:defclass ContactMode (<ContactMode>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <ContactMode>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'ContactMode)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name quad_msgs-msg:<ContactMode> is deprecated: use quad_msgs-msg:ContactMode instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <ContactMode>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:header-val is deprecated.  Use quad_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'leg_contacts-val :lambda-list '(m))
(cl:defmethod leg_contacts-val ((m <ContactMode>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:leg_contacts-val is deprecated.  Use quad_msgs-msg:leg_contacts instead.")
  (leg_contacts m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <ContactMode>) ostream)
  "Serializes a message object of type '<ContactMode>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'leg_contacts))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'leg_contacts))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <ContactMode>) istream)
  "Deserializes a message object of type '<ContactMode>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'leg_contacts) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'leg_contacts)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'quad_msgs-msg:LegContactMode))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<ContactMode>)))
  "Returns string type for a message object of type '<ContactMode>"
  "quad_msgs/ContactMode")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'ContactMode)))
  "Returns string type for a message object of type 'ContactMode"
  "quad_msgs/ContactMode")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<ContactMode>)))
  "Returns md5sum for a message object of type '<ContactMode>"
  "26ebde1d6ad14a11545e27eb1d085e28")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'ContactMode)))
  "Returns md5sum for a message object of type 'ContactMode"
  "26ebde1d6ad14a11545e27eb1d085e28")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<ContactMode>)))
  "Returns full string definition for message of type '<ContactMode>"
  (cl:format cl:nil "# This is a message to hold contact states of the robot~%Header header~%~%LegContactMode[] leg_contacts # FL Bl FR BR~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: quad_msgs/LegContactMode~%# This is a message to hold contact mode of one leg~%Header header~%~%float32 contact_prob~%bool contact_state~%geometry_msgs/Vector3 contact_forces #fx,fy,fz~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'ContactMode)))
  "Returns full string definition for message of type 'ContactMode"
  (cl:format cl:nil "# This is a message to hold contact states of the robot~%Header header~%~%LegContactMode[] leg_contacts # FL Bl FR BR~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: quad_msgs/LegContactMode~%# This is a message to hold contact mode of one leg~%Header header~%~%float32 contact_prob~%bool contact_state~%geometry_msgs/Vector3 contact_forces #fx,fy,fz~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <ContactMode>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'leg_contacts) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <ContactMode>))
  "Converts a ROS message object to a list"
  (cl:list 'ContactMode
    (cl:cons ':header (header msg))
    (cl:cons ':leg_contacts (leg_contacts msg))
))
