#/bin/bash
source /home/meizan/workspace/athena-robot-dog/modules/message/ros/devel/setup.bash
roslaunch perception_msgs perception_bridge_msg.launch
cd bin;
./robot_dog_app;
