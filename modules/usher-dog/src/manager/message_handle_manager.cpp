
//#include <ros/ros.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>

#include "common/public_fun.h"
#include "robot_dog_main.h"
#include "message_handle_manager.h"
#include "unitree_sdk_service.h"
#include "factory/factory.h"
#include "services/joy_handle_service.h"
#include "services/voice_service.h"

using namespace athena::function::action;
using namespace robot_dog::operations;

MessageHandleManager::MessageHandleManager()
    :dog_state_(UsherDogState::DOG_IDLE)
    , m_can_finish(true)
    , start_record_(false)
    , recorder_pid_(-1)
    , mutex_()
    ,joy_services_ptr_(nullptr)
{
    Init();
}

MessageHandleManager::~MessageHandleManager()
{
    SAFE_DELETE(joy_services_ptr_);
    SAFE_DELETE(voice_services_ptr_);
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
    task_list_planning_.target_position = robot_dog::Position();
    task_list_planning_.target_object = "";
    task_list_planning_.task_state = TaskState::STATE_IDLE;
    task_list_planning_.task_result = TaskResult::RESULT_INVALID;
    task_list_planning_.is_in_place_rotation = false;
    }
    m_can_finish = true;

    joy_services_ptr_ = new robot_dog::services::JoyHandleService();
}

const UsherDogState& MessageHandleManager::GetDogState()
{
    return dog_state_;
}

void MessageHandleManager::SetCanFinish(const bool& enable)
{
    if(m_can_finish != enable)
        m_can_finish = enable;
}

const robot_dog::TaskList& MessageHandleManager::GetOutputPlanning()
{
    return task_list_planning_;
}

const robot_dog::PercState& MessageHandleManager::GetConstStateMsg()
{
    std::lock_guard<std::mutex> lock(mutex_);
    return perc_state_;
}

robot_dog::PercState& MessageHandleManager::GetStateMsg()
{
    std::lock_guard<std::mutex> lock(mutex_);
    return perc_state_;
}

void MessageHandleManager::handleTaskEvent(const robot_dog::PercCmd& msg)
{
    printf("Received PercCmd: action_id=%lu, perc_kind=%u \n", msg.action_id, msg.perc_kind);
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

void MessageHandleManager::handlePerceptionEvent(const robot_dog::TaskList& msg)
{
    printf("Received TaskPt: task_type=%u, x=%f, y=%f, z=%f target_object=%s task_state=%u \n",
                  msg.task_type, msg.target_position.x,  msg.target_position.y,  msg.target_position.z, msg.target_object.c_str(), msg.task_state);

    static bool is_perception_error = false;

    robot_dog::Position pose;
    pose = msg.target_position;
    
    robot_dog::ActionEntry actionMsg;

    switch (msg.task_type)
    {
    case TaskType::TASK_FOLLOW://跟随任务
    case TaskType::TASK_WELCOME://欢迎任务
        if(msg.task_state == 2)//主人识别失败
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

        task_list_planning_.task_type = TaskType::TASK_NAVIGATION;
        task_list_planning_.target_position = pose;
        if(AppIsNotNull)
        {
            AfxGetApp()->PublishPose(pose);
            AfxGetApp()->PublishTaskList(task_list_planning_);
        }
        else
            std::cout << "main is null" << std::endl;
        
        break;
    case TaskType::TASK_LOBBY://找人任务
        
        if(recv_cmd_msg_info_.follow_name == msg.target_object)
            printf("Find target suceess! \n");
        else
            printf("Find target fail target: [%s] -> recv: [%s] \n", recv_cmd_msg_info_.follow_name.c_str(), msg.target_object.c_str());
        
        SetCanFinish(true);

        task_list_planning_.task_type = TaskType::TASK_NAVIGATION;
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

void MessageHandleManager::handleStateEvent(const robot_dog::TaskList& msg)
{
    //特殊状态下不切换为完成状态
    if(!m_can_finish && (uint8_t)msg.task_state == TaskState::STATE_COMPLETED){
        printf("Special task not Done \n");
        return;
    }

    if(perc_state_.exe_state != (uint8_t)msg.task_state || perc_state_.exe_result != (uint8_t)msg.task_result) {
        std::lock_guard<std::mutex> lock(mutex_);
        printf("Recv  change state: [%d]-> [%d], result: [%d] -> [%d] \n", perc_state_.exe_state, (uint8_t)msg.task_state , perc_state_.exe_result, (uint8_t)msg.task_result);

        perc_state_.exe_state = static_cast<uint8_t>(msg.task_state);
        perc_state_.exe_result = static_cast<uint8_t>(msg.task_result);
    }
}

void MessageHandleManager::HandleObuCmdMsg(const std::vector<robot_dog::ObuCmd>& obu_cmd_msg)
{
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
            printf("Sent SIGINT to rosbag process (PID: %d) \n", recorder_pid_);
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
                        printf("Sent SIGINT to rosbag process (PID: %d) \n", recorder_pid_);
                    }
                    recorder_pid_ = -1;
                    return true;
                }
            }

            start_record_ = true;
            printf("Rosbag recording started (PID: %d) \n", pid);
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
            printf("children start sh \n");
            if(execvp("/bin/bash", argv.data()) == -1)
            {
                printf("error start sh \n");
                std::string error = "record failed:  \n" + std::string(strerror(errno));
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
            printf("Rosbag recording started (PID: %d) \n", pid);
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

bool MessageHandleManager::_isCanFinish()
{
    return m_can_finish;
}

bool MessageHandleManager::_isRunningChildren()
{
    return !waitpid(recorder_pid_, NULL, WNOHANG); //0 为运行;
}

