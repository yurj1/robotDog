#include "costmap_generator.h"

namespace athena
{
  namespace common
  {
    void CostmapGenerator::Init()
    {
      size_cell_x_ = 400;
      size_cell_y_ = 400;
      resolution_ = 0.1;
      origin_x_ = 0; // -0.5*size_x_;
      origin_y_ = 0; // -0.5*size_y_;
      frame_id_ = "map";
      costmap_ =
          std::make_shared<Costmap>(size_cell_x_, size_cell_y_, resolution_, origin_x_, origin_y_);
      costmap_->setGlobalFrameID(frame_id_);

      inflation_radius_ = 2.5;
      inscribed_radius_ = 1.8;
      local_weight_ = 5.0;
      inflation_ =
          std::make_shared<Inflation>(inflation_radius_, inscribed_radius_, local_weight_, resolution_);
      // inflation_->Init();
    }

    std::shared_ptr<Costmap> CostmapGenerator::getCostmapFromObjects(
        const athena::interface::ObstacleList &obstacle_list)
    {
      // 释放上一帧costmap内存
      costmap_->clearCharmap();
      // 标记障碍物
      markCostmapFromObjects(obstacle_list);
      // 膨胀
      inflation_->UpdateCosts(costmap_, {0, 0, size_cell_x_, size_cell_y_});
      return costmap_;
    }

    void CostmapGenerator::markCostmapFromObjects(
        const athena::interface::ObstacleList &obstacle_list)
    {
      // std::vector<athena::interface::Obstacle> ob_vector;
      // obstacle_list.obstacle(ob_vector);
      // polygon的边等间距的插补并标记到costmap
      double resolution = costmap_->getResolution();
      for (const auto &object : obstacle_list.obstacle())
      {
        std::vector<athena::interface::Point3D> polygon;
        object.polygon_point_abs(polygon);
        // object.polygon_point_vehicle(polygon);
        unsigned char lethal_cost;
        // 通过障碍物速度判断静态\动态
        if (object.velocity_abs().x() == 0.0 || object.velocity_abs().y() == 0.0)
        {
          lethal_cost = STATIC_OBSTACLE;
        }
        else
        {
          lethal_cost = DYNAMIC_OBSTACLE;
        }

        for (size_t i = 0; i < polygon.size(); i++)
        {
          athena::interface::Point3D start = polygon.at(i);
          athena::interface::Point3D end;
          // polygon的尾部衔接到头部
          if (i == polygon.size() - 1)
            end = polygon.front();
          else
            end = polygon.at(i + 1);

          // 填充障碍物内部
          int num = hypot(start.x() - end.x(), start.y() - end.y()) / resolution;
          for (int n = 0; n < num; n++)
          {
            double theta = atan2(end.y() - start.y(), end.x() - start.x());
            double x = start.x() + n * resolution * cos(theta);
            double y = start.y() + n * resolution * sin(theta);
            int mx, my;
            //  实际世界坐标转换为costmap中栅格坐标
            if (costmap_->worldToMap(x, y, mx, my))
            {
              // printf("x,y(%f,%f),mx,my(%d,%d)\n",x,y,mx,my);
              costmap_->setCost(mx, my, lethal_cost); // 感知结果标记
            }
          }
        }
      }
    }

    void CostmapGenerator::setOrigin(double x, double y)
    {
      costmap_->setOriginX(x);
      costmap_->setOriginY(y);
    };
  } // namespace common
} // namespace athena
