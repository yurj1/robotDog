/**
 * @file         time_tool_test.cpp
 * @author  jiangchengjie<jiangchengjie@indrv.cn>
 * @date       2020-03-26
 * @version 1.0.0
 * @par          Copyright(c)
 * @license   GNU General Public License (GPL)
 */

#include <iostream>
#include <unistd.h>
#include "common/time/time_tool.h"
#include "common/time/time_tool_test.h"

/**
 * @namespace athena::common
 * @brief athena::common
 */
namespace athena {
namespace common {

void TimeToolTest::Init() {
  task_thread_.reset(new std::thread([this] { Spin(); }));
  if (task_thread_ == nullptr) {
    std::cout << "Unable to create can task_thread_ thread." << std::endl;
    return;
  }
}

void TimeToolTest::Join() {
  if (task_thread_ != nullptr && task_thread_->joinable()) {
    task_thread_->join();
    task_thread_.reset();
    std::cout << "task_thread_ stopped [ok]." << std::endl;
  }
}

void TimeToolTest::Spin() {
  while (1) {
    std::chrono::system_clock::time_point start_time;
    std::cout << "ElapseSeconds: " << TimeTool::ElapseSeconds(start_time)
              << std::endl;
    std::cout << "ElapseMs: " << TimeTool::ElapseMs(start_time) << std::endl;
    std::cout << "ElapseUs: " << TimeTool::ElapseUs(start_time) << std::endl;
    std::cout << "Now2Seconds: " << TimeTool::Now2Seconds() << std::endl;
    std::cout << "Now2Ms: " << TimeTool::Now2Ms() << std::endl;
    std::cout << "Now2Us: " << TimeTool::Now2Us() << std::endl;

    // std::chrono::system_clock::time_point t(std::chrono::seconds(2));
    // std::cout << "ToSeconds: " << TimeTool::ToSeconds(t) << std::endl;
    // std::cout << "ToMs: " << TimeTool::ToMs(t) << std::endl;
    // std::cout << "ToUs: " << TimeTool::ToUs(t) << std::endl;
    // std::cout << "ToStr: " << TimeTool::ToStr(t) << std::endl;
    // std::cout << "ToStr: " << TimeTool::ToStr(t) << std::endl;

    std::cout << "Now2MsEx: " << TimeTool::Now2MsEx() << std::endl;

    std::cout << "ToTime: " << TimeTool::ToTime("2020-03-26 17:16:32")
              << std::endl;

    std::chrono::system_clock::time_point t =
        TimeTool::ToTimeEx("2020-03-26 17:16:32:123");
    std::cout << "ToSeconds: " << TimeTool::ToSeconds(t) << std::endl;
    std::cout << "ToMs: " << TimeTool::ToMs(t) << std::endl;
    std::cout << "ToUs: " << TimeTool::ToUs(t) << std::endl;
    std::cout << "ToStr: " << TimeTool::ToStr(t) << std::endl;
    std::cout << "ToStr: " << TimeTool::ToStr(t) << std::endl;
    std::cout << std::endl;
    sleep(1);
  }
}
} // namespace common
} // namespace athena
