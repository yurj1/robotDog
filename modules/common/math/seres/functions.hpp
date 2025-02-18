#include <math.h>
#include <iostream>
#include <vector>

#include "modules/common/interface/routing_response.hpp"
#include "modules/common/interface/point_2d.hpp"
#include "modules/common/interface/point_3d.hpp"
#include "modules/common/interface/parking_info.hpp"
#include "modules/common/math/polygon2d.h"
#include "modules/common/enum/enum.h"

namespace athena
{
    namespace common
    {
        namespace math
        {
            class SeresFunction
            {
            public:
                /**
                 * @brief  返回多边形与目标圆的交点
                 * @param  P 为圆心的位置
                 * @param  polygon 为多边形各点的位置，应按顺时针或者逆时针顺序
                 * @param  radius 为目标半径
                 * @return std::vector<athena::interface::Point3D> .
                 */
                std::vector<athena::interface::Point3D> PolygonAndCircleIntersection(athena::interface::Point3D P, std::vector<athena::interface::Point3D> polygon, float radius)
                {
                    std::vector<athena::interface::Point3D> points;
                    double m, n;         // 多边形选定边上两端点到圆心的距离
                    double sag_x, sag_y; // 定义垂点
                    double distance;     // 圆心到多边形边所在直线的距离
                    float angle_1;       // 多边形边所在直线的角度
                    for (int i = 0; i < polygon.size(); i++)
                    {
                        distance = std::sqrt((polygon[i].y() - P.y()) * (polygon[i].y() - P.y()) + (polygon[i].x() - P.x()) * (polygon[i].x() - P.x()));
                        if (distance == radius)
                        {
                            points.push_back(polygon[i]);
                        }
                    } // 第一次循环，检测多边形是否有顶点在圆上
                    // polygon.push_back(polygon[0]) ; // 如果多边形首尾相连
                    for (int i = 1; i < polygon.size(); i++)
                    { // 第二次循环，寻找边与圆的交点
                        angle_1 = atan2((polygon[i].y() - polygon[i - 1].y()), (polygon[i].x() - polygon[i - 1].x()));
                        if (polygon[i].x() == polygon[i - 1].x())
                        {
                            distance = abs(P.x() - polygon[i].x()); // 圆心到边所在直线的距离
                            sag_x = polygon[i].x();
                            sag_y = P.y();
                        }
                        else
                        {
                            float k = tan(angle_1);
                            distance = abs(k * P.x() - P.y() + polygon[i].y() - k * polygon[i].x()) / std::sqrt(k * k + 1);
                            sag_x = (P.x() + k * P.y() - k * (polygon[i].y() - k * polygon[i].x())) / (k * k + 1);
                            sag_y = (k * P.x() + k * k * P.y() + polygon[i].y() - k * polygon[i].x()) / (k * k + 1);
                        } // 一般情况下的距离与角度
                        if (distance == radius)
                        { // 距离等于半径，存在一个切点
                            athena::interface::Point3D point;
                            point.set_x(sag_x);
                            point.set_y(sag_y); // 切点位置
                            points.push_back(point);
                        }
                        if (distance < radius)
                        { // 距离小于半径，根据端点存在不同情况
                            m = std::sqrt((polygon[i].y() - P.y()) * (polygon[i].y() - P.y()) + (polygon[i].x() - P.x()) * (polygon[i].x() - P.x()));
                            n = std::sqrt((polygon[i - 1].y() - P.y()) * (polygon[i - 1].y() - P.y()) + (polygon[i - 1].x() - P.x()) * (polygon[i - 1].x() - P.x()));
                            if (m <= radius && n > radius)
                            {
                                athena::interface::Point3D point;
                                double l = std::sqrt(radius * radius - distance * distance);
                                if (polygon[i].x() == polygon[i - 1].x())
                                {
                                    if ((sag_y > polygon[i].y() && sag_y < polygon[i - 1].y()) || (sag_y < polygon[i].y() && sag_y > polygon[i - 1].y()))
                                    {
                                        point.set_x(sag_x);
                                        point.set_y(sag_y - l);
                                        points.push_back(point);
                                    }
                                }
                                else if ((sag_x > polygon[i].x() && sag_x < polygon[i - 1].x()) || (sag_x < polygon[i].x() && sag_x > polygon[i - 1].x()))
                                {
                                    point.set_x(sag_x - l * cos(angle_1));
                                    point.set_y(sag_y - l * sin(angle_1));
                                    points.push_back(point);
                                }
                            }
                            if (m > radius && n <= radius)
                            {
                                athena::interface::Point3D point;
                                double l = std::sqrt(radius * radius - distance * distance);
                                if (polygon[i].x() == polygon[i - 1].x())
                                {
                                    if ((sag_y > polygon[i].y() && sag_y < polygon[i - 1].y()) || (sag_y < polygon[i].y() && sag_y > polygon[i - 1].y()))
                                    {
                                        point.set_x(sag_x);
                                        point.set_y(sag_y + l);
                                        points.push_back(point);
                                    }
                                }
                                else if ((sag_x > polygon[i].x() && sag_x < polygon[i - 1].x()) || (sag_x < polygon[i].x() && sag_x > polygon[i - 1].x()))
                                {
                                    point.set_x(sag_x + l * cos(angle_1));
                                    point.set_y(sag_y + l * sin(angle_1));
                                    points.push_back(point);
                                }
                            }
                            if (m > radius && n > radius)
                            {
                                if (polygon[i].x() == polygon[i - 1].x())
                                {
                                    if ((sag_y > polygon[i].y() && sag_y < polygon[i - 1].y()) || (sag_y < polygon[i].y() && sag_y > polygon[i - 1].y()))
                                    {
                                        athena::interface::Point3D point1, point2;
                                        double l = std::sqrt(radius * radius - distance * distance);
                                        point1.set_x(sag_x);
                                        point1.set_y(sag_y + l);
                                        point2.set_x(sag_x);
                                        point2.set_y(sag_y - l);
                                        points.push_back(point1);
                                        points.push_back(point2);
                                    }
                                }
                                else if ((sag_x > polygon[i].x() && sag_x < polygon[i - 1].x()) || (sag_x < polygon[i].x() && sag_x > polygon[i - 1].x()))
                                {
                                    athena::interface::Point3D point1, point2;
                                    double l = std::sqrt(radius * radius - distance * distance);
                                    point1.set_x(sag_x + l * cos(angle_1));
                                    point1.set_y(sag_y + l * sin(angle_1));
                                    point2.set_x(sag_x - l * cos(angle_1));
                                    point2.set_y(sag_y - l * sin(angle_1));
                                    points.push_back(point1);
                                    points.push_back(point2);
                                }
                            }
                        } // 如果距离大于半径没有交点
                    }
                    return points;
                }

