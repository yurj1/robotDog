/**
 * @file    ultrasonic.hpp
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
#include "modules/common/interface/ultrasonic_obstacle.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class Ultrasonic {
public:
  Ultrasonic() {
    ranges_mutex_ = std::make_shared<std::mutex>();

    clear_ranges();
  }
  ~Ultrasonic() = default;

  inline void set_header(const athena::interface::Header& header) {
    header_ = header;
    header_ptr_ = &header_;
  }

  inline const athena::interface::Header& header() const { return header_; }

  inline athena::interface::Header* mutable_header() { return &header_; }

  inline bool has_header() { return (header_ptr_ != nullptr); }

  inline void
  set_ranges(std::vector<athena::interface::UltrasonicObstacle>* ranges) {
    std::lock_guard<std::mutex> lock(*ranges_mutex_);
    ranges_.assign(ranges->begin(), ranges->end());
  }

  inline void
  set_ranges(const std::vector<athena::interface::UltrasonicObstacle>& ranges) {
    std::lock_guard<std::mutex> lock(*ranges_mutex_);
    ranges_ = ranges;
  }

  inline void set_ranges(const uint32_t index,
                         athena::interface::UltrasonicObstacle& ranges) {
    std::lock_guard<std::mutex> lock(*ranges_mutex_);
    ranges_[index] = ranges;
  }

  inline void add_ranges(const athena::interface::UltrasonicObstacle& ranges) {
    std::lock_guard<std::mutex> lock(*ranges_mutex_);
    ranges_.emplace_back(ranges);
  }

  inline const athena::interface::UltrasonicObstacle&
  ranges(uint32_t index) const {
    std::lock_guard<std::mutex> lock(*ranges_mutex_);
    return ranges_[index];
  }

  inline std::vector<athena::interface::UltrasonicObstacle>* mutable_ranges() {
    std::lock_guard<std::mutex> lock(*ranges_mutex_);
    return &ranges_;
  }

  inline void
  ranges(std::vector<athena::interface::UltrasonicObstacle>& ranges) const {
    std::lock_guard<std::mutex> lock(*ranges_mutex_);
    ranges.assign(ranges_.begin(), ranges_.end());
  }

  inline const std::vector<athena::interface::UltrasonicObstacle>&
  ranges() const {
    std::lock_guard<std::mutex> lock(*ranges_mutex_);
    return ranges_;
  }

  inline uint32_t ranges_size() const {
    std::lock_guard<std::mutex> lock(*ranges_mutex_);
    return ranges_.size();
  }

  inline void clear_ranges() {
    std::lock_guard<std::mutex> lock(*ranges_mutex_);
    ranges_.clear();
    ranges_.shrink_to_fit();
  }

  inline bool has_ranges() { return (ranges_size() != 0); }

  void operator=(const Ultrasonic& ultrasonic) { CopyFrom(ultrasonic); }

  void CopyFrom(const Ultrasonic& ultrasonic) {
    header_ = ultrasonic.header();
    ranges_ = ultrasonic.ranges();
  }

protected:
  std::shared_ptr<std::mutex> ranges_mutex_;
  //消息头
  athena::interface::Header header_;
  athena::interface::Header* header_ptr_ = nullptr;
  //超声波障碍物数组
  std::vector<athena::interface::UltrasonicObstacle> ranges_;
};
} // namespace interface
} // namespace athena
