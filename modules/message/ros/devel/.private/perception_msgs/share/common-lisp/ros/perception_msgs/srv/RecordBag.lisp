; Auto-generated. Do not edit!


(cl:in-package perception_msgs-srv)


;//! \htmlinclude RecordBag-request.msg.html

(cl:defclass <RecordBag-request> (roslisp-msg-protocol:ros-message)
  ((bagMode
    :reader bagMode
    :initarg :bagMode
    :type cl:fixnum
    :initform 0)
   (bagName
    :reader bagName
    :initarg :bagName
    :type cl:string
    :initform "")
   (topics
    :reader topics
    :initarg :topics
    :type (cl:vector cl:string)
   :initform (cl:make-array 0 :element-type 'cl:string :initial-element ""))
   (bashName
    :reader bashName
    :initarg :bashName
    :type cl:string
    :initform ""))
)

(cl:defclass RecordBag-request (<RecordBag-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RecordBag-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RecordBag-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name perception_msgs-srv:<RecordBag-request> is deprecated: use perception_msgs-srv:RecordBag-request instead.")))

(cl:ensure-generic-function 'bagMode-val :lambda-list '(m))
(cl:defmethod bagMode-val ((m <RecordBag-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-srv:bagMode-val is deprecated.  Use perception_msgs-srv:bagMode instead.")
  (bagMode m))

(cl:ensure-generic-function 'bagName-val :lambda-list '(m))
(cl:defmethod bagName-val ((m <RecordBag-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-srv:bagName-val is deprecated.  Use perception_msgs-srv:bagName instead.")
  (bagName m))

(cl:ensure-generic-function 'topics-val :lambda-list '(m))
(cl:defmethod topics-val ((m <RecordBag-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-srv:topics-val is deprecated.  Use perception_msgs-srv:topics instead.")
  (topics m))

(cl:ensure-generic-function 'bashName-val :lambda-list '(m))
(cl:defmethod bashName-val ((m <RecordBag-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-srv:bashName-val is deprecated.  Use perception_msgs-srv:bashName instead.")
  (bashName m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RecordBag-request>) ostream)
  "Serializes a message object of type '<RecordBag-request>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'bagMode)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'bagName))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'bagName))
  (cl:let ((__ros_arr_len (cl:length (cl:slot-value msg 'topics))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_arr_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_arr_len) ostream))
  (cl:map cl:nil #'(cl:lambda (ele) (cl:let ((__ros_str_len (cl:length ele)))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) ele))
   (cl:slot-value msg 'topics))
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'bashName))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'bashName))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RecordBag-request>) istream)
  "Deserializes a message object of type '<RecordBag-request>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'bagMode)) (cl:read-byte istream))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'bagName) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'bagName) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  (cl:let ((__ros_arr_len 0))
    (cl:setf (cl:ldb (cl:byte 8 0) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) __ros_arr_len) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) __ros_arr_len) (cl:read-byte istream))
  (cl:setf (cl:slot-value msg 'topics) (cl:make-array __ros_arr_len))
  (cl:let ((vals (cl:slot-value msg 'topics)))
    (cl:dotimes (i __ros_arr_len)
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:aref vals i) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:aref vals i) __ros_str_idx) (cl:code-char (cl:read-byte istream))))))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'bashName) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'bashName) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RecordBag-request>)))
  "Returns string type for a service object of type '<RecordBag-request>"
  "perception_msgs/RecordBagRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RecordBag-request)))
  "Returns string type for a service object of type 'RecordBag-request"
  "perception_msgs/RecordBagRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RecordBag-request>)))
  "Returns md5sum for a message object of type '<RecordBag-request>"
  "0e3c6c8f89a4078d1c2279ef76b31bf7")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RecordBag-request)))
  "Returns md5sum for a message object of type 'RecordBag-request"
  "0e3c6c8f89a4078d1c2279ef76b31bf7")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RecordBag-request>)))
  "Returns full string definition for message of type '<RecordBag-request>"
  (cl:format cl:nil "uint8 bagMode #0: 结束  1: 自定义录包 2： 执行脚本录包~%# type1 ~%string bagName #包名~%string[] topics #录制的所有话题~%# type2~%string bashName #脚本名~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RecordBag-request)))
  "Returns full string definition for message of type 'RecordBag-request"
  (cl:format cl:nil "uint8 bagMode #0: 结束  1: 自定义录包 2： 执行脚本录包~%# type1 ~%string bagName #包名~%string[] topics #录制的所有话题~%# type2~%string bashName #脚本名~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RecordBag-request>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'bagName))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'topics) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
     4 (cl:length (cl:slot-value msg 'bashName))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RecordBag-request>))
  "Converts a ROS message object to a list"
  (cl:list 'RecordBag-request
    (cl:cons ':bagMode (bagMode msg))
    (cl:cons ':bagName (bagName msg))
    (cl:cons ':topics (topics msg))
    (cl:cons ':bashName (bashName msg))
))
;//! \htmlinclude RecordBag-response.msg.html

(cl:defclass <RecordBag-response> (roslisp-msg-protocol:ros-message)
  ((success
    :reader success
    :initarg :success
    :type cl:boolean
    :initform cl:nil)
   (errorInfo
    :reader errorInfo
    :initarg :errorInfo
    :type cl:string
    :initform ""))
)

(cl:defclass RecordBag-response (<RecordBag-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <RecordBag-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'RecordBag-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name perception_msgs-srv:<RecordBag-response> is deprecated: use perception_msgs-srv:RecordBag-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <RecordBag-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-srv:success-val is deprecated.  Use perception_msgs-srv:success instead.")
  (success m))

(cl:ensure-generic-function 'errorInfo-val :lambda-list '(m))
(cl:defmethod errorInfo-val ((m <RecordBag-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-srv:errorInfo-val is deprecated.  Use perception_msgs-srv:errorInfo instead.")
  (errorInfo m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <RecordBag-response>) ostream)
  "Serializes a message object of type '<RecordBag-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'errorInfo))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'errorInfo))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <RecordBag-response>) istream)
  "Deserializes a message object of type '<RecordBag-response>"
    (cl:setf (cl:slot-value msg 'success) (cl:not (cl:zerop (cl:read-byte istream))))
    (cl:let ((__ros_str_len 0))
      (cl:setf (cl:ldb (cl:byte 8 0) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) __ros_str_len) (cl:read-byte istream))
      (cl:setf (cl:slot-value msg 'errorInfo) (cl:make-string __ros_str_len))
      (cl:dotimes (__ros_str_idx __ros_str_len msg)
        (cl:setf (cl:char (cl:slot-value msg 'errorInfo) __ros_str_idx) (cl:code-char (cl:read-byte istream)))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<RecordBag-response>)))
  "Returns string type for a service object of type '<RecordBag-response>"
  "perception_msgs/RecordBagResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RecordBag-response)))
  "Returns string type for a service object of type 'RecordBag-response"
  "perception_msgs/RecordBagResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<RecordBag-response>)))
  "Returns md5sum for a message object of type '<RecordBag-response>"
  "0e3c6c8f89a4078d1c2279ef76b31bf7")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'RecordBag-response)))
  "Returns md5sum for a message object of type 'RecordBag-response"
  "0e3c6c8f89a4078d1c2279ef76b31bf7")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<RecordBag-response>)))
  "Returns full string definition for message of type '<RecordBag-response>"
  (cl:format cl:nil "bool success~%string errorInfo~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'RecordBag-response)))
  "Returns full string definition for message of type 'RecordBag-response"
  (cl:format cl:nil "bool success~%string errorInfo~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <RecordBag-response>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'errorInfo))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <RecordBag-response>))
  "Converts a ROS message object to a list"
  (cl:list 'RecordBag-response
    (cl:cons ':success (success msg))
    (cl:cons ':errorInfo (errorInfo msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'RecordBag)))
  'RecordBag-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'RecordBag)))
  'RecordBag-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'RecordBag)))
  "Returns string type for a service object of type '<RecordBag>"
  "perception_msgs/RecordBag")