                /**
                 * @brief  返回小圆绕行路径
                 * @param  p 为目标点位置
                 * @param  pose_0 为当前车辆位置点
                 * @param  radius 为绕行半径（圆的）
                 * @param  length 为规划路径点之间的间隔
                 * @param  clockwise 为绕行方向，true为顺时针，false为逆时针
                 * @return std::vector<athena::interface::Point3D> .
                 */
                std::vector<athena::interface::Point3D> SmallCircleRoutine(athena::interface::Point3D p, athena::interface::Point3D pose_0, float radius, float length, float angle, bool clockwise)
                {
                    // 根据方向与角度进行圆形绕行
                    //  pose_0为当前车辆位置点，p为目标点位置;
                    //  length为规划路径点之间的间隔,radius为绕行半径;angle为绕行的角度;clockwise为绕行方向，true为顺时针，false为逆时针
                    std::vector<athena::interface::Point3D> path;
                    athena::interface::Point3D pose_midpoint, pose_1;
                    double d = std::sqrt((p.x() - pose_0.x()) * (p.x() - pose_0.x()) + (p.y() - pose_0.y()) * (p.y() - pose_0.y()));
                    float angle_pose0_p = atan2((p.y() - pose_0.y()), (p.x() - pose_0.x()));
                    float dif_angle = length / radius;
                    float direction;
                    if (clockwise)
                    {
                        direction = -1;
                    }
                    else
                    {
                        direction = 1;
                    } // 判断绕行的方向，顺时针为-1，角度减小
                    if (d >= radius)
                    {                                                  // 如果车辆在圆上或者在圆外,走切钱到圆周上
                        double m = std::sqrt(d * d - radius * radius); // 计算车辆位置点到圆上切点的距离
                        float angle_1 = atan2(radius, m);
                        for (double i = 0; i <= m; i = i + length)
                        {
                            pose_midpoint.set_x(pose_0.x() + cos(angle_pose0_p - direction * angle_1) * i);
                            pose_midpoint.set_y(pose_0.y() + sin(angle_pose0_p - direction * angle_1) * i);
                            path.push_back(pose_midpoint);
                        } // 切线的路径
                    }
                    else
                    { // 如果在圆内，按角度递增走到圆上，方向与旋转方向相同
                        angle_pose0_p = atan2((pose_0.y() - p.y()), (pose_0.x() - p.x()));
                        float angle_1 = 0;
                        for (double i = d; i <= radius; i = i + 0.7 * length)
                        {
                            pose_midpoint.set_x(p.x() + cos(angle_pose0_p + direction * angle_1) * i);
                            pose_midpoint.set_y(p.y() + sin(angle_pose0_p + direction * angle_1) * i);
                            path.push_back(pose_midpoint);
                            angle_1 = angle_1 + 0.7 * dif_angle;
                        }
                    }
                    pose_1.set_x(pose_midpoint.x());
                    pose_1.set_y(pose_midpoint.y());
                    float angle_p_pose1 = atan2((pose_1.y() - p.y()), (pose_1.x() - p.x()));
                    for (float i = 0; i <= angle; i = i + dif_angle)
                    {
                        pose_midpoint.set_x(p.x() + cos(angle_p_pose1 + direction * i) * radius);
                        pose_midpoint.set_y(p.y() + sin(angle_p_pose1 + direction * i) * radius);
                        path.push_back(pose_midpoint);
                    } // 绕行过程，按给定方向与角度绕行
                    return path;
                }
                // std::vector<athena::interface::Point3D> SmallCircleRoutine(athena::interface::Point3D p, athena::interface::Point3D pose_0, float radius, float length)
                // {
                //     std::vector<athena::interface::Point3D> path;
                //     double d = std::sqrt((p.x() - pose_0.x()) * (p.x() - pose_0.x()) + (p.y() - pose_0.y()) * (p.y() - pose_0.y()));
                //     float sin_alpha = (pose_0.y() - p.y()) / d;
                //     float cos_alpha = (pose_0.x() - p.x()) / d; // 计算车辆位置点相对于目标点的角度信息
                //     athena::interface::Point3D pose_1, pose_2, pose_3, pose_midpoint;
                //     pose_1.set_x(p.x() + radius * sin_alpha);
                //     pose_1.set_y(p.y() - radius * cos_alpha);
                //     pose_2.set_x(p.x() - radius * cos_alpha);
                //     pose_2.set_y(p.y() - radius * sin_alpha);
                //     pose_3.set_x(p.x() - radius * sin_alpha);
                //     pose_3.set_y(p.y() + radius * cos_alpha);           // 计算在半径圆上的三个参考点
                //     double path_1 = std::sqrt(d * d + radius * radius); // 计算第一段路线的长度
                //     double path_2 = radius * 1.4142;                    // 计算后面两段路线的长度
                //     float sin_1 = (pose_1.y() - pose_0.y()) / path_1;
                //     float cos_1 = (pose_1.x() - pose_0.x()) / path_1; // 计算第一个参考点相对于车辆位置点的角度信息
                //     for (double i = 0; i < path_1; i = i + length)
                //     {
                //         pose_midpoint.set_x(pose_0.x() + i * cos_1);
                //         pose_midpoint.set_y(pose_0.y() + i * sin_1);
                //         path.push_back(pose_midpoint);
                //     } // 以length为长度间隔，计算中间点
                //     sin_1 = (pose_2.y() - pose_1.y()) / path_2;
                //     cos_1 = (pose_2.x() - pose_1.x()) / path_2; // 计算第二个参考点相对于第一个参考点的角度信息
                //     for (double i = 0; i < path_2; i = i + length)
                //     {
                //         pose_midpoint.set_x(pose_1.x() + i * cos_1);
                //         pose_midpoint.set_y(pose_1.y() + i * sin_1);
                //         path.push_back(pose_midpoint);
                //     } // 计算中间点
                //     sin_1 = (pose_3.y() - pose_2.y()) / path_2;
                //     cos_1 = (pose_3.x() - pose_2.x()) / path_2; // 计算第三个参考点相对于第二个参考点的角度信息
                //     for (double i = 0; i < path_2; i = i + length)
                //     {
                //         pose_midpoint.set_x(pose_2.x() + i * cos_1);
                //         pose_midpoint.set_y(pose_2.y() + i * sin_1);
                //         path.push_back(pose_midpoint);
                //     } // 计算中间点
                //     sin_1 = (pose_0.y() - pose_3.y()) / path_1;
                //     cos_1 = (pose_0.x() - pose_3.x()) / path_1;
                //     for (double i = 0; i < path_1; i = i + length)
                //     {
                //         pose_midpoint.set_x(pose_3.x() + i * cos_1);
                //         pose_midpoint.set_y(pose_3.y() + i * sin_1);
                //         path.push_back(pose_midpoint);
                //     } // 计算中间点
                //     path.push_back(pose_0); // 插入初始点，也是路径终点
                //     return path;            // 返回路径
                // }

