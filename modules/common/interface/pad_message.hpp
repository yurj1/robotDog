/**
 * @file    pad_message.hpp
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#pragma once

#include <string>
#include <iostream>
#include <stdint.h>

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class PadMessage {
public:
  PadMessage() { cmd_.clear(); }
  ~PadMessage() = default;

  inline void set_cmd(const std::string& cmd) {
    cmd_ = cmd;
    cmd_ptr_ = &cmd_;
  }

  inline const std::string& cmd() const { return cmd_; }

  inline std::string* mutable_cmd() { return &cmd_; }

  inline bool has_cmd() { return (cmd_ptr_ != nullptr); }

  void operator=(const PadMessage& pad_message) { CopyFrom(pad_message); }

  void CopyFrom(const PadMessage& pad_message) { cmd_ = pad_message.cmd(); }

protected:
  //命令
  std::string cmd_;
  std::string* cmd_ptr_ = nullptr;
};
} // namespace interface
} // namespace athena
