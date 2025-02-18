;; Auto-generated. Do not edit!


(when (boundp 'ros_interface::GuideRoad)
  (if (not (find-package "ROS_INTERFACE"))
    (make-package "ROS_INTERFACE"))
  (shadow 'GuideRoad (find-package "ROS_INTERFACE")))
(unless (find-package "ROS_INTERFACE::GUIDEROAD")
  (make-package "ROS_INTERFACE::GUIDEROAD"))

(in-package "ROS")
;;//! \htmlinclude GuideRoad.msg.html


(defclass ros_interface::GuideRoad
  :super ros::object
  :slots (_road_id _road_type _turn_type _avg_curvature _curvature_size _curvature ))

(defmethod ros_interface::GuideRoad
  (:init
   (&key
    ((:road_id __road_id) 0)
    ((:road_type __road_type) 0)
    ((:turn_type __turn_type) 0)
    ((:avg_curvature __avg_curvature) 0.0)
    ((:curvature_size __curvature_size) 0)
    ((:curvature __curvature) ())
    )
   (send-super :init)
   (setq _road_id (round __road_id))
   (setq _road_type (round __road_type))
   (setq _turn_type (round __turn_type))
   (setq _avg_curvature (float __avg_curvature))
   (setq _curvature_size (round __curvature_size))
   (setq _curvature __curvature)
   self)
  (:road_id
   (&optional __road_id)
   (if __road_id (setq _road_id __road_id)) _road_id)
  (:road_type
   (&optional __road_type)
   (if __road_type (setq _road_type __road_type)) _road_type)
  (:turn_type
   (&optional __turn_type)
   (if __turn_type (setq _turn_type __turn_type)) _turn_type)
  (:avg_curvature
   (&optional __avg_curvature)
   (if __avg_curvature (setq _avg_curvature __avg_curvature)) _avg_curvature)
  (:curvature_size
   (&optional __curvature_size)
   (if __curvature_size (setq _curvature_size __curvature_size)) _curvature_size)
  (:curvature
   (&rest __curvature)
   (if (keywordp (car __curvature))
       (send* _curvature __curvature)
     (progn
       (if __curvature (setq _curvature (car __curvature)))
       _curvature)))
  (:serialization-length
   ()
   (+
    ;; int64 _road_id
    8
    ;; int8 _road_type
    1
    ;; int8 _turn_type
    1
    ;; float64 _avg_curvature
    8
    ;; int32 _curvature_size
    4
    ;; ros_interface/CurvatureInfo[] _curvature
    (apply #'+ (send-all _curvature :serialization-length)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int64 _road_id
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _road_id (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _road_id) (= (length (_road_id . bv)) 2)) ;; bignum
              (write-long (ash (elt (_road_id . bv) 0) 0) s)
              (write-long (ash (elt (_road_id . bv) 1) -1) s))
             ((and (class _road_id) (= (length (_road_id . bv)) 1)) ;; big1
              (write-long (elt (_road_id . bv) 0) s)
              (write-long (if (>= _road_id 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _road_id s)(write-long (if (>= _road_id 0) 0 #xffffffff) s)))
     ;; int8 _road_type
       (write-byte _road_type s)
     ;; int8 _turn_type
       (write-byte _turn_type s)
     ;; float64 _avg_curvature
       (sys::poke _avg_curvature (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; int32 _curvature_size
       (write-long _curvature_size s)
     ;; ros_interface/CurvatureInfo[] _curvature
     (write-long (length _curvature) s)
     (dolist (elem _curvature)
       (send elem :serialize s)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int64 _road_id
#+(or :alpha :irix6 :x86_64)
      (setf _road_id (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _road_id (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; int8 _road_type
     (setq _road_type (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _road_type 127) (setq _road_type (- _road_type 256)))
   ;; int8 _turn_type
     (setq _turn_type (sys::peek buf ptr- :char)) (incf ptr- 1)
     (if (> _turn_type 127) (setq _turn_type (- _turn_type 256)))
   ;; float64 _avg_curvature
     (setq _avg_curvature (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; int32 _curvature_size
     (setq _curvature_size (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; ros_interface/CurvatureInfo[] _curvature
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _curvature (let (r) (dotimes (i n) (push (instance ros_interface::CurvatureInfo :init) r)) r))
     (dolist (elem- _curvature)
     (send elem- :deserialize buf ptr-) (incf ptr- (send elem- :serialization-length))
     ))
   ;;
   self)
  )

(setf (get ros_interface::GuideRoad :md5sum-) "2111a81fc9be87fa69598a4bd29fcca4")
(setf (get ros_interface::GuideRoad :datatype-) "ros_interface/GuideRoad")
(setf (get ros_interface::GuideRoad :definition-)
      "int64   road_id     # 道路的id
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



(provide :ros_interface/GuideRoad "2111a81fc9be87fa69598a4bd29fcca4")