                /**
                 * @brief  返回大圆绕行路径
                 * @param  p 为目标点位置
                 * @param  pose_0 为当前车辆位置点
                 * @param  radius 为绕行半径（方的）
                 * @param  length 为规划路径点之间的间隔
                 * @return std::vector<athena::interface::Point3D> .
                 */
                std::vector<athena::interface::Point3D> BigCircleRoutine(athena::interface::Point3D p, athena::interface::Point3D pose_0, float radius, float length)
                {
                    std::vector<athena::interface::Point3D> path;
                    double d = std::sqrt((p.x() - pose_0.x()) * (p.x() - pose_0.x()) + (p.y() - pose_0.y()) * (p.y() - pose_0.y()));
                    float sin_p_pose_0 = (pose_0.y() - p.y()) / d;
                    float cos_p_pose_0 = (pose_0.x() - p.x()) / d; // 计算车辆位置点相对于目标点的角度信息

                    if (d >= radius)
                    {                                                  // 如果车辆在圆上或者在圆外
                        double m = std::sqrt(d * d - radius * radius); // 计算车辆位置点到圆上切点的距离
                        float zeta = asin(m / d);                      // 计算车辆点与切点之间的角度
                        athena::interface::Point3D pose_1, pose_2, pose_midpoint;

                        float sin_1 = sin_p_pose_0 * cos(zeta) - cos_p_pose_0 * sin(zeta);
                        float cos_1 = cos_p_pose_0 * cos(zeta) + sin_p_pose_0 * sin(zeta); // 计算pose_1相对于目标点的三角函数
                        pose_1.set_x(p.x() + radius * cos_1);
                        pose_1.set_y(p.y() + radius * sin_1);
                        sin_1 = sin_p_pose_0 * cos(zeta) + cos_p_pose_0 * sin(zeta);
                        cos_1 = cos_p_pose_0 * cos(zeta) - sin_p_pose_0 * sin(zeta);
                        pose_2.set_x(p.x() + radius * cos_1);
                        pose_2.set_y(p.y() + radius * sin_1); // 计算在半径圆上的2个参考点
                        if (m != 0)
                        {
                            sin_1 = (pose_1.y() - pose_0.y()) / m;
                            cos_1 = (pose_1.x() - pose_0.x()) / m; // 计算pose1相对于车辆点的三角函数
                        }
                        for (double i = 0; i < m; i = i + length)
                        {
                            pose_midpoint.set_x(pose_0.x() + i * cos_1);
                            pose_midpoint.set_y(pose_0.y() + i * sin_1);
                            path.push_back(pose_midpoint);
                        } // 以length为长度间隔，计算中间点
                        sin_1 = (pose_1.y() - p.y()) / radius;
                        cos_1 = (pose_1.x() - p.x()) / radius; // 计算pose1相对于目标点的三角函数
                        float sin_p_midpoint, cos_p_midpoint;
                        float dif_angle = length / radius; // 根据间隔距离确定角度的微分值
                        for (float i = 0; i < M_PI; i = i + dif_angle)
                        {
                            // 从目标点出发，根据其到圆上各点的三角函数信息计算中间点
                            sin_p_midpoint = sin_1 * cos(i) - cos_1 * sin(i);
                            cos_p_midpoint = cos_1 * cos(i) + sin_1 * sin(i);
                            pose_midpoint.set_x(p.x() + radius * cos_p_midpoint);
                            pose_midpoint.set_y(p.y() + radius * sin_p_midpoint);
                            path.push_back(pose_midpoint);
                        }
                        path.push_back(pose_2); // 插入最后的pose2点
                        return path;            // 返回路径
                    }
                    else
                    {
                        float distance_p_minpoint = d;
                        float i = 0;
                        float sin_p_pose0 = (pose_0.y() - p.y()) / d;
                        float cos_p_pose0 = (pose_0.x() - p.x()) / d;
                        athena::interface::Point3D pose_midpoint;
                        while (i < M_PI)
                        {
                            float sin_midpoint = sin_p_pose0 * cos(i) - cos_p_pose0 * sin(i);
                            float cos_midpoint = cos_p_pose0 * cos(i) + sin_p_pose0 * sin(i);
                            pose_midpoint.set_x(p.x() + distance_p_minpoint * cos_midpoint);
                            pose_midpoint.set_y(p.y() + distance_p_minpoint * sin_midpoint);
                            path.push_back(pose_midpoint);
                            if (distance_p_minpoint < (d - 0.2))
                            {
                                distance_p_minpoint = distance_p_minpoint + 0.2;
                                i = i + length / (radius * 2);
                            }
                            else
                            {
                                i = i + length / radius;
                            }
                        }
                        return path;
                    }
                }

