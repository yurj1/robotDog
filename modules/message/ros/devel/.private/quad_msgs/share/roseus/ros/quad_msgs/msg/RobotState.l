;; Auto-generated. Do not edit!


(when (boundp 'quad_msgs::RobotState)
  (if (not (find-package "QUAD_MSGS"))
    (make-package "QUAD_MSGS"))
  (shadow 'RobotState (find-package "QUAD_MSGS")))
(unless (find-package "QUAD_MSGS::ROBOTSTATE")
  (make-package "QUAD_MSGS::ROBOTSTATE"))

(in-package "ROS")
;;//! \htmlinclude RobotState.msg.html
(if (not (find-package "SENSOR_MSGS"))
  (ros::roseus-add-msgs "sensor_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass quad_msgs::RobotState
  :super ros::object
  :slots (_header _traj_index _body _joints _feet ))

(defmethod quad_msgs::RobotState
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:traj_index __traj_index) 0)
    ((:body __body) (instance quad_msgs::BodyState :init))
    ((:joints __joints) (instance sensor_msgs::JointState :init))
    ((:feet __feet) (instance quad_msgs::MultiFootState :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _traj_index (round __traj_index))
   (setq _body __body)
   (setq _joints __joints)
   (setq _feet __feet)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:traj_index
   (&optional __traj_index)
   (if __traj_index (setq _traj_index __traj_index)) _traj_index)
  (:body
   (&rest __body)
   (if (keywordp (car __body))
       (send* _body __body)
     (progn
       (if __body (setq _body (car __body)))
       _body)))
  (:joints
   (&rest __joints)
   (if (keywordp (car __joints))
       (send* _joints __joints)
     (progn
       (if __joints (setq _joints (car __joints)))
       _joints)))
  (:feet
   (&rest __feet)
   (if (keywordp (car __feet))
       (send* _feet __feet)
     (progn
       (if __feet (setq _feet (car __feet)))
       _feet)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; uint32 _traj_index
    4
    ;; quad_msgs/BodyState _body
    (send _body :serialization-length)
    ;; sensor_msgs/JointState _joints
    (send _joints :serialization-length)
    ;; quad_msgs/MultiFootState _feet
    (send _feet :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint32 _traj_index
       (write-long _traj_index s)
     ;; quad_msgs/BodyState _body
       (send _body :serialize s)
     ;; sensor_msgs/JointState _joints
       (send _joints :serialize s)
     ;; quad_msgs/MultiFootState _feet
       (send _feet :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint32 _traj_index
     (setq _traj_index (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; quad_msgs/BodyState _body
     (send _body :deserialize buf ptr-) (incf ptr- (send _body :serialization-length))
   ;; sensor_msgs/JointState _joints
     (send _joints :deserialize buf ptr-) (incf ptr- (send _joints :serialization-length))
   ;; quad_msgs/MultiFootState _feet
     (send _feet :deserialize buf ptr-) (incf ptr- (send _feet :serialization-length))
   ;;
   self)
  )

(setf (get quad_msgs::RobotState :md5sum-) "574a4aa128f06841e7a15be99c32c86c")
(setf (get quad_msgs::RobotState :datatype-) "quad_msgs/RobotState")
(setf (get quad_msgs::RobotState :definition-)
      "# This is a message to hold a robot state
#
# The state is defined as an Odometry message with the body odometry, and a JointState message with joint positions and velocities
# Accurate timing information is stored in the header

Header header
uint32 traj_index
quad_msgs/BodyState body
sensor_msgs/JointState joints
quad_msgs/MultiFootState feet
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
")



(provide :quad_msgs/RobotState "574a4aa128f06841e7a15be99c32c86c")


