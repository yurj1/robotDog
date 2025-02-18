/**
 * @file    vehicle_config.hpp
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
#include "modules/common/interface/vehicle_param.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class VehicleConfig {
public:
  VehicleConfig() = default;
  ~VehicleConfig() = default;

  inline void set_header(const athena::interface::Header& header) {
    header_ = header;
    header_ptr_ = &header_;
  }

  inline const athena::interface::Header& header() const { return header_; }

  inline athena::interface::Header* mutable_header() { return &header_; }

  inline bool has_header() { return (header_ptr_ != nullptr); }

  inline void
  set_vehicle_param(const athena::interface::VehicleParam& vehicle_param) {
    vehicle_param_ = vehicle_param;
    vehicle_param_ptr_ = &vehicle_param_;
  }

  inline const athena::interface::VehicleParam& vehicle_param() const {
    return vehicle_param_;
  }

  inline athena::interface::VehicleParam* mutable_vehicle_param() {
    return &vehicle_param_;
  }

  inline bool has_vehicle_param() { return (vehicle_param_ptr_ != nullptr); }

  void operator=(const VehicleConfig& vehicle_config) {
    CopyFrom(vehicle_config);
  }

  void CopyFrom(const VehicleConfig& vehicle_config) {
    header_ = vehicle_config.header();
    vehicle_param_ = vehicle_config.vehicle_param();
  }

protected:
  athena::interface::Header header_;
  athena::interface::Header* header_ptr_ = nullptr;
  //车辆参数表
  athena::interface::VehicleParam vehicle_param_;
  athena::interface::VehicleParam* vehicle_param_ptr_ = nullptr;
};
} // namespace interface
} // namespace athena
