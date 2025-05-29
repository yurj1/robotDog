#ifndef __UNITREE_SDK_SERVICE_H__
#define __UNITREE_SDK_SERVICE_H__

#include <unitree/idl/go2/UwbState_.hpp>
#include <unitree/idl/go2/SportModeState_.hpp>
#include <unitree/robot/channel/channel_subscriber.hpp>
#include <unitree/robot/channel/channel_publisher.hpp>
#include <unitree/robot/go2/sport/sport_client.hpp>
#include <unitree/robot/go2/obstacles_avoid/obstacles_avoid_client.hpp>
#include <unitree/ros2_idl/QtCommand_.hpp>
#include "common/struct/CommonStruct.h"

#include <atomic>
#include <mutex>
#include <cstring>

class UnitreeSdkService
{
public:
    UnitreeSdkService(std::string networkInterface = "");
    ~UnitreeSdkService();
    void Init();

    const robot_dog::UwbState& GetUwbState(){ return uwb_state_; }
    const robot_dog::Pose& GetOwnerPose(); // 获取主人坐标，朝向
    void FaceOwner();       //面向主人模式开始
    void FaceOwnerStop();
    int PerformingAcrtion(const robot_dog::operations::DogMition& action);
    int MoveToAbsolutePosition(const robot_dog::Position& pose);
    int MoveOnObstaclesAvoid(float vx, float vy, float vw);
    int ObstaclesMoveStop();
    //单点导航
    void SingleNav(int node_edge_name_);
    //暂停导航
    void StopNav();
    void PrintState();
private:
    void UwbStateHandler(const void* message);
    void UnitreeDogStateHandler(const void* message);
    void NoticeHandler(const void *message);
    bool IsVaildPose(robot_dog::Pose pose);
    float GetRotationAngleInRadians(const robot_dog::Quaternion& q);
    
private:
    //创建一个 uwb Subscriber
    unitree::robot::ChannelSubscriber<unitree_go::msg::dds_::UwbState_>* uwb_suber_;
    //创建一个state Subscriber
    unitree::robot::ChannelSubscriber<unitree_go::msg::dds_::SportModeState_>* sportmodestate_suber_;
    //创建一个nav callback Subscriber
    unitree::robot::ChannelSubscriber<std_msgs::msg::dds_::String_>* subQtNotice;
    //创建一个slam node 发布对象
    unitree::robot::ChannelPublisher<unitree_interfaces::msg::dds_::QtCommand_>* conmmand_puber_;
    //创建sport client对象
    unitree::robot::go2::SportClient* sport_client_;
    //具有避障功能的移动类
    unitree::robot::go2::ObstaclesAvoidClient* obstacles_client_;

    std::string networkInterface_;
    unitree_go::msg::dds_::SportModeState_ dogStateInfo_;
    robot_dog::UwbState     uwb_state_;
    std::atomic<bool> is_owner_follow;
    static int nav_index_;
};













#endif // __UNITREE_SERVICE_H__