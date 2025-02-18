#include "inflation.h"
// #include <ros/ros.h>
#include <algorithm>
namespace athena
{
  namespace common
  {

    Inflation::Inflation(double inflation_radius, double inscribed_radius, double weight,
                         double resolution)
        : inflation_radius_(inflation_radius),
          inscribed_radius_(inscribed_radius),
          weight_(weight),
          resolution_(resolution),
          max_inflation_radius_(inflation_radius)
    {
      // 单元格膨胀半径
      cell_inflation_radius_ = ceil(inflation_radius_ / resolution_);
      // 构建膨胀矩阵
      computeCaches();

      seen_size_ = 0;
    }

    Inflation::Inflation(double inflation_radius, double inscribed_radius, double weight,
                         const std::shared_ptr<Costmap> &pMap, int x0, int x1, int y0, int y1)
        : inflation_radius_(inflation_radius),
          inscribed_radius_(inscribed_radius),
          weight_(weight),
          max_inflation_radius_(inflation_radius),
          x0_(x0),
          x1_(x1),
          y0_(y0),
          y1_(y1)
    {
      resolution_ = pMap->getResolution();
      cell_inflation_radius_ = ceil(inflation_radius_ / resolution_);
      grid_ = pMap->getCharMap();
      size_x_ = pMap->getSizeInCellsX();
      size_y_ = pMap->getSizeInCellsY();
    }

    void Inflation::Init() { computeCaches(); }

    Inflation::~Inflation() { deleteKernels(); }

    void Inflation::deleteKernels()
    {
      if (cached_distances_ != NULL)
      {
        for (int i = 0; i <= cell_inflation_radius_ + 1; ++i)
        {
          if (cached_distances_[i])
            delete[] cached_distances_[i];
        }
        if (cached_distances_)
          delete[] cached_distances_;
        cached_distances_ = NULL;
      }

      if (static_cached_costs_ != NULL)
      {
        for (int i = 0; i <= cell_inflation_radius_ + 1; ++i)
        {
          if (static_cached_costs_[i])
            delete[] static_cached_costs_[i];
        }
        delete[] static_cached_costs_;
        static_cached_costs_ = NULL;

        if (dynamic_cached_costs_ != NULL)
        {
          for (int i = 0; i <= cell_inflation_radius_ + 1; ++i)
          {
            if (dynamic_cached_costs_[i])
              delete[] dynamic_cached_costs_[i];
          }
          delete[] dynamic_cached_costs_;
          dynamic_cached_costs_ = NULL;
        }
      }
    }
    // 通过调用distanceLookup函数，在参考矩阵cached_distances_上，找到当前cell
    //  cost，当距离在阈值内，将当前cell加入到inflation_queue_
    void Inflation::enqueue(unsigned char *grid, int index, int mx, int my, int src_x, int src_y,
                            bool is_static)
    {
      // 如果已经访问过，跳过
      if (seen_[index])
      {
        return;
      }
      double lethal_cost = is_static ? STATIC_OBSTACLE : DYNAMIC_OBSTACLE;
      double inflated_cost = is_static ? STATIC_INFLATED_OBSTACLE : DYNAMIC_INFLATED_OBSTACLE;
      // 标记
      seen_[index] = true;
      int origin_index = src_y * size_x_ + src_x;
      unsigned char origin_cost = grid[origin_index];
      unsigned char decrease_cost = lethal_cost - origin_cost;
      double distance;
      unsigned char cost;

      distance = distanceLookup(mx, my, src_x, src_y);
      if (distance > cell_inflation_radius_)
      {
        return;
      }
      cost = costLookup(mx, my, src_x, src_y, is_static);

      unsigned char old_cost = grid[index];
      if (cost > decrease_cost)
        cost -= decrease_cost;
      else
        return;
      // 只有 254、253、252、251 可以进入 NO_INFORMATION
      if (old_cost == NO_INFORMATION && cost >= inflated_cost)
        grid[index] = cost;
      else
        grid[index] = std::max(old_cost, cost);

      // push the cell data onto the queue and mark
      // int16_t level = levelLookup(mx, my, src_x, src_y);
      // if (level_grid_[level_grid_index] > level)
      // {
      Cell data(distance, index, mx, my, src_x, src_y);
      inflation_queue_.push(data);
      // level_grid_[level_grid_index] = level;
      // }
    }

