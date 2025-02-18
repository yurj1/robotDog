/**
 * @file    uss_parking_info.hpp
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
class UssParkingInfo {
public:
  UssParkingInfo() {
    uss_parking_type_ = athena::common::UssParkingType::RIGHT_PARALLEL_PARKING;
  }
  ~UssParkingInfo() = default;

  inline void set_header(const athena::interface::Header& header) {
    header_ = header;
    header_ptr_ = &header_;
  }

  inline const athena::interface::Header& header() const { return header_; }

  inline athena::interface::Header* mutable_header() { return &header_; }

  inline bool has_header() { return (header_ptr_ != nullptr); }

  inline void
  set_uss_parking_type(const athena::common::UssParkingType& uss_parking_type) {
    uss_parking_type_ = uss_parking_type;
    uss_parking_type_ptr_ = &uss_parking_type_;
  }

  inline const athena::common::UssParkingType& uss_parking_type() const {
    return uss_parking_type_;
  }

  inline athena::common::UssParkingType* mutable_uss_parking_type() {
    return &uss_parking_type_;
  }

  inline bool has_uss_parking_type() {
    return (uss_parking_type_ptr_ != nullptr);
  }

  inline void
  set_parking_point0(const athena::interface::Point3D& parking_point0) {
    parking_point0_ = parking_point0;
    parking_point0_ptr_ = &parking_point0_;
  }

  inline const athena::interface::Point3D& parking_point0() const {
    return parking_point0_;
  }

  inline athena::interface::Point3D* mutable_parking_point0() {
    return &parking_point0_;
  }

  inline bool has_parking_point0() { return (parking_point0_ptr_ != nullptr); }

  inline void
  set_parking_point1(const athena::interface::Point3D& parking_point1) {
    parking_point1_ = parking_point1;
    parking_point1_ptr_ = &parking_point1_;
  }

  inline const athena::interface::Point3D& parking_point1() const {
    return parking_point1_;
  }

  inline athena::interface::Point3D* mutable_parking_point1() {
    return &parking_point1_;
  }

  inline bool has_parking_point1() { return (parking_point1_ptr_ != nullptr); }

  inline void
  set_parking_point2(const athena::interface::Point3D& parking_point2) {
    parking_point2_ = parking_point2;
    parking_point2_ptr_ = &parking_point2_;
  }

  inline const athena::interface::Point3D& parking_point2() const {
    return parking_point2_;
  }

  inline athena::interface::Point3D* mutable_parking_point2() {
    return &parking_point2_;
  }

  inline bool has_parking_point2() { return (parking_point2_ptr_ != nullptr); }

  inline void
  set_parking_point3(const athena::interface::Point3D& parking_point3) {
    parking_point3_ = parking_point3;
    parking_point3_ptr_ = &parking_point3_;
  }

  inline const athena::interface::Point3D& parking_point3() const {
    return parking_point3_;
  }

  inline athena::interface::Point3D* mutable_parking_point3() {
    return &parking_point3_;
  }

  inline bool has_parking_point3() { return (parking_point3_ptr_ != nullptr); }

  void operator=(const UssParkingInfo& uss_parking_info) {
    CopyFrom(uss_parking_info);
  }

  void CopyFrom(const UssParkingInfo& uss_parking_info) {
    header_ = uss_parking_info.header();
    uss_parking_type_ = uss_parking_info.uss_parking_type();
    parking_point0_ = uss_parking_info.parking_point0();
    parking_point1_ = uss_parking_info.parking_point1();
    parking_point2_ = uss_parking_info.parking_point2();
    parking_point3_ = uss_parking_info.parking_point3();
  }

protected:
  // timestamp is included in header
  athena::interface::Header header_;
  athena::interface::Header* header_ptr_ = nullptr;
  //超声波车位类型： 0-右侧平行 1-左侧平行 2-右侧垂直 3-左侧垂直
  athena::common::UssParkingType uss_parking_type_;
  athena::common::UssParkingType* uss_parking_type_ptr_ = nullptr;
  //车体中心坐标系下，超声波车位0点位置
  athena::interface::Point3D parking_point0_;
  athena::interface::Point3D* parking_point0_ptr_ = nullptr;
  //车体中心坐标系下，超声波车位1点位置
  athena::interface::Point3D parking_point1_;
  athena::interface::Point3D* parking_point1_ptr_ = nullptr;
  //车体中心坐标系下，超声波车位2点位置
  athena::interface::Point3D parking_point2_;
  athena::interface::Point3D* parking_point2_ptr_ = nullptr;
  //车体中心坐标系下，超声波车位3点位置
  athena::interface::Point3D parking_point3_;
  athena::interface::Point3D* parking_point3_ptr_ = nullptr;
};
} // namespace interface
} // namespace athena
