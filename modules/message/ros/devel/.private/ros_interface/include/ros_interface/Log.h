// Generated by gencpp from file ros_interface/Log.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_LOG_H
#define ROS_INTERFACE_MESSAGE_LOG_H


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
struct Log_
{
  typedef Log_<ContainerAllocator> Type;

  Log_()
    : stamp()
    , level(0)
    , name()
    , msg()
    , file()
    , function()
    , line(0)  {
    }
  Log_(const ContainerAllocator& _alloc)
    : stamp(_alloc)
    , level(0)
    , name(_alloc)
    , msg(_alloc)
    , file(_alloc)
    , function(_alloc)
    , line(0)  {
  (void)_alloc;
    }



   typedef  ::ros_interface::Time_<ContainerAllocator>  _stamp_type;
  _stamp_type stamp;

   typedef uint8_t _level_type;
  _level_type level;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _name_type;
  _name_type name;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _msg_type;
  _msg_type msg;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _file_type;
  _file_type file;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _function_type;
  _function_type function;

   typedef uint32_t _line_type;
  _line_type line;





  typedef boost::shared_ptr< ::ros_interface::Log_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::Log_<ContainerAllocator> const> ConstPtr;

}; // struct Log_

typedef ::ros_interface::Log_<std::allocator<void> > Log;

typedef boost::shared_ptr< ::ros_interface::Log > LogPtr;
typedef boost::shared_ptr< ::ros_interface::Log const> LogConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::Log_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::Log_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::Log_<ContainerAllocator1> & lhs, const ::ros_interface::Log_<ContainerAllocator2> & rhs)
{
  return lhs.stamp == rhs.stamp &&
    lhs.level == rhs.level &&
    lhs.name == rhs.name &&
    lhs.msg == rhs.msg &&
    lhs.file == rhs.file &&
    lhs.function == rhs.function &&
    lhs.line == rhs.line;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::Log_<ContainerAllocator1> & lhs, const ::ros_interface::Log_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::Log_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::Log_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::Log_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::Log_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::Log_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::Log_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::Log_<ContainerAllocator> >
{
  static const char* value()
  {
    return "2071f6faae9945ec94584b4d4ed5edd8";
  }

  static const char* value(const ::ros_interface::Log_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x2071f6faae9945ecULL;
  static const uint64_t static_value2 = 0x94584b4d4ed5edd8ULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::Log_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/Log";
  }

  static const char* value(const ::ros_interface::Log_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::Log_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Time   stamp     # 时间戳\n"
"uint8   level     # log等级 DEBUG   : 10  INFO       : 20   WARN     : 30   ERROR   : 40  FATAL     : 50 \n"
"string   name     # 节点名\n"
"string   msg     # log消息\n"
"string   file     # 发送log文件路径\n"
"string   function     # 模块名\n"
"uint32   line     # 消息行\n"
"\n"
"================================================================================\n"
"MSG: ros_interface/Time\n"
"uint32   sec     # 秒\n"
"uint32   nsec     # 纳秒\n"
;
  }

  static const char* value(const ::ros_interface::Log_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::Log_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.stamp);
      stream.next(m.level);
      stream.next(m.name);
      stream.next(m.msg);
      stream.next(m.file);
      stream.next(m.function);
      stream.next(m.line);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Log_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::Log_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::Log_<ContainerAllocator>& v)
  {
    s << indent << "stamp: ";
    s << std::endl;
    Printer< ::ros_interface::Time_<ContainerAllocator> >::stream(s, indent + "  ", v.stamp);
    s << indent << "level: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.level);
    s << indent << "name: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.name);
    s << indent << "msg: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.msg);
    s << indent << "file: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.file);
    s << indent << "function: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.function);
    s << indent << "line: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.line);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_LOG_H
