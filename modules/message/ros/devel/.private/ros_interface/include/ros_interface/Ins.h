// Generated by gencpp from file ros_interface/Ins.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_INS_H
#define ROS_INTERFACE_MESSAGE_INS_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <ros_interface/Point3D.h>
#include <ros_interface/Point3D.h>
#include <ros_interface/Point3D.h>
#include <ros_interface/Point3D.h>
#include <ros_interface/Point3D.h>
#include <ros_interface/Point3D.h>
#include <ros_interface/Point3D.h>
#include <ros_interface/Point3D.h>
#include <ros_interface/Point3D.h>
#include <ros_interface/Point3D.h>

namespace ros_interface
{
template <class ContainerAllocator>
struct Ins_
{
  typedef Ins_<ContainerAllocator> Type;

  Ins_()
    : header()
    , is_valid(false)
    , latitude(0.0)
    , longitude(0.0)
    , elevation(0.0)
    , utm_position()
    , utm_zone_mumber(0)
    , utm_zone_char(0)
    , attitude()
    , linear_velocity()
    , sd_position()
    , sd_attitude()
    , sd_velocity()
    , cep68(0.0)
    , cep95(0.0)
    , second(0.0)
    , sat_use_num(0)
    , sat_in_view_num(0)
    , solution_status(0)
    , position_type(0)
    , p_dop(0.0)
    , h_dop(0.0)
    , v_dop(0.0)
    , attitude_dual()
    , sd_angle_dual()
    , base_line_length_dual(0.0)
    , solution_status_dual(0)
    , position_type_dual(0)
    , solution_source_dual(0)
    , aoc(0)
    , rtk_baseline(0)
    , angular_velocity()
    , acceleration()  {
    }
  Ins_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , is_valid(false)
    , latitude(0.0)
    , longitude(0.0)
    , elevation(0.0)
    , utm_position(_alloc)
    , utm_zone_mumber(0)
    , utm_zone_char(0)
    , attitude(_alloc)
    , linear_velocity(_alloc)
    , sd_position(_alloc)
    , sd_attitude(_alloc)
    , sd_velocity(_alloc)
    , cep68(0.0)
    , cep95(0.0)
    , second(0.0)
    , sat_use_num(0)
    , sat_in_view_num(0)
    , solution_status(0)
    , position_type(0)
    , p_dop(0.0)
    , h_dop(0.0)
    , v_dop(0.0)
    , attitude_dual(_alloc)
    , sd_angle_dual(_alloc)
    , base_line_length_dual(0.0)
    , solution_status_dual(0)
    , position_type_dual(0)
    , solution_source_dual(0)
    , aoc(0)
    , rtk_baseline(0)
    , angular_velocity(_alloc)
    , acceleration(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef uint8_t _is_valid_type;
  _is_valid_type is_valid;

   typedef double _latitude_type;
  _latitude_type latitude;

   typedef double _longitude_type;
  _longitude_type longitude;

   typedef double _elevation_type;
  _elevation_type elevation;

   typedef  ::ros_interface::Point3D_<ContainerAllocator>  _utm_position_type;
  _utm_position_type utm_position;

   typedef int32_t _utm_zone_mumber_type;
  _utm_zone_mumber_type utm_zone_mumber;

   typedef uint8_t _utm_zone_char_type;
  _utm_zone_char_type utm_zone_char;

   typedef  ::ros_interface::Point3D_<ContainerAllocator>  _attitude_type;
  _attitude_type attitude;

   typedef  ::ros_interface::Point3D_<ContainerAllocator>  _linear_velocity_type;
  _linear_velocity_type linear_velocity;

   typedef  ::ros_interface::Point3D_<ContainerAllocator>  _sd_position_type;
  _sd_position_type sd_position;

   typedef  ::ros_interface::Point3D_<ContainerAllocator>  _sd_attitude_type;
  _sd_attitude_type sd_attitude;

   typedef  ::ros_interface::Point3D_<ContainerAllocator>  _sd_velocity_type;
  _sd_velocity_type sd_velocity;

   typedef double _cep68_type;
  _cep68_type cep68;

   typedef double _cep95_type;
  _cep95_type cep95;

   typedef double _second_type;
  _second_type second;

   typedef int32_t _sat_use_num_type;
  _sat_use_num_type sat_use_num;

   typedef int32_t _sat_in_view_num_type;
  _sat_in_view_num_type sat_in_view_num;

   typedef uint16_t _solution_status_type;
  _solution_status_type solution_status;

   typedef uint16_t _position_type_type;
  _position_type_type position_type;

   typedef double _p_dop_type;
  _p_dop_type p_dop;

   typedef double _h_dop_type;
  _h_dop_type h_dop;

   typedef double _v_dop_type;
  _v_dop_type v_dop;

   typedef  ::ros_interface::Point3D_<ContainerAllocator>  _attitude_dual_type;
  _attitude_dual_type attitude_dual;

   typedef  ::ros_interface::Point3D_<ContainerAllocator>  _sd_angle_dual_type;
  _sd_angle_dual_type sd_angle_dual;

   typedef double _base_line_length_dual_type;
  _base_line_length_dual_type base_line_length_dual;

   typedef int32_t _solution_status_dual_type;
  _solution_status_dual_type solution_status_dual;

   typedef int32_t _position_type_dual_type;
  _position_type_dual_type position_type_dual;

   typedef int32_t _solution_source_dual_type;
  _solution_source_dual_type solution_source_dual;

   typedef uint32_t _aoc_type;
  _aoc_type aoc;

   typedef uint32_t _rtk_baseline_type;
  _rtk_baseline_type rtk_baseline;

   typedef  ::ros_interface::Point3D_<ContainerAllocator>  _angular_velocity_type;
  _angular_velocity_type angular_velocity;

   typedef  ::ros_interface::Point3D_<ContainerAllocator>  _acceleration_type;
  _acceleration_type acceleration;





  typedef boost::shared_ptr< ::ros_interface::Ins_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::Ins_<ContainerAllocator> const> ConstPtr;

}; // struct Ins_

typedef ::ros_interface::Ins_<std::allocator<void> > Ins;

typedef boost::shared_ptr< ::ros_interface::Ins > InsPtr;
typedef boost::shared_ptr< ::ros_interface::Ins const> InsConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::Ins_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::Ins_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::Ins_<ContainerAllocator1> & lhs, const ::ros_interface::Ins_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.is_valid == rhs.is_valid &&
    lhs.latitude == rhs.latitude &&
    lhs.longitude == rhs.longitude &&
    lhs.elevation == rhs.elevation &&
    lhs.utm_position == rhs.utm_position &&
    lhs.utm_zone_mumber == rhs.utm_zone_mumber &&
    lhs.utm_zone_char == rhs.utm_zone_char &&
    lhs.attitude == rhs.attitude &&
    lhs.linear_velocity == rhs.linear_velocity &&
    lhs.sd_position == rhs.sd_position &&
    lhs.sd_attitude == rhs.sd_attitude &&
    lhs.sd_velocity == rhs.sd_velocity &&
    lhs.cep68 == rhs.cep68 &&
    lhs.cep95 == rhs.cep95 &&
    lhs.second == rhs.second &&
    lhs.sat_use_num == rhs.sat_use_num &&
    lhs.sat_in_view_num == rhs.sat_in_view_num &&
    lhs.solution_status == rhs.solution_status &&
    lhs.position_type == rhs.position_type &&
    lhs.p_dop == rhs.p_dop &&
    lhs.h_dop == rhs.h_dop &&
    lhs.v_dop == rhs.v_dop &&
    lhs.attitude_dual == rhs.attitude_dual &&
    lhs.sd_angle_dual == rhs.sd_angle_dual &&
    lhs.base_line_length_dual == rhs.base_line_length_dual &&
    lhs.solution_status_dual == rhs.solution_status_dual &&
    lhs.position_type_dual == rhs.position_type_dual &&
    lhs.solution_source_dual == rhs.solution_source_dual &&
    lhs.aoc == rhs.aoc &&
    lhs.rtk_baseline == rhs.rtk_baseline &&
    lhs.angular_velocity == rhs.angular_velocity &&
    lhs.acceleration == rhs.acceleration;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::Ins_<ContainerAllocator1> & lhs, const ::ros_interface::Ins_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::Ins_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::Ins_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::Ins_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::Ins_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::Ins_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::Ins_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::Ins_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a208bce72b0cc6abb54188331564ad26";
  }

