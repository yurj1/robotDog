#ifndef COMMON_STRUCT_H
#define COMMON_STRUCT_H

#include <cstring>
#include <string>
#include <cstring>
#include <vector>

namespace robot_dog {
    typedef struct tagPosistion
    {
        float x;
        float y;
        float z;
        float q_x;
        float q_y;
        float q_z;
        float q_w;

        tagPosistion() { memset(this, 0, sizeof(*this)); };
        tagPosistion(float x, float y, float z, float q_x= 0, float q_y= 0, float q_z= 0, float q_w = 0)
            : x(x), y(y), z(z), q_x(q_x), q_y(q_y), q_z(q_z), q_w(q_w) {  }
        // tagPosistion operator+(const tagPosistion &other) const
        // {
        //     return tagPosistion(x + other.x, y + other.y, theta + other.theta);
        // }
        // tagPosistion operator-(const tagPosistion &other) const
        // {
        //     return tagPosistion(x - other.x, y - other.y, theta - other.theta);
        // }
        // tagPosistion operator*(float value) const
        // {
        //     return tagPosistion(x * value, y * value, theta);
        // }
        // tagPosistion operator/(float value) const
        // {
        //     return tagPosistion(x / value, y / value, theta);
        // }
    }Position, *PPOSITION;

    typedef struct tagPose
        {
            float x;
            float y;
            float z;
            float theta;
        
            tagPose() { memset(this, 0, sizeof(*this)); }
            tagPose(float x, float y, float z, float theta) : x(x), y(y), z(z), theta(theta){}
        
            bool operator== (const tagPose& other)
            {
                return (x == other.x && y == other.y && z == other.z && theta == other.theta);
            }
        
            bool operator!= (const tagPose& other)
            {
                return !operator== (other);
            }
        
        }Pose, *PPose;

    typedef struct tagPoint {
        float x;
        float y;
        float z;

        tagPoint()
        : x(0.0), y(0.0), z(0.0){}
        tagPoint(float x, float y, float z)
        : x(x), y(y), z(z){}

        bool operator== (const tagPoint& other)
        {
            return x == other.x && y == other.y && z == other.z ;
        }

        bool operator!= (const tagPoint& other)
        {
            return ! operator==(other) ;
        }

    }Point, *PPoint;

    typedef struct tagPercCmd {
        uint64_t action_id;
        float angle;
        std::string follow_name;
        int on_off;
        uint32_t perc_kind;
        Point point;
        std::string point_name;
        int req_id;

        tagPercCmd():action_id(0),angle(0.0),follow_name(""),on_off(0),perc_kind(-1),point(),point_name(""),req_id(-1){}

    }PercCmd, *PPercCmd;

    typedef struct tagTaskList {
        uint64_t task_id;
        uint32_t task_type;
        Position target_position;
        std::string target_object;
        uint8_t task_state;
        uint8_t task_result;
        bool is_in_place_rotation;

        tagTaskList():task_id(0),task_type(0.0),target_position(),target_object(""),task_state(-1),task_result(),is_in_place_rotation(false){}

    }TaskList, *PTaskList;

    typedef struct tagPercState
    {
        // 当前执行的id
        uint64_t action_id;
        //感知类型
        uint32_t perc_kind;
        //执行状态：空闲/正在执行/执行完成
        uint8_t exe_state;
        //执行结果：无效/成功/失败
        uint8_t exe_result;
        // 错误码
        uint16_t err_code;
        // 错误消息
        std::string err_info;
        // 剩余执行时间
        uint64_t wait_for_millisec;

        tagPercState():perc_kind(0),exe_state(0),exe_result(0),err_code(0),err_info(""),wait_for_millisec(0){}
    }PercState, *PPercState;

    typedef struct tagActionEntry
    {
        // 动作id
        int  id;
        // 动作参数
        int  param1;
        int  param2;
        std::string param3;
        // 消息
        std::string info;
    }ActionEntry, PActionEntry;

    typedef struct tagRecordBag
    {
        uint8_t bag_mode;
        std::string bag_name;
        std::vector<std::string> topics;
        std::string bash_name;

        tagRecordBag()
        :bag_mode(0), bag_name(""), bash_name(""){}
    }RecordBag, *PRecordBag;

    typedef struct tagCallbackInfo
    {
        bool success;
        std::string info;

        tagCallbackInfo()
        :success(false), info(""){}
    }CallbackInfo, PCallbackInfo;

    typedef struct tagJoyInfo
    {
        std::vector<int> buttons;
        std::vector<float> axes;

        tagJoyInfo():buttons(),axes(){}
        tagJoyInfo(std::vector<int> v, std::vector<float> a):buttons(v),axes(a){
        }
        tagJoyInfo& operator=(const tagJoyInfo& other) {
            if (this == &other) {
                return *this;  // 防止自赋值
            }
            // 释放当前对象的资源
            buttons = other.buttons;
            axes = other.axes;

            return *this;
        }

        bool operator==(const tagJoyInfo& other) {
            if (this == &other) {
                return true;
            }
            if(buttons == other.buttons && axes == other.axes)
                return true;

            return false;
        }
        bool operator!=(const tagJoyInfo& other) {

            return ! operator==(other);
        }
        bool isEmpty()
        {
            if(buttons.empty() && axes.empty())
                return true;
            return false;
        }

    }JoyInfo, *PJoyInfo;

