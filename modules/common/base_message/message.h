/**
 * @file              message.h
 * @author       jiangchengjie (jiangchengjie@indrv.cn)
 * @brief
 * @version     1.0.0
 * @date           2021-06-25 11:51:09
 * @copyright Copyright (c) 2021
 * @license      GNU General Public License (GPL)
 */
#pragma once

#include <iostream>

/**
 * @namespace athena::common
 * @brief athena::common
 */
namespace athena {
namespace common {
enum MessageType {
  LCM = 0,
  DDS = 1,
  ROS = 2,
  ADSFI = 3,
  ROS2 = 4,
  MQTT = 5,
  ZMQ = 6,
};

typedef struct {
  MessageType type;
  std::string name;
  std::string url;
} Message;
} // namespace common
} // namespace athena
