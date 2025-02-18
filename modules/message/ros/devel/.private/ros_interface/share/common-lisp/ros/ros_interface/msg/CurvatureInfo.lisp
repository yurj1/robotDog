; Auto-generated. Do not edit!


(cl:in-package ros_interface-msg)


;//! \htmlinclude CurvatureInfo.msg.html

(cl:defclass <CurvatureInfo> (roslisp-msg-protocol:ros-message)
  ((offset
    :reader offset
    :initarg :offset
    :type cl:float
    :initform 0.0)
   (value
    :reader value
    :initarg :value
    :type cl:float
    :initform 0.0))
)

(cl:defclass CurvatureInfo (<CurvatureInfo>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <CurvatureInfo>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'CurvatureInfo)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name ros_interface-msg:<CurvatureInfo> is deprecated: use ros_interface-msg:CurvatureInfo instead.")))

(cl:ensure-generic-function 'offset-val :lambda-list '(m))
(cl:defmethod offset-val ((m <CurvatureInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_interface-msg:offset-val is deprecated.  Use ros_interface-msg:offset instead.")
  (offset m))

(cl:ensure-generic-function 'value-val :lambda-list '(m))
(cl:defmethod value-val ((m <CurvatureInfo>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader ros_interface-msg:value-val is deprecated.  Use ros_interface-msg:value instead.")
  (value m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <CurvatureInfo>) ostream)
  "Serializes a message object of type '<CurvatureInfo>"
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'offset))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'value))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <CurvatureInfo>) istream)
  "Deserializes a message object of type '<CurvatureInfo>"
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'offset) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'value) (roslisp-utils:decode-double-float-bits bits)))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<CurvatureInfo>)))
  "Returns string type for a message object of type '<CurvatureInfo>"
  "ros_interface/CurvatureInfo")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'CurvatureInfo)))
  "Returns string type for a message object of type 'CurvatureInfo"
  "ros_interface/CurvatureInfo")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<CurvatureInfo>)))
  "Returns md5sum for a message object of type '<CurvatureInfo>"
  "3fa4f475bde56d903dde34d20c370fb9")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'CurvatureInfo)))
  "Returns md5sum for a message object of type 'CurvatureInfo"
  "3fa4f475bde56d903dde34d20c370fb9")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<CurvatureInfo>)))
  "Returns full string definition for message of type '<CurvatureInfo>"
  (cl:format cl:nil "float64   offset     # 道路中心线上点位于该道路的位置（与道路起点的距离）~%float64   value     # 道路中心线上点的曲率值~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'CurvatureInfo)))
  "Returns full string definition for message of type 'CurvatureInfo"
  (cl:format cl:nil "float64   offset     # 道路中心线上点位于该道路的位置（与道路起点的距离）~%float64   value     # 道路中心线上点的曲率值~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <CurvatureInfo>))
  (cl:+ 0
     8
     8
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <CurvatureInfo>))
  "Converts a ROS message object to a list"
  (cl:list 'CurvatureInfo
    (cl:cons ':offset (offset msg))
    (cl:cons ':value (value msg))
))
