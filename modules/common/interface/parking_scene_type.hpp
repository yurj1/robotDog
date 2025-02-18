/**
 * @file    parking_scene_type.hpp
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
class ParkingSceneType {
public:
  ParkingSceneType() = default;
  ~ParkingSceneType() = default;

  enum ParkingSceneType {
    COMMON = 0,
    DEAD_END = 1,
    SELF_CREATED = 2,
  };

  void operator=(const ParkingSceneType &parking_scene_type) {
    CopyFrom(parking_scene_type);
  }

  void CopyFrom(const ParkingSceneType &parking_scene_type) {
    COMMON_ = parking_scene_type.COMMON();
    DEAD_END_ = parking_scene_type.DEAD_END();
    SELF_CREATED_ = parking_scene_type.SELF_CREATED();
  }

protected:
  // 0
  athena::interface::enum COMMON_;
  athena::interface::enum *COMMON_ptr_ = nullptr;
  // 1
  athena::interface::enum DEAD_END_;
  athena::interface::enum *DEAD_END_ptr_ = nullptr;
  // 2
  athena::interface::enum SELF_CREATED_;
  athena::interface::enum *SELF_CREATED_ptr_ = nullptr;
};
} // namespace interface
} // namespace athena
