/**
 * @file    hmi_diagnostic_array.hpp
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

#include "modules/common/interface/header.hpp"
#include "modules/common/interface/hmi_diagnostic_status.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class HMIDiagnosticArray {
public:
  HMIDiagnosticArray() {
    status_mutex_ = std::make_shared<std::mutex>();

    clear_status();
  }
  ~HMIDiagnosticArray() = default;

  inline void set_header(const athena::interface::Header& header) {
    header_ = header;
    header_ptr_ = &header_;
  }

  inline const athena::interface::Header& header() const { return header_; }

  inline athena::interface::Header* mutable_header() { return &header_; }

  inline bool has_header() { return (header_ptr_ != nullptr); }

  inline void
  set_status(std::vector<athena::interface::HMIDiagnosticStatus>* status) {
    std::lock_guard<std::mutex> lock(*status_mutex_);
    status_.assign(status->begin(), status->end());
  }

  inline void set_status(
      const std::vector<athena::interface::HMIDiagnosticStatus>& status) {
    std::lock_guard<std::mutex> lock(*status_mutex_);
    status_ = status;
  }

  inline void set_status(const uint32_t index,
                         athena::interface::HMIDiagnosticStatus& status) {
    std::lock_guard<std::mutex> lock(*status_mutex_);
    status_[index] = status;
  }

  inline void add_status(const athena::interface::HMIDiagnosticStatus& status) {
    std::lock_guard<std::mutex> lock(*status_mutex_);
    status_.emplace_back(status);
  }

  inline const athena::interface::HMIDiagnosticStatus&
  status(uint32_t index) const {
    std::lock_guard<std::mutex> lock(*status_mutex_);
    return status_[index];
  }

  inline std::vector<athena::interface::HMIDiagnosticStatus>* mutable_status() {
    std::lock_guard<std::mutex> lock(*status_mutex_);
    return &status_;
  }

  inline void
  status(std::vector<athena::interface::HMIDiagnosticStatus>& status) const {
    std::lock_guard<std::mutex> lock(*status_mutex_);
    status.assign(status_.begin(), status_.end());
  }

  inline const std::vector<athena::interface::HMIDiagnosticStatus>&
  status() const {
    std::lock_guard<std::mutex> lock(*status_mutex_);
    return status_;
  }

  inline uint32_t status_size() const {
    std::lock_guard<std::mutex> lock(*status_mutex_);
    return status_.size();
  }

  inline void clear_status() {
    std::lock_guard<std::mutex> lock(*status_mutex_);
    status_.clear();
    status_.shrink_to_fit();
  }

  inline bool has_status() { return (status_size() != 0); }

  void operator=(const HMIDiagnosticArray& hmi_diagnostic_array) {
    CopyFrom(hmi_diagnostic_array);
  }

  void CopyFrom(const HMIDiagnosticArray& hmi_diagnostic_array) {
    header_ = hmi_diagnostic_array.header();
    status_ = hmi_diagnostic_array.status();
  }

protected:
  std::shared_ptr<std::mutex> status_mutex_;
  // timestamp is  included in header
  athena::interface::Header header_;
  athena::interface::Header* header_ptr_ = nullptr;
  std::vector<athena::interface::HMIDiagnosticStatus> status_;
};
} // namespace interface
} // namespace athena
