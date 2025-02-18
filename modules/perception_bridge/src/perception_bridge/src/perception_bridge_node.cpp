#include <perception_bridge/perception_bridge.h>

RobotDogMain::RobotDogMain() {
    // 从参数服务器加载 point_map
    loadPointMap();

    // 订阅集成模块的消息
    _subscriber.insert(std::make_pair<std::string, ros::Subscriber>(sub_callback_to_cmd, nh.subscribe(sub_callback_to_cmd, 10, &RobotDogMain::cmdCallback, this)));
    //cmd_sub_ = nh.subscribe(sub_callback_to_cmd, 10, &RobotDogMain::cmdCallback, this);

    // 发布消息给感知、规划模块
    _pubscriber.insert(std::make_pair<PUB_TOP, ros::Publisher>(PUB_TOP::CMD, nh.advertise<perception_msgs::TaskList>(pub_perception_mode, 10)));
    //cmd_pub_ = nh.advertise<perception_msgs::TaskList>(pub_perception_mode, 10);

    // 订阅感知模块的反馈消息
    _subscriber.insert(std::make_pair<std::string, ros::Subscriber>(sub_recv_callback_perception, nh.subscribe(sub_recv_callback_perception, 10, &RobotDogMain::ptCallback, this)));
    //pt_sub_ = nh.subscribe(sub_recv_callback_perception, 10, &RobotDogMain::ptCallback, this);

    // 发布点消息给可视化
    _pubscriber.insert(std::make_pair<PUB_TOP, ros::Publisher>(PUB_TOP::PT, nh.advertise<geometry_msgs::Pose>(pub_goal_state_extern, 10)));
    //pt_pub_ = nh.advertise<geometry_msgs::Pose>(pub_goal_state_extern, 10);

    // 订阅规划模块的反馈消息
    _subscriber.insert(std::make_pair<std::string, ros::Subscriber>(sub_planning_feedback, nh.subscribe(sub_planning_feedback, 10, &RobotDogMain::stateCallback, this)));
    //state_sub_ = nh.subscribe(sub_planning_feedback, 10, &RobotDogMain::stateCallback, this);

    // 发布反馈消息给集成
    _pubscriber.insert(std::make_pair<PUB_TOP, ros::Publisher>(PUB_TOP::STATE, nh.advertise<perception_msgs::PercState>(pub_feedback_to_cmd, 10)));
    //state_pub_ = nh.advertise<perception_msgs::PercState>(pub_feedback_to_cmd, 10);

    // 初始化定时器，按周期发布状态
    state_timer_ = nh.createTimer(ros::Duration(0.05), &RobotDogMain::timerCallback, this);

    // // 初始化 PercState
    // perc_state_.action_id = 0;
    // perc_state_.exe_state = perception_msgs::PercState::ACTION_IDLE;
    // perc_state_.exe_result = perception_msgs::PercState::ACTION_NONE;
}
  
void RobotDogMain::clear() {
    task_list_.task_id = 0;
    geometry_msgs::Pose pose;
    pose.position.x = 0;
    pose.position.y = 0;
    pose.position.z = 0;
    pose.orientation.x = 0;
    pose.orientation.y = 0;
    pose.orientation.z = 0;
    pose.orientation.w = 0;
    task_list_.target_position = pose;
    task_list_.target_object = "";
    task_list_.task_state = perception_bridge::TaskState::STATE_IDLE;
    task_list_.task_result = perception_bridge::TaskResult::RESULT_INVALID;
    task_list_.isInPlaceRotation = false;

    perc_state_.action_id = 0;

    /* perc_state_.exe_state = perception_msgs::PercState::ACTION_IDLE;
    perc_state_.exe_result = perception_msgs::PercState::ACTION_NONE; */
    m_state.Clear();
    UpdateState();
}
  
bool RobotDogMain::getPose(const std::string& point_name, geometry_msgs::Pose& pose) {
    auto it = point_map_.find(point_name);
    if (it != point_map_.end()) {
      pose = it->second;
      return true;
    }
    ROS_ERROR("Point name not found: %s", point_name.c_str());
    return false;
}

void RobotDogMain::UpdateState() {
    switch (m_state.GetState())
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

    switch (m_state.GetResult())
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
    }
}

void RobotDogMain::Publish(const PUB_TOP& topicType, void* data) {
    switch (topicType)
    {
    case PUB_TOP::CMD :
    _pubscriber[topicType].publish(*(static_cast<perception_msgs::TaskList *>(data)));
      break;
    case PUB_TOP::PT : 
    _pubscriber[topicType].publish(*(static_cast<geometry_msgs::Pose *>(data)));
      break;
    case PUB_TOP::STATE : 
    _pubscriber[topicType].publish(*(static_cast<perception_msgs::PercState *>(data)));
      break;
    default:
    ROS_WARN("Push topic is not register");
      break;
    }
}