                /**
                 * @brief  计算车头与路径夹角
                 * @param  heading 为车头朝向
                 * @param  target_angle 为轨迹点朝向
                 * @return float .
                 */
                float IncludedAngleCalculation(float heading, float target_angle)
                {
                    float angle = target_angle - heading;
                    if (angle > M_PI)
                    {
                        angle = angle - 2 * M_PI;
                    }
                    else if (angle < -M_PI)
                    {
                        angle = angle + 2 * M_PI;
                    }
                    return abs(angle);
                }

                /**
                 * @brief  计算车头调整与路径相同时的泊车车位
                 * @param  p 为当前车辆的位置
                 * @param  heading 为车辆航向角
                 * @param  target_angle 为目标航向
                 * @param  l 车位的横向偏移
                 * @param  bias 车位的纵向偏移
                 * @return athena::interface::ParkingInfo .
                 */
                athena::interface::ParkingInfo IncludedAngleParkingInfoCalculation(athena::interface::Point3D p, float heading, float target_angle, double l, double bias)
                {
                    // p为当前车辆的位置 ,heading为车辆航向角，target_angle为目标航向，给定车位位于target_angle与车辆位置决定的直线，可以通过l与bias进行调整位置
                    athena::interface::ParkingInfo target;                                                    // 目标车位
                    athena::common::ParkingType parking_type = athena::common::ParkingType::VERTICAL_PARKING; // 设定为垂直车位，需要头泊入
                    athena::common::ParkingStatus parking_status = athena::common::ParkingStatus::PARKING_ENABLE;
                    athena::common::Direction parking_direction_type = athena::common::Direction::UP;
                    athena::common::OccupiedStatus ocstatus = athena::common::OccupiedStatus::EMPTY; // 车位两侧设定为空
                    athena::interface::Point3D center_point, polygon_point;
                    athena::interface::Polygon3D polygon;
                    double lane_width = 40; // 泊车行道的宽度
                    float width = 30.0;     // 目标车位的宽度
                    float length = 30.0;    // 目标车位的长度

                    center_point.set_x(p.x() + l * cos(target_angle) + bias * cos(target_angle + 1.57078));
                    center_point.set_y(p.y() + l * sin(target_angle) + bias * sin(target_angle + 1.57078)); // 设定车位中心点
                    polygon_point.set_x(center_point.x() + cos(target_angle) * length / 2 + cos(target_angle - M_PI/2) * width / 2);
                    polygon_point.set_y(center_point.y() + sin(target_angle) * length / 2 + sin(target_angle - M_PI/2) * width / 2);
                    polygon.add_points(polygon_point);
                    polygon_point.set_x(center_point.x() + cos(target_angle) * length / 2 + cos(target_angle + M_PI/2) * width / 2);
                    polygon_point.set_y(center_point.y() + sin(target_angle) * length / 2 + sin(target_angle + M_PI/2) * width / 2);
                    polygon.add_points(polygon_point);
                    polygon_point.set_x(center_point.x() - cos(target_angle) * length / 2 + cos(target_angle + M_PI/2) * width / 2);
                    polygon_point.set_y(center_point.y() - sin(target_angle) * length / 2 + sin(target_angle + M_PI/2) * width / 2);
                    polygon.add_points(polygon_point);
                    polygon_point.set_x(center_point.x() - cos(target_angle) * length / 2 + cos(target_angle - M_PI/2) * width / 2);
                    polygon_point.set_y(center_point.y() - sin(target_angle) * length / 2 + sin(target_angle - M_PI/2) * width / 2);
                    polygon.add_points(polygon_point); // 设定目标车位的多边形
                    target.set_parking_type(parking_type);
                    target.set_parking_status(parking_status);
                    target.set_is_lane_width_valid(true);
                    target.set_lane_width(lane_width);
                    target.set_parking_space_id(1);
                    target.set_length(length);
                    target.set_width(width);
                    target.set_parking_direction_type(Direction::DIR_INVALID);
                    target.set_right_occupied_status(ocstatus);
                    target.set_left_occupied_status(ocstatus);
                    target.set_theta(target_angle);
                    target.set_polygon(polygon);
                    target.set_center_point_of_parking(center_point);
                    // 设定车位参数

                    return target;
                }

