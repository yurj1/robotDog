/**
 * @file    polygon_3d.hpp
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

#include "modules/common/enum/enum.h"
#include "modules/common/interface/point_3d.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class Polygon3D {
public:
  Polygon3D() {
    points_mutex_ = std::make_shared<std::mutex>();

    coordinate_system_ =
        athena::common::CoordinateSystem::INVALID_COORDINATE_SYSTEM;
    clear_points();
  }
  ~Polygon3D() = default;

  inline void set_coordinate_system(
      const athena::common::CoordinateSystem& coordinate_system) {
    coordinate_system_ = coordinate_system;
    coordinate_system_ptr_ = &coordinate_system_;
  }

  inline const athena::common::CoordinateSystem& coordinate_system() const {
    return coordinate_system_;
  }

  inline athena::common::CoordinateSystem* mutable_coordinate_system() {
    return &coordinate_system_;
  }

  inline bool has_coordinate_system() {
    return (coordinate_system_ptr_ != nullptr);
  }

  inline void set_points(std::vector<athena::interface::Point3D>* points) {
    std::lock_guard<std::mutex> lock(*points_mutex_);
    points_.assign(points->begin(), points->end());
  }

  inline void
  set_points(const std::vector<athena::interface::Point3D>& points) {
    std::lock_guard<std::mutex> lock(*points_mutex_);
    points_ = points;
  }

  inline void set_points(const uint32_t index,
                         athena::interface::Point3D& points) {
    std::lock_guard<std::mutex> lock(*points_mutex_);
    points_[index] = points;
  }

  inline void add_points(const athena::interface::Point3D& points) {
    std::lock_guard<std::mutex> lock(*points_mutex_);
    points_.emplace_back(points);
  }

  inline const athena::interface::Point3D& points(uint32_t index) const {
    std::lock_guard<std::mutex> lock(*points_mutex_);
    return points_[index];
  }

  inline std::vector<athena::interface::Point3D>* mutable_points() {
    std::lock_guard<std::mutex> lock(*points_mutex_);
    return &points_;
  }

  inline void points(std::vector<athena::interface::Point3D>& points) const {
    std::lock_guard<std::mutex> lock(*points_mutex_);
    points.assign(points_.begin(), points_.end());
  }

  inline const std::vector<athena::interface::Point3D>& points() const {
    std::lock_guard<std::mutex> lock(*points_mutex_);
    return points_;
  }

  inline uint32_t points_size() const {
    std::lock_guard<std::mutex> lock(*points_mutex_);
    return points_.size();
  }

  inline void clear_points() {
    std::lock_guard<std::mutex> lock(*points_mutex_);
    points_.clear();
    points_.shrink_to_fit();
  }

  inline bool has_points() { return (points_size() != 0); }

  void operator=(const Polygon3D& polygon_3d) { CopyFrom(polygon_3d); }

  void CopyFrom(const Polygon3D& polygon_3d) {
    coordinate_system_ = polygon_3d.coordinate_system();
    points_ = polygon_3d.points();
  }

protected:
  std::shared_ptr<std::mutex> points_mutex_;
  //坐标系
  athena::common::CoordinateSystem coordinate_system_;
  athena::common::CoordinateSystem* coordinate_system_ptr_ = nullptr;
  //三维点集
  std::vector<athena::interface::Point3D> points_;
};
} // namespace interface
} // namespace athena
