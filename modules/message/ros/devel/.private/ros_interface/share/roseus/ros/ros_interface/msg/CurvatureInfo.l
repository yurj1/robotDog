;; Auto-generated. Do not edit!


(when (boundp 'ros_interface::CurvatureInfo)
  (if (not (find-package "ROS_INTERFACE"))
    (make-package "ROS_INTERFACE"))
  (shadow 'CurvatureInfo (find-package "ROS_INTERFACE")))
(unless (find-package "ROS_INTERFACE::CURVATUREINFO")
  (make-package "ROS_INTERFACE::CURVATUREINFO"))

(in-package "ROS")
;;//! \htmlinclude CurvatureInfo.msg.html


(defclass ros_interface::CurvatureInfo
  :super ros::object
  :slots (_offset _value ))

(defmethod ros_interface::CurvatureInfo
  (:init
   (&key
    ((:offset __offset) 0.0)
    ((:value __value) 0.0)
    )
   (send-super :init)
   (setq _offset (float __offset))
   (setq _value (float __value))
   self)
  (:offset
   (&optional __offset)
   (if __offset (setq _offset __offset)) _offset)
  (:value
   (&optional __value)
   (if __value (setq _value __value)) _value)
  (:serialization-length
   ()
   (+
    ;; float64 _offset
    8
    ;; float64 _value
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _offset
       (sys::poke _offset (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _value
       (sys::poke _value (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _offset
     (setq _offset (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _value
     (setq _value (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get ros_interface::CurvatureInfo :md5sum-) "3fa4f475bde56d903dde34d20c370fb9")
(setf (get ros_interface::CurvatureInfo :datatype-) "ros_interface/CurvatureInfo")
(setf (get ros_interface::CurvatureInfo :definition-)
      "float64   offset     # 道路中心线上点位于该道路的位置（与道路起点的距离）
float64   value     # 道路中心线上点的曲率值

")



(provide :ros_interface/CurvatureInfo "3fa4f475bde56d903dde34d20c370fb9")


