#ifndef _COSTMAP_H_
#define _COSTMAP_H_

#include <math.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

#include <mutex>
namespace athena
{
  namespace common
  {

    static const unsigned char NO_INFORMATION = 255;            // 禁止行驶区域
    static const unsigned char STATIC_OBSTACLE = 254;           // 静态障碍物区域
    static const unsigned char STATIC_INFLATED_OBSTACLE = 253;  // 静态障碍物膨胀区域
    static const unsigned char DYNAMIC_OBSTACLE = 252;          // 动态障碍物区域
    static const unsigned char DYNAMIC_INFLATED_OBSTACLE = 251; // 动态障碍物膨胀区域
    static const unsigned char FREE_SPACE = 0;

    // costmap结构
    struct COSTMAP
    {
      int size_cell_x;
      int size_cell_y;
      double resolution;
      double origin_x;
      double origin_y;
      unsigned char charmap[400 * 400];
    };

    struct UpdateRange
    {
      UpdateRange() {}
      UpdateRange(int x0, int y0, int xn, int yn) : x0_(x0), y0_(y0), xn_(xn), yn_(yn) {}
      UpdateRange(const UpdateRange &range)
          : x0_(range.x0_), y0_(range.y0_), xn_(range.xn_), yn_(range.yn_) {}
      int x0_{0};
      int y0_{0};
      int xn_{0};
      int yn_{0};
    };

    class Costmap
    {
    public:
      Costmap()
      {
        size_cell_x_ = 0;
        size_cell_y_ = 0;
        resolution_ = 0.0;
        origin_x_ = 0.0;
        origin_y_ = 0.0;
        charmap_ = nullptr;
      }

      Costmap(unsigned int cells_size_x, unsigned int cells_size_y, double resolution, double origin_x,
              double origin_y)
      {
        size_cell_x_ = cells_size_x;
        size_cell_y_ = cells_size_y;
        resolution_ = resolution;
        origin_x_ = origin_x;
        origin_y_ = origin_y;
        size_x_ = size_cell_x_ * resolution_;
        size_y_ = size_cell_y_ * resolution_;
        charmap_ = new unsigned char[cells_size_x * cells_size_y];
      }

      Costmap(unsigned int cells_size_x, unsigned int cells_size_y, double resolution, double origin_x,
              double origin_y, double value)
      {
        size_cell_x_ = cells_size_x;
        size_cell_y_ = cells_size_y;
        resolution_ = resolution;
        origin_x_ = origin_x;
        origin_y_ = origin_y;
        size_x_ = size_cell_x_ * resolution_;
        size_y_ = size_cell_y_ * resolution_;
        charmap_ = new unsigned char[cells_size_x * cells_size_y];
        memset(charmap_, value, size_cell_x_ * size_cell_y_ * sizeof(unsigned char));
      }
      ~Costmap() { delete[] charmap_; }

      void clearCharmap()
      {
        // 释放内存
        if (charmap_ == nullptr)
          return;
        delete[] charmap_;
        charmap_ = new unsigned char[size_cell_x_ * size_cell_y_];
        memset(charmap_, FREE_SPACE, size_cell_x_ * size_cell_y_ * sizeof(unsigned char));
      }

      Costmap &operator=(const Costmap &map)
      {
        if (this == &map)
          return *this;
        deleteMaps();
        // copy the cost map
        initMaps(map);
        return *this;
      }

      bool CheckPointSafe(double wx, double wy)
      {
        int cell_x, cell_y;

        if (!worldToMap(wx, wy, cell_x, cell_y))
        {
          return false;
        }

        if (getCost(cell_x, cell_y) == STATIC_OBSTACLE)
        {
          // LOG_INFO("unsafe cell:%d,%d ", cell_x, cell_y);
          return false;
        }
        return true;
      }

      inline unsigned char getCost(int mx, int my) const { return charmap_[getIndex(mx, my)]; }
      inline unsigned char getCost(int index) const { return charmap_[index]; }
      inline int getIndex(int mx, int my) const { return my * size_cell_x_ + mx; }
      int getSizeInCellsX() const { return size_cell_x_; }
      int getSizeInCellsY() const { return size_cell_y_; }
      int getSizeInMetersX() const { return size_x_; }
      int getSizeInMetersY() const { return size_y_; }
      double getOriginX() const { return origin_x_; }
      double getOriginY() const { return origin_y_; }
      void setOriginX(double x) { origin_x_ = x; }
      void setOriginY(double y) { origin_y_ = y; }
      double getResolution() const { return resolution_; }
      unsigned char *getCharMap() const { return charmap_; }

