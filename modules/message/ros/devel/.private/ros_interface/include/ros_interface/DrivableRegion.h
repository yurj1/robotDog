// Generated by gencpp from file ros_interface/DrivableRegion.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_DRIVABLEREGION_H
#define ROS_INTERFACE_MESSAGE_DRIVABLEREGION_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <ros_interface/Polygon3D.h>

namespace ros_interface
{
template <class ContainerAllocator>
struct DrivableRegion_
{
  typedef DrivableRegion_<ContainerAllocator> Type;

  DrivableRegion_()
    : header()
    , drivable_region()  {
    }
  DrivableRegion_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , drivable_region(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef std::vector< ::ros_interface::Polygon3D_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::ros_interface::Polygon3D_<ContainerAllocator> >> _drivable_region_type;
  _drivable_region_type drivable_region;





  typedef boost::shared_ptr< ::ros_interface::DrivableRegion_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::DrivableRegion_<ContainerAllocator> const> ConstPtr;

}; // struct DrivableRegion_

typedef ::ros_interface::DrivableRegion_<std::allocator<void> > DrivableRegion;

typedef boost::shared_ptr< ::ros_interface::DrivableRegion > DrivableRegionPtr;
typedef boost::shared_ptr< ::ros_interface::DrivableRegion const> DrivableRegionConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::DrivableRegion_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::DrivableRegion_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::DrivableRegion_<ContainerAllocator1> & lhs, const ::ros_interface::DrivableRegion_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.drivable_region == rhs.drivable_region;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::DrivableRegion_<ContainerAllocator1> & lhs, const ::ros_interface::DrivableRegion_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::DrivableRegion_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::DrivableRegion_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::DrivableRegion_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::DrivableRegion_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::DrivableRegion_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::DrivableRegion_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::DrivableRegion_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c14f4161a36f4f3dbefbe28192146c82";
  }

  static const char* value(const ::ros_interface::DrivableRegion_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc14f4161a36f4f3dULL;
  static const uint64_t static_value2 = 0xbefbe28192146c82ULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::DrivableRegion_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/DrivableRegion";
  }

  static const char* value(const ::ros_interface::DrivableRegion_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::DrivableRegion_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header   header     # timestamp is included in header\n"
"Polygon3D[] drivable_region # 可行驶区域\n"
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
"MSG: ros_interface/Polygon3D\n"
"int32   coordinate_system     # 坐标系\n"
"Point3D[] points # 三维点集\n"
"\n"
"================================================================================\n"
"MSG: ros_interface/Point3D\n"
"float64   x     # 位置坐标x\n"
"float64   y     # 位置坐标y\n"
"float64   z     # 位置坐标z\n"
;
  }

  static const char* value(const ::ros_interface::DrivableRegion_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::DrivableRegion_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.drivable_region);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DrivableRegion_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::DrivableRegion_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::DrivableRegion_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "drivable_region[]" << std::endl;
    for (size_t i = 0; i < v.drivable_region.size(); ++i)
    {
      s << indent << "  drivable_region[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::ros_interface::Polygon3D_<ContainerAllocator> >::stream(s, indent + "    ", v.drivable_region[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_DRIVABLEREGION_H
