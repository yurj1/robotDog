#include "dest_mode.h"
#include "common/global_project.h"

using namespace athena::function::action;

DestMode::DestMode(TaskType type)
  : ModeBase(type)
  , pubData_()
{
}

void DestMode::Init()
{
}

void DestMode::Handle(const perception_msgs::PercCmd::ConstPtr& msg, RobotDogState* data_manager)
{
    //可直接完成
    data_manager->SetCanFinish(true);
    

    //坐标
    geometry_msgs::Pose pose;
    //状态更新
    auto& stateResult = data_manager->GetStateMsg();
    stateResult.action_id = msg->action_id;
    stateResult.perc_kind = perception_msgs::PercState::PERC_DEST;

    auto getPose = [](const std::string& point_name, geometry_msgs::Pose& pose){
        const auto& point_map = AfjGetMain()->GetPointMap();
        auto it = point_map.find(point_name);
        if (it != point_map.end()) {
            pose = it->second;
            return true;
        }
        ROS_ERROR("Point name not found: %s", point_name.c_str());
        return false;
    };

    //类型赋值
    pubData_.task_id = msg->action_id;
    pubData_.task_type = robot_dog::operations::TaskType::TASK_PRECISE_DOCKING;
    std::string point_name = msg->point_name;
    
    //获取坐标
    if (getPose(point_name, pose)) {
    ROS_INFO("Pose for %s:", point_name.c_str());
    ROS_INFO("  Position: x=%f, y=%f, z=%f", 
            pose.position.x, pose.position.y, pose.position.z);
    ROS_INFO("  Orientation: x=%f, y=%f, z=%f, w=%f", 
            pose.orientation.x, pose.orientation.y, 
            pose.orientation.z, pose.orientation.w);
    pubData_.target_position = pose;

    AfjGetMain()->PublishPose(pose);
    } else {
        ROS_WARN("Point %s not found!", point_name.c_str());
        }
    AfjGetMain()->PublishTaskList(pubData_);
}