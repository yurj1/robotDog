// Generated by gencpp from file ros_interface/VehicleSignal.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_VEHICLESIGNAL_H
#define ROS_INTERFACE_MESSAGE_VEHICLESIGNAL_H


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
struct VehicleSignal_
{
  typedef VehicleSignal_<ContainerAllocator> Type;

  VehicleSignal_()
    : turn_signal(0)
    , high_beam(false)
    , low_beam(false)
    , horn(false)
    , emergency_light(false)  {
    }
  VehicleSignal_(const ContainerAllocator& _alloc)
    : turn_signal(0)
    , high_beam(false)
    , low_beam(false)
    , horn(false)
    , emergency_light(false)  {
  (void)_alloc;
    }



   typedef int32_t _turn_signal_type;
  _turn_signal_type turn_signal;

   typedef uint8_t _high_beam_type;
  _high_beam_type high_beam;

   typedef uint8_t _low_beam_type;
  _low_beam_type low_beam;

   typedef uint8_t _horn_type;
  _horn_type horn;

   typedef uint8_t _emergency_light_type;
  _emergency_light_type emergency_light;





  typedef boost::shared_ptr< ::ros_interface::VehicleSignal_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::VehicleSignal_<ContainerAllocator> const> ConstPtr;

}; // struct VehicleSignal_

typedef ::ros_interface::VehicleSignal_<std::allocator<void> > VehicleSignal;

typedef boost::shared_ptr< ::ros_interface::VehicleSignal > VehicleSignalPtr;
typedef boost::shared_ptr< ::ros_interface::VehicleSignal const> VehicleSignalConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::VehicleSignal_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::VehicleSignal_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::VehicleSignal_<ContainerAllocator1> & lhs, const ::ros_interface::VehicleSignal_<ContainerAllocator2> & rhs)
{
  return lhs.turn_signal == rhs.turn_signal &&
    lhs.high_beam == rhs.high_beam &&
    lhs.low_beam == rhs.low_beam &&
    lhs.horn == rhs.horn &&
    lhs.emergency_light == rhs.emergency_light;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::VehicleSignal_<ContainerAllocator1> & lhs, const ::ros_interface::VehicleSignal_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::VehicleSignal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::VehicleSignal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::VehicleSignal_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::VehicleSignal_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::VehicleSignal_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::VehicleSignal_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::VehicleSignal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "47860a6c8e7e3e428751d2354cd4426d";
  }

  static const char* value(const ::ros_interface::VehicleSignal_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x47860a6c8e7e3e42ULL;
  static const uint64_t static_value2 = 0x8751d2354cd4426dULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::VehicleSignal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/VehicleSignal";
  }

  static const char* value(const ::ros_interface::VehicleSignal_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::VehicleSignal_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int32   turn_signal     # 转向信号\n"
"bool   high_beam     # high beam\n"
"bool   low_beam     # low beam\n"
"bool   horn     # horn\n"
"bool   emergency_light     # emergency light\n"
;
  }

  static const char* value(const ::ros_interface::VehicleSignal_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::VehicleSignal_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.turn_signal);
      stream.next(m.high_beam);
      stream.next(m.low_beam);
      stream.next(m.horn);
      stream.next(m.emergency_light);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct VehicleSignal_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::VehicleSignal_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::VehicleSignal_<ContainerAllocator>& v)
  {
    s << indent << "turn_signal: ";
    Printer<int32_t>::stream(s, indent + "  ", v.turn_signal);
    s << indent << "high_beam: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.high_beam);
    s << indent << "low_beam: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.low_beam);
    s << indent << "horn: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.horn);
    s << indent << "emergency_light: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.emergency_light);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_VEHICLESIGNAL_H
