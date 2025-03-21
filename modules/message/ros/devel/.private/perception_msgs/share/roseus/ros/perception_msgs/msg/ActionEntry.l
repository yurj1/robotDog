;; Auto-generated. Do not edit!


(when (boundp 'perception_msgs::ActionEntry)
  (if (not (find-package "PERCEPTION_MSGS"))
    (make-package "PERCEPTION_MSGS"))
  (shadow 'ActionEntry (find-package "PERCEPTION_MSGS")))
(unless (find-package "PERCEPTION_MSGS::ACTIONENTRY")
  (make-package "PERCEPTION_MSGS::ACTIONENTRY"))

(in-package "ROS")
;;//! \htmlinclude ActionEntry.msg.html


(defclass perception_msgs::ActionEntry
  :super ros::object
  :slots (_id _param1 _param2 _param3 _info ))

(defmethod perception_msgs::ActionEntry
  (:init
   (&key
    ((:id __id) 0)
    ((:param1 __param1) 0)
    ((:param2 __param2) 0)
    ((:param3 __param3) "")
    ((:info __info) "")
    )
   (send-super :init)
   (setq _id (round __id))
   (setq _param1 (round __param1))
   (setq _param2 (round __param2))
   (setq _param3 (string __param3))
   (setq _info (string __info))
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:param1
   (&optional __param1)
   (if __param1 (setq _param1 __param1)) _param1)
  (:param2
   (&optional __param2)
   (if __param2 (setq _param2 __param2)) _param2)
  (:param3
   (&optional __param3)
   (if __param3 (setq _param3 __param3)) _param3)
  (:info
   (&optional __info)
   (if __info (setq _info __info)) _info)
  (:serialization-length
   ()
   (+
    ;; int32 _id
    4
    ;; int32 _param1
    4
    ;; int32 _param2
    4
    ;; string _param3
    4 (length _param3)
    ;; string _info
    4 (length _info)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _id
       (write-long _id s)
     ;; int32 _param1
       (write-long _param1 s)
     ;; int32 _param2
       (write-long _param2 s)
     ;; string _param3
       (write-long (length _param3) s) (princ _param3 s)
     ;; string _info
       (write-long (length _info) s) (princ _info s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _id
     (setq _id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _param1
     (setq _param1 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _param2
     (setq _param2 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; string _param3
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _param3 (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string _info
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _info (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get perception_msgs::ActionEntry :md5sum-) "79cce1446717db417b50a2a6f23271bb")
(setf (get perception_msgs::ActionEntry :datatype-) "perception_msgs/ActionEntry")
(setf (get perception_msgs::ActionEntry :definition-)
      "#动作id
int32  id
#动作参数
int32  param1
int32  param2
string param3
#消息
string info
")



(provide :perception_msgs/ActionEntry "79cce1446717db417b50a2a6f23271bb")


