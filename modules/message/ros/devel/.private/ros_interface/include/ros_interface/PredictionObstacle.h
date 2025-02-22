// Generated by gencpp from file ros_interface/PredictionObstacle.msg
// DO NOT EDIT!


#ifndef ROS_INTERFACE_MESSAGE_PREDICTIONOBSTACLE_H
#define ROS_INTERFACE_MESSAGE_PREDICTIONOBSTACLE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>

#include <ros_interface/PerceptionObstacle.h>
#include <ros_interface/TrajectoryInPrediction.h>
#include <ros_interface/ObstacleIntent.h>
#include <ros_interface/ObstaclePriority.h>
#include <ros_interface/ObstacleInteractiveTag.h>

namespace ros_interface
{
template <class ContainerAllocator>
struct PredictionObstacle_
{
  typedef PredictionObstacle_<ContainerAllocator> Type;

  PredictionObstacle_()
    : perception_obstacle()
    , timestamp(0.0)
    , predicted_period(0.0)
    , trajectory()
    , intent()
    , priority()
    , interactive_tag()
    , is_static(false)  {
    }
  PredictionObstacle_(const ContainerAllocator& _alloc)
    : perception_obstacle(_alloc)
    , timestamp(0.0)
    , predicted_period(0.0)
    , trajectory(_alloc)
    , intent(_alloc)
    , priority(_alloc)
    , interactive_tag(_alloc)
    , is_static(false)  {
  (void)_alloc;
    }



   typedef  ::ros_interface::PerceptionObstacle_<ContainerAllocator>  _perception_obstacle_type;
  _perception_obstacle_type perception_obstacle;

   typedef double _timestamp_type;
  _timestamp_type timestamp;

   typedef double _predicted_period_type;
  _predicted_period_type predicted_period;

   typedef std::vector< ::ros_interface::TrajectoryInPrediction_<ContainerAllocator> , typename std::allocator_traits<ContainerAllocator>::template rebind_alloc< ::ros_interface::TrajectoryInPrediction_<ContainerAllocator> >> _trajectory_type;
  _trajectory_type trajectory;

   typedef  ::ros_interface::ObstacleIntent_<ContainerAllocator>  _intent_type;
  _intent_type intent;

   typedef  ::ros_interface::ObstaclePriority_<ContainerAllocator>  _priority_type;
  _priority_type priority;

   typedef  ::ros_interface::ObstacleInteractiveTag_<ContainerAllocator>  _interactive_tag_type;
  _interactive_tag_type interactive_tag;

   typedef uint8_t _is_static_type;
  _is_static_type is_static;





  typedef boost::shared_ptr< ::ros_interface::PredictionObstacle_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::ros_interface::PredictionObstacle_<ContainerAllocator> const> ConstPtr;

}; // struct PredictionObstacle_

typedef ::ros_interface::PredictionObstacle_<std::allocator<void> > PredictionObstacle;

typedef boost::shared_ptr< ::ros_interface::PredictionObstacle > PredictionObstaclePtr;
typedef boost::shared_ptr< ::ros_interface::PredictionObstacle const> PredictionObstacleConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::ros_interface::PredictionObstacle_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::ros_interface::PredictionObstacle_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::ros_interface::PredictionObstacle_<ContainerAllocator1> & lhs, const ::ros_interface::PredictionObstacle_<ContainerAllocator2> & rhs)
{
  return lhs.perception_obstacle == rhs.perception_obstacle &&
    lhs.timestamp == rhs.timestamp &&
    lhs.predicted_period == rhs.predicted_period &&
    lhs.trajectory == rhs.trajectory &&
    lhs.intent == rhs.intent &&
    lhs.priority == rhs.priority &&
    lhs.interactive_tag == rhs.interactive_tag &&
    lhs.is_static == rhs.is_static;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::ros_interface::PredictionObstacle_<ContainerAllocator1> & lhs, const ::ros_interface::PredictionObstacle_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace ros_interface

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::ros_interface::PredictionObstacle_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::ros_interface::PredictionObstacle_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::PredictionObstacle_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::ros_interface::PredictionObstacle_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::PredictionObstacle_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::ros_interface::PredictionObstacle_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::ros_interface::PredictionObstacle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "57b9e49b9055de569a665462768dbd6a";
  }

  static const char* value(const ::ros_interface::PredictionObstacle_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x57b9e49b9055de56ULL;
  static const uint64_t static_value2 = 0x9a665462768dbd6aULL;
};

