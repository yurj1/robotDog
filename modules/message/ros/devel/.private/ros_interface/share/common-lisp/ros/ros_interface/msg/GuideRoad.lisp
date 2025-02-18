; Auto-generated. Do not edit!


(cl:in-package ros_interface-msg)


;//! \htmlinclude GuideRoad.msg.html

(cl:defclass <GuideRoad> (roslisp-msg-protocol:ros-message)
  ((road_id
    :reader road_id
    :initarg :road_id
    :type cl:integer
    :initform 0)
   (road_type
    :reader road_type
    :initarg :road_type
    :type cl:fixnum
    :initform 0)
   (turn_type
    :reader turn_type
    :initarg :turn_type
    :type cl:fixnum
    :initform 0)
   (avg_curvature
    :reader avg_curvature
    :initarg :avg_curvature
    :type cl:float
    :initform 0.0)
   (curvature_size
    :reader curvature_size
    :initarg :curvature_size
    :type cl:integer
    :initform 0)
   (curvature
    :reader curvature
    :initarg :curvature
    :type (cl:vector ros_interface-msg:CurvatureInfo)
   :initform (cl:make-array 0 :element-type 'ros_interface-msg:CurvatureInfo :initial-element (cl:make-instance 'ros_interface-msg:CurvatureInfo))))
)

(cl:defclass GuideRoad (<GuideRoad>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GuideRoad>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GuideRoad)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ros_interface-msg:<GuideRoad> is deprecated: use ros_interface-msg:GuideRoad instead.")))

(cl:ensure-generic-function 'road_id-val :lambda-list '(m))
(cl:defmethod road_id-val ((m <GuideRoad>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_interface-msg:road_id-val is deprecated.  Use ros_interface-msg:road_id instead.")
  (road_id m))

(cl:ensure-generic-function 'road_type-val :lambda-list '(m))
(cl:defmethod road_type-val ((m <GuideRoad>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_interface-msg:road_type-val is deprecated.  Use ros_interface-msg:road_type instead.")
  (road_type m))

(cl:ensure-generic-function 'turn_type-val :lambda-list '(m))
(cl:defmethod turn_type-val ((m <GuideRoad>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_interface-msg:turn_type-val is deprecated.  Use ros_interface-msg:turn_type instead.")
  (turn_type m))

(cl:ensure-generic-function 'avg_curvature-val :lambda-list '(m))
(cl:defmethod avg_curvature-val ((m <GuideRoad>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_interface-msg:avg_curvature-val is deprecated.  Use ros_interface-msg:avg_curvature instead.")
  (avg_curvature m))

(cl:ensure-generic-function 'curvature_size-val :lambda-list '(m))
(cl:defmethod curvature_size-val ((m <GuideRoad>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_interface-msg:curvature_size-val is deprecated.  Use ros_interface-msg:curvature_size instead.")
  (curvature_size m))

(cl:ensure-generic-function 'curvature-val :lambda-list '(m))
(cl:defmethod curvature-val ((m <GuideRoad>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_interface-msg:curvature-val is deprecated.  Use ros_interface-msg:curvature instead.")
  (curvature m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GuideRoad>) ostream)
  "Serializes a message object of type '<GuideRoad>"
  (cl:let* ((signed (cl:slot-value msg 'road_id)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 18446744073709551616) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'road_type)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'turn_type)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'avg_curvature))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let* ((signed (cl:slot-value msg 'curvature_size)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 4294967296) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) unsigned) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) unsigned) ostream)
    )
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'curvature))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (roslisp-msg-protocol:serialize ele ostream))
   (cl:slot-value msg 'curvature))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GuideRoad>) istream)
  "Deserializes a message object of type '<GuideRoad>"
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'road_id) (cl:if (cl:< unsigned 9223372036854775808) unsigned (cl:- unsigned 18446744073709551616))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'road_type) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'turn_type) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'avg_curvature) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) unsigned) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'curvature_size) (cl:if (cl:< unsigned 2147483648) unsigned (cl:- unsigned 4294967296))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'curvature) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'curvature)))
    (cl:dotimes (i __ros_arr_len)
    (cl:setf (cl:aref vals i) (cl:make-instance 'ros_interface-msg:CurvatureInfo))
  (roslisp-msg-protocol:deserialize (cl:aref vals i) istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GuideRoad>)))
  "Returns string type for a message object of type '<GuideRoad>"
  "ros_interface/GuideRoad")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GuideRoad)))
  "Returns string type for a message object of type 'GuideRoad"
  "ros_interface/GuideRoad")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GuideRoad>)))
  "Returns md5sum for a message object of type '<GuideRoad>"
  "2111a81fc9be87fa69598a4bd29fcca4")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GuideRoad)))
  "Returns md5sum for a message object of type 'GuideRoad"
  "2111a81fc9be87fa69598a4bd29fcca4")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GuideRoad>)))
  "Returns full string definition for message of type '<GuideRoad>"
  (cl:format cl:nil "int64   road_id     # 道路的id~%int8   road_type     # 道路的类型: 0：未知或一般道路  1：环岛 2：交叉路口 3：主路 4：辅路~%int8   turn_type     # 规划路线上道路的转向信息 1：左转 2：直行 3：右转~%float64   avg_curvature     # 道路的平均曲率~%int32   curvature_size     # 道路中心线上点(曲率)数量~%CurvatureInfo[] curvature # 道路曲率信息数组~%~%================================================================================~%MSG: ros_interface/CurvatureInfo~%float64   offset     # 道路中心线上点位于该道路的位置（与道路起点的距离）~%float64   value     # 道路中心线上点的曲率值~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GuideRoad)))
  "Returns full string definition for message of type 'GuideRoad"
  (cl:format cl:nil "int64   road_id     # 道路的id~%int8   road_type     # 道路的类型: 0：未知或一般道路  1：环岛 2：交叉路口 3：主路 4：辅路~%int8   turn_type     # 规划路线上道路的转向信息 1：左转 2：直行 3：右转~%float64   avg_curvature     # 道路的平均曲率~%int32   curvature_size     # 道路中心线上点(曲率)数量~%CurvatureInfo[] curvature # 道路曲率信息数组~%~%================================================================================~%MSG: ros_interface/CurvatureInfo~%float64   offset     # 道路中心线上点位于该道路的位置（与道路起点的距离）~%float64   value     # 道路中心线上点的曲率值~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GuideRoad>))
  (cl:+ 0
     8
     1
     1
     8
     4
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'curvature) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ (roslisp-msg-protocol:serialization-length ele))))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GuideRoad>))
  "Converts a ROS message object to a list"
  (cl:list 'GuideRoad
    (cl:cons ':road_id (road_id msg))
    (cl:cons ':road_type (road_type msg))
    (cl:cons ':turn_type (turn_type msg))
    (cl:cons ':avg_curvature (avg_curvature msg))
    (cl:cons ':curvature_size (curvature_size msg))
    (cl:cons ':curvature (curvature msg))
))
