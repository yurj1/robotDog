// Generated by gencpp from file ros_interface/Fault.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_FAULT_H
#define ROS_INTERFACE_MESSAGE_FAULT_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <ros_interface/Time.h>

namespace ros_interface
{
template <class ContainerAllocator>
struct Fault_
{
  typedef Fault_<ContainerAllocator> Type;

  Fault_()
    : timestamp()
    , code(0)
    , reason()  {
    }
  Fault_(const ContainerAllocator& _alloc)
    : timestamp(_alloc)
    , code(0)
    , reason(_alloc)  {
  (void)_alloc;
    }



   typedef  ::ros_interface::Time_<ContainerAllocator>  _timestamp_type;
  _timestamp_type timestamp;

   typedef uint64_t _code_type;
  _code_type code;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _reason_type;
  _reason_type reason;





  typedef boost::shared_ptr< ::ros_interface::Fault_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::Fault_<ContainerAllocator> const> ConstPtr;

}; // struct Fault_

typedef ::ros_interface::Fault_<std::allocator<void> > Fault;

typedef boost::shared_ptr< ::ros_interface::Fault > FaultPtr;
typedef boost::shared_ptr< ::ros_interface::Fault const> FaultConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::Fault_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::Fault_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::Fault_<ContainerAllocator1> & lhs, const ::ros_interface::Fault_<ContainerAllocator2> & rhs)
{
  return lhs.timestamp == rhs.timestamp &&
    lhs.code == rhs.code &&
    lhs.reason == rhs.reason;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::Fault_<ContainerAllocator1> & lhs, const ::ros_interface::Fault_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::Fault_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::Fault_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::Fault_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::Fault_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::Fault_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::Fault_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::Fault_<ContainerAllocator> >
{
  static const char* value()
  {
    return "e0cea8990aa7abb79c265ed7ac636c6d";
  }

  static const char* value(const ::ros_interface::Fault_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xe0cea8990aa7abb7ULL;
  static const uint64_t static_value2 = 0x9c265ed7ac636c6dULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::Fault_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/Fault";
  }

  static const char* value(const ::ros_interface::Fault_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::Fault_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Time   timestamp     # 时间戳\n"
"uint64   code     # 故障码\n"
"string   reason     # 原因\n"
"\n"
"================================================================================\n"
"MSG: ros_interface/Time\n"
"uint32   sec     # 秒\n"
"uint32   nsec     # 纳秒\n"
;
  }

  static const char* value(const ::ros_interface::Fault_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::Fault_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.timestamp);
      stream.next(m.code);
      stream.next(m.reason);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Fault_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::Fault_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::Fault_<ContainerAllocator>& v)
  {
    s << indent << "timestamp: ";
    s << std::endl;
    Printer< ::ros_interface::Time_<ContainerAllocator> >::stream(s, indent + "  ", v.timestamp);
    s << indent << "code: ";
    Printer<uint64_t>::stream(s, indent + "  ", v.code);
    s << indent << "reason: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.reason);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_FAULT_H
