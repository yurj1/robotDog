#ifndef __VERSION_H__
#define __VERSION_H__
#include <string>
#include <chrono>

/** 
 *   @brief version 1: 2025 以此递增
               02： month
               17：day
               1： modify count （cur day）
*/
#define VERSION "Version: 1.02.21.1"
#define BUILD_TIME_STRING "Build on " __DATE__ " " __TIME__

namespace Version {

    std::string GetVersion()
    {
        return std::string(VERSION)+ "\t" + BUILD_TIME_STRING;
    }

    std::string GetCurrentDateTime() {
        auto now = std::chrono::system_clock::now();
        auto time = std::chrono::system_clock::to_time_t(now);
        
        char buffer[80];
        std::strftime(buffer, sizeof(buffer), 
                    "%Y-%m-%d %H:%M:%S",  // 格式：2025-02-01 10:13:00
                    std::localtime(&time));
        
        return std::string(buffer);
    }
}
#endif