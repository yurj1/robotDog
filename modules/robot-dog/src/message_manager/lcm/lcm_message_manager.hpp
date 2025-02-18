/**
 * @file    lcm_message_manager.hpp
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#include "lcm_message_manager.h"
#include "modules/common/macros/macros.h"
#include "modules/common/logging/logging.h"
#include "modules/common/base_message/message.h"
#include "modules/common/math/euler_angles_zxy.h"

#if LCM_ENABLE
/**
 * @namespace athena::function
 * @brief athena::function
 */

namespace athena {
namespace function {
using namespace athena::common;
template <typename T> void LcmMessageManager<T>::Init(T* t) {
  is_init_ = false;
  is_active_ = false;
  instance_ = t;
  std::map<std::string, athena::common::Message> messages =
      instance_->GetConf()->messages();
  lcm_ = std::make_shared<lcm::LCM>(messages["LCM"].url);

  if (!lcm_->good()) {
    AERROR << "lcm init error!";
    return;
  }

  lcm_->subscribe("/vui_client/ObuCmdMsg",
                  &LcmMessageManager::HandleObuCmdMsgMessage, this);
  // 线程执行开始
  handle_message_thread_.reset(new std::thread([this] { Run(); }));
  if (handle_message_thread_ == nullptr) {
    AERROR << "Unable to create handle_message_thread thread.";
    return;
  }
  is_init_ = true;
}

template <typename T> bool LcmMessageManager<T>::Activate() {
  if (is_active_) {
    return false;
  }
  std::lock_guard<std::mutex> lock(mutex_);
  events_sub_ = lcm_->subscribe("/state_manager/Events",
                                &LcmMessageManager::HandleEventsMessage, this);

  obu_cmd_msg_input_sub_ =
      lcm_->subscribe("/state_manager/ObuCmdMsg",
                      &LcmMessageManager::HandleObuCmdMsgInputMessage, this);

  std::cout << "lcm activate" << std::endl;
  is_active_ = true;
  return true;
}

template <typename T> bool LcmMessageManager<T>::DeActivate() {
  if (is_active_ == false) {
    return false;
  }
  std::lock_guard<std::mutex> lock(mutex_);
  lcm_->unsubscribe(events_sub_);

  lcm_->unsubscribe(obu_cmd_msg_input_sub_);

  is_active_ = false;
  std::cout << "lcm deactivate" << std::endl;
  return true;
}

template <typename T>
void LcmMessageManager<T>::PublishObuCmdMsgOutput(
    athena::interface::ObuCmdMsg msg) {
  if (is_init_ == false)
    return;
  lcm_interface::ObuCmdMsg obu_cmd_msg;
  MESSAGE_HEADER_ASSIGN(lcm_interface, obu_cmd_msg)
  obu_cmd_msg.id = msg.id();
  obu_cmd_msg.name = msg.name();
  std::vector<lcm_interface::ObuCmd> lcm_obu_cmd_list;
  std::vector<athena::interface::ObuCmd> athena_obu_cmd_list;
  msg.obu_cmd_list(athena_obu_cmd_list);
  for (auto it_obu_cmd_list : athena_obu_cmd_list) {
    lcm_interface::ObuCmd obu_cmd_msg_obu_cmd;
    obu_cmd_msg_obu_cmd.code = it_obu_cmd_list.code();
    obu_cmd_msg_obu_cmd.val = it_obu_cmd_list.val();
    lcm_obu_cmd_list.emplace_back(obu_cmd_msg_obu_cmd);
  }
  obu_cmd_msg.obu_cmd_list_size = lcm_obu_cmd_list.size();
  obu_cmd_msg.obu_cmd_list = lcm_obu_cmd_list;

  lcm_->publish("/function/emergency_stop/ObuCmdMsg", &obu_cmd_msg);
}

template <typename T>
void LcmMessageManager<T>::HandleEventsMessage(
    const lcm::ReceiveBuffer* rbuf, const std::string& chan,
    const lcm_interface::Events* msg) {
  if (is_active_ == false)
    return;

  athena::interface::Events events;

  instance_->HandleEvents(events);
}

template <typename T>
void LcmMessageManager<T>::HandleObuCmdMsgInputMessage(
    const lcm::ReceiveBuffer* rbuf, const std::string& chan,
    const lcm_interface::ObuCmdMsg* msg) {
  if (is_init_ == false)
    return;

  athena::interface::ObuCmdMsg obu_cmd_msg;
  MESSAGE_HEADER_PARSER(obu_cmd_msg)
  obu_cmd_msg.set_id(msg->id);
  obu_cmd_msg.set_name(msg->name);
  std::vector<athena::interface::ObuCmd> obu_cmd_list;
  for (auto it_obu_cmd_list : msg->obu_cmd_list) {
    athena::interface::ObuCmd obu_cmd_msg_obu_cmd;
    obu_cmd_msg_obu_cmd.set_code(it_obu_cmd_list.code);
    obu_cmd_msg_obu_cmd.set_val(it_obu_cmd_list.val);
    obu_cmd_list.emplace_back(obu_cmd_msg_obu_cmd);
  }
  obu_cmd_msg.set_obu_cmd_list(&obu_cmd_list);

  instance_->HandleObuCmdMsgInput(obu_cmd_msg);
}

template <typename T> void LcmMessageManager<T>::Run() {
  while (0 == lcm_->handle())
    ;
}

template <typename T> void LcmMessageManager<T>::Stop() {
  if (handle_message_thread_ != nullptr && handle_message_thread_->joinable()) {
    handle_message_thread_->join();
    handle_message_thread_.reset();
    AINFO << "handle_message_thread stopped [ok].";
  }
}
} // namespace function
} // namespace athena
#endif