; Auto-generated. Do not edit!


(cl:in-package ros_interface-msg)


;//! \htmlinclude DrivableRegion.msg.html

(cl:defclass <DrivableRegion> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (drivable_region
    :reader drivable_region
    :initarg :drivable_region
    :type (cl:vector ros_interface-msg:Polygon3D)
   :initform (cl:make-array 0 :element-type 'ros_interface-msg:Polygon3D :initial-element (cl:make-instance 'ros_interface-msg:Polygon3D))))
)

(cl:defclass DrivableRegion (<DrivableRegion>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DrivableRegion>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DrivableRegion)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ros_interface-msg:<DrivableRegion> is deprecated: use ros_interface-msg:DrivableRegion instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <DrivableRegion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_interface-msg:header-val is deprecated.  Use ros_interface-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'drivable_region-val :lambda-list '(m))
(cl:defmethod drivable_region-val ((m <DrivableRegion>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_interface-msg:drivable_region-val is deprecated.  Use ros_interface-msg:drivable_region instead.")
  (drivable_region m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DrivableRegion>) ostream)
  "Serializes a message object of type '<DrivableRegion>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'drivable_region))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'drivable_region))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DrivableRegion>) istream)
  "Deserializes a message object of type '<DrivableRegion>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'drivable_region) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'drivable_region)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'ros_interface-msg:Polygon3D))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DrivableRegion>)))
  "Returns string type for a message object of type '<DrivableRegion>"
  "ros_interface/DrivableRegion")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DrivableRegion)))
  "Returns string type for a message object of type 'DrivableRegion"
  "ros_interface/DrivableRegion")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DrivableRegion>)))
  "Returns md5sum for a message object of type '<DrivableRegion>"
  "c14f4161a36f4f3dbefbe28192146c82")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DrivableRegion)))
  "Returns md5sum for a message object of type 'DrivableRegion"
  "c14f4161a36f4f3dbefbe28192146c82")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DrivableRegion>)))
  "Returns full string definition for message of type '<DrivableRegion>"
  (cl:format cl:nil "Header   header     # timestamp is included in header~%Polygon3D[] drivable_region # 可行驶区域~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: ros_interface/Polygon3D~%int32   coordinate_system     # 坐标系~%Point3D[] points # 三维点集~%~%================================================================================~%MSG: ros_interface/Point3D~%float64   x     # 位置坐标x~%float64   y     # 位置坐标y~%float64   z     # 位置坐标z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DrivableRegion)))
  "Returns full string definition for message of type 'DrivableRegion"
  (cl:format cl:nil "Header   header     # timestamp is included in header~%Polygon3D[] drivable_region # 可行驶区域~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: ros_interface/Polygon3D~%int32   coordinate_system     # 坐标系~%Point3D[] points # 三维点集~%~%================================================================================~%MSG: ros_interface/Point3D~%float64   x     # 位置坐标x~%float64   y     # 位置坐标y~%float64   z     # 位置坐标z~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DrivableRegion>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'drivable_region) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DrivableRegion>))
  "Converts a ROS message object to a list"
  (cl:list 'DrivableRegion
    (cl:cons ':header (header msg))
    (cl:cons ':drivable_region (drivable_region msg))
))