template<class ContainerAllocator>
struct DataType< ::ros_interface::PredictionObstacle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "ros_interface/PredictionObstacle";
  }

  static const char* value(const ::ros_interface::PredictionObstacle_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::ros_interface::PredictionObstacle_<ContainerAllocator> >
{
  static const char* value()
  {
    return "PerceptionObstacle   perception_obstacle     # perception info of obstacle\n"
"float64   timestamp     # GPS time in seconds\n"
"float64   predicted_period     # the length of the time for this prediction (e.g. 10s)\n"
"TrajectoryInPrediction[] trajectory # can have multiple trajectories per obstacle\n"
"ObstacleIntent   intent     # 估计障碍物的意图        0-UNKNOWN, 1-STOP, 2-STATIONARY, 3-移动 MOVING, 4-HANGE_LANE, 5-LOW_ACCELERATION, 6-HIGH_ACCELERATION, 7-LOW_DECELERATION, 8-HIGH_DECELERATION, \n"
"ObstaclePriority   priority     # 障碍物优先级               1-CAUTION, 2-NORMAL, 3-IGNORE\n"
"ObstacleInteractiveTag   interactive_tag     #  \n"
"bool   is_static     # is obstacle static (default = false)\n"
"\n"
"================================================================================\n"
"MSG: ros_interface/PerceptionObstacle\n"
"int32   id     #  \n"
"Point3D   position     #  \n"
"float64   theta     #  \n"
"Point3D   velocity     #  \n"
"float64   length     #  \n"
"float64   width     #  \n"
"float64   height     #  \n"
"Point3D[] polygon_point #  \n"
"float64   tracking_time     #  \n"
"int32   type     # 障碍物类型： 0-Unknown 1-Unknown_movable 2-Unknown_unmovable 3-Pedestrian 4-Bicycle   5-Vehicle\n"
"int32   lane_position     # 车道线位置 -2-NEXT_LEFT_LANE -1-LEFT_LANE 0-EGO_LANE 1-RIGHT_LANE 2-NEXT_RIGHT_LANE 3-OTHERS 4-UNKNOWN\n"
"float64   confidence     #  \n"
"float64   timestamp     #  \n"
"uint8   confidence_type     # 置信度类型                  0-CONFIDENCE_UNKNOWN, 1-CONFIDENCE_CN, 2-CONFIDENCE_RAD\n"
"Point3D   drops     #  \n"
"Point3D   acceleration     #  \n"
"Point3D   anchor_point     #  \n"
"Point3D[] bounding_box #  \n"
"int32   sub_type     #  \n"
"float64   height_above_ground     #  \n"
"float64[] position_covariance #  \n"
"float64[] velocity_covariance #  \n"
"float64[] acceleration_covariance #  \n"
"uint8   light_status     #  \n"
"\n"
"================================================================================\n"
"MSG: ros_interface/Point3D\n"
"float64   x     # 位置坐标x\n"
"float64   y     # 位置坐标y\n"
"float64   z     # 位置坐标z\n"
"\n"
"================================================================================\n"
"MSG: ros_interface/TrajectoryInPrediction\n"
"float64   probability     # probability of this trajectory\n"
"TrajectoryPoint[] trajectory_points #  \n"
"\n"
"================================================================================\n"
"MSG: ros_interface/TrajectoryPoint\n"
"PathPoint   path_point     # path point\n"
"float64   v     # linear velocity\n"
"float64   a     # linear acceleration\n"
"float64   relative_time     # relative time from beginning of the trajectory\n"
"float64   da     # longitudinal jerk\n"
"bool   is_steer_valid     # 转向是否有效\n"
"float64   front_steer     # The angle between vehicle front wheel and vehicle longitudinal axis\n"
"float64   rear_steer     # 后轮转角\n"
"int32   gear     # 档位\n"
"\n"
"================================================================================\n"
"MSG: ros_interface/PathPoint\n"
"float64   x     # coordinates x\n"
"float64   y     # coordinates y\n"
"float64   z     # coordinates z\n"
"float64   theta     # direction on the x-y plane\n"
"float64   kappa     # curvature on the x-y planning\n"
"float64   s     # accumulated distance from beginning of the path\n"
"float64   dkappa     # derivative of kappa w.r.t s.\n"
"float64   ddkappa     # derivative of derivative of kappa w.r.t s.\n"
"float64   lane_id     # The lane ID where the path point is on\n"
"float64   x_derivative     # derivative of x w.r.t parametric parameter t in CosThetareferenceline\n"
"float64   y_derivative     # derivative of y w.r.t parametric parameter t in CosThetareferenceline\n"
"\n"
"================================================================================\n"
"MSG: ros_interface/ObstacleIntent\n"
"int32   type     # 估计障碍物的意图        0-UNKNOWN, 1-STOP, 2-STATIONARY, 3-移动 MOVING, 4-HANGE_LANE, 5-LOW_ACCELERATION, 6-HIGH_ACCELERATION, 7-LOW_DECELERATION, 8-HIGH_DECELERATION, \n"
"\n"
"================================================================================\n"
"MSG: ros_interface/ObstaclePriority\n"
"int32   priority     # CAUTION = 1; NORMAL = 2; IGNORE = 3;\n"
"\n"
"================================================================================\n"
"MSG: ros_interface/ObstacleInteractiveTag\n"
"int32   interactive_tag     #  \n"
;
  }

  static const char* value(const ::ros_interface::PredictionObstacle_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::ros_interface::PredictionObstacle_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.perception_obstacle);
      stream.next(m.timestamp);
      stream.next(m.predicted_period);
      stream.next(m.trajectory);
      stream.next(m.intent);
      stream.next(m.priority);
      stream.next(m.interactive_tag);
      stream.next(m.is_static);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct PredictionObstacle_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::ros_interface::PredictionObstacle_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::ros_interface::PredictionObstacle_<ContainerAllocator>& v)
  {
    s << indent << "perception_obstacle: ";
    s << std::endl;
    Printer< ::ros_interface::PerceptionObstacle_<ContainerAllocator> >::stream(s, indent + "  ", v.perception_obstacle);
    s << indent << "timestamp: ";
    Printer<double>::stream(s, indent + "  ", v.timestamp);
    s << indent << "predicted_period: ";
    Printer<double>::stream(s, indent + "  ", v.predicted_period);
    s << indent << "trajectory[]" << std::endl;
    for (size_t i = 0; i < v.trajectory.size(); ++i)
    {
      s << indent << "  trajectory[" << i << "]: ";
      s << std::endl;
      s << indent;
      Printer< ::ros_interface::TrajectoryInPrediction_<ContainerAllocator> >::stream(s, indent + "    ", v.trajectory[i]);
    }
    s << indent << "intent: ";
    s << std::endl;
    Printer< ::ros_interface::ObstacleIntent_<ContainerAllocator> >::stream(s, indent + "  ", v.intent);
    s << indent << "priority: ";
    s << std::endl;
    Printer< ::ros_interface::ObstaclePriority_<ContainerAllocator> >::stream(s, indent + "  ", v.priority);
    s << indent << "interactive_tag: ";
    s << std::endl;
    Printer< ::ros_interface::ObstacleInteractiveTag_<ContainerAllocator> >::stream(s, indent + "  ", v.interactive_tag);
    s << indent << "is_static: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.is_static);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROS_INTERFACE_MESSAGE_PREDICTIONOBSTACLE_H
