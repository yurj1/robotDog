;; Auto-generated. Do not edit!


(when (boundp 'ros_interface::ImageRect)
  (if (not (find-package "ROS_INTERFACE"))
    (make-package "ROS_INTERFACE"))
  (shadow 'ImageRect (find-package "ROS_INTERFACE")))
(unless (find-package "ROS_INTERFACE::IMAGERECT")
  (make-package "ROS_INTERFACE::IMAGERECT"))

(in-package "ROS")
;;//! \htmlinclude ImageRect.msg.html


(defclass ros_interface::ImageRect
  :super ros::object
  :slots (_x _y _width _height ))

(defmethod ros_interface::ImageRect
  (:init
   (&key
    ((:x __x) 0)
    ((:y __y) 0)
    ((:width __width) 0)
    ((:height __height) 0)
    )
   (send-super :init)
   (setq _x (round __x))
   (setq _y (round __y))
   (setq _width (round __width))
   (setq _height (round __height))
   self)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:width
   (&optional __width)
   (if __width (setq _width __width)) _width)
  (:height
   (&optional __height)
   (if __height (setq _height __height)) _height)
  (:serialization-length
   ()
   (+
    ;; int32 _x
    4
    ;; int32 _y
    4
    ;; int32 _width
    4
    ;; int32 _height
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _x
       (write-long _x s)
     ;; int32 _y
       (write-long _y s)
     ;; int32 _width
       (write-long _width s)
     ;; int32 _height
       (write-long _height s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _x
     (setq _x (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _y
     (setq _y (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _width
     (setq _width (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _height
     (setq _height (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(setf (get ros_interface::ImageRect :md5sum-) "4425f1067abc7ec2e487d28194eccff4")
(setf (get ros_interface::ImageRect :datatype-) "ros_interface/ImageRect")
(setf (get ros_interface::ImageRect :definition-)
      "int32   x     # coordinate x of left-top point of image rect
int32   y     # coordinate y of left-top point of image rect
int32   width     # width of image rect
int32   height     # height of image rect

")



(provide :ros_interface/ImageRect "4425f1067abc7ec2e487d28194eccff4")


