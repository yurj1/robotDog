#ifndef PERCEPTION_BRIDGE_ENUM_H
#define PERCEPTION_BRIDGE_ENUM_H

namespace perception_bridge {
    enum TaskType
    {
        TASK_CANCEL = 0,      // 取消任务
        TASK_NAVIGATION = 1,  // 导航任务
        TASK_FOLLOW = 2,      // 跟随任务
        TASK_WELCOME = 3,     // 欢迎任务
        TASK_LOBBY = 4,       // 找人任务
        TASK_NODE_CLOSE = 200, // 关闭感知规划模块
        TASK_NODE_START = 201, // 开启感知规划模块
        TASK_NODE_RESET = 202, // 重启感知规划模块

        TASK_NONE = 800, // 空任务
    };

    enum TaskState
    {
        STATE_IDLE = 0,        // 空闲
        STATE_RUNNING = 1,     // 执行中
        STATE_COMPLETED = 2,   // 完成
    };

    enum TaskResult
    {
        RESULT_INVALID = 0,    // 无效
        RESULT_SUCCESS = 1,    // 成功
        RESULT_FAILED = 2,     // 失败
    };
}

#endif  // PERCEPTION_BRIDGE_ENUM_H