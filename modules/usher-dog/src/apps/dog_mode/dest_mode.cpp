#include "dest_mode.h"
#include "common/public_fun.h"
#include "robot_dog_main.h"

using namespace athena::function::action;

DestMode::DestMode(TaskType type)
  : ModeBase(type)
  , pubData_()
{
}

void DestMode::Init()
{
}

void DestMode::Handle(const robot_dog::PercCmd& msg, MessageHandleManager* data_manager)
{
    //可直接完成
    data_manager->SetCanFinish(true);
    
    //坐标
    robot_dog::Position pose;
    //状态更新
    auto& stateResult = data_manager->GetStateMsg();
    stateResult.action_id = msg.action_id;
    stateResult.perc_kind = robot_dog::operations::PercCmd::PERC_DEST;

    auto getPose = [](const std::string& point_name, robot_dog::Position& pose){
        const auto& point_map = AfxGetApp()->GetPointMap();
        auto it = point_map.find(point_name);
        if (it != point_map.end()) {
            pose = it->second;
            return true;
        }
        printf("Point name not found: %s \n", point_name.c_str());
        return false;
    };

    //类型赋值
    pubData_.task_id = msg.action_id;
    pubData_.task_type = robot_dog::operations::TaskType::TASK_PRECISE_DOCKING;
    std::string point_name = msg.point_name;
    
    //获取坐标
    if (getPose(point_name, pose)) {
    printf("Pose for %s:", point_name.c_str());
    printf("  Position: x=%f, y=%f, z=%f", 
            pose.x, pose.y, pose.z);
    printf("  Orientation: x=%f, y=%f, z=%f, w=%f \n", 
            pose.q_x, pose.q_y, 
            pose.q_z, pose.q_w);
    pubData_.target_position = pose;

    AfxGetApp()->PublishPose(pose);
    } else {
        printf("Point %s not found! \n", point_name.c_str());
        }
    AfxGetApp()->PublishTaskList(pubData_);
}