/**
 * @file    parking_info.hpp
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#pragma once

#include <iostream>
#include <memory>
#include <mutex>
#include <stdint.h>
#include <vector>

#include "modules/common/enum/enum.h"
#include "modules/common/interface/header.hpp"
#include "modules/common/interface/parking_stopper.hpp"
#include "modules/common/interface/point_3d.hpp"
#include "modules/common/interface/polygon_3d.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class ParkingInfo {
public:
  ParkingInfo() {
    parking_stoppers_mutex_ = std::make_shared<std::mutex>();

    parking_space_id_ = 0;
    parking_type_ = athena::common::ParkingType::INVALID_PARKING;
    parking_status_ = athena::common::ParkingStatus::PARKING_DISENABLE;
    confidence_ = 0.0;
    theta_ = 0.0;
    width_ = 0.0;
    length_ = 0.0;
    yaw_offset_ = 0.0;
    sensor_id_ = athena::common::SensorID::CAMERA_FRONT_CENTER;
    is_lane_width_valid_ = false;
    lane_width_ = 0.0;
    clear_parking_stoppers();
    parking_direction_type_ = athena::common::Direction::DIR_INVALID;
    left_occupied_status_ =
        athena::common::OccupiedStatus::UNKNOWN_OCCUPIED_STATUS;
    right_occupied_status_ =
        athena::common::OccupiedStatus::UNKNOWN_OCCUPIED_STATUS;
    parking_source_type_ = athena::common::ParkingSourceType::LINE_PARKING;
    parking_scene_type_ = athena::common::ParkingSceneType::COMMON;
    is_update_finished_ = false;
  }
  ~ParkingInfo() = default;

  inline void set_header(const athena::interface::Header &header) {
    header_ = header;
    header_ptr_ = &header_;
  }

  inline const athena::interface::Header &header() const { return header_; }

  inline athena::interface::Header *mutable_header() { return &header_; }

  inline bool has_header() { return (header_ptr_ != nullptr); }

  inline void set_parking_space_id(const int32_t &parking_space_id) {
    parking_space_id_ = parking_space_id;
    parking_space_id_ptr_ = &parking_space_id_;
  }

  inline const int32_t &parking_space_id() const { return parking_space_id_; }

  inline int32_t *mutable_parking_space_id() { return &parking_space_id_; }

  inline bool has_parking_space_id() {
    return (parking_space_id_ptr_ != nullptr);
  }

  inline void
  set_parking_type(const athena::common::ParkingType &parking_type) {
    parking_type_ = parking_type;
    parking_type_ptr_ = &parking_type_;
  }

  inline const athena::common::ParkingType &parking_type() const {
    return parking_type_;
  }

  inline athena::common::ParkingType *mutable_parking_type() {
    return &parking_type_;
  }

  inline bool has_parking_type() { return (parking_type_ptr_ != nullptr); }

  inline void
  set_parking_status(const athena::common::ParkingStatus &parking_status) {
    parking_status_ = parking_status;
    parking_status_ptr_ = &parking_status_;
  }

  inline const athena::common::ParkingStatus &parking_status() const {
    return parking_status_;
  }

  inline athena::common::ParkingStatus *mutable_parking_status() {
    return &parking_status_;
  }

  inline bool has_parking_status() { return (parking_status_ptr_ != nullptr); }

  inline void set_confidence(const double &confidence) {
    confidence_ = confidence;
    confidence_ptr_ = &confidence_;
  }

  inline const double &confidence() const { return confidence_; }

  inline double *mutable_confidence() { return &confidence_; }

  inline bool has_confidence() { return (confidence_ptr_ != nullptr); }

  inline void set_center_point_of_parking(
      const athena::interface::Point3D &center_point_of_parking) {
    center_point_of_parking_ = center_point_of_parking;
    center_point_of_parking_ptr_ = &center_point_of_parking_;
  }

  inline const athena::interface::Point3D &center_point_of_parking() const {
    return center_point_of_parking_;
  }

  inline athena::interface::Point3D *mutable_center_point_of_parking() {
    return &center_point_of_parking_;
  }

  inline bool has_center_point_of_parking() {
    return (center_point_of_parking_ptr_ != nullptr);
  }

  inline void set_theta(const double &theta) {
    theta_ = theta;
    theta_ptr_ = &theta_;
  }

  inline const double &theta() const { return theta_; }

  inline double *mutable_theta() { return &theta_; }

  inline bool has_theta() { return (theta_ptr_ != nullptr); }

  inline void set_width(const double &width) {
    width_ = width;
    width_ptr_ = &width_;
  }

  inline const double &width() const { return width_; }

  inline double *mutable_width() { return &width_; }

  inline bool has_width() { return (width_ptr_ != nullptr); }

  inline void set_length(const double &length) {
    length_ = length;
    length_ptr_ = &length_;
  }

  inline const double &length() const { return length_; }

  inline double *mutable_length() { return &length_; }

  inline bool has_length() { return (length_ptr_ != nullptr); }

  inline void set_yaw_offset(const double &yaw_offset) {
    yaw_offset_ = yaw_offset;
    yaw_offset_ptr_ = &yaw_offset_;
  }

  inline const double &yaw_offset() const { return yaw_offset_; }

  inline double *mutable_yaw_offset() { return &yaw_offset_; }

  inline bool has_yaw_offset() { return (yaw_offset_ptr_ != nullptr); }

  inline void set_polygon(const athena::interface::Polygon3D &polygon) {
    polygon_ = polygon;
    polygon_ptr_ = &polygon_;
  }

  inline const athena::interface::Polygon3D &polygon() const {
    return polygon_;
  }

  inline athena::interface::Polygon3D *mutable_polygon() { return &polygon_; }

  inline bool has_polygon() { return (polygon_ptr_ != nullptr); }

  inline void set_sensor_id(const athena::common::SensorID &sensor_id) {
    sensor_id_ = sensor_id;
    sensor_id_ptr_ = &sensor_id_;
  }

  inline const athena::common::SensorID &sensor_id() const {
    return sensor_id_;
  }

  inline athena::common::SensorID *mutable_sensor_id() { return &sensor_id_; }

  inline bool has_sensor_id() { return (sensor_id_ptr_ != nullptr); }

  inline void set_is_lane_width_valid(const bool &is_lane_width_valid) {
    is_lane_width_valid_ = is_lane_width_valid;
    is_lane_width_valid_ptr_ = &is_lane_width_valid_;
  }

  inline const bool &is_lane_width_valid() const {
    return is_lane_width_valid_;
  }

  inline bool *mutable_is_lane_width_valid() { return &is_lane_width_valid_; }

  inline bool has_is_lane_width_valid() {
    return (is_lane_width_valid_ptr_ != nullptr);
  }

  inline void set_lane_width(const double &lane_width) {
    lane_width_ = lane_width;
    lane_width_ptr_ = &lane_width_;
  }

  inline const double &lane_width() const { return lane_width_; }

  inline double *mutable_lane_width() { return &lane_width_; }

  inline bool has_lane_width() { return (lane_width_ptr_ != nullptr); }

  inline void set_parking_stoppers(
      std::vector<athena::interface::ParkingStopper> *parking_stoppers) {
    std::lock_guard<std::mutex> lock(*parking_stoppers_mutex_);
    parking_stoppers_.assign(parking_stoppers->begin(),
                             parking_stoppers->end());
  }

  inline void set_parking_stoppers(
      const std::vector<athena::interface::ParkingStopper> &parking_stoppers) {
    std::lock_guard<std::mutex> lock(*parking_stoppers_mutex_);
    parking_stoppers_ = parking_stoppers;
  }

  inline void
  set_parking_stoppers(const uint32_t index,
                       athena::interface::ParkingStopper &parking_stoppers) {
    std::lock_guard<std::mutex> lock(*parking_stoppers_mutex_);
    parking_stoppers_[index] = parking_stoppers;
  }

  inline void add_parking_stoppers(
      const athena::interface::ParkingStopper &parking_stoppers) {
    std::lock_guard<std::mutex> lock(*parking_stoppers_mutex_);
    parking_stoppers_.emplace_back(parking_stoppers);
  }

  inline const athena::interface::ParkingStopper &
  parking_stoppers(uint32_t index) const {
    std::lock_guard<std::mutex> lock(*parking_stoppers_mutex_);
    return parking_stoppers_[index];
  }

  inline std::vector<athena::interface::ParkingStopper> *
  mutable_parking_stoppers() {
    std::lock_guard<std::mutex> lock(*parking_stoppers_mutex_);
    return &parking_stoppers_;
  }

  inline void parking_stoppers(
      std::vector<athena::interface::ParkingStopper> &parking_stoppers) const {
    std::lock_guard<std::mutex> lock(*parking_stoppers_mutex_);
    parking_stoppers.assign(parking_stoppers_.begin(), parking_stoppers_.end());
  }

  inline const std::vector<athena::interface::ParkingStopper> &
  parking_stoppers() const {
    std::lock_guard<std::mutex> lock(*parking_stoppers_mutex_);
    return parking_stoppers_;
  }

  inline uint32_t parking_stoppers_size() const {
    std::lock_guard<std::mutex> lock(*parking_stoppers_mutex_);
    return parking_stoppers_.size();
  }

  inline void clear_parking_stoppers() {
    std::lock_guard<std::mutex> lock(*parking_stoppers_mutex_);
    parking_stoppers_.clear();
    parking_stoppers_.shrink_to_fit();
  }

  inline bool has_parking_stoppers() { return (parking_stoppers_size() != 0); }

  inline void set_parking_direction_type(
      const athena::common::Direction &parking_direction_type) {
    parking_direction_type_ = parking_direction_type;
    parking_direction_type_ptr_ = &parking_direction_type_;
  }

  inline const athena::common::Direction &parking_direction_type() const {
    return parking_direction_type_;
  }

  inline athena::common::Direction *mutable_parking_direction_type() {
    return &parking_direction_type_;
  }

  inline bool has_parking_direction_type() {
    return (parking_direction_type_ptr_ != nullptr);
  }

  inline void set_left_occupied_status(
      const athena::common::OccupiedStatus &left_occupied_status) {
    left_occupied_status_ = left_occupied_status;
    left_occupied_status_ptr_ = &left_occupied_status_;
  }

  inline const athena::common::OccupiedStatus &left_occupied_status() const {
    return left_occupied_status_;
  }

  inline athena::common::OccupiedStatus *mutable_left_occupied_status() {
    return &left_occupied_status_;
  }

  inline bool has_left_occupied_status() {
    return (left_occupied_status_ptr_ != nullptr);
  }

  inline void set_right_occupied_status(
      const athena::common::OccupiedStatus &right_occupied_status) {
    right_occupied_status_ = right_occupied_status;
    right_occupied_status_ptr_ = &right_occupied_status_;
  }

  inline const athena::common::OccupiedStatus &right_occupied_status() const {
    return right_occupied_status_;
  }

  inline athena::common::OccupiedStatus *mutable_right_occupied_status() {
    return &right_occupied_status_;
  }

  inline bool has_right_occupied_status() {
    return (right_occupied_status_ptr_ != nullptr);
  }

  inline void set_parking_source_type(
      const athena::common::ParkingSourceType &parking_source_type) {
    parking_source_type_ = parking_source_type;
    parking_source_type_ptr_ = &parking_source_type_;
  }

  inline const athena::common::ParkingSourceType &parking_source_type() const {
    return parking_source_type_;
  }

  inline athena::common::ParkingSourceType *mutable_parking_source_type() {
    return &parking_source_type_;
  }

  inline bool has_parking_source_type() {
    return (parking_source_type_ptr_ != nullptr);
  }

  inline void set_parking_scene_type(
      const athena::common::ParkingSceneType &parking_scene_type) {
    parking_scene_type_ = parking_scene_type;
    parking_scene_type_ptr_ = &parking_scene_type_;
  }

  inline const athena::common::ParkingSceneType &parking_scene_type() const {
    return parking_scene_type_;
  }

  inline athena::common::ParkingSceneType *mutable_parking_scene_type() {
    return &parking_scene_type_;
  }

  inline bool has_parking_scene_type() {
    return (parking_scene_type_ptr_ != nullptr);
  }

  inline void set_is_update_finished(const bool &is_update_finished) {
    is_update_finished_ = is_update_finished;
    is_update_finished_ptr_ = &is_update_finished_;
  }

  inline const bool &is_update_finished() const { return is_update_finished_; }

  inline bool *mutable_is_update_finished() { return &is_update_finished_; }

  inline bool has_is_update_finished() {
    return (is_update_finished_ptr_ != nullptr);
  }

  void operator=(const ParkingInfo &parking_info) { CopyFrom(parking_info); }

  void CopyFrom(const ParkingInfo &parking_info) {
    header_ = parking_info.header();
    parking_space_id_ = parking_info.parking_space_id();
    parking_type_ = parking_info.parking_type();
    parking_status_ = parking_info.parking_status();
    confidence_ = parking_info.confidence();
    center_point_of_parking_ = parking_info.center_point_of_parking();
    theta_ = parking_info.theta();
    width_ = parking_info.width();
    length_ = parking_info.length();
    yaw_offset_ = parking_info.yaw_offset();
    polygon_ = parking_info.polygon();
    sensor_id_ = parking_info.sensor_id();
    is_lane_width_valid_ = parking_info.is_lane_width_valid();
    lane_width_ = parking_info.lane_width();
    parking_stoppers_ = parking_info.parking_stoppers();
    parking_direction_type_ = parking_info.parking_direction_type();
    left_occupied_status_ = parking_info.left_occupied_status();
    right_occupied_status_ = parking_info.right_occupied_status();
    parking_source_type_ = parking_info.parking_source_type();
    parking_scene_type_ = parking_info.parking_scene_type();
    is_update_finished_ = parking_info.is_update_finished();
  }

protected:
  std::shared_ptr<std::mutex> parking_stoppers_mutex_;
  // timestamp is included in header
  athena::interface::Header header_;
  athena::interface::Header *header_ptr_ = nullptr;
  //停车位id
  int32_t parking_space_id_;
  int32_t *parking_space_id_ptr_ = nullptr;
  // PARKING_TYPE=0//无效车位 PARKING_TYPE=1//水平车位 PARKING_TYPE=2//垂直车位
  // PARKING_TYPE=3//倾斜车位 PARKING_TYPE=4//鱼骨车位 PARKING_TYPE=5//未知车位
  athena::common::ParkingType parking_type_;
  athena::common::ParkingType *parking_type_ptr_ = nullptr;
  // PARKING_DISABLE=0//不可泊 PARKING_ENABLE=1//可泊
  // PARKING_NONOPTIONAL=2//不可选
  athena::common::ParkingStatus parking_status_;
  athena::common::ParkingStatus *parking_status_ptr_ = nullptr;
  //车位置信度
  double confidence_;
  double *confidence_ptr_ = nullptr;
  //世界坐标系下停车位中心点
  athena::interface::Point3D center_point_of_parking_;
  athena::interface::Point3D *center_point_of_parking_ptr_ = nullptr;
  //世界坐标系下的夹角（单位rad），车位出口与正东方向夹角
  double theta_;
  double *theta_ptr_ = nullptr;
  //停车位宽（单位m）
  double width_;
  double *width_ptr_ = nullptr;
  //停车位长单位m）
  double length_;
  double *length_ptr_ = nullptr;
  //停车位角度偏移量（倾斜车位），倾斜车位与道路边线夹角,(单位m）
  double yaw_offset_;
  double *yaw_offset_ptr_ = nullptr;
  //世界坐标系下的车位多边形
  athena::interface::Polygon3D polygon_;
  athena::interface::Polygon3D *polygon_ptr_ = nullptr;
  //车位数据来自相机id 0-front_center相机 1-front_left相机 2-front_right相机
  //3-left_front相机 4-left_back右后相机 5-right_front相机 6-right_back相机
  //7-back相机 8-相机融合
  athena::common::SensorID sensor_id_;
  athena::common::SensorID *sensor_id_ptr_ = nullptr;
  //车道宽度是否有效
  bool is_lane_width_valid_;
  bool *is_lane_width_valid_ptr_ = nullptr;
  //泊车可用(双)车道宽度
  double lane_width_;
  double *lane_width_ptr_ = nullptr;
  //车位内部的限位器数组
  std::vector<athena::interface::ParkingStopper> parking_stoppers_;
  //  DIR_INVALID = 0,   LEFT = 1,   UP = 2,   RIGHT = 3,   DOWN = 4,
  athena::common::Direction parking_direction_type_;
  athena::common::Direction *parking_direction_type_ptr_ = nullptr;
  // 0-unknown 未知，1-empty 空闲，2-occupied 被占用
  athena::common::OccupiedStatus left_occupied_status_;
  athena::common::OccupiedStatus *left_occupied_status_ptr_ = nullptr;
  // 0-unknown 未知，1-empty 空闲，2-occupied 被占用
  athena::common::OccupiedStatus right_occupied_status_;
  athena::common::OccupiedStatus *right_occupied_status_ptr_ = nullptr;
  // 0-线车位， 1-空间车位， 2-超声波车位， 3-融合车位
  athena::common::ParkingSourceType parking_source_type_;
  athena::common::ParkingSourceType *parking_source_type_ptr_ = nullptr;
  // 0-常规车位， 1-断头路车位， 2-自选车位，
  athena::common::ParkingSceneType parking_scene_type_;
  athena::common::ParkingSceneType *parking_scene_type_ptr_ = nullptr;
  //车位是否完成更新
  bool is_update_finished_;
  bool *is_update_finished_ptr_ = nullptr;
};
} // namespace interface
} // namespace athena
