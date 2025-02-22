;; Auto-generated. Do not edit!


(when (boundp 'ros_interface::VehicleMotion)
  (if (not (find-package "ROS_INTERFACE"))
    (make-package "ROS_INTERFACE"))
  (shadow 'VehicleMotion (find-package "ROS_INTERFACE")))
(unless (find-package "ROS_INTERFACE::VEHICLEMOTION")
  (make-package "ROS_INTERFACE::VEHICLEMOTION"))

(in-package "ROS")
;;//! \htmlinclude VehicleMotion.msg.html


(defclass ros_interface::VehicleMotion
  :super ros::object
  :slots (_name _vehicle_motion_point ))

(defmethod ros_interface::VehicleMotion
  (:init
   (&key
    ((:name __name) "")
    ((:vehicle_motion_point __vehicle_motion_point) ())
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _vehicle_motion_point __vehicle_motion_point)
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:vehicle_motion_point
   (&rest __vehicle_motion_point)
   (if (keywordp (car __vehicle_motion_point))
       (send* _vehicle_motion_point __vehicle_motion_point)
     (progn
       (if __vehicle_motion_point (setq _vehicle_motion_point (car __vehicle_motion_point)))
       _vehicle_motion_point)))
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; ros_interface/VehicleMotionPoint[] _vehicle_motion_point
    (apply #'+ (send-all _vehicle_motion_point :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; ros_interface/VehicleMotionPoint[] _vehicle_motion_point
     (write-long (length _vehicle_motion_point) s)
     (dolist (elem _vehicle_motion_point)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; ros_interface/VehicleMotionPoint[] _vehicle_motion_point
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _vehicle_motion_point (let (r) (dotimes (i n) (push (instance ros_interface::VehicleMotionPoint :init) r)) r))
     (dolist (elem- _vehicle_motion_point)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get ros_interface::VehicleMotion :md5sum-) "7c74308fe22ff4f1bcd4e63067f250c9")
(setf (get ros_interface::VehicleMotion :datatype-) "ros_interface/VehicleMotion")
(setf (get ros_interface::VehicleMotion :definition-)
      "string   name     # 名称
VehicleMotionPoint[] vehicle_motion_point #  

================================================================================
MSG: ros_interface/VehicleMotionPoint
TrajectoryPoint   trajectory_point     # trajectory point
float64   steer     # The angle between vehicle front wheel and vehicle longitudinal axis

================================================================================
MSG: ros_interface/TrajectoryPoint
PathPoint   path_point     # path point
float64   v     # linear velocity
float64   a     # linear acceleration
float64   relative_time     # relative time from beginning of the trajectory
float64   da     # longitudinal jerk
bool   is_steer_valid     # 转向是否有效
float64   front_steer     # The angle between vehicle front wheel and vehicle longitudinal axis
float64   rear_steer     # 后轮转角
int32   gear     # 档位

================================================================================
MSG: ros_interface/PathPoint
float64   x     # coordinates x
float64   y     # coordinates y
float64   z     # coordinates z
float64   theta     # direction on the x-y plane
float64   kappa     # curvature on the x-y planning
float64   s     # accumulated distance from beginning of the path
float64   dkappa     # derivative of kappa w.r.t s.
float64   ddkappa     # derivative of derivative of kappa w.r.t s.
float64   lane_id     # The lane ID where the path point is on
float64   x_derivative     # derivative of x w.r.t parametric parameter t in CosThetareferenceline
float64   y_derivative     # derivative of y w.r.t parametric parameter t in CosThetareferenceline

")



(provide :ros_interface/VehicleMotion "7c74308fe22ff4f1bcd4e63067f250c9")


