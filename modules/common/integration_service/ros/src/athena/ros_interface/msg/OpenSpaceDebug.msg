float64   lat_error     # 横向误差
float64   lon_error     # 纵向误差
float64   yaw_error     # 角度误差(度)
float64   pos_error     # 位置误差
Trajectory   warm_start_path     # 粗轨迹
Trajectory   smoothed_path     # 平滑轨迹
Polygon2D[] obstacle_list # 动态障碍物
Point2dList[] obstacles_vec # 静态障碍物
Polygon2D[] vehicle_preiew_polygon # 车辆预测多边形
