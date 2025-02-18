/**
 * @file    RobotDogConf.hpp
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */
#pragma once

#include "modules/common/base_message/message.h"
#include "modules/common/logging/logging.h"
#include <map>
#include <mutex>

/**
 * @namespace athena::function
 * @brief athena::function
 */

namespace athena {
namespace function {

/**
 * @class RobotDogConf
 * @brief RobotDogConf.
 */
class RobotDogConf {
public:
  /**
   * @brief constructor
   */
  RobotDogConf() { messages_mutex_ = std::make_shared<std::mutex>(); };

  /**
   * @brief destructor
   */
  ~RobotDogConf() = default;

  inline void set_use_system_timestamp(bool use_system_timestamp) {
    use_system_timestamp_ = use_system_timestamp;
  }

  inline const bool& use_system_timestamp() const {
    return use_system_timestamp_;
  }

  inline bool* mutable_use_system_timestamp() { return &use_system_timestamp_; }

  inline void
  set_logging_conf(const athena::common::LoggingConf& logging_conf) {
    logging_conf_ = logging_conf;
  }

  inline const athena::common::LoggingConf& logging_conf() const {
    return logging_conf_;
  }

  inline athena::common::LoggingConf* mutable_logging_conf() {
    return &logging_conf_;
  }

  inline void
  set_messages(const std::map<std::string, athena::common::Message>& messages) {
    std::lock_guard<std::mutex> lock(*messages_mutex_);
    messages_ = messages;
  }

  inline const std::map<std::string, athena::common::Message>&
  messages() const {
    std::lock_guard<std::mutex> lock(*messages_mutex_);
    return messages_;
  }

  inline void messages_clear() {
    std::lock_guard<std::mutex> lock(*messages_mutex_);
    messages_.clear();
  }

protected:
  std::shared_ptr<std::mutex> messages_mutex_;
  bool use_system_timestamp_;
  athena::common::LoggingConf logging_conf_;
  std::map<std::string, athena::common::Message> messages_;
};
} // namespace function
} // namespace athena