                /**
                 * @brief  计算躲避点
                 * @param  P1 为目标点1
                 * @param  P2 为目标点2
                 * @param  pose0 为车辆当前位置
                 * @param  heading 为车辆目前朝向
                 * @param  length 为路径点之间间隔
                 * @param  danger_range 为危险范围
                 * @param  wind_angle 为风的方向
                 * @param  l 为向外延伸的平行距离
                 * @return std::vector<athena::interface::Point3D> .
                 */
                std::vector<athena::interface::Point3D> DodgePointCalculation(athena::interface::Point3D P1, athena::interface::Point3D P2, athena::interface::Point3D pose_0,
                                                                              float heading, float length, float danger_range, float wind_angle, float l)
                {
                    // P1,P2为两个目标点，pose0为车辆当前位置，heading为车辆目前朝向，length为路径点之间间隔，danger_range为危险范围，wind_angle为风的方向,l为向外延伸的平行距离
                    std::vector<athena::interface::Point3D> path;
                    float angle_target;
                    float angle_p1_p2, k;
                    athena::interface::Point3D pose_0_saggingpoint, pose_midpoint;
                    if (P1.x() == P2.x())
                    { // 如果在两点x坐标相同
                        if (pose_0.x() - P1.x() > 0)
                        {
                            angle_target = 0;
                        }
                        else
                        {
                            angle_target = 3.1419126;
                        }
                    }
                    else
                    {
                        angle_p1_p2 = atan2((P1.y() - P2.y()), (P1.x() - P2.x()));
                        k = tan(angle_p1_p2);
                        pose_0_saggingpoint.set_x((pose_0.x() - k * (P1.y() - k * P1.x()) + k * pose_0.y()) / (1 + k * k));
                        pose_0_saggingpoint.set_y((k * pose_0.x() + k * k * pose_0.y() + (P1.y() - k * P1.x()) / (1 + k * k)));
                        // 计算车辆点到两目标点连线的垂点位置
                        angle_target = atan2((pose_0.y() - pose_0_saggingpoint.y()), (pose_0.x() - pose_0_saggingpoint.x()));
                    } // 计算撤离方向

                    float angle = angle_target - wind_angle;
                    if (angle > M_PI)
                    {
                        angle = angle - 2 * M_PI;
                    }
                    else if (angle < -M_PI)
                    {
                        angle = angle + 2 * M_PI;
                    } // 判断风向与目标航向的夹角
                    float angle_1 = angle_target;
                    if (abs(angle) < 1.57078)
                    {
                        angle_target = angle_target + M_PI;
                    } // 如果夹角过小则选择另一侧

                    pose_midpoint.set_x(pose_0.x());
                    pose_midpoint.set_y(pose_0.y());

                    if (angle_target >= 0)
                    { // 根据最终角度与当前航向角的关系设置路径
                        if ((heading >= angle_target) || (heading <= -angle_target))
                        {
                            if (heading < 0)
                            {
                                heading = heading + M_PI * 2;
                            }
                            for (float i = heading; i > angle_target; i = i - 0.05)
                            {
                                pose_midpoint.set_x(pose_midpoint.x() + length * cos(i));
                                pose_midpoint.set_y(pose_midpoint.y() + length * sin(i));
                                path.push_back(pose_midpoint);
                            }
                        }
                        else
                        {
                            for (float i = heading; i < angle_target; i = i + 0.05)
                            {
                                pose_midpoint.set_x(pose_midpoint.x() + length * cos(i));
                                pose_midpoint.set_y(pose_midpoint.y() + length * sin(i));
                                path.push_back(pose_midpoint);
                            }
                        }
                    }
                    else
                    {
                        if ((heading >= angle_target) && (heading <= -angle_target))
                        {
                            for (float i = heading; i > angle_target; i = i - 0.05)
                            {
                                pose_midpoint.set_x(pose_midpoint.x() + length * cos(i));
                                pose_midpoint.set_y(pose_midpoint.y() + length * sin(i));
                                path.push_back(pose_midpoint);
                            }
                        }
                        else
                        {
                            if (heading > 0)
                            {
                                heading = heading - M_PI * 2;
                            }
                            for (float i = heading; i < angle_target; i = i + 0.05)
                            {
                                pose_midpoint.set_x(pose_midpoint.x() + length * cos(i));
                                pose_midpoint.set_y(pose_midpoint.y() + length * sin(i));
                                path.push_back(pose_midpoint);
                            }
                        }
                    }
                    double m = std::abs(k * pose_midpoint.x() - pose_midpoint.y() + P1.y() - k * P1.x()) / std::sqrt(k * k + 1);
                    if (angle_1 == angle_target)
                    {
                        double l = danger_range + l - m;
                    }
                    else
                    {
                        double l = danger_range + l + m;
                    }
                    // 计算此时距离P1P2连线的距离
                    // 计算需要撤离行进的距离
                    for (float i = 0; i <= l; i = i + length)
                    {
                        pose_midpoint.set_x(pose_midpoint.x() + i * cos(angle_target));
                        pose_midpoint.set_y(pose_midpoint.y() + i * sin(angle_target));
                        path.push_back(pose_midpoint);
                    }
                    return path;
                }

                /**
                 * @brief  计算躲避点与靠近点
                 * @param  P1 为目标点1
                 * @param  P2 为目标点2
                 * @param  pose0 为车辆当前位置
                 * @param  radius 为危险范围
                 * @param  close_radius 为靠近半径
                 * @return std::vector<athena::common::math::Vec2d> .
                 */
                std::vector<athena::common::math::Vec2d> dodge_approach(athena::interface::Point3D P1, athena::interface::Point3D P2, athena::interface::Point3D pose_0,
                                                                        float radius, float close_radius)
                {
                    // 返回原胶囊形状，撤离点和接近点
                    //  P1,P2为两个目标点，pose0为车辆当前位置，close_radius为靠近半径，radius为危险范围
                    std::vector<athena::common::math::Vec2d> return_points; // 定义返回内容，1-4为胶囊，5为撤离点，6为接近点
                    athena::common::math::Vec2d midpoint;
                    float angle_target, angle_p1_p2;
                    athena::interface::Point3D pose_0_saggingpoint;
                    if (P1.x() == P2.x())
                    { // 如果在两点x坐标相同
                        if (pose_0.x() - P1.x() > 0)
                        {
                            angle_target = 0;
                        }
                        else
                        {
                            angle_target = 3.1419126;
                        }
                    }
                    else
                    {
                        angle_p1_p2 = atan2((P1.y() - P2.y()), (P1.x() - P2.x()));
                        float k = tan(angle_p1_p2);
                        pose_0_saggingpoint.set_x((pose_0.x() - k * (P1.y() - k * P1.x()) + k * pose_0.y()) / (1 + k * k));
                        pose_0_saggingpoint.set_y((k * pose_0.x() + k * k * pose_0.y() + (P1.y() - k * P1.x())) / (1 + k * k));
                        // 计算车辆点到两目标点连线的垂点位置
                        angle_target = atan2((pose_0.y() - pose_0_saggingpoint.y()), (pose_0.x() - pose_0_saggingpoint.x()));
                    } // 计算撤离方向
                    midpoint.set_x(P1.x() + radius * cos(angle_p1_p2) + radius * cos(angle_target));
                    midpoint.set_y(P1.y() + radius * sin(angle_p1_p2) + radius * sin(angle_target));
                    return_points.push_back(midpoint);
                    midpoint.set_x(P1.x() + radius * cos(angle_p1_p2) - radius * cos(angle_target));
                    midpoint.set_y(P1.y() + radius * sin(angle_p1_p2) - radius * sin(angle_target));
                    return_points.push_back(midpoint);
                    midpoint.set_x(P2.x() - radius * cos(angle_p1_p2) - radius * cos(angle_target));
                    midpoint.set_y(P2.y() - radius * sin(angle_p1_p2) - radius * sin(angle_target));
                    return_points.push_back(midpoint);
                    midpoint.set_x(P2.x() - radius * cos(angle_p1_p2) + radius * cos(angle_target));
                    midpoint.set_y(P2.y() - radius * sin(angle_p1_p2) + radius * sin(angle_target));
                    return_points.push_back(midpoint);
                    midpoint.set_x(pose_0_saggingpoint.x() + radius * cos(angle_target));
                    midpoint.set_y(pose_0_saggingpoint.y() + radius * sin(angle_target));
                    return_points.push_back(midpoint);

                    float angle_1 = atan2((midpoint.y() - P1.y() - radius * sin(angle_target)),
                                          (midpoint.x() - P1.x() - radius * cos(angle_target)));
                    double m = std::sqrt(abs(close_radius * close_radius - radius * radius));
                    midpoint.set_x(P1.x() + radius * cos(angle_target) + m * cos(angle_1));
                    midpoint.set_y(P1.y() + radius * sin(angle_target) + m * sin(angle_1));
                    return_points.push_back(midpoint);
                    return return_points;
                }

