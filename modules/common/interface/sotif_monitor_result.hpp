/**
 * @file    sotif_monitor_result.hpp
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

#include "modules/common/interface/grid.hpp"
#include "modules/common/interface/header.hpp"
#include "modules/common/interface/region.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class SotifMonitorResult {
public:
  SotifMonitorResult() {
    region_value_mutex_ = std::make_shared<std::mutex>();
    grid_map_mutex_ = std::make_shared<std::mutex>();

    clear_region_value();
    clear_grid_map();
  }
  ~SotifMonitorResult() = default;

  inline void set_header(const athena::interface::Header& header) {
    header_ = header;
    header_ptr_ = &header_;
  }

  inline const athena::interface::Header& header() const { return header_; }

  inline athena::interface::Header* mutable_header() { return &header_; }

  inline bool has_header() { return (header_ptr_ != nullptr); }

  inline void
  set_region_value(std::vector<athena::interface::Region>* region_value) {
    std::lock_guard<std::mutex> lock(*region_value_mutex_);
    region_value_.assign(region_value->begin(), region_value->end());
  }

  inline void
  set_region_value(const std::vector<athena::interface::Region>& region_value) {
    std::lock_guard<std::mutex> lock(*region_value_mutex_);
    region_value_ = region_value;
  }

  inline void set_region_value(const uint32_t index,
                               athena::interface::Region& region_value) {
    std::lock_guard<std::mutex> lock(*region_value_mutex_);
    region_value_[index] = region_value;
  }

  inline void add_region_value(const athena::interface::Region& region_value) {
    std::lock_guard<std::mutex> lock(*region_value_mutex_);
    region_value_.emplace_back(region_value);
  }

  inline const athena::interface::Region& region_value(uint32_t index) const {
    std::lock_guard<std::mutex> lock(*region_value_mutex_);
    return region_value_[index];
  }

  inline std::vector<athena::interface::Region>* mutable_region_value() {
    std::lock_guard<std::mutex> lock(*region_value_mutex_);
    return &region_value_;
  }

  inline void
  region_value(std::vector<athena::interface::Region>& region_value) const {
    std::lock_guard<std::mutex> lock(*region_value_mutex_);
    region_value.assign(region_value_.begin(), region_value_.end());
  }

  inline const std::vector<athena::interface::Region>& region_value() const {
    std::lock_guard<std::mutex> lock(*region_value_mutex_);
    return region_value_;
  }

  inline uint32_t region_value_size() const {
    std::lock_guard<std::mutex> lock(*region_value_mutex_);
    return region_value_.size();
  }

  inline void clear_region_value() {
    std::lock_guard<std::mutex> lock(*region_value_mutex_);
    region_value_.clear();
    region_value_.shrink_to_fit();
  }

  inline bool has_region_value() { return (region_value_size() != 0); }

  inline void set_grid_map(std::vector<athena::interface::Grid>* grid_map) {
    std::lock_guard<std::mutex> lock(*grid_map_mutex_);
    grid_map_.assign(grid_map->begin(), grid_map->end());
  }

  inline void
  set_grid_map(const std::vector<athena::interface::Grid>& grid_map) {
    std::lock_guard<std::mutex> lock(*grid_map_mutex_);
    grid_map_ = grid_map;
  }

  inline void set_grid_map(const uint32_t index,
                           athena::interface::Grid& grid_map) {
    std::lock_guard<std::mutex> lock(*grid_map_mutex_);
    grid_map_[index] = grid_map;
  }

  inline void add_grid_map(const athena::interface::Grid& grid_map) {
    std::lock_guard<std::mutex> lock(*grid_map_mutex_);
    grid_map_.emplace_back(grid_map);
  }

  inline const athena::interface::Grid& grid_map(uint32_t index) const {
    std::lock_guard<std::mutex> lock(*grid_map_mutex_);
    return grid_map_[index];
  }

  inline std::vector<athena::interface::Grid>* mutable_grid_map() {
    std::lock_guard<std::mutex> lock(*grid_map_mutex_);
    return &grid_map_;
  }

  inline void grid_map(std::vector<athena::interface::Grid>& grid_map) const {
    std::lock_guard<std::mutex> lock(*grid_map_mutex_);
    grid_map.assign(grid_map_.begin(), grid_map_.end());
  }

  inline const std::vector<athena::interface::Grid>& grid_map() const {
    std::lock_guard<std::mutex> lock(*grid_map_mutex_);
    return grid_map_;
  }

  inline uint32_t grid_map_size() const {
    std::lock_guard<std::mutex> lock(*grid_map_mutex_);
    return grid_map_.size();
  }

  inline void clear_grid_map() {
    std::lock_guard<std::mutex> lock(*grid_map_mutex_);
    grid_map_.clear();
    grid_map_.shrink_to_fit();
  }

  inline bool has_grid_map() { return (grid_map_size() != 0); }

  void operator=(const SotifMonitorResult& sotif_monitor_result) {
    CopyFrom(sotif_monitor_result);
  }

  void CopyFrom(const SotifMonitorResult& sotif_monitor_result) {
    header_ = sotif_monitor_result.header();
    region_value_ = sotif_monitor_result.region_value();
    grid_map_ = sotif_monitor_result.grid_map();
  }

protected:
  std::shared_ptr<std::mutex> region_value_mutex_;
  std::shared_ptr<std::mutex> grid_map_mutex_;
  athena::interface::Header header_;
  athena::interface::Header* header_ptr_ = nullptr;
  //区域态势
  std::vector<athena::interface::Region> region_value_;
  //栅格地图
  std::vector<athena::interface::Grid> grid_map_;
};
} // namespace interface
} // namespace athena
