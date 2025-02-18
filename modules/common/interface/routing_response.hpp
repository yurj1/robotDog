/**
 * @file    routing_response.hpp
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
#include "modules/common/interface/lane_info.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class RoutingResponse {
public:
  RoutingResponse() {
    lane_list_mutex_ = std::make_shared<std::mutex>();

    plan_status_ = athena::interface::RoutingResponse::PlanStatus::PLAN_SUCCESS;
    replan_flag_ =
        athena::interface::RoutingResponse::ReplanFlag::REPLAN_FLAG_NONE;
    route_reason_ =
        athena::interface::RoutingResponse::RouteReason::ROUTE_REASON_HMI;
    clear_lane_list();
  }
  ~RoutingResponse() = default;

  enum ReplanFlag {
    REPLAN_FLAG_NONE = 0,
    REPLAN_FLAG_NAVI = 1,
    REPLAN_FLAG_HUMAN = 2,
  };

  enum RouteReason {
    ROUTE_REASON_HMI = 0,
    ROUTE_REASON_PLATOON_HEADER = 1,
    ROUTE_REASON_PLATOON_OTHER = 2,
  };

  enum PlanStatus {
    PLAN_SUCCESS = 0,
    REQUEST_ERROR = 1,
    OUT_OF_MAP = 2,
  };

  inline void set_header(const athena::interface::Header& header) {
    header_ = header;
    header_ptr_ = &header_;
  }

  inline const athena::interface::Header& header() const { return header_; }

  inline athena::interface::Header* mutable_header() { return &header_; }

  inline bool has_header() { return (header_ptr_ != nullptr); }

  inline void set_plan_status(
      const athena::interface::RoutingResponse::PlanStatus& plan_status) {
    plan_status_ = plan_status;
    plan_status_ptr_ = &plan_status_;
  }

  inline const athena::interface::RoutingResponse::PlanStatus&
  plan_status() const {
    return plan_status_;
  }

  inline athena::interface::RoutingResponse::PlanStatus* mutable_plan_status() {
    return &plan_status_;
  }

  inline bool has_plan_status() { return (plan_status_ptr_ != nullptr); }

  inline void set_replan_flag(
      const athena::interface::RoutingResponse::ReplanFlag& replan_flag) {
    replan_flag_ = replan_flag;
    replan_flag_ptr_ = &replan_flag_;
  }

  inline const athena::interface::RoutingResponse::ReplanFlag&
  replan_flag() const {
    return replan_flag_;
  }

  inline athena::interface::RoutingResponse::ReplanFlag* mutable_replan_flag() {
    return &replan_flag_;
  }

  inline bool has_replan_flag() { return (replan_flag_ptr_ != nullptr); }

  inline void set_route_reason(
      const athena::interface::RoutingResponse::RouteReason& route_reason) {
    route_reason_ = route_reason;
    route_reason_ptr_ = &route_reason_;
  }

  inline const athena::interface::RoutingResponse::RouteReason&
  route_reason() const {
    return route_reason_;
  }

  inline athena::interface::RoutingResponse::RouteReason*
  mutable_route_reason() {
    return &route_reason_;
  }

  inline bool has_route_reason() { return (route_reason_ptr_ != nullptr); }

  inline void
  set_lane_list(std::vector<athena::interface::LaneInfo>* lane_list) {
    std::lock_guard<std::mutex> lock(*lane_list_mutex_);
    lane_list_.assign(lane_list->begin(), lane_list->end());
  }

  inline void
  set_lane_list(const std::vector<athena::interface::LaneInfo>& lane_list) {
    std::lock_guard<std::mutex> lock(*lane_list_mutex_);
    lane_list_ = lane_list;
  }

  inline void set_lane_list(const uint32_t index,
                            athena::interface::LaneInfo& lane_list) {
    std::lock_guard<std::mutex> lock(*lane_list_mutex_);
    lane_list_[index] = lane_list;
  }

  inline void add_lane_list(const athena::interface::LaneInfo& lane_list) {
    std::lock_guard<std::mutex> lock(*lane_list_mutex_);
    lane_list_.emplace_back(lane_list);
  }

  inline const athena::interface::LaneInfo& lane_list(uint32_t index) const {
    std::lock_guard<std::mutex> lock(*lane_list_mutex_);
    return lane_list_[index];
  }

  inline std::vector<athena::interface::LaneInfo>* mutable_lane_list() {
    std::lock_guard<std::mutex> lock(*lane_list_mutex_);
    return &lane_list_;
  }

  inline void
  lane_list(std::vector<athena::interface::LaneInfo>& lane_list) const {
    std::lock_guard<std::mutex> lock(*lane_list_mutex_);
    lane_list.assign(lane_list_.begin(), lane_list_.end());
  }

  inline const std::vector<athena::interface::LaneInfo>& lane_list() const {
    std::lock_guard<std::mutex> lock(*lane_list_mutex_);
    return lane_list_;
  }

  inline uint32_t lane_list_size() const {
    std::lock_guard<std::mutex> lock(*lane_list_mutex_);
    return lane_list_.size();
  }

  inline void clear_lane_list() {
    std::lock_guard<std::mutex> lock(*lane_list_mutex_);
    lane_list_.clear();
    lane_list_.shrink_to_fit();
  }

  inline bool has_lane_list() { return (lane_list_size() != 0); }

  void operator=(const RoutingResponse& routing_response) {
    CopyFrom(routing_response);
  }

  void CopyFrom(const RoutingResponse& routing_response) {
    header_ = routing_response.header();
    plan_status_ = routing_response.plan_status();
    replan_flag_ = routing_response.replan_flag();
    route_reason_ = routing_response.route_reason();
    lane_list_ = routing_response.lane_list();
  }

protected:
  std::shared_ptr<std::mutex> lane_list_mutex_;
  // timestamp is included in header
  athena::interface::Header header_;
  athena::interface::Header* header_ptr_ = nullptr;
  //规划结果状态
  athena::interface::RoutingResponse::PlanStatus plan_status_;
  athena::interface::RoutingResponse::PlanStatus* plan_status_ptr_ = nullptr;
  // REPLAN_FLAG_NONE=0  //不需要重规划 REPLAN_FLAG_NAVI=1 //网络层重规划
  // REPLAN_FLAG_HUMAN=2 //人为重规划
  athena::interface::RoutingResponse::ReplanFlag replan_flag_;
  athena::interface::RoutingResponse::ReplanFlag* replan_flag_ptr_ = nullptr;
  //规划原因 ROUTE_REASON_HMI = 0 //hmi上触发规划 ROUTE_REASON_PLATOON_HEADER =
  //1 //车队头车下发规划 ROUTE_REASON_PLATOON_OTHER = 2 //车队其他车辆下发规划
  athena::interface::RoutingResponse::RouteReason route_reason_;
  athena::interface::RoutingResponse::RouteReason* route_reason_ptr_ = nullptr;
  //分段路径规划结果
  std::vector<athena::interface::LaneInfo> lane_list_;
};
} // namespace interface
} // namespace athena
