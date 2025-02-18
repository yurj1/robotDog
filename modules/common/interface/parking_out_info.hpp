/**
 * @file    parking_out_info.hpp
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#pragma once

#include <iostream>
#include <stdint.h>

#include "modules/common/enum/enum.h"
#include "modules/common/interface/header.hpp"
#include "modules/common/interface/point_3d.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class ParkingOutInfo {
public:
  ParkingOutInfo() {
    parking_out_id_ = 0;
    parking_direction_type_ = athena::common::Direction::DIR_INVALID;
    is_parking_out_enable_ = false;
    theta_ = 0.0;
  }
  ~ParkingOutInfo() = default;

  inline void set_header(const athena::interface::Header& header) {
    header_ = header;
    header_ptr_ = &header_;
  }

  inline const athena::interface::Header& header() const { return header_; }

  inline athena::interface::Header* mutable_header() { return &header_; }

  inline bool has_header() { return (header_ptr_ != nullptr); }

  inline void set_parking_out_id(const int32_t& parking_out_id) {
    parking_out_id_ = parking_out_id;
    parking_out_id_ptr_ = &parking_out_id_;
  }

  inline const int32_t& parking_out_id() const { return parking_out_id_; }

  inline int32_t* mutable_parking_out_id() { return &parking_out_id_; }

  inline bool has_parking_out_id() { return (parking_out_id_ptr_ != nullptr); }

  inline void set_parking_direction_type(
      const athena::common::Direction& parking_direction_type) {
    parking_direction_type_ = parking_direction_type;
    parking_direction_type_ptr_ = &parking_direction_type_;
  }

  inline const athena::common::Direction& parking_direction_type() const {
    return parking_direction_type_;
  }

  inline athena::common::Direction* mutable_parking_direction_type() {
    return &parking_direction_type_;
  }

  inline bool has_parking_direction_type() {
    return (parking_direction_type_ptr_ != nullptr);
  }

  inline void set_is_parking_out_enable(const bool& is_parking_out_enable) {
    is_parking_out_enable_ = is_parking_out_enable;
    is_parking_out_enable_ptr_ = &is_parking_out_enable_;
  }

  inline const bool& is_parking_out_enable() const {
    return is_parking_out_enable_;
  }

  inline bool* mutable_is_parking_out_enable() {
    return &is_parking_out_enable_;
  }

  inline bool has_is_parking_out_enable() {
    return (is_parking_out_enable_ptr_ != nullptr);
  }

  inline void
  set_parking_out_point(const athena::interface::Point3D& parking_out_point) {
    parking_out_point_ = parking_out_point;
    parking_out_point_ptr_ = &parking_out_point_;
  }

  inline const athena::interface::Point3D& parking_out_point() const {
    return parking_out_point_;
  }

  inline athena::interface::Point3D* mutable_parking_out_point() {
    return &parking_out_point_;
  }

  inline bool has_parking_out_point() {
    return (parking_out_point_ptr_ != nullptr);
  }

  inline void set_theta(const double& theta) {
    theta_ = theta;
    theta_ptr_ = &theta_;
  }

  inline const double& theta() const { return theta_; }

  inline double* mutable_theta() { return &theta_; }

  inline bool has_theta() { return (theta_ptr_ != nullptr); }

  void operator=(const ParkingOutInfo& parking_out_info) {
    CopyFrom(parking_out_info);
  }

  void CopyFrom(const ParkingOutInfo& parking_out_info) {
    header_ = parking_out_info.header();
    parking_out_id_ = parking_out_info.parking_out_id();
    parking_direction_type_ = parking_out_info.parking_direction_type();
    is_parking_out_enable_ = parking_out_info.is_parking_out_enable();
    parking_out_point_ = parking_out_info.parking_out_point();
    theta_ = parking_out_info.theta();
  }

protected:
  // timestamp is included in header
  athena::interface::Header header_;
  athena::interface::Header* header_ptr_ = nullptr;
  //若车位有id，同停车位id
  int32_t parking_out_id_;
  int32_t* parking_out_id_ptr_ = nullptr;
  athena::common::Direction parking_direction_type_;
  athena::common::Direction* parking_direction_type_ptr_ = nullptr;
  // true可泊出，false不可泊出
  bool is_parking_out_enable_;
  bool* is_parking_out_enable_ptr_ = nullptr;
  //世界坐标系下提车点位置
  athena::interface::Point3D parking_out_point_;
  athena::interface::Point3D* parking_out_point_ptr_ = nullptr;
  //世界坐标系下的夹角（单位rad），提车点与正东方向夹角
  double theta_;
  double* theta_ptr_ = nullptr;
};
} // namespace interface
} // namespace athena
