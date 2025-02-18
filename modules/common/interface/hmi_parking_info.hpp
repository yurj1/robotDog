/**
 * @file    hmi_parking_info.hpp
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
#include "modules/common/interface/polygon_3d.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class HMIParkingInfo {
public:
  HMIParkingInfo() {
    parking_space_id_ = 0;
    parking_type_ = athena::common::ParkingType::INVALID_PARKING;
    parking_status_ = athena::common::ParkingStatus::PARKING_ENABLE;
    theta_ = 0.0;
    width_ = 0.0;
    length_ = 0.0;
    is_custom_parking_ = false;
    parking_source_type_ = athena::common::ParkingSourceType::LINE_PARKING;
  }
  ~HMIParkingInfo() = default;

  inline void set_header(const athena::interface::Header& header) {
    header_ = header;
    header_ptr_ = &header_;
  }

  inline const athena::interface::Header& header() const { return header_; }

  inline athena::interface::Header* mutable_header() { return &header_; }

  inline bool has_header() { return (header_ptr_ != nullptr); }

  inline void set_parking_space_id(const int32_t& parking_space_id) {
    parking_space_id_ = parking_space_id;
    parking_space_id_ptr_ = &parking_space_id_;
  }

  inline const int32_t& parking_space_id() const { return parking_space_id_; }

  inline int32_t* mutable_parking_space_id() { return &parking_space_id_; }

  inline bool has_parking_space_id() {
    return (parking_space_id_ptr_ != nullptr);
  }

  inline void
  set_parking_type(const athena::common::ParkingType& parking_type) {
    parking_type_ = parking_type;
    parking_type_ptr_ = &parking_type_;
  }

  inline const athena::common::ParkingType& parking_type() const {
    return parking_type_;
  }

  inline athena::common::ParkingType* mutable_parking_type() {
    return &parking_type_;
  }

  inline bool has_parking_type() { return (parking_type_ptr_ != nullptr); }

  inline void
  set_parking_status(const athena::common::ParkingStatus& parking_status) {
    parking_status_ = parking_status;
    parking_status_ptr_ = &parking_status_;
  }

  inline const athena::common::ParkingStatus& parking_status() const {
    return parking_status_;
  }

  inline athena::common::ParkingStatus* mutable_parking_status() {
    return &parking_status_;
  }

  inline bool has_parking_status() { return (parking_status_ptr_ != nullptr); }

  inline void set_center_point_of_parking(
      const athena::interface::Point3D& center_point_of_parking) {
    center_point_of_parking_ = center_point_of_parking;
    center_point_of_parking_ptr_ = &center_point_of_parking_;
  }

  inline const athena::interface::Point3D& center_point_of_parking() const {
    return center_point_of_parking_;
  }

  inline athena::interface::Point3D* mutable_center_point_of_parking() {
    return &center_point_of_parking_;
  }

  inline bool has_center_point_of_parking() {
    return (center_point_of_parking_ptr_ != nullptr);
  }

  inline void set_theta(const double& theta) {
    theta_ = theta;
    theta_ptr_ = &theta_;
  }

  inline const double& theta() const { return theta_; }

  inline double* mutable_theta() { return &theta_; }

  inline bool has_theta() { return (theta_ptr_ != nullptr); }

  inline void set_width(const double& width) {
    width_ = width;
    width_ptr_ = &width_;
  }

  inline const double& width() const { return width_; }

  inline double* mutable_width() { return &width_; }

  inline bool has_width() { return (width_ptr_ != nullptr); }

  inline void set_length(const double& length) {
    length_ = length;
    length_ptr_ = &length_;
  }

  inline const double& length() const { return length_; }

  inline double* mutable_length() { return &length_; }

  inline bool has_length() { return (length_ptr_ != nullptr); }

  inline void set_is_custom_parking(const bool& is_custom_parking) {
    is_custom_parking_ = is_custom_parking;
    is_custom_parking_ptr_ = &is_custom_parking_;
  }

  inline const bool& is_custom_parking() const { return is_custom_parking_; }

  inline bool* mutable_is_custom_parking() { return &is_custom_parking_; }

  inline bool has_is_custom_parking() {
    return (is_custom_parking_ptr_ != nullptr);
  }

  inline void set_polygon(const athena::interface::Polygon3D& polygon) {
    polygon_ = polygon;
    polygon_ptr_ = &polygon_;
  }

  inline const athena::interface::Polygon3D& polygon() const {
    return polygon_;
  }

  inline athena::interface::Polygon3D* mutable_polygon() { return &polygon_; }

  inline bool has_polygon() { return (polygon_ptr_ != nullptr); }

  inline void set_parking_source_type(
      const athena::common::ParkingSourceType& parking_source_type) {
    parking_source_type_ = parking_source_type;
    parking_source_type_ptr_ = &parking_source_type_;
  }

  inline const athena::common::ParkingSourceType& parking_source_type() const {
    return parking_source_type_;
  }

  inline athena::common::ParkingSourceType* mutable_parking_source_type() {
    return &parking_source_type_;
  }

  inline bool has_parking_source_type() {
    return (parking_source_type_ptr_ != nullptr);
  }

  void operator=(const HMIParkingInfo& hmi_parking_info) {
    CopyFrom(hmi_parking_info);
  }

  void CopyFrom(const HMIParkingInfo& hmi_parking_info) {
    header_ = hmi_parking_info.header();
    parking_space_id_ = hmi_parking_info.parking_space_id();
    parking_type_ = hmi_parking_info.parking_type();
    parking_status_ = hmi_parking_info.parking_status();
    center_point_of_parking_ = hmi_parking_info.center_point_of_parking();
    theta_ = hmi_parking_info.theta();
    width_ = hmi_parking_info.width();
    length_ = hmi_parking_info.length();
    is_custom_parking_ = hmi_parking_info.is_custom_parking();
    polygon_ = hmi_parking_info.polygon();
    parking_source_type_ = hmi_parking_info.parking_source_type();
  }

protected:
  // timestamp is  included in header
  athena::interface::Header header_;
  athena::interface::Header* header_ptr_ = nullptr;
  //// 停车位id
  int32_t parking_space_id_;
  int32_t* parking_space_id_ptr_ = nullptr;
  //// PARKING_TYPE=0 //无效泊车 PARKING_TYPE=1 //水平泊车 PARKING_TYPE=2
  /////垂直泊车 PARKING_TYPE=3 //倾斜泊车
  athena::common::ParkingType parking_type_;
  athena::common::ParkingType* parking_type_ptr_ = nullptr;
  // PARKING_ENABLE=0//可泊 PARKING_DISENABLE=1//不可泊
  // PARKING_NONOPTIONAL=2//不可选
  athena::common::ParkingStatus parking_status_;
  athena::common::ParkingStatus* parking_status_ptr_ = nullptr;
  //// 世界坐标系下停车位中心点
  athena::interface::Point3D center_point_of_parking_;
  athena::interface::Point3D* center_point_of_parking_ptr_ = nullptr;
  //// 世界坐标系下的夹角（单位rad），车位出口与正东方向夹角
  double theta_;
  double* theta_ptr_ = nullptr;
  //// 停车位宽（单位m）
  double width_;
  double* width_ptr_ = nullptr;
  //// 停车位长单位m）
  double length_;
  double* length_ptr_ = nullptr;
  //// 是否是自定义车位
  bool is_custom_parking_;
  bool* is_custom_parking_ptr_ = nullptr;
  //世界坐标系下的车位多边形
  athena::interface::Polygon3D polygon_;
  athena::interface::Polygon3D* polygon_ptr_ = nullptr;
  // 0-线车位， 1-空间车位， 2-融合车位
  athena::common::ParkingSourceType parking_source_type_;
  athena::common::ParkingSourceType* parking_source_type_ptr_ = nullptr;
};
} // namespace interface
} // namespace athena
