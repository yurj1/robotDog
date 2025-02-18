/**
 * @file    header.hpp
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

#include "modules/common/interface/time.hpp"

/**
 * @namespace athena::interface
 * @brief athena::interface
 */
namespace athena {
namespace interface {
class Header {
public:
  Header() {
    seq_ = 0;
    frame_id_.clear();
  }
  ~Header() = default;

  inline void set_seq(const uint32_t& seq) {
    seq_ = seq;
    seq_ptr_ = &seq_;
  }

  inline const uint32_t& seq() const { return seq_; }

  inline uint32_t* mutable_seq() { return &seq_; }

  inline bool has_seq() { return (seq_ptr_ != nullptr); }

  inline void set_stamp(const athena::interface::Time& stamp) {
    stamp_ = stamp;
    stamp_ptr_ = &stamp_;
  }

  inline const athena::interface::Time& stamp() const { return stamp_; }

  inline athena::interface::Time* mutable_stamp() { return &stamp_; }

  inline bool has_stamp() { return (stamp_ptr_ != nullptr); }

  inline void set_frame_id(const std::string& frame_id) {
    frame_id_ = frame_id;
    frame_id_ptr_ = &frame_id_;
  }

  inline const std::string& frame_id() const { return frame_id_; }

  inline std::string* mutable_frame_id() { return &frame_id_; }

  inline bool has_frame_id() { return (frame_id_ptr_ != nullptr); }

  void operator=(const Header& header) { CopyFrom(header); }

  void CopyFrom(const Header& header) {
    seq_ = header.seq();
    stamp_ = header.stamp();
    frame_id_ = header.frame_id();
  }

protected:
  // Sequence number for each message. Each module maintains its own counter for
  // sequence_num, always starting from 1 on boot.
  uint32_t seq_;
  uint32_t* seq_ptr_ = nullptr;
  //时间戳
  athena::interface::Time stamp_;
  athena::interface::Time* stamp_ptr_ = nullptr;
  //帧id
  std::string frame_id_;
  std::string* frame_id_ptr_ = nullptr;
};
} // namespace interface
} // namespace athena
