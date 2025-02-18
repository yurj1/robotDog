;; Auto-generated. Do not edit!


(when (boundp 'ros_interface::GuideInfo)
  (if (not (find-package "ROS_INTERFACE"))
    (make-package "ROS_INTERFACE"))
  (shadow 'GuideInfo (find-package "ROS_INTERFACE")))
(unless (find-package "ROS_INTERFACE::GUIDEINFO")
  (make-package "ROS_INTERFACE::GUIDEINFO"))

(in-package "ROS")
;;//! \htmlinclude GuideInfo.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass ros_interface::GuideInfo
  :super ros::object
  :slots (_header _next_dis _current_road _next_road _round_status _intersection_status _roads_status ))

(defmethod ros_interface::GuideInfo
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:next_dis __next_dis) 0.0)
    ((:current_road __current_road) (instance ros_interface::GuideRoad :init))
    ((:next_road __next_road) (instance ros_interface::GuideRoad :init))
    ((:round_status __round_status) 0)
    ((:intersection_status __intersection_status) 0)
    ((:roads_status __roads_status) 0)
    )
   (send-super :init)
   (setq _header __header)
   (setq _next_dis (float __next_dis))
   (setq _current_road __current_road)
   (setq _next_road __next_road)
   (setq _round_status (round __round_status))
   (setq _intersection_status (round __intersection_status))
   (setq _roads_status (round __roads_status))
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:next_dis
   (&optional __next_dis)
   (if __next_dis (setq _next_dis __next_dis)) _next_dis)
  (:current_road
   (&rest __current_road)
   (if (keywordp (car __current_road))
       (send* _current_road __current_road)
     (progn
       (if __current_road (setq _current_road (car __current_road)))
       _current_road)))
  (:next_road
   (&rest __next_road)
   (if (keywordp (car __next_road))
       (send* _next_road __next_road)
     (progn
       (if __next_road (setq _next_road (car __next_road)))
       _next_road)))
  (:round_status
   (&optional __round_status)
   (if __round_status (setq _round_status __round_status)) _round_status)
  (:intersection_status
   (&optional __intersection_status)
   (if __intersection_status (setq _intersection_status __intersection_status)) _intersection_status)
  (:roads_status
   (&optional __roads_status)
   (if __roads_status (setq _roads_status __roads_status)) _roads_status)
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; float64 _next_dis
    8
    ;; ros_interface/GuideRoad _current_road
    (send _current_road :serialization-length)
    ;; ros_interface/GuideRoad _next_road
    (send _next_road :serialization-length)
    ;; int8 _round_status
    1
    ;; int8 _intersection_status
    1
    ;; int8 _roads_status
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; float64 _next_dis
       (sys::poke _next_dis (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; ros_interface/GuideRoad _current_road
       (send _current_road :serialize s)
     ;; ros_interface/GuideRoad _next_road
       (send _next_road :serialize s)
     ;; int8 _round_status
       (write-byte _round_status s)
     ;; int8 _intersection_status
       (write-byte _intersection_status s)
     ;; int8 _roads_status
       (write-byte _roads_status s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; float64 _next_dis
     (setq _next_dis (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; ros_interface/GuideRoad _current_road
     (send _current_road :deserialize buf ptr-) (incf ptr- (send _current_road :serialization-length))
   ;; ros_interface/GuideRoad _next_road
     (send _next_road :deserialize buf ptr-) (incf ptr- (send _next_road :serialization-length))
   ;; int8 _round_status
     (setq _round_status (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _round_status 127) (setq _round_status (- _round_status 256)))
   ;; int8 _intersection_status
     (setq _intersection_status (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _intersection_status 127) (setq _intersection_status (- _intersection_status 256)))
   ;; int8 _roads_status
     (setq _roads_status (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _roads_status 127) (setq _roads_status (- _roads_status 256)))
   ;;
   self)
  )

(setf (get ros_interface::GuideInfo :md5sum-) "aa74d1653e11a6cb191e3ce919a1654f")
(setf (get ros_interface::GuideInfo :datatype-) "ros_interface/GuideInfo")
(setf (get ros_interface::GuideInfo :definition-)
      "Header   header     # 头部信息
float64   next_dis     # 下一条规划路线上道路的距离
GuideRoad   current_road     # 当前道路的引导信息
GuideRoad   next_road     # 下一条规划道路的引导信息
int8   round_status     # 环岛状态: 0：未知或非环岛状态 1：当前为非环岛道路并且规划路线即将驶入环岛主路 2：当前道路类型是环岛并且规划路线还是在环岛主路中行驶 3：当前道路类型是环岛并且规划路线即将驶出环岛主路
int8   intersection_status     # 交叉路口状态: 0：未知 1：非交叉路口状态 2：交叉路口通行状态
int8   roads_status     # 主辅路状态： 0：未知或非主辅路状态 1：当前道路类型是辅路下一条道路类型是主路  2：当前道路类型是主路下一条道路类型是辅路

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
MSG: ros_interface/GuideRoad
int64   road_id     # 道路的id
int8   road_type     # 道路的类型: 0：未知或一般道路  1：环岛 2：交叉路口 3：主路 4：辅路
int8   turn_type     # 规划路线上道路的转向信息 1：左转 2：直行 3：右转
float64   avg_curvature     # 道路的平均曲率
int32   curvature_size     # 道路中心线上点(曲率)数量
CurvatureInfo[] curvature # 道路曲率信息数组

================================================================================
MSG: ros_interface/CurvatureInfo
float64   offset     # 道路中心线上点位于该道路的位置（与道路起点的距离）
float64   value     # 道路中心线上点的曲率值

")



(provide :ros_interface/GuideInfo "aa74d1653e11a6cb191e3ce919a1654f")


