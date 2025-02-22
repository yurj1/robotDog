// Generated by gencpp from file ros_interface/RoutingRequest.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_ROUTINGREQUEST_H
#define ROS_INTERFACE_MESSAGE_ROUTINGREQUEST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <ros_interface/KeyPoint.h>

namespace ros_interface
{
template <class ContainerAllocator>
struct RoutingRequest_
{
  typedef RoutingRequest_<ContainerAllocator> Type;

  RoutingRequest_()
    : header()
    , request_source()
    , request_type(0)
    , num_of_kp(0)
    , key_point_list()  {
    }
  RoutingRequest_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , request_source(_alloc)
    , request_type(0)
    , num_of_kp(0)
    , key_point_list(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _request_source_type;
  _request_source_type request_source;

   typedef int8_t _request_type_type;
  _request_type_type request_type;

   typedef int16_t _num_of_kp_type;
  _num_of_kp_type num_of_kp;

   typedef std::vector< ::ros_interface::KeyPoint_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::ros_interface::KeyPoint_<ContainerAllocator> >> _key_point_list_type;
  _key_point_list_type key_point_list;





  typedef boost::shared_ptr< ::ros_interface::RoutingRequest_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::RoutingRequest_<ContainerAllocator> const> ConstPtr;

}; // struct RoutingRequest_

typedef ::ros_interface::RoutingRequest_<std::allocator<void> > RoutingRequest;

typedef boost::shared_ptr< ::ros_interface::RoutingRequest > RoutingRequestPtr;
typedef boost::shared_ptr< ::ros_interface::RoutingRequest const> RoutingRequestConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::RoutingRequest_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::RoutingRequest_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::RoutingRequest_<ContainerAllocator1> & lhs, const ::ros_interface::RoutingRequest_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.request_source == rhs.request_source &&
    lhs.request_type == rhs.request_type &&
    lhs.num_of_kp == rhs.num_of_kp &&
    lhs.key_point_list == rhs.key_point_list;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::RoutingRequest_<ContainerAllocator1> & lhs, const ::ros_interface::RoutingRequest_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::RoutingRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::RoutingRequest_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::RoutingRequest_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::RoutingRequest_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::RoutingRequest_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::RoutingRequest_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::RoutingRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "1771a80ac13a976ae23dbca9cd7f5386";
  }

  static const char* value(const ::ros_interface::RoutingRequest_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x1771a80ac13a976aULL;
  static const uint64_t static_value2 = 0xe23dbca9cd7f5386ULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::RoutingRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/RoutingRequest";
  }

  static const char* value(const ::ros_interface::RoutingRequest_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::RoutingRequest_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header   header     # timestamp is included in header\n"
"string   request_source     # 发起请求的来源名称\n"
"int8   request_type     # REQUEST_TYPE=0//无效 REQUEST_TYPE=1//正常路由 REQUEST_TYPE=2//泊车路由\n"
"int16   num_of_kp     # 关键点数量\n"
"KeyPoint[] key_point_list # 关键点列表，第一个为起点，最后一个为终点，中间为途经点\n"
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
"MSG: ros_interface/KeyPoint\n"
"int16   id     # 关键点id\n"
"float64   latitude     # 关键点纬度\n"
"float64   longitude     # 关键点经度\n"
"float64   ele     # 关键点海拔\n"
"float64   heading     # 关键点航向角（与北方向夹角，顺时针方向为正，单位为°）\n"
"string   name     # 关键点名称\n"
;
  }

  static const char* value(const ::ros_interface::RoutingRequest_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::RoutingRequest_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.request_source);
      stream.next(m.request_type);
      stream.next(m.num_of_kp);
      stream.next(m.key_point_list);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RoutingRequest_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::RoutingRequest_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::RoutingRequest_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "request_source: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.request_source);
    s << indent << "request_type: ";
    Printer<int8_t>::stream(s, indent + "  ", v.request_type);
    s << indent << "num_of_kp: ";
    Printer<int16_t>::stream(s, indent + "  ", v.num_of_kp);
    s << indent << "key_point_list[]" << std::endl;
    for (size_t i = 0; i < v.key_point_list.size(); ++i)
    {
      s << indent << "  key_point_list[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::ros_interface::KeyPoint_<ContainerAllocator> >::stream(s, indent + "    ", v.key_point_list[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_ROUTINGREQUEST_H
