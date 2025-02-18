// Generated by gencpp from file ros_interface/VehicleMotionPoint.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_VEHICLEMOTIONPOINT_H
#define ROS_INTERFACE_MESSAGE_VEHICLEMOTIONPOINT_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <ros_interface/TrajectoryPoint.h>

namespace ros_interface
{
template <class ContainerAllocator>
struct VehicleMotionPoint_
{
  typedef VehicleMotionPoint_<ContainerAllocator> Type;

  VehicleMotionPoint_()
    : trajectory_point()
    , steer(0.0)  {
    }
  VehicleMotionPoint_(const ContainerAllocator& _alloc)
    : trajectory_point(_alloc)
    , steer(0.0)  {
  (void)_alloc;
    }



   typedef  ::ros_interface::TrajectoryPoint_<ContainerAllocator>  _trajectory_point_type;
  _trajectory_point_type trajectory_point;

   typedef double _steer_type;
  _steer_type steer;





  typedef boost::shared_ptr< ::ros_interface::VehicleMotionPoint_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::VehicleMotionPoint_<ContainerAllocator> const> ConstPtr;

}; // struct VehicleMotionPoint_

typedef ::ros_interface::VehicleMotionPoint_<std::allocator<void> > VehicleMotionPoint;

typedef boost::shared_ptr< ::ros_interface::VehicleMotionPoint > VehicleMotionPointPtr;
typedef boost::shared_ptr< ::ros_interface::VehicleMotionPoint const> VehicleMotionPointConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::VehicleMotionPoint_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::VehicleMotionPoint_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::VehicleMotionPoint_<ContainerAllocator1> & lhs, const ::ros_interface::VehicleMotionPoint_<ContainerAllocator2> & rhs)
{
  return lhs.trajectory_point == rhs.trajectory_point &&
    lhs.steer == rhs.steer;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::VehicleMotionPoint_<ContainerAllocator1> & lhs, const ::ros_interface::VehicleMotionPoint_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::VehicleMotionPoint_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::VehicleMotionPoint_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::VehicleMotionPoint_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::VehicleMotionPoint_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::VehicleMotionPoint_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::VehicleMotionPoint_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::VehicleMotionPoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "817b6833314550b435f029c9809d3a23";
  }

  static const char* value(const ::ros_interface::VehicleMotionPoint_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x817b6833314550b4ULL;
  static const uint64_t static_value2 = 0x35f029c9809d3a23ULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::VehicleMotionPoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/VehicleMotionPoint";
  }

  static const char* value(const ::ros_interface::VehicleMotionPoint_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::VehicleMotionPoint_<ContainerAllocator> >
{
  static const char* value()
  {
    return "TrajectoryPoint   trajectory_point     # trajectory point\n"
"float64   steer     # The angle between vehicle front wheel and vehicle longitudinal axis\n"
"\n"
"================================================================================\n"
"MSG: ros_interface/TrajectoryPoint\n"
"PathPoint   path_point     # path point\n"
"float64   v     # linear velocity\n"
"float64   a     # linear acceleration\n"
"float64   relative_time     # relative time from beginning of the trajectory\n"
"float64   da     # longitudinal jerk\n"
"bool   is_steer_valid     # 转向是否有效\n"
"float64   front_steer     # The angle between vehicle front wheel and vehicle longitudinal axis\n"
"float64   rear_steer     # 后轮转角\n"
"int32   gear     # 档位\n"
"\n"
"================================================================================\n"
"MSG: ros_interface/PathPoint\n"
"float64   x     # coordinates x\n"
"float64   y     # coordinates y\n"
"float64   z     # coordinates z\n"
"float64   theta     # direction on the x-y plane\n"
"float64   kappa     # curvature on the x-y planning\n"
"float64   s     # accumulated distance from beginning of the path\n"
"float64   dkappa     # derivative of kappa w.r.t s.\n"
"float64   ddkappa     # derivative of derivative of kappa w.r.t s.\n"
"float64   lane_id     # The lane ID where the path point is on\n"
"float64   x_derivative     # derivative of x w.r.t parametric parameter t in CosThetareferenceline\n"
"float64   y_derivative     # derivative of y w.r.t parametric parameter t in CosThetareferenceline\n"
;
  }

  static const char* value(const ::ros_interface::VehicleMotionPoint_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::VehicleMotionPoint_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.trajectory_point);
      stream.next(m.steer);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct VehicleMotionPoint_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::VehicleMotionPoint_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::VehicleMotionPoint_<ContainerAllocator>& v)
  {
    s << indent << "trajectory_point: ";
    s << std::endl;
    Printer< ::ros_interface::TrajectoryPoint_<ContainerAllocator> >::stream(s, indent + "  ", v.trajectory_point);
    s << indent << "steer: ";
    Printer<double>::stream(s, indent + "  ", v.steer);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_VEHICLEMOTIONPOINT_H
