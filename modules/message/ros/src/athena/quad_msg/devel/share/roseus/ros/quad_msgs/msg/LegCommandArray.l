;; Auto-generated. Do not edit!


(when (boundp 'quad_msgs::LegCommandArray)
  (if (not (find-package "QUAD_MSGS"))
    (make-package "QUAD_MSGS"))
  (shadow 'LegCommandArray (find-package "QUAD_MSGS")))
(unless (find-package "QUAD_MSGS::LEGCOMMANDARRAY")
  (make-package "QUAD_MSGS::LEGCOMMANDARRAY"))

(in-package "ROS")
;;//! \htmlinclude LegCommandArray.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass quad_msgs::LegCommandArray
  :super ros::object
  :slots (_header _leg_commands ))

(defmethod quad_msgs::LegCommandArray
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:leg_commands __leg_commands) ())
    )
   (send-super :init)
   (setq _header __header)
   (setq _leg_commands __leg_commands)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:leg_commands
   (&rest __leg_commands)
   (if (keywordp (car __leg_commands))
       (send* _leg_commands __leg_commands)
     (progn
       (if __leg_commands (setq _leg_commands (car __leg_commands)))
       _leg_commands)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; quad_msgs/LegCommand[] _leg_commands
    (apply #'+ (send-all _leg_commands :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; quad_msgs/LegCommand[] _leg_commands
     (write-long (length _leg_commands) s)
     (dolist (elem _leg_commands)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; quad_msgs/LegCommand[] _leg_commands
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _leg_commands (let (r) (dotimes (i n) (push (instance quad_msgs::LegCommand :init) r)) r))
     (dolist (elem- _leg_commands)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get quad_msgs::LegCommandArray :md5sum-) "021ecb87d231eeb30d1c10093fda1cef")
(setf (get quad_msgs::LegCommandArray :datatype-) "quad_msgs/LegCommandArray")
(setf (get quad_msgs::LegCommandArray :definition-)
      "# This is a message of leg commands for each leg on quad. The order is in FL, BL, FR, BR.
#
# Accurate timing information is stored in the header

Header header

LegCommand[] leg_commands # FL, BL, FR, BR

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
MSG: quad_msgs/LegCommand
# This is a message of motor commands for each joint on a quad leg.
#
# Accurate timing information is stored in the header

Header header

MotorCommand[] motor_commands # Stored as Abd, Hip, Knee

================================================================================
MSG: quad_msgs/MotorCommand
# This is a message to hold the desired position, desired velocity, feedforward torques and control gains for a single joint on Quad
#
# Accurate timing information is stored in the header

Header header

# Commands
float64 pos_setpoint # Position command
float64 vel_setpoint # Velocity command
float32 kp # Position setpoint gain
float32 kd # Derivative setpoint gain
float64 torque_ff # Feedforward torque

# Diagnostics
float64 pos_component # Feedback position component
float64 vel_component # Feedback velocity component
float64 fb_component # Feedback total component
float64 effort # Total effort
float64 fb_ratio # Feedback to total ratio

")



(provide :quad_msgs/LegCommandArray "021ecb87d231eeb30d1c10093fda1cef")


