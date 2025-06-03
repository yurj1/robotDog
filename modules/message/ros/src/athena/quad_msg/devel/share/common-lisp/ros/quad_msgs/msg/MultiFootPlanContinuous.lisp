; Auto-generated. Do not edit!


(cl:in-package quad_msgs-msg)


;//! \htmlinclude MultiFootPlanContinuous.msg.html

(cl:defclass <MultiFootPlanContinuous> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (states
    :reader states
    :initarg :states
    :type (cl:vector quad_msgs-msg:MultiFootState)
   :initform (cl:make-array 0 :element-type 'quad_msgs-msg:MultiFootState :initial-element (cl:make-instance 'quad_msgs-msg:MultiFootState))))
)

(cl:defclass MultiFootPlanContinuous (<MultiFootPlanContinuous>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <MultiFootPlanContinuous>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'MultiFootPlanContinuous)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name quad_msgs-msg:<MultiFootPlanContinuous> is deprecated: use quad_msgs-msg:MultiFootPlanContinuous instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <MultiFootPlanContinuous>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:header-val is deprecated.  Use quad_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'states-val :lambda-list '(m))
(cl:defmethod states-val ((m <MultiFootPlanContinuous>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:states-val is deprecated.  Use quad_msgs-msg:states instead.")
  (states m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <MultiFootPlanContinuous>) ostream)
  "Serializes a message object of type '<MultiFootPlanContinuous>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'states))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'states))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <MultiFootPlanContinuous>) istream)
  "Deserializes a message object of type '<MultiFootPlanContinuous>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'states) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'states)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'quad_msgs-msg:MultiFootState))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<MultiFootPlanContinuous>)))
  "Returns string type for a message object of type '<MultiFootPlanContinuous>"
  "quad_msgs/MultiFootPlanContinuous")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'MultiFootPlanContinuous)))
  "Returns string type for a message object of type 'MultiFootPlanContinuous"
  "quad_msgs/MultiFootPlanContinuous")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<MultiFootPlanContinuous>)))
  "Returns md5sum for a message object of type '<MultiFootPlanContinuous>"
  "d273ca50ce913e8177d08f48b443b819")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'MultiFootPlanContinuous)))
  "Returns md5sum for a message object of type 'MultiFootPlanContinuous"
  "d273ca50ce913e8177d08f48b443b819")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<MultiFootPlanContinuous>)))
  "Returns full string definition for message of type '<MultiFootPlanContinuous>"
  (cl:format cl:nil "# This is a message to hold a continuous foot plan for multiple robot feet~%#~%# The plan is defined as a vector of MultiFootState messages~%# Accurate timing information to localize the plans is stored in the header~%~%Header header~%quad_msgs/MultiFootState[] states~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: quad_msgs/MultiFootState~%# This is a message to hold the state of all feet of a legged robot~%#~%# The states of each foot are stored in a vector of FootState messages~%# (0 = front left, 1 = back left, 2 = front right, 3 = back right).~%# Accurate timing information is stored in the header~%~%Header header~%uint32 traj_index~%quad_msgs/FootState[] feet~%================================================================================~%MSG: quad_msgs/FootState~%# This is a message to hold the state of a single foot of a legged robot~%#~%# The states of each foot are stored in a vector of FootState messages~%# Accurate timing information is stored in the header~%~%Header header~%uint32 traj_index~%geometry_msgs/Vector3 position~%geometry_msgs/Vector3 velocity~%geometry_msgs/Vector3 acceleration~%bool contact~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'MultiFootPlanContinuous)))
  "Returns full string definition for message of type 'MultiFootPlanContinuous"
  (cl:format cl:nil "# This is a message to hold a continuous foot plan for multiple robot feet~%#~%# The plan is defined as a vector of MultiFootState messages~%# Accurate timing information to localize the plans is stored in the header~%~%Header header~%quad_msgs/MultiFootState[] states~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: quad_msgs/MultiFootState~%# This is a message to hold the state of all feet of a legged robot~%#~%# The states of each foot are stored in a vector of FootState messages~%# (0 = front left, 1 = back left, 2 = front right, 3 = back right).~%# Accurate timing information is stored in the header~%~%Header header~%uint32 traj_index~%quad_msgs/FootState[] feet~%================================================================================~%MSG: quad_msgs/FootState~%# This is a message to hold the state of a single foot of a legged robot~%#~%# The states of each foot are stored in a vector of FootState messages~%# Accurate timing information is stored in the header~%~%Header header~%uint32 traj_index~%geometry_msgs/Vector3 position~%geometry_msgs/Vector3 velocity~%geometry_msgs/Vector3 acceleration~%bool contact~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <MultiFootPlanContinuous>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'states) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <MultiFootPlanContinuous>))
  "Converts a ROS message object to a list"
  (cl:list 'MultiFootPlanContinuous
    (cl:cons ':header (header msg))
    (cl:cons ':states (states msg))
))
