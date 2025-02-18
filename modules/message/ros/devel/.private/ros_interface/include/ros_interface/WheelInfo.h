// Generated by gencpp from file ros_interface/WheelInfo.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_WHEELINFO_H
#define ROS_INTERFACE_MESSAGE_WHEELINFO_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>

namespace ros_interface
{
template <class ContainerAllocator>
struct WheelInfo_
{
  typedef WheelInfo_<ContainerAllocator> Type;

  WheelInfo_()
    : header()
    , moving_status(0)
    , steer_driving_mode(0)
    , steering_value(0.0)
    , steering_torque_nm(0.0)
    , steering_rate_dps(0.0)
    , speed_mps(0.0)
    , veh_spd_vld(false)
    , gear(0)
    , gear_vld(false)
    , wheel_direction_rr(0)
    , wheel_spd_rr(0.0)
    , wheel_direction_rl(0)
    , wheel_spd_rl(0.0)
    , wheel_direction_fr(0)
    , wheel_spd_fr(0.0)
    , wheel_direction_fl(0)
    , wheel_spd_fl(0.0)
    , yaw_rate(0.0)
    , wss_fl_edges_sum(0)
    , wss_fr_edges_sum(0)
    , wss_rl_edges_sum(0)
    , wss_rr_edges_sum(0)
    , wss_fl_edges_sum_vld(false)
    , wss_fr_edges_sum_vld(false)
    , wss_rl_edges_sum_vld(false)
    , wss_rr_edges_sum_vld(false)
    , veh_lat_accel(0.0)
    , veh_lgt_accel(0.0)
    , veh_lat_accel_vld(false)
    , veh_lgt_accel_vld(false)  {
    }
  WheelInfo_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , moving_status(0)
    , steer_driving_mode(0)
    , steering_value(0.0)
    , steering_torque_nm(0.0)
    , steering_rate_dps(0.0)
    , speed_mps(0.0)
    , veh_spd_vld(false)
    , gear(0)
    , gear_vld(false)
    , wheel_direction_rr(0)
    , wheel_spd_rr(0.0)
    , wheel_direction_rl(0)
    , wheel_spd_rl(0.0)
    , wheel_direction_fr(0)
    , wheel_spd_fr(0.0)
    , wheel_direction_fl(0)
    , wheel_spd_fl(0.0)
    , yaw_rate(0.0)
    , wss_fl_edges_sum(0)
    , wss_fr_edges_sum(0)
    , wss_rl_edges_sum(0)
    , wss_rr_edges_sum(0)
    , wss_fl_edges_sum_vld(false)
    , wss_fr_edges_sum_vld(false)
    , wss_rl_edges_sum_vld(false)
    , wss_rr_edges_sum_vld(false)
    , veh_lat_accel(0.0)
    , veh_lgt_accel(0.0)
    , veh_lat_accel_vld(false)
    , veh_lgt_accel_vld(false)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef int32_t _moving_status_type;
  _moving_status_type moving_status;

   typedef int32_t _steer_driving_mode_type;
  _steer_driving_mode_type steer_driving_mode;

   typedef double _steering_value_type;
  _steering_value_type steering_value;

   typedef double _steering_torque_nm_type;
  _steering_torque_nm_type steering_torque_nm;

   typedef double _steering_rate_dps_type;
  _steering_rate_dps_type steering_rate_dps;

   typedef double _speed_mps_type;
  _speed_mps_type speed_mps;

   typedef uint8_t _veh_spd_vld_type;
  _veh_spd_vld_type veh_spd_vld;

   typedef int32_t _gear_type;
  _gear_type gear;

   typedef uint8_t _gear_vld_type;
  _gear_vld_type gear_vld;

   typedef int32_t _wheel_direction_rr_type;
  _wheel_direction_rr_type wheel_direction_rr;

   typedef double _wheel_spd_rr_type;
  _wheel_spd_rr_type wheel_spd_rr;

   typedef int32_t _wheel_direction_rl_type;
  _wheel_direction_rl_type wheel_direction_rl;

   typedef double _wheel_spd_rl_type;
  _wheel_spd_rl_type wheel_spd_rl;

   typedef int32_t _wheel_direction_fr_type;
  _wheel_direction_fr_type wheel_direction_fr;

   typedef double _wheel_spd_fr_type;
  _wheel_spd_fr_type wheel_spd_fr;

   typedef int32_t _wheel_direction_fl_type;
  _wheel_direction_fl_type wheel_direction_fl;

   typedef double _wheel_spd_fl_type;
  _wheel_spd_fl_type wheel_spd_fl;

   typedef double _yaw_rate_type;
  _yaw_rate_type yaw_rate;

   typedef int32_t _wss_fl_edges_sum_type;
  _wss_fl_edges_sum_type wss_fl_edges_sum;

   typedef int32_t _wss_fr_edges_sum_type;
  _wss_fr_edges_sum_type wss_fr_edges_sum;

   typedef int32_t _wss_rl_edges_sum_type;
  _wss_rl_edges_sum_type wss_rl_edges_sum;

   typedef int32_t _wss_rr_edges_sum_type;
  _wss_rr_edges_sum_type wss_rr_edges_sum;

   typedef uint8_t _wss_fl_edges_sum_vld_type;
  _wss_fl_edges_sum_vld_type wss_fl_edges_sum_vld;

   typedef uint8_t _wss_fr_edges_sum_vld_type;
  _wss_fr_edges_sum_vld_type wss_fr_edges_sum_vld;

   typedef uint8_t _wss_rl_edges_sum_vld_type;
  _wss_rl_edges_sum_vld_type wss_rl_edges_sum_vld;

   typedef uint8_t _wss_rr_edges_sum_vld_type;
  _wss_rr_edges_sum_vld_type wss_rr_edges_sum_vld;

   typedef double _veh_lat_accel_type;
  _veh_lat_accel_type veh_lat_accel;

   typedef double _veh_lgt_accel_type;
  _veh_lgt_accel_type veh_lgt_accel;

   typedef uint8_t _veh_lat_accel_vld_type;
  _veh_lat_accel_vld_type veh_lat_accel_vld;

   typedef uint8_t _veh_lgt_accel_vld_type;
  _veh_lgt_accel_vld_type veh_lgt_accel_vld;





  typedef boost::shared_ptr< ::ros_interface::WheelInfo_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::WheelInfo_<ContainerAllocator> const> ConstPtr;

}; // struct WheelInfo_

typedef ::ros_interface::WheelInfo_<std::allocator<void> > WheelInfo;

typedef boost::shared_ptr< ::ros_interface::WheelInfo > WheelInfoPtr;
typedef boost::shared_ptr< ::ros_interface::WheelInfo const> WheelInfoConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::WheelInfo_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::WheelInfo_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::WheelInfo_<ContainerAllocator1> & lhs, const ::ros_interface::WheelInfo_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.moving_status == rhs.moving_status &&
    lhs.steer_driving_mode == rhs.steer_driving_mode &&
    lhs.steering_value == rhs.steering_value &&
    lhs.steering_torque_nm == rhs.steering_torque_nm &&
    lhs.steering_rate_dps == rhs.steering_rate_dps &&
    lhs.speed_mps == rhs.speed_mps &&
    lhs.veh_spd_vld == rhs.veh_spd_vld &&
    lhs.gear == rhs.gear &&
    lhs.gear_vld == rhs.gear_vld &&
    lhs.wheel_direction_rr == rhs.wheel_direction_rr &&
    lhs.wheel_spd_rr == rhs.wheel_spd_rr &&
    lhs.wheel_direction_rl == rhs.wheel_direction_rl &&
    lhs.wheel_spd_rl == rhs.wheel_spd_rl &&
    lhs.wheel_direction_fr == rhs.wheel_direction_fr &&
    lhs.wheel_spd_fr == rhs.wheel_spd_fr &&
    lhs.wheel_direction_fl == rhs.wheel_direction_fl &&
    lhs.wheel_spd_fl == rhs.wheel_spd_fl &&
    lhs.yaw_rate == rhs.yaw_rate &&
    lhs.wss_fl_edges_sum == rhs.wss_fl_edges_sum &&
    lhs.wss_fr_edges_sum == rhs.wss_fr_edges_sum &&
    lhs.wss_rl_edges_sum == rhs.wss_rl_edges_sum &&
    lhs.wss_rr_edges_sum == rhs.wss_rr_edges_sum &&
    lhs.wss_fl_edges_sum_vld == rhs.wss_fl_edges_sum_vld &&
    lhs.wss_fr_edges_sum_vld == rhs.wss_fr_edges_sum_vld &&
    lhs.wss_rl_edges_sum_vld == rhs.wss_rl_edges_sum_vld &&
    lhs.wss_rr_edges_sum_vld == rhs.wss_rr_edges_sum_vld &&
    lhs.veh_lat_accel == rhs.veh_lat_accel &&
    lhs.veh_lgt_accel == rhs.veh_lgt_accel &&
    lhs.veh_lat_accel_vld == rhs.veh_lat_accel_vld &&
    lhs.veh_lgt_accel_vld == rhs.veh_lgt_accel_vld;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::WheelInfo_<ContainerAllocator1> & lhs, const ::ros_interface::WheelInfo_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::WheelInfo_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::WheelInfo_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::WheelInfo_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::WheelInfo_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::WheelInfo_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::WheelInfo_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::WheelInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "89a45d7281d30b62ae7cbb5f0d17e21a";
  }

  static const char* value(const ::ros_interface::WheelInfo_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x89a45d7281d30b62ULL;
  static const uint64_t static_value2 = 0xae7cbb5f0d17e21aULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::WheelInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/WheelInfo";
  }

  static const char* value(const ::ros_interface::WheelInfo_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::WheelInfo_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header   header     #  \n"
"int32   moving_status     # 0=UNKNOWN_VEHICLE_STATE  1=STATIONARY  2=MOVING_FORWARD  3=MOVING_BACKWARD\n"
"int32   steer_driving_mode     # 0=COMPLETE_MANUAL  1=COMPLETE_AUTO_DRIVE  4=EMERGENCY_MODE\n"
"float64   steering_value     # Real steering location\n"
"float64   steering_torque_nm     # Applied steering torque in [Nm]\n"
"float64   steering_rate_dps     # degree/s\n"
"float64   speed_mps     # Vehicle Speed in meters per second\n"
"bool   veh_spd_vld     # 车速有效性\n"
"int32   gear     # 档位\n"
"bool   gear_vld     # 档位有效性\n"
"int32   wheel_direction_rr     # 0=FORWARD 1=BACKWARD 2=STANDSTILL 3=INVALID\n"
"float64   wheel_spd_rr     # Actual speed of the right rear wheel\n"
"int32   wheel_direction_rl     # 0=FORWARD 1=BACKWARD 2=STANDSTILL 3=INVALID\n"
"float64   wheel_spd_rl     # Actual speed of the left rear wheel\n"
"int32   wheel_direction_fr     # 0=FORWARD 1=BACKWARD 2=STANDSTILL 3=INVALID\n"
"float64   wheel_spd_fr     # Actual speed of the right front wheel\n"
"int32   wheel_direction_fl     # 0=FORWARD 1=BACKWARD 2=STANDSTILL 3=INVALID\n"
"float64   wheel_spd_fl     # Actual speed of the left front wheel\n"
"float64   yaw_rate     # Yaw rate[degree/s] [-163.84|163.835]\n"
"int32   wss_fl_edges_sum     # 左前轮边缘和\n"
"int32   wss_fr_edges_sum     # 右前轮边缘和\n"
"int32   wss_rl_edges_sum     # 左后轮边缘和\n"
"int32   wss_rr_edges_sum     # 右后轮边缘和\n"
"bool   wss_fl_edges_sum_vld     # 左前轮边缘和有效位（0：无效 1：有效）\n"
"bool   wss_fr_edges_sum_vld     # 右前轮边缘和有效位（0：无效 1：有效）\n"
"bool   wss_rl_edges_sum_vld     # 左后轮边缘和有效位（0：无效 1：有效）\n"
"bool   wss_rr_edges_sum_vld     # 右后轮边缘和有效位（0：无效 1：有效）\n"
"float64   veh_lat_accel     # 车辆横向加速度\n"
"float64   veh_lgt_accel     # 车辆纵向加速度\n"
"bool   veh_lat_accel_vld     # 车辆横向加速度有效性\n"
"bool   veh_lgt_accel_vld     # 车辆纵向加速度有效性\n"
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
;
  }

  static const char* value(const ::ros_interface::WheelInfo_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::WheelInfo_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.moving_status);
      stream.next(m.steer_driving_mode);
      stream.next(m.steering_value);
      stream.next(m.steering_torque_nm);
      stream.next(m.steering_rate_dps);
      stream.next(m.speed_mps);
      stream.next(m.veh_spd_vld);
      stream.next(m.gear);
      stream.next(m.gear_vld);
      stream.next(m.wheel_direction_rr);
      stream.next(m.wheel_spd_rr);
      stream.next(m.wheel_direction_rl);
      stream.next(m.wheel_spd_rl);
      stream.next(m.wheel_direction_fr);
      stream.next(m.wheel_spd_fr);
      stream.next(m.wheel_direction_fl);
      stream.next(m.wheel_spd_fl);
      stream.next(m.yaw_rate);
      stream.next(m.wss_fl_edges_sum);
      stream.next(m.wss_fr_edges_sum);
      stream.next(m.wss_rl_edges_sum);
      stream.next(m.wss_rr_edges_sum);
      stream.next(m.wss_fl_edges_sum_vld);
      stream.next(m.wss_fr_edges_sum_vld);
      stream.next(m.wss_rl_edges_sum_vld);
      stream.next(m.wss_rr_edges_sum_vld);
      stream.next(m.veh_lat_accel);
      stream.next(m.veh_lgt_accel);
      stream.next(m.veh_lat_accel_vld);
      stream.next(m.veh_lgt_accel_vld);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct WheelInfo_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::WheelInfo_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::WheelInfo_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "moving_status: ";
    Printer<int32_t>::stream(s, indent + "  ", v.moving_status);
    s << indent << "steer_driving_mode: ";
    Printer<int32_t>::stream(s, indent + "  ", v.steer_driving_mode);
    s << indent << "steering_value: ";
    Printer<double>::stream(s, indent + "  ", v.steering_value);
    s << indent << "steering_torque_nm: ";
    Printer<double>::stream(s, indent + "  ", v.steering_torque_nm);
    s << indent << "steering_rate_dps: ";
    Printer<double>::stream(s, indent + "  ", v.steering_rate_dps);
    s << indent << "speed_mps: ";
    Printer<double>::stream(s, indent + "  ", v.speed_mps);
    s << indent << "veh_spd_vld: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.veh_spd_vld);
    s << indent << "gear: ";
    Printer<int32_t>::stream(s, indent + "  ", v.gear);
    s << indent << "gear_vld: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.gear_vld);
    s << indent << "wheel_direction_rr: ";
    Printer<int32_t>::stream(s, indent + "  ", v.wheel_direction_rr);
    s << indent << "wheel_spd_rr: ";
    Printer<double>::stream(s, indent + "  ", v.wheel_spd_rr);
    s << indent << "wheel_direction_rl: ";
    Printer<int32_t>::stream(s, indent + "  ", v.wheel_direction_rl);
    s << indent << "wheel_spd_rl: ";
    Printer<double>::stream(s, indent + "  ", v.wheel_spd_rl);
    s << indent << "wheel_direction_fr: ";
    Printer<int32_t>::stream(s, indent + "  ", v.wheel_direction_fr);
    s << indent << "wheel_spd_fr: ";
    Printer<double>::stream(s, indent + "  ", v.wheel_spd_fr);
    s << indent << "wheel_direction_fl: ";
    Printer<int32_t>::stream(s, indent + "  ", v.wheel_direction_fl);
    s << indent << "wheel_spd_fl: ";
    Printer<double>::stream(s, indent + "  ", v.wheel_spd_fl);
    s << indent << "yaw_rate: ";
    Printer<double>::stream(s, indent + "  ", v.yaw_rate);
    s << indent << "wss_fl_edges_sum: ";
    Printer<int32_t>::stream(s, indent + "  ", v.wss_fl_edges_sum);
    s << indent << "wss_fr_edges_sum: ";
    Printer<int32_t>::stream(s, indent + "  ", v.wss_fr_edges_sum);
    s << indent << "wss_rl_edges_sum: ";
    Printer<int32_t>::stream(s, indent + "  ", v.wss_rl_edges_sum);
    s << indent << "wss_rr_edges_sum: ";
    Printer<int32_t>::stream(s, indent + "  ", v.wss_rr_edges_sum);
    s << indent << "wss_fl_edges_sum_vld: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.wss_fl_edges_sum_vld);
    s << indent << "wss_fr_edges_sum_vld: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.wss_fr_edges_sum_vld);
    s << indent << "wss_rl_edges_sum_vld: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.wss_rl_edges_sum_vld);
    s << indent << "wss_rr_edges_sum_vld: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.wss_rr_edges_sum_vld);
    s << indent << "veh_lat_accel: ";
    Printer<double>::stream(s, indent + "  ", v.veh_lat_accel);
    s << indent << "veh_lgt_accel: ";
    Printer<double>::stream(s, indent + "  ", v.veh_lgt_accel);
    s << indent << "veh_lat_accel_vld: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.veh_lat_accel_vld);
    s << indent << "veh_lgt_accel_vld: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.veh_lgt_accel_vld);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_WHEELINFO_H
