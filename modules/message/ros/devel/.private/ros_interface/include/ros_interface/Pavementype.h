// Generated by gencpp from file ros_interface/Pavementype.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_PAVEMENTYPE_H
#define ROS_INTERFACE_MESSAGE_PAVEMENTYPE_H


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
struct Pavementype_
{
  typedef Pavementype_<ContainerAllocator> Type;

  Pavementype_()
    : header()
    , type(0)
    , confidence(0.0)  {
    }
  Pavementype_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , type(0)
    , confidence(0.0)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

   typedef int32_t _type_type;
  _type_type type;

   typedef double _confidence_type;
  _confidence_type confidence;





  typedef boost::shared_ptr< ::ros_interface::Pavementype_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::Pavementype_<ContainerAllocator> const> ConstPtr;

}; // struct Pavementype_

typedef ::ros_interface::Pavementype_<std::allocator<void> > Pavementype;

typedef boost::shared_ptr< ::ros_interface::Pavementype > PavementypePtr;
typedef boost::shared_ptr< ::ros_interface::Pavementype const> PavementypeConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::Pavementype_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::Pavementype_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::Pavementype_<ContainerAllocator1> & lhs, const ::ros_interface::Pavementype_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.type == rhs.type &&
    lhs.confidence == rhs.confidence;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::Pavementype_<ContainerAllocator1> & lhs, const ::ros_interface::Pavementype_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::Pavementype_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::Pavementype_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::Pavementype_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::Pavementype_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::Pavementype_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::Pavementype_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::Pavementype_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2ba57874d7cb9b2d8f6f058b753342d8";
  }

  static const char* value(const ::ros_interface::Pavementype_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2ba57874d7cb9b2dULL;
  static const uint64_t static_value2 = 0x8f6f058b753342d8ULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::Pavementype_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/Pavementype";
  }

  static const char* value(const ::ros_interface::Pavementype_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::Pavementype_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header   header     # 消息头\n"
"int32   type     # 0-沥青 1-水泥 2-雪地 3-草地 4-泥地 5-沙地\n"
"float64   confidence     # 置信度\n"
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

  static const char* value(const ::ros_interface::Pavementype_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::Pavementype_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.type);
      stream.next(m.confidence);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Pavementype_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::Pavementype_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::Pavementype_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
    s << indent << "type: ";
    Printer<int32_t>::stream(s, indent + "  ", v.type);
    s << indent << "confidence: ";
    Printer<double>::stream(s, indent + "  ", v.confidence);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_PAVEMENTYPE_H
