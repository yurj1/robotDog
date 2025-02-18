/**
 * @file    apa_parking_status.hpp
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#pragma once

#include <iostream>
#include <stdint.h>

#include "modules/common/interface/header.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class APAParkingStatus {
public:
  APAParkingStatus() {
    state_ = athena::interface::APAParkingStatus::Status::APA_IDLE;
  }
  ~APAParkingStatus() = default;

  enum Status {
    APA_IDLE = 0,
    APA_SEARCHING = 1,
    APA_ACTIVE = 2,
    APA_PARKING = 3,
    APA_PAUSE = 4,
    APA_FAILURE = 5,
    APA_FINISH = 6,
  };

  inline void set_header(const athena::interface::Header &header) {
    header_ = header;
    header_ptr_ = &header_;
  }

  inline const athena::interface::Header &header() const { return header_; }

  inline athena::interface::Header *mutable_header() { return &header_; }

  inline bool has_header() { return (header_ptr_ != nullptr); }

  inline void
  set_state(const athena::interface::APAParkingStatus::Status &state) {
    state_ = state;
    state_ptr_ = &state_;
  }

  inline const athena::interface::APAParkingStatus::Status &state() const {
    return state_;
  }

  inline athena::interface::APAParkingStatus::Status *mutable_state() {
    return &state_;
  }

  inline bool has_state() { return (state_ptr_ != nullptr); }

  void operator=(const APAParkingStatus &apa_parking_status) {
    CopyFrom(apa_parking_status);
  }

  void CopyFrom(const APAParkingStatus &apa_parking_status) {
    header_ = apa_parking_status.header();
    state_ = apa_parking_status.state();
  }

protected:
  athena::interface::Header header_;
  athena::interface::Header *header_ptr_ = nullptr;
  athena::interface::APAParkingStatus::Status state_;
  athena::interface::APAParkingStatus::Status *state_ptr_ = nullptr;
};
} // namespace interface
} // namespace athena
