// Generated by gencpp from file ros_interface/RoadMark.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_ROADMARK_H
#define ROS_INTERFACE_MESSAGE_ROADMARK_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ros_interface
{
template <class ContainerAllocator>
struct RoadMark_
{
  typedef RoadMark_<ContainerAllocator> Type;

  RoadMark_()
    : longitude_dist(0.0)
    , lateral_dist(0.0)
    , x(0.0)
    , y(0.0)
    , z(0.0)
    , confidence(0.0)
    , type(0)  {
    }
  RoadMark_(const ContainerAllocator& _alloc)
    : longitude_dist(0.0)
    , lateral_dist(0.0)
    , x(0.0)
    , y(0.0)
    , z(0.0)
    , confidence(0.0)
    , type(0)  {
  (void)_alloc;
    }



   typedef double _longitude_dist_type;
  _longitude_dist_type longitude_dist;

   typedef double _lateral_dist_type;
  _lateral_dist_type lateral_dist;

   typedef double _x_type;
  _x_type x;

   typedef double _y_type;
  _y_type y;

   typedef double _z_type;
  _z_type z;

   typedef double _confidence_type;
  _confidence_type confidence;

   typedef int32_t _type_type;
  _type_type type;





  typedef boost::shared_ptr< ::ros_interface::RoadMark_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::RoadMark_<ContainerAllocator> const> ConstPtr;

}; // struct RoadMark_

typedef ::ros_interface::RoadMark_<std::allocator<void> > RoadMark;

typedef boost::shared_ptr< ::ros_interface::RoadMark > RoadMarkPtr;
typedef boost::shared_ptr< ::ros_interface::RoadMark const> RoadMarkConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::RoadMark_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::RoadMark_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::RoadMark_<ContainerAllocator1> & lhs, const ::ros_interface::RoadMark_<ContainerAllocator2> & rhs)
{
  return lhs.longitude_dist == rhs.longitude_dist &&
    lhs.lateral_dist == rhs.lateral_dist &&
    lhs.x == rhs.x &&
    lhs.y == rhs.y &&
    lhs.z == rhs.z &&
    lhs.confidence == rhs.confidence &&
    lhs.type == rhs.type;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::RoadMark_<ContainerAllocator1> & lhs, const ::ros_interface::RoadMark_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::RoadMark_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::RoadMark_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::RoadMark_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::RoadMark_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::RoadMark_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::RoadMark_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::RoadMark_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1eab58881f87a0f5c354efa8d4f36c41";
  }

  static const char* value(const ::ros_interface::RoadMark_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1eab58881f87a0f5ULL;
  static const uint64_t static_value2 = 0xc354efa8d4f36c41ULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::RoadMark_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/RoadMark";
  }

  static const char* value(const ::ros_interface::RoadMark_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::RoadMark_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64   longitude_dist     # 相对于车身坐标系原点的纵向距离,单位m\n"
"float64   lateral_dist     # 相对于车身坐标系原点的横向距离,单位m\n"
"float64   x     # 质心坐标x\n"
"float64   y     # 质心坐标y\n"
"float64   z     # 质心坐标z\n"
"float64   confidence     # 置信度[0 - 1]\n"
"int32   type     # 标识类型 1 - 停止线 2 - 斑马线 3 - 禁停区 4 - 直行箭头 5 - 左转箭头 6 - 右转箭头 7 - 直行+左转 8 - 直行+右转 9 - 直行+左转+右转 10 - 掉头 11 - 左掉头 12 - 菱形(前方有人行横道) 13 - 倒三角 (减速让行) 14 - 地面文字\n"
;
  }

  static const char* value(const ::ros_interface::RoadMark_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::RoadMark_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.longitude_dist);
      stream.next(m.lateral_dist);
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
      stream.next(m.confidence);
      stream.next(m.type);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RoadMark_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::RoadMark_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::RoadMark_<ContainerAllocator>& v)
  {
    s << indent << "longitude_dist: ";
    Printer<double>::stream(s, indent + "  ", v.longitude_dist);
    s << indent << "lateral_dist: ";
    Printer<double>::stream(s, indent + "  ", v.lateral_dist);
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<double>::stream(s, indent + "  ", v.z);
    s << indent << "confidence: ";
    Printer<double>::stream(s, indent + "  ", v.confidence);
    s << indent << "type: ";
    Printer<int32_t>::stream(s, indent + "  ", v.type);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_ROADMARK_H
