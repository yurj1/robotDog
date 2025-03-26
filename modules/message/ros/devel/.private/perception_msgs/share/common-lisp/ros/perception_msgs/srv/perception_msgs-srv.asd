
(cl:in-package :asdf)

(defsystem "perception_msgs-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "RecordBag" :depends-on ("_package_RecordBag"))
    (:file "_package_RecordBag" :depends-on ("_package"))
  ))