/**
 * @file    camera_parking_stopper.hpp
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
#include "modules/common/interface/bbox_2d.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class CameraParkingStopper {
public:
  CameraParkingStopper() = default;
  ~CameraParkingStopper() = default;

  inline void set_header(const athena::interface::Header& header) {
    header_ = header;
    header_ptr_ = &header_;
  }

  inline const athena::interface::Header& header() const { return header_; }

  inline athena::interface::Header* mutable_header() { return &header_; }

  inline bool has_header() { return (header_ptr_ != nullptr); }

  inline void set_bbox2d(const athena::interface::BBox2D& bbox2d) {
    bbox2d_ = bbox2d;
    bbox2d_ptr_ = &bbox2d_;
  }

  inline const athena::interface::BBox2D& bbox2d() const { return bbox2d_; }

  inline athena::interface::BBox2D* mutable_bbox2d() { return &bbox2d_; }

  inline bool has_bbox2d() { return (bbox2d_ptr_ != nullptr); }

  void operator=(const CameraParkingStopper& camera_parking_stopper) {
    CopyFrom(camera_parking_stopper);
  }

  void CopyFrom(const CameraParkingStopper& camera_parking_stopper) {
    header_ = camera_parking_stopper.header();
    bbox2d_ = camera_parking_stopper.bbox2d();
  }

protected:
  // timestamp is  included in header
  athena::interface::Header header_;
  athena::interface::Header* header_ptr_ = nullptr;
  //限位器图像框
  athena::interface::BBox2D bbox2d_;
  athena::interface::BBox2D* bbox2d_ptr_ = nullptr;
};
} // namespace interface
} // namespace athena
