;; Auto-generated. Do not edit!


(when (boundp 'quad_msgs::RobotPlan)
  (if (not (find-package "QUAD_MSGS"))
    (make-package "QUAD_MSGS"))
  (shadow 'RobotPlan (find-package "QUAD_MSGS")))
(unless (find-package "QUAD_MSGS::ROBOTPLAN")
  (make-package "QUAD_MSGS::ROBOTPLAN"))

(in-package "ROS")
;;//! \htmlinclude RobotPlan.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass quad_msgs::RobotPlan
  :super ros::object
  :slots (_header _global_plan_timestamp _state_timestamp _states _grfs _plan_indices _primitive_ids _compute_time _diagnostics ))

(defmethod quad_msgs::RobotPlan
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:global_plan_timestamp __global_plan_timestamp) (instance ros::time :init))
    ((:state_timestamp __state_timestamp) (instance ros::time :init))
    ((:states __states) ())
    ((:grfs __grfs) ())
    ((:plan_indices __plan_indices) (make-array 0 :initial-element 0 :element-type :integer))
    ((:primitive_ids __primitive_ids) (make-array 0 :initial-element 0 :element-type :integer))
    ((:compute_time __compute_time) 0.0)
    ((:diagnostics __diagnostics) (instance quad_msgs::RobotPlanDiagnostics :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _global_plan_timestamp __global_plan_timestamp)
   (setq _state_timestamp __state_timestamp)
   (setq _states __states)
   (setq _grfs __grfs)
   (setq _plan_indices __plan_indices)
   (setq _primitive_ids __primitive_ids)
   (setq _compute_time (float __compute_time))
   (setq _diagnostics __diagnostics)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:global_plan_timestamp
   (&optional __global_plan_timestamp)
   (if __global_plan_timestamp (setq _global_plan_timestamp __global_plan_timestamp)) _global_plan_timestamp)
  (:state_timestamp
   (&optional __state_timestamp)
   (if __state_timestamp (setq _state_timestamp __state_timestamp)) _state_timestamp)
  (:states
   (&rest __states)
   (if (keywordp (car __states))
       (send* _states __states)
     (progn
       (if __states (setq _states (car __states)))
       _states)))
  (:grfs
   (&rest __grfs)
   (if (keywordp (car __grfs))
       (send* _grfs __grfs)
     (progn
       (if __grfs (setq _grfs (car __grfs)))
       _grfs)))
  (:plan_indices
   (&optional __plan_indices)
   (if __plan_indices (setq _plan_indices __plan_indices)) _plan_indices)
  (:primitive_ids
   (&optional __primitive_ids)
   (if __primitive_ids (setq _primitive_ids __primitive_ids)) _primitive_ids)
  (:compute_time
   (&optional __compute_time)
   (if __compute_time (setq _compute_time __compute_time)) _compute_time)
  (:diagnostics
   (&rest __diagnostics)
   (if (keywordp (car __diagnostics))
       (send* _diagnostics __diagnostics)
     (progn
       (if __diagnostics (setq _diagnostics (car __diagnostics)))
       _diagnostics)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; time _global_plan_timestamp
    8
    ;; time _state_timestamp
    8
    ;; quad_msgs/RobotState[] _states
    (apply #'+ (send-all _states :serialization-length)) 4
    ;; quad_msgs/GRFArray[] _grfs
    (apply #'+ (send-all _grfs :serialization-length)) 4
    ;; uint32[] _plan_indices
    (* 4    (length _plan_indices)) 4
    ;; uint32[] _primitive_ids
    (* 4    (length _primitive_ids)) 4
    ;; float64 _compute_time
    8
    ;; quad_msgs/RobotPlanDiagnostics _diagnostics
    (send _diagnostics :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; time _global_plan_timestamp
       (write-long (send _global_plan_timestamp :sec) s) (write-long (send _global_plan_timestamp :nsec) s)
     ;; time _state_timestamp
       (write-long (send _state_timestamp :sec) s) (write-long (send _state_timestamp :nsec) s)
     ;; quad_msgs/RobotState[] _states
     (write-long (length _states) s)
     (dolist (elem _states)
       (send elem :serialize s)
       )
     ;; quad_msgs/GRFArray[] _grfs
     (write-long (length _grfs) s)
     (dolist (elem _grfs)
       (send elem :serialize s)
       )
     ;; uint32[] _plan_indices
     (write-long (length _plan_indices) s)
     (dotimes (i (length _plan_indices))
       (write-long (elt _plan_indices i) s)
       )
     ;; uint32[] _primitive_ids
     (write-long (length _primitive_ids) s)
     (dotimes (i (length _primitive_ids))
       (write-long (elt _primitive_ids i) s)
       )
     ;; float64 _compute_time
       (sys::poke _compute_time (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; quad_msgs/RobotPlanDiagnostics _diagnostics
       (send _diagnostics :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; time _global_plan_timestamp
     (send _global_plan_timestamp :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _global_plan_timestamp :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; time _state_timestamp
     (send _state_timestamp :sec (sys::peek buf ptr- :integer)) (incf ptr- 4)  (send _state_timestamp :nsec (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; quad_msgs/RobotState[] _states
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _states (let (r) (dotimes (i n) (push (instance quad_msgs::RobotState :init) r)) r))
     (dolist (elem- _states)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; quad_msgs/GRFArray[] _grfs
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _grfs (let (r) (dotimes (i n) (push (instance quad_msgs::GRFArray :init) r)) r))
     (dolist (elem- _grfs)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; uint32[] _plan_indices
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _plan_indices (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _plan_indices i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; uint32[] _primitive_ids
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _primitive_ids (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _primitive_ids i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; float64 _compute_time
     (setq _compute_time (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; quad_msgs/RobotPlanDiagnostics _diagnostics
     (send _diagnostics :deserialize buf ptr-) (incf ptr- (send _diagnostics :serialization-length))
   ;;
   self)
  )

(setf (get quad_msgs::RobotPlan :md5sum-) "8de5642b258cdd451a16eb8e7e249612")
(setf (get quad_msgs::RobotPlan :datatype-) "quad_msgs/RobotPlan")
(setf (get quad_msgs::RobotPlan :definition-)
      "# This is a message to hold a robot plan
#
# The plan is defined as an array of odometry messages.
# Accurate timing information for localization is stored in the header.
# This should match the first state in the states vector.

Header header
time global_plan_timestamp
time state_timestamp
quad_msgs/RobotState[] states
quad_msgs/GRFArray[] grfs
uint32[] plan_indices
uint32[] primitive_ids
float64 compute_time
quad_msgs/RobotPlanDiagnostics diagnostics

================================================================================
MSG: std_msgs/Header
# Standard metadata for higher-level stamped data types.
# This is generally used to communicate timestamped data 
# in a particular coordinate frame.
# 
# sequence ID: consecutively increasing ID 
uint32 seq
#Two-integer timestamp that is expressed as:
# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')
# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')
# time-handling sugar is provided by the client library
time stamp
#Frame this data is associated with
string frame_id

================================================================================
MSG: quad_msgs/RobotState
# This is a message to hold a robot state
#
# The state is defined as an Odometry message with the body odometry, and a JointState message with joint positions and velocities
# Accurate timing information is stored in the header

Header header
uint32 traj_index
quad_msgs/BodyState body
sensor_msgs/JointState joints
quad_msgs/MultiFootState feet
================================================================================
MSG: quad_msgs/BodyState
# This is a message to hold a robot body state
#
# The body state is defined as an pose and twist messages
# Accurate timing information is stored in the header

Header header
uint32 traj_index
geometry_msgs/Pose pose
geometry_msgs/Twist twist

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: geometry_msgs/Twist
# This expresses velocity in free space broken into its linear and angular parts.
Vector3  linear
Vector3  angular

================================================================================
MSG: geometry_msgs/Vector3
# This represents a vector in free space. 
# It is only meant to represent a direction. Therefore, it does not
# make sense to apply a translation to it (e.g., when applying a 
# generic rigid transformation to a Vector3, tf2 will only apply the
# rotation). If you want your data to be translatable too, use the
# geometry_msgs/Point message instead.

float64 x
float64 y
float64 z
================================================================================
MSG: sensor_msgs/JointState
# This is a message that holds data to describe the state of a set of torque controlled joints. 
#
# The state of each joint (revolute or prismatic) is defined by:
#  * the position of the joint (rad or m),
#  * the velocity of the joint (rad/s or m/s) and 
#  * the effort that is applied in the joint (Nm or N).
#
# Each joint is uniquely identified by its name
# The header specifies the time at which the joint states were recorded. All the joint states
# in one message have to be recorded at the same time.
#
# This message consists of a multiple arrays, one for each part of the joint state. 
# The goal is to make each of the fields optional. When e.g. your joints have no
# effort associated with them, you can leave the effort array empty. 
#
# All arrays in this message should have the same size, or be empty.
# This is the only way to uniquely associate the joint name with the correct
# states.


Header header

string[] name
float64[] position
float64[] velocity
float64[] effort

================================================================================
MSG: quad_msgs/MultiFootState
# This is a message to hold the state of all feet of a legged robot
#
# The states of each foot are stored in a vector of FootState messages
# (0 = front left, 1 = back left, 2 = front right, 3 = back right).
# Accurate timing information is stored in the header

Header header
uint32 traj_index
quad_msgs/FootState[] feet
================================================================================
MSG: quad_msgs/FootState
# This is a message to hold the state of a single foot of a legged robot
#
# The states of each foot are stored in a vector of FootState messages
# Accurate timing information is stored in the header

Header header
uint32 traj_index
geometry_msgs/Vector3 position
geometry_msgs/Vector3 velocity
geometry_msgs/Vector3 acceleration
bool contact
================================================================================
MSG: quad_msgs/GRFArray
# This is a message to hold an array of ground reaction forces and their points of application
#
# Accurate timing information is stored in the header.

Header header
geometry_msgs/Vector3[] vectors
geometry_msgs/Point[] points
bool[] contact_states
uint32 traj_index
================================================================================
MSG: quad_msgs/RobotPlanDiagnostics
# This is a message to hold local plan diagnostics

float64 compute_time
float64 cost
uint32 iterations
uint32 horizon_length
uint32[] complexity_schedule
float64[] element_times

")



(provide :quad_msgs/RobotPlan "8de5642b258cdd451a16eb8e7e249612")


