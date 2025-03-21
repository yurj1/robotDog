;; Auto-generated. Do not edit!


(when (boundp 'perception_msgs::AlarmEntry)
  (if (not (find-package "PERCEPTION_MSGS"))
    (make-package "PERCEPTION_MSGS"))
  (shadow 'AlarmEntry (find-package "PERCEPTION_MSGS")))
(unless (find-package "PERCEPTION_MSGS::ALARMENTRY")
  (make-package "PERCEPTION_MSGS::ALARMENTRY"))

(in-package "ROS")
;;//! \htmlinclude AlarmEntry.msg.html


(defclass perception_msgs::AlarmEntry
  :super ros::object
  :slots (_id _source _level _status _message ))

(defmethod perception_msgs::AlarmEntry
  (:init
   (&key
    ((:id __id) 0)
    ((:source __source) 0)
    ((:level __level) 0)
    ((:status __status) 0)
    ((:message __message) "")
    )
   (send-super :init)
   (setq _id (round __id))
   (setq _source (round __source))
   (setq _level (round __level))
   (setq _status (round __status))
   (setq _message (string __message))
   self)
  (:id
   (&optional __id)
   (if __id (setq _id __id)) _id)
  (:source
   (&optional __source)
   (if __source (setq _source __source)) _source)
  (:level
   (&optional __level)
   (if __level (setq _level __level)) _level)
  (:status
   (&optional __status)
   (if __status (setq _status __status)) _status)
  (:message
   (&optional __message)
   (if __message (setq _message __message)) _message)
  (:serialization-length
   ()
   (+
    ;; int32 _id
    4
    ;; int32 _source
    4
    ;; int32 _level
    4
    ;; int32 _status
    4
    ;; string _message
    4 (length _message)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _id
       (write-long _id s)
     ;; int32 _source
       (write-long _source s)
     ;; int32 _level
       (write-long _level s)
     ;; int32 _status
       (write-long _status s)
     ;; string _message
       (write-long (length _message) s) (princ _message s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _id
     (setq _id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _source
     (setq _source (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _level
     (setq _level (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _status
     (setq _status (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; string _message
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _message (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get perception_msgs::AlarmEntry :md5sum-) "572a1444f59dbedf187030dc52cb77da")
(setf (get perception_msgs::AlarmEntry :datatype-) "perception_msgs/AlarmEntry")
(setf (get perception_msgs::AlarmEntry :definition-)
      "int32  id
int32  source
int32  level
int32  status
string message
")



(provide :perception_msgs/AlarmEntry "572a1444f59dbedf187030dc52cb77da")


