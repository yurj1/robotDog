#ifndef PERCEPTION_BRIDGE_ENUM_H
#define PERCEPTION_BRIDGE_ENUM_H

namespace robot_dog {
    namespace operations {
        enum TaskType
        {
            TASK_NONE = 800, // 空任务

            //通用
            TASK_CANCEL = 0,            // 取消任务  (通用)
            TASK_NODE_CLOSE = 200,      // 关闭感知规划模块  (通用)
            TASK_NODE_START = 201,      // 开启感知规划模块  (通用)
            TASK_NODE_RESET = 202,      // 重启感知规划模块  (通用)

            //规划
            TASK_NAVIGATION = 1,        // 导航任务  (规划）
            TASK_PRECISE_DOCKING = 5,   //精准停靠 (规划）

            //感知
            TASK_FOLLOW = 2,            // 跟随任务  (集成)
            TASK_WELCOME = 3,           // 欢迎任务  (集成)
            TASK_LOBBY = 4,             // 找人任务  (集成)

            //手势
            PERC_HAND_OK = 401,         // （回到某点找人，地点和人是集成控制的）
            PERC_HAND_V     ,           //（拍照）
            PERC_HAND_SHAKE ,           // (握手)
            PERC_HAND_COME  ,           // (过来，集成收到请求以后，会进行判断是否执行该任务，如果执行会给感知规划下方命令)
            PERC_HAND_WAVE  ,           // (挥手)

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
}
    

#endif  // PERCEPTION_BRIDGE_ENUM_H