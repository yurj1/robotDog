/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/

/**
 * @file
 **/

#pragma once

#include <utility>
#include <vector>

#include "modules/common/interface/path_point.hpp"
#include "modules/common/math/vec3d.h"
#include "modules/common/math/math_utils.h"

namespace athena {
namespace common {
namespace math {
using namespace athena::interface;
class PathMatcher {
public:
  PathMatcher() = delete;

  static PathPoint MatchToPath(const std::vector<PathPoint>& reference_line,
                               const double x, const double y);

  static PathPoint MatchToPath(const std::vector<PathPoint>& reference_line,
                               const Vec3d& position, const double yaw,
                               int& index_min);

  static std::pair<double, double>
  GetPathFrenetCoordinate(const std::vector<PathPoint>& reference_line,
                          const double x, const double y);

  static PathPoint MatchToPath(const std::vector<PathPoint>& reference_line,
                               const double s);

private:
  static PathPoint FindProjectionPoint(const PathPoint& p0, const PathPoint& p1,
                                       const double x, const double y);
};

} // namespace math
} // namespace common
} // namespace athena