void RobotDogMain::loadPointMap() {
    // 获取 point_map 参数
    XmlRpc::XmlRpcValue point_map_param;
    if (nh.getParam("/perception_bridge_two_node/perception_bridge/point_map", point_map_param)) {
      ROS_INFO("Loaded point_map from parameter server.");
      for (auto& pair : point_map_param) {
        std::string point_name = pair.first;
        XmlRpc::XmlRpcValue pose_param = pair.second;

        // 解析 pose 参数
        geometry_msgs::Pose pose;
        pose.position.x = static_cast<double>(pose_param["x"]);
        pose.position.y = static_cast<double>(pose_param["y"]);
        pose.position.z = static_cast<double>(pose_param["z"]);
        pose.orientation.x = static_cast<double>(pose_param["qx"]);
        pose.orientation.y = static_cast<double>(pose_param["qy"]);
        pose.orientation.z = static_cast<double>(pose_param["qz"]);
        pose.orientation.w = static_cast<double>(pose_param["qw"]);

        // 将 point_name 和 pose 添加到 point_map_
        point_map_[point_name] = pose;
        ROS_INFO("Added point: %s", point_name.c_str());
      }
    } else {
      ROS_ERROR("Failed to load point_map from parameter server.");
    }
}

void RobotDogMain::CancelTask() {
    //事件更新
      m_state.handleTaskEvent(TASK_CANCEL);
      task_list_.task_type = perception_bridge::TaskType::TASK_CANCEL;
      perc_state_.perc_kind = perception_msgs::PercState::PERC_CANCEL;
}

//前往固定点任务
void RobotDogMain::GoDest(const perception_msgs::PercCmd::ConstPtr& msg) {
    //事件更新
      m_state.handleTaskEvent(TASK_NAVIGATION);
      task_list_.task_type = perception_bridge::TaskType::TASK_NAVIGATION;
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
        task_list_.target_position = pose;
        //pt_pub_.publish(pose);
        _pubscriber[PUB_TOP::PT].publish(pose);
      } else {
        ROS_WARN("Point %s not found!", point_name.c_str());
      }
}
//跟随任务
void RobotDogMain::Follow(const perception_msgs::PercCmd::ConstPtr& msg) {
    //事件更新
      m_state.handleTaskEvent(TASK_FOLLOW);
      task_list_.task_type = perception_bridge::TaskType::TASK_FOLLOW;
      perc_state_.perc_kind = perception_msgs::PercState::PERC_FOLLOW;
      ROS_INFO("Follow %s:", msg->follow_name.c_str());
}
//欢迎任务
void RobotDogMain::Welcome(const perception_msgs::PercCmd::ConstPtr& msg) {
    //事件更新
      m_state.handleTaskEvent(TASK_WELCOME);
      task_list_.task_type = perception_bridge::TaskType::TASK_WELCOME;
      perc_state_.perc_kind = 61;
      ROS_INFO("Welcome %s:", msg->follow_name.c_str());
}
//找人任务
void RobotDogMain::GoDestAndFindTarget(const perception_msgs::PercCmd::ConstPtr& msg)
  {
    //事件更新
      m_state.handleTaskEvent(TASK_LOBBY);
      task_list_.task_type = perception_bridge::TaskType::TASK_LOBBY;
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
        
        //pt_pub_.publish(pose);
        _pubscriber[PUB_TOP::PT].publish(pose);
      } else {//固定点坐标赋值
        ROS_INFO("Point %s not found! Get Point value", point_name.c_str());
        pose.position.x = msg->point.x;
        pose.position.y = msg->point.y;
        pose.position.z = msg->point.z;
      }//不是固定点则坐标赋值
      task_list_.target_position = pose;
      task_list_.isInPlaceRotation = true;
      ROS_INFO("Find %s:", msg->follow_name.c_str());
}

