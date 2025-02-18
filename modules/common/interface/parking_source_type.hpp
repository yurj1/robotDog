/**
 * @file    parking_source_type.hpp
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
class ParkingSourceType {
public:
  ParkingSourceType() = default;
  ~ParkingSourceType() = default;

  enum ParkingSourceType {
    LINE_PARKING = 0,
    SPACE_PARKING = 1,
    USS_PARKING = 2,
    FUSED_PARKING = 3,
  };

  void operator=(const ParkingSourceType &parking_source_type) {
    CopyFrom(parking_source_type);
  }

  void CopyFrom(const ParkingSourceType &parking_source_type) {
    LINE_PARKING_ = parking_source_type.LINE_PARKING();
    SPACE_PARKING_ = parking_source_type.SPACE_PARKING();
    USS_PARKING_ = parking_source_type.USS_PARKING();
    FUSED_PARKING_ = parking_source_type.FUSED_PARKING();
  }

protected:
  // 0
  athena::interface::enum LINE_PARKING_;
  athena::interface::enum *LINE_PARKING_ptr_ = nullptr;
  // 1
  athena::interface::enum SPACE_PARKING_;
  athena::interface::enum *SPACE_PARKING_ptr_ = nullptr;
  // 2
  athena::interface::enum USS_PARKING_;
  athena::interface::enum *USS_PARKING_ptr_ = nullptr;
  // 3
  athena::interface::enum FUSED_PARKING_;
  athena::interface::enum *FUSED_PARKING_ptr_ = nullptr;
};
} // namespace interface
} // namespace athena
