// Generated by gencpp from file ros_interface/ObuCmd.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_OBUCMD_H
#define ROS_INTERFACE_MESSAGE_OBUCMD_H


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
struct ObuCmd_
{
  typedef ObuCmd_<ContainerAllocator> Type;

  ObuCmd_()
    : code(0)
    , val(0)  {
    }
  ObuCmd_(const ContainerAllocator& _alloc)
    : code(0)
    , val(0)  {
  (void)_alloc;
    }



   typedef int32_t _code_type;
  _code_type code;

   typedef int32_t _val_type;
  _val_type val;





  typedef boost::shared_ptr< ::ros_interface::ObuCmd_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::ObuCmd_<ContainerAllocator> const> ConstPtr;

}; // struct ObuCmd_

typedef ::ros_interface::ObuCmd_<std::allocator<void> > ObuCmd;

typedef boost::shared_ptr< ::ros_interface::ObuCmd > ObuCmdPtr;
typedef boost::shared_ptr< ::ros_interface::ObuCmd const> ObuCmdConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::ObuCmd_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::ObuCmd_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::ObuCmd_<ContainerAllocator1> & lhs, const ::ros_interface::ObuCmd_<ContainerAllocator2> & rhs)
{
  return lhs.code == rhs.code &&
    lhs.val == rhs.val;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::ObuCmd_<ContainerAllocator1> & lhs, const ::ros_interface::ObuCmd_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::ObuCmd_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::ObuCmd_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::ObuCmd_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::ObuCmd_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::ObuCmd_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::ObuCmd_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::ObuCmd_<ContainerAllocator> >
{
  static const char* value()
  {
    return "91ea1945ea9eb75814f68563f19c738f";
  }

  static const char* value(const ::ros_interface::ObuCmd_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x91ea1945ea9eb758ULL;
  static const uint64_t static_value2 = 0x14f68563f19c738fULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::ObuCmd_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/ObuCmd";
  }

  static const char* value(const ::ros_interface::ObuCmd_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::ObuCmd_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32   code     # 指令编码：10001、自动驾驶使能开关；\n"
"int32   val     # 编码值：0、不响应；1、自定义状态；2、自定义状态...（更多参考：“ObuCmdMsg.md”）\n"
;
  }

  static const char* value(const ::ros_interface::ObuCmd_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::ObuCmd_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.code);
      stream.next(m.val);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct ObuCmd_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::ObuCmd_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::ObuCmd_<ContainerAllocator>& v)
  {
    s << indent << "code: ";
    Printer<int32_t>::stream(s, indent + "  ", v.code);
    s << indent << "val: ";
    Printer<int32_t>::stream(s, indent + "  ", v.val);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_OBUCMD_H
