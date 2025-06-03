;; Auto-generated. Do not edit!


(when (boundp 'quad_msgs::MultiFootPlanContinuous)
  (if (not (find-package "QUAD_MSGS"))
    (make-package "QUAD_MSGS"))
  (shadow 'MultiFootPlanContinuous (find-package "QUAD_MSGS")))
(unless (find-package "QUAD_MSGS::MULTIFOOTPLANCONTINUOUS")
  (make-package "QUAD_MSGS::MULTIFOOTPLANCONTINUOUS"))

(in-package "ROS")
;;//! \htmlinclude MultiFootPlanContinuous.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass quad_msgs::MultiFootPlanContinuous
  :super ros::object
  :slots (_header _states ))

(defmethod quad_msgs::MultiFootPlanContinuous
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:states __states) ())
    )
   (send-super :init)
   (setq _header __header)
   (setq _states __states)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:states
   (&rest __states)
   (if (keywordp (car __states))
       (send* _states __states)
     (progn
       (if __states (setq _states (car __states)))
       _states)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; quad_msgs/MultiFootState[] _states
    (apply #'+ (send-all _states :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; quad_msgs/MultiFootState[] _states
     (write-long (length _states) s)
     (dolist (elem _states)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; quad_msgs/MultiFootState[] _states
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _states (let (r) (dotimes (i n) (push (instance quad_msgs::MultiFootState :init) r)) r))
     (dolist (elem- _states)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get quad_msgs::MultiFootPlanContinuous :md5sum-) "d273ca50ce913e8177d08f48b443b819")
(setf (get quad_msgs::MultiFootPlanContinuous :datatype-) "quad_msgs/MultiFootPlanContinuous")
(setf (get quad_msgs::MultiFootPlanContinuous :definition-)
      "# This is a message to hold a continuous foot plan for multiple robot feet
#
# The plan is defined as a vector of MultiFootState messages
# Accurate timing information to localize the plans is stored in the header

Header header
quad_msgs/MultiFootState[] states
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
")



(provide :quad_msgs/MultiFootPlanContinuous "d273ca50ce913e8177d08f48b443b819")


