;; Auto-generated. Do not edit!


(when (boundp 'perception_msgs::DogState)
  (if (not (find-package "PERCEPTION_MSGS"))
    (make-package "PERCEPTION_MSGS"))
  (shadow 'DogState (find-package "PERCEPTION_MSGS")))
(unless (find-package "PERCEPTION_MSGS::DOGSTATE")
  (make-package "PERCEPTION_MSGS::DOGSTATE"))

(in-package "ROS")
;;//! \htmlinclude DogState.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass perception_msgs::DogState
  :super ros::object
  :slots (_battery _chargingState _gesture _speed _person_state _target_position _alarmInfo ))

(defmethod perception_msgs::DogState
  (:init
   (&key
    ((:battery __battery) 0.0)
    ((:chargingState __chargingState) 0)
    ((:gesture __gesture) 0)
    ((:speed __speed) 0.0)
    ((:person_state __person_state) 0)
    ((:target_position __target_position) (instance geometry_msgs::Pose :init))
    ((:alarmInfo __alarmInfo) ())
    )
   (send-super :init)
   (setq _battery (float __battery))
   (setq _chargingState (round __chargingState))
   (setq _gesture (round __gesture))
   (setq _speed (float __speed))
   (setq _person_state (round __person_state))
   (setq _target_position __target_position)
   (setq _alarmInfo __alarmInfo)
   self)
  (:battery
   (&optional __battery)
   (if __battery (setq _battery __battery)) _battery)
  (:chargingState
   (&optional __chargingState)
   (if __chargingState (setq _chargingState __chargingState)) _chargingState)
  (:gesture
   (&optional __gesture)
   (if __gesture (setq _gesture __gesture)) _gesture)
  (:speed
   (&optional __speed)
   (if __speed (setq _speed __speed)) _speed)
  (:person_state
   (&optional __person_state)
   (if __person_state (setq _person_state __person_state)) _person_state)
  (:target_position
   (&rest __target_position)
   (if (keywordp (car __target_position))
       (send* _target_position __target_position)
     (progn
       (if __target_position (setq _target_position (car __target_position)))
       _target_position)))
  (:alarmInfo
   (&rest __alarmInfo)
   (if (keywordp (car __alarmInfo))
       (send* _alarmInfo __alarmInfo)
     (progn
       (if __alarmInfo (setq _alarmInfo (car __alarmInfo)))
       _alarmInfo)))
  (:serialization-length
   ()
   (+
    ;; float64 _battery
    8
    ;; uint8 _chargingState
    1
    ;; uint8 _gesture
    1
    ;; float64 _speed
    8
    ;; uint8 _person_state
    1
    ;; geometry_msgs/Pose _target_position
    (send _target_position :serialization-length)
    ;; perception_msgs/AlarmEntry[] _alarmInfo
    (apply #'+ (send-all _alarmInfo :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _battery
       (sys::poke _battery (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; uint8 _chargingState
       (write-byte _chargingState s)
     ;; uint8 _gesture
       (write-byte _gesture s)
     ;; float64 _speed
       (sys::poke _speed (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; uint8 _person_state
       (write-byte _person_state s)
     ;; geometry_msgs/Pose _target_position
       (send _target_position :serialize s)
     ;; perception_msgs/AlarmEntry[] _alarmInfo
     (write-long (length _alarmInfo) s)
     (dolist (elem _alarmInfo)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _battery
     (setq _battery (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; uint8 _chargingState
     (setq _chargingState (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _gesture
     (setq _gesture (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; float64 _speed
     (setq _speed (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; uint8 _person_state
     (setq _person_state (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; geometry_msgs/Pose _target_position
     (send _target_position :deserialize buf ptr-) (incf ptr- (send _target_position :serialization-length))
   ;; perception_msgs/AlarmEntry[] _alarmInfo
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _alarmInfo (let (r) (dotimes (i n) (push (instance perception_msgs::AlarmEntry :init) r)) r))
     (dolist (elem- _alarmInfo)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get perception_msgs::DogState :md5sum-) "37a76525c34080656fe716b1e4427824")
(setf (get perception_msgs::DogState :datatype-) "perception_msgs/DogState")
(setf (get perception_msgs::DogState :definition-)
      "# 电量
float64 battery
#充电状态   0：空闲 1: 准备充电 2：充电中 
uint8 chargingState
#手势
uint8 gesture
#速度 
float64 speed
#主人识别状态
uint8 person_state
# 目标点
geometry_msgs/Pose target_position
#报警信息
AlarmEntry[] alarmInfo
#动作信息
#ActionEntry[] actions

================================================================================
MSG: geometry_msgs/Pose
# A representation of pose in free space, composed of position and orientation. 
Point position
Quaternion orientation

================================================================================
MSG: geometry_msgs/Point
# This contains the position of a point in free space
float64 x
float64 y
float64 z

================================================================================
MSG: geometry_msgs/Quaternion
# This represents an orientation in free space in quaternion form.

float64 x
float64 y
float64 z
float64 w

================================================================================
MSG: perception_msgs/AlarmEntry
int32  id
int32  source
int32  level
int32  status
string message
")



(provide :perception_msgs/DogState "37a76525c34080656fe716b1e4427824")


