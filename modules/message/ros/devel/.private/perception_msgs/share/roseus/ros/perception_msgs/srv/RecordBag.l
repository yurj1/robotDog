;; Auto-generated. Do not edit!


(when (boundp 'perception_msgs::RecordBag)
  (if (not (find-package "PERCEPTION_MSGS"))
    (make-package "PERCEPTION_MSGS"))
  (shadow 'RecordBag (find-package "PERCEPTION_MSGS")))
(unless (find-package "PERCEPTION_MSGS::RECORDBAG")
  (make-package "PERCEPTION_MSGS::RECORDBAG"))
(unless (find-package "PERCEPTION_MSGS::RECORDBAGREQUEST")
  (make-package "PERCEPTION_MSGS::RECORDBAGREQUEST"))
(unless (find-package "PERCEPTION_MSGS::RECORDBAGRESPONSE")
  (make-package "PERCEPTION_MSGS::RECORDBAGRESPONSE"))

(in-package "ROS")





(defclass perception_msgs::RecordBagRequest
  :super ros::object
  :slots (_bagMode _bagName _topics _bashName ))

(defmethod perception_msgs::RecordBagRequest
  (:init
   (&key
    ((:bagMode __bagMode) 0)
    ((:bagName __bagName) "")
    ((:topics __topics) (let (r) (dotimes (i 0) (push "" r)) r))
    ((:bashName __bashName) "")
    )
   (send-super :init)
   (setq _bagMode (round __bagMode))
   (setq _bagName (string __bagName))
   (setq _topics __topics)
   (setq _bashName (string __bashName))
   self)
  (:bagMode
   (&optional __bagMode)
   (if __bagMode (setq _bagMode __bagMode)) _bagMode)
  (:bagName
   (&optional __bagName)
   (if __bagName (setq _bagName __bagName)) _bagName)
  (:topics
   (&optional __topics)
   (if __topics (setq _topics __topics)) _topics)
  (:bashName
   (&optional __bashName)
   (if __bashName (setq _bashName __bashName)) _bashName)
  (:serialization-length
   ()
   (+
    ;; uint8 _bagMode
    1
    ;; string _bagName
    4 (length _bagName)
    ;; string[] _topics
    (apply #'+ (mapcar #'(lambda (x) (+ 4 (length x))) _topics)) 4
    ;; string _bashName
    4 (length _bashName)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint8 _bagMode
       (write-byte _bagMode s)
     ;; string _bagName
       (write-long (length _bagName) s) (princ _bagName s)
     ;; string[] _topics
     (write-long (length _topics) s)
     (dolist (elem _topics)
       (write-long (length elem) s) (princ elem s)
       )
     ;; string _bashName
       (write-long (length _bashName) s) (princ _bashName s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint8 _bagMode
     (setq _bagMode (sys::peek buf ptr- :char)) (incf ptr- 1)
   ;; string _bagName
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _bagName (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; string[] _topics
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _topics (make-list n))
     (dotimes (i n)
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setf (elt _topics i) (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
     ))
   ;; string _bashName
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _bashName (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass perception_msgs::RecordBagResponse
  :super ros::object
  :slots (_success _errorInfo ))

(defmethod perception_msgs::RecordBagResponse
  (:init
   (&key
    ((:success __success) nil)
    ((:errorInfo __errorInfo) "")
    )
   (send-super :init)
   (setq _success __success)
   (setq _errorInfo (string __errorInfo))
   self)
  (:success
   (&optional (__success :null))
   (if (not (eq __success :null)) (setq _success __success)) _success)
  (:errorInfo
   (&optional __errorInfo)
   (if __errorInfo (setq _errorInfo __errorInfo)) _errorInfo)
  (:serialization-length
   ()
   (+
    ;; bool _success
    1
    ;; string _errorInfo
    4 (length _errorInfo)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; bool _success
       (if _success (write-byte -1 s) (write-byte 0 s))
     ;; string _errorInfo
       (write-long (length _errorInfo) s) (princ _errorInfo s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; bool _success
     (setq _success (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;; string _errorInfo
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _errorInfo (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(defclass perception_msgs::RecordBag
  :super ros::object
  :slots ())

(setf (get perception_msgs::RecordBag :md5sum-) "0e3c6c8f89a4078d1c2279ef76b31bf7")
(setf (get perception_msgs::RecordBag :datatype-) "perception_msgs/RecordBag")
(setf (get perception_msgs::RecordBag :request) perception_msgs::RecordBagRequest)
(setf (get perception_msgs::RecordBag :response) perception_msgs::RecordBagResponse)

(defmethod perception_msgs::RecordBagRequest
  (:response () (instance perception_msgs::RecordBagResponse :init)))

(setf (get perception_msgs::RecordBagRequest :md5sum-) "0e3c6c8f89a4078d1c2279ef76b31bf7")
(setf (get perception_msgs::RecordBagRequest :datatype-) "perception_msgs/RecordBagRequest")
(setf (get perception_msgs::RecordBagRequest :definition-)
      "uint8 bagMode #0: 结束  1: 自定义录包 2： 执行脚本录包
# type1 
string bagName #包名
string[] topics #录制的所有话题
# type2
string bashName #脚本名
---
bool success
string errorInfo
")

(setf (get perception_msgs::RecordBagResponse :md5sum-) "0e3c6c8f89a4078d1c2279ef76b31bf7")
(setf (get perception_msgs::RecordBagResponse :datatype-) "perception_msgs/RecordBagResponse")
(setf (get perception_msgs::RecordBagResponse :definition-)
      "uint8 bagMode #0: 结束  1: 自定义录包 2： 执行脚本录包
# type1 
string bagName #包名
string[] topics #录制的所有话题
# type2
string bashName #脚本名
---
bool success
string errorInfo
")



(provide :perception_msgs/RecordBag "0e3c6c8f89a4078d1c2279ef76b31bf7")


