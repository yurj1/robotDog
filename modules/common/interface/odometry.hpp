/**
 * @file    odometry.hpp
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
#include "modules/common/interface/point_enu.hpp"
#include "modules/common/interface/quaternion.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class Odometry {
public:
  Odometry() {
    covariance_mutex_ = std::make_shared<std::mutex>();

    clear_covariance();
  }
  ~Odometry() = default;

  inline void set_header(const athena::interface::Header& header) {
    header_ = header;
    header_ptr_ = &header_;
  }

  inline const athena::interface::Header& header() const { return header_; }

  inline athena::interface::Header* mutable_header() { return &header_; }

  inline bool has_header() { return (header_ptr_ != nullptr); }

  inline void set_position(const athena::interface::PointENU& position) {
    position_ = position;
    position_ptr_ = &position_;
  }

  inline const athena::interface::PointENU& position() const {
    return position_;
  }

  inline athena::interface::PointENU* mutable_position() { return &position_; }

  inline bool has_position() { return (position_ptr_ != nullptr); }

  inline void
  set_orientation(const athena::interface::Quaternion& orientation) {
    orientation_ = orientation;
    orientation_ptr_ = &orientation_;
  }

  inline const athena::interface::Quaternion& orientation() const {
    return orientation_;
  }

  inline athena::interface::Quaternion* mutable_orientation() {
    return &orientation_;
  }

  inline bool has_orientation() { return (orientation_ptr_ != nullptr); }

  inline void set_covariance(std::vector<double>* covariance) {
    std::lock_guard<std::mutex> lock(*covariance_mutex_);
    covariance_.assign(covariance->begin(), covariance->end());
  }

  inline void set_covariance(const std::vector<double>& covariance) {
    std::lock_guard<std::mutex> lock(*covariance_mutex_);
    covariance_ = covariance;
  }

  inline void set_covariance(const uint32_t index, double& covariance) {
    std::lock_guard<std::mutex> lock(*covariance_mutex_);
    covariance_[index] = covariance;
  }

  inline void add_covariance(const double& covariance) {
    std::lock_guard<std::mutex> lock(*covariance_mutex_);
    covariance_.emplace_back(covariance);
  }

  inline const double& covariance(uint32_t index) const {
    std::lock_guard<std::mutex> lock(*covariance_mutex_);
    return covariance_[index];
  }

  inline std::vector<double>* mutable_covariance() {
    std::lock_guard<std::mutex> lock(*covariance_mutex_);
    return &covariance_;
  }

  inline void covariance(std::vector<double>& covariance) const {
    std::lock_guard<std::mutex> lock(*covariance_mutex_);
    covariance.assign(covariance_.begin(), covariance_.end());
  }

  inline const std::vector<double>& covariance() const {
    std::lock_guard<std::mutex> lock(*covariance_mutex_);
    return covariance_;
  }

  inline uint32_t covariance_size() const {
    std::lock_guard<std::mutex> lock(*covariance_mutex_);
    return covariance_.size();
  }

  inline void clear_covariance() {
    std::lock_guard<std::mutex> lock(*covariance_mutex_);
    covariance_.clear();
    covariance_.shrink_to_fit();
  }

  inline bool has_covariance() { return (covariance_size() != 0); }

  void operator=(const Odometry& odometry) { CopyFrom(odometry); }

  void CopyFrom(const Odometry& odometry) {
    header_ = odometry.header();
    position_ = odometry.position();
    orientation_ = odometry.orientation();
    covariance_ = odometry.covariance();
  }

protected:
  std::shared_ptr<std::mutex> covariance_mutex_;
  //含有时间戳信息的结构体
  athena::interface::Header header_;
  athena::interface::Header* header_ptr_ = nullptr;
  //位置
  athena::interface::PointENU position_;
  athena::interface::PointENU* position_ptr_ = nullptr;
  //角度
  athena::interface::Quaternion orientation_;
  athena::interface::Quaternion* orientation_ptr_ = nullptr;
  //方差
  std::vector<double> covariance_;
};
} // namespace interface
} // namespace athena
