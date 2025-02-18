/**
 * @file    point_2d_list.hpp
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

#include "modules/common/interface/point_2d.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class Point2dList {
public:
  Point2dList() {
    point2d_list_mutex_ = std::make_shared<std::mutex>();

    clear_point2d_list();
  }
  ~Point2dList() = default;

  inline void
  set_point2d_list(std::vector<athena::interface::Point2D>* point2d_list) {
    std::lock_guard<std::mutex> lock(*point2d_list_mutex_);
    point2d_list_.assign(point2d_list->begin(), point2d_list->end());
  }

  inline void set_point2d_list(
      const std::vector<athena::interface::Point2D>& point2d_list) {
    std::lock_guard<std::mutex> lock(*point2d_list_mutex_);
    point2d_list_ = point2d_list;
  }

  inline void set_point2d_list(const uint32_t index,
                               athena::interface::Point2D& point2d_list) {
    std::lock_guard<std::mutex> lock(*point2d_list_mutex_);
    point2d_list_[index] = point2d_list;
  }

  inline void add_point2d_list(const athena::interface::Point2D& point2d_list) {
    std::lock_guard<std::mutex> lock(*point2d_list_mutex_);
    point2d_list_.emplace_back(point2d_list);
  }

  inline const athena::interface::Point2D& point2d_list(uint32_t index) const {
    std::lock_guard<std::mutex> lock(*point2d_list_mutex_);
    return point2d_list_[index];
  }

  inline std::vector<athena::interface::Point2D>* mutable_point2d_list() {
    std::lock_guard<std::mutex> lock(*point2d_list_mutex_);
    return &point2d_list_;
  }

  inline void
  point2d_list(std::vector<athena::interface::Point2D>& point2d_list) const {
    std::lock_guard<std::mutex> lock(*point2d_list_mutex_);
    point2d_list.assign(point2d_list_.begin(), point2d_list_.end());
  }

  inline const std::vector<athena::interface::Point2D>& point2d_list() const {
    std::lock_guard<std::mutex> lock(*point2d_list_mutex_);
    return point2d_list_;
  }

  inline uint32_t point2d_list_size() const {
    std::lock_guard<std::mutex> lock(*point2d_list_mutex_);
    return point2d_list_.size();
  }

  inline void clear_point2d_list() {
    std::lock_guard<std::mutex> lock(*point2d_list_mutex_);
    point2d_list_.clear();
    point2d_list_.shrink_to_fit();
  }

  inline bool has_point2d_list() { return (point2d_list_size() != 0); }

  void operator=(const Point2dList& point_2d_list) { CopyFrom(point_2d_list); }

  void CopyFrom(const Point2dList& point_2d_list) {
    point2d_list_ = point_2d_list.point2d_list();
  }

protected:
  std::shared_ptr<std::mutex> point2d_list_mutex_;
  std::vector<athena::interface::Point2D> point2d_list_;
};
} // namespace interface
} // namespace athena
