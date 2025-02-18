// Generated by gencpp from file ros_interface/HMIDiagnosticStatus.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_HMIDIAGNOSTICSTATUS_H
#define ROS_INTERFACE_MESSAGE_HMIDIAGNOSTICSTATUS_H


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
struct HMIDiagnosticStatus_
{
  typedef HMIDiagnosticStatus_<ContainerAllocator> Type;

  HMIDiagnosticStatus_()
    : id(0)
    , level(0)
    , name()
    , message()
    , hardware_id()  {
    }
  HMIDiagnosticStatus_(const ContainerAllocator& _alloc)
    : id(0)
    , level(0)
    , name(_alloc)
    , message(_alloc)
    , hardware_id(_alloc)  {
  (void)_alloc;
    }



   typedef int32_t _id_type;
  _id_type id;

   typedef int32_t _level_type;
  _level_type level;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _name_type;
  _name_type name;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _message_type;
  _message_type message;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _hardware_id_type;
  _hardware_id_type hardware_id;





  typedef boost::shared_ptr< ::ros_interface::HMIDiagnosticStatus_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::HMIDiagnosticStatus_<ContainerAllocator> const> ConstPtr;

}; // struct HMIDiagnosticStatus_

typedef ::ros_interface::HMIDiagnosticStatus_<std::allocator<void> > HMIDiagnosticStatus;

typedef boost::shared_ptr< ::ros_interface::HMIDiagnosticStatus > HMIDiagnosticStatusPtr;
typedef boost::shared_ptr< ::ros_interface::HMIDiagnosticStatus const> HMIDiagnosticStatusConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::HMIDiagnosticStatus_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::HMIDiagnosticStatus_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::HMIDiagnosticStatus_<ContainerAllocator1> & lhs, const ::ros_interface::HMIDiagnosticStatus_<ContainerAllocator2> & rhs)
{
  return lhs.id == rhs.id &&
    lhs.level == rhs.level &&
    lhs.name == rhs.name &&
    lhs.message == rhs.message &&
    lhs.hardware_id == rhs.hardware_id;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::HMIDiagnosticStatus_<ContainerAllocator1> & lhs, const ::ros_interface::HMIDiagnosticStatus_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::HMIDiagnosticStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::HMIDiagnosticStatus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::HMIDiagnosticStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::HMIDiagnosticStatus_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::HMIDiagnosticStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::HMIDiagnosticStatus_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::HMIDiagnosticStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "857f32f3eaa106a1f8ebfcfe253beedb";
  }

  static const char* value(const ::ros_interface::HMIDiagnosticStatus_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x857f32f3eaa106a1ULL;
  static const uint64_t static_value2 = 0xf8ebfcfe253beedbULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::HMIDiagnosticStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/HMIDiagnosticStatus";
  }

  static const char* value(const ::ros_interface::HMIDiagnosticStatus_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::HMIDiagnosticStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32   id     #  \n"
"int32   level     # // 诊断状态\n"
"string   name     # //测试/组件报告的描述\n"
"string   message     # // 状态描述\n"
"string   hardware_id     # // 硬件的唯一描述\n"
;
  }

  static const char* value(const ::ros_interface::HMIDiagnosticStatus_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::HMIDiagnosticStatus_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.id);
      stream.next(m.level);
      stream.next(m.name);
      stream.next(m.message);
      stream.next(m.hardware_id);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct HMIDiagnosticStatus_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::HMIDiagnosticStatus_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::HMIDiagnosticStatus_<ContainerAllocator>& v)
  {
    s << indent << "id: ";
    Printer<int32_t>::stream(s, indent + "  ", v.id);
    s << indent << "level: ";
    Printer<int32_t>::stream(s, indent + "  ", v.level);
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.name);
    s << indent << "message: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.message);
    s << indent << "hardware_id: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.hardware_id);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_HMIDIAGNOSTICSTATUS_H
