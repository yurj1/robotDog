
#include <ros/ros.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

#include "common/public_fun.h"
#include "robot_dog_main.h"
#include "message_handle_manager.h"
#include "factory/factory.h"

using namespace athena::function::action;

MessageHandleManager::MessageHandleManager()
    : m_can_finish(true)
    ,start_record_(false)
    ,recorder_pid_(-1)
    , mutex_()
{
    Init();
}

TaskState MessageHandleManager::GetState()
{
    return (TaskState)perc_state_.exe_state;
}

TaskResult MessageHandleManager::GetResult()
{
    return (TaskResult)perc_state_.exe_result;
}

void MessageHandleManager::Init()
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

void MessageHandleManager::SetCanFinish(const bool& enable)
{
    if(m_can_finish != enable)
        m_can_finish = enable;
}

bool MessageHandleManager::GetCanFinish()
{
    return m_can_finish;
}

const perception_msgs::TaskList& MessageHandleManager::GetOutputPlanning()
{
    return task_list_planning_;
}

const perception_msgs::PercState& MessageHandleManager::GetConstStateMsg()
{
    std::lock_guard<std::mutex> lock(mutex_);
    return perc_state_;
}

perception_msgs::PercState& MessageHandleManager::GetStateMsg()
{
    std::lock_guard<std::mutex> lock(mutex_);
    return perc_state_;
}

void MessageHandleManager::handlePerceptionEvent(const perception_msgs::TaskList::ConstPtr& msg)
{
    printf("Received TaskPt: task_type=%u, x=%f, y=%f, z=%f target_object=%s task_state=%u",
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
            actionMsg.info = "主人识别失败";
            AfxGetApp()->PublishAction(actionMsg);

            is_perception_error = true;
            return;
        }
        //复位
        if(is_perception_error) {
            is_perception_error = false;

            actionMsg.id = 0;
            actionMsg.info = "";
            AfxGetApp()->PublishAction(actionMsg);
        }

        task_list_planning_.task_type = robot_dog::operations::TaskType::TASK_NAVIGATION;
        task_list_planning_.target_position = pose;
        if(AppIsNotNull)
        {
            AfxGetApp()->PublishPose(pose);
            AfxGetApp()->PublishTaskList(task_list_planning_);
        }
        else
            std::cout << "main is null" << std::endl;
        
        break;
    case robot_dog::operations::TaskType::TASK_LOBBY://找人任务
        
        if(recv_cmd_msg_info_.follow_name == msg->target_object)
            printf("Find target suceess!");
        else
            printf("Find target fail target: [%s] -> recv: [%s]", recv_cmd_msg_info_.follow_name.c_str(), msg->target_object.c_str());
        
        SetCanFinish(true);

        task_list_planning_.task_type = robot_dog::operations::TaskType::TASK_NAVIGATION;
        task_list_planning_.target_position = pose;

        if(AppIsNotNull)
        {
            AfxGetApp()->PublishPose(pose);
            AfxGetApp()->PublishTaskList(task_list_planning_);
        }
        else
            AERROR << "main is nullptr";
        break;
    default:
        AERROR << "recv not parse type";
        break;
    }
}

void MessageHandleManager::handleStateEvent(const perception_msgs::TaskList::ConstPtr& msg)
{
    //特殊状态下不切换为完成状态
    if(!m_can_finish && (uint8_t)msg->task_state == TaskState::STATE_COMPLETED){
        printf("Special task not Done");
        return;
    }

    if(perc_state_.exe_state != (uint8_t)msg->task_state || perc_state_.exe_result != (uint8_t)msg->task_result) {
        std::lock_guard<std::mutex> lock(mutex_);
        printf("Recv  change state: [%d]-> [%d], result: [%d] -> [%d]", perc_state_.exe_state, (uint8_t)msg->task_state , perc_state_.exe_result, (uint8_t)msg->task_result);

        perc_state_.exe_state = static_cast<uint8_t>(msg->task_state);
        perc_state_.exe_result = static_cast<uint8_t>(msg->task_result);
    }
}

