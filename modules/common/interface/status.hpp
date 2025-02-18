/**
 * @file    status.hpp
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

#include "modules/common/enum/enum.h"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class Status {
public:
  Status() {
    error_code_ = athena::common::ErrorCode::LOCALIZATION_ERROR;
    msg_.clear();
  }
  ~Status() = default;

  inline void set_error_code(const athena::common::ErrorCode& error_code) {
    error_code_ = error_code;
    error_code_ptr_ = &error_code_;
  }

  inline const athena::common::ErrorCode& error_code() const {
    return error_code_;
  }

  inline athena::common::ErrorCode* mutable_error_code() {
    return &error_code_;
  }

  inline bool has_error_code() { return (error_code_ptr_ != nullptr); }

  inline void set_msg(const std::string& msg) {
    msg_ = msg;
    msg_ptr_ = &msg_;
  }

  inline const std::string& msg() const { return msg_; }

  inline std::string* mutable_msg() { return &msg_; }

  inline bool has_msg() { return (msg_ptr_ != nullptr); }

  void operator=(const Status& status) { CopyFrom(status); }

  void CopyFrom(const Status& status) {
    error_code_ = status.error_code();
    msg_ = status.msg();
  }

protected:
  //错误码
  athena::common::ErrorCode error_code_;
  athena::common::ErrorCode* error_code_ptr_ = nullptr;
  //错误码描述
  std::string msg_;
  std::string* msg_ptr_ = nullptr;
};
} // namespace interface
} // namespace athena
