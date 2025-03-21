
#include <ros/ros.h>

#include "common/global_project.h"
#include "robot_dog_state_manager.h"
#include "factory/factory.h"

using namespace athena::function::action;

RobotDogState::RobotDogState()
    : m_can_finish(true)
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

    //规控数据初始化
    {
    task_list_planning_.task_id = 0;
    geometry_msgs::Pose pose;
    pose.position.x = 0;
    pose.position.y = 0;
    pose.position.z = 0;
    pose.orientation.x = 0;
    pose.orientation.y = 0;
    pose.orientation.z = 0;
    pose.orientation.w = 0;
    task_list_planning_.target_position = pose;
    task_list_planning_.target_object = "";
    task_list_planning_.task_state = robot_dog::operations::TaskState::STATE_IDLE;
    task_list_planning_.task_result = robot_dog::operations::TaskResult::RESULT_INVALID;
    task_list_planning_.isInPlaceRotation = false;
    }
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
    //std::lock_guard<std::mutex> lock(m_mutex);
    return perc_state_;
}

void RobotDogState::handleTaskEvent(const perception_msgs::PercCmd::ConstPtr& msg)
{
    ROS_INFO("Received PercCmd: action_id=%lu, perc_kind=%u", msg->action_id, msg->perc_kind);
    recv_cmd_msg_info_ = *msg;
    Init();
    
    std::shared_ptr<ModeBase> m_task = Factory::CreateModeFactory(msg->perc_kind);
        if(m_task == nullptr)
        {
            AERROR << "Not find mode";
            return;
        }
        m_task->Handle(msg, this);
}

void RobotDogState::handlePerceptionEvent(const perception_msgs::TaskList::ConstPtr& msg)
{
    ROS_INFO("Received TaskPt: task_type=%u, x=%f, y=%f, z=%f target_object=%s task_state=%u",
                  msg->task_type, msg->target_position.position.x,  msg->target_position.position.y,  msg->target_position.position.z, msg->target_object.c_str(), msg->task_state);

    static bool is_perception_error = false;

    geometry_msgs::Pose pose;
    pose.position.x = msg->target_position.position.x;
    pose.position.y = msg->target_position.position.y;
    pose.position.z = msg->target_position.position.z;
    pose.orientation.x = msg->target_position.orientation.x;
    pose.orientation.y = msg->target_position.orientation.y;
    pose.orientation.z = msg->target_position.orientation.z;
    pose.orientation.w = msg->target_position.orientation.w;
    
    perception_msgs::ActionEntry actionMsg;

    switch (msg->task_type)
    {
    case robot_dog::operations::TaskType::TASK_FOLLOW://跟随任务
    case robot_dog::operations::TaskType::TASK_WELCOME://欢迎任务
        if(msg->task_state == 2)//主人识别失败
        {
            if(is_perception_error) return;
            
            actionMsg.id = 1;
            actionMsg.info = "等等我";
            AfjGetMain()->PublishAction(actionMsg);

            is_perception_error = true;
            return;
        }
        //复位
        if(is_perception_error) is_perception_error = false;

        task_list_planning_.task_type = robot_dog::operations::TaskType::TASK_NAVIGATION;
        task_list_planning_.target_position = pose;
        if(AfjGetMainNotNull)
        {
            AfjGetMain()->PublishPose(pose);
            AfjGetMain()->PublishTaskList(task_list_planning_);
        }
        else
            std::cout << "main is null" << std::endl;
        
        break;
    case robot_dog::operations::TaskType::TASK_LOBBY://找人任务
        
        if(recv_cmd_msg_info_.follow_name == msg->target_object)
            ROS_INFO("Find target suceess!");
        else
            ROS_INFO("Find target fail target: [%s] -> recv: [%s]", recv_cmd_msg_info_.follow_name.c_str(), msg->target_object.c_str());
        
        SetCanFinish(true);

        task_list_planning_.task_type = robot_dog::operations::TaskType::TASK_NAVIGATION;
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
        AERROR << "recv not parse type";
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
