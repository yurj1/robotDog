/**
 * @file    alarm_message.hpp
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#pragma once

#include <string>
#include <iostream>
#include <stdint.h>

#include "modules/common/enum/enum.h"
#include "modules/common/interface/header.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class AlarmMessage {
public:
  AlarmMessage() {
    alarm_proc_.clear();
    alarm_level_ = athena::common::AlarmLevel::ALARM_INFO;
    alarm_type_ = athena::common::AlarmType::ALARM_TYPE_REPORT;
    alarm_id_ = 0;
    alarm_display_ = athena::common::AlarmDisplay::ALARM_DISPLAY_TEXT;
    alarm_data_.clear();
  }
  ~AlarmMessage() = default;

  inline void set_header(const athena::interface::Header& header) {
    header_ = header;
    header_ptr_ = &header_;
  }

  inline const athena::interface::Header& header() const { return header_; }

  inline athena::interface::Header* mutable_header() { return &header_; }

  inline bool has_header() { return (header_ptr_ != nullptr); }

  inline void set_alarm_proc(const std::string& alarm_proc) {
    alarm_proc_ = alarm_proc;
    alarm_proc_ptr_ = &alarm_proc_;
  }

  inline const std::string& alarm_proc() const { return alarm_proc_; }

  inline std::string* mutable_alarm_proc() { return &alarm_proc_; }

  inline bool has_alarm_proc() { return (alarm_proc_ptr_ != nullptr); }

  inline void set_alarm_level(const athena::common::AlarmLevel& alarm_level) {
    alarm_level_ = alarm_level;
    alarm_level_ptr_ = &alarm_level_;
  }

  inline const athena::common::AlarmLevel& alarm_level() const {
    return alarm_level_;
  }

  inline athena::common::AlarmLevel* mutable_alarm_level() {
    return &alarm_level_;
  }

  inline bool has_alarm_level() { return (alarm_level_ptr_ != nullptr); }

  inline void set_alarm_type(const athena::common::AlarmType& alarm_type) {
    alarm_type_ = alarm_type;
    alarm_type_ptr_ = &alarm_type_;
  }

  inline const athena::common::AlarmType& alarm_type() const {
    return alarm_type_;
  }

  inline athena::common::AlarmType* mutable_alarm_type() {
    return &alarm_type_;
  }

  inline bool has_alarm_type() { return (alarm_type_ptr_ != nullptr); }

  inline void set_alarm_id(const int32_t& alarm_id) {
    alarm_id_ = alarm_id;
    alarm_id_ptr_ = &alarm_id_;
  }

  inline const int32_t& alarm_id() const { return alarm_id_; }

  inline int32_t* mutable_alarm_id() { return &alarm_id_; }

  inline bool has_alarm_id() { return (alarm_id_ptr_ != nullptr); }

  inline void
  set_alarm_display(const athena::common::AlarmDisplay& alarm_display) {
    alarm_display_ = alarm_display;
    alarm_display_ptr_ = &alarm_display_;
  }

  inline const athena::common::AlarmDisplay& alarm_display() const {
    return alarm_display_;
  }

  inline athena::common::AlarmDisplay* mutable_alarm_display() {
    return &alarm_display_;
  }

  inline bool has_alarm_display() { return (alarm_display_ptr_ != nullptr); }

  inline void set_alarm_data(const std::string& alarm_data) {
    alarm_data_ = alarm_data;
    alarm_data_ptr_ = &alarm_data_;
  }

  inline const std::string& alarm_data() const { return alarm_data_; }

  inline std::string* mutable_alarm_data() { return &alarm_data_; }

  inline bool has_alarm_data() { return (alarm_data_ptr_ != nullptr); }

  void operator=(const AlarmMessage& alarm_message) { CopyFrom(alarm_message); }

  void CopyFrom(const AlarmMessage& alarm_message) {
    header_ = alarm_message.header();
    alarm_proc_ = alarm_message.alarm_proc();
    alarm_level_ = alarm_message.alarm_level();
    alarm_type_ = alarm_message.alarm_type();
    alarm_id_ = alarm_message.alarm_id();
    alarm_display_ = alarm_message.alarm_display();
    alarm_data_ = alarm_message.alarm_data();
  }

protected:
  //消息头
  athena::interface::Header header_;
  athena::interface::Header* header_ptr_ = nullptr;
  //产生告警的进程名
  std::string alarm_proc_;
  std::string* alarm_proc_ptr_ = nullptr;
  //告警等级
  athena::common::AlarmLevel alarm_level_;
  athena::common::AlarmLevel* alarm_level_ptr_ = nullptr;
  //告警类型
  athena::common::AlarmType alarm_type_;
  athena::common::AlarmType* alarm_type_ptr_ = nullptr;
  //告警序列号，用于恢复告警
  int32_t alarm_id_;
  int32_t* alarm_id_ptr_ = nullptr;
  //告警展示类型
  athena::common::AlarmDisplay alarm_display_;
  athena::common::AlarmDisplay* alarm_display_ptr_ = nullptr;
  //告警正文
  std::string alarm_data_;
  std::string* alarm_data_ptr_ = nullptr;
};
} // namespace interface
} // namespace athena
