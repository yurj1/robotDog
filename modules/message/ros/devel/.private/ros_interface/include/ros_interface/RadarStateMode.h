// Generated by gencpp from file ros_interface/RadarStateMode.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_RADARSTATEMODE_H
#define ROS_INTERFACE_MESSAGE_RADARSTATEMODE_H


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
struct RadarStateMode_
{
  typedef RadarStateMode_<ContainerAllocator> Type;

  RadarStateMode_()
    : can0_work_mode(0)
    , can1_work_mode(0)
    , dual_can_mode(0)
    , timming_mode(0)
    , power_mode(0)
    , performance_mode(0)  {
    }
  RadarStateMode_(const ContainerAllocator& _alloc)
    : can0_work_mode(0)
    , can1_work_mode(0)
    , dual_can_mode(0)
    , timming_mode(0)
    , power_mode(0)
    , performance_mode(0)  {
  (void)_alloc;
    }



   typedef uint8_t _can0_work_mode_type;
  _can0_work_mode_type can0_work_mode;

   typedef uint8_t _can1_work_mode_type;
  _can1_work_mode_type can1_work_mode;

   typedef uint8_t _dual_can_mode_type;
  _dual_can_mode_type dual_can_mode;

   typedef uint8_t _timming_mode_type;
  _timming_mode_type timming_mode;

   typedef uint8_t _power_mode_type;
  _power_mode_type power_mode;

   typedef uint8_t _performance_mode_type;
  _performance_mode_type performance_mode;





  typedef boost::shared_ptr< ::ros_interface::RadarStateMode_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::RadarStateMode_<ContainerAllocator> const> ConstPtr;

}; // struct RadarStateMode_

typedef ::ros_interface::RadarStateMode_<std::allocator<void> > RadarStateMode;

typedef boost::shared_ptr< ::ros_interface::RadarStateMode > RadarStateModePtr;
typedef boost::shared_ptr< ::ros_interface::RadarStateMode const> RadarStateModeConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::RadarStateMode_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::RadarStateMode_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::RadarStateMode_<ContainerAllocator1> & lhs, const ::ros_interface::RadarStateMode_<ContainerAllocator2> & rhs)
{
  return lhs.can0_work_mode == rhs.can0_work_mode &&
    lhs.can1_work_mode == rhs.can1_work_mode &&
    lhs.dual_can_mode == rhs.dual_can_mode &&
    lhs.timming_mode == rhs.timming_mode &&
    lhs.power_mode == rhs.power_mode &&
    lhs.performance_mode == rhs.performance_mode;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::RadarStateMode_<ContainerAllocator1> & lhs, const ::ros_interface::RadarStateMode_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::RadarStateMode_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::RadarStateMode_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::RadarStateMode_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::RadarStateMode_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::RadarStateMode_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::RadarStateMode_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::RadarStateMode_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d3643a2a561b16d4937dd76d21d14be0";
  }

  static const char* value(const ::ros_interface::RadarStateMode_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd3643a2a561b16d4ULL;
  static const uint64_t static_value2 = 0x937dd76d21d14be0ULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::RadarStateMode_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/RadarStateMode";
  }

  static const char* value(const ::ros_interface::RadarStateMode_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::RadarStateMode_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint8   can0_work_mode     # can0工作模式\n"
"uint8   can1_work_mode     # can1工作模式\n"
"uint8   dual_can_mode     # 双总线工作模式\n"
"uint8   timming_mode     # 计时模式\n"
"uint8   power_mode     # 电源模式\n"
"uint8   performance_mode     # 效能模式\n"
;
  }

  static const char* value(const ::ros_interface::RadarStateMode_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::RadarStateMode_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.can0_work_mode);
      stream.next(m.can1_work_mode);
      stream.next(m.dual_can_mode);
      stream.next(m.timming_mode);
      stream.next(m.power_mode);
      stream.next(m.performance_mode);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct RadarStateMode_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::RadarStateMode_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::RadarStateMode_<ContainerAllocator>& v)
  {
    s << indent << "can0_work_mode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.can0_work_mode);
    s << indent << "can1_work_mode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.can1_work_mode);
    s << indent << "dual_can_mode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.dual_can_mode);
    s << indent << "timming_mode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.timming_mode);
    s << indent << "power_mode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.power_mode);
    s << indent << "performance_mode: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.performance_mode);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_RADARSTATEMODE_H
