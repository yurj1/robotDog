/**
 * @file    parking_status.hpp
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#pragma once

#include <iostream>
#include <stdint.h>

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class ParkingStatus {
public:
  ParkingStatus() = default;
  ~ParkingStatus() = default;

  enum ParkingStatus {
    PARKING_DISABLE = 0,
    PARKING_ENABLE = 1,
    PARKING_NONOPTIONAL = 2,
  };

  void operator=(const ParkingStatus &parking_status) {
    CopyFrom(parking_status);
  }

  void CopyFrom(const ParkingStatus &parking_status) {
    PARKING_DISABLE_ = parking_status.PARKING_DISABLE();
    PARKING_ENABLE_ = parking_status.PARKING_ENABLE();
    PARKING_NONOPTIONAL_ = parking_status.PARKING_NONOPTIONAL();
  }

protected:
  // 0
  athena::interface::enum PARKING_DISABLE_;
  athena::interface::enum *PARKING_DISABLE_ptr_ = nullptr;
  // 1
  athena::interface::enum PARKING_ENABLE_;
  athena::interface::enum *PARKING_ENABLE_ptr_ = nullptr;
  // 2
  athena::interface::enum PARKING_NONOPTIONAL_;
  athena::interface::enum *PARKING_NONOPTIONAL_ptr_ = nullptr;
};
} // namespace interface
} // namespace athena
