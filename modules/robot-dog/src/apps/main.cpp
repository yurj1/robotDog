/**
 * @file    main.cpp
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#include <iostream>
#include <signal.h>

#include "global_project.h"

#if GLOG_ENABLE
#include <glog/logging.h>
#elif MDCLOG_ENABLEg
#include <ara/log/logging.h>
#endif

#if ROS_ENABLE
#include <ros/ros.h>
#endif

#if ROS2_ENABLE
#include "rclcpp/rclcpp.hpp"
#endif

using namespace std;
using namespace athena::function;
#ifndef G_TEST
int main(int argc, char** argv) {
  //std::string file_path = "./conf/function/robot-dog/robot_dog.json";
  system("mkdir -p log");
#if ROS_ENABLE
  ros::init(argc, argv, "robot_dog_app");
#endif

#if ROS2_ENABLE
  rclcpp::init(argc, argv);
#endif

#if GLOG_ENABLE
  google::InitGoogleLogging(argv[0]);
#endif

  // 创建 RobotDogMain 对象
    auto robotDog = AfjGetMain();
    if(robotDog != nullptr)
    {
      robotDog->Start();
      robotDog->Loop();
      robotDog->Close();
    }
    
  return 1;
}
#endif