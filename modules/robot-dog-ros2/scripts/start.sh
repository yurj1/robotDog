#!/bin/bash
work_path=/home/meizan/workspace/athena-robot-dog/modules/robot-dog-ros2
source ${work_path}/../message/ros/devel/setup.bash
roslaunch perception_msgs perception_bridge_msg.launch
cd ${work_path}/bin;
./robot_dog_app;
