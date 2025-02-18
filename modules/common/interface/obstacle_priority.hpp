/**
 * @file    obstacle_priority.hpp
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#pragma once

#include <iostream>
#include <stdint.h>

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class ObstaclePriority {
public:
  ObstaclePriority() {
    priority_ = athena::interface::ObstaclePriority::Priority::CAUTION;
  }
  ~ObstaclePriority() = default;

  enum Priority {
    CAUTION = 1,
    NORMAL = 2,
    IGNORE = 3,
  };

  inline void
  set_priority(const athena::interface::ObstaclePriority::Priority& priority) {
    priority_ = priority;
    priority_ptr_ = &priority_;
  }

  inline const athena::interface::ObstaclePriority::Priority& priority() const {
    return priority_;
  }

  inline athena::interface::ObstaclePriority::Priority* mutable_priority() {
    return &priority_;
  }

  inline bool has_priority() { return (priority_ptr_ != nullptr); }

  void operator=(const ObstaclePriority& obstacle_priority) {
    CopyFrom(obstacle_priority);
  }

  void CopyFrom(const ObstaclePriority& obstacle_priority) {
    priority_ = obstacle_priority.priority();
  }

protected:
  // CAUTION = 1; NORMAL = 2; IGNORE = 3;
  athena::interface::ObstaclePriority::Priority priority_;
  athena::interface::ObstaclePriority::Priority* priority_ptr_ = nullptr;
};
} // namespace interface
} // namespace athena
