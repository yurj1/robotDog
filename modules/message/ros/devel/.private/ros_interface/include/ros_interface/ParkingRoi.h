// Generated by gencpp from file ros_interface/ParkingRoi.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_PARKINGROI_H
#define ROS_INTERFACE_MESSAGE_PARKINGROI_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <ros_interface/Point2dList.h>

namespace ros_interface
{
template <class ContainerAllocator>
struct ParkingRoi_
{
  typedef ParkingRoi_<ContainerAllocator> Type;

  ParkingRoi_()
    : header()
    , obstacles_vec()  {
    }
  ParkingRoi_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , obstacles_vec(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector< ::ros_interface::Point2dList_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::ros_interface::Point2dList_<ContainerAllocator> >> _obstacles_vec_type;
  _obstacles_vec_type obstacles_vec;





  typedef boost::shared_ptr< ::ros_interface::ParkingRoi_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::ParkingRoi_<ContainerAllocator> const> ConstPtr;

}; // struct ParkingRoi_

typedef ::ros_interface::ParkingRoi_<std::allocator<void> > ParkingRoi;

typedef boost::shared_ptr< ::ros_interface::ParkingRoi > ParkingRoiPtr;
typedef boost::shared_ptr< ::ros_interface::ParkingRoi const> ParkingRoiConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::ParkingRoi_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::ParkingRoi_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::ParkingRoi_<ContainerAllocator1> & lhs, const ::ros_interface::ParkingRoi_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.obstacles_vec == rhs.obstacles_vec;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::ParkingRoi_<ContainerAllocator1> & lhs, const ::ros_interface::ParkingRoi_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::ParkingRoi_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::ParkingRoi_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::ParkingRoi_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::ParkingRoi_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::ParkingRoi_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::ParkingRoi_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::ParkingRoi_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ebe8c02013248ccb80975a9d10310742";
  }

  static const char* value(const ::ros_interface::ParkingRoi_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xebe8c02013248ccbULL;
  static const uint64_t static_value2 = 0x80975a9d10310742ULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::ParkingRoi_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/ParkingRoi";
  }

  static const char* value(const ::ros_interface::ParkingRoi_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::ParkingRoi_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header   header     # 消息头\n"
"Point2dList[] obstacles_vec # 泊车可行驶区域可视化\n"
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
"MSG: ros_interface/Point2dList\n"
"Point2D[] point2d_list #  \n"
"\n"
"================================================================================\n"
"MSG: ros_interface/Point2D\n"
"float64   x     # 位置坐标x\n"
"float64   y     # 位置坐标y\n"
;
  }

  static const char* value(const ::ros_interface::ParkingRoi_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::ParkingRoi_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.obstacles_vec);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ParkingRoi_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::ParkingRoi_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::ParkingRoi_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "obstacles_vec[]" << std::endl;
    for (size_t i = 0; i < v.obstacles_vec.size(); ++i)
    {
      s << indent << "  obstacles_vec[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::ros_interface::Point2dList_<ContainerAllocator> >::stream(s, indent + "    ", v.obstacles_vec[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_PARKINGROI_H
