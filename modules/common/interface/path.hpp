/**
 * @file    path.hpp
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#pragma once

#include <mutex>
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include <stdint.h>

#include "modules/common/interface/path_point.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class Path {
public:
  Path() {
    path_points_mutex_ = std::make_shared<std::mutex>();

    name_.clear();
    clear_path_points();
  }
  ~Path() = default;

  inline void set_name(const std::string& name) {
    name_ = name;
    name_ptr_ = &name_;
  }

  inline const std::string& name() const { return name_; }

  inline std::string* mutable_name() { return &name_; }

  inline bool has_name() { return (name_ptr_ != nullptr); }

  inline void
  set_path_points(std::vector<athena::interface::PathPoint>* path_points) {
    std::lock_guard<std::mutex> lock(*path_points_mutex_);
    path_points_.assign(path_points->begin(), path_points->end());
  }

  inline void set_path_points(
      const std::vector<athena::interface::PathPoint>& path_points) {
    std::lock_guard<std::mutex> lock(*path_points_mutex_);
    path_points_ = path_points;
  }

  inline void set_path_points(const uint32_t index,
                              athena::interface::PathPoint& path_points) {
    std::lock_guard<std::mutex> lock(*path_points_mutex_);
    path_points_[index] = path_points;
  }

  inline void add_path_points(const athena::interface::PathPoint& path_points) {
    std::lock_guard<std::mutex> lock(*path_points_mutex_);
    path_points_.emplace_back(path_points);
  }

  inline const athena::interface::PathPoint& path_points(uint32_t index) const {
    std::lock_guard<std::mutex> lock(*path_points_mutex_);
    return path_points_[index];
  }

  inline std::vector<athena::interface::PathPoint>* mutable_path_points() {
    std::lock_guard<std::mutex> lock(*path_points_mutex_);
    return &path_points_;
  }

  inline void
  path_points(std::vector<athena::interface::PathPoint>& path_points) const {
    std::lock_guard<std::mutex> lock(*path_points_mutex_);
    path_points.assign(path_points_.begin(), path_points_.end());
  }

  inline const std::vector<athena::interface::PathPoint>& path_points() const {
    std::lock_guard<std::mutex> lock(*path_points_mutex_);
    return path_points_;
  }

  inline uint32_t path_points_size() const {
    std::lock_guard<std::mutex> lock(*path_points_mutex_);
    return path_points_.size();
  }

  inline void clear_path_points() {
    std::lock_guard<std::mutex> lock(*path_points_mutex_);
    path_points_.clear();
    path_points_.shrink_to_fit();
  }

  inline bool has_path_points() { return (path_points_size() != 0); }

  void operator=(const Path& path) { CopyFrom(path); }

  void CopyFrom(const Path& path) {
    name_ = path.name();
    path_points_ = path.path_points();
  }

protected:
  std::shared_ptr<std::mutex> path_points_mutex_;
  //名称
  std::string name_;
  std::string* name_ptr_ = nullptr;
  //路径点集
  std::vector<athena::interface::PathPoint> path_points_;
};
} // namespace interface
} // namespace athena