                /**
                 * @brief  计算测控车躲避
                 * @param  P1 为目标点1
                 * @param  P2 为目标点2
                 * @param  pose0 为车辆当前位置
                 * @param  length 为撤退范围
                 * @param  radius 为危险范围
                 * @param  wind_angle 为风的方向
                 * @return std::vector<athena::common::math::Vec2d> .
                 */
                std::vector<athena::common::math::Vec2d> ckc_dodge(athena::interface::Point3D P1, athena::interface::Point3D P2, athena::interface::Point3D pose_0, float radius)
                {
                    // 返回扩大胶囊形状，撤离点
                    //  P1,P2为两个目标点，pose0为车辆当前位置，length为撤退范围，radius为危险范围，wind_angle为风的方向
                    std::vector<athena::common::math::Vec2d> return_points; // 定义返回内容，1-4为胶囊，5为撤离点
                    athena::interface::Point3D pose_0_saggingpoint;
                    athena::common::math::Vec2d midpoint;
                    float angle_target, angle_p1_p2;
                    if (P1.x() == P2.x())
                    { // 如果在两点x坐标相同
                        if (pose_0.x() - P1.x() > 0)
                        {
                            angle_target = 0;
                        }
                        else
                        {
                            angle_target = M_PI;
                        }
                    }
                    else
                    {
                        angle_p1_p2 = atan2((P1.y() - P2.y()), (P1.x() - P2.x()));
                        float k = tan(angle_p1_p2);
                        pose_0_saggingpoint.set_x((pose_0.x() - k * (P1.y() - k * P1.x()) + k * pose_0.y()) / (1 + k * k));
                        pose_0_saggingpoint.set_y((k * pose_0.x() + k * k * pose_0.y() + (P1.y() - k * P1.x())) / (1 + k * k));
                        // 计算车辆点到两目标点连线的垂点位置
                        angle_target = atan2((pose_0.y() - pose_0_saggingpoint.y()), (pose_0.x() - pose_0_saggingpoint.x()));
                    } // 计算撤离方向
                    midpoint.set_x(P1.x() + radius * cos(angle_p1_p2) + radius * cos(angle_target));
                    midpoint.set_y(P1.y() + radius * sin(angle_p1_p2) + radius * sin(angle_target));
                    return_points.push_back(midpoint);
                    midpoint.set_x(P1.x() + radius * cos(angle_p1_p2) - radius * cos(angle_target));
                    midpoint.set_y(P1.y() + radius * sin(angle_p1_p2) - radius * sin(angle_target));
                    return_points.push_back(midpoint);
                    midpoint.set_x(P2.x() - radius * cos(angle_p1_p2) - radius * cos(angle_target));
                    midpoint.set_y(P2.y() - radius * sin(angle_p1_p2) - radius * sin(angle_target));
                    return_points.push_back(midpoint);
                    midpoint.set_x(P2.x() - radius * cos(angle_p1_p2) + radius * cos(angle_target));
                    midpoint.set_y(P2.y() - radius * sin(angle_p1_p2) + radius * sin(angle_target));
                    return_points.push_back(midpoint);
                    midpoint.set_x(pose_0_saggingpoint.x() + radius * cos(angle_target));
                    midpoint.set_y(pose_0_saggingpoint.y() + radius * sin(angle_target));
                    return_points.push_back(midpoint);

                    return return_points;
                }

                /**
                 * @brief  计算目标搜索路径
                 * @param  target 为目标点位置
                 * @param  pose 为车辆当前位置
                 * @param  r_d1 为小圆半径
                 * @param  r_d2 为大圆半径
                 * @return std::vector<athena::interface::Point3D> .
                 */
                std::vector<athena::interface::Point3D> TargetSearchPointCalculation(athena::interface::Point3D target, athena::interface::Point3D pose, double r_d1, double r_d2)
                {
                    // target为目标点位置，pose为车辆当前位置，r_d1,r_d2为小圆与大圆的半径
                    std::vector<athena::interface::Point3D> points;
                    athena::interface::Point3D pose_midpoint;
                    float angle_target_pose = atan2((pose.y() - target.y()), (pose.x() - target.x()));
                    pose_midpoint.set_x(target.x() + r_d1 * cos(angle_target_pose));
                    pose_midpoint.set_y(target.y() + r_d1 * sin(angle_target_pose));
                    points.push_back(pose_midpoint);
                    pose_midpoint.set_x(target.x() + r_d2 * cos(angle_target_pose + M_PI / 2));
                    pose_midpoint.set_y(target.y() + r_d2 * sin(angle_target_pose + M_PI / 2));
                    points.push_back(pose_midpoint);
                    pose_midpoint.set_x(target.x() - r_d2 * cos(angle_target_pose));
                    pose_midpoint.set_y(target.y() - r_d2 * sin(angle_target_pose));
                    points.push_back(pose_midpoint);
                    pose_midpoint.set_x(target.x() + r_d2 * cos(angle_target_pose - M_PI / 2));
                    pose_midpoint.set_y(target.y() + r_d2 * sin(angle_target_pose - M_PI / 2));
                    points.push_back(pose_midpoint);
                    return points;
                }

