;; Auto-generated. Do not edit!


(when (boundp 'quad_msgs::ContactMode)
  (if (not (find-package "QUAD_MSGS"))
    (make-package "QUAD_MSGS"))
  (shadow 'ContactMode (find-package "QUAD_MSGS")))
(unless (find-package "QUAD_MSGS::CONTACTMODE")
  (make-package "QUAD_MSGS::CONTACTMODE"))

(in-package "ROS")
;;//! \htmlinclude ContactMode.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass quad_msgs::ContactMode
  :super ros::object
  :slots (_header _leg_contacts ))

(defmethod quad_msgs::ContactMode
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:leg_contacts __leg_contacts) ())
    )
   (send-super :init)
   (setq _header __header)
   (setq _leg_contacts __leg_contacts)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:leg_contacts
   (&rest __leg_contacts)
   (if (keywordp (car __leg_contacts))
       (send* _leg_contacts __leg_contacts)
     (progn
       (if __leg_contacts (setq _leg_contacts (car __leg_contacts)))
       _leg_contacts)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; quad_msgs/LegContactMode[] _leg_contacts
    (apply #'+ (send-all _leg_contacts :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; quad_msgs/LegContactMode[] _leg_contacts
     (write-long (length _leg_contacts) s)
     (dolist (elem _leg_contacts)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; quad_msgs/LegContactMode[] _leg_contacts
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _leg_contacts (let (r) (dotimes (i n) (push (instance quad_msgs::LegContactMode :init) r)) r))
     (dolist (elem- _leg_contacts)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get quad_msgs::ContactMode :md5sum-) "26ebde1d6ad14a11545e27eb1d085e28")
(setf (get quad_msgs::ContactMode :datatype-) "quad_msgs/ContactMode")
(setf (get quad_msgs::ContactMode :definition-)
      "# This is a message to hold contact states of the robot
Header header

LegContactMode[] leg_contacts # FL Bl FR BR

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
MSG: quad_msgs/LegContactMode
# This is a message to hold contact mode of one leg
Header header

float32 contact_prob
bool contact_state
geometry_msgs/Vector3 contact_forces #fx,fy,fz

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



(provide :quad_msgs/ContactMode "26ebde1d6ad14a11545e27eb1d085e28")


