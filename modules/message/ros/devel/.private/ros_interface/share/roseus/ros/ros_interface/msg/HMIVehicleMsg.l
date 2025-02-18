;; Auto-generated. Do not edit!


(when (boundp 'ros_interface::HMIVehicleMsg)
  (if (not (find-package "ROS_INTERFACE"))
    (make-package "ROS_INTERFACE"))
  (shadow 'HMIVehicleMsg (find-package "ROS_INTERFACE")))
(unless (find-package "ROS_INTERFACE::HMIVEHICLEMSG")
  (make-package "ROS_INTERFACE::HMIVEHICLEMSG"))

(in-package "ROS")
;;//! \htmlinclude HMIVehicleMsg.msg.html
(if (not (find-package "STD_MSGS"))
  (ros::roseus-add-msgs "std_msgs"))


(defclass ros_interface::HMIVehicleMsg
  :super ros::object
  :slots (_header _driving_mode _gear_location _steering_value _accel_value _brake_value _speed_mps _position _utm_position _pitch _roll _heading _rtk_flag _origin_lat _origin_lon _current_ins_yaw _auto_safe _battery_power_percentage _charging_gun_status _chassis_error_code _brake_lamp_status _turn_lamp_status _mercator_position ))

(defmethod ros_interface::HMIVehicleMsg
  (:init
   (&key
    ((:header __header) (instance std_msgs::Header :init))
    ((:driving_mode __driving_mode) 0)
    ((:gear_location __gear_location) 0)
    ((:steering_value __steering_value) 0.0)
    ((:accel_value __accel_value) 0.0)
    ((:brake_value __brake_value) 0.0)
    ((:speed_mps __speed_mps) 0.0)
    ((:position __position) (instance ros_interface::PointLLH :init))
    ((:utm_position __utm_position) (instance ros_interface::PointENU :init))
    ((:pitch __pitch) 0.0)
    ((:roll __roll) 0.0)
    ((:heading __heading) 0.0)
    ((:rtk_flag __rtk_flag) 0)
    ((:origin_lat __origin_lat) 0.0)
    ((:origin_lon __origin_lon) 0.0)
    ((:current_ins_yaw __current_ins_yaw) 0.0)
    ((:auto_safe __auto_safe) 0)
    ((:battery_power_percentage __battery_power_percentage) 0.0)
    ((:charging_gun_status __charging_gun_status) 0)
    ((:chassis_error_code __chassis_error_code) (make-array 0 :initial-element 0 :element-type :integer))
    ((:brake_lamp_status __brake_lamp_status) 0)
    ((:turn_lamp_status __turn_lamp_status) 0)
    ((:mercator_position __mercator_position) (instance ros_interface::PointENU :init))
    )
   (send-super :init)
   (setq _header __header)
   (setq _driving_mode (round __driving_mode))
   (setq _gear_location (round __gear_location))
   (setq _steering_value (float __steering_value))
   (setq _accel_value (float __accel_value))
   (setq _brake_value (float __brake_value))
   (setq _speed_mps (float __speed_mps))
   (setq _position __position)
   (setq _utm_position __utm_position)
   (setq _pitch (float __pitch))
   (setq _roll (float __roll))
   (setq _heading (float __heading))
   (setq _rtk_flag (round __rtk_flag))
   (setq _origin_lat (float __origin_lat))
   (setq _origin_lon (float __origin_lon))
   (setq _current_ins_yaw (float __current_ins_yaw))
   (setq _auto_safe (round __auto_safe))
   (setq _battery_power_percentage (float __battery_power_percentage))
   (setq _charging_gun_status (round __charging_gun_status))
   (setq _chassis_error_code __chassis_error_code)
   (setq _brake_lamp_status (round __brake_lamp_status))
   (setq _turn_lamp_status (round __turn_lamp_status))
   (setq _mercator_position __mercator_position)
   self)
  (:header
   (&rest __header)
   (if (keywordp (car __header))
       (send* _header __header)
     (progn
       (if __header (setq _header (car __header)))
       _header)))
  (:driving_mode
   (&optional __driving_mode)
   (if __driving_mode (setq _driving_mode __driving_mode)) _driving_mode)
  (:gear_location
   (&optional __gear_location)
   (if __gear_location (setq _gear_location __gear_location)) _gear_location)
  (:steering_value
   (&optional __steering_value)
   (if __steering_value (setq _steering_value __steering_value)) _steering_value)
  (:accel_value
   (&optional __accel_value)
   (if __accel_value (setq _accel_value __accel_value)) _accel_value)
  (:brake_value
   (&optional __brake_value)
   (if __brake_value (setq _brake_value __brake_value)) _brake_value)
  (:speed_mps
   (&optional __speed_mps)
   (if __speed_mps (setq _speed_mps __speed_mps)) _speed_mps)
  (:position
   (&rest __position)
   (if (keywordp (car __position))
       (send* _position __position)
     (progn
       (if __position (setq _position (car __position)))
       _position)))
  (:utm_position
   (&rest __utm_position)
   (if (keywordp (car __utm_position))
       (send* _utm_position __utm_position)
     (progn
       (if __utm_position (setq _utm_position (car __utm_position)))
       _utm_position)))
  (:pitch
   (&optional __pitch)
   (if __pitch (setq _pitch __pitch)) _pitch)
  (:roll
   (&optional __roll)
   (if __roll (setq _roll __roll)) _roll)
  (:heading
   (&optional __heading)
   (if __heading (setq _heading __heading)) _heading)
  (:rtk_flag
   (&optional __rtk_flag)
   (if __rtk_flag (setq _rtk_flag __rtk_flag)) _rtk_flag)
  (:origin_lat
   (&optional __origin_lat)
   (if __origin_lat (setq _origin_lat __origin_lat)) _origin_lat)
  (:origin_lon
   (&optional __origin_lon)
   (if __origin_lon (setq _origin_lon __origin_lon)) _origin_lon)
  (:current_ins_yaw
   (&optional __current_ins_yaw)
   (if __current_ins_yaw (setq _current_ins_yaw __current_ins_yaw)) _current_ins_yaw)
  (:auto_safe
   (&optional __auto_safe)
   (if __auto_safe (setq _auto_safe __auto_safe)) _auto_safe)
  (:battery_power_percentage
   (&optional __battery_power_percentage)
   (if __battery_power_percentage (setq _battery_power_percentage __battery_power_percentage)) _battery_power_percentage)
  (:charging_gun_status
   (&optional __charging_gun_status)
   (if __charging_gun_status (setq _charging_gun_status __charging_gun_status)) _charging_gun_status)
  (:chassis_error_code
   (&optional __chassis_error_code)
   (if __chassis_error_code (setq _chassis_error_code __chassis_error_code)) _chassis_error_code)
  (:brake_lamp_status
   (&optional __brake_lamp_status)
   (if __brake_lamp_status (setq _brake_lamp_status __brake_lamp_status)) _brake_lamp_status)
  (:turn_lamp_status
   (&optional __turn_lamp_status)
   (if __turn_lamp_status (setq _turn_lamp_status __turn_lamp_status)) _turn_lamp_status)
  (:mercator_position
   (&rest __mercator_position)
   (if (keywordp (car __mercator_position))
       (send* _mercator_position __mercator_position)
     (progn
       (if __mercator_position (setq _mercator_position (car __mercator_position)))
       _mercator_position)))
  (:serialization-length
   ()
   (+
    ;; std_msgs/Header _header
    (send _header :serialization-length)
    ;; int32 _driving_mode
    4
    ;; int32 _gear_location
    4
    ;; float64 _steering_value
    8
    ;; float64 _accel_value
    8
    ;; float64 _brake_value
    8
    ;; float64 _speed_mps
    8
    ;; ros_interface/PointLLH _position
    (send _position :serialization-length)
    ;; ros_interface/PointENU _utm_position
    (send _utm_position :serialization-length)
    ;; float64 _pitch
    8
    ;; float64 _roll
    8
    ;; float64 _heading
    8
    ;; int32 _rtk_flag
    4
    ;; float64 _origin_lat
    8
    ;; float64 _origin_lon
    8
    ;; float64 _current_ins_yaw
    8
    ;; int32 _auto_safe
    4
    ;; float64 _battery_power_percentage
    8
    ;; int32 _charging_gun_status
    4
    ;; int32[] _chassis_error_code
    (* 4    (length _chassis_error_code)) 4
    ;; int32 _brake_lamp_status
    4
    ;; int32 _turn_lamp_status
    4
    ;; ros_interface/PointENU _mercator_position
    (send _mercator_position :serialization-length)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; std_msgs/Header _header
       (send _header :serialize s)
     ;; int32 _driving_mode
       (write-long _driving_mode s)
     ;; int32 _gear_location
       (write-long _gear_location s)
     ;; float64 _steering_value
       (sys::poke _steering_value (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _accel_value
       (sys::poke _accel_value (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _brake_value
       (sys::poke _brake_value (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _speed_mps
       (sys::poke _speed_mps (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; ros_interface/PointLLH _position
       (send _position :serialize s)
     ;; ros_interface/PointENU _utm_position
       (send _utm_position :serialize s)
     ;; float64 _pitch
       (sys::poke _pitch (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _roll
       (sys::poke _roll (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _heading
       (sys::poke _heading (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int32 _rtk_flag
       (write-long _rtk_flag s)
     ;; float64 _origin_lat
       (sys::poke _origin_lat (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _origin_lon
       (sys::poke _origin_lon (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _current_ins_yaw
       (sys::poke _current_ins_yaw (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int32 _auto_safe
       (write-long _auto_safe s)
     ;; float64 _battery_power_percentage
       (sys::poke _battery_power_percentage (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int32 _charging_gun_status
       (write-long _charging_gun_status s)
     ;; int32[] _chassis_error_code
     (write-long (length _chassis_error_code) s)
     (dotimes (i (length _chassis_error_code))
       (write-long (elt _chassis_error_code i) s)
       )
     ;; int32 _brake_lamp_status
       (write-long _brake_lamp_status s)
     ;; int32 _turn_lamp_status
       (write-long _turn_lamp_status s)
     ;; ros_interface/PointENU _mercator_position
       (send _mercator_position :serialize s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; std_msgs/Header _header
     (send _header :deserialize buf ptr-) (incf ptr- (send _header :serialization-length))
   ;; int32 _driving_mode
     (setq _driving_mode (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _gear_location
     (setq _gear_location (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _steering_value
     (setq _steering_value (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _accel_value
     (setq _accel_value (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _brake_value
     (setq _brake_value (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _speed_mps
     (setq _speed_mps (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; ros_interface/PointLLH _position
     (send _position :deserialize buf ptr-) (incf ptr- (send _position :serialization-length))
   ;; ros_interface/PointENU _utm_position
     (send _utm_position :deserialize buf ptr-) (incf ptr- (send _utm_position :serialization-length))
   ;; float64 _pitch
     (setq _pitch (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _roll
     (setq _roll (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _heading
     (setq _heading (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int32 _rtk_flag
     (setq _rtk_flag (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _origin_lat
     (setq _origin_lat (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _origin_lon
     (setq _origin_lon (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _current_ins_yaw
     (setq _current_ins_yaw (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int32 _auto_safe
     (setq _auto_safe (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _battery_power_percentage
     (setq _battery_power_percentage (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int32 _charging_gun_status
     (setq _charging_gun_status (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32[] _chassis_error_code
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _chassis_error_code (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _chassis_error_code i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; int32 _brake_lamp_status
     (setq _brake_lamp_status (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _turn_lamp_status
     (setq _turn_lamp_status (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; ros_interface/PointENU _mercator_position
     (send _mercator_position :deserialize buf ptr-) (incf ptr- (send _mercator_position :serialization-length))
   ;;
   self)
  )

(setf (get ros_interface::HMIVehicleMsg :md5sum-) "406f4c0f16a35ecb30b22550fabf5c9f")
(setf (get ros_interface::HMIVehicleMsg :datatype-) "ros_interface/HMIVehicleMsg")
(setf (get ros_interface::HMIVehicleMsg :definition-)
      "Header   header     #  
int32   driving_mode     # 驾驶状态
int32   gear_location     # 档位值
float64   steering_value     # 方向盘转角
float64   accel_value     # 线控驱动值（油门值）
float64   brake_value     # 线控制动值（刹车值）
float64   speed_mps     # 车速（m/s）
PointLLH   position     # 经纬度高程
PointENU   utm_position     # 相对参考点xyz坐标
float64   pitch     # 方向(单位弧度，-π～π,正东:0, 逆时针。都满足右手定则)
float64   roll     #  
float64   heading     #  
int32   rtk_flag     # RTK标志值
float64   origin_lat     # // 参考点纬度 GCJ-02格式
float64   origin_lon     # // 参考点经度 GCJ-02格式
float64   current_ins_yaw     #  
int32   auto_safe     # //  安全驾驶0:正常 1:左前车门没关 2:右前车门没关 3:左后车门没关 4:右后车门没关 5:未系安全带 6: 未打开反观镜 7:车辆未静止
float64   battery_power_percentage     # 电池电量值
int32   charging_gun_status     # 充电枪状态
int32[] chassis_error_code # 底盘错误码
int32   brake_lamp_status     # 刹车灯状态
int32   turn_lamp_status     # 转向灯状态
PointENU   mercator_position     # 转坐标系后的参考点

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
MSG: ros_interface/PointLLH
float64   lon     # Longitude in degrees, ranging from -180 to 180.
float64   lat     # Latitude in degrees, ranging from -90 to 90.
float64   height     # WGS-84 ellipsoid height in meters.

================================================================================
MSG: ros_interface/PointENU
float64   x     # East from the origin, in meters.
float64   y     # North from the origin, in meters.
float64   z     # Up from the WGS-84 ellipsoid, in meters.

")



(provide :ros_interface/HMIVehicleMsg "406f4c0f16a35ecb30b22550fabf5c9f")


