#ifndef PERCEPTION_BRIDGE_COMMON_STRUCT_H
#define PERCEPTION_BRIDGE_COMMON_STRUCT_H
#include <iostream>

typedef struct tag_perc_cmd
{
//感知命令类型
int perc_kind;
uint64_t req_id;

// 跟随开关
/* uint32_t FOLLOW_ON  = 1
uint32 FOLLOW_OFF = 2 */
uint32_t on_off;
std::string follow_name;

// 目标角度
float angle;

// 字符串表示某个位置
std::string point_name;

// Point表示某个位置
_Float64 x;
_Float64 y;
_Float64 z;

}PercCmd, *PPercCmd;

typedef struct tag_perc_state
{
// 感知类型
uint32_t perc_kind;
// 执行状态：空闲/正在执行/执行完成
uint8_t exe_state;
// 执行结果：无效/成功/失败
uint8_t exe_result;

// 错误码
uint16_t err_code;
// 错误消息
std::string err_info;
// 剩余执行时间
uint64_t wait_for_millisec;

}PercState, *PPercState;

typedef struct tag_task_list
{
    // Task Id
uint64_t task_id;

// Task Type
uint32_t task_type;

// Target Position
//geometry_msgs/Pose target_position

// Target Object
std::string target_object;

// Task State
uint8_t task_state;

// Task Result
uint8_t task_result;
}TaskList, *PTaskList;

#endif //PERCEPTION_BRIDGE_COMMON_STRUCT_H