/**
 * @file    parking_type.hpp
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
class ParkingType {
public:
  ParkingType() = default;
  ~ParkingType() = default;

  enum ParkingType {
    INVALID_PARKING = 0,
    PARALLEL_PARKING = 1,
    VERTICAL_PARKING = 2,
    OBLIQUE_PARKING = 3,
    YUGU_PARKING = 4,
    UNKNOWN_PARKING = 5,
  };

  void operator=(const ParkingType &parking_type) { CopyFrom(parking_type); }

  void CopyFrom(const ParkingType &parking_type) {
    INVALID_PARKING_ = parking_type.INVALID_PARKING();
    PARALLEL_PARKING_ = parking_type.PARALLEL_PARKING();
    VERTICAL_PARKING_ = parking_type.VERTICAL_PARKING();
    OBLIQUE_PARKING_ = parking_type.OBLIQUE_PARKING();
    YUGU_PARKING_ = parking_type.YUGU_PARKING();
    UNKNOWN_PARKING_ = parking_type.UNKNOWN_PARKING();
  }

protected:
  // 0
  athena::interface::enum INVALID_PARKING_;
  athena::interface::enum *INVALID_PARKING_ptr_ = nullptr;
  // 1
  athena::interface::enum PARALLEL_PARKING_;
  athena::interface::enum *PARALLEL_PARKING_ptr_ = nullptr;
  // 2
  athena::interface::enum VERTICAL_PARKING_;
  athena::interface::enum *VERTICAL_PARKING_ptr_ = nullptr;
  // 3
  athena::interface::enum OBLIQUE_PARKING_;
  athena::interface::enum *OBLIQUE_PARKING_ptr_ = nullptr;
  // 4
  athena::interface::enum YUGU_PARKING_;
  athena::interface::enum *YUGU_PARKING_ptr_ = nullptr;
  // 5
  athena::interface::enum UNKNOWN_PARKING_;
  athena::interface::enum *UNKNOWN_PARKING_ptr_ = nullptr;
};
} // namespace interface
} // namespace athena
