/**
 * @file    road_mark_list.hpp
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
#include "modules/common/interface/road_mark.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class RoadMarkList {
public:
  RoadMarkList() {
    roadmarks_mutex_ = std::make_shared<std::mutex>();

    clear_roadmarks();
  }
  ~RoadMarkList() = default;

  inline void set_header(const athena::interface::Header& header) {
    header_ = header;
    header_ptr_ = &header_;
  }

  inline const athena::interface::Header& header() const { return header_; }

  inline athena::interface::Header* mutable_header() { return &header_; }

  inline bool has_header() { return (header_ptr_ != nullptr); }

  inline void
  set_roadmarks(std::vector<athena::interface::RoadMark>* roadmarks) {
    std::lock_guard<std::mutex> lock(*roadmarks_mutex_);
    roadmarks_.assign(roadmarks->begin(), roadmarks->end());
  }

  inline void
  set_roadmarks(const std::vector<athena::interface::RoadMark>& roadmarks) {
    std::lock_guard<std::mutex> lock(*roadmarks_mutex_);
    roadmarks_ = roadmarks;
  }

  inline void set_roadmarks(const uint32_t index,
                            athena::interface::RoadMark& roadmarks) {
    std::lock_guard<std::mutex> lock(*roadmarks_mutex_);
    roadmarks_[index] = roadmarks;
  }

  inline void add_roadmarks(const athena::interface::RoadMark& roadmarks) {
    std::lock_guard<std::mutex> lock(*roadmarks_mutex_);
    roadmarks_.emplace_back(roadmarks);
  }

  inline const athena::interface::RoadMark& roadmarks(uint32_t index) const {
    std::lock_guard<std::mutex> lock(*roadmarks_mutex_);
    return roadmarks_[index];
  }

  inline std::vector<athena::interface::RoadMark>* mutable_roadmarks() {
    std::lock_guard<std::mutex> lock(*roadmarks_mutex_);
    return &roadmarks_;
  }

  inline void
  roadmarks(std::vector<athena::interface::RoadMark>& roadmarks) const {
    std::lock_guard<std::mutex> lock(*roadmarks_mutex_);
    roadmarks.assign(roadmarks_.begin(), roadmarks_.end());
  }

  inline const std::vector<athena::interface::RoadMark>& roadmarks() const {
    std::lock_guard<std::mutex> lock(*roadmarks_mutex_);
    return roadmarks_;
  }

  inline uint32_t roadmarks_size() const {
    std::lock_guard<std::mutex> lock(*roadmarks_mutex_);
    return roadmarks_.size();
  }

  inline void clear_roadmarks() {
    std::lock_guard<std::mutex> lock(*roadmarks_mutex_);
    roadmarks_.clear();
    roadmarks_.shrink_to_fit();
  }

  inline bool has_roadmarks() { return (roadmarks_size() != 0); }

  void operator=(const RoadMarkList& road_mark_list) {
    CopyFrom(road_mark_list);
  }

  void CopyFrom(const RoadMarkList& road_mark_list) {
    header_ = road_mark_list.header();
    roadmarks_ = road_mark_list.roadmarks();
  }

protected:
  std::shared_ptr<std::mutex> roadmarks_mutex_;
  // timestamp is included in header
  athena::interface::Header header_;
  athena::interface::Header* header_ptr_ = nullptr;
  //交通标识列表
  std::vector<athena::interface::RoadMark> roadmarks_;
};
} // namespace interface
} // namespace athena
