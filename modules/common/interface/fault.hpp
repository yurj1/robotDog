/**
 * @file    fault.hpp
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

#include "modules/common/interface/time.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class Fault {
public:
  Fault() {
    code_ = 0;
    reason_.clear();
  }
  ~Fault() = default;

  inline void set_timestamp(const athena::interface::Time& timestamp) {
    timestamp_ = timestamp;
    timestamp_ptr_ = &timestamp_;
  }

  inline const athena::interface::Time& timestamp() const { return timestamp_; }

  inline athena::interface::Time* mutable_timestamp() { return &timestamp_; }

  inline bool has_timestamp() { return (timestamp_ptr_ != nullptr); }

  inline void set_code(const uint64_t& code) {
    code_ = code;
    code_ptr_ = &code_;
  }

  inline const uint64_t& code() const { return code_; }

  inline uint64_t* mutable_code() { return &code_; }

  inline bool has_code() { return (code_ptr_ != nullptr); }

  inline void set_reason(const std::string& reason) {
    reason_ = reason;
    reason_ptr_ = &reason_;
  }

  inline const std::string& reason() const { return reason_; }

  inline std::string* mutable_reason() { return &reason_; }

  inline bool has_reason() { return (reason_ptr_ != nullptr); }

  void operator=(const Fault& fault) { CopyFrom(fault); }

  void CopyFrom(const Fault& fault) {
    timestamp_ = fault.timestamp();
    code_ = fault.code();
    reason_ = fault.reason();
  }

protected:
  //时间戳
  athena::interface::Time timestamp_;
  athena::interface::Time* timestamp_ptr_ = nullptr;
  //故障码
  uint64_t code_;
  uint64_t* code_ptr_ = nullptr;
  //原因
  std::string reason_;
  std::string* reason_ptr_ = nullptr;
};
} // namespace interface
} // namespace athena