    void Inflation::UpdateCosts(std::shared_ptr<Costmap> &master_grid, const UpdateRange &range)
    {
      unsigned char *master_array = master_grid->getCharMap();
      int size_x = master_grid->getSizeInCellsX();
      int size_y = master_grid->getSizeInCellsY();

      size_x_ = size_x;
      size_y_ = size_y;
      int temp_cell_inflation_radius = cell_inflation_radius_; // 以格子为单位
      std::vector<InflationPoint> map_points;
      int min_i = range.x0_; // 0
      int max_i = range.xn_; // local_cells_size_x_
      int min_j = range.y0_; // 0
      int max_j = range.yn_; // local_cells_size_y_
      int left = range.x0_;
      int right = range.xn_;
      int down = range.y0_;
      int top = range.yn_;

      min_i = std::max(0, min_i - temp_cell_inflation_radius);
      min_j = std::max(0, min_j - temp_cell_inflation_radius);
      max_i = std::min(size_x, max_i + temp_cell_inflation_radius);
      max_j = std::min(size_y, max_j + temp_cell_inflation_radius);

      // 最大值不能小于最小值
      if (max_i <= min_i || max_j <= min_j)
        return;
      // std::vector<bool> seen_;
      seen_.clear();
      seen_.resize(size_x * size_y, false);

      // 把master costmap障碍物的点添加到膨胀队列中，作为起始点，然后把该点的前后左右
      // 距离符合条件的点加入到膨胀队列中，逐渐往外膨胀，并且在下一次计算前后左右
      // 点时，起始点(原来master costmap中一系列点)不变，距离起始点距离变了

      // 将障碍物cell推入inflation_queue_
      for (int j = min_j; j < max_j; j++)
      {
        for (int i = min_i; i < max_i; i++)
        {
          int index = master_grid->getIndex(i, j);
          if (master_array[index] == STATIC_OBSTACLE)
            enqueue(master_array, index, i, j, i, j, true);
          if (master_array[index] == DYNAMIC_OBSTACLE)
            enqueue(master_array, index, i, j, i, j, false);
        }
      }
      // 遍历inflation_queue_,把四周的点也放进inflation_queue_
      while (!inflation_queue_.empty())
      {
        // get the highest priority cell and pop it off the priority queue
        const Cell &current_cell = inflation_queue_.top();
        // 当前的cell和最近障碍物cell的位置
        int index = current_cell.index_;
        int mx = current_cell.x_;
        int my = current_cell.y_;
        int sx = current_cell.src_x_;
        int sy = current_cell.src_y_;

        bool is_static;
        if (master_array[index] == STATIC_OBSTACLE)
          is_static = true;

        // pop once we have our cell info
        inflation_queue_.pop();

        // 标记
        if (mx > left)
          enqueue(master_array, index - 1, mx - 1, my, sx, sy, is_static);
        if (my > down)
          enqueue(master_array, index - size_x, mx, my - 1, sx, sy, is_static);
        if (mx < right - 1)
          enqueue(master_array, index + 1, mx + 1, my, sx, sy, is_static);
        if (my < top - 1)
          enqueue(master_array, index + size_x, mx, my + 1, sx, sy, is_static);
      }
    }

    // 非循环调用
    void Inflation::updateCachedCosts()
    {
      for (int i = 0; i <= cell_inflation_radius_ + 1; ++i)
      {
        for (int j = 0; j <= cell_inflation_radius_ + 1; ++j)
        {
          static_cached_costs_[i][j] =
              computeCost(cached_distances_[i][j], STATIC_OBSTACLE, STATIC_INFLATED_OBSTACLE);
          dynamic_cached_costs_[i][j] =
              computeCost(cached_distances_[i][j], DYNAMIC_OBSTACLE, DYNAMIC_INFLATED_OBSTACLE);
        }
      }
    }

    // 基于膨胀参数设置参考矩阵(代价和成本),cached_costs_，cached_distances_,大小是略大于膨胀圆的方形
    //  cached_distances_存的是，cached_distances_(i,j)到cached_distances_（0,0）的距离。cached_distances_存的是对应的cost。
    //  通过computeCost（）计算。
    void Inflation::computeCaches()
    {
      if (cell_inflation_radius_ < 0)
        return;
      // if (cell_inflation_radius_ != cached_cell_inflation_radius_)
      // {
      // 成本和代价的数组“行”大小都是cell_inflation_radius_+2
      static_cached_costs_ = new unsigned char *[cell_inflation_radius_ + 2];
      dynamic_cached_costs_ = new unsigned char *[cell_inflation_radius_ + 2];
      cached_distances_ = new double *[cell_inflation_radius_ + 2];

      for (int i = 0; i <= cell_inflation_radius_ + 1; ++i)
      {
        // 成本和代价的数组“列”大小也是cell_inflation_radius_+2
        static_cached_costs_[i] = new unsigned char[cell_inflation_radius_ + 2];
        dynamic_cached_costs_[i] = new unsigned char[cell_inflation_radius_ + 2];
        cached_distances_[i] = new double[cell_inflation_radius_ + 2];
        for (int j = 0; j <= cell_inflation_radius_ + 1; ++j)
        {
          // 每个元素的值即为它到[0][0]点的三角距离
          cached_distances_[i][j] = hypot(i, j);
        }
      }
      // cell_inflation_radius_ = cached_cell_inflation_radius_;
      // }
      for (int i = 0; i <= cell_inflation_radius_ + 1; ++i)
      {
        for (int j = 0; j <= cell_inflation_radius_ + 1; ++j)
        {
          static_cached_costs_[i][j] =
              computeCost(cached_distances_[i][j], STATIC_OBSTACLE,
                          STATIC_INFLATED_OBSTACLE); // 根据cell离障碍物原点距离计算代价
          dynamic_cached_costs_[i][j] =
              computeCost(cached_distances_[i][j], DYNAMIC_OBSTACLE,
                          DYNAMIC_INFLATED_OBSTACLE); // 根据cell离障碍物原点距离计算代价
        }
      }
    }
  } // namespace common
} // namespace athena
