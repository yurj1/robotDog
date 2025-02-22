// Generated by gencpp from file ros_interface/RoadMarkList.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_ROADMARKLIST_H
#define ROS_INTERFACE_MESSAGE_ROADMARKLIST_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <ros_interface/RoadMark.h>

namespace ros_interface
{
template <class ContainerAllocator>
struct RoadMarkList_
{
  typedef RoadMarkList_<ContainerAllocator> Type;

  RoadMarkList_()
    : header()
    , roadmarks()  {
    }
  RoadMarkList_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , roadmarks(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector< ::ros_interface::RoadMark_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::ros_interface::RoadMark_<ContainerAllocator> >> _roadmarks_type;
  _roadmarks_type roadmarks;





  typedef boost::shared_ptr< ::ros_interface::RoadMarkList_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::RoadMarkList_<ContainerAllocator> const> ConstPtr;

}; // struct RoadMarkList_

typedef ::ros_interface::RoadMarkList_<std::allocator<void> > RoadMarkList;

typedef boost::shared_ptr< ::ros_interface::RoadMarkList > RoadMarkListPtr;
typedef boost::shared_ptr< ::ros_interface::RoadMarkList const> RoadMarkListConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::RoadMarkList_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::RoadMarkList_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::RoadMarkList_<ContainerAllocator1> & lhs, const ::ros_interface::RoadMarkList_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.roadmarks == rhs.roadmarks;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::RoadMarkList_<ContainerAllocator1> & lhs, const ::ros_interface::RoadMarkList_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::RoadMarkList_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::RoadMarkList_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::RoadMarkList_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::RoadMarkList_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::RoadMarkList_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::RoadMarkList_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::RoadMarkList_<ContainerAllocator> >
{
  static const char* value()
  {
    return "167f3e013a1861ca3ba3feb2f5be99a4";
  }

  static const char* value(const ::ros_interface::RoadMarkList_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x167f3e013a1861caULL;
  static const uint64_t static_value2 = 0x3ba3feb2f5be99a4ULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::RoadMarkList_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/RoadMarkList";
  }

  static const char* value(const ::ros_interface::RoadMarkList_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::RoadMarkList_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header   header     # timestamp is included in header\n"
"RoadMark[] roadmarks # 交通标识列表\n"
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
"MSG: ros_interface/RoadMark\n"
"float64   longitude_dist     # 相对于车身坐标系原点的纵向距离,单位m\n"
"float64   lateral_dist     # 相对于车身坐标系原点的横向距离,单位m\n"
"float64   x     # 质心坐标x\n"
"float64   y     # 质心坐标y\n"
"float64   z     # 质心坐标z\n"
"float64   confidence     # 置信度[0 - 1]\n"
"int32   type     # 标识类型 1 - 停止线 2 - 斑马线 3 - 禁停区 4 - 直行箭头 5 - 左转箭头 6 - 右转箭头 7 - 直行+左转 8 - 直行+右转 9 - 直行+左转+右转 10 - 掉头 11 - 左掉头 12 - 菱形(前方有人行横道) 13 - 倒三角 (减速让行) 14 - 地面文字\n"
;
  }

  static const char* value(const ::ros_interface::RoadMarkList_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::RoadMarkList_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.roadmarks);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RoadMarkList_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::RoadMarkList_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::RoadMarkList_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "roadmarks[]" << std::endl;
    for (size_t i = 0; i < v.roadmarks.size(); ++i)
    {
      s << indent << "  roadmarks[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::ros_interface::RoadMark_<ContainerAllocator> >::stream(s, indent + "    ", v.roadmarks[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_ROADMARKLIST_H
