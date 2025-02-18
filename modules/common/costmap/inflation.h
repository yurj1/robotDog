#ifndef INCLUDE_COSTMAP_INFLATION_H_
#define INCLUDE_COSTMAP_INFLATION_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <algorithm>
#include <queue>
#include <memory>
#include "costmap.h"

namespace athena
{
  namespace common
  {
    class Cell
    {
    public:
      Cell(double d, double i, int x, int y, int sx, int sy)
          : distance_(d), index_(i), x_(x), y_(y), src_x_(sx), src_y_(sy) {}
      double distance_;
      int index_;
      int x_, y_;
      int src_x_, src_y_;
    };

    inline bool operator<(const Cell &a, const Cell &b) { return a.distance_ > b.distance_; }

    class InflationCaculateDistance
    {
    public:
      InflationCaculateDistance(double inscribed_radius, double resolution);
      ~InflationCaculateDistance();

    private:
      inline double distanceLookup(int mx, int my, int src_x, int src_y)
      {
        int dx = abs(mx - src_x);
        int dy = abs(my - src_y);
        if (!cached_distances_)
        {
          if (!dx && !dy)
          {
            return 0;
          }
          else
          {
            return std::numeric_limits<double>::max();
          }
        }
        return cached_distances_[dx][dy];
      }

      inline void enqueue(unsigned char *grid, int index, int mx, int my, int src_x, int src_y);

      void computeCaches();
      void deleteKernels();

      // void ResetCachedMap(const Costmap* map);

      double inflation_radius_, resolution_;
      int cell_inflation_radius_;

      unsigned char *global_cached_distances_{nullptr};
      double **cached_distances_{nullptr};
      int16_t *level_grid_{nullptr};
      std::priority_queue<Cell> inflation_queue_;
      int size_x_;
      int size_y_;
      //   CaculateGridLevel* caculate_grid_level_{nullptr};
    };

    struct InflationPoint
    {
      InflationPoint(int i, int j, int idx, unsigned char cost) : i(i), j(j), index(idx), cost(cost) {}
      int i;
      int j;
      int index;
      unsigned char cost;
    };

    class Inflation
    {
    public:
      Inflation(double inflation_radius, double inscribed_radius, double weight, double resolution);
      Inflation(double inflation_radius, double inscribed_radius, double weight,
                const std::shared_ptr<Costmap> &pMap, int x0, int x1, int y0, int y1);
      void Init();
      ~Inflation();
      // void updateCosts(const Costmap *map, int min_i, int max_i, int min_j, int max_j);
      void UpdateCosts(std::shared_ptr<Costmap> &master_grid, const UpdateRange &range);
      // void updateCosts(unsigned char *grid, int grid_size_x, int grid_size_y,
      //                  int min_i, int max_i, int min_j, int max_j);
      inline unsigned char computeCost(double distance, const unsigned char &lethal_cost,
                                       const unsigned char &inflated_cost) const
      {
        unsigned char cost = 0;
        if (distance == 0)
        {
          cost = lethal_cost;
        }
        else if (distance * resolution_ <= inscribed_radius_)
        {
          cost = inflated_cost;
        }
        else
        {
          // cost = FREE_SPACE;
          double euclidean_distance = distance * resolution_;
          double factor = exp(-1.0 * weight_ * (euclidean_distance - inscribed_radius_));
          cost = (unsigned char)((inflated_cost - 1) * factor);
        }
        return cost;
      }

      void updateInscribeRadius(double radius)
      {
        inscribed_radius_ = radius;
        updateCachedCosts();
      }

    private:
      inline double distanceLookup(int mx, int my, int src_x, int src_y)
      {
        int dx = abs(mx - src_x);
        int dy = abs(my - src_y);
        return cached_distances_[dx][dy];
      }

      inline unsigned char costLookup(int mx, int my, int src_x, int src_y, bool is_static)
      {
        int dx = abs(mx - src_x);
        int dy = abs(my - src_y);
        return is_static ? static_cached_costs_[dx][dy] : dynamic_cached_costs_[dx][dy];
      }

      void enqueue(unsigned char *grid, int index, int mx, int my, int src_x, int src_y,
                   bool is_static);

      void computeCaches();
      void deleteKernels();

      void updateCachedCosts();
      void ResetCaches(double inflation_radius);

    private:
      double inflation_radius_, inscribed_radius_, weight_, resolution_;
      int cell_inflation_radius_;
      double max_inflation_radius_;
      unsigned int cached_cell_inflation_radius_;
      double **cached_distances_;
      unsigned char **static_cached_costs_;
      unsigned char **dynamic_cached_costs_;

      // int16_t* level_grid_{NULL};
      // int level_grid_size_;
      std::priority_queue<Cell> inflation_queue_;
      // InflationCaculateDistance* inflation_caculate_distance_{NULL};
      // InflationCaculateDistance* virtual_caculate_distance_{NULL};

      // CaculateGridLevel* caculate_grid_level_{NULL};

      int size_x_{0};
      int size_y_{0};
      int size_z_{0};

      int x0_;
      int x1_;
      int y0_;
      int y1_;
      int level_grid_size_x_;
      int level_grid_size_y_;
      int level_grid_origin_x_;
      int level_grid_origin_y_;
      unsigned char *grid_{NULL};
      std::vector<bool> seen_;
      int seen_size_;
    };
  } // namespace common
} // namespace athena

#endif // INCLUDE_COSTMAP_2D_INFLATION_H_
