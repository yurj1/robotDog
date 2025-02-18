; Auto-generated. Do not edit!


(cl:in-package ros_interface-msg)


;//! \htmlinclude GuideInfo.msg.html

(cl:defclass <GuideInfo> (roslisp-msg-protocol:ros-message)
  ((header
    :reader header
    :initarg :header
    :type std_msgs-msg:Header
    :initform (cl:make-instance 'std_msgs-msg:Header))
   (next_dis
    :reader next_dis
    :initarg :next_dis
    :type cl:float
    :initform 0.0)
   (current_road
    :reader current_road
    :initarg :current_road
    :type ros_interface-msg:GuideRoad
    :initform (cl:make-instance 'ros_interface-msg:GuideRoad))
   (next_road
    :reader next_road
    :initarg :next_road
    :type ros_interface-msg:GuideRoad
    :initform (cl:make-instance 'ros_interface-msg:GuideRoad))
   (round_status
    :reader round_status
    :initarg :round_status
    :type cl:fixnum
    :initform 0)
   (intersection_status
    :reader intersection_status
    :initarg :intersection_status
    :type cl:fixnum
    :initform 0)
   (roads_status
    :reader roads_status
    :initarg :roads_status
    :type cl:fixnum
    :initform 0))
)

(cl:defclass GuideInfo (<GuideInfo>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <GuideInfo>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'GuideInfo)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ros_interface-msg:<GuideInfo> is deprecated: use ros_interface-msg:GuideInfo instead.")))

(cl:ensure-generic-function 'header-val :lambda-list '(m))
(cl:defmethod header-val ((m <GuideInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_interface-msg:header-val is deprecated.  Use ros_interface-msg:header instead.")
  (header m))

(cl:ensure-generic-function 'next_dis-val :lambda-list '(m))
(cl:defmethod next_dis-val ((m <GuideInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_interface-msg:next_dis-val is deprecated.  Use ros_interface-msg:next_dis instead.")
  (next_dis m))

(cl:ensure-generic-function 'current_road-val :lambda-list '(m))
(cl:defmethod current_road-val ((m <GuideInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_interface-msg:current_road-val is deprecated.  Use ros_interface-msg:current_road instead.")
  (current_road m))

(cl:ensure-generic-function 'next_road-val :lambda-list '(m))
(cl:defmethod next_road-val ((m <GuideInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_interface-msg:next_road-val is deprecated.  Use ros_interface-msg:next_road instead.")
  (next_road m))

(cl:ensure-generic-function 'round_status-val :lambda-list '(m))
(cl:defmethod round_status-val ((m <GuideInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_interface-msg:round_status-val is deprecated.  Use ros_interface-msg:round_status instead.")
  (round_status m))

(cl:ensure-generic-function 'intersection_status-val :lambda-list '(m))
(cl:defmethod intersection_status-val ((m <GuideInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_interface-msg:intersection_status-val is deprecated.  Use ros_interface-msg:intersection_status instead.")
  (intersection_status m))

(cl:ensure-generic-function 'roads_status-val :lambda-list '(m))
(cl:defmethod roads_status-val ((m <GuideInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_interface-msg:roads_status-val is deprecated.  Use ros_interface-msg:roads_status instead.")
  (roads_status m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <GuideInfo>) ostream)
  "Serializes a message object of type '<GuideInfo>"
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'header) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'next_dis))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'current_road) ostream)
  (roslisp-msg-protocol:serialize (cl:slot-value msg 'next_road) ostream)
  (cl:let* ((signed (cl:slot-value msg 'round_status)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'intersection_status)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
  (cl:let* ((signed (cl:slot-value msg 'roads_status)) (unsigned (cl:if (cl:< signed 0) (cl:+ signed 256) signed)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) unsigned) ostream)
    )
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <GuideInfo>) istream)
  "Deserializes a message object of type '<GuideInfo>"
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'header) istream)
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'next_dis) (roslisp-utils:decode-double-float-bits bits)))
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'current_road) istream)
  (roslisp-msg-protocol:deserialize (cl:slot-value msg 'next_road) istream)
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'round_status) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'intersection_status) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
    (cl:let ((unsigned 0))
      (cl:setf (cl:ldb (cl:byte 8 0) unsigned) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'roads_status) (cl:if (cl:< unsigned 128) unsigned (cl:- unsigned 256))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<GuideInfo>)))
  "Returns string type for a message object of type '<GuideInfo>"
  "ros_interface/GuideInfo")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'GuideInfo)))
  "Returns string type for a message object of type 'GuideInfo"
  "ros_interface/GuideInfo")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<GuideInfo>)))
  "Returns md5sum for a message object of type '<GuideInfo>"
  "aa74d1653e11a6cb191e3ce919a1654f")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'GuideInfo)))
  "Returns md5sum for a message object of type 'GuideInfo"
  "aa74d1653e11a6cb191e3ce919a1654f")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<GuideInfo>)))
  "Returns full string definition for message of type '<GuideInfo>"
  (cl:format cl:nil "Header   header     # 头部信息~%float64   next_dis     # 下一条规划路线上道路的距离~%GuideRoad   current_road     # 当前道路的引导信息~%GuideRoad   next_road     # 下一条规划道路的引导信息~%int8   round_status     # 环岛状态: 0：未知或非环岛状态 1：当前为非环岛道路并且规划路线即将驶入环岛主路 2：当前道路类型是环岛并且规划路线还是在环岛主路中行驶 3：当前道路类型是环岛并且规划路线即将驶出环岛主路~%int8   intersection_status     # 交叉路口状态: 0：未知 1：非交叉路口状态 2：交叉路口通行状态~%int8   roads_status     # 主辅路状态： 0：未知或非主辅路状态 1：当前道路类型是辅路下一条道路类型是主路  2：当前道路类型是主路下一条道路类型是辅路~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: ros_interface/GuideRoad~%int64   road_id     # 道路的id~%int8   road_type     # 道路的类型: 0：未知或一般道路  1：环岛 2：交叉路口 3：主路 4：辅路~%int8   turn_type     # 规划路线上道路的转向信息 1：左转 2：直行 3：右转~%float64   avg_curvature     # 道路的平均曲率~%int32   curvature_size     # 道路中心线上点(曲率)数量~%CurvatureInfo[] curvature # 道路曲率信息数组~%~%================================================================================~%MSG: ros_interface/CurvatureInfo~%float64   offset     # 道路中心线上点位于该道路的位置（与道路起点的距离）~%float64   value     # 道路中心线上点的曲率值~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'GuideInfo)))
  "Returns full string definition for message of type 'GuideInfo"
  (cl:format cl:nil "Header   header     # 头部信息~%float64   next_dis     # 下一条规划路线上道路的距离~%GuideRoad   current_road     # 当前道路的引导信息~%GuideRoad   next_road     # 下一条规划道路的引导信息~%int8   round_status     # 环岛状态: 0：未知或非环岛状态 1：当前为非环岛道路并且规划路线即将驶入环岛主路 2：当前道路类型是环岛并且规划路线还是在环岛主路中行驶 3：当前道路类型是环岛并且规划路线即将驶出环岛主路~%int8   intersection_status     # 交叉路口状态: 0：未知 1：非交叉路口状态 2：交叉路口通行状态~%int8   roads_status     # 主辅路状态： 0：未知或非主辅路状态 1：当前道路类型是辅路下一条道路类型是主路  2：当前道路类型是主路下一条道路类型是辅路~%~%================================================================================~%MSG: std_msgs/Header~%# Standard metadata for higher-level stamped data types.~%# This is generally used to communicate timestamped data ~%# in a particular coordinate frame.~%# ~%# sequence ID: consecutively increasing ID ~%uint32 seq~%#Two-integer timestamp that is expressed as:~%# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')~%# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')~%# time-handling sugar is provided by the client library~%time stamp~%#Frame this data is associated with~%string frame_id~%~%================================================================================~%MSG: ros_interface/GuideRoad~%int64   road_id     # 道路的id~%int8   road_type     # 道路的类型: 0：未知或一般道路  1：环岛 2：交叉路口 3：主路 4：辅路~%int8   turn_type     # 规划路线上道路的转向信息 1：左转 2：直行 3：右转~%float64   avg_curvature     # 道路的平均曲率~%int32   curvature_size     # 道路中心线上点(曲率)数量~%CurvatureInfo[] curvature # 道路曲率信息数组~%~%================================================================================~%MSG: ros_interface/CurvatureInfo~%float64   offset     # 道路中心线上点位于该道路的位置（与道路起点的距离）~%float64   value     # 道路中心线上点的曲率值~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <GuideInfo>))
  (cl:+ 0
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'header))
     8
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'current_road))
     (roslisp-msg-protocol:serialization-length (cl:slot-value msg 'next_road))
     1
     1
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <GuideInfo>))
  "Converts a ROS message object to a list"
  (cl:list 'GuideInfo
    (cl:cons ':header (header msg))
    (cl:cons ':next_dis (next_dis msg))
    (cl:cons ':current_road (current_road msg))
    (cl:cons ':next_road (next_road msg))
    (cl:cons ':round_status (round_status msg))
    (cl:cons ':intersection_status (intersection_status msg))
    (cl:cons ':roads_status (roads_status msg))
))
