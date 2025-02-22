;; Auto-generated. Do not edit!


(when (boundp 'ros_interface::FreeSpace)
  (if (not (find-package "ROS_INTERFACE"))
    (make-package "ROS_INTERFACE"))
  (shadow 'FreeSpace (find-package "ROS_INTERFACE")))
(unless (find-package "ROS_INTERFACE::FREESPACE")
  (make-package "ROS_INTERFACE::FREESPACE"))

(in-package "ROS")
;;//! \htmlinclude FreeSpace.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass ros_interface::FreeSpace
  :super ros::object
  :slots (_header _sensor_id _freespace_region _error_code _is_valid ))

(defmethod ros_interface::FreeSpace
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:sensor_id __sensor_id) 0)
    ((:freespace_region __freespace_region) ())
    ((:error_code __error_code) 0)
    ((:is_valid __is_valid) nil)
    )
   (send-super :init)
   (setq _header __header)
   (setq _sensor_id (round __sensor_id))
   (setq _freespace_region __freespace_region)
   (setq _error_code (round __error_code))
   (setq _is_valid __is_valid)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:sensor_id
   (&optional __sensor_id)
   (if __sensor_id (setq _sensor_id __sensor_id)) _sensor_id)
  (:freespace_region
   (&rest __freespace_region)
   (if (keywordp (car __freespace_region))
       (send* _freespace_region __freespace_region)
     (progn
       (if __freespace_region (setq _freespace_region (car __freespace_region)))
       _freespace_region)))
  (:error_code
   (&optional __error_code)
   (if __error_code (setq _error_code __error_code)) _error_code)
  (:is_valid
   (&optional (__is_valid :null))
   (if (not (eq __is_valid :null)) (setq _is_valid __is_valid)) _is_valid)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int32 _sensor_id
    4
    ;; ros_interface/Polygon2D[] _freespace_region
    (apply #'+ (send-all _freespace_region :serialization-length)) 4
    ;; int32 _error_code
    4
    ;; bool _is_valid
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int32 _sensor_id
       (write-long _sensor_id s)
     ;; ros_interface/Polygon2D[] _freespace_region
     (write-long (length _freespace_region) s)
     (dolist (elem _freespace_region)
       (send elem :serialize s)
       )
     ;; int32 _error_code
       (write-long _error_code s)
     ;; bool _is_valid
       (if _is_valid (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int32 _sensor_id
     (setq _sensor_id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; ros_interface/Polygon2D[] _freespace_region
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _freespace_region (let (r) (dotimes (i n) (push (instance ros_interface::Polygon2D :init) r)) r))
     (dolist (elem- _freespace_region)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;; int32 _error_code
     (setq _error_code (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; bool _is_valid
     (setq _is_valid (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get ros_interface::FreeSpace :md5sum-) "86e4a72c19135f501d4833fae261dd9b")
(setf (get ros_interface::FreeSpace :datatype-) "ros_interface/FreeSpace")
(setf (get ros_interface::FreeSpace :definition-)
      "Header   header     # timestamp is included in header
int32   sensor_id     # 安装的传感器id(camera,lidar,radar) ' 相机id: 0-front_center相机 1-front_left相机 2-front_right相机 3-left_front相机 4-left_back右后相机 5-right_front相机 6-right_back相机 7-back相机'  8-相机融合
Polygon2D[] freespace_region # freespace轮廓图像坐标
int32   error_code     # 错误码（default = OK）
bool   is_valid     # 障碍物数据是否合法

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
MSG: ros_interface/Polygon2D
int32   coordinate_system     # 坐标系
Point2D[] points # 二维点集

================================================================================
MSG: ros_interface/Point2D
float64   x     # 位置坐标x
float64   y     # 位置坐标y

")



(provide :ros_interface/FreeSpace "86e4a72c19135f501d4833fae261dd9b")