  static const char* value(const ::ros_interface::Ins_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa208bce72b0cc6abULL;
  static const uint64_t static_value2 = 0xb54188331564ad26ULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::Ins_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/Ins";
  }

  static const char* value(const ::ros_interface::Ins_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::Ins_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header   header     # 头部信息\n"
"bool   is_valid     # 数据有效性标志位\n"
"float64   latitude     # 纬度信息\n"
"float64   longitude     # 经度信息\n"
"float64   elevation     # 海拔信息\n"
"Point3D   utm_position     # UTM坐标位置\n"
"int32   utm_zone_mumber     # UTM区号\n"
"uint8   utm_zone_char     # UTM区号\n"
"Point3D   attitude     # 三轴姿态\n"
"Point3D   linear_velocity     # 线速度信息\n"
"Point3D   sd_position     # 位置标准差\n"
"Point3D   sd_attitude     # 姿态标准差\n"
"Point3D   sd_velocity     # 速度标准差\n"
"float64   cep68     # cep68数据位\n"
"float64   cep95     # cep95数据位\n"
"float64   second     # 时间\n"
"int32   sat_use_num     # 使用卫星数\n"
"int32   sat_in_view_num     # 可见卫星数\n"
"uint16   solution_status     # 求解状态\n"
"uint16   position_type     # 定位状态\n"
"float64   p_dop     # pDop数据位\n"
"float64   h_dop     # hDop数据位\n"
"float64   v_dop     # vDop数据位\n"
"Point3D   attitude_dual     # 双天线姿态\n"
"Point3D   sd_angle_dual     # 双天线角度标准差\n"
"float64   base_line_length_dual     # 双天线距离\n"
"int32   solution_status_dual     # 双天线求解状态\n"
"int32   position_type_dual     # 双天线定位状态\n"
"int32   solution_source_dual     # 双天线求解源\n"
"uint32   aoc     # Aoc数据位\n"
"uint32   rtk_baseline     # RTK基线信息\n"
"Point3D   angular_velocity     # 角速度信息\n"
"Point3D   acceleration     # 加速度信息\n"
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
"MSG: ros_interface/Point3D\n"
"float64   x     # 位置坐标x\n"
"float64   y     # 位置坐标y\n"
"float64   z     # 位置坐标z\n"
;
  }

