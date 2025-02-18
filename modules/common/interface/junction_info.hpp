/**
 * @file    junction_info.hpp
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
class JunctionInfo {
public:
  JunctionInfo() {
    stop_line_mutex_ = std::make_shared<std::mutex>();

    id_ = 0;
    light_flag_ = athena::common::IsValid::INVALID;
    light_color_ = athena::common::TrafficLightColor::COLOR_UNKNOWN;
    light_remain_time_ = 0.0;
    distance_to_stop_ = 0.0;
    direction_flag_ = athena::common::IsValid::INVALID;
    direction_ = athena::common::Direction::DIR_INVALID;
    distance_to_junction_ = 0.0;
    clear_stop_line();
  }
  ~JunctionInfo() = default;

  inline void set_id(const int32_t& id) {
    id_ = id;
    id_ptr_ = &id_;
  }

  inline const int32_t& id() const { return id_; }

  inline int32_t* mutable_id() { return &id_; }

  inline bool has_id() { return (id_ptr_ != nullptr); }

  inline void set_light_flag(const athena::common::IsValid& light_flag) {
    light_flag_ = light_flag;
    light_flag_ptr_ = &light_flag_;
  }

  inline const athena::common::IsValid& light_flag() const {
    return light_flag_;
  }

  inline athena::common::IsValid* mutable_light_flag() { return &light_flag_; }

  inline bool has_light_flag() { return (light_flag_ptr_ != nullptr); }

  inline void
  set_light_color(const athena::common::TrafficLightColor& light_color) {
    light_color_ = light_color;
    light_color_ptr_ = &light_color_;
  }

  inline const athena::common::TrafficLightColor& light_color() const {
    return light_color_;
  }

  inline athena::common::TrafficLightColor* mutable_light_color() {
    return &light_color_;
  }

  inline bool has_light_color() { return (light_color_ptr_ != nullptr); }

  inline void set_light_remain_time(const double& light_remain_time) {
    light_remain_time_ = light_remain_time;
    light_remain_time_ptr_ = &light_remain_time_;
  }

  inline const double& light_remain_time() const { return light_remain_time_; }

  inline double* mutable_light_remain_time() { return &light_remain_time_; }

  inline bool has_light_remain_time() {
    return (light_remain_time_ptr_ != nullptr);
  }

  inline void set_distance_to_stop(const double& distance_to_stop) {
    distance_to_stop_ = distance_to_stop;
    distance_to_stop_ptr_ = &distance_to_stop_;
  }

  inline const double& distance_to_stop() const { return distance_to_stop_; }

  inline double* mutable_distance_to_stop() { return &distance_to_stop_; }

  inline bool has_distance_to_stop() {
    return (distance_to_stop_ptr_ != nullptr);
  }

  inline void
  set_direction_flag(const athena::common::IsValid& direction_flag) {
    direction_flag_ = direction_flag;
    direction_flag_ptr_ = &direction_flag_;
  }

  inline const athena::common::IsValid& direction_flag() const {
    return direction_flag_;
  }

  inline athena::common::IsValid* mutable_direction_flag() {
    return &direction_flag_;
  }

  inline bool has_direction_flag() { return (direction_flag_ptr_ != nullptr); }

  inline void set_direction(const athena::common::Direction& direction) {
    direction_ = direction;
    direction_ptr_ = &direction_;
  }

  inline const athena::common::Direction& direction() const {
    return direction_;
  }

  inline athena::common::Direction* mutable_direction() { return &direction_; }

  inline bool has_direction() { return (direction_ptr_ != nullptr); }

  inline void set_distance_to_junction(const double& distance_to_junction) {
    distance_to_junction_ = distance_to_junction;
    distance_to_junction_ptr_ = &distance_to_junction_;
  }

  inline const double& distance_to_junction() const {
    return distance_to_junction_;
  }

  inline double* mutable_distance_to_junction() {
    return &distance_to_junction_;
  }

  inline bool has_distance_to_junction() {
    return (distance_to_junction_ptr_ != nullptr);
  }

  inline void
  set_stop_line(std::vector<athena::interface::Point3D>* stop_line) {
    std::lock_guard<std::mutex> lock(*stop_line_mutex_);
    stop_line_.assign(stop_line->begin(), stop_line->end());
  }

  inline void
  set_stop_line(const std::vector<athena::interface::Point3D>& stop_line) {
    std::lock_guard<std::mutex> lock(*stop_line_mutex_);
    stop_line_ = stop_line;
  }

  inline void set_stop_line(const uint32_t index,
                            athena::interface::Point3D& stop_line) {
    std::lock_guard<std::mutex> lock(*stop_line_mutex_);
    stop_line_[index] = stop_line;
  }

  inline void add_stop_line(const athena::interface::Point3D& stop_line) {
    std::lock_guard<std::mutex> lock(*stop_line_mutex_);
    stop_line_.emplace_back(stop_line);
  }

  inline const athena::interface::Point3D& stop_line(uint32_t index) const {
    std::lock_guard<std::mutex> lock(*stop_line_mutex_);
    return stop_line_[index];
  }

  inline std::vector<athena::interface::Point3D>* mutable_stop_line() {
    std::lock_guard<std::mutex> lock(*stop_line_mutex_);
    return &stop_line_;
  }

  inline void
  stop_line(std::vector<athena::interface::Point3D>& stop_line) const {
    std::lock_guard<std::mutex> lock(*stop_line_mutex_);
    stop_line.assign(stop_line_.begin(), stop_line_.end());
  }

  inline const std::vector<athena::interface::Point3D>& stop_line() const {
    std::lock_guard<std::mutex> lock(*stop_line_mutex_);
    return stop_line_;
  }

  inline uint32_t stop_line_size() const {
    std::lock_guard<std::mutex> lock(*stop_line_mutex_);
    return stop_line_.size();
  }

  inline void clear_stop_line() {
    std::lock_guard<std::mutex> lock(*stop_line_mutex_);
    stop_line_.clear();
    stop_line_.shrink_to_fit();
  }

  inline bool has_stop_line() { return (stop_line_size() != 0); }

  void operator=(const JunctionInfo& junction_info) { CopyFrom(junction_info); }

  void CopyFrom(const JunctionInfo& junction_info) {
    id_ = junction_info.id();
    light_flag_ = junction_info.light_flag();
    light_color_ = junction_info.light_color();
    light_remain_time_ = junction_info.light_remain_time();
    distance_to_stop_ = junction_info.distance_to_stop();
    direction_flag_ = junction_info.direction_flag();
    direction_ = junction_info.direction();
    distance_to_junction_ = junction_info.distance_to_junction();
    stop_line_ = junction_info.stop_line();
  }

protected:
  std::shared_ptr<std::mutex> stop_line_mutex_;
  int32_t id_;
  int32_t* id_ptr_ = nullptr;
  //是否有效，无效就可能是清除了，或者已经过路口了
  athena::common::IsValid light_flag_;
  athena::common::IsValid* light_flag_ptr_ = nullptr;
  //信号灯颜色，绿灯可通行，false红灯不能通行
  athena::common::TrafficLightColor light_color_;
  athena::common::TrafficLightColor* light_color_ptr_ = nullptr;
  //信号灯剩余时间
  double light_remain_time_;
  double* light_remain_time_ptr_ = nullptr;
  //停车距离，停止线
  double distance_to_stop_;
  double* distance_to_stop_ptr_ = nullptr;
  //是否有效，无效就可能是清除了，或者已经过路口了
  athena::common::IsValid direction_flag_;
  athena::common::IsValid* direction_flag_ptr_ = nullptr;
  //路口通行方向，0：无效、1：左、2：前、3：右
  athena::common::Direction direction_;
  athena::common::Direction* direction_ptr_ = nullptr;
  //距路口距离
  double distance_to_junction_;
  double* distance_to_junction_ptr_ = nullptr;
  //路口停止线
  std::vector<athena::interface::Point3D> stop_line_;
};
} // namespace interface
} // namespace athena
