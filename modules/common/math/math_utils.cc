/******************************************************************************
 * Copyright 2017 The Apollo Authors. All Rights Reserved.
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

#include "modules/common/math/math_utils.h"

#include <cmath>
#include <utility>

namespace athena {
namespace common {
namespace math {

double Norm(double para1, double para2) {
  return std::sqrt(para1 * para1 + para2 * para2);
}
double Sqr(const double x) { return x * x; }

double CrossProd(const Vec2d& start_point, const Vec2d& end_point_1,
                 const Vec2d& end_point_2) {
  return (end_point_1 - start_point).CrossProd(end_point_2 - start_point);
}

double InnerProd(const Vec2d& start_point, const Vec2d& end_point_1,
                 const Vec2d& end_point_2) {
  return (end_point_1 - start_point).InnerProd(end_point_2 - start_point);
}

double CrossProd(const double x0, const double y0, const double x1,
                 const double y1) {
  return x0 * y1 - x1 * y0;
}

double InnerProd(const double x0, const double y0, const double x1,
                 const double y1) {
  return x0 * x1 + y0 * y1;
}

double WrapAngle(const double angle) {
  const double new_angle = std::fmod(angle, M_PI * 2.0);
  return new_angle < 0 ? new_angle + M_PI * 2.0 : new_angle;
}

double NormalizeAngle(const double angle) {
  double a = std::fmod(angle + M_PI, 2.0 * M_PI);
  if (a < 0.0) {
    a += (2.0 * M_PI);
  }
  return a - M_PI;
}

double AngleDiff(const double from, const double to) {
  return NormalizeAngle(to - from);
}

double NormalizeAngle2(const double angle) {
  double a = std::fmod(angle, 2.0 * M_PI);
  if (a < 0.0) {
    a += (2.0 * M_PI);
  }
  return a;
}

double AngleDiff2(const double from, const double to) {
  return NormalizeAngle2(to - from);
}

int RandomInt(const int s, const int t, unsigned int rand_seed) {
  if (s >= t) {
    return s;
  }
  return s + rand_r(&rand_seed) % (t - s + 1);
}

double RandomDouble(const double s, const double t, unsigned int rand_seed) {
  return s + (t - s) / 16383.0 * (rand_r(&rand_seed) & 16383);
}

// Gaussian
double Gaussian(const double u, const double std, const double x) {
  return (1.0 / std::sqrt(2 * M_PI * std * std)) *
         std::exp(-(x - u) * (x - u) / (2 * std * std));
}

Eigen::Vector2d RotateVector2d(const Eigen::Vector2d& v_in,
                               const double theta) {
  const double cos_theta = std::cos(theta);
  const double sin_theta = std::sin(theta);

  auto x = cos_theta * v_in.x() - sin_theta * v_in.y();
  auto y = sin_theta * v_in.x() + cos_theta * v_in.y();

  return {x, y};
}

std::pair<double, double> Cartesian2Polar(double x, double y) {
  double r = std::sqrt(x * x + y * y);
  double theta = std::atan2(y, x);
  return std::make_pair(r, theta);
}

double VectorialAngle(const Vec2d& start_point, const Vec2d& end_point_1,
                      const Vec2d& end_point_2) {
  double v1_length = std::sqrt(
      (end_point_1 - start_point).y() * (end_point_1 - start_point).y() +
      (end_point_1 - start_point).x() * (end_point_1 - start_point).x());
  double v2_length = std::sqrt(
      (end_point_2 - start_point).y() * (end_point_2 - start_point).y() +
      (end_point_2 - start_point).x() * (end_point_2 - start_point).x());
  double f1 =
      (end_point_1 - start_point).x() * (end_point_2 - start_point).x() +
      (end_point_1 - start_point).y() * (end_point_2 - start_point).y();
  double f2 = v1_length * v2_length;
  double f = f1 / f2;
  return std::acos(std::fminl(std::fmaxl(f,-1.0),1.0));
}
}  // namespace math
}  // namespace common
}  // namespace athena
