#ifndef __VIDEO_SERVICE_H__
#define __VIDEO_SERVICE_H__

#include <mutex>
#include <atomic>
#include <map>
#include <condition_variable>

#include "common/struct/CommonStruct.h"

namespace robot_dog {
    namespace services {
        class VideoService
        {
        public:
            VideoService();
            ~VideoService();
            void Init();

            void HandleVideoCode(const robot_dog::ObuCmdMsg& obu_cmd_msg);
            void PlayAudio(const int& voice_val);
        private:
            int parseAction(robot_dog::operations::VoiceActionCommand val);
            int parseToDest(robot_dog::operations::VoiceActionCommand val); 
            
            void MoveToTarget(const std::string& target);
            bool GetPose(const std::string& target_name, robot_dog::Position& tPose);
            bool GetVideoCode(const std::string& target_name, int& v_code);
        private:
            std::string current_target_name;

            static const std::map<robot_dog::operations::VoiceDestCommand, std::string> DestCommandMap;
            static const std::map<std::string, robot_dog::operations::AudioOrder> AudioCommandMap;
        };
    }// namespace services
}// namespace robot_dog

#endif //__VIDEO_SERVICE_H__