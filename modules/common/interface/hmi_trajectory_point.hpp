/**
 * @file    hmi_trajectory_point.hpp
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#pragma once

#include <iostream>
#include <stdint.h>

#include "modules/common/interface/point_3d.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class HMITrajectoryPoint {
public:
  HMITrajectoryPoint() { v_ = 0.0; }
  ~HMITrajectoryPoint() = default;

  inline void set_point(const athena::interface::Point3D& point) {
    point_ = point;
    point_ptr_ = &point_;
  }

  inline const athena::interface::Point3D& point() const { return point_; }

  inline athena::interface::Point3D* mutable_point() { return &point_; }

  inline bool has_point() { return (point_ptr_ != nullptr); }

  inline void set_v(const double& v) {
    v_ = v;
    v_ptr_ = &v_;
  }

  inline const double& v() const { return v_; }

  inline double* mutable_v() { return &v_; }

  inline bool has_v() { return (v_ptr_ != nullptr); }

  void operator=(const HMITrajectoryPoint& hmi_trajectory_point) {
    CopyFrom(hmi_trajectory_point);
  }

  void CopyFrom(const HMITrajectoryPoint& hmi_trajectory_point) {
    point_ = hmi_trajectory_point.point();
    v_ = hmi_trajectory_point.v();
  }

protected:
  athena::interface::Point3D point_;
  athena::interface::Point3D* point_ptr_ = nullptr;
  double v_;
  double* v_ptr_ = nullptr;
};
} // namespace interface
} // namespace athena