      void setCost(int mx, int my, unsigned char cost)
      {
        if (isOutOfBound(mx, my))
          return;
        charmap_[getIndex(mx, my)] = cost;
      }

      void setCost(int index, unsigned char cost)
      {
        if (isOutOfBound(index))
          return;
        charmap_[index] = cost;
      }
      void setCharMap(unsigned char *charmap)
      {
        if (sizeof(charmap_) / sizeof(unsigned char) != sizeof(charmap) / sizeof(unsigned char))
          return;
        memcpy(charmap_, charmap, size_cell_x_ * size_cell_y_ * sizeof(unsigned char));
      }
      bool isOutOfBound(int mx, int my)
      {
        return !(mx >= 0 && my >= 0 && mx < size_cell_x_ && my < size_cell_y_);
      }
      bool isOutOfBound(int index) { return !(index >= 0 && index < size_cell_x_ * size_cell_y_); }
      // localmap的oring_x oring_y是左下角在全局系下的坐标
      bool worldToMap(double wx, double wy, int &mx, int &my) const
      {
        if (wx >= origin_x_ && wy >= origin_y_ && resolution_ > 0)
        {
          mx = floor((wx - origin_x_) / resolution_);
          my = floor((wy - origin_y_) / resolution_);
          if (mx >= 0 && my >= 0 && mx < size_cell_x_ && my < size_cell_y_)
            return true;
        }
        return false;
      }

      bool worldToMap(double wx, double wy, unsigned int &mx, unsigned int &my) const
      {
        int tmp_x{0}, tmp_y{0};
        if (worldToMap(wx, wy, tmp_x, tmp_y))
        {
          mx = tmp_x;
          my = tmp_y;
          return true;
        }
        return false;
      }

      void mapToWorld(int mx, int my, double &wx, double &wy) const
      {
        wx = origin_x_ + (mx + 0.5) * resolution_;
        wy = origin_y_ + (my + 0.5) * resolution_;
      }

      void mapToWorld(unsigned int mx, unsigned int my, double &wx, double &wy) const
      {
        wx = origin_x_ + (mx + 0.5) * resolution_;
        wy = origin_y_ + (my + 0.5) * resolution_;
      }

      void localToWorld(double lx, double ly, double &wx, double &wy) const
      {
        wx = lx + origin_x_;
        wy = ly + origin_y_;
      }

      void worldToLocal(double wx, double wy, double &lx, double &ly) const
      {
        lx = wx - origin_x_;
        ly = wy - origin_y_;
      }

      void setGlobalFrameID(std::string frame_id) { global_frame_id_ = frame_id; }
      std::string getGlobalFrameID() const { return global_frame_id_; }
      //  int getSizeInCellsX() const { return size_x_; }

    private:
      void deleteMaps()
      {
        // clean up data
        std::lock_guard<std::mutex> guard(access_);
        delete[] charmap_;
      }

      void initMaps(const Costmap &map)
      {
        std::lock_guard<std::mutex> guard(access_);
        size_x_ = map.getSizeInMetersX();
        size_y_ = map.getSizeInMetersY();
        size_cell_x_ = map.getSizeInCellsX();
        size_cell_y_ = map.getSizeInCellsY();
        resolution_ = map.getResolution();
        origin_x_ = map.getOriginX();
        origin_y_ = map.getOriginY();
        global_frame_id_ = map.getGlobalFrameID();
        charmap_ = new unsigned char[size_cell_x_ * size_cell_y_];
        memcpy(charmap_, map.getCharMap(), size_cell_x_ * size_cell_y_ * sizeof(unsigned char));
      }

      unsigned char *charmap_;
      int size_x_{0};
      int size_y_{0};
      int size_cell_x_{0};
      int size_cell_y_{0};
      double origin_x_{0};
      double origin_y_{0};
      double resolution_{0.0};
      std::string global_frame_id_;
      std::mutex access_;
    };
  } // namespace common
} // namespace athena
#endif
