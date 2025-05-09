#include "lobby_mode.h"
#include "common/public_fun.h"
#include "robot_dog_main.h"

using namespace athena::function::action;

LobbyMode::LobbyMode(TaskType type)
  : ModeBase(type)
{
}

void LobbyMode::Handle(const robot_dog::PercCmd& msg, MessageHandleManager* data_manager)
{
    robot_dog::TaskList task_list_perception_;
    robot_dog::TaskList task_list_planning_;
    //状态更新
    {
        auto& stateResult = data_manager->GetStateMsg();
        stateResult.perc_kind = robot_dog::operations::PercCmd::PERC_LOBBY_DEMO;
        stateResult.action_id = msg.action_id;
    }//赋值完立马释放锁
    //id更新,目标名称赋值
    task_list_perception_.task_id = task_list_planning_.task_id = msg.action_id;
    task_list_perception_.target_object = msg.follow_name;

    //特殊模式，不能直接完成
    data_manager->SetCanFinish(false);
    
    task_list_perception_.task_type = robot_dog::operations::TaskType::TASK_LOBBY;
    task_list_planning_.task_type = robot_dog::operations::TaskType::TASK_NAVIGATION;
    //前往固定点，到达终点时，需要打转
    task_list_planning_.is_in_place_rotation = true;
    
    //获取固定点坐标
    std::string point_name = msg.point_name;
    auto getPose = [](const std::string& point_name, robot_dog::Position& pose){
        const auto& point_map = AfxGetApp()->GetPointMap();
        auto it = point_map.find(point_name);
        if (it != point_map.end()) {
            pose = it->second;
            return true;
        }
        printf("Point name not found: %s", point_name.c_str());
        return false;
    };
    robot_dog::Position pose;
    //固定点坐标赋值,不是固定点则坐标赋值
    if (getPose(point_name, pose)) {
        printf("Pose for %s:", point_name.c_str());
        printf("  Position: x=%f, y=%f, z=%f", 
                pose.x, pose.y, pose.z);
        printf("  Orientation: x=%f, y=%f, z=%f, w=%f", 
                pose.q_x, pose.q_y, 
                pose.q_z, pose.q_w);
        
        AfxGetApp()->PublishPose(pose);
    } else {
        printf("Point %s not found! Get Point value", point_name.c_str());
        pose.x = msg.point.x;
        pose.y = msg.point.y;
        pose.z = msg.point.z;
    }

    task_list_planning_.target_position = pose;
    
    if(AppIsNotNull){
        AfxGetApp()->PublishTaskList(task_list_perception_);
        AfxGetApp()->PublishTaskList(task_list_planning_);
    }
    else
        AERROR << "main is nullptr";
    printf("Find %s:", msg.follow_name.c_str());
}