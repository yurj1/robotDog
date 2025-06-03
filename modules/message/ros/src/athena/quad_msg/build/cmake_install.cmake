# Install script for directory: /home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/install")
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

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/install/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/install" TYPE PROGRAM FILES "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/build/catkin_generated/installspace/_setup_util.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/install/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/install" TYPE PROGRAM FILES "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/build/catkin_generated/installspace/env.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/install/setup.bash;/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/install/local_setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/install" TYPE FILE FILES
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/build/catkin_generated/installspace/setup.bash"
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/build/catkin_generated/installspace/local_setup.bash"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/install/setup.sh;/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/install/local_setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/install" TYPE FILE FILES
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/build/catkin_generated/installspace/setup.sh"
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/build/catkin_generated/installspace/local_setup.sh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/install/setup.zsh;/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/install/local_setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/install" TYPE FILE FILES
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/build/catkin_generated/installspace/setup.zsh"
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/build/catkin_generated/installspace/local_setup.zsh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/install/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/install" TYPE FILE FILES "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/build/catkin_generated/installspace/.rosinstall")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/quad_msgs/msg" TYPE FILE FILES
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/src/msg/BodyForceEstimate.msg"
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/src/msg/RobotState.msg"
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/src/msg/BodyState.msg"
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/src/msg/GRFArray.msg"
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/src/msg/RobotPlan.msg"
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/src/msg/RobotPlanDiagnostics.msg"
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/src/msg/FootState.msg"
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/src/msg/MultiFootState.msg"
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/src/msg/MultiFootPlanContinuous.msg"
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/src/msg/FootPlanDiscrete.msg"
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/src/msg/MultiFootPlanDiscrete.msg"
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/src/msg/LegContactMode.msg"
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/src/msg/ContactMode.msg"
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/src/msg/MotorCommand.msg"
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/src/msg/LegCommand.msg"
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/src/msg/LegCommandArray.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/quad_msgs/cmake" TYPE FILE FILES "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/build/catkin_generated/installspace/quad_msgs-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/devel/include/quad_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/devel/share/roseus/ros/quad_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/devel/share/common-lisp/ros/quad_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/devel/share/gennodejs/ros/quad_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python3" -m compileall "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/devel/lib/python3/dist-packages/quad_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python3/dist-packages" TYPE DIRECTORY FILES "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/devel/lib/python3/dist-packages/quad_msgs")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/build/catkin_generated/installspace/quad_msgs.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/quad_msgs/cmake" TYPE FILE FILES "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/build/catkin_generated/installspace/quad_msgs-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/quad_msgs/cmake" TYPE FILE FILES
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/build/catkin_generated/installspace/quad_msgsConfig.cmake"
    "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/build/catkin_generated/installspace/quad_msgsConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/quad_msgs" TYPE FILE FILES "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/src/package.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/build/gtest/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/ys/Documents/dog/vis_flashocc1220_ys/vis_flashocc_bak/quad_msg/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
