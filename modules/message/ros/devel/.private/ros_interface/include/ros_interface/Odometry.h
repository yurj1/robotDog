// Generated by gencpp from file ros_interface/Odometry.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_ODOMETRY_H
#define ROS_INTERFACE_MESSAGE_ODOMETRY_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <ros_interface/PointENU.h>
#include <ros_interface/Quaternion.h>

namespace ros_interface
{
template <class ContainerAllocator>
struct Odometry_
{
  typedef Odometry_<ContainerAllocator> Type;

  Odometry_()
    : header()
    , position()
    , orientation()
    , covariance()  {
    }
  Odometry_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , position(_alloc)
    , orientation(_alloc)
    , covariance(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::ros_interface::PointENU_<ContainerAllocator>  _position_type;
  _position_type position;

   typedef  ::ros_interface::Quaternion_<ContainerAllocator>  _orientation_type;
  _orientation_type orientation;

   typedef std::vector<double, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<double>> _covariance_type;
  _covariance_type covariance;





  typedef boost::shared_ptr< ::ros_interface::Odometry_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::Odometry_<ContainerAllocator> const> ConstPtr;

}; // struct Odometry_

typedef ::ros_interface::Odometry_<std::allocator<void> > Odometry;

typedef boost::shared_ptr< ::ros_interface::Odometry > OdometryPtr;
typedef boost::shared_ptr< ::ros_interface::Odometry const> OdometryConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::Odometry_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::Odometry_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::Odometry_<ContainerAllocator1> & lhs, const ::ros_interface::Odometry_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.position == rhs.position &&
    lhs.orientation == rhs.orientation &&
    lhs.covariance == rhs.covariance;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::Odometry_<ContainerAllocator1> & lhs, const ::ros_interface::Odometry_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::Odometry_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::Odometry_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::Odometry_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::Odometry_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::Odometry_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::Odometry_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::Odometry_<ContainerAllocator> >
{
  static const char* value()
  {
    return "772a78ca9f8e31d00868db9627807309";
  }

  static const char* value(const ::ros_interface::Odometry_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x772a78ca9f8e31d0ULL;
  static const uint64_t static_value2 = 0x0868db9627807309ULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::Odometry_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/Odometry";
  }

  static const char* value(const ::ros_interface::Odometry_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::Odometry_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header   header     # 含有时间戳信息的结构体\n"
"PointENU   position     # 位置\n"
"Quaternion   orientation     # 角度\n"
"float64[] covariance # 方差\n"
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
"MSG: ros_interface/PointENU\n"
"float64   x     # East from the origin, in meters.\n"
"float64   y     # North from the origin, in meters.\n"
"float64   z     # Up from the WGS-84 ellipsoid, in meters.\n"
"\n"
"================================================================================\n"
"MSG: ros_interface/Quaternion\n"
"float64   qx     # 四维空间x\n"
"float64   qy     # 四维空间y\n"
"float64   qz     # 四维空间z\n"
"float64   qw     # 四维空间w\n"
;
  }

  static const char* value(const ::ros_interface::Odometry_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::Odometry_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.position);
      stream.next(m.orientation);
      stream.next(m.covariance);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Odometry_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::Odometry_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::Odometry_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "position: ";
    s << std::endl;
    Printer< ::ros_interface::PointENU_<ContainerAllocator> >::stream(s, indent + "  ", v.position);
    s << indent << "orientation: ";
    s << std::endl;
    Printer< ::ros_interface::Quaternion_<ContainerAllocator> >::stream(s, indent + "  ", v.orientation);
    s << indent << "covariance[]" << std::endl;
    for (size_t i = 0; i < v.covariance.size(); ++i)
    {
      s << indent << "  covariance[" << i << "]: ";
      Printer<double>::stream(s, indent + "  ", v.covariance[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_ODOMETRY_H
