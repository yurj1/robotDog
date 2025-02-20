#ifndef __PERCEPTION_BRIDGE_H__
#define __PERCEPTION_BRIDGE_H__

#include <ros/ros.h>
#include <robot_dog_state_manager.h>

#include <mutex>
#include <thread>
#include <iomanip>

#include "modules/common/json/json.hpp"
#include "modules/common/status/status.h"
#include "modules/common/logging/logging.h"
#include "modules/common/state_machine/state_context.hpp"
#include "modules/common/state_machine/state_flags.hpp"
#include "modules/common/state_machine/state.hpp"
#include "message_manager/message_manager.h"
#include "modules/common/timer/timer_manager.h"
#include "modules/common/fault/fault_client.hpp"
#include "modules/common/timer/ad_timer_manager.h"
#include "modules/common/base_message/message_status.hpp"
#include "modules/robot-dog/src/common/local_view.h"
#include "modules/common/base_message/message_status.hpp"

#if LCM_ENABLE
#include "message_manager/lcm/lcm_message_manager.h"
#endif
#if DDS_ENABLE
#include "message_manager/dds/dds_message_manager.h"
#endif
#if ROS_ENABLE
#include "message_manager/ros/ros_message_manager.h"
#endif
#if ROS2_ENABLE
#include "message_manager/ros2/ros2_message_manager.h"
#endif

#include "conf/robot_dog_conf.hpp"

namespace athena
{
  namespace function {
    using namespace athena::common;
    using json = nlohmann::json;

    class RobotDogMain {
    public:
    RobotDogMain(std::string file_path);
    ~RobotDogMain() = default;
      /**
       * @brief     初始化．
       * @param[in] void．
       * @return    void.
       */
      void Start();

      /**
       * @brief     loop
       * @param[in] void．
       * @return    void.
       */
      void Loop();

      /**
       * @brief     join．
       * @param[in] void.
       * @return    void.
       */
      void Join();

      /**
       * @brief     Close.
       * @param[in] void.
       * @return    void.
       */
      void Close();

      /**
       * @brief     detach．
       * @param[in] void.
       * @return    void.
       */
      void Detach();

      /**
       * @brief Get the Conf object
       * @return std::shared_ptr<RobotDogConf>
       */
      std::shared_ptr<RobotDogConf> GetConf() const;
      // 初始化待传参数
      void clear();
      // 根据 point_name 获取 geometry_msgs/Pose
      bool getPose(const std::string& point_name, geometry_msgs::Pose& pose);
      // 将状态管理的状态更新到字段消息中
      void UpdateState();

    protected:
      // 初始化状态
      bool is_init_;
      // 配置文件路径
      std::string config_file_path_;
      // 配置文件操作类
      json roobt_dog_json_;
      // 控制逻辑设置
      std::shared_ptr<RobotDogConf> robot_dog_conf_;
      // 消息控制器
      std::map<std::string, std::shared_ptr<MessageManager<RobotDogMain>>>
          message_manager_;
    #if LCM_ENABLE
      std::shared_ptr<LcmMessageManager<RobotDogMain>> lcm_message_manager_;
    #endif
    #if DDS_ENABLE
          // DDS消息控制器
          std::shared_ptr<DdsMessageManager<RobotDogMain>> dds_message_manager_;
    #endif
    #if ROS_ENABLE
          std::shared_ptr<RosMessageManager<RobotDogMain>> ros_message_manager_;
    #endif
    #if ROS2_ENABLE
          std::shared_ptr<Ros2MessageManager<RobotDogMain>> ros2_message_manager_;
    #endif
    #if ADSFI_ENABLE
          std::shared_ptr<AdsfiMessageManager<RobotDogMain>> adsfi_message_manager_;
    #endif

    protected:
      /**
       * @brief     注册消息控制器.
       * @param[in] message_manager　消息控制器对象指针.
       * @return    void.
       */
      void ResigerMessageManager(
          std::string name,
          std::shared_ptr<MessageManager<RobotDogMain>> message_manager);

      /**
       * @brief
       *
       */
      void VariableInit();

      /**
       * @brief     消息初始化.
       * @return    void.
       */
      void MessagesInit();

      /**
       * @brief     消息激活.
       * @return    void.
       */
      void MessagesActivate();

      /**
       * @brief     消息去激活.
       * @return    void.
       */
      void MessagesDeActivate();

      /**
       * @brief 定时器任务激活
       */
      void TaskActivate();

      /**
       * @brief 定时器任务停止
       */
      void TaskStop();

      /**
       * @brief 故障码监控初始化
       */
      //void FaultMonitorInit();

      /**
       * @brief 周期发送状态到集成,以及广播robot_dog状态
       * @return void.
       */
      void Task1000ms(void *param);
      void StateCallback(void *param);
      /**
       * @brief     打印调试.
       * @return    void.
       */
      void Print();

      /**
       * @brief     日志调试.
       * @return    void.
       */
      void Log();

    public:
      // 处理集成消息
      void cmdCallback(const perception_msgs::PercCmd::ConstPtr& msg);
      // 处理感知反馈消息
      void ptCallback(const perception_msgs::TaskList::ConstPtr& msg);
      // 处理规划状态反馈消息
      void stateCallback(const perception_msgs::TaskList::ConstPtr& msg);
      const std::map<std::string, geometry_msgs::Pose>& GetPointMap();

    protected:
      /**
       * @brief     状态机初始化.
       */
      bool RobotDogMainStateMachineInit();
      /**
       * @brief     空闲状态.
       */
      void IdleStateUpdate(const std::string &state_name, int state);
      /**
       * @brief     任务执行中状态.
       */
      void RunningStateUpdate(const std::string &state_name, int state);
      /**
       * @brief     完成状态.
       */
      void FinishStateUpdate(const std::string &state_name, int state);

    private:
      std::unique_ptr<state_machine::StateContext> robot_dog_conf_sm;

    protected:
      athena::interface::FaultCodeSet *faultcodeset_;
      // 功能激活状态,激活为true，未激活为false
      bool function_activation_;
      // 消息状态
      std::map<std::string, MessageStatus> message_status_;
      // task线程
      std::unique_ptr<std::thread> task_thread_;

      std::mutex mutex_;

    protected:
      // 定时器
      std::shared_ptr<ADTimerManager<RobotDogMain, void>> ad_timer_manager_;
      std::shared_ptr<WheelTimer<RobotDogMain, void>> task_1000ms_;
      /**
       * @brief     Spin．
       * @param[in] void.
       * @return    void.
       */
      void Spin();

    private:
      // 取消任务
      void CancelTask();
      // 前往固定点任务
      void GoDest(const perception_msgs::PercCmd::ConstPtr& msg);
      // 跟随任务
      void Follow(const perception_msgs::PercCmd::ConstPtr& msg);
      // 欢迎任务
      void Welcome(const perception_msgs::PercCmd::ConstPtr& msg);
      // 找人任务
      void GoDestAndFindTarget(const perception_msgs::PercCmd::ConstPtr& msg);

      void PublishTaskList(perception_msgs::TaskList msg);
      void PublishPose(geometry_msgs::Pose msg);
      void PublishState(perception_msgs::PercState msg);
    private:
      perception_msgs::TaskList task_list_perception_; //to perception
      perception_msgs::TaskList task_list_planning_; //to planning
      perception_msgs::PercState perc_state_;

      // 状态管理器
      RobotDogState state_manager_;
    };
  }
}
#endif