    typedef struct tagOrder
    {
        std::string order;

        tagOrder():order(""){}
        tagOrder(std::string order):order(order){}
    }Order, *POrder;

    typedef struct tagQuaternion
    {
        float x;
        float y;
        float z;
        float w;

        tagQuaternion():x(0), y(0), z(0), w(0){}
        tagQuaternion(float x, float y, float z, float w):x(x), y(y), z(z), w(w){}
    }Quaternion, *PQuaternion;

    typedef struct tagObuCmd
    {
        int code;
        int val;

        tagObuCmd():code(0), val(0){}
        tagObuCmd(int code, int val):code(code), val(val){}

    }ObuCmd, *PObuCmd;

    typedef struct tagObuCmdMsg
    {
        int id;
        std::string name;
        std::vector<ObuCmd> obu_cmd_list;

        tagObuCmdMsg():id(0), name(""){}
        tagObuCmdMsg(int id, std::string name, std::vector<ObuCmd> obu_cmd_list): id(id), name(name), obu_cmd_list(obu_cmd_list){}

    }ObuCmdMsg, *PObuCmdMsg;

    typedef struct tagEvent
    {
        uint64_t code;
        std::string reason;

        tagEvent():code(0), reason(""){}
        tagEvent(int code, std::string reason):code(code), reason(reason){}

    }Event, *PEvent;

    // 定义结构体
    typedef struct tagVelocity{
        float vx;  // X方向速度（前进/后退）
        float vy;  // 横移速度（左右移动）
        float vw;  // 转弯速度（角速度，如绕Z轴旋转）
        tagVelocity():vx(0), vy(0), vw(0){}
        tagVelocity(float vx, float vy, float vw):vx(vx), vy(vy), vw(vw){}
    }Velocity, *PVelocity;

    typedef struct tagUwbState {
        robot_dog::Pose owner_pose;     //主人基于狗的坐标
        int joy_mode;       //模式 （0-摇杆控制，1-行走跟踪，2-跑步跟踪，3-站起，4-趴下，5- 阻尼，6-侧滚，7-触发运动，8-站立）
        int error_state;     //错误码
        int buttons;        //按键模式
        bool enabled_from_app;      //APP是否打开跟踪（0为关闭，1为跟踪）

        tagUwbState():error_state(0), buttons(0), enabled_from_app(false){}
    }UwbState, *PUwbState;

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

        enum UsherDogState
        {
            DOG_IDLE = 0,
            DOG_USHER,
            DOG_FINISH 
        };

        enum TaskResult
        {
            RESULT_INVALID = 0,    // 无效
            RESULT_SUCCESS = 1,    // 成功
            RESULT_FAILED = 2,     // 失败
        };

        enum PercCmd
        {
            PERC_DEST = 1,
            PERC_CANCEL = 100,
            PERC_FOLLOW = 30,
            PERC_WELCOME_DEMO = 61,
            PERC_LOBBY_DEMO = 62,
            PERC_NODE_CLOSE = 200,
            PERC_NODE_START = 201,
            PERC_NODE_RESET = 202
        };

        enum DogMition
        {
            MORMAL_STAND = 1,       //正常站立
            BLANCE_STAND,          //平衡站立
            VELOCITyMOVE,          //速度控制
            TRAJECTORyFOLLOW,      //轨迹跟踪控制
            STAND_DOWN,             //趴下
            STAND_UP,               //站高
            DAMP,                   //阻尼模式 软急停
            RECOVERY_STAND,         //恢复站立

            SIT =101,               //坐下
            RISE_SIT,               //从坐下到恢复
            STRETCH,                //伸懒腰
            WALLOW,                 //打滚
            CONTENT,                //开心
            POSE,                   //摆姿势
            SCRAPE,                 //拜年作辑
            FRONT_FILP,             //前空翻
            FRONT_JUMP,             //前跳
            FRONT_POUNCE,           //向前仆人
            HELLO,                  //打招呼
            HEART,
            Dance1,                 //舞蹈1
            Dance2,                  //舞蹈2

            STOP_MOVE = 999         //停止运动
        };

        enum VocieCode
        {
            CODE_Action = 10010,    //接收动作指令
            CODE_ToDest = 10020,    //接收固定点指令

            CODE_PLAY_VIDEO = 20010 //播放音频
        };

        enum VoiceActionCommand
        {
            ACTION_STOP = 0,
            ACTION_HELLO,
            ACTION_SCRAPE
        };

        enum VoiceDestCommand
        {
            COMMAND_STOP = 0,
            COMMAND_GotoA,
            COMMAND_GotoB,
            COMMAND_GotoC,
            COMMAND_GotoD
        };

        enum AudioOrder
        {
            STOP_PLAY = 0,
            COMPANY_INTRODUCTION, //公司介绍
            ELEVATOR_ARRIVE,  //到达电梯口
            CONFERENCE_ROOM_ARRIVE, //到达会议室
            DRIVE_VEHICLE_ARRIVE, //到达行车产品线
            PARK_VEHICLE_ARRIVE //到达泊车产品线
        };
    }// namespace operations
}//namespaces robot_dog

#endif // !COMMON_STRUCT_H
