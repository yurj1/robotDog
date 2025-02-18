// Generated by gencpp from file ros_interface/BBox2D.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_BBOX2D_H
#define ROS_INTERFACE_MESSAGE_BBOX2D_H


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
struct BBox2D_
{
  typedef BBox2D_<ContainerAllocator> Type;

  BBox2D_()
    : xmin(0)
    , ymin(0)
    , xmax(0)
    , ymax(0)  {
    }
  BBox2D_(const ContainerAllocator& _alloc)
    : xmin(0)
    , ymin(0)
    , xmax(0)
    , ymax(0)  {
  (void)_alloc;
    }



   typedef int16_t _xmin_type;
  _xmin_type xmin;

   typedef int16_t _ymin_type;
  _ymin_type ymin;

   typedef int16_t _xmax_type;
  _xmax_type xmax;

   typedef int16_t _ymax_type;
  _ymax_type ymax;





  typedef boost::shared_ptr< ::ros_interface::BBox2D_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::BBox2D_<ContainerAllocator> const> ConstPtr;

}; // struct BBox2D_

typedef ::ros_interface::BBox2D_<std::allocator<void> > BBox2D;

typedef boost::shared_ptr< ::ros_interface::BBox2D > BBox2DPtr;
typedef boost::shared_ptr< ::ros_interface::BBox2D const> BBox2DConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::BBox2D_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::BBox2D_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::BBox2D_<ContainerAllocator1> & lhs, const ::ros_interface::BBox2D_<ContainerAllocator2> & rhs)
{
  return lhs.xmin == rhs.xmin &&
    lhs.ymin == rhs.ymin &&
    lhs.xmax == rhs.xmax &&
    lhs.ymax == rhs.ymax;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::BBox2D_<ContainerAllocator1> & lhs, const ::ros_interface::BBox2D_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::BBox2D_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::BBox2D_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::BBox2D_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::BBox2D_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::BBox2D_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::BBox2D_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::BBox2D_<ContainerAllocator> >
{
  static const char* value()
  {
    return "d19258be40eb6712eae30dd94922a828";
  }

  static const char* value(const ::ros_interface::BBox2D_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xd19258be40eb6712ULL;
  static const uint64_t static_value2 = 0xeae30dd94922a828ULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::BBox2D_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/BBox2D";
  }

  static const char* value(const ::ros_interface::BBox2D_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::BBox2D_<ContainerAllocator> >
{
  static const char* value()
  {
    return "int16   xmin     # 图像框左上角的x坐标\n"
"int16   ymin     # 图像框左上角的y坐标\n"
"int16   xmax     # 图像框右下角的x坐标\n"
"int16   ymax     # 图像框右下角的y坐标\n"
;
  }

  static const char* value(const ::ros_interface::BBox2D_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::BBox2D_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.xmin);
      stream.next(m.ymin);
      stream.next(m.xmax);
      stream.next(m.ymax);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct BBox2D_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::BBox2D_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::BBox2D_<ContainerAllocator>& v)
  {
    s << indent << "xmin: ";
    Printer<int16_t>::stream(s, indent + "  ", v.xmin);
    s << indent << "ymin: ";
    Printer<int16_t>::stream(s, indent + "  ", v.ymin);
    s << indent << "xmax: ";
    Printer<int16_t>::stream(s, indent + "  ", v.xmax);
    s << indent << "ymax: ";
    Printer<int16_t>::stream(s, indent + "  ", v.ymax);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_BBOX2D_H
