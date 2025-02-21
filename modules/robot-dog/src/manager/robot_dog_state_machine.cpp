/**
 * @file    emergency_stop_state_machine.cpp
 * @author  hyzx
 * @date    2022-08-27
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */
#include <sys/time.h>
#include <time.h>

#include <fstream>

#include "robot_dog_main.h"

namespace athena
{
  namespace function
  {
    int requestcount = 0;

    bool RobotDogMain::RobotDogMainStateMachineInit()
    {
      robot_dog_conf_sm.reset(new state_machine::StateContext(
          "./conf/function/robot-dog/state_machine/state_machine.json",
          true, "./log/state_machine/",
          "robot_dog_state_machine"));
      // Point2Point
      robot_dog_conf_sm->SetCallback(state_machine::CallbackType::UPDATE, "IdleDog",
                                      std::bind(&RobotDogMain::IdleStateUpdate, this,
                                                std::placeholders::_1, 0));
      robot_dog_conf_sm->SetCallback(state_machine::CallbackType::UPDATE, "RunningDog",
                                      std::bind(&RobotDogMain::RunningStateUpdate, this,
                                                std::placeholders::_1, 0));

      robot_dog_conf_sm->SetCallback(state_machine::CallbackType::UPDATE, "FinishDog",
                                      std::bind(&RobotDogMain::FinishStateUpdate, this,
                                                std::placeholders::_1, 0));

      // 初始化默认进入空闲模式
      robot_dog_conf_sm->NextState("Idle");
      std::cout << "change : RobotDogMainIdle " << std::endl;

      return true;
    }

    // 空闲状态
    void RobotDogMain::IdleStateUpdate(const std::string &state_name, int state)
    {
      //std::cout << "state_machine : Idle " << std::endl;
      if (state_manager_.GetState() == perception_bridge::STATE_RUNNING)
      {
        std::cout << "change : RobotDogMainRun " << std::endl;
        robot_dog_conf_sm->NextState("Run");
        return;
      }
    }

    // 运行状态
    void RobotDogMain::RunningStateUpdate(const std::string &state_name, int state)
    {
      //std::cout << "state_machine : Run " << std::endl;
      if (state_manager_.GetState() == perception_bridge::STATE_COMPLETED)
      {
        std::cout << "change : RobotDogMainComplete " << std::endl;
        robot_dog_conf_sm->NextState("complete");
        return;
      }
      else if (state_manager_.GetState() == perception_bridge::STATE_IDLE)
      {
        std::cout << "change : RobotDogMainIdle " << std::endl;
        robot_dog_conf_sm->NextState("Idle");
        return;
      }
    }

    // 完成状态
    void RobotDogMain::FinishStateUpdate(const std::string &state_name, int state)
    {
      //std::cout << "state_machine : Complete " << std::endl;
      if (state_manager_.GetState() == perception_bridge::STATE_IDLE)
      {
        std::cout << "change : RobotDogMainIdle " << std::endl;
        robot_dog_conf_sm->NextState("Idle");
        return;
      }
    }
  } // namespace emergency_stop
} // namespace athena