void MessageHandleManager::HandleJoyMsg(const robot_dog::JoyInfo& joy_msg)
{
    if(joy_msg_mqtt_input_ != joy_msg)
    {
        joy_msg_mqtt_input_ = joy_msg;
    }
    //   std::cout << joy_msg_mqtt_input_.axes(0) << std::endl;
       std::cout << "速度摇杆_a0[左右]: " << joy_msg_mqtt_input_.axes[0] << std::endl;//MA 左摇杆
       std::cout << "速度摇杆_a1:[上下]: " << joy_msg_mqtt_input_.axes[1] << std::endl;
    //   std::cout << "joy_msg_axes2_:" << joy_msg_mqtt_input_.axes(2) << std::endl;
       std::cout << "转弯摇杆_a3[左右]: " << joy_msg_mqtt_input_.axes[3] << std::endl;//MB 右摇杆 LEFT :1  RIGHT : -1
    //   std::cout << "joy_msg_axes4_:" << joy_msg_mqtt_input_.axes(4) << std::endl;
    //   std::cout << "joy_msg_axes5_:" << joy_msg_mqtt_input_.axes(5) << std::endl;
    //   std::cout << "joy_msg_axes6_:" << joy_msg_mqtt_input_.axes(6) << std::endl;
    //   std::cout << "joy_msg_axes7_:" << joy_msg_mqtt_input_.axes(7) << std::endl;
    //   std::cout << "joy_msg_buttons0_:" << joy_msg_mqtt_input_.buttons(0) << std::endl;
       std::cout << "B按键_b1: " << joy_msg_mqtt_input_.buttons[1] << std::endl;//B
    //   std::cout << "joy_msg_buttons2_:" << joy_msg_mqtt_input_.buttons(2) << std::endl;
    //   std::cout << "joy_msg_buttons3_:" << joy_msg_mqtt_input_.buttons(3) << std::endl;
       std::cout << "LB按键_b4: " << joy_msg_mqtt_input_.buttons[4] << std::endl;//LB
       std::cout << "RB按键_b5: " << joy_msg_mqtt_input_.buttons[5] << std::endl;//RB
    //   std::cout << "joy_msg_buttons6_:" << joy_msg_mqtt_input_.buttons(6) << std::endl;
       std::cout << "START按键: " << joy_msg_mqtt_input_.buttons[7] << std::endl;//START
    //   std::cout << "joy_msg_buttons8_:" << joy_msg_mqtt_input_.buttons(8) << std::endl;
       std::cout << "速度摇杆按下_b9:" << joy_msg_mqtt_input_.buttons[9] << std::endl;
       std::cout << "转弯摇杆按下_b10:" << joy_msg_mqtt_input_.buttons[10] << std::endl;
      if (joy_msg_mqtt_input_.buttons[7] == 1)//加载数据
      {
        //Joyload();
        std_msgs::Float32 msg;
        msg.data =  1.0;
        AfxGetApp()->PublishJoyMsgLoad(msg);
        return;
      }
      if(joy_msg_mqtt_input_.buttons[5] == 1&&joy_msg_mqtt_input_.buttons[9] == 1)// 站立
      {
        //Joystandup();
        std_msgs::Float32 msg;
        msg.data =  1.0;
        AfxGetApp()->PublishJoyMsgStandup(msg);
        return;
      }
      if(joy_msg_mqtt_input_.buttons[5] == 1&&joy_msg_mqtt_input_.buttons[10] == 1) // 趴下
      {
        //Joygetdown();
        std_msgs::Float32 msg;
        msg.data =  1.0;
        AfxGetApp()->PublishJoyMsgGetdown(msg);
        return;
      }
      if(joy_msg_mqtt_input_.buttons[5] == 1&&joy_msg_mqtt_input_.buttons[1] == 1) // 急停
      {
        //Joystop();
        std_msgs::Float32 msg;
        msg.data =  1.0;
        AfxGetApp()->PublishJoyMsgStop(msg);
        return;
      }

      if(joy_msg_mqtt_input_.buttons[4]==1) // 遥控机器狗
      {
        twist_.linear.x=joy_msg_mqtt_input_.axes[1];// VX
        twist_.linear.y=joy_msg_mqtt_input_.axes[0];// Vy
        twist_.angular.z=joy_msg_mqtt_input_.axes[3] * 2;//Vw   -2 ~ 2
      }
      else
      {
        twist_.linear.x=0;
        twist_.linear.y=0;
        twist_.angular.z=0.0;
      }
      AfxGetApp()->PublishJoyMsgTwist(twist_);
}

