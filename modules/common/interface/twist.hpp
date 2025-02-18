/**
 * @file    twist.hpp
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#pragma once

#include <iostream>
#include <stdint.h>

#include "modules/common/interface/header.hpp"
#include "modules/common/interface/point_3d.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class Twist {
public:
  Twist() = default;
  ~Twist() = default;

  inline void set_header(const athena::interface::Header& header) {
    header_ = header;
    header_ptr_ = &header_;
  }

  inline const athena::interface::Header& header() const { return header_; }

  inline athena::interface::Header* mutable_header() { return &header_; }

  inline bool has_header() { return (header_ptr_ != nullptr); }

  inline void set_linear(const athena::interface::Point3D& linear) {
    linear_ = linear;
    linear_ptr_ = &linear_;
  }

  inline const athena::interface::Point3D& linear() const { return linear_; }

  inline athena::interface::Point3D* mutable_linear() { return &linear_; }

  inline bool has_linear() { return (linear_ptr_ != nullptr); }

  inline void set_angular(const athena::interface::Point3D& angular) {
    angular_ = angular;
    angular_ptr_ = &angular_;
  }

  inline const athena::interface::Point3D& angular() const { return angular_; }

  inline athena::interface::Point3D* mutable_angular() { return &angular_; }

  inline bool has_angular() { return (angular_ptr_ != nullptr); }

  void operator=(const Twist& twist) { CopyFrom(twist); }

  void CopyFrom(const Twist& twist) {
    header_ = twist.header();
    linear_ = twist.linear();
    angular_ = twist.angular();
  }

protected:
  athena::interface::Header header_;
  athena::interface::Header* header_ptr_ = nullptr;
  //线速度 m/s
  athena::interface::Point3D linear_;
  athena::interface::Point3D* linear_ptr_ = nullptr;
  //角速度 deg/s
  athena::interface::Point3D angular_;
  athena::interface::Point3D* angular_ptr_ = nullptr;
};
} // namespace interface
} // namespace athena
