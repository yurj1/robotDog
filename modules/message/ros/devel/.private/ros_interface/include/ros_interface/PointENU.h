// Generated by gencpp from file ros_interface/PointENU.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_POINTENU_H
#define ROS_INTERFACE_MESSAGE_POINTENU_H


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
struct PointENU_
{
  typedef PointENU_<ContainerAllocator> Type;

  PointENU_()
    : x(0.0)
    , y(0.0)
    , z(0.0)  {
    }
  PointENU_(const ContainerAllocator& _alloc)
    : x(0.0)
    , y(0.0)
    , z(0.0)  {
  (void)_alloc;
    }



   typedef double _x_type;
  _x_type x;

   typedef double _y_type;
  _y_type y;

   typedef double _z_type;
  _z_type z;





  typedef boost::shared_ptr< ::ros_interface::PointENU_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::PointENU_<ContainerAllocator> const> ConstPtr;

}; // struct PointENU_

typedef ::ros_interface::PointENU_<std::allocator<void> > PointENU;

typedef boost::shared_ptr< ::ros_interface::PointENU > PointENUPtr;
typedef boost::shared_ptr< ::ros_interface::PointENU const> PointENUConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::PointENU_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::PointENU_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::PointENU_<ContainerAllocator1> & lhs, const ::ros_interface::PointENU_<ContainerAllocator2> & rhs)
{
  return lhs.x == rhs.x &&
    lhs.y == rhs.y &&
    lhs.z == rhs.z;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::PointENU_<ContainerAllocator1> & lhs, const ::ros_interface::PointENU_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::PointENU_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::PointENU_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::PointENU_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::PointENU_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::PointENU_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::PointENU_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::PointENU_<ContainerAllocator> >
{
  static const char* value()
  {
    return "4a842b65f413084dc2b10fb484ea7f17";
  }

  static const char* value(const ::ros_interface::PointENU_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x4a842b65f413084dULL;
  static const uint64_t static_value2 = 0xc2b10fb484ea7f17ULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::PointENU_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/PointENU";
  }

  static const char* value(const ::ros_interface::PointENU_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::PointENU_<ContainerAllocator> >
{
  static const char* value()
  {
    return "float64   x     # East from the origin, in meters.\n"
"float64   y     # North from the origin, in meters.\n"
"float64   z     # Up from the WGS-84 ellipsoid, in meters.\n"
;
  }

  static const char* value(const ::ros_interface::PointENU_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::PointENU_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PointENU_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::PointENU_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::PointENU_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<double>::stream(s, indent + "  ", v.z);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_POINTENU_H
