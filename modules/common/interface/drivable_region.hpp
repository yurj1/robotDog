/**
 * @file    drivable_region.hpp
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
#include "modules/common/interface/polygon_3d.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class DrivableRegion {
public:
  DrivableRegion() {
    drivable_region_mutex_ = std::make_shared<std::mutex>();

    clear_drivable_region();
  }
  ~DrivableRegion() = default;

  inline void set_header(const athena::interface::Header& header) {
    header_ = header;
    header_ptr_ = &header_;
  }

  inline const athena::interface::Header& header() const { return header_; }

  inline athena::interface::Header* mutable_header() { return &header_; }

  inline bool has_header() { return (header_ptr_ != nullptr); }

  inline void set_drivable_region(
      std::vector<athena::interface::Polygon3D>* drivable_region) {
    std::lock_guard<std::mutex> lock(*drivable_region_mutex_);
    drivable_region_.assign(drivable_region->begin(), drivable_region->end());
  }

  inline void set_drivable_region(
      const std::vector<athena::interface::Polygon3D>& drivable_region) {
    std::lock_guard<std::mutex> lock(*drivable_region_mutex_);
    drivable_region_ = drivable_region;
  }

  inline void
  set_drivable_region(const uint32_t index,
                      athena::interface::Polygon3D& drivable_region) {
    std::lock_guard<std::mutex> lock(*drivable_region_mutex_);
    drivable_region_[index] = drivable_region;
  }

  inline void
  add_drivable_region(const athena::interface::Polygon3D& drivable_region) {
    std::lock_guard<std::mutex> lock(*drivable_region_mutex_);
    drivable_region_.emplace_back(drivable_region);
  }

  inline const athena::interface::Polygon3D&
  drivable_region(uint32_t index) const {
    std::lock_guard<std::mutex> lock(*drivable_region_mutex_);
    return drivable_region_[index];
  }

  inline std::vector<athena::interface::Polygon3D>* mutable_drivable_region() {
    std::lock_guard<std::mutex> lock(*drivable_region_mutex_);
    return &drivable_region_;
  }

  inline void drivable_region(
      std::vector<athena::interface::Polygon3D>& drivable_region) const {
    std::lock_guard<std::mutex> lock(*drivable_region_mutex_);
    drivable_region.assign(drivable_region_.begin(), drivable_region_.end());
  }

  inline const std::vector<athena::interface::Polygon3D>&
  drivable_region() const {
    std::lock_guard<std::mutex> lock(*drivable_region_mutex_);
    return drivable_region_;
  }

  inline uint32_t drivable_region_size() const {
    std::lock_guard<std::mutex> lock(*drivable_region_mutex_);
    return drivable_region_.size();
  }

  inline void clear_drivable_region() {
    std::lock_guard<std::mutex> lock(*drivable_region_mutex_);
    drivable_region_.clear();
    drivable_region_.shrink_to_fit();
  }

  inline bool has_drivable_region() { return (drivable_region_size() != 0); }

  void operator=(const DrivableRegion& drivable_region) {
    CopyFrom(drivable_region);
  }

  void CopyFrom(const DrivableRegion& drivable_region) {
    header_ = drivable_region.header();
    drivable_region_ = drivable_region.drivable_region();
  }

protected:
  std::shared_ptr<std::mutex> drivable_region_mutex_;
  // timestamp is included in header
  athena::interface::Header header_;
  athena::interface::Header* header_ptr_ = nullptr;
  //可行驶区域
  std::vector<athena::interface::Polygon3D> drivable_region_;
};
} // namespace interface
} // namespace athena
