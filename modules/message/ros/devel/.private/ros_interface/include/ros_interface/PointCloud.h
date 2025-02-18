// Generated by gencpp from file ros_interface/PointCloud.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_POINTCLOUD_H
#define ROS_INTERFACE_MESSAGE_POINTCLOUD_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <ros_interface/PointXYZIRT.h>

namespace ros_interface
{
template <class ContainerAllocator>
struct PointCloud_
{
  typedef PointCloud_<ContainerAllocator> Type;

  PointCloud_()
    : header()
    , frame_id()
    , is_dense(false)
    , point()
    , measurement_time(0.0)
    , width(0)
    , height(0)  {
    }
  PointCloud_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , frame_id(_alloc)
    , is_dense(false)
    , point(_alloc)
    , measurement_time(0.0)
    , width(0)
    , height(0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _frame_id_type;
  _frame_id_type frame_id;

   typedef uint8_t _is_dense_type;
  _is_dense_type is_dense;

   typedef std::vector< ::ros_interface::PointXYZIRT_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::ros_interface::PointXYZIRT_<ContainerAllocator> >> _point_type;
  _point_type point;

   typedef double _measurement_time_type;
  _measurement_time_type measurement_time;

   typedef uint32_t _width_type;
  _width_type width;

   typedef uint32_t _height_type;
  _height_type height;





  typedef boost::shared_ptr< ::ros_interface::PointCloud_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::PointCloud_<ContainerAllocator> const> ConstPtr;

}; // struct PointCloud_

typedef ::ros_interface::PointCloud_<std::allocator<void> > PointCloud;

typedef boost::shared_ptr< ::ros_interface::PointCloud > PointCloudPtr;
typedef boost::shared_ptr< ::ros_interface::PointCloud const> PointCloudConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::PointCloud_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::PointCloud_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::PointCloud_<ContainerAllocator1> & lhs, const ::ros_interface::PointCloud_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.frame_id == rhs.frame_id &&
    lhs.is_dense == rhs.is_dense &&
    lhs.point == rhs.point &&
    lhs.measurement_time == rhs.measurement_time &&
    lhs.width == rhs.width &&
    lhs.height == rhs.height;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::PointCloud_<ContainerAllocator1> & lhs, const ::ros_interface::PointCloud_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::PointCloud_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::PointCloud_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::PointCloud_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::PointCloud_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::PointCloud_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::PointCloud_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::PointCloud_<ContainerAllocator> >
{
  static const char* value()
  {
    return "9aef8e2e76707f6e8f4b50d95d6bdbd3";
  }

  static const char* value(const ::ros_interface::PointCloud_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x9aef8e2e76707f6eULL;
  static const uint64_t static_value2 = 0x8f4b50d95d6bdbd3ULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::PointCloud_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/PointCloud";
  }

  static const char* value(const ::ros_interface::PointCloud_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::PointCloud_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header   header     # 消息头\n"
"string   frame_id     # 帧id\n"
"bool   is_dense     # True if there are no invalid points\n"
"PointXYZIRT[] point # 激光点结构体\n"
"float64   measurement_time     # 测量时间\n"
"uint32   width     # 激光点宽度\n"
"uint32   height     # 激光点高度\n"
"\n"
"================================================================================\n"
"MSG: std_msgs/Header\n"
"# Standard metadata for higher-level stamped data types.\n"
"# This is generally used to communicate timestamped data \n"
"# in a particular coordinate frame.\n"
"# \n"
"# sequence ID: consecutively increasing ID \n"
"uint32 seq\n"
"#Two-integer timestamp that is expressed as:\n"
"# * stamp.sec: seconds (stamp_secs) since epoch (in Python the variable is called 'secs')\n"
"# * stamp.nsec: nanoseconds since stamp_secs (in Python the variable is called 'nsecs')\n"
"# time-handling sugar is provided by the client library\n"
"time stamp\n"
"#Frame this data is associated with\n"
"string frame_id\n"
"\n"
"================================================================================\n"
"MSG: ros_interface/PointXYZIRT\n"
"float64   x     # x//坐标x\n"
"float64   y     # y//坐标y\n"
"float64   z     # z//坐标z\n"
"uint32   intensity     # 反射强度\n"
"uint8   ring_id     # 线束ID\n"
"uint64   timestamp     # 时间戳\n"
;
  }

  static const char* value(const ::ros_interface::PointCloud_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::PointCloud_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.frame_id);
      stream.next(m.is_dense);
      stream.next(m.point);
      stream.next(m.measurement_time);
      stream.next(m.width);
      stream.next(m.height);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PointCloud_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::PointCloud_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::PointCloud_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "frame_id: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.frame_id);
    s << indent << "is_dense: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.is_dense);
    s << indent << "point[]" << std::endl;
    for (size_t i = 0; i < v.point.size(); ++i)
    {
      s << indent << "  point[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::ros_interface::PointXYZIRT_<ContainerAllocator> >::stream(s, indent + "    ", v.point[i]);
    }
    s << indent << "measurement_time: ";
    Printer<double>::stream(s, indent + "  ", v.measurement_time);
    s << indent << "width: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.width);
    s << indent << "height: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.height);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_POINTCLOUD_H