                /**
                 * @brief  车在圆内，沿车头方向与圆的交点坐标位置
                 * @param  p 为圆心位置
                 * @param  pose_0 为车辆当前位置
                 * @param  heading 为车辆航向角
                 * @param  radius 为圆半径
                 * @return athena::interface::Point3D .
                 */
                athena::interface::Point3D CircleInsideIntersection(athena::interface::Point3D p, athena::interface::Point3D pose_0, float heading, double radius)
                {
                    // 车在圆内，沿车头方向与圆的交点坐标位置
                    // p为圆心位置，pose_0为车辆当前位置 ，heading为车辆航向角，radius为圆半径
                    float dif_angle = atan2((p.y() - pose_0.y()), (p.x() - pose_0.x()));
                    if (dif_angle > M_PI)
                    {
                        dif_angle = dif_angle - M_PI * 2;
                    }
                    else if (dif_angle < -M_PI)
                    {
                        dif_angle = dif_angle + M_PI * 2;
                    } // 计算航向角相对于圆心车辆位置连线的角度差值
                    double m = std::sqrt((p.y() - pose_0.y()) * (p.y() - pose_0.y()) + (p.x() - pose_0.x()) * (p.x() - pose_0.x()));
                    double l = std::sqrt(radius * radius - (m * sin(dif_angle)) * (m * sin(dif_angle)));
                    // l为车辆以及其航向所在直线 规定的弦的一半长度
                    double n = l + cos(dif_angle) * m; // n为车辆所在点延长到直线的距离
                    athena::interface::Point3D pose_1;
                    pose_1.set_x(pose_0.x() + cos(heading) * n);
                    pose_1.set_y(pose_0.y() + sin(heading) * n);
                    return pose_1;
                }

                athena::interface::RoutingResponse extend_responese(athena::interface::RoutingResponse routing, float length, int n)
                {
                    // 返回车辆航向延长线上的n个点
                    //  rounting为发送的路径，length为路径点之间的间隔，n为路径点总数
                    athena::interface::RoutingResponse RoutingResponse;
                    std::vector<athena::interface::LanePoint> lane_points;
                    athena::interface::LaneInfo laneInfo;
                    std::vector<athena::interface::LaneInfo> lane_list;
                    athena::interface::Point3D midpoint, P;
                    lane_points = routing.lane_list()[0].lane_points();
                    float heading = routing.lane_list()[0].lane_points().back().theta();
                    P.CopyFrom(routing.lane_list()[0].lane_points().back().point());
                    for (int i = 1; i <= n; i++)
                    {
                        athena::interface::LanePoint extend_point;
                        midpoint.set_x(P.x() + length * cos(heading) * i);
                        midpoint.set_y(P.y() + length * sin(heading) * i);
                        extend_point.set_point(midpoint);
                        extend_point.set_theta(heading);
                        lane_points.push_back(extend_point);
                    }
                    laneInfo.set_lane_points(lane_points);
                    lane_list.push_back(laneInfo);
                    RoutingResponse.set_lane_list(lane_list);
                    return RoutingResponse;
                }

                athena::interface::RoutingResponse extend_responese_reverse(athena::interface::RoutingResponse routing, float length, int n)
                {
                    // 返回车辆航向延长线上的n个点
                    //  rounting为发送的路径，length为路径点之间的间隔，n为路径点总数
                    athena::interface::RoutingResponse RoutingResponse;
                    std::vector<athena::interface::LanePoint> lane_points;
                    std::vector<athena::interface::LanePoint> new_lane_points;
                    athena::interface::LaneInfo laneInfo;
                    std::vector<athena::interface::LaneInfo> lane_list;
                    athena::interface::Point3D midpoint, P;
                    lane_points = routing.lane_list()[0].lane_points();
                    float heading = routing.lane_list()[0].lane_points().front().theta() + M_PI;
                    if (heading > M_PI)
                    {
                        heading = heading - 2 * M_PI;
                    }
                    P.CopyFrom(routing.lane_list()[0].lane_points().front().point());
                    for (int i = n; i >= 0; i--)
                    {
                        athena::interface::LanePoint extend_point;
                        midpoint.set_x(P.x() + length * cos(heading) * i);
                        midpoint.set_y(P.y() + length * sin(heading) * i);
                        extend_point.set_point(midpoint);
                        new_lane_points.push_back(extend_point);
                    }
                    for (auto point : lane_points)
                    {
                        new_lane_points.push_back(point);
                    }
                    laneInfo.set_lane_points(new_lane_points);
                    lane_list.push_back(laneInfo);
                    RoutingResponse.set_lane_list(lane_list);
                    return RoutingResponse;
                }

                std::vector<athena::interface::Point3D> find_nearnest_farthest_point(std::vector<athena::interface::Point3D> points, athena::interface::Point3D pose)
                {
                    // 绕行开始时 降落伞在圆周上 此时需要计算降落伞与圆周的交点最近点与最远 最远点作为行车终点
                    //  返回距离车辆位置最近和最远的点
                    //   points为输入的点，pose为车辆当前位置，返回的第一个点为最近的点，第二个为最远的点
                    std::vector<athena::interface::Point3D> return_points;
                    int min_i, max_i;
                    double min_d, max_d;
                    for (int i = 0; i < points.size(); i++)
                    {
                        double m = std::sqrt((points[i].x() - pose.x()) * (points[i].x() - pose.x()) + (points[i].y() - pose.y()) * (points[i].y() - pose.y()));
                        if (i == 0)
                        {
                            max_i = i;
                            min_i = i;
                            max_d = m;
                            min_d = m;
                        }
                        if (m > max_d)
                        {
                            max_i = i;
                            max_d = m;
                        }
                        if (m < min_d)
                        {
                            min_i = i;
                            min_d = m;
                        }
                    }
                    athena::interface::Point3D p;
                    p.set_x(points[min_i].x());
                    p.set_y(points[min_i].y());
                    return_points.push_back(p);
                    p.set_x(points[max_i].x());
                    p.set_y(points[max_i].y());
                    return_points.push_back(p);
                    return return_points;
                }