//处理集成消息
void RobotDogMain::cmdCallback(const perception_msgs::PercCmd::ConstPtr& msg) {
    ROS_INFO("Received PercCmd: action_id=%lu, perc_kind=%u", msg->action_id, msg->perc_kind);

    clear();
    
    task_list_.task_id = msg->action_id;
    perc_state_.action_id = msg->action_id;
    task_list_.target_object = msg->follow_name;
    if (msg->perc_kind == perception_msgs::PercCmd::PERC_CANCEL) {
      CancelTask();
    }    // 取消任务
    else if (msg->perc_kind == perception_msgs::PercCmd::PERC_DEST) {
      GoDest(msg);
    }    // 导航任务
    else if (msg->perc_kind == perception_msgs::PercCmd::PERC_FOLLOW) {
      Follow(msg);
    }    // 跟随任务
    else if (msg->perc_kind == perception_msgs::PercCmd::PERC_WELCOME_DEMO) {
      Welcome(msg);
    }    // 欢迎任务
    else if (msg->perc_kind == perception_msgs::PercCmd::PERC_LOBBY_DEMO) {
      GoDestAndFindTarget(msg);
    }    // 找人任务
    else if (msg->perc_kind == perception_msgs::PercCmd::PERC_NODE_CLOSE) {
      //事件更新
      m_state.handleTaskEvent(TASK_NODE_CLOSE);
      task_list_.task_type = perception_bridge::TaskType::TASK_NODE_CLOSE;
      perc_state_.perc_kind = perception_msgs::PercState::PERC_NODE_CLOSE;
    }    // 关闭感知规划模块
    else if (msg->perc_kind == perception_msgs::PercCmd::PERC_NODE_START) {
      //事件更新
      m_state.handleTaskEvent(TASK_NODE_START);
      task_list_.task_type = perception_bridge::TaskType::TASK_NODE_START;
      perc_state_.perc_kind = perception_msgs::PercState::PERC_NODE_START;
    }    // 开启感知规划模块
    else if (msg->perc_kind == perception_msgs::PercCmd::PERC_NODE_RESET) {
      //事件更新
      m_state.handleTaskEvent(TASK_NODE_RESET);
      task_list_.task_type = perception_bridge::TaskType::TASK_NODE_RESET;
      perc_state_.perc_kind = perception_msgs::PercState::PERC_NODE_RESET;
    }    // 重启感知规划模块

    //cmd_pub_.publish(task_list_);
    _pubscriber[PUB_TOP::CMD].publish(task_list_);
}

//处理感知反馈消息
void RobotDogMain::ptCallback(const perception_msgs::TaskList::ConstPtr& msg) {
    ROS_INFO("Received TaskPt: task_type=%u, x=%f, y=%f, z=%f",
              msg->task_type, msg->target_position.position.x,  msg->target_position.position.y,  msg->target_position.position.z);

    if(task_list_.task_type != msg->task_type){
        ROS_WARN("Different types");
    }
    auto GetPose = [](const perception_msgs::TaskList::ConstPtr& msg){
      geometry_msgs::Pose pose;
      pose.position.x = msg->target_position.position.x;
      pose.position.y = msg->target_position.position.y;
      pose.position.z = msg->target_position.position.z;
      pose.orientation.x = msg->target_position.orientation.x;
      pose.orientation.y = msg->target_position.orientation.y;
      pose.orientation.z = msg->target_position.orientation.z;
      pose.orientation.w = msg->target_position.orientation.w;
      return pose;
    };

    if (msg->task_type == perception_bridge::TaskType::TASK_FOLLOW) {
      task_list_.task_type = perception_bridge::TaskType::TASK_NAVIGATION;
      geometry_msgs::Pose pose(GetPose(msg));
      task_list_.target_position = pose;

      _pubscriber[PUB_TOP::PT].publish(pose);
      _pubscriber[PUB_TOP::CMD].publish(task_list_);
    }    // 跟随任务
    else if (msg->task_type == perception_bridge::TaskType::TASK_WELCOME) {
      task_list_.task_type = perception_bridge::TaskType::TASK_NAVIGATION;
      geometry_msgs::Pose pose(GetPose(msg));
      task_list_.target_position = pose;

      _pubscriber[PUB_TOP::PT].publish(pose);
      _pubscriber[PUB_TOP::CMD].publish(task_list_);
    }    // 欢迎任务
    else if(msg->task_type == perception_bridge::TaskType::TASK_LOBBY){
      //满足找到人条件，则可以上报规划反馈的完成状态
      if(msg->target_object == task_list_.target_object){
        ROS_INFO("Find target suceess!");
          m_state.SetCanFinish(true);
          task_list_.isInPlaceRotation = false;
      } 
      task_list_.task_type = perception_bridge::TaskType::TASK_NAVIGATION;
      geometry_msgs::Pose pose(GetPose(msg));
      task_list_.target_position = pose;

      _pubscriber[PUB_TOP::PT].publish(pose);
      _pubscriber[PUB_TOP::CMD].publish(task_list_);
    }//找人任务
}

//处理规划状态反馈消息
void RobotDogMain::stateCallback(const perception_msgs::TaskList::ConstPtr& msg) {
    m_state.handleStateEvent(static_cast<TaskState>(msg->task_state), static_cast<TaskResult>(msg->task_result));
    //狀態更新
    UpdateState();
}

//定时器回调函数，按周期发布状态
void RobotDogMain::timerCallback(const ros::TimerEvent& event) {
    _pubscriber[PUB_TOP::STATE].publish(perc_state_);
    //Publish(PUB_TOP::STATE, static_cast<void *>(&perc_state_));
    // ROS_INFO("Published PercState: action_id=%lu, exe_state=%u, exe_result=%u",
    //           perc_state_.action_id, perc_state_.exe_state, perc_state_.exe_result);
}
