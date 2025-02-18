/**
 * @file    uss_parking_info_list.hpp
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#pragma once

#include <mutex>
#include <vector>
#include <memory>
#include <iostream>
#include <stdint.h>

#include "modules/common/enum/enum.h"
#include "modules/common/interface/header.hpp"
#include "modules/common/interface/uss_parking_info.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class UssParkingInfoList {
public:
  UssParkingInfoList() {
    uss_parking_info_mutex_ = std::make_shared<std::mutex>();

    clear_uss_parking_info();
    error_code_ = athena::common::ErrorCode::LOCALIZATION_ERROR;
    is_valid_ = false;
  }
  ~UssParkingInfoList() = default;

  inline void set_header(const athena::interface::Header& header) {
    header_ = header;
    header_ptr_ = &header_;
  }

  inline const athena::interface::Header& header() const { return header_; }

  inline athena::interface::Header* mutable_header() { return &header_; }

  inline bool has_header() { return (header_ptr_ != nullptr); }

  inline void set_uss_parking_info(
      std::vector<athena::interface::UssParkingInfo>* uss_parking_info) {
    std::lock_guard<std::mutex> lock(*uss_parking_info_mutex_);
    uss_parking_info_.assign(uss_parking_info->begin(),
                             uss_parking_info->end());
  }

  inline void set_uss_parking_info(
      const std::vector<athena::interface::UssParkingInfo>& uss_parking_info) {
    std::lock_guard<std::mutex> lock(*uss_parking_info_mutex_);
    uss_parking_info_ = uss_parking_info;
  }

  inline void
  set_uss_parking_info(const uint32_t index,
                       athena::interface::UssParkingInfo& uss_parking_info) {
    std::lock_guard<std::mutex> lock(*uss_parking_info_mutex_);
    uss_parking_info_[index] = uss_parking_info;
  }

  inline void add_uss_parking_info(
      const athena::interface::UssParkingInfo& uss_parking_info) {
    std::lock_guard<std::mutex> lock(*uss_parking_info_mutex_);
    uss_parking_info_.emplace_back(uss_parking_info);
  }

  inline const athena::interface::UssParkingInfo&
  uss_parking_info(uint32_t index) const {
    std::lock_guard<std::mutex> lock(*uss_parking_info_mutex_);
    return uss_parking_info_[index];
  }

  inline std::vector<athena::interface::UssParkingInfo>*
  mutable_uss_parking_info() {
    std::lock_guard<std::mutex> lock(*uss_parking_info_mutex_);
    return &uss_parking_info_;
  }

  inline void uss_parking_info(
      std::vector<athena::interface::UssParkingInfo>& uss_parking_info) const {
    std::lock_guard<std::mutex> lock(*uss_parking_info_mutex_);
    uss_parking_info.assign(uss_parking_info_.begin(), uss_parking_info_.end());
  }

  inline const std::vector<athena::interface::UssParkingInfo>&
  uss_parking_info() const {
    std::lock_guard<std::mutex> lock(*uss_parking_info_mutex_);
    return uss_parking_info_;
  }

  inline uint32_t uss_parking_info_size() const {
    std::lock_guard<std::mutex> lock(*uss_parking_info_mutex_);
    return uss_parking_info_.size();
  }

  inline void clear_uss_parking_info() {
    std::lock_guard<std::mutex> lock(*uss_parking_info_mutex_);
    uss_parking_info_.clear();
    uss_parking_info_.shrink_to_fit();
  }

  inline bool has_uss_parking_info() { return (uss_parking_info_size() != 0); }

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

  inline void set_is_valid(const bool& is_valid) {
    is_valid_ = is_valid;
    is_valid_ptr_ = &is_valid_;
  }

  inline const bool& is_valid() const { return is_valid_; }

  inline bool* mutable_is_valid() { return &is_valid_; }

  inline bool has_is_valid() { return (is_valid_ptr_ != nullptr); }

  void operator=(const UssParkingInfoList& uss_parking_info_list) {
    CopyFrom(uss_parking_info_list);
  }

  void CopyFrom(const UssParkingInfoList& uss_parking_info_list) {
    header_ = uss_parking_info_list.header();
    uss_parking_info_ = uss_parking_info_list.uss_parking_info();
    error_code_ = uss_parking_info_list.error_code();
    is_valid_ = uss_parking_info_list.is_valid();
  }

protected:
  std::shared_ptr<std::mutex> uss_parking_info_mutex_;
  //消息头
  athena::interface::Header header_;
  athena::interface::Header* header_ptr_ = nullptr;
  //超声波检测出的停车位数组
  std::vector<athena::interface::UssParkingInfo> uss_parking_info_;
  //错误码（default = OK）
  athena::common::ErrorCode error_code_;
  athena::common::ErrorCode* error_code_ptr_ = nullptr;
  //超声波车位数据是否合法
  bool is_valid_;
  bool* is_valid_ptr_ = nullptr;
};
} // namespace interface
} // namespace athena
