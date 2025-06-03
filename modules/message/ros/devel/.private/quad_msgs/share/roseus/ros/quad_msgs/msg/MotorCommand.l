;; Auto-generated. Do not edit!


(when (boundp 'quad_msgs::MotorCommand)
  (if (not (find-package "QUAD_MSGS"))
    (make-package "QUAD_MSGS"))
  (shadow 'MotorCommand (find-package "QUAD_MSGS")))
(unless (find-package "QUAD_MSGS::MOTORCOMMAND")
  (make-package "QUAD_MSGS::MOTORCOMMAND"))

(in-package "ROS")
;;//! \htmlinclude MotorCommand.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass quad_msgs::MotorCommand
  :super ros::object
  :slots (_header _pos_setpoint _vel_setpoint _kp _kd _torque_ff _pos_component _vel_component _fb_component _effort _fb_ratio ))

(defmethod quad_msgs::MotorCommand
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:pos_setpoint __pos_setpoint) 0.0)
    ((:vel_setpoint __vel_setpoint) 0.0)
    ((:kp __kp) 0.0)
    ((:kd __kd) 0.0)
    ((:torque_ff __torque_ff) 0.0)
    ((:pos_component __pos_component) 0.0)
    ((:vel_component __vel_component) 0.0)
    ((:fb_component __fb_component) 0.0)
    ((:effort __effort) 0.0)
    ((:fb_ratio __fb_ratio) 0.0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _pos_setpoint (float __pos_setpoint))
   (setq _vel_setpoint (float __vel_setpoint))
   (setq _kp (float __kp))
   (setq _kd (float __kd))
   (setq _torque_ff (float __torque_ff))
   (setq _pos_component (float __pos_component))
   (setq _vel_component (float __vel_component))
   (setq _fb_component (float __fb_component))
   (setq _effort (float __effort))
   (setq _fb_ratio (float __fb_ratio))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:pos_setpoint
   (&optional __pos_setpoint)
   (if __pos_setpoint (setq _pos_setpoint __pos_setpoint)) _pos_setpoint)
  (:vel_setpoint
   (&optional __vel_setpoint)
   (if __vel_setpoint (setq _vel_setpoint __vel_setpoint)) _vel_setpoint)
  (:kp
   (&optional __kp)
   (if __kp (setq _kp __kp)) _kp)
  (:kd
   (&optional __kd)
   (if __kd (setq _kd __kd)) _kd)
  (:torque_ff
   (&optional __torque_ff)
   (if __torque_ff (setq _torque_ff __torque_ff)) _torque_ff)
  (:pos_component
   (&optional __pos_component)
   (if __pos_component (setq _pos_component __pos_component)) _pos_component)
  (:vel_component
   (&optional __vel_component)
   (if __vel_component (setq _vel_component __vel_component)) _vel_component)
  (:fb_component
   (&optional __fb_component)
   (if __fb_component (setq _fb_component __fb_component)) _fb_component)
  (:effort
   (&optional __effort)
   (if __effort (setq _effort __effort)) _effort)
  (:fb_ratio
   (&optional __fb_ratio)
   (if __fb_ratio (setq _fb_ratio __fb_ratio)) _fb_ratio)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float64 _pos_setpoint
    8
    ;; float64 _vel_setpoint
    8
    ;; float32 _kp
    4
    ;; float32 _kd
    4
    ;; float64 _torque_ff
    8
    ;; float64 _pos_component
    8
    ;; float64 _vel_component
    8
    ;; float64 _fb_component
    8
    ;; float64 _effort
    8
    ;; float64 _fb_ratio
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float64 _pos_setpoint
       (sys::poke _pos_setpoint (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vel_setpoint
       (sys::poke _vel_setpoint (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float32 _kp
       (sys::poke _kp (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float32 _kd
       (sys::poke _kd (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; float64 _torque_ff
       (sys::poke _torque_ff (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _pos_component
       (sys::poke _pos_component (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _vel_component
       (sys::poke _vel_component (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _fb_component
       (sys::poke _fb_component (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _effort
       (sys::poke _effort (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _fb_ratio
       (sys::poke _fb_ratio (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float64 _pos_setpoint
     (setq _pos_setpoint (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vel_setpoint
     (setq _vel_setpoint (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float32 _kp
     (setq _kp (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float32 _kd
     (setq _kd (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; float64 _torque_ff
     (setq _torque_ff (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _pos_component
     (setq _pos_component (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _vel_component
     (setq _vel_component (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _fb_component
     (setq _fb_component (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _effort
     (setq _effort (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _fb_ratio
     (setq _fb_ratio (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get quad_msgs::MotorCommand :md5sum-) "e200217cec0ef4e0862655a028b63ff2")
(setf (get quad_msgs::MotorCommand :datatype-) "quad_msgs/MotorCommand")
(setf (get quad_msgs::MotorCommand :definition-)
      "# This is a message to hold the desired position, desired velocity, feedforward torques and control gains for a single joint on Quad
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

")



(provide :quad_msgs/MotorCommand "e200217cec0ef4e0862655a028b63ff2")


