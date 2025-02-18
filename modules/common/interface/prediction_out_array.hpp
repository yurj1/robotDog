/**
 * @file    prediction_out_array.hpp
 * @author  hyzx
 * @date    2021-12-07
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
#include "modules/common/interface/location.hpp"
#include "modules/common/interface/adc_trajectory.hpp"
#include "modules/common/interface/prediction_obstacle.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class PredictionOutArray {
public:
  PredictionOutArray() {
    prediction_obstacles_mutex_ = std::make_shared<std::mutex>();

    clear_prediction_obstacles();
    change_origin_flag_ =
        athena::interface::Location::ChangeOriginFlag::CHANGE_NULL;
    start_timestamp_ = 0.0;
    end_timestamp_ = 0.0;
    self_intent_ = athena::interface::PredictionOutArray::SelfIntent::UNKNOWN;
    scenario_ = athena::interface::ADCTrajectory::Scenario::SCENARIO_UNKNOWN;
  }
  ~PredictionOutArray() = default;

  enum SelfIntent {
    UNKNOWN = 0,
    STOP = 1,
    CRUISE = 2,
    CHANGE_LANE = 3,
  };

  inline void set_header(const athena::interface::Header& header) {
    header_ = header;
  }

  inline const athena::interface::Header& header() const { return header_; }

  inline athena::interface::Header* mutable_header() { return &header_; }

  inline void
  set_prediction_obstacles(std::vector<athena::interface::PredictionObstacle>*
                               prediction_obstacles) {
    std::lock_guard<std::mutex> lock(*prediction_obstacles_mutex_);
    prediction_obstacles_.assign(prediction_obstacles->begin(),
                                 prediction_obstacles->end());
  }

  inline void set_prediction_obstacles(
      const std::vector<athena::interface::PredictionObstacle>&
          prediction_obstacles) {
    std::lock_guard<std::mutex> lock(*prediction_obstacles_mutex_);
    prediction_obstacles_ = prediction_obstacles;
  }

  inline void set_prediction_obstacles(
      const uint32_t index,
      athena::interface::PredictionObstacle& prediction_obstacles) {
    std::lock_guard<std::mutex> lock(*prediction_obstacles_mutex_);
    prediction_obstacles_[index] = prediction_obstacles;
  }

  inline void add_prediction_obstacles(
      const athena::interface::PredictionObstacle& prediction_obstacles) {
    std::lock_guard<std::mutex> lock(*prediction_obstacles_mutex_);
    prediction_obstacles_.emplace_back(prediction_obstacles);
  }

  inline const athena::interface::PredictionObstacle&
  prediction_obstacles(uint32_t index) const {
    std::lock_guard<std::mutex> lock(*prediction_obstacles_mutex_);
    return prediction_obstacles_[index];
  }

  inline std::vector<athena::interface::PredictionObstacle>*
  mutable_prediction_obstacles() {
    std::lock_guard<std::mutex> lock(*prediction_obstacles_mutex_);
    return &prediction_obstacles_;
  }

  inline void prediction_obstacles(
      std::vector<athena::interface::PredictionObstacle>& prediction_obstacles)
      const {
    std::lock_guard<std::mutex> lock(*prediction_obstacles_mutex_);
    prediction_obstacles.assign(prediction_obstacles_.begin(),
                                prediction_obstacles_.end());
  }

  inline const std::vector<athena::interface::PredictionObstacle>&
  prediction_obstacles() const {
    std::lock_guard<std::mutex> lock(*prediction_obstacles_mutex_);
    return prediction_obstacles_;
  }

  inline uint32_t prediction_obstacles_size() const {
    std::lock_guard<std::mutex> lock(*prediction_obstacles_mutex_);
    return prediction_obstacles_.size();
  }

  inline void clear_prediction_obstacles() {
    std::lock_guard<std::mutex> lock(*prediction_obstacles_mutex_);
    prediction_obstacles_.clear();
  }

  inline void set_change_origin_flag(
      const athena::interface::Location::ChangeOriginFlag& change_origin_flag) {
    change_origin_flag_ = change_origin_flag;
  }

  inline const athena::interface::Location::ChangeOriginFlag&
  change_origin_flag() const {
    return change_origin_flag_;
  }

  inline athena::interface::Location::ChangeOriginFlag*
  mutable_change_origin_flag() {
    return &change_origin_flag_;
  }

  inline void set_start_timestamp(const double& start_timestamp) {
    start_timestamp_ = start_timestamp;
  }

  inline const double& start_timestamp() const { return start_timestamp_; }

  inline double* mutable_start_timestamp() { return &start_timestamp_; }

  inline void set_end_timestamp(const double& end_timestamp) {
    end_timestamp_ = end_timestamp;
  }

  inline const double& end_timestamp() const { return end_timestamp_; }

  inline double* mutable_end_timestamp() { return &end_timestamp_; }

  inline void set_self_intent(
      const athena::interface::PredictionOutArray::SelfIntent& self_intent) {
    self_intent_ = self_intent;
  }

  inline const athena::interface::PredictionOutArray::SelfIntent&
  self_intent() const {
    return self_intent_;
  }

  inline athena::interface::PredictionOutArray::SelfIntent*
  mutable_self_intent() {
    return &self_intent_;
  }

  inline void
  set_scenario(const athena::interface::ADCTrajectory::Scenario& scenario) {
    scenario_ = scenario;
  }

  inline const athena::interface::ADCTrajectory::Scenario& scenario() const {
    return scenario_;
  }

  inline athena::interface::ADCTrajectory::Scenario* mutable_scenario() {
    return &scenario_;
  }

protected:
  std::shared_ptr<std::mutex> prediction_obstacles_mutex_;
  // timestamp is included in header
  athena::interface::Header header_;
  // make prediction for multiple obstacles
  std::vector<athena::interface::PredictionObstacle> prediction_obstacles_;
  // 0:坐标系切换成功 1:坐标系切换中 2:坐标系切换故障
  athena::interface::Location::ChangeOriginFlag change_origin_flag_;
  // start timestamp
  double start_timestamp_;
  // end timestamp
  double end_timestamp_;
  //自动驾驶车辆意图  0-UNKNOWN, 1-STOP, 2-CRUISE, 3-CHANGE_LANE
  athena::interface::PredictionOutArray::SelfIntent self_intent_;
  //场景              0-UNKNOWN, 1000-CRUISE, 1001-CRUISE_URBAN
  // 1002-CRUISE_HIGHWAY, 2000-JUNCTION  2001-JUNCTION_TRAFFIC_LIGHT
  // 2002-JUNCTION_STOP_SIGN
  athena::interface::ADCTrajectory::Scenario scenario_;
};
} // namespace interface
} // namespace athena
