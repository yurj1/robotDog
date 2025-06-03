;; Auto-generated. Do not edit!


(when (boundp 'quad_msgs::LegCommand)
  (if (not (find-package "QUAD_MSGS"))
    (make-package "QUAD_MSGS"))
  (shadow 'LegCommand (find-package "QUAD_MSGS")))
(unless (find-package "QUAD_MSGS::LEGCOMMAND")
  (make-package "QUAD_MSGS::LEGCOMMAND"))

(in-package "ROS")
;;//! \htmlinclude LegCommand.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass quad_msgs::LegCommand
  :super ros::object
  :slots (_header _motor_commands ))

(defmethod quad_msgs::LegCommand
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:motor_commands __motor_commands) ())
    )
   (send-super :init)
   (setq _header __header)
   (setq _motor_commands __motor_commands)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:motor_commands
   (&rest __motor_commands)
   (if (keywordp (car __motor_commands))
       (send* _motor_commands __motor_commands)
     (progn
       (if __motor_commands (setq _motor_commands (car __motor_commands)))
       _motor_commands)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; quad_msgs/MotorCommand[] _motor_commands
    (apply #'+ (send-all _motor_commands :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; quad_msgs/MotorCommand[] _motor_commands
     (write-long (length _motor_commands) s)
     (dolist (elem _motor_commands)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; quad_msgs/MotorCommand[] _motor_commands
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _motor_commands (let (r) (dotimes (i n) (push (instance quad_msgs::MotorCommand :init) r)) r))
     (dolist (elem- _motor_commands)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get quad_msgs::LegCommand :md5sum-) "d6c030f02d2ce6c38e25ddee1faf99f3")
(setf (get quad_msgs::LegCommand :datatype-) "quad_msgs/LegCommand")
(setf (get quad_msgs::LegCommand :definition-)
      "# This is a message of motor commands for each joint on a quad leg.
#
# Accurate timing information is stored in the header

Header header

MotorCommand[] motor_commands # Stored as Abd, Hip, Knee

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



(provide :quad_msgs/LegCommand "d6c030f02d2ce6c38e25ddee1faf99f3")


