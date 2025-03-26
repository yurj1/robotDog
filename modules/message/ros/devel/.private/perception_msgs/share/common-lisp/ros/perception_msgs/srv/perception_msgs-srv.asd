
(cl:in-package :asdf)

(defsystem "perception_msgs-srv"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "DogRecordBag" :depends-on ("_package_DogRecordBag"))
    (:file "_package_DogRecordBag" :depends-on ("_package"))
  ))