  static const char* value(const ::ros_interface::Ins_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::Ins_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.is_valid);
      stream.next(m.latitude);
      stream.next(m.longitude);
      stream.next(m.elevation);
      stream.next(m.utm_position);
      stream.next(m.utm_zone_mumber);
      stream.next(m.utm_zone_char);
      stream.next(m.attitude);
      stream.next(m.linear_velocity);
      stream.next(m.sd_position);
      stream.next(m.sd_attitude);
      stream.next(m.sd_velocity);
      stream.next(m.cep68);
      stream.next(m.cep95);
      stream.next(m.second);
      stream.next(m.sat_use_num);
      stream.next(m.sat_in_view_num);
      stream.next(m.solution_status);
      stream.next(m.position_type);
      stream.next(m.p_dop);
      stream.next(m.h_dop);
      stream.next(m.v_dop);
      stream.next(m.attitude_dual);
      stream.next(m.sd_angle_dual);
      stream.next(m.base_line_length_dual);
      stream.next(m.solution_status_dual);
      stream.next(m.position_type_dual);
      stream.next(m.solution_source_dual);
      stream.next(m.aoc);
      stream.next(m.rtk_baseline);
      stream.next(m.angular_velocity);
      stream.next(m.acceleration);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Ins_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::Ins_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::Ins_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "is_valid: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.is_valid);
    s << indent << "latitude: ";
    Printer<double>::stream(s, indent + "  ", v.latitude);
    s << indent << "longitude: ";
    Printer<double>::stream(s, indent + "  ", v.longitude);
    s << indent << "elevation: ";
    Printer<double>::stream(s, indent + "  ", v.elevation);
    s << indent << "utm_position: ";
    s << std::endl;
    Printer< ::ros_interface::Point3D_<ContainerAllocator> >::stream(s, indent + "  ", v.utm_position);
    s << indent << "utm_zone_mumber: ";
    Printer<int32_t>::stream(s, indent + "  ", v.utm_zone_mumber);
    s << indent << "utm_zone_char: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.utm_zone_char);
    s << indent << "attitude: ";
    s << std::endl;
    Printer< ::ros_interface::Point3D_<ContainerAllocator> >::stream(s, indent + "  ", v.attitude);
    s << indent << "linear_velocity: ";
    s << std::endl;
    Printer< ::ros_interface::Point3D_<ContainerAllocator> >::stream(s, indent + "  ", v.linear_velocity);
    s << indent << "sd_position: ";
    s << std::endl;
    Printer< ::ros_interface::Point3D_<ContainerAllocator> >::stream(s, indent + "  ", v.sd_position);
    s << indent << "sd_attitude: ";
    s << std::endl;
    Printer< ::ros_interface::Point3D_<ContainerAllocator> >::stream(s, indent + "  ", v.sd_attitude);
    s << indent << "sd_velocity: ";
    s << std::endl;
    Printer< ::ros_interface::Point3D_<ContainerAllocator> >::stream(s, indent + "  ", v.sd_velocity);
    s << indent << "cep68: ";
    Printer<double>::stream(s, indent + "  ", v.cep68);
    s << indent << "cep95: ";
    Printer<double>::stream(s, indent + "  ", v.cep95);
    s << indent << "second: ";
    Printer<double>::stream(s, indent + "  ", v.second);
    s << indent << "sat_use_num: ";
    Printer<int32_t>::stream(s, indent + "  ", v.sat_use_num);
    s << indent << "sat_in_view_num: ";
    Printer<int32_t>::stream(s, indent + "  ", v.sat_in_view_num);
    s << indent << "solution_status: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.solution_status);
    s << indent << "position_type: ";
    Printer<uint16_t>::stream(s, indent + "  ", v.position_type);
    s << indent << "p_dop: ";
    Printer<double>::stream(s, indent + "  ", v.p_dop);
    s << indent << "h_dop: ";
    Printer<double>::stream(s, indent + "  ", v.h_dop);
    s << indent << "v_dop: ";
    Printer<double>::stream(s, indent + "  ", v.v_dop);
    s << indent << "attitude_dual: ";
    s << std::endl;
    Printer< ::ros_interface::Point3D_<ContainerAllocator> >::stream(s, indent + "  ", v.attitude_dual);
    s << indent << "sd_angle_dual: ";
    s << std::endl;
    Printer< ::ros_interface::Point3D_<ContainerAllocator> >::stream(s, indent + "  ", v.sd_angle_dual);
    s << indent << "base_line_length_dual: ";
    Printer<double>::stream(s, indent + "  ", v.base_line_length_dual);
    s << indent << "solution_status_dual: ";
    Printer<int32_t>::stream(s, indent + "  ", v.solution_status_dual);
    s << indent << "position_type_dual: ";
    Printer<int32_t>::stream(s, indent + "  ", v.position_type_dual);
    s << indent << "solution_source_dual: ";
    Printer<int32_t>::stream(s, indent + "  ", v.solution_source_dual);
    s << indent << "aoc: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.aoc);
    s << indent << "rtk_baseline: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.rtk_baseline);
    s << indent << "angular_velocity: ";
    s << std::endl;
    Printer< ::ros_interface::Point3D_<ContainerAllocator> >::stream(s, indent + "  ", v.angular_velocity);
    s << indent << "acceleration: ";
    s << std::endl;
    Printer< ::ros_interface::Point3D_<ContainerAllocator> >::stream(s, indent + "  ", v.acceleration);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_INS_H
