
(cl:in-package :asdf)

(defsystem "perception_msgs-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils :geometry_msgs-msg
               :std_msgs-msg
)
  :components ((:file "_package")
    (:file "ActionEntry" :depends-on ("_package_ActionEntry"))
    (:file "_package_ActionEntry" :depends-on ("_package"))
    (:file "AlarmEntry" :depends-on ("_package_AlarmEntry"))
    (:file "_package_AlarmEntry" :depends-on ("_package"))
    (:file "DogState" :depends-on ("_package_DogState"))
    (:file "_package_DogState" :depends-on ("_package"))
    (:file "GestureReq" :depends-on ("_package_GestureReq"))
    (:file "_package_GestureReq" :depends-on ("_package"))
    (:file "PercCmd" :depends-on ("_package_PercCmd"))
    (:file "_package_PercCmd" :depends-on ("_package"))
    (:file "PercReq" :depends-on ("_package_PercReq"))
    (:file "_package_PercReq" :depends-on ("_package"))
    (:file "PercState" :depends-on ("_package_PercState"))
    (:file "_package_PercState" :depends-on ("_package"))
    (:file "TaskList" :depends-on ("_package_TaskList"))
    (:file "_package_TaskList" :depends-on ("_package"))
  ))