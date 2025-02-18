;; Auto-generated. Do not edit!


(when (boundp 'perception_msgs::TaskList)
  (if (not (find-package "PERCEPTION_MSGS"))
    (make-package "PERCEPTION_MSGS"))
  (shadow 'TaskList (find-package "PERCEPTION_MSGS")))
(unless (find-package "PERCEPTION_MSGS::TASKLIST")
  (make-package "PERCEPTION_MSGS::TASKLIST"))

(in-package "ROS")
;;//! \htmlinclude TaskList.msg.html
(if (not (find-package "GEOMETRY_MSGS"))
  (ros::roseus-add-msgs "geometry_msgs"))


(defclass perception_msgs::TaskList
  :super ros::object
  :slots (_task_id _task_type _target_position _target_object _task_state _task_result _isInPlaceRotation ))

(defmethod perception_msgs::TaskList
  (:init
   (&key
    ((:task_id __task_id) 0)
    ((:task_type __task_type) 0)
    ((:target_position __target_position) (instance geometry_msgs::Pose :init))
    ((:target_object __target_object) "")
    ((:task_state __task_state) 0)
    ((:task_result __task_result) 0)
    ((:isInPlaceRotation __isInPlaceRotation) 0)
    )
   (send-super :init)
   (setq _task_id (round __task_id))
   (setq _task_type (round __task_type))
   (setq _target_position __target_position)
   (setq _target_object (string __target_object))
   (setq _task_state (round __task_state))
   (setq _task_result (round __task_result))
   (setq _isInPlaceRotation (round __isInPlaceRotation))
   self)
  (:task_id
   (&optional __task_id)
   (if __task_id (setq _task_id __task_id)) _task_id)
  (:task_type
   (&optional __task_type)
   (if __task_type (setq _task_type __task_type)) _task_type)
  (:target_position
   (&rest __target_position)
   (if (keywordp (car __target_position))
       (send* _target_position __target_position)
     (progn
       (if __target_position (setq _target_position (car __target_position)))
       _target_position)))
  (:target_object
   (&optional __target_object)
   (if __target_object (setq _target_object __target_object)) _target_object)
  (:task_state
   (&optional __task_state)
   (if __task_state (setq _task_state __task_state)) _task_state)
  (:task_result
   (&optional __task_result)
   (if __task_result (setq _task_result __task_result)) _task_result)
  (:isInPlaceRotation
   (&optional __isInPlaceRotation)
   (if __isInPlaceRotation (setq _isInPlaceRotation __isInPlaceRotation)) _isInPlaceRotation)
  (:serialization-length
   ()
   (+
    ;; uint64 _task_id
    8
    ;; uint32 _task_type
    4
    ;; geometry_msgs/Pose _target_position
    (send _target_position :serialization-length)
    ;; string _target_object
    4 (length _target_object)
    ;; uint8 _task_state
    1
    ;; uint8 _task_result
    1
    ;; uint8 _isInPlaceRotation
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint64 _task_id
#+(or :alpha :irix6 :x86_64)
       (progn (sys::poke _task_id (send s :buffer) (send s :count) :long) (incf (stream-count s) 8))
#-(or :alpha :irix6 :x86_64)
       (cond ((and (class _task_id) (= (length (_task_id . bv)) 2)) ;; bignum
              (write-long (ash (elt (_task_id . bv) 0) 0) s)
              (write-long (ash (elt (_task_id . bv) 1) -1) s))
             ((and (class _task_id) (= (length (_task_id . bv)) 1)) ;; big1
              (write-long (elt (_task_id . bv) 0) s)
              (write-long (if (>= _task_id 0) 0 #xffffffff) s))
             (t                                         ;; integer
              (write-long _task_id s)(write-long (if (>= _task_id 0) 0 #xffffffff) s)))
     ;; uint32 _task_type
       (write-long _task_type s)
     ;; geometry_msgs/Pose _target_position
       (send _target_position :serialize s)
     ;; string _target_object
       (write-long (length _target_object) s) (princ _target_object s)
     ;; uint8 _task_state
       (write-byte _task_state s)
     ;; uint8 _task_result
       (write-byte _task_result s)
     ;; uint8 _isInPlaceRotation
       (write-byte _isInPlaceRotation s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint64 _task_id
     
#+(or :alpha :irix6 :x86_64)
      (setf _task_id (prog1 (sys::peek buf ptr- :long) (incf ptr- 8)))
#-(or :alpha :irix6 :x86_64)
      (setf _task_id (let ((b0 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4)))
                  (b1 (prog1 (sys::peek buf ptr- :integer) (incf ptr- 4))))
              (cond ((= b1 -1) b0)
                     ((and (= b1  0)
                           (<= lisp::most-negative-fixnum b0 lisp::most-positive-fixnum))
                      b0)
                    ((= b1  0) (make-instance bignum :size 1 :bv (integer-vector b0)))
                    (t (make-instance bignum :size 2 :bv (integer-vector b0 (ash b1 1)))))))
   ;; uint32 _task_type
     (setq _task_type (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; geometry_msgs/Pose _target_position
     (send _target_position :deserialize buf ptr-) (incf ptr- (send _target_position :serialization-length))
   ;; string _target_object
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _target_object (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint8 _task_state
     (setq _task_state (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _task_result
     (setq _task_result (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; uint8 _isInPlaceRotation
     (setq _isInPlaceRotation (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;;
   self)
  )

(setf (get perception_msgs::TaskList :md5sum-) "72dfea7a02287e1a585c8d273011f6e9")
(setf (get perception_msgs::TaskList :datatype-) "perception_msgs/TaskList")
(setf (get perception_msgs::TaskList :definition-)
      "# Task Id
uint64 task_id

# Task Type
uint32 task_type

# Target Position
geometry_msgs/Pose target_position

# Target Object
string target_object

# Task State
uint8 task_state

# Task Result
uint8 task_result

# 到达终点是否原地打转
uint8 isInPlaceRotation 

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

")



(provide :perception_msgs/TaskList "72dfea7a02287e1a585c8d273011f6e9")


