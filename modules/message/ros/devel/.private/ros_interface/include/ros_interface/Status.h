// Generated by gencpp from file ros_interface/Status.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_STATUS_H
#define ROS_INTERFACE_MESSAGE_STATUS_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace ros_interface
{
template <class ContainerAllocator>
struct Status_
{
  typedef Status_<ContainerAllocator> Type;

  Status_()
    : error_code(0)
    , msg()  {
    }
  Status_(const ContainerAllocator& _alloc)
    : error_code(0)
    , msg(_alloc)  {
  (void)_alloc;
    }



   typedef int32_t _error_code_type;
  _error_code_type error_code;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _msg_type;
  _msg_type msg;





  typedef boost::shared_ptr< ::ros_interface::Status_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::Status_<ContainerAllocator> const> ConstPtr;

}; // struct Status_

typedef ::ros_interface::Status_<std::allocator<void> > Status;

typedef boost::shared_ptr< ::ros_interface::Status > StatusPtr;
typedef boost::shared_ptr< ::ros_interface::Status const> StatusConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::Status_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::Status_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::Status_<ContainerAllocator1> & lhs, const ::ros_interface::Status_<ContainerAllocator2> & rhs)
{
  return lhs.error_code == rhs.error_code &&
    lhs.msg == rhs.msg;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::Status_<ContainerAllocator1> & lhs, const ::ros_interface::Status_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::Status_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::Status_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::Status_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::Status_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::Status_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::Status_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::Status_<ContainerAllocator> >
{
  static const char* value()
  {
    return "762fba2d8d55ed14d51a08c9479679ed";
  }

  static const char* value(const ::ros_interface::Status_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x762fba2d8d55ed14ULL;
  static const uint64_t static_value2 = 0xd51a08c9479679edULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::Status_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/Status";
  }

  static const char* value(const ::ros_interface::Status_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::Status_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32   error_code     # 错误码\n"
"string   msg     # 错误码描述\n"
;
  }

  static const char* value(const ::ros_interface::Status_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::Status_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.error_code);
      stream.next(m.msg);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Status_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::Status_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::Status_<ContainerAllocator>& v)
  {
    s << indent << "error_code: ";
    Printer<int32_t>::stream(s, indent + "  ", v.error_code);
    s << indent << "msg: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.msg);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_STATUS_H
