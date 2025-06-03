; Auto-generated. Do not edit!


(cl:in-package quad_msgs-msg)


;//! \htmlinclude RobotPlan.msg.html

(cl:defclass <RobotPlan> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (global_plan_timestamp
    :reader global_plan_timestamp
    :initarg :global_plan_timestamp
    :type cl:real
    :initform 0)
   (state_timestamp
    :reader state_timestamp
    :initarg :state_timestamp
    :type cl:real
    :initform 0)
   (states
    :reader states
    :initarg :states
    :type (cl:vector quad_msgs-msg:RobotState)
   :initform (cl:make-array 0 :element-type 'quad_msgs-msg:RobotState :initial-element (cl:make-instance 'quad_msgs-msg:RobotState)))
   (grfs
    :reader grfs
    :initarg :grfs
    :type (cl:vector quad_msgs-msg:GRFArray)
   :initform (cl:make-array 0 :element-type 'quad_msgs-msg:GRFArray :initial-element (cl:make-instance 'quad_msgs-msg:GRFArray)))
   (plan_indices
    :reader plan_indices
    :initarg :plan_indices
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0))
   (primitive_ids
    :reader primitive_ids
    :initarg :primitive_ids
    :type (cl:vector cl:integer)
   :initform (cl:make-array 0 :element-type 'cl:integer :initial-element 0))
   (compute_time
    :reader compute_time
    :initarg :compute_time
    :type cl:float
    :initform 0.0)
   (diagnostics
    :reader diagnostics
    :initarg :diagnostics
    :type quad_msgs-msg:RobotPlanDiagnostics
    :initform (cl:make-instance 'quad_msgs-msg:RobotPlanDiagnostics)))
)

(cl:defclass RobotPlan (<RobotPlan>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RobotPlan>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RobotPlan)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name quad_msgs-msg:<RobotPlan> is deprecated: use quad_msgs-msg:RobotPlan instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <RobotPlan>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:header-val is deprecated.  Use quad_msgs-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'global_plan_timestamp-val :lambda-list '(m))
(cl:defmethod global_plan_timestamp-val ((m <RobotPlan>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:global_plan_timestamp-val is deprecated.  Use quad_msgs-msg:global_plan_timestamp instead.")
  (global_plan_timestamp m))

(cl:ensure-generic-function 'state_timestamp-val :lambda-list '(m))
(cl:defmethod state_timestamp-val ((m <RobotPlan>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:state_timestamp-val is deprecated.  Use quad_msgs-msg:state_timestamp instead.")
  (state_timestamp m))

(cl:ensure-generic-function 'states-val :lambda-list '(m))
(cl:defmethod states-val ((m <RobotPlan>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:states-val is deprecated.  Use quad_msgs-msg:states instead.")
  (states m))

(cl:ensure-generic-function 'grfs-val :lambda-list '(m))
(cl:defmethod grfs-val ((m <RobotPlan>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:grfs-val is deprecated.  Use quad_msgs-msg:grfs instead.")
  (grfs m))

(cl:ensure-generic-function 'plan_indices-val :lambda-list '(m))
(cl:defmethod plan_indices-val ((m <RobotPlan>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:plan_indices-val is deprecated.  Use quad_msgs-msg:plan_indices instead.")
  (plan_indices m))

(cl:ensure-generic-function 'primitive_ids-val :lambda-list '(m))
(cl:defmethod primitive_ids-val ((m <RobotPlan>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:primitive_ids-val is deprecated.  Use quad_msgs-msg:primitive_ids instead.")
  (primitive_ids m))

(cl:ensure-generic-function 'compute_time-val :lambda-list '(m))
(cl:defmethod compute_time-val ((m <RobotPlan>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:compute_time-val is deprecated.  Use quad_msgs-msg:compute_time instead.")
  (compute_time m))

(cl:ensure-generic-function 'diagnostics-val :lambda-list '(m))
(cl:defmethod diagnostics-val ((m <RobotPlan>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader quad_msgs-msg:diagnostics-val is deprecated.  Use quad_msgs-msg:diagnostics instead.")
  (diagnostics m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RobotPlan>) ostream)
  "Serializes a message object of type '<RobotPlan>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((__sec (cl:floor (cl:slot-value msg 'global_plan_timestamp)))
        (__nsec (cl:round (cl:* 1e9 (cl:- (cl:slot-value msg 'global_plan_timestamp) (cl:floor (cl:slot-value msg 'global_plan_timestamp)))))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 0) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __nsec) ostream))
  (cl:let ((__sec (cl:floor (cl:slot-value msg 'state_timestamp)))
        (__nsec (cl:round (cl:* 1e9 (cl:- (cl:slot-value msg 'state_timestamp) (cl:floor (cl:slot-value msg 'state_timestamp)))))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __sec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 0) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __nsec) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __nsec) ostream))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'states))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'states))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'grfs))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'grfs))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'plan_indices))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) ele) ostream))
   (cl:slot-value msg 'plan_indices))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'primitive_ids))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:write-byte (cl:ldb (cl:byte 8 0) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) ele) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) ele) ostream))
   (cl:slot-value msg 'primitive_ids))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'compute_time))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'diagnostics) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RobotPlan>) istream)
  "Deserializes a message object of type '<RobotPlan>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((__sec 0) (__nsec 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 0) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __nsec) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'global_plan_timestamp) (cl:+ (cl:coerce __sec 'cl:double-float) (cl:/ __nsec 1e9))))
    (cl:let ((__sec 0) (__nsec 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __sec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 0) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __nsec) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __nsec) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'state_timestamp) (cl:+ (cl:coerce __sec 'cl:double-float) (cl:/ __nsec 1e9))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'states) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'states)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'quad_msgs-msg:RobotState))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'grfs) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'grfs)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'quad_msgs-msg:GRFArray))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'plan_indices) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'plan_indices)))
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
  (cl:setf (cl:slot-value msg 'primitive_ids) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'primitive_ids)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:aref vals i)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:aref vals i)) (cl:read-byte istream)))))
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
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'diagnostics) istream)
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RobotPlan>)))
  "Returns string type for a message object of type '<RobotPlan>"
  "quad_msgs/RobotPlan")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RobotPlan)))
  "Returns string type for a message object of type 'RobotPlan"
  "quad_msgs/RobotPlan")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RobotPlan>)))
  "Returns md5sum for a message object of type '<RobotPlan>"
  "8de5642b258cdd451a16eb8e7e249612")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RobotPlan)))
  "Returns md5sum for a message object of type 'RobotPlan"
  "8de5642b258cdd451a16eb8e7e249612")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RobotPlan>)))
  "Returns full string definition for message of type '<RobotPlan>"
  (cl:format cl:nil "# This is a message to hold a robot plan~%#~%# The plan is defined as an array of odometry messages.~%# Accurate timing information for localization is stored in the header.~%# This should match the first state in the states vector.~%~%Header header~%time global_plan_timestamp~%time state_timestamp~%quad_msgs/RobotState[] states~%quad_msgs/GRFArray[] grfs~%uint32[] plan_indices~%uint32[] primitive_ids~%float64 compute_time~%quad_msgs/RobotPlanDiagnostics diagnostics~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: quad_msgs/RobotState~%# This is a message to hold a robot state~%#~%# The state is defined as an Odometry message with the body odometry, and a JointState message with joint positions and velocities~%# Accurate timing information is stored in the header~%~%Header header~%uint32 traj_index~%quad_msgs/BodyState body~%sensor_msgs/JointState joints~%quad_msgs/MultiFootState feet~%================================================================================~%MSG: quad_msgs/BodyState~%# This is a message to hold a robot body state~%#~%# The body state is defined as an pose and twist messages~%# Accurate timing information is stored in the header~%~%Header header~%uint32 traj_index~%geometry_msgs/Pose pose~%geometry_msgs/Twist twist~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: sensor_msgs/JointState~%# This is a message that holds data to describe the state of a set of torque controlled joints. ~%#~%# The state of each joint (revolute or prismatic) is defined by:~%#  * the position of the joint (rad or m),~%#  * the velocity of the joint (rad/s or m/s) and ~%#  * the effort that is applied in the joint (Nm or N).~%#~%# Each joint is uniquely identified by its name~%# The header specifies the time at which the joint states were recorded. All the joint states~%# in one message have to be recorded at the same time.~%#~%# This message consists of a multiple arrays, one for each part of the joint state. ~%# The goal is to make each of the fields optional. When e.g. your joints have no~%# effort associated with them, you can leave the effort array empty. ~%#~%# All arrays in this message should have the same size, or be empty.~%# This is the only way to uniquely associate the joint name with the correct~%# states.~%~%~%Header header~%~%string[] name~%float64[] position~%float64[] velocity~%float64[] effort~%~%================================================================================~%MSG: quad_msgs/MultiFootState~%# This is a message to hold the state of all feet of a legged robot~%#~%# The states of each foot are stored in a vector of FootState messages~%# (0 = front left, 1 = back left, 2 = front right, 3 = back right).~%# Accurate timing information is stored in the header~%~%Header header~%uint32 traj_index~%quad_msgs/FootState[] feet~%================================================================================~%MSG: quad_msgs/FootState~%# This is a message to hold the state of a single foot of a legged robot~%#~%# The states of each foot are stored in a vector of FootState messages~%# Accurate timing information is stored in the header~%~%Header header~%uint32 traj_index~%geometry_msgs/Vector3 position~%geometry_msgs/Vector3 velocity~%geometry_msgs/Vector3 acceleration~%bool contact~%================================================================================~%MSG: quad_msgs/GRFArray~%# This is a message to hold an array of ground reaction forces and their points of application~%#~%# Accurate timing information is stored in the header.~%~%Header header~%geometry_msgs/Vector3[] vectors~%geometry_msgs/Point[] points~%bool[] contact_states~%uint32 traj_index~%================================================================================~%MSG: quad_msgs/RobotPlanDiagnostics~%# This is a message to hold local plan diagnostics~%~%float64 compute_time~%float64 cost~%uint32 iterations~%uint32 horizon_length~%uint32[] complexity_schedule~%float64[] element_times~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RobotPlan)))
  "Returns full string definition for message of type 'RobotPlan"
  (cl:format cl:nil "# This is a message to hold a robot plan~%#~%# The plan is defined as an array of odometry messages.~%# Accurate timing information for localization is stored in the header.~%# This should match the first state in the states vector.~%~%Header header~%time global_plan_timestamp~%time state_timestamp~%quad_msgs/RobotState[] states~%quad_msgs/GRFArray[] grfs~%uint32[] plan_indices~%uint32[] primitive_ids~%float64 compute_time~%quad_msgs/RobotPlanDiagnostics diagnostics~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: quad_msgs/RobotState~%# This is a message to hold a robot state~%#~%# The state is defined as an Odometry message with the body odometry, and a JointState message with joint positions and velocities~%# Accurate timing information is stored in the header~%~%Header header~%uint32 traj_index~%quad_msgs/BodyState body~%sensor_msgs/JointState joints~%quad_msgs/MultiFootState feet~%================================================================================~%MSG: quad_msgs/BodyState~%# This is a message to hold a robot body state~%#~%# The body state is defined as an pose and twist messages~%# Accurate timing information is stored in the header~%~%Header header~%uint32 traj_index~%geometry_msgs/Pose pose~%geometry_msgs/Twist twist~%~%================================================================================~%MSG: geometry_msgs/Pose~%# A representation of pose in free space, composed of position and orientation. ~%Point position~%Quaternion orientation~%~%================================================================================~%MSG: geometry_msgs/Point~%# This contains the position of a point in free space~%float64 x~%float64 y~%float64 z~%~%================================================================================~%MSG: geometry_msgs/Quaternion~%# This represents an orientation in free space in quaternion form.~%~%float64 x~%float64 y~%float64 z~%float64 w~%~%================================================================================~%MSG: geometry_msgs/Twist~%# This expresses velocity in free space broken into its linear and angular parts.~%Vector3  linear~%Vector3  angular~%~%================================================================================~%MSG: geometry_msgs/Vector3~%# This represents a vector in free space. ~%# It is only meant to represent a direction. Therefore, it does not~%# make sense to apply a translation to it (e.g., when applying a ~%# generic rigid transformation to a Vector3, tf2 will only apply the~%# rotation). If you want your data to be translatable too, use the~%# geometry_msgs/Point message instead.~%~%float64 x~%float64 y~%float64 z~%================================================================================~%MSG: sensor_msgs/JointState~%# This is a message that holds data to describe the state of a set of torque controlled joints. ~%#~%# The state of each joint (revolute or prismatic) is defined by:~%#  * the position of the joint (rad or m),~%#  * the velocity of the joint (rad/s or m/s) and ~%#  * the effort that is applied in the joint (Nm or N).~%#~%# Each joint is uniquely identified by its name~%# The header specifies the time at which the joint states were recorded. All the joint states~%# in one message have to be recorded at the same time.~%#~%# This message consists of a multiple arrays, one for each part of the joint state. ~%# The goal is to make each of the fields optional. When e.g. your joints have no~%# effort associated with them, you can leave the effort array empty. ~%#~%# All arrays in this message should have the same size, or be empty.~%# This is the only way to uniquely associate the joint name with the correct~%# states.~%~%~%Header header~%~%string[] name~%float64[] position~%float64[] velocity~%float64[] effort~%~%================================================================================~%MSG: quad_msgs/MultiFootState~%# This is a message to hold the state of all feet of a legged robot~%#~%# The states of each foot are stored in a vector of FootState messages~%# (0 = front left, 1 = back left, 2 = front right, 3 = back right).~%# Accurate timing information is stored in the header~%~%Header header~%uint32 traj_index~%quad_msgs/FootState[] feet~%================================================================================~%MSG: quad_msgs/FootState~%# This is a message to hold the state of a single foot of a legged robot~%#~%# The states of each foot are stored in a vector of FootState messages~%# Accurate timing information is stored in the header~%~%Header header~%uint32 traj_index~%geometry_msgs/Vector3 position~%geometry_msgs/Vector3 velocity~%geometry_msgs/Vector3 acceleration~%bool contact~%================================================================================~%MSG: quad_msgs/GRFArray~%# This is a message to hold an array of ground reaction forces and their points of application~%#~%# Accurate timing information is stored in the header.~%~%Header header~%geometry_msgs/Vector3[] vectors~%geometry_msgs/Point[] points~%bool[] contact_states~%uint32 traj_index~%================================================================================~%MSG: quad_msgs/RobotPlanDiagnostics~%# This is a message to hold local plan diagnostics~%~%float64 compute_time~%float64 cost~%uint32 iterations~%uint32 horizon_length~%uint32[] complexity_schedule~%float64[] element_times~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RobotPlan>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     8
     8
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'states) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'grfs) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'plan_indices) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'primitive_ids) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4)))
     8
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'diagnostics))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RobotPlan>))
  "Converts a ROS message object to a list"
  (cl:list 'RobotPlan
    (cl:cons ':header (header msg))
    (cl:cons ':global_plan_timestamp (global_plan_timestamp msg))
    (cl:cons ':state_timestamp (state_timestamp msg))
    (cl:cons ':states (states msg))
    (cl:cons ':grfs (grfs msg))
    (cl:cons ':plan_indices (plan_indices msg))
    (cl:cons ':primitive_ids (primitive_ids msg))
    (cl:cons ':compute_time (compute_time msg))
    (cl:cons ':diagnostics (diagnostics msg))
))
