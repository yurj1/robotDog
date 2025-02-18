/**
 * @file         ad_timer_manager_test.cpp
 * @author  jiangchengjie<jiangchengjie@indrv.cn>
 * @date       2020-03-26
 * @version 1.0.0
 * @par          Copyright(c)
 * @license   GNU General Public License (GPL)
 */

#include <iostream>
#include <unistd.h>
#include "common/timer/ad_timer_manager_test.h"

/**
 * @namespace athena::common
 * @brief athena::common
 */
namespace athena {
namespace common {
void ADTimerManagerTest::Init() {

  ad_timer_manager_ =
      std::make_shared<ADTimerManager<ADTimerManagerTest, void>>();
  ad_timer1_ =
      std::make_shared<WheelTimer<ADTimerManagerTest, void>>(ad_timer_manager_);
  ad_timer2_ =
      std::make_shared<WheelTimer<ADTimerManagerTest, void>>(ad_timer_manager_);
  ad_timer3_ =
      std::make_shared<WheelTimer<ADTimerManagerTest, void>>(ad_timer_manager_);
  ad_timer4_ =
      std::make_shared<WheelTimer<ADTimerManagerTest, void>>(ad_timer_manager_);
  ad_timer5_ =
      std::make_shared<WheelTimer<ADTimerManagerTest, void>>(ad_timer_manager_);
  ad_timer1_->AddTimer(10, &ADTimerManagerTest::T1, this);
  ad_timer2_->AddTimer(10, &ADTimerManagerTest::T2, this);
  ad_timer3_->AddTimer(10, &ADTimerManagerTest::T3, this);
  ad_timer4_->AddTimer(10, &ADTimerManagerTest::T4, this);
  ad_timer5_->AddTimer(10, &ADTimerManagerTest::T5, this);

  ad_hd_timer_manager_ =
      std::make_shared<ADTimerManager<ADTimerManagerTest, void>>();
  ad_timer6_ = std::make_shared<WheelTimer<ADTimerManagerTest, void>>(
      ad_hd_timer_manager_);
  ad_timer7_ = std::make_shared<WheelTimer<ADTimerManagerTest, void>>(
      ad_hd_timer_manager_);
  ad_timer8_ = std::make_shared<WheelTimer<ADTimerManagerTest, void>>(
      ad_hd_timer_manager_);
  ad_timer9_ = std::make_shared<WheelTimer<ADTimerManagerTest, void>>(
      ad_hd_timer_manager_);
  ad_timer10_ = std::make_shared<WheelTimer<ADTimerManagerTest, void>>(
      ad_hd_timer_manager_);
  ad_timer6_->AddTimer(10, &ADTimerManagerTest::T6, this);
  ad_timer7_->AddTimer(10, &ADTimerManagerTest::T7, this);
  ad_timer8_->AddTimer(10, &ADTimerManagerTest::T8, this);
  ad_timer9_->AddTimer(10, &ADTimerManagerTest::T9, this);
  ad_timer10_->AddTimer(10, &ADTimerManagerTest::T10, this);
  task_thread_.reset(new std::thread([this] { Spin(); }));
  if (task_thread_ == nullptr) {
    std::cout << "Unable to create can task_thread_ thread." << std::endl;
    return;
  }

  hd_task_thread_.reset(new std::thread([this] { HDSpin(); }));
  if (hd_task_thread_ == nullptr) {
    std::cout << "Unable to create can hd_task_thread_ thread." << std::endl;
    return;
  }
}

void ADTimerManagerTest::Join() {
  if (task_thread_ != nullptr && task_thread_->joinable()) {
    task_thread_->join();
    task_thread_.reset();
    std::cout << "task_thread_ stopped [ok]." << std::endl;
  }

  if (hd_task_thread_ != nullptr && hd_task_thread_->joinable()) {
    hd_task_thread_->join();
    hd_task_thread_.reset();
    std::cout << "hd_task_thread_ stopped [ok]." << std::endl;
  }
}

void ADTimerManagerTest::Spin() {
  while (1) {
    ad_timer_manager_->DetectTimers(NULL);
    usleep(10);
  }
}

void ADTimerManagerTest::HDSpin() {
  sched_param sch;
  sch.sched_priority = 99;
  pthread_setschedparam(pthread_self(), SCHED_FIFO, &sch);
  while (1) {
    ad_hd_timer_manager_->DetectTimers(NULL);
  }
}

void ADTimerManagerTest::T1(void*) { std::cout << "T1" << std::endl; }

void ADTimerManagerTest::T2(void*) { std::cout << "T2" << std::endl; }

void ADTimerManagerTest::T3(void*) { std::cout << "T3" << std::endl; }

void ADTimerManagerTest::T4(void*) { std::cout << "T4" << std::endl; }

void ADTimerManagerTest::T5(void*) { std::cout << "T5" << std::endl; }

void ADTimerManagerTest::T6(void*) { std::cout << "T6" << std::endl; }

void ADTimerManagerTest::T7(void*) { std::cout << "T7" << std::endl; }

void ADTimerManagerTest::T8(void*) { std::cout << "T8" << std::endl; }

void ADTimerManagerTest::T9(void*) { std::cout << "T9" << std::endl; }

void ADTimerManagerTest::T10(void*) { std::cout << "T10" << std::endl; }
} // namespace common
} // namespace athena
