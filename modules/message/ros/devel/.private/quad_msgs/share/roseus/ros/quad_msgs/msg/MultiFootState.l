;; Auto-generated. Do not edit!


(when (boundp 'quad_msgs::MultiFootState)
  (if (not (find-package "QUAD_MSGS"))
    (make-package "QUAD_MSGS"))
  (shadow 'MultiFootState (find-package "QUAD_MSGS")))
(unless (find-package "QUAD_MSGS::MULTIFOOTSTATE")
  (make-package "QUAD_MSGS::MULTIFOOTSTATE"))

(in-package "ROS")
;;//! \htmlinclude MultiFootState.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass quad_msgs::MultiFootState
  :super ros::object
  :slots (_header _traj_index _feet ))

(defmethod quad_msgs::MultiFootState
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:traj_index __traj_index) 0)
    ((:feet __feet) ())
    )
   (send-super :init)
   (setq _header __header)
   (setq _traj_index (round __traj_index))
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
    ;; quad_msgs/FootState[] _feet
    (apply #'+ (send-all _feet :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; uint32 _traj_index
       (write-long _traj_index s)
     ;; quad_msgs/FootState[] _feet
     (write-long (length _feet) s)
     (dolist (elem _feet)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; uint32 _traj_index
     (setq _traj_index (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; quad_msgs/FootState[] _feet
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _feet (let (r) (dotimes (i n) (push (instance quad_msgs::FootState :init) r)) r))
     (dolist (elem- _feet)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get quad_msgs::MultiFootState :md5sum-) "0ebb914d22f2140664b36ac273cb4479")
(setf (get quad_msgs::MultiFootState :datatype-) "quad_msgs/MultiFootState")
(setf (get quad_msgs::MultiFootState :definition-)
      "# This is a message to hold the state of all feet of a legged robot
#
# The states of each foot are stored in a vector of FootState messages
# (0 = front left, 1 = back left, 2 = front right, 3 = back right).
# Accurate timing information is stored in the header

Header header
uint32 traj_index
quad_msgs/FootState[] feet
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



(provide :quad_msgs/MultiFootState "0ebb914d22f2140664b36ac273cb4479")


