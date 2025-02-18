/**
 * @file    lcm_message_manager.h
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#pragma once

#if LCM_ENABLE
#include <thread>
#include <lcm/lcm.h>
#include <lcm/lcm-cpp.hpp>

#include "lcm_interface/Events.hpp"
#include "lcm_interface/ObuCmdMsg.hpp"

#include "message_manager/message_manager.h"

/**
 * @namespace athena::function
 * @brief athena::function
 */

namespace athena {
namespace function {
/**
 * @class LcmMessageManager
 * @brief LCM消息管理器.
 */
template <typename T> class LcmMessageManager : public MessageManager<T> {
public:
  LcmMessageManager() = default;
  ~LcmMessageManager() = default;

  /**
   * @brief     初始化。
   * @param[in] obu_url LCM组播信息.
   * @return    void.
   */
  void Init(T* t) override;

  /**
   * @brief     ObuCmdMsg消息发送.
   * @param[in] obu_cmd_msg
   * @return    void.
   */
  void PublishObuCmdMsgOutput(athena::interface::ObuCmdMsg msg) override;

  bool Activate() override;
  bool DeActivate() override;

protected:
  T* instance_;
  bool is_init_;
  bool is_active_;
  std::shared_ptr<lcm::LCM> lcm_;
  std::mutex mutex_;

  std::unique_ptr<std::thread> handle_message_thread_;

  lcm::Subscription* events_sub_;
  void HandleEventsMessage(const lcm::ReceiveBuffer* rbuf,
                           const std::string& chan,
                           const lcm_interface::Events* msg);

  lcm::Subscription* obu_cmd_msg_input_sub_;
  void HandleObuCmdMsgInputMessage(const lcm::ReceiveBuffer* rbuf,
                                   const std::string& chan,
                                   const lcm_interface::ObuCmdMsg* msg);

  /**
   * @brief     线程运行函数.
   * @return    void.
   */
  void Run();

  /**
   * @brief     线程结束函数.
   * @return    void.
   */
  void Stop();
};
} // namespace function
} // namespace athena
#include "lcm_message_manager.hpp"
#endif