;; Auto-generated. Do not edit!


(when (boundp 'quad_msgs::RobotPlanDiagnostics)
  (if (not (find-package "QUAD_MSGS"))
    (make-package "QUAD_MSGS"))
  (shadow 'RobotPlanDiagnostics (find-package "QUAD_MSGS")))
(unless (find-package "QUAD_MSGS::ROBOTPLANDIAGNOSTICS")
  (make-package "QUAD_MSGS::ROBOTPLANDIAGNOSTICS"))

(in-package "ROS")
;;//! \htmlinclude RobotPlanDiagnostics.msg.html


(defclass quad_msgs::RobotPlanDiagnostics
  :super ros::object
  :slots (_compute_time _cost _iterations _horizon_length _complexity_schedule _element_times ))

(defmethod quad_msgs::RobotPlanDiagnostics
  (:init
   (&key
    ((:compute_time __compute_time) 0.0)
    ((:cost __cost) 0.0)
    ((:iterations __iterations) 0)
    ((:horizon_length __horizon_length) 0)
    ((:complexity_schedule __complexity_schedule) (make-array 0 :initial-element 0 :element-type :integer))
    ((:element_times __element_times) (make-array 0 :initial-element 0.0 :element-type :float))
    )
   (send-super :init)
   (setq _compute_time (float __compute_time))
   (setq _cost (float __cost))
   (setq _iterations (round __iterations))
   (setq _horizon_length (round __horizon_length))
   (setq _complexity_schedule __complexity_schedule)
   (setq _element_times __element_times)
   self)
  (:compute_time
   (&optional __compute_time)
   (if __compute_time (setq _compute_time __compute_time)) _compute_time)
  (:cost
   (&optional __cost)
   (if __cost (setq _cost __cost)) _cost)
  (:iterations
   (&optional __iterations)
   (if __iterations (setq _iterations __iterations)) _iterations)
  (:horizon_length
   (&optional __horizon_length)
   (if __horizon_length (setq _horizon_length __horizon_length)) _horizon_length)
  (:complexity_schedule
   (&optional __complexity_schedule)
   (if __complexity_schedule (setq _complexity_schedule __complexity_schedule)) _complexity_schedule)
  (:element_times
   (&optional __element_times)
   (if __element_times (setq _element_times __element_times)) _element_times)
  (:serialization-length
   ()
   (+
    ;; float64 _compute_time
    8
    ;; float64 _cost
    8
    ;; uint32 _iterations
    4
    ;; uint32 _horizon_length
    4
    ;; uint32[] _complexity_schedule
    (* 4    (length _complexity_schedule)) 4
    ;; float64[] _element_times
    (* 8    (length _element_times)) 4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; float64 _compute_time
       (sys::poke _compute_time (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _cost
       (sys::poke _cost (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; uint32 _iterations
       (write-long _iterations s)
     ;; uint32 _horizon_length
       (write-long _horizon_length s)
     ;; uint32[] _complexity_schedule
     (write-long (length _complexity_schedule) s)
     (dotimes (i (length _complexity_schedule))
       (write-long (elt _complexity_schedule i) s)
       )
     ;; float64[] _element_times
     (write-long (length _element_times) s)
     (dotimes (i (length _element_times))
       (sys::poke (elt _element_times i) (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
       )
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; float64 _compute_time
     (setq _compute_time (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _cost
     (setq _cost (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; uint32 _iterations
     (setq _iterations (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _horizon_length
     (setq _horizon_length (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32[] _complexity_schedule
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _complexity_schedule (instantiate integer-vector n))
     (dotimes (i n)
     (setf (elt _complexity_schedule i) (sys::peek buf ptr- :integer)) (incf ptr- 4)
     ))
   ;; float64[] _element_times
   (let (n)
     (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4)
     (setq _element_times (instantiate float-vector n))
     (dotimes (i n)
     (setf (elt _element_times i) (sys::peek buf ptr- :double)) (incf ptr- 8)
     ))
   ;;
   self)
  )

(setf (get quad_msgs::RobotPlanDiagnostics :md5sum-) "4ba495ddc8d93cb86ca454812d102149")
(setf (get quad_msgs::RobotPlanDiagnostics :datatype-) "quad_msgs/RobotPlanDiagnostics")
(setf (get quad_msgs::RobotPlanDiagnostics :definition-)
      "# This is a message to hold local plan diagnostics

float64 compute_time
float64 cost
uint32 iterations
uint32 horizon_length
uint32[] complexity_schedule
float64[] element_times

")



(provide :quad_msgs/RobotPlanDiagnostics "4ba495ddc8d93cb86ca454812d102149")


