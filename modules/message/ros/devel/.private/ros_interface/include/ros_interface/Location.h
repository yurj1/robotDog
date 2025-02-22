// Generated by gencpp from file ros_interface/Location.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_LOCATION_H
#define ROS_INTERFACE_MESSAGE_LOCATION_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <ros_interface/PointLLH.h>
#include <ros_interface/Point3D.h>
#include <ros_interface/Point3D.h>
#include <ros_interface/Point3D.h>
#include <ros_interface/PointENU.h>
#include <ros_interface/PointENU.h>
#include <ros_interface/Point3D.h>
#include <ros_interface/Point3D.h>
#include <ros_interface/Point3D.h>
#include <ros_interface/Point3D.h>
#include <ros_interface/Point3D.h>

namespace ros_interface
{
template <class ContainerAllocator>
struct Location_
{
  typedef Location_<ContainerAllocator> Type;

  Location_()
    : header()
    , position()
    , pitch(0.0)
    , roll(0.0)
    , heading(0.0)
    , linear_velocity()
    , linear_acceleration()
    , angular_velocity()
    , rtk_flag(0)
    , odom_type(0)
    , auxiliary_type(0)
    , location_valid_flag(0)
    , origin_lat(0.0)
    , origin_lon(0.0)
    , utm_position()
    , change_origin_flag(0)
    , utm_position_next()
    , position_std_dev()
    , orientation_std_dev()
    , linear_velocity_std_dev()
    , linear_acceleration_std_dev()
    , angular_velocity_std_dev()  {
    }
  Location_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , position(_alloc)
    , pitch(0.0)
    , roll(0.0)
    , heading(0.0)
    , linear_velocity(_alloc)
    , linear_acceleration(_alloc)
    , angular_velocity(_alloc)
    , rtk_flag(0)
    , odom_type(0)
    , auxiliary_type(0)
    , location_valid_flag(0)
    , origin_lat(0.0)
    , origin_lon(0.0)
    , utm_position(_alloc)
    , change_origin_flag(0)
    , utm_position_next(_alloc)
    , position_std_dev(_alloc)
    , orientation_std_dev(_alloc)
    , linear_velocity_std_dev(_alloc)
    , linear_acceleration_std_dev(_alloc)
    , angular_velocity_std_dev(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef  ::ros_interface::PointLLH_<ContainerAllocator>  _position_type;
  _position_type position;

   typedef double _pitch_type;
  _pitch_type pitch;

   typedef double _roll_type;
  _roll_type roll;

   typedef double _heading_type;
  _heading_type heading;

   typedef  ::ros_interface::Point3D_<ContainerAllocator>  _linear_velocity_type;
  _linear_velocity_type linear_velocity;

   typedef  ::ros_interface::Point3D_<ContainerAllocator>  _linear_acceleration_type;
  _linear_acceleration_type linear_acceleration;

   typedef  ::ros_interface::Point3D_<ContainerAllocator>  _angular_velocity_type;
  _angular_velocity_type angular_velocity;

   typedef int32_t _rtk_flag_type;
  _rtk_flag_type rtk_flag;

   typedef int32_t _odom_type_type;
  _odom_type_type odom_type;

   typedef int32_t _auxiliary_type_type;
  _auxiliary_type_type auxiliary_type;

   typedef int32_t _location_valid_flag_type;
  _location_valid_flag_type location_valid_flag;

   typedef double _origin_lat_type;
  _origin_lat_type origin_lat;

   typedef double _origin_lon_type;
  _origin_lon_type origin_lon;

   typedef  ::ros_interface::PointENU_<ContainerAllocator>  _utm_position_type;
  _utm_position_type utm_position;

   typedef int32_t _change_origin_flag_type;
  _change_origin_flag_type change_origin_flag;

   typedef  ::ros_interface::PointENU_<ContainerAllocator>  _utm_position_next_type;
  _utm_position_next_type utm_position_next;

   typedef  ::ros_interface::Point3D_<ContainerAllocator>  _position_std_dev_type;
  _position_std_dev_type position_std_dev;

   typedef  ::ros_interface::Point3D_<ContainerAllocator>  _orientation_std_dev_type;
  _orientation_std_dev_type orientation_std_dev;

   typedef  ::ros_interface::Point3D_<ContainerAllocator>  _linear_velocity_std_dev_type;
  _linear_velocity_std_dev_type linear_velocity_std_dev;

   typedef  ::ros_interface::Point3D_<ContainerAllocator>  _linear_acceleration_std_dev_type;
  _linear_acceleration_std_dev_type linear_acceleration_std_dev;

   typedef  ::ros_interface::Point3D_<ContainerAllocator>  _angular_velocity_std_dev_type;
  _angular_velocity_std_dev_type angular_velocity_std_dev;





  typedef boost::shared_ptr< ::ros_interface::Location_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::Location_<ContainerAllocator> const> ConstPtr;

}; // struct Location_

typedef ::ros_interface::Location_<std::allocator<void> > Location;

typedef boost::shared_ptr< ::ros_interface::Location > LocationPtr;
typedef boost::shared_ptr< ::ros_interface::Location const> LocationConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::Location_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::Location_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::Location_<ContainerAllocator1> & lhs, const ::ros_interface::Location_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.position == rhs.position &&
    lhs.pitch == rhs.pitch &&
    lhs.roll == rhs.roll &&
    lhs.heading == rhs.heading &&
    lhs.linear_velocity == rhs.linear_velocity &&
    lhs.linear_acceleration == rhs.linear_acceleration &&
    lhs.angular_velocity == rhs.angular_velocity &&
    lhs.rtk_flag == rhs.rtk_flag &&
    lhs.odom_type == rhs.odom_type &&
    lhs.auxiliary_type == rhs.auxiliary_type &&
    lhs.location_valid_flag == rhs.location_valid_flag &&
    lhs.origin_lat == rhs.origin_lat &&
    lhs.origin_lon == rhs.origin_lon &&
    lhs.utm_position == rhs.utm_position &&
    lhs.change_origin_flag == rhs.change_origin_flag &&
    lhs.utm_position_next == rhs.utm_position_next &&
    lhs.position_std_dev == rhs.position_std_dev &&
    lhs.orientation_std_dev == rhs.orientation_std_dev &&
    lhs.linear_velocity_std_dev == rhs.linear_velocity_std_dev &&
    lhs.linear_acceleration_std_dev == rhs.linear_acceleration_std_dev &&
    lhs.angular_velocity_std_dev == rhs.angular_velocity_std_dev;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::Location_<ContainerAllocator1> & lhs, const ::ros_interface::Location_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::Location_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::Location_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::Location_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::Location_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::Location_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::Location_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::Location_<ContainerAllocator> >
{
  static const char* value()
  {
    return "6b25c2b9af6ab35d68c43d9abb43d342";
  }

  static const char* value(const ::ros_interface::Location_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x6b25c2b9af6ab35dULL;
  static const uint64_t static_value2 = 0x68c43d9abb43d342ULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::Location_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/Location";
  }

  static const char* value(const ::ros_interface::Location_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::Location_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header   header     # 消息头\n"
"PointLLH   position     # 经纬度高程\n"
"float64   pitch     # 方向(单位弧度，-π～π,正东:0, 逆时针。都满足右手定则)\n"
"float64   roll     #  \n"
"float64   heading     #  \n"
"Point3D   linear_velocity     # 线速度（m/s，北东地坐标系）\n"
"Point3D   linear_acceleration     # 线加速度（m/s2，前右下坐标系）\n"
"Point3D   angular_velocity     # 角速度（度/s，前右下，满足右手定则）\n"
"int32   rtk_flag     # RTK标志值\n"
"int32   odom_type     # 融合标志:0-(纯ins) 1-(纯轮速) 2-(泊车递推) 3-(无) 4-(orb匹配定位)\n"
"int32   auxiliary_type     # 辅助方式:0-NULL(无辅助方式) 1-laneliine_map(车道线/标识牌)2-feature_map(lidar)3-feature_map(lidar_camera)\n"
"int32   location_valid_flag     # Location有效性标志位0: invalid； 1: valid\n"
"float64   origin_lat     # 参考点纬度 GCJ-02格式\n"
"float64   origin_lon     # 参考点经度 GCJ-02格式\n"
"PointENU   utm_position     # 相对参考点xyz坐标\n"
"int32   change_origin_flag     # 0::无坐标系切换 1:坐标系切换成功2:坐标系切换中3:坐标系切换故障\n"
"PointENU   utm_position_next     # 相对参考点坐标(切换状态下，为新的原点坐标系下)\n"
"Point3D   position_std_dev     # 位置标准差\n"
"Point3D   orientation_std_dev     # 方向标准差\n"
"Point3D   linear_velocity_std_dev     # 速度标准差\n"
"Point3D   linear_acceleration_std_dev     # 加速度标准差\n"
"Point3D   angular_velocity_std_dev     # 角速度标准差\n"
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
"MSG: ros_interface/PointLLH\n"
"float64   lon     # Longitude in degrees, ranging from -180 to 180.\n"
"float64   lat     # Latitude in degrees, ranging from -90 to 90.\n"
"float64   height     # WGS-84 ellipsoid height in meters.\n"
"\n"
"================================================================================\n"
"MSG: ros_interface/Point3D\n"
"float64   x     # 位置坐标x\n"
"float64   y     # 位置坐标y\n"
"float64   z     # 位置坐标z\n"
"\n"
"================================================================================\n"
"MSG: ros_interface/PointENU\n"
"float64   x     # East from the origin, in meters.\n"
"float64   y     # North from the origin, in meters.\n"
"float64   z     # Up from the WGS-84 ellipsoid, in meters.\n"
;
  }

  static const char* value(const ::ros_interface::Location_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::Location_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.position);
      stream.next(m.pitch);
      stream.next(m.roll);
      stream.next(m.heading);
      stream.next(m.linear_velocity);
      stream.next(m.linear_acceleration);
      stream.next(m.angular_velocity);
      stream.next(m.rtk_flag);
      stream.next(m.odom_type);
      stream.next(m.auxiliary_type);
      stream.next(m.location_valid_flag);
      stream.next(m.origin_lat);
      stream.next(m.origin_lon);
      stream.next(m.utm_position);
      stream.next(m.change_origin_flag);
      stream.next(m.utm_position_next);
      stream.next(m.position_std_dev);
      stream.next(m.orientation_std_dev);
      stream.next(m.linear_velocity_std_dev);
      stream.next(m.linear_acceleration_std_dev);
      stream.next(m.angular_velocity_std_dev);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Location_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::Location_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::Location_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "position: ";
    s << std::endl;
    Printer< ::ros_interface::PointLLH_<ContainerAllocator> >::stream(s, indent + "  ", v.position);
    s << indent << "pitch: ";
    Printer<double>::stream(s, indent + "  ", v.pitch);
    s << indent << "roll: ";
    Printer<double>::stream(s, indent + "  ", v.roll);
    s << indent << "heading: ";
    Printer<double>::stream(s, indent + "  ", v.heading);
    s << indent << "linear_velocity: ";
    s << std::endl;
    Printer< ::ros_interface::Point3D_<ContainerAllocator> >::stream(s, indent + "  ", v.linear_velocity);
    s << indent << "linear_acceleration: ";
    s << std::endl;
    Printer< ::ros_interface::Point3D_<ContainerAllocator> >::stream(s, indent + "  ", v.linear_acceleration);
    s << indent << "angular_velocity: ";
    s << std::endl;
    Printer< ::ros_interface::Point3D_<ContainerAllocator> >::stream(s, indent + "  ", v.angular_velocity);
    s << indent << "rtk_flag: ";
    Printer<int32_t>::stream(s, indent + "  ", v.rtk_flag);
    s << indent << "odom_type: ";
    Printer<int32_t>::stream(s, indent + "  ", v.odom_type);
    s << indent << "auxiliary_type: ";
    Printer<int32_t>::stream(s, indent + "  ", v.auxiliary_type);
    s << indent << "location_valid_flag: ";
    Printer<int32_t>::stream(s, indent + "  ", v.location_valid_flag);
    s << indent << "origin_lat: ";
    Printer<double>::stream(s, indent + "  ", v.origin_lat);
    s << indent << "origin_lon: ";
    Printer<double>::stream(s, indent + "  ", v.origin_lon);
    s << indent << "utm_position: ";
    s << std::endl;
    Printer< ::ros_interface::PointENU_<ContainerAllocator> >::stream(s, indent + "  ", v.utm_position);
    s << indent << "change_origin_flag: ";
    Printer<int32_t>::stream(s, indent + "  ", v.change_origin_flag);
    s << indent << "utm_position_next: ";
    s << std::endl;
    Printer< ::ros_interface::PointENU_<ContainerAllocator> >::stream(s, indent + "  ", v.utm_position_next);
    s << indent << "position_std_dev: ";
    s << std::endl;
    Printer< ::ros_interface::Point3D_<ContainerAllocator> >::stream(s, indent + "  ", v.position_std_dev);
    s << indent << "orientation_std_dev: ";
    s << std::endl;
    Printer< ::ros_interface::Point3D_<ContainerAllocator> >::stream(s, indent + "  ", v.orientation_std_dev);
    s << indent << "linear_velocity_std_dev: ";
    s << std::endl;
    Printer< ::ros_interface::Point3D_<ContainerAllocator> >::stream(s, indent + "  ", v.linear_velocity_std_dev);
    s << indent << "linear_acceleration_std_dev: ";
    s << std::endl;
    Printer< ::ros_interface::Point3D_<ContainerAllocator> >::stream(s, indent + "  ", v.linear_acceleration_std_dev);
    s << indent << "angular_velocity_std_dev: ";
    s << std::endl;
    Printer< ::ros_interface::Point3D_<ContainerAllocator> >::stream(s, indent + "  ", v.angular_velocity_std_dev);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_LOCATION_H
