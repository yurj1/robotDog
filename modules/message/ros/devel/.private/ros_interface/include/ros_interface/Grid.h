// Generated by gencpp from file ros_interface/Grid.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_GRID_H
#define ROS_INTERFACE_MESSAGE_GRID_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <ros_interface/SLPoint.h>

namespace ros_interface
{
template <class ContainerAllocator>
struct Grid_
{
  typedef Grid_<ContainerAllocator> Type;

  Grid_()
    : x(0.0)
    , y(0.0)
    , sl_point()
    , yaw(0.0)
    , potential(0.0)
    , region_id(0)  {
    }
  Grid_(const ContainerAllocator& _alloc)
    : x(0.0)
    , y(0.0)
    , sl_point(_alloc)
    , yaw(0.0)
    , potential(0.0)
    , region_id(0)  {
  (void)_alloc;
    }



   typedef double _x_type;
  _x_type x;

   typedef double _y_type;
  _y_type y;

   typedef  ::ros_interface::SLPoint_<ContainerAllocator>  _sl_point_type;
  _sl_point_type sl_point;

   typedef double _yaw_type;
  _yaw_type yaw;

   typedef double _potential_type;
  _potential_type potential;

   typedef int32_t _region_id_type;
  _region_id_type region_id;





  typedef boost::shared_ptr< ::ros_interface::Grid_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::Grid_<ContainerAllocator> const> ConstPtr;

}; // struct Grid_

typedef ::ros_interface::Grid_<std::allocator<void> > Grid;

typedef boost::shared_ptr< ::ros_interface::Grid > GridPtr;
typedef boost::shared_ptr< ::ros_interface::Grid const> GridConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::Grid_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::Grid_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::Grid_<ContainerAllocator1> & lhs, const ::ros_interface::Grid_<ContainerAllocator2> & rhs)
{
  return lhs.x == rhs.x &&
    lhs.y == rhs.y &&
    lhs.sl_point == rhs.sl_point &&
    lhs.yaw == rhs.yaw &&
    lhs.potential == rhs.potential &&
    lhs.region_id == rhs.region_id;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::Grid_<ContainerAllocator1> & lhs, const ::ros_interface::Grid_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::Grid_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::Grid_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::Grid_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::Grid_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::Grid_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::Grid_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::Grid_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9568bcb9570b90eb25fe5d5c120e6ee7";
  }

  static const char* value(const ::ros_interface::Grid_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9568bcb9570b90ebULL;
  static const uint64_t static_value2 = 0x25fe5d5c120e6ee7ULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::Grid_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/Grid";
  }

  static const char* value(const ::ros_interface::Grid_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::Grid_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64   x     # 世界坐标系下的x\n"
"float64   y     # 世界坐标系下的y\n"
"SLPoint   sl_point     # Frenet坐标系下的x\n"
"float64   yaw     #  \n"
"float64   potential     # 势场值\n"
"int32   region_id     # 区域编号\n"
"\n"
"================================================================================\n"
"MSG: ros_interface/SLPoint\n"
"float64   s     # 纵向位移\n"
"float64   l     # 横向位移\n"
;
  }

  static const char* value(const ::ros_interface::Grid_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::Grid_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.sl_point);
      stream.next(m.yaw);
      stream.next(m.potential);
      stream.next(m.region_id);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Grid_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::Grid_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::Grid_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "sl_point: ";
    s << std::endl;
    Printer< ::ros_interface::SLPoint_<ContainerAllocator> >::stream(s, indent + "  ", v.sl_point);
    s << indent << "yaw: ";
    Printer<double>::stream(s, indent + "  ", v.yaw);
    s << indent << "potential: ";
    Printer<double>::stream(s, indent + "  ", v.potential);
    s << indent << "region_id: ";
    Printer<int32_t>::stream(s, indent + "  ", v.region_id);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_GRID_H