                float stopinfo_heading(athena::interface::RoutingResponse rounting, athena::interface::Point3D p)
                {
                    // 绕行规划时 绕行终点为降落伞与圆周交点 此时只知道stopinfo位置不知道方向 需要routingresponse上找到最近点的方向作为行车终点方向
                    //  输入RoutingResponse和点位返回heading
                    //   p为输入的点位，返回的是RoutingResponse中距离点位最近点的heading
                    double min_d;
                    int min_i;
                    for (int i = 0; i < rounting.lane_list()[0].lane_points().size(); i++)
                    {
                        double m = std::sqrt((rounting.lane_list()[0].lane_points()[i].point().x() - p.x()) * (rounting.lane_list()[0].lane_points()[i].point().x() - p.x()) + (rounting.lane_list()[0].lane_points()[i].point().y() - p.y()) * (rounting.lane_list()[0].lane_points()[i].point().y() - p.y()));
                        if (i == 0)
                        {
                            min_d = m;
                            min_d = i;
                        }
                        if (m < min_d)
                        {
                            min_d = m;
                            min_i = i;
                        }
                    }
                    float heading = atan2(p.x() - rounting.lane_list()[0].lane_points()[min_i].point().x(),
                                          p.y() - rounting.lane_list()[0].lane_points()[min_i].point().y());
                    return heading;
                }

                //
                athena::interface::ParkingInfo air_port_parkinginfo(athena::interface::Point3D target, std::vector<athena::interface::Point3D> polygon, float wind_angle, double radius, float bias)
                {
                    // 返回风向与圆的交点产生的车位并且避开障碍物
                    //  target为目标点的位置，radius为目标车位中心所在的半径，wind_angle为风向，polygon为可能与圆有交点的障碍多边形,bias为车位位置在圆上的偏移量(单位为弧度)
                    //  假设降落伞遮盖目标圆的部分弧度值小于M_PI
                    athena::interface::Point3D p;
                    athena::interface::ParkingInfo parking;
                    p.set_x(target.x() + cos(wind_angle) * radius);
                    p.set_y(target.y() + sin(wind_angle) * radius);
                    std::vector<athena::interface::Point3D> points;
                    points = PolygonAndCircleIntersection(target, polygon, radius);
                    int size = points.size();
                    float heading = wind_angle + M_PI / 2;
                    if (size == 0)
                    {
                        heading = wind_angle + M_PI / 2;
                    }
                    else
                    {
                        float max_angle = 0;
                        int m = 0, n = 0;
                        for (int i = 0; i < size - 1; i++)
                        {
                            for (int j = i + 1; j < size; j++)
                            {
                                float angle_1 = atan2(polygon[i].y() - p.y(), polygon[i].x() - p.x());
                                float angle_2 = atan2(polygon[j].y() - p.y(), polygon[j].x() - p.x());
                                float dif_angle = IncludedAngleCalculation(angle_1, angle_2);
                                if (dif_angle > max_angle)
                                {
                                    max_angle = dif_angle;
                                    m = i;
                                    n = j;
                                }
                            }
                        }
                        if (max_angle > M_PI / 2)
                        {
                            float angle_p;
                            double length_m = sqrt(pow(polygon[m].y() - p.y(), 2) + pow(polygon[m].x() - p.x(), 2));
                            double length_n = sqrt(pow(polygon[n].y() - p.y(), 2) + pow(polygon[n].x() - p.x(), 2));
                            if (length_m > length_n)
                            {
                                angle_p = atan2(polygon[n].y() - p.y(), polygon[n].x() - p.x());
                                p.CopyFrom(polygon[n]);
                            }
                            else
                            {
                                angle_p = atan2(polygon[m].y() - p.y(), polygon[m].x() - p.x());
                                p.CopyFrom(polygon[m]);
                            }
                            float heading_1 = wind_angle + M_PI / 2;
                            if (heading_1 > M_PI)
                            {
                                heading_1 = heading_1 - M_PI * 2;
                            }
                            if (IncludedAngleCalculation(heading_1, angle_p) > M_PI / 2)
                            {
                                heading = wind_angle - M_PI / 2;
                                if (heading_1 < -M_PI)
                                {
                                    heading = heading + M_PI * 2;
                                }
                            }
                            else
                            {
                                heading = heading_1;
                            }
                        }
                    }
                    float angle_end = atan2(p.y() - target.y(), p.x() - target.x());
                    p.set_x(target.x() + cos(angle_end + bias) * radius);
                    p.set_y(target.y() + sin(angle_end + bias) * radius);
                    return IncludedAngleParkingInfoCalculation(p, 0, heading, 0, 0);
                }
                std::vector<athena::interface::Point3D> Response(double radius, double length, float heading, float target, athena::interface::Point3D P0)
                {
                    //  radius为转圈圆半径，length为步长，heading为车辆目前航向角，target为目标航向角，P0为车辆当前位置
                    float angle = target - heading;
                    if (angle > M_PI)
                    {
                        angle = angle - 2 * M_PI;
                    }
                    else if (angle < -M_PI)
                    {
                        angle = angle + 2 * M_PI;
                    }
                    float m;
                    if (angle >= 0)
                    {
                        m = 1;
                    }
                    else
                    {
                        m = -1;
                    }
                    athena::interface::Point3D center;
                    center.set_x(P0.x() + radius * cos(heading + M_PI / 2) * m);
                    center.set_y(P0.y() + radius * sin(heading + M_PI / 2) * m);
                    std::vector<athena::interface::Point3D> path;
                    athena::interface::Point3D midpoint;
                    float angle_1 = heading - M_PI / 2 * m;
                    for (float i = 0; i <= M_PI + 0.3; i = i + length / radius)
                    {
                        midpoint.set_x(center.x() + radius * cos(angle_1 + i * m));
                        midpoint.set_y(center.y() + radius * sin(angle_1 + i * m));
                        path.push_back(midpoint);
                    }
                    return path;
                }
            };
        }
    }
}
