#include "voice_service.h"

#include "common/public_fun.h"
#include "robot_dog_main.h"
#include "manager/message_handle_manager.h"
#include "unitree_sdk_service.h"

using namespace robot_dog::services;
using namespace robot_dog::operations;
using namespace robot_dog;

static const std::map<VoiceDestCommand, std::string> VideoService::DestCommandMap = 
{
    {VoiceDestCommand::COMMAND_GotoA, "A_point"},
    {VoiceDestCommand::COMMAND_GotoB, "B_point"},
    {VoiceDestCommand::COMMAND_GotoC, "C_point"},
    {VoiceDestCommand::COMMAND_GotoD, "D_point"}
};

static const std::map<std::string, AudioOrder> VideoService::AudioCommandMap = 
{
    {"A_point" , AudioOrder::ELEVATOR_ARRIVE},
    {"B_point" , AudioOrder::CONFERENCE_ROOM_ARRIVE},
    {"C_point" , AudioOrder::DRIVE_VEHICLE_ARRIVE},
    {"D_point" , AudioOrder::PARK_VEHICLE_ARRIVE}
};

VideoService::VideoService(){}

VideoService::~VideoService(){}

void VideoService::Init(){}

void VideoService::HandleVideoCode(const robot_dog::ObuCmdMsg& obu_cmd_msg)
{
    for(auto cmd : obu_cmd_msg.obu_cmd_list) {
        AINFO << "Recv code: [" << cmd.code << "] val: [" << cmd.val <<"]";
        int code = 0;
        
        // 外层switch处理主命令码
        switch(cmd.code) {
            case VocieCode::CODE_Action:
                //动作指令，需要sdk service
                if(!AppGetUnitreeService()) return;

                if(parseAction(cmd.val)) {
                    AERROR << "exec 10010 order error code: " << code;
                }
                break;

            case VocieCode::CODE_ToDest:
                parseToDest(cmd.val);
                break;

            default:
                AERROR << "Unsupported command code: " << cmd.code;
                break;
        }
    }
}

void VideoService::PlayAudio(const int& voice_val)
{
    AINFO << "Play voice_code: " << voice_val;
    robot_dog::ObuCmdMsg voiceCode;
    voiceCode.name = "arrival";
    voiceCode.obu_cmd_list.emplace_back(robot_dog::ObuCmd(VocieCode::CODE_PLAY_VIDEO, voice_val));
    AfxGetApp()->PublishVideoOnInt(voiceCode);
}

int VideoService::parseAction(VoiceActionCommand val)
{
    int code = -1;
    // 内层switch处理具体动作值
    switch(val) {
        case VoiceActionCommand::ACTION_STOP:
            AppGetUnitreeService()->ObstaclesMoveStop();
            code = AppGetUnitreeService()->PerformingAcrtion(
                DogMition::STOP_MOVE);
            break;
            
        case VoiceActionCommand::ACTION_HELLO:
            if(AppGetUnitreeService())
                code = AppGetUnitreeService()->PerformingAcrtion(
                    DogMition::HELLO);
            break;
        case VoiceActionCommand::ACTION_SCRAPE:
        if(AppGetUnitreeService())
            code = AppGetUnitreeService()->PerformingAcrtion(
                DogMition::SCRAPE);
        break;
            
        default:
            AERROR << "Unsupported action value: " << val;
            break;
    }
    return code;
}

int VideoService::parseToDest(VoiceActionCommand val)
{
    // 内层switch处理导航目标值
    if(val == VoiceDestCommand::COMMAND_STOP) {
        robot_dog::PercCmd task;
        task.perc_kind = 100; //取消任务
        task.action_id = 10000;
        AppGetMessageHandManager()->handleTaskEvent(task);
    }
    else if(DestCommandMap.count((VoiceDestCommand)val) != 0) {
        MoveToTarget(DestCommandMap[(VoiceDestCommand)val]);
    }
    return 0;
}

void VideoService::MoveToTarget(const std::string& target)
{
    if(! _AppIsMessageHandManagerNotNull) return ;

    robot_dog::Position pose;
    //if (! GetPose(target, pose)) return ;

    AINFO << "Video ctrl to: " << target;

    robot_dog::PercCmd task;
    task.perc_kind = 1; //固定点模式
    task.action_id = 10000;
    task.point_name = target; //目标名字

    AppGetMessageHandManager()->handleTaskEvent(task);
}

bool VideoService::GetPose(const std::string& target_name, robot_dog::Position& tPose)
{
    const auto& point_map = AfxGetApp()->GetPointMap();

    auto it = point_map.find(target_name);
    if (it != point_map.end()) {
        tPose = it->second;
        return true;
    }
    printf("%s of the point hasn't been found \n", target_name.c_str());
    return false;
}

bool VideoService::GetVideoCode(const std::string& target_name, int& v_code)
{

}