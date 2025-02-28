
#include <ros/ros.h>

#include "apps/global_project.h"
#include "robot_dog_state_manager.h"
#include "mode/factory.hpp"

RobotDogState::RobotDogState()
    : m_taskType(TaskType::TASK_NONE)
    , m_can_finish(true)
    , m_mutex()
{
    Init();
}

TaskState RobotDogState::GetState()
{
    return (TaskState)perc_state_.exe_state;
}

TaskResult RobotDogState::GetResult()
{
    return (TaskResult)perc_state_.exe_result;
}

void RobotDogState::Init()
{
    //状态反馈初始化
    perc_state_.action_id = 0;
    perc_state_.err_code = 0;
    perc_state_.exe_result = 0;

    m_can_finish = true;
}

void RobotDogState::SetCanFinish(const bool& enable)
{
    if(m_can_finish != enable)
        m_can_finish = enable;
}

bool RobotDogState::GetCanFinish()
{
    return m_can_finish;
}

const perception_msgs::TaskList& RobotDogState::GetOutputPlanning()
{
    return task_list_planning_;
}

const perception_msgs::PercState& RobotDogState::GetConstStateMsg()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    return perc_state_;
}

perception_msgs::PercState& RobotDogState::GetStateMsg()
{
    std::lock_guard<std::mutex> lock(m_mutex);
    return perc_state_;
}
/*
bool RobotDogState::getPose(const std::string& point_name, geometry_msgs::Pose& pose) {
    const auto& point_map = AfjGetMain()->GetPointMap();
    auto it = point_map.find(point_name);
    if (it != point_map.end()) {
        pose = it->second;
        return true;
    }
    ROS_ERROR("Point name not found: %s", point_name.c_str());
    return false;
}
//取消任务
void RobotDogState::CancelTask() {
    Init();
    task_list_perception_.task_type = perception_bridge::TaskType::TASK_CANCEL;
    perc_state_.perc_kind = perception_msgs::PercState::PERC_CANCEL;
    ROS_INFO("Cancel Task");
    AfjGetMain()->PublishTaskList(task_list_perception_);
}
//前往固定点任务
void RobotDogState::GoDest(const perception_msgs::PercCmd::ConstPtr& msg) {
    SetCanFinish(true);
    task_list_planning_.task_type = perception_bridge::TaskType::TASK_PRECISE_DOCKING;
    perc_state_.perc_kind = perception_msgs::PercState::PERC_DEST;
    std::string point_name = msg->point_name;
    geometry_msgs::Pose pose;
    if (this->getPose(point_name, pose)) {
    ROS_INFO("Pose for %s:", point_name.c_str());
    ROS_INFO("  Position: x=%f, y=%f, z=%f", 
            pose.position.x, pose.position.y, pose.position.z);
    ROS_INFO("  Orientation: x=%f, y=%f, z=%f, w=%f", 
            pose.orientation.x, pose.orientation.y, 
            pose.orientation.z, pose.orientation.w);
    task_list_planning_.target_position = pose;

    AfjGetMain()->PublishPose(pose);
    } else {
        ROS_WARN("Point %s not found!", point_name.c_str());
        }
    AfjGetMain()->PublishTaskList(task_list_planning_);
}
//跟随任务
void RobotDogState::Follow(const perception_msgs::PercCmd::ConstPtr& msg) {
    SetCanFinish(false);
    task_list_perception_.task_type = perception_bridge::TaskType::TASK_FOLLOW;
    perc_state_.perc_kind = perception_msgs::PercState::PERC_FOLLOW;
    ROS_INFO("Follow %s:", msg->follow_name.c_str());
    AfjGetMain()->PublishTaskList(task_list_perception_);
}
//欢迎任务
void RobotDogState::Welcome(const perception_msgs::PercCmd::ConstPtr& msg) {
    SetCanFinish(true);
    task_list_perception_.task_type = perception_bridge::TaskType::TASK_WELCOME;
    perc_state_.perc_kind = 61;
    ROS_INFO("Welcome %s:", msg->follow_name.c_str());
    AfjGetMain()->PublishTaskList(task_list_perception_);
}
//找人任务
void RobotDogState::GoDestAndFindTarget(const perception_msgs::PercCmd::ConstPtr& msg)
{
    SetCanFinish(false);
    task_list_perception_.task_type = perception_bridge::TaskType::TASK_LOBBY;
    task_list_planning_.task_type = perception_bridge::TaskType::TASK_NAVIGATION;
    perc_state_.perc_kind = 62;
    std::string point_name = msg->point_name;
    geometry_msgs::Pose pose;
    if (this->getPose(point_name, pose)) {
        ROS_INFO("Pose for %s:", point_name.c_str());
        ROS_INFO("  Position: x=%f, y=%f, z=%f", 
                pose.position.x, pose.position.y, pose.position.z);
        ROS_INFO("  Orientation: x=%f, y=%f, z=%f, w=%f", 
                pose.orientation.x, pose.orientation.y, 
                pose.orientation.z, pose.orientation.w);
        
        AfjGetMain()->PublishPose(pose);
    } else {//固定点坐标赋值
        ROS_INFO("Point %s not found! Get Point value", point_name.c_str());
        pose.position.x = msg->point.x;
        pose.position.y = msg->point.y;
        pose.position.z = msg->point.z;
    }//不是固定点则坐标赋值
    task_list_planning_.target_position = pose;
    task_list_planning_.isInPlaceRotation = true;
    if(AfjGetMainNotNull){
        AfjGetMain()->PublishTaskList(task_list_perception_);
        AfjGetMain()->PublishTaskList(task_list_planning_);
    }
    else
        AERROR << "main is nullptr";
    ROS_INFO("Find %s:", msg->follow_name.c_str());
}
*/
void RobotDogState::handleTaskEvent(const perception_msgs::PercCmd::ConstPtr& msg)
{
    ROS_INFO("Received PercCmd: action_id=%lu, perc_kind=%u", msg->action_id, msg->perc_kind);

    Init();
    std::shared_ptr<ModeBase> mode;
    
    mode = Factory::CreateModeFactory(msg->perc_kind);
        if(mode == nullptr)
        {
            AERROR << "Not find mode";
            return;
        }
        mode->Handle(msg, this);
}

void RobotDogState::handlePerceptionEvent(const perception_msgs::TaskList::ConstPtr& msg)
{
    ROS_INFO("Received TaskPt: task_type=%u, x=%f, y=%f, z=%f target_object=%s",
                  msg->task_type, msg->target_position.position.x,  msg->target_position.position.y,  msg->target_position.position.z, msg->target_object.c_str());

    geometry_msgs::Pose pose;
    pose.position.x = msg->target_position.position.x;
    pose.position.y = msg->target_position.position.y;
    pose.position.z = msg->target_position.position.z;
    pose.orientation.x = msg->target_position.orientation.x;
    pose.orientation.y = msg->target_position.orientation.y;
    pose.orientation.z = msg->target_position.orientation.z;
    pose.orientation.w = msg->target_position.orientation.w;
    
    switch (msg->task_type)
    {
    case perception_bridge::TaskType::TASK_FOLLOW://跟随任务
    case perception_bridge::TaskType::TASK_WELCOME://欢迎任务
        task_list_planning_.task_type = perception_bridge::TaskType::TASK_NAVIGATION;
        task_list_planning_.target_position = pose;
        if(AfjGetMainNotNull)
        {
            AfjGetMain()->PublishPose(pose);
            AfjGetMain()->PublishTaskList(task_list_planning_);
        }
        else
            std::cout << "main is null" << std::endl;
        
        break;
    case perception_bridge::TaskType::TASK_LOBBY://找人任务
        ROS_INFO("Find target suceess!");
        SetCanFinish(true);

        task_list_planning_.isInPlaceRotation = false;
        task_list_planning_.task_type = perception_bridge::TaskType::TASK_NAVIGATION;
        task_list_planning_.target_position = pose;

        if(AfjGetMainNotNull)
        {
            AfjGetMain()->PublishPose(pose);
            AfjGetMain()->PublishTaskList(task_list_planning_);
        }
        else
            AERROR << "main is nullptr";
        break;
    default:
        break;
    }
}

void RobotDogState::handleStateEvent(const perception_msgs::TaskList::ConstPtr& msg)
{
    
    //特殊状态下不切换为完成状态
    if(!m_can_finish && (uint8_t)msg->task_state == TaskState::STATE_COMPLETED){
        ROS_INFO("Special task not Done");
        return;
    }

    if(perc_state_.exe_state != (uint8_t)msg->task_state || perc_state_.exe_result != (uint8_t)msg->task_result) {
        std::lock_guard<std::mutex> lock(m_mutex);
        ROS_INFO("Recv  change state: [%d]-> [%d], result: [%d] -> [%d]", perc_state_.exe_state, (uint8_t)msg->task_state , perc_state_.exe_result, (uint8_t)msg->task_result);

        perc_state_.exe_state = static_cast<uint8_t>(msg->task_state);
        perc_state_.exe_result = static_cast<uint8_t>(msg->task_result);

        /* switch (m_currentState)
        {
        case STATE_IDLE:
            perc_state_.exe_state = perception_msgs::PercState::ACTION_IDLE;
            break;
        case STATE_RUNNING:
            perc_state_.exe_state = perception_msgs::PercState::ACTION_RUNNING;
            break;
        case STATE_COMPLETED:
            perc_state_.exe_state = perception_msgs::PercState::ACTION_DONE;
            break;
        default:
            break;
        }

        switch (m_currentResult)
        {
        case RESULT_INVALID:
            perc_state_.exe_result = perception_msgs::PercState::ACTION_NONE;
            break;
        case RESULT_SUCCESS:
            perc_state_.exe_result = perception_msgs::PercState::ACTION_SUCCESS;
            break;
        case RESULT_FAILED:
            perc_state_.exe_result = perception_msgs::PercState::ACTION_FAIL;
            break;
        default:
            break;
        } */
    }
}
