/**
 * @file    end_points.hpp
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#pragma once

#include <iostream>
#include <stdint.h>

#include "modules/common/interface/point_2d.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class EndPoints {
public:
  EndPoints() = default;
  ~EndPoints() = default;

  inline void set_start(const athena::interface::Point2D& start) {
    start_ = start;
    start_ptr_ = &start_;
  }

  inline const athena::interface::Point2D& start() const { return start_; }

  inline athena::interface::Point2D* mutable_start() { return &start_; }

  inline bool has_start() { return (start_ptr_ != nullptr); }

  inline void set_end(const athena::interface::Point2D& end) {
    end_ = end;
    end_ptr_ = &end_;
  }

  inline const athena::interface::Point2D& end() const { return end_; }

  inline athena::interface::Point2D* mutable_end() { return &end_; }

  inline bool has_end() { return (end_ptr_ != nullptr); }

  void operator=(const EndPoints& end_points) { CopyFrom(end_points); }

  void CopyFrom(const EndPoints& end_points) {
    start_ = end_points.start();
    end_ = end_points.end();
  }

protected:
  //车道线上顶点
  athena::interface::Point2D start_;
  athena::interface::Point2D* start_ptr_ = nullptr;
  //车道线下顶点
  athena::interface::Point2D end_;
  athena::interface::Point2D* end_ptr_ = nullptr;
};
} // namespace interface
} // namespace athena
