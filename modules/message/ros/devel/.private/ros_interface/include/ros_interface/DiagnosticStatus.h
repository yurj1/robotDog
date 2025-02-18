// Generated by gencpp from file ros_interface/DiagnosticStatus.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_DIAGNOSTICSTATUS_H
#define ROS_INTERFACE_MESSAGE_DIAGNOSTICSTATUS_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <std_msgs/Header.h>
#include <ros_interface/KeyValues.h>

namespace ros_interface
{
template <class ContainerAllocator>
struct DiagnosticStatus_
{
  typedef DiagnosticStatus_<ContainerAllocator> Type;

  DiagnosticStatus_()
    : header()
    , id(0)
    , level(0)
    , name()
    , message()
    , hardware_id()
    , values()  {
    }
  DiagnosticStatus_(const ContainerAllocator& _alloc)
    : header(_alloc)
    , id(0)
    , level(0)
    , name(_alloc)
    , message(_alloc)
    , hardware_id(_alloc)
    , values(_alloc)  {
  (void)_alloc;
    }



   typedef  ::std_msgs::Header_<ContainerAllocator>  _header_type;
  _header_type header;

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

   typedef std::vector< ::ros_interface::KeyValues_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::ros_interface::KeyValues_<ContainerAllocator> >> _values_type;
  _values_type values;





  typedef boost::shared_ptr< ::ros_interface::DiagnosticStatus_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::DiagnosticStatus_<ContainerAllocator> const> ConstPtr;

}; // struct DiagnosticStatus_

typedef ::ros_interface::DiagnosticStatus_<std::allocator<void> > DiagnosticStatus;

typedef boost::shared_ptr< ::ros_interface::DiagnosticStatus > DiagnosticStatusPtr;
typedef boost::shared_ptr< ::ros_interface::DiagnosticStatus const> DiagnosticStatusConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::DiagnosticStatus_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::DiagnosticStatus_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::DiagnosticStatus_<ContainerAllocator1> & lhs, const ::ros_interface::DiagnosticStatus_<ContainerAllocator2> & rhs)
{
  return lhs.header == rhs.header &&
    lhs.id == rhs.id &&
    lhs.level == rhs.level &&
    lhs.name == rhs.name &&
    lhs.message == rhs.message &&
    lhs.hardware_id == rhs.hardware_id &&
    lhs.values == rhs.values;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::DiagnosticStatus_<ContainerAllocator1> & lhs, const ::ros_interface::DiagnosticStatus_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::DiagnosticStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::DiagnosticStatus_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::DiagnosticStatus_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::DiagnosticStatus_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::DiagnosticStatus_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::DiagnosticStatus_<ContainerAllocator> const>
  : TrueType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::DiagnosticStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "cd2dd61053c8951ae47922af0c08a853";
  }

  static const char* value(const ::ros_interface::DiagnosticStatus_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xcd2dd61053c8951aULL;
  static const uint64_t static_value2 = 0xe47922af0c08a853ULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::DiagnosticStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/DiagnosticStatus";
  }

  static const char* value(const ::ros_interface::DiagnosticStatus_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::DiagnosticStatus_<ContainerAllocator> >
{
  static const char* value()
  {
    return "Header   header     # timestamp is  included in header\n"
"int32   id     # level*100000 + 序号（RECOVER 400000） WARN 车运动状态（静止）100001 左前门状态（关闭）100002 右前门状态（关闭）100003 左后门状态（关闭）100004 右后门状态（关闭）100005 安全带状态（关闭）100006 后视镜状态（打开）100007 充电枪状态 100008 油门状态 （正常）100009 智驾系统（正常）100010 动力系统（正常）100011 左前轮胎压（正常）100012 右前轮胎压（正常）100013 左后轮胎压（正常）100014 右后轮胎压（正常）100015 转向系统（正常）100016 制动系统（正常）100017 档位系统（正常）100018 EPB系统（正常）100019 气囊状态（正常）100020 油箱盖状态（正常）100021 后备箱状态（正常）100022 底盘信息（正常）100023 定位信息（正常）100024 方向盘人工接管 100025 电量表（正常）100026 暂停超时 100027 暂停次数过多 100028 泊车超时 100029 人为刹车 100030 人为挂P挡 100031 障碍物碰撞 100032 EPB状态(释放) 100033 ERROR 规划失败 200000\n"
"int32   level     # 诊断状态\n"
"string   name     # 测试/组件报告的描述\n"
"string   message     # 状态描述\n"
"string   hardware_id     # 硬件的唯一描述\n"
"KeyValues[] values # 与状态关联的key-value组\n"
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
"MSG: ros_interface/KeyValues\n"
"string   key     #  \n"
"string   value     #  \n"
;
  }

  static const char* value(const ::ros_interface::DiagnosticStatus_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::DiagnosticStatus_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.header);
      stream.next(m.id);
      stream.next(m.level);
      stream.next(m.name);
      stream.next(m.message);
      stream.next(m.hardware_id);
      stream.next(m.values);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct DiagnosticStatus_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::DiagnosticStatus_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::DiagnosticStatus_<ContainerAllocator>& v)
  {
    s << indent << "header: ";
    s << std::endl;
    Printer< ::std_msgs::Header_<ContainerAllocator> >::stream(s, indent + "  ", v.header);
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
    s << indent << "values[]" << std::endl;
    for (size_t i = 0; i < v.values.size(); ++i)
    {
      s << indent << "  values[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::ros_interface::KeyValues_<ContainerAllocator> >::stream(s, indent + "    ", v.values[i]);
    }
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_DIAGNOSTICSTATUS_H
