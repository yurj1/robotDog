#include <perception_bridge/perception_bridge.h>

int main(int argc, char** argv) {
    // 初始化 ROS 节点
    ros::init(argc, argv, "perception_bridge_two_node");

    // 创建 RobotDogMain 对象
    RobotDogMain perception_bridge;

    ROS_INFO("perception bridge two node start!");

    perception_bridge.clear();

    // 进入 ROS 事件循环
    ros::spin();

    return 0;
}