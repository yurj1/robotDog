// Generated by gencpp from file ros_interface/RoutingResponse.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_ROUTINGRESPONSE_H
#define ROS_INTERFACE_MESSAGE_ROUTINGRESPONSE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <ros_interface/LaneInfo.h>

namespace ros_interface
{
template <class ContainerAllocator>
struct RoutingResponse_
{
  typedef RoutingResponse_<ContainerAllocator> Type;

  RoutingResponse_()
    : header()
    , plan_status(0)
    , replan_flag(0)
    , route_reason(0)
    , lane_list()  {
    }
  RoutingResponse_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , plan_status(0)
    , replan_flag(0)
    , route_reason(0)
    , lane_list(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef int32_t _plan_status_type;
  _plan_status_type plan_status;

   typedef int32_t _replan_flag_type;
  _replan_flag_type replan_flag;

   typedef int32_t _route_reason_type;
  _route_reason_type route_reason;

   typedef std::vector< ::ros_interface::LaneInfo_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::ros_interface::LaneInfo_<ContainerAllocator> >> _lane_list_type;
  _lane_list_type lane_list;





  typedef boost::shared_ptr< ::ros_interface::RoutingResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::RoutingResponse_<ContainerAllocator> const> ConstPtr;

}; // struct RoutingResponse_

typedef ::ros_interface::RoutingResponse_<std::allocator<void> > RoutingResponse;

typedef boost::shared_ptr< ::ros_interface::RoutingResponse > RoutingResponsePtr;
typedef boost::shared_ptr< ::ros_interface::RoutingResponse const> RoutingResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::RoutingResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::RoutingResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::RoutingResponse_<ContainerAllocator1> & lhs, const ::ros_interface::RoutingResponse_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.plan_status == rhs.plan_status &&
    lhs.replan_flag == rhs.replan_flag &&
    lhs.route_reason == rhs.route_reason &&
    lhs.lane_list == rhs.lane_list;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::RoutingResponse_<ContainerAllocator1> & lhs, const ::ros_interface::RoutingResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::RoutingResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::RoutingResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::RoutingResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::RoutingResponse_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::RoutingResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::RoutingResponse_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::RoutingResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "15cd52a06ebf7f4a70dca47308a3032d";
  }

  static const char* value(const ::ros_interface::RoutingResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x15cd52a06ebf7f4aULL;
  static const uint64_t static_value2 = 0x70dca47308a3032dULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::RoutingResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/RoutingResponse";
  }

  static const char* value(const ::ros_interface::RoutingResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::RoutingResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header   header     # timestamp is included in header\n"
"int32   plan_status     # 规划结果状态\n"
"int32   replan_flag     # REPLAN_FLAG_NONE=0  //不需要重规划 REPLAN_FLAG_NAVI=1 //网络层重规划 REPLAN_FLAG_HUMAN=2 //人为重规划\n"
"int32   route_reason     # 规划原因 ROUTE_REASON_HMI = 0 //hmi上触发规划 ROUTE_REASON_PLATOON_HEADER = 1 //车队头车下发规划 ROUTE_REASON_PLATOON_OTHER = 2 //车队其他车辆下发规划\n"
"LaneInfo[] lane_list # 分段路径规划结果\n"
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
"MSG: ros_interface/LaneInfo\n"
"int8   priority     # 道路优先级\n"
"int8   global_id     # 道路全局id（从左至右，从0开始）\n"
"int8   predecessor_id     # 上一车道id\n"
"int8   successor_id     # 下一车道id\n"
"int8   left_neighbor_id     # 左边相邻车道id\n"
"int8   right_neighbor_id     # 右边相邻车道id\n"
"int8   type     # 类型（预留）\n"
"LanePoint[] lane_points # 道路参考线（z）\n"
"\n"
"================================================================================\n"
"MSG: ros_interface/LanePoint\n"
"Point3D   point     # 点xyz\n"
"float64   theta     # 方向（与东方向夹角，逆时针方向为正，单位为弧度）\n"
"float64   mileage     # 总体里程\n"
"float64   limit_speed     # 地图限速（单位m/s）\n"
"float64   left_road_width     # 左边车道宽\n"
"float64   right_road_width     # 右边车道宽\n"
"int32   left_line_type     # 左边车线线型\n"
"int32   right_line_type     # 右边车线线型\n"
"\n"
"================================================================================\n"
"MSG: ros_interface/Point3D\n"
"float64   x     # 位置坐标x\n"
"float64   y     # 位置坐标y\n"
"float64   z     # 位置坐标z\n"
;
  }

  static const char* value(const ::ros_interface::RoutingResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::RoutingResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.plan_status);
      stream.next(m.replan_flag);
      stream.next(m.route_reason);
      stream.next(m.lane_list);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RoutingResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::RoutingResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::RoutingResponse_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "plan_status: ";
    Printer<int32_t>::stream(s, indent + "  ", v.plan_status);
    s << indent << "replan_flag: ";
    Printer<int32_t>::stream(s, indent + "  ", v.replan_flag);
    s << indent << "route_reason: ";
    Printer<int32_t>::stream(s, indent + "  ", v.route_reason);
    s << indent << "lane_list[]" << std::endl;
    for (size_t i = 0; i < v.lane_list.size(); ++i)
    {
      s << indent << "  lane_list[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::ros_interface::LaneInfo_<ContainerAllocator> >::stream(s, indent + "    ", v.lane_list[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_ROUTINGRESPONSE_H
