#include <perception_bridge/RobotDogState.h>
#include <ros/ros.h>

RobotDogState::RobotDogState()
    : m_taskType(TaskType::TASK_NONE)
    , m_currentState(TaskState::STATE_IDLE)
    , m_currentResult(TaskResult::RESULT_INVALID)
    , m_can_finish(true)
{}

TaskState RobotDogState::GetState()
{
    return m_currentState;
}

TaskResult RobotDogState::GetResult()
{
    return m_currentResult;
}

void RobotDogState::Clear()
{
    m_currentState = TaskState::STATE_IDLE;
    m_currentResult = TaskResult::RESULT_INVALID;
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

void RobotDogState::handleTaskEvent(const TaskType& event)
{
    if(m_taskType != event)
    {
        m_taskType = event;
        //特殊任务不能直接上报完成状态
        switch (event)
        {
        case TaskType::TASK_FOLLOW:
        case TaskType::TASK_LOBBY:
            m_can_finish = false;
            break;
        default:
            m_can_finish = true;
            break;
        }
    }
}

void RobotDogState::handleStateEvent(const TaskState& state,  const TaskResult& result)
{
    ROS_INFO("Recv state: [%d], result: [%d]", state, result);
    //特殊状态下不切换为完成状态
    if(!m_can_finish && state == TaskState::STATE_COMPLETED){
        ROS_INFO("Special task not Done");
        return;
    }
    if(m_currentState != state) m_currentState = state;
    if(m_currentResult != result) m_currentResult = result;
}

