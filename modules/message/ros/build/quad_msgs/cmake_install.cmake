# Install script for directory: /home/meizan/workspace/athena-robot-dog/modules/message/ros/src/athena/quad_msg/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/meizan/workspace/athena-robot-dog/modules/message/ros/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/meizan/workspace/athena-robot-dog/modules/message/ros/install/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/meizan/workspace/athena-robot-dog/modules/message/ros/install" TYPE PROGRAM FILES "/home/meizan/workspace/athena-robot-dog/modules/message/ros/build/quad_msgs/catkin_generated/installspace/_setup_util.py")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/meizan/workspace/athena-robot-dog/modules/message/ros/install/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/meizan/workspace/athena-robot-dog/modules/message/ros/install" TYPE PROGRAM FILES "/home/meizan/workspace/athena-robot-dog/modules/message/ros/build/quad_msgs/catkin_generated/installspace/env.sh")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/meizan/workspace/athena-robot-dog/modules/message/ros/install/setup.bash;/home/meizan/workspace/athena-robot-dog/modules/message/ros/install/local_setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/meizan/workspace/athena-robot-dog/modules/message/ros/install" TYPE FILE FILES
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/build/quad_msgs/catkin_generated/installspace/setup.bash"
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/build/quad_msgs/catkin_generated/installspace/local_setup.bash"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/meizan/workspace/athena-robot-dog/modules/message/ros/install/setup.sh;/home/meizan/workspace/athena-robot-dog/modules/message/ros/install/local_setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/meizan/workspace/athena-robot-dog/modules/message/ros/install" TYPE FILE FILES
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/build/quad_msgs/catkin_generated/installspace/setup.sh"
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/build/quad_msgs/catkin_generated/installspace/local_setup.sh"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/meizan/workspace/athena-robot-dog/modules/message/ros/install/setup.zsh;/home/meizan/workspace/athena-robot-dog/modules/message/ros/install/local_setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/meizan/workspace/athena-robot-dog/modules/message/ros/install" TYPE FILE FILES
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/build/quad_msgs/catkin_generated/installspace/setup.zsh"
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/build/quad_msgs/catkin_generated/installspace/local_setup.zsh"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/meizan/workspace/athena-robot-dog/modules/message/ros/install/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/meizan/workspace/athena-robot-dog/modules/message/ros/install" TYPE FILE FILES "/home/meizan/workspace/athena-robot-dog/modules/message/ros/build/quad_msgs/catkin_generated/installspace/.rosinstall")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/quad_msgs/msg" TYPE FILE FILES
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/src/athena/quad_msg/src/msg/BodyForceEstimate.msg"
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/src/athena/quad_msg/src/msg/RobotState.msg"
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/src/athena/quad_msg/src/msg/BodyState.msg"
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/src/athena/quad_msg/src/msg/GRFArray.msg"
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/src/athena/quad_msg/src/msg/RobotPlan.msg"
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/src/athena/quad_msg/src/msg/RobotPlanDiagnostics.msg"
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/src/athena/quad_msg/src/msg/FootState.msg"
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/src/athena/quad_msg/src/msg/MultiFootState.msg"
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/src/athena/quad_msg/src/msg/MultiFootPlanContinuous.msg"
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/src/athena/quad_msg/src/msg/FootPlanDiscrete.msg"
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/src/athena/quad_msg/src/msg/MultiFootPlanDiscrete.msg"
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/src/athena/quad_msg/src/msg/LegContactMode.msg"
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/src/athena/quad_msg/src/msg/ContactMode.msg"
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/src/athena/quad_msg/src/msg/MotorCommand.msg"
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/src/athena/quad_msg/src/msg/LegCommand.msg"
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/src/athena/quad_msg/src/msg/LegCommandArray.msg"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/quad_msgs/cmake" TYPE FILE FILES "/home/meizan/workspace/athena-robot-dog/modules/message/ros/build/quad_msgs/catkin_generated/installspace/quad_msgs-msg-paths.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/meizan/workspace/athena-robot-dog/modules/message/ros/devel/.private/quad_msgs/include/quad_msgs")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/meizan/workspace/athena-robot-dog/modules/message/ros/devel/.private/quad_msgs/share/roseus/ros/quad_msgs")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/meizan/workspace/athena-robot-dog/modules/message/ros/devel/.private/quad_msgs/share/common-lisp/ros/quad_msgs")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/meizan/workspace/athena-robot-dog/modules/message/ros/devel/.private/quad_msgs/share/gennodejs/ros/quad_msgs")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python3" -m compileall "/home/meizan/workspace/athena-robot-dog/modules/message/ros/devel/.private/quad_msgs/lib/python3/dist-packages/quad_msgs")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3/dist-packages" TYPE DIRECTORY FILES "/home/meizan/workspace/athena-robot-dog/modules/message/ros/devel/.private/quad_msgs/lib/python3/dist-packages/quad_msgs")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/meizan/workspace/athena-robot-dog/modules/message/ros/build/quad_msgs/catkin_generated/installspace/quad_msgs.pc")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/quad_msgs/cmake" TYPE FILE FILES "/home/meizan/workspace/athena-robot-dog/modules/message/ros/build/quad_msgs/catkin_generated/installspace/quad_msgs-msg-extras.cmake")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/quad_msgs/cmake" TYPE FILE FILES
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/build/quad_msgs/catkin_generated/installspace/quad_msgsConfig.cmake"
    "/home/meizan/workspace/athena-robot-dog/modules/message/ros/build/quad_msgs/catkin_generated/installspace/quad_msgsConfig-version.cmake"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/quad_msgs" TYPE FILE FILES "/home/meizan/workspace/athena-robot-dog/modules/message/ros/src/athena/quad_msg/src/package.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/meizan/workspace/athena-robot-dog/modules/message/ros/build/quad_msgs/gtest/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  if(CMAKE_INSTALL_COMPONENT MATCHES "^[a-zA-Z0-9_.+-]+$")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
  else()
    string(MD5 CMAKE_INST_COMP_HASH "${CMAKE_INSTALL_COMPONENT}")
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INST_COMP_HASH}.txt")
    unset(CMAKE_INST_COMP_HASH)
  endif()
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
  file(WRITE "/home/meizan/workspace/athena-robot-dog/modules/message/ros/build/quad_msgs/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
