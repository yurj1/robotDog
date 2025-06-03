;; Auto-generated. Do not edit!


(when (boundp 'quad_msgs::BodyForceEstimate)
  (if (not (find-package "QUAD_MSGS"))
    (make-package "QUAD_MSGS"))
  (shadow 'BodyForceEstimate (find-package "QUAD_MSGS")))
(unless (find-package "QUAD_MSGS::BODYFORCEESTIMATE")
  (make-package "QUAD_MSGS::BODYFORCEESTIMATE"))

(in-package "ROS")
;;//! \htmlinclude BodyForceEstimate.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass quad_msgs::BodyForceEstimate
  :super ros::object
  :slots (_header _joint_torques ))

(defmethod quad_msgs::BodyForceEstimate
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:joint_torques __joint_torques) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _header __header)
   (setq _joint_torques __joint_torques)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:joint_torques
   (&optional __joint_torques)
   (if __joint_torques (setq _joint_torques __joint_torques)) _joint_torques)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float64[] _joint_torques
    (* 8    (length _joint_torques)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float64[] _joint_torques
     (write-long (length _joint_torques) s)
     (dotimes (i (length _joint_torques))
       (sys::poke (elt _joint_torques i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float64[] _joint_torques
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _joint_torques (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _joint_torques i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(setf (get quad_msgs::BodyForceEstimate :md5sum-) "ef120516450a16904de7fd214a0b2b2e")
(setf (get quad_msgs::BodyForceEstimate :datatype-) "quad_msgs/BodyForceEstimate")
(setf (get quad_msgs::BodyForceEstimate :definition-)
      "# This is a message to hold a body contact force estimate
#
# The body contact force vector holds the estimated external torques acting on each of the 12 joints.
# Accurate timing information is stored in the header

Header header

float64[] joint_torques
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



(provide :quad_msgs/BodyForceEstimate "ef120516450a16904de7fd214a0b2b2e")


