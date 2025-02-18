#ifndef COSMTAP_GENEARTOR_
#define COSMTAP_GENEARTOR_

// #include <tf2/utils.h>
#include <cmath>
#include <functional>
// #include <geometry_msgs/msg/pose.hpp>
// #include <geometry_msgs/msg/pose_array.hpp>
#include <iostream>
// #include <nav_msgs/msg/occupancy_grid.hpp>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

#include "costmap.h"
#include "inflation.h"
#include "modules/common/interface/obstacle_list.hpp"

namespace athena
{
  namespace common
  {

    class CostmapGenerator
    {
    public:
      CostmapGenerator() {}
      ~CostmapGenerator() {}
      std::shared_ptr<Costmap> getCostmapFromObjects(
          const athena::interface::ObstacleList &obstacle_list);
      static CostmapGenerator &Instance()
      {
        static CostmapGenerator instance;
        return instance;
      }
      void Init();
      void setOrigin(double x, double y);

    protected:
    private:
      void markCostmapFromObjects(const athena::interface::ObstacleList &obstacle_list);
      // params
      double size_x_;
      double size_y_;
      int size_cell_x_;
      int size_cell_y_;
      double resolution_;
      double origin_x_;
      double origin_y_;
      std::string frame_id_;
      // inflation
      double inflation_radius_; // 外接圆
      double inscribed_radius_; // 内接圆
      double local_weight_;

      std::shared_ptr<Costmap> costmap_{nullptr};
      std::shared_ptr<Inflation> inflation_{NULL};
    };

  } // namespace common
} // namespace athena
#endif
