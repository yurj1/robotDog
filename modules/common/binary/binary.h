/**
 * @file              binary.h
 * @author       jiangchengjie (jiangchengjie@indrv.cn)
 * @brief
 * @version     1.0.0
 * @date           2021-12-29 11:19:37
 * @copyright Copyright (c) 2021
 * @license      GNU General Public License (GPL)
 */
#pragma once

#include <string>

namespace athena {
namespace common {
namespace binary {
std::string GetName();
void SetName(const std::string& name);
} // namespace binary
} // namespace common
} // namespace athena
