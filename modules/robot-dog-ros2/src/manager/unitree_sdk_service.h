#ifndef __UNITREE_SDK_SERVICE_H__
#define __UNITREE_SDK_SERVICE_H__

#include <unitree/idl/go2/UwbState_.hpp>
#include <unitree/idl/go2/SportModeState_.hpp>
#include <unitree/robot/channel/channel_subscriber.hpp>
#include <unitree/robot/go2/sport/sport_client.hpp>
#include <unitree/robot/go2/obstacles_avoid/obstacles_avoid_client.hpp>
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

    const robot_dog::Pose& GetOwnerPose(); // 获取主人坐标，朝向
    void FaceOwner();       //面向主人模式开始
    void FaceOwnerStop();
    int PerformingAcrtion(const robot_dog::operations::DogMition& action);
    int MoveToAbsolutePosition(const robot_dog::Position& pose);
    void ObstaclesMoveStop();
    void PrintState();
    robot_dog::Position GetDogPose(){ return robot_dog_posiotn_; }
    bool DogIsStop(){return vx_ < 0.05 && vy_ == 0.05 && vz_ == 0.05;}
private:
    void UwbStateHandler(const void* message);
    void UnitreeDogStateHandler(const void* message);
    bool IsVaildPose(robot_dog::Pose pose);
    
private:
    //创建一个 uwb Subscriber
    unitree::robot::ChannelSubscriber<unitree_go::msg::dds_::UwbState_>* uwb_suber_;
    //创建一个state Subscriber
    unitree::robot::ChannelSubscriber<unitree_go::msg::dds_::SportModeState_>* sportmodestate_suber_;
    //创建sport client对象
    unitree::robot::go2::SportClient* sport_client_;
    //具有避障功能的移动类
    unitree::robot::go2::ObstaclesAvoidClient* obstacles_client_;

    std::string networkInterface_;
    robot_dog::Pose owner_pose_;
    robot_dog::Position robot_dog_posiotn_;
    //unitree_go::msg::dds_::UwbState_ uwbStateInfo_;
    unitree_go::msg::dds_::SportModeState_ dogStateInfo_;
    std::mutex mutex_;
    std::atomic<bool> is_owner_follow;
    float vx_;
    float vy_;
    float vz_;
};













#endif // __UNITREE_SERVICE_H__