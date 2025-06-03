;; Auto-generated. Do not edit!


(when (boundp 'quad_msgs::LegContactMode)
  (if (not (find-package "QUAD_MSGS"))
    (make-package "QUAD_MSGS"))
  (shadow 'LegContactMode (find-package "QUAD_MSGS")))
(unless (find-package "QUAD_MSGS::LEGCONTACTMODE")
  (make-package "QUAD_MSGS::LEGCONTACTMODE"))

(in-package "ROS")
;;//! \htmlinclude LegContactMode.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass quad_msgs::LegContactMode
  :super ros::object
  :slots (_header _contact_prob _contact_state _contact_forces ))

(defmethod quad_msgs::LegContactMode
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:contact_prob __contact_prob) 0.0)
    ((:contact_state __contact_state) nil)
    ((:contact_forces __contact_forces) (instance geometry_msgs::Vector3 :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _contact_prob (float __contact_prob))
   (setq _contact_state __contact_state)
   (setq _contact_forces __contact_forces)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:contact_prob
   (&optional __contact_prob)
   (if __contact_prob (setq _contact_prob __contact_prob)) _contact_prob)
  (:contact_state
   (&optional (__contact_state :null))
   (if (not (eq __contact_state :null)) (setq _contact_state __contact_state)) _contact_state)
  (:contact_forces
   (&rest __contact_forces)
   (if (keywordp (car __contact_forces))
       (send* _contact_forces __contact_forces)
     (progn
       (if __contact_forces (setq _contact_forces (car __contact_forces)))
       _contact_forces)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float32 _contact_prob
    4
    ;; bool _contact_state
    1
    ;; geometry_msgs/Vector3 _contact_forces
    (send _contact_forces :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float32 _contact_prob
       (sys::poke _contact_prob (send s :buffer) (send s :count) :float) (incf (stream-count s) 4)
     ;; bool _contact_state
       (if _contact_state (write-byte -1 s) (write-byte 0 s))
     ;; geometry_msgs/Vector3 _contact_forces
       (send _contact_forces :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float32 _contact_prob
     (setq _contact_prob (sys::peek buf ptr- :float)) (incf ptr- 4)
   ;; bool _contact_state
     (setq _contact_state (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; geometry_msgs/Vector3 _contact_forces
     (send _contact_forces :deserialize buf ptr-) (incf ptr- (send _contact_forces :serialization-length))
   ;;
   self)
  )

(setf (get quad_msgs::LegContactMode :md5sum-) "46ad19315dce64937e892556c64f6977")
(setf (get quad_msgs::LegContactMode :datatype-) "quad_msgs/LegContactMode")
(setf (get quad_msgs::LegContactMode :definition-)
      "# This is a message to hold contact mode of one leg
Header header

float32 contact_prob
bool contact_state
geometry_msgs/Vector3 contact_forces #fx,fy,fz

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



(provide :quad_msgs/LegContactMode "46ad19315dce64937e892556c64f6977")


