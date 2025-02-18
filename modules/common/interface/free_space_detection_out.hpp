/**
 * @file    free_space_detection_out.hpp
 * @author  hyzx
 * @date    2021-12-07
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
#include "modules/common/interface/polygon_2d.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class FreeSpaceDetectionOut {
public:
  FreeSpaceDetectionOut() {
    freespace_region_mutex_ = std::make_shared<std::mutex>();

    clear_freespace_region();
  }
  ~FreeSpaceDetectionOut() = default;

  inline void set_header(const athena::interface::Header& header) {
    header_ = header;
  }

  inline const athena::interface::Header& header() const { return header_; }

  inline athena::interface::Header* mutable_header() { return &header_; }

  inline void set_freespace_region(
      std::vector<athena::interface::Polygon2D>* freespace_region) {
    std::lock_guard<std::mutex> lock(*freespace_region_mutex_);
    freespace_region_.assign(freespace_region->begin(),
                             freespace_region->end());
  }

  inline void set_freespace_region(
      const std::vector<athena::interface::Polygon2D>& freespace_region) {
    std::lock_guard<std::mutex> lock(*freespace_region_mutex_);
    freespace_region_ = freespace_region;
  }

  inline void
  set_freespace_region(const uint32_t index,
                       athena::interface::Polygon2D& freespace_region) {
    std::lock_guard<std::mutex> lock(*freespace_region_mutex_);
    freespace_region_[index] = freespace_region;
  }

  inline void
  add_freespace_region(const athena::interface::Polygon2D& freespace_region) {
    std::lock_guard<std::mutex> lock(*freespace_region_mutex_);
    freespace_region_.emplace_back(freespace_region);
  }

  inline const athena::interface::Polygon2D&
  freespace_region(uint32_t index) const {
    std::lock_guard<std::mutex> lock(*freespace_region_mutex_);
    return freespace_region_[index];
  }

  inline std::vector<athena::interface::Polygon2D>* mutable_freespace_region() {
    std::lock_guard<std::mutex> lock(*freespace_region_mutex_);
    return &freespace_region_;
  }

  inline void freespace_region(
      std::vector<athena::interface::Polygon2D>& freespace_region) const {
    std::lock_guard<std::mutex> lock(*freespace_region_mutex_);
    freespace_region.assign(freespace_region_.begin(), freespace_region_.end());
  }

  inline const std::vector<athena::interface::Polygon2D>&
  freespace_region() const {
    std::lock_guard<std::mutex> lock(*freespace_region_mutex_);
    return freespace_region_;
  }

  inline uint32_t freespace_region_size() const {
    std::lock_guard<std::mutex> lock(*freespace_region_mutex_);
    return freespace_region_.size();
  }

  inline void clear_freespace_region() {
    std::lock_guard<std::mutex> lock(*freespace_region_mutex_);
    freespace_region_.clear();
  }

protected:
  std::shared_ptr<std::mutex> freespace_region_mutex_;
  // timestamp is included in header
  athena::interface::Header header_;
  // freespace轮廓图像坐标
  std::vector<athena::interface::Polygon2D> freespace_region_;
};
} // namespace interface
} // namespace athena
