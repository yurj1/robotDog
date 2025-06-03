; Auto-generated. Do not edit!


(cl:in-package perception_msgs-srv)


;//! \htmlinclude DogRecordBag-request.msg.html

(cl:defclass <DogRecordBag-request> (roslisp-msg-protocol:ros-message)
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

(cl:defclass DogRecordBag-request (<DogRecordBag-request>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DogRecordBag-request>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DogRecordBag-request)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name perception_msgs-srv:<DogRecordBag-request> is deprecated: use perception_msgs-srv:DogRecordBag-request instead.")))

(cl:ensure-generic-function 'bagMode-val :lambda-list '(m))
(cl:defmethod bagMode-val ((m <DogRecordBag-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-srv:bagMode-val is deprecated.  Use perception_msgs-srv:bagMode instead.")
  (bagMode m))

(cl:ensure-generic-function 'bagName-val :lambda-list '(m))
(cl:defmethod bagName-val ((m <DogRecordBag-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-srv:bagName-val is deprecated.  Use perception_msgs-srv:bagName instead.")
  (bagName m))

(cl:ensure-generic-function 'topics-val :lambda-list '(m))
(cl:defmethod topics-val ((m <DogRecordBag-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-srv:topics-val is deprecated.  Use perception_msgs-srv:topics instead.")
  (topics m))

(cl:ensure-generic-function 'bashName-val :lambda-list '(m))
(cl:defmethod bashName-val ((m <DogRecordBag-request>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-srv:bashName-val is deprecated.  Use perception_msgs-srv:bashName instead.")
  (bashName m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DogRecordBag-request>) ostream)
  "Serializes a message object of type '<DogRecordBag-request>"
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
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DogRecordBag-request>) istream)
  "Deserializes a message object of type '<DogRecordBag-request>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DogRecordBag-request>)))
  "Returns string type for a service object of type '<DogRecordBag-request>"
  "perception_msgs/DogRecordBagRequest")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DogRecordBag-request)))
  "Returns string type for a service object of type 'DogRecordBag-request"
  "perception_msgs/DogRecordBagRequest")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DogRecordBag-request>)))
  "Returns md5sum for a message object of type '<DogRecordBag-request>"
  "0e3c6c8f89a4078d1c2279ef76b31bf7")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DogRecordBag-request)))
  "Returns md5sum for a message object of type 'DogRecordBag-request"
  "0e3c6c8f89a4078d1c2279ef76b31bf7")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DogRecordBag-request>)))
  "Returns full string definition for message of type '<DogRecordBag-request>"
  (cl:format cl:nil "# 0:结束；1：话题录包；2：执行脚本录包~%uint8 bagMode~%string bagName~%string[] topics~%string bashName~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DogRecordBag-request)))
  "Returns full string definition for message of type 'DogRecordBag-request"
  (cl:format cl:nil "# 0:结束；1：话题录包；2：执行脚本录包~%uint8 bagMode~%string bagName~%string[] topics~%string bashName~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DogRecordBag-request>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'bagName))
     4 (cl:reduce #'cl:+ (cl:slot-value msg 'topics) :key #'(cl:lambda (ele) (cl:declare (cl:ignorable ele)) (cl:+ 4 (cl:length ele))))
     4 (cl:length (cl:slot-value msg 'bashName))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DogRecordBag-request>))
  "Converts a ROS message object to a list"
  (cl:list 'DogRecordBag-request
    (cl:cons ':bagMode (bagMode msg))
    (cl:cons ':bagName (bagName msg))
    (cl:cons ':topics (topics msg))
    (cl:cons ':bashName (bashName msg))
))
;//! \htmlinclude DogRecordBag-response.msg.html

(cl:defclass <DogRecordBag-response> (roslisp-msg-protocol:ros-message)
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

(cl:defclass DogRecordBag-response (<DogRecordBag-response>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <DogRecordBag-response>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'DogRecordBag-response)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name perception_msgs-srv:<DogRecordBag-response> is deprecated: use perception_msgs-srv:DogRecordBag-response instead.")))

(cl:ensure-generic-function 'success-val :lambda-list '(m))
(cl:defmethod success-val ((m <DogRecordBag-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-srv:success-val is deprecated.  Use perception_msgs-srv:success instead.")
  (success m))

(cl:ensure-generic-function 'errorInfo-val :lambda-list '(m))
(cl:defmethod errorInfo-val ((m <DogRecordBag-response>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader perception_msgs-srv:errorInfo-val is deprecated.  Use perception_msgs-srv:errorInfo instead.")
  (errorInfo m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <DogRecordBag-response>) ostream)
  "Serializes a message object of type '<DogRecordBag-response>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'success) 1 0)) ostream)
  (cl:let ((__ros_str_len (cl:length (cl:slot-value msg 'errorInfo))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) __ros_str_len) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) __ros_str_len) ostream))
  (cl:map cl:nil #'(cl:lambda (c) (cl:write-byte (cl:char-code c) ostream)) (cl:slot-value msg 'errorInfo))
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <DogRecordBag-response>) istream)
  "Deserializes a message object of type '<DogRecordBag-response>"
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
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<DogRecordBag-response>)))
  "Returns string type for a service object of type '<DogRecordBag-response>"
  "perception_msgs/DogRecordBagResponse")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DogRecordBag-response)))
  "Returns string type for a service object of type 'DogRecordBag-response"
  "perception_msgs/DogRecordBagResponse")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<DogRecordBag-response>)))
  "Returns md5sum for a message object of type '<DogRecordBag-response>"
  "0e3c6c8f89a4078d1c2279ef76b31bf7")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'DogRecordBag-response)))
  "Returns md5sum for a message object of type 'DogRecordBag-response"
  "0e3c6c8f89a4078d1c2279ef76b31bf7")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<DogRecordBag-response>)))
  "Returns full string definition for message of type '<DogRecordBag-response>"
  (cl:format cl:nil "bool success~%string errorInfo~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'DogRecordBag-response)))
  "Returns full string definition for message of type 'DogRecordBag-response"
  (cl:format cl:nil "bool success~%string errorInfo~%~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <DogRecordBag-response>))
  (cl:+ 0
     1
     4 (cl:length (cl:slot-value msg 'errorInfo))
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <DogRecordBag-response>))
  "Converts a ROS message object to a list"
  (cl:list 'DogRecordBag-response
    (cl:cons ':success (success msg))
    (cl:cons ':errorInfo (errorInfo msg))
))
(cl:defmethod roslisp-msg-protocol:service-request-type ((msg (cl:eql 'DogRecordBag)))
  'DogRecordBag-request)
(cl:defmethod roslisp-msg-protocol:service-response-type ((msg (cl:eql 'DogRecordBag)))
  'DogRecordBag-response)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'DogRecordBag)))
  "Returns string type for a service object of type '<DogRecordBag>"
  "perception_msgs/DogRecordBag")