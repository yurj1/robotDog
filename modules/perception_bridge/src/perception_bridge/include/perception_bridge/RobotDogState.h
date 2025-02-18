#ifndef __ROBOT_DOG_STATE_H__
#define __ROBOT_DOG_STATE_H__
#include <perception_bridge/enum.h>

using namespace perception_bridge;
//状态机切换
class RobotDogState
{
public:
    RobotDogState();

    TaskState GetState();
    TaskResult GetResult();
    void Clear();
    void SetCanFinish(const bool& enable);
    bool GetCanFinish();
    void handleTaskEvent(const TaskType& event);
    void handleStateEvent(const TaskState& state, const TaskResult& result);
private:
    TaskType m_taskType;
    TaskState m_currentState;
    TaskResult m_currentResult;
    bool m_can_finish;
};

#endif //__ROBOT_DOG_STATE_H__