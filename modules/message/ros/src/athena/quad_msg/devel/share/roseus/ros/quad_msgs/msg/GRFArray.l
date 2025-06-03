;; Auto-generated. Do not edit!


(when (boundp 'quad_msgs::GRFArray)
  (if (not (find-package "QUAD_MSGS"))
    (make-package "QUAD_MSGS"))
  (shadow 'GRFArray (find-package "QUAD_MSGS")))
(unless (find-package "QUAD_MSGS::GRFARRAY")
  (make-package "QUAD_MSGS::GRFARRAY"))

(in-package "ROS")
;;//! \htmlinclude GRFArray.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass quad_msgs::GRFArray
  :super ros::object
  :slots (_header _vectors _points _contact_states _traj_index ))

(defmethod quad_msgs::GRFArray
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:vectors __vectors) ())
    ((:points __points) ())
    ((:contact_states __contact_states) (let (r) (dotimes (i 0) (push nil r)) r))
    ((:traj_index __traj_index) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _vectors __vectors)
   (setq _points __points)
   (setq _contact_states __contact_states)
   (setq _traj_index (round __traj_index))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:vectors
   (&rest __vectors)
   (if (keywordp (car __vectors))
       (send* _vectors __vectors)
     (progn
       (if __vectors (setq _vectors (car __vectors)))
       _vectors)))
  (:points
   (&rest __points)
   (if (keywordp (car __points))
       (send* _points __points)
     (progn
       (if __points (setq _points (car __points)))
       _points)))
  (:contact_states
   (&optional __contact_states)
   (if __contact_states (setq _contact_states __contact_states)) _contact_states)
  (:traj_index
   (&optional __traj_index)
   (if __traj_index (setq _traj_index __traj_index)) _traj_index)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; geometry_msgs/Vector3[] _vectors
    (apply #'+ (send-all _vectors :serialization-length)) 4
    ;; geometry_msgs/Point[] _points
    (apply #'+ (send-all _points :serialization-length)) 4
    ;; bool[] _contact_states
    (* 1    (length _contact_states)) 4
    ;; uint32 _traj_index
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; geometry_msgs/Vector3[] _vectors
     (write-long (length _vectors) s)
     (dolist (elem _vectors)
       (send elem :serialize s)
       )
     ;; geometry_msgs/Point[] _points
     (write-long (length _points) s)
     (dolist (elem _points)
       (send elem :serialize s)
       )
     ;; bool[] _contact_states
     (write-long (length _contact_states) s)
     (dotimes (i (length _contact_states))
       (if (elt _contact_states i) (write-byte -1 s) (write-byte 0 s))
       )
     ;; uint32 _traj_index
       (write-long _traj_index s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; geometry_msgs/Vector3[] _vectors
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _vectors (let (r) (dotimes (i n) (push (instance geometry_msgs::Vector3 :init) r)) r))
     (dolist (elem- _vectors)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; geometry_msgs/Point[] _points
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _points (let (r) (dotimes (i n) (push (instance geometry_msgs::Point :init) r)) r))
     (dolist (elem- _points)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; bool[] _contact_states
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _contact_states (make-list n))
     (dotimes (i n)
     (setf (elt _contact_states i) (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
     ))
   ;; uint32 _traj_index
     (setq _traj_index (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get quad_msgs::GRFArray :md5sum-) "e3a7d93ab37eb491eee31b8dde628447")
(setf (get quad_msgs::GRFArray :datatype-) "quad_msgs/GRFArray")
(setf (get quad_msgs::GRFArray :definition-)
      "# This is a message to hold an array of ground reaction forces and their points of application
#
# Accurate timing information is stored in the header.

Header header
geometry_msgs/Vector3[] vectors
geometry_msgs/Point[] points
bool[] contact_states
uint32 traj_index
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
================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

")



(provide :quad_msgs/GRFArray "e3a7d93ab37eb491eee31b8dde628447")


