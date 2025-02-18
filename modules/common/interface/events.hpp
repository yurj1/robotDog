/**
 * @file    events.hpp
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

#include "modules/common/interface/event.hpp"
#include "modules/common/interface/header.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class Events {
public:
  Events() {
    events_mutex_ = std::make_shared<std::mutex>();

    version_ = 0;
    clear_events();
  }
  ~Events() = default;

  inline void set_header(const athena::interface::Header& header) {
    header_ = header;
    header_ptr_ = &header_;
  }

  inline const athena::interface::Header& header() const { return header_; }

  inline athena::interface::Header* mutable_header() { return &header_; }

  inline bool has_header() { return (header_ptr_ != nullptr); }

  inline void set_version(const int32_t& version) {
    version_ = version;
    version_ptr_ = &version_;
  }

  inline const int32_t& version() const { return version_; }

  inline int32_t* mutable_version() { return &version_; }

  inline bool has_version() { return (version_ptr_ != nullptr); }

  inline void set_events(std::vector<athena::interface::Event>* events) {
    std::lock_guard<std::mutex> lock(*events_mutex_);
    events_.assign(events->begin(), events->end());
  }

  inline void set_events(const std::vector<athena::interface::Event>& events) {
    std::lock_guard<std::mutex> lock(*events_mutex_);
    events_ = events;
  }

  inline void set_events(const uint32_t index,
                         athena::interface::Event& events) {
    std::lock_guard<std::mutex> lock(*events_mutex_);
    events_[index] = events;
  }

  inline void add_events(const athena::interface::Event& events) {
    std::lock_guard<std::mutex> lock(*events_mutex_);
    events_.emplace_back(events);
  }

  inline const athena::interface::Event& events(uint32_t index) const {
    std::lock_guard<std::mutex> lock(*events_mutex_);
    return events_[index];
  }

  inline std::vector<athena::interface::Event>* mutable_events() {
    std::lock_guard<std::mutex> lock(*events_mutex_);
    return &events_;
  }

  inline void events(std::vector<athena::interface::Event>& events) const {
    std::lock_guard<std::mutex> lock(*events_mutex_);
    events.assign(events_.begin(), events_.end());
  }

  inline const std::vector<athena::interface::Event>& events() const {
    std::lock_guard<std::mutex> lock(*events_mutex_);
    return events_;
  }

  inline uint32_t events_size() const {
    std::lock_guard<std::mutex> lock(*events_mutex_);
    return events_.size();
  }

  inline void clear_events() {
    std::lock_guard<std::mutex> lock(*events_mutex_);
    events_.clear();
    events_.shrink_to_fit();
  }

  inline bool has_events() { return (events_size() != 0); }

  void operator=(const Events& events) { CopyFrom(events); }

  void CopyFrom(const Events& events) {
    header_ = events.header();
    version_ = events.version();
    events_ = events.events();
  }

protected:
  std::shared_ptr<std::mutex> events_mutex_;
  athena::interface::Header header_;
  athena::interface::Header* header_ptr_ = nullptr;
  //软件模块版本号
  int32_t version_;
  int32_t* version_ptr_ = nullptr;
  //时间集
  std::vector<athena::interface::Event> events_;
};
} // namespace interface
} // namespace athena