void MessageHandleManager::handleTaskEvent(const robot_dog::PercCmd& msg)
{
    printf("Received PercCmd: action_id=%lu, perc_kind=%u", msg.action_id, msg.perc_kind);
    //recv_cmd_msg_info_ = *msg;
    Init();
    
    std::shared_ptr<ModeBase> m_task = Factory::CreateModeFactory(msg.perc_kind);
        if(m_task == nullptr)
        {
            AERROR << "Not find mode";
            return;
        }
        m_task->Handle(msg, this);
}

bool MessageHandleManager::recordBagCallback(robot_dog::RecordBag &req, robot_dog::CallbackInfo &rsp)
{
  if(req.bag_mode == 0)//结束录包
  {
    if(start_record_)
    {
        // 停止录制
        if (recorder_pid_ != -1) {
            kill(recorder_pid_, SIGINT); // 安全终止信号
            printf("Sent SIGINT to rosbag process (PID: %d)", recorder_pid_);
            recorder_pid_ = -1;
        }

        start_record_ = false;
    }
    rsp.success = true;
    rsp.info = "已停止";
  }
  else if(req.bag_mode == 1 || req.bag_mode == 2) {
    if(start_record_ != -1)//没有正常点击停止，或双击
    {
        if(_isRunningChildren())//0代表仍在运行
        {
            rsp.success = false;
            rsp.info = "请先停止录包";
            return true;
        }
    }
    //创建管道用于进程通信
    int pipe_fd[2];
    if(pipe(pipe_fd) == -1)
    {
        rsp.success = false;
        rsp.info = "create pipe failed";
        return true;
    }

    if(req.bag_mode == 1)//自定义录包
    {
        pid_t pid = fork();
        if (pid == 0) { // 子进程
            // 将标准错误重定向到管道
            dup2(pipe_fd[1], STDERR_FILENO); // 关键修改！
            close(pipe_fd[0]);//close read
            
            std::vector<std::string> args;
            args.push_back("rosbag");
            args.push_back("record");
            args.push_back("-O");
            args.push_back(req.bag_name);
            for (const auto& topic : req.topics) {
                args.push_back(topic);
            }

            // 构造参数数组
            std::vector<char*> argv;
            for (auto& arg : args) {
                argv.push_back(&arg[0]);
            }
            argv.push_back(nullptr); // 参数数组以 nullptr 结尾

            // 使用 execvp 启动 rosbag
            //printf("Rosbag recording cmd: %s", argv;
            if(execvp("rosbag", argv.data()) == -1)
            {
                std::string error = "record failed: " + std::string(strerror(errno));
                write(pipe_fd[1], error.c_str(), error.length());
                close(pipe_fd[1]);
                exit(1);
            }
            exit(0); // 如果 execvp 失败，确保退出
        } 
        else if (pid > 0) { // 父进程
            recorder_pid_ = pid;

            close(pipe_fd[1]);//close write

            //非阻塞读取
            int flags = fcntl(pipe_fd[0], F_GETFL, 0);
            fcntl(pipe_fd[0], F_SETFL, flags | O_NONBLOCK);

            fd_set fds;
            struct timeval tv;
            FD_ZERO(&fds);
            FD_SET(pipe_fd[0],&fds);
            tv.tv_sec = 1;//超时1s
            tv.tv_usec = 0;
            //监听套接字
            int ret = select(pipe_fd[0] + 1, &fds, NULL, NULL, &tv);
            if(ret > 0)//有就绪的套接字了
            {
                char error[256];
                int n =read(pipe_fd[0], error, sizeof(error) - 1);
                close(pipe_fd[0]);

                if(n > 0) {
                    error[n] = '\0';
                    rsp.success = false;
                    rsp.info = error;

                    if(_isRunningChildren())
                    {
                        kill(pid, SIGINT); // 安全终止信号
                        printf("Sent SIGINT to rosbag process (PID: %d)", recorder_pid_);
                    }
                    recorder_pid_ = -1;
                    return true;
                }
            }

            start_record_ = true;
            printf("Rosbag recording started (PID: %d)", pid);
            rsp.success = true;
            rsp.info = "开始录包";
        }
        else {//进程创建失败
            close(pipe_fd[0]);
            close(pipe_fd[1]);
            rsp.success = false;
            rsp.info = "create fork failed";
        }
    }
    else if(req.bag_mode == 2) // 执行脚本
    {
        // 检查脚本是否存在
        if (access(req.bash_name.c_str(), F_OK) == -1) {
            std::string error = "Script not found: " + std::string(strerror(errno));
            rsp.success = false;
            rsp.info = error;
            return true;
        }

        pid_t pid = fork();
        if (pid == 0) { // 子进程
            // 将标准错误重定向到管道
            dup2(pipe_fd[1], STDERR_FILENO); // 关键修改！
            close(pipe_fd[0]);//close read
            
            std::vector<std::string> args;
            args.push_back("/bin/bash");
            args.push_back(req.bash_name);
            
            // 构造参数数组
            std::vector<char*> argv;
            for (auto& arg : args) {
                argv.push_back(&arg[0]);
            }
            argv.push_back(nullptr); // 参数数组以 nullptr 结尾

            // 使用 execvp 启动脚本
            printf("children start sh");
            if(execvp("/bin/bash", argv.data()) == -1)
            {
                printf("error start sh");
                std::string error = "record failed: " + std::string(strerror(errno));
                write(pipe_fd[1], error.c_str(), error.length());
                close(pipe_fd[1]);
                exit(1);
            }
            close(pipe_fd[1]);
            exit(0); // 如果 execvp 失败，确保退出
        }
        else if (pid > 0) { // 父进程
            close(pipe_fd[1]);//close write
            int flags = fcntl(pipe_fd[0], F_GETFL, 0);
            fcntl(pipe_fd[0], F_SETFL, flags | O_NONBLOCK);

            fd_set fds;
            struct timeval tv;
            FD_ZERO(&fds);
            FD_SET(pipe_fd[0],&fds);
            tv.tv_sec = 1;
            tv.tv_usec = 0;

            int ret = select(pipe_fd[0] + 1, &fds, NULL, NULL, &tv);
            if(ret > 0)
            {
                char error[256];
                int n =read(pipe_fd[0], error, sizeof(error) - 1);
                close(pipe_fd[0]);

                if(n > 0) {
                    error[n] = '\0';
                    rsp.success = false;
                    rsp.info = error;

                    return true;
                }
            }

            recorder_pid_ = pid;
            start_record_ = true;
            printf("Rosbag recording started (PID: %d)", pid);
            rsp.success = true;
            rsp.info = "开始执行脚本";
        }
        else {
            close(pipe_fd[0]);
            close(pipe_fd[1]);
            rsp.success = false;
            rsp.info = "create fork failed";
        }
    }

    }
    
  return true;
}

bool MessageHandleManager::_isRunningChildren()
{
    return !waitpid(recorder_pid_, NULL, WNOHANG); //0 为运行;
}