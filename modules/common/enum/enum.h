/**
 * @file    enum.h
 * @author  hyzx
 * @date    2022-05-06
 * @version 1.0.0
 * @par     Copyright(c)
 * @license GNU General Public License (GPL)
 */

#pragma once

namespace athena
{
  namespace common
  {
    enum class AutoDrivingCMD
    {
      CODE = 10001,
      VAL_INVALID = 0,
      VAL_STARTAUTO = 1,
      VAL_STOPAUTO = 2,
    };
    enum class PlanningDecisionCMD
    {
      CODE = 10021,
      VAL_NONE = 0,
      VAL_EMERGENT_STOP = 1,
      VAL_PULLOVER = 2,
      VAL_OVERTAKE = 3,
      VAL_MERGING = 4,
    };
    enum class ManualLaneChangeCMD
    {
      CODE = 10022,
      VAL_INVALID = 0,
      VAL_LEFT = 1,
      VAL_RIGHT = 2,
    };
    enum class AutoLaneChangeCMD
    {
      CODE = 10023,
      VAL_KEEPLANE = 0,
      VAL_AUTOCHANGE = 1,
      VAL_MANUALCHANGE = 2,
    };
    enum class ParkingRequestCMD
    {
      CODE = 10042,
      VAL_PARKINGINREQUEST = 1,
      VAL_STARTPARKINGIN = 2,
      VAL_PARKINGOUTREQUEST = 3,
      VAL_STARTPARKINGOUT = 4,
      VAL_STOPPARKINGOUT = 5,
    };
    enum class ActivationCMD
    {
      CODE = 10086,
      VAL_ALLDEACTIVATE = 0,
      VAL_DRIVING_ACTIVATE = 1,
      VAL_DRIVING_DEACTIVATE = 2,
      VAL_PARKING_ACTIVATE = 3,
      VAL_PARKING_DEACTIVATE = 4
    };
    enum class RemoteDrivingModeCMD
    {
      CODE = 20001,
      VAL_INVALID = 0,
      VAL_ACTIVATE = 1,
      VAL_DEACTIVATE = 2,
    };
    enum class RemoteRegisteredCMD
    {
      CODE = 20002,
      VAL_INVALID = 0,
      VAL_REQUEST = 1,
      VAL_RESPONSE = 2,
    };
    enum class EmergencyModeCMD
    {
      CODE = 20011,
      VAL_INVALID = 0,
      VAL_ACTIVATE = 1,
      VAL_DEACTIVATE = 2,
    };
    enum class AutoDrivingModeCMD
    {
      CODE = 20021,
      VAL_INVALID = 0,
      VAL_ACTIVATE = 1,
      VAL_DEACTIVATE = 2,
    };
    enum class TaskEventNotify
    {
      CODE = 20022,
      VAL_ARRIVED_STANDBY_POINT = 0,
      VAL_OPEN_PARACHUTE = 1,
      VAL_CANOPY_SEPARATION = 2,
      VAL_CANOPY_BOTTOM_LAND = 3,
      VAL_TARGET_LAND = 4,
      VAL_MEASURE_COORDINATE = 5,
      VAL_DETOUR_20M = 6,
      VAL_APPROACH = 7,
      VAL_DETOUR_4_1 = 8,
      VAL_DETOUR_4_2 = 9,
      VAL_DETOUR_4_3 = 10,
      VAL_QUIT_MISSION_POINT = 11,
      VAL_POINT_TO_POINT = 12,
    };
    enum class AutoDrivingTaskCMD
    {
      CODE = 20023,
      VAL_INVALID = 0,
      VAL_CKC_AUTO_DODGE = 1,
      VAL_CZC_DODGE_AND_APPROACH = 2,
      VAL_CZC_TARGET_SEARCH = 3,
      VAL_CZC_BIG_CIRCLE_ROUTINE = 4,
      VAL_CZC_SMALL_CIRCLE_ROUTINE = 5,
      VAL_POINT_TO_POINT = 6,
      VAL_RETURN_TO_TASKPOINT = 7,
    };
    enum class DodgeAndApproachTaskCMD
    {
      CODE = 20024,
      VAL_INVALID = 0,
      VAL_OPEN_PARACHUTE = 1,
      VAL_CANOPY_SEPARATION = 2,
      VAL_CANOPY_BOTTOM_LAND = 3
    };
    enum class TargetSearchCMD
    {
      CODE = 20025,
      VAL_INVALID = 0,
      VAL_TargetFound = 1
    };
    enum class SmallCircleRoutineCMD
    {
      CODE = 20026,
      VAL_INVALID = 0,
      VAL_APPROACH = 1,
      VAL_DETOUR_4_1 = 2,
      VAL_DETOUR_4_2 = 3,
      VAL_DETOUR_4_3 = 3
    };
    enum class PLANNING_EVENTS
    {
      INVALID_CODE = 0,
      UNABLE_PARKING_CODE = 1,
      ABLE_PARKING_CODE = 2,
      PARKING_OVER_CODE = 3,
      UNABLE_PARKING_OUT_CODE = 4,
      ABLE_PARKING_OUT_CODE = 5,
      PARKING_OUT_OVER_CODE = 6,
      UNABLE_DRIVING_CODE = 7,
      ABLE_DRIVING_CODE = 8,
      DRIVING_OVER_CODE = 9,
      AUTO_EXIT_CODE = 10,
      MANUAL_LANE_CHANGE_REJECTE_CODE = 20,
      LEFT_MANUAL_LANE_CHANGE_CODE = 21,
      RIGHT_MANUAL_LANE_CHANGE_CODE = 22,
      MANUAL_LANE_CHANGE_OVER_CODE = 23,
      LEFT_AUTO_LANE_CHANGE_CODE = 30,
      LEFT_AUTO_LANE_CHANGING_CODE = 31,
      RIGHT_AUTO_LANE_CHANGE_CODE = 32,
      RIGHT_AUTO_LANE_CHANGING_CODE = 33,
      AUTO_LANE_CHANGE_OVER_CODE = 34,
      OBSTACLE_PARKING_CODE = 40,
    };
    enum class StateInfoCode
    {
      STANDBY_CODE = 1001,
      AUTODRIVING_CODE = 1002,
      REMOTEDRIVING_CODE = 1003,
      EMERGENCYSTATUS_CODE = 1004,
      FAULTSTATUS_CODE = 1005,
      HUMANDRIVING_CODE = 1006,
      AUTODRIVING_CKC_AUTO_DODGE_CODE = 1011,
      AUTODRIVING_CZC_BIG_CIRCLE_ROUTINE_CODE = 1012,
      AUTODRIVING_CZC_DODGE_AND_APPROACH_CODE = 1013,
      AUTODRIVING_CZC_SMALL_CIRCLE_ROUTINE_CODE = 1014,
      AUTODRIVING_CZC_TARGET_SEARCH_CODE = 1015,
      AUTODRIVING_POINT_TO_POINT_CODE = 1016,
      AUTODRIVING_RETURN_TO_TASKPOINT_CODE = 1017,
      CANOPY_SEPARATION_S = 2011,
      CANOPY_SEPARATION_F = 2012,
      CANOPY_BOTTOM_LAND_S = 2021,
      CANOPY_BOTTOM_LAND_F = 2022,
      TARGET_LAND_S = 2031,
      TARGET_LAND_F = 2032,
      MEASURE_COORDINATE_S = 2041,
      MEASURE_COORDINATE_F = 2042,
      DETOUR_20M_S = 2051,
      DETOUR_20M_F = 2052,
      APPROACH_5M_S = 2061,
      APPROACH_5M_F = 2062,
      DETOUR_5M_4_1_S = 2071,
      DETOUR_5M_4_1_F = 2072,
      DETOUR_5M_4_2_S = 2081,
      DETOUR_5M_4_2_F = 2082,
      DETOUR_5M_4_3_S = 2091,
      DETOUR_5M_4_3_F = 2092,
      APPROACH_DOWNWIND_POINT_S = 2101,
      APPROACH_DOWNWIND_POINT_F = 2102,
      QUIT_MISSION_POINT_S = 2111,
      QUIT_MISSION_POINT_F = 2112,
      REMOTEDRIVING_STAY = 3001,
      REMOTEDRIVING_ENABLE = 3002,
      REMOTEDRIVING_UNABLE = 3003,
      EMERGENCYSTATUS_STAY = 4001,
      EMERGENCYSTATUS_ON = 4002,
      EMERGENCYSTATUS_OFF = 4003,
      VEHICLE_STATUS_AUTO_MODE = 5001,
      VEHICLE_STATUS_REMOTE_MODE = 5002,
      VEHICLE_STATUS_EMERGENCY_MODE = 5003,
      VEHICLE_STATUS_STAY_MODE = 5004,
      VEHICLE_STATUS_FAULT_MODE = 5005,
      AUTO_DRIVING_BYPASS_OBSTACLES = 5006,
      AUTO_DRIVING_LANE_DEPARTURE_WARNING = 5007,
      AUTO_DRIVING_BLOCKED = 5008,
      PRELAND_EVENT_SKY_TARGET_AVOIDED = 5009,
      PRELAND_EVENT_AVOIDED_FALLING_OBJECTS = 5010,
      ERROR_TURN_FAULT = 5011,
      ERROR_BRAKE_FAULT = 5012,
      ERROR_POWER_FAULT = 5013,
      ERROR_AUTO_DRIVE_FAULT = 5014,
      ERROR_SENSOR_FAULT = 5015,
      COMMUNICATION_DELAY = 5016,
      DATA_VALIDATE_PASSED = 5017,
      DATA_VALIDATE_FAILED = 5018,
      AUTO_DRIVING_COLLISION_OBSTACLES = 5019,
    };
    enum ErrorCode
    {
      LOCALIZATION_ERROR = 3000,
      LOCALIZATION_ERROR_MSG = 3100,
      LOCALIZATION_ERROR_LIDAR = 3200,
      LOCALIZATION_ERROR_INTEG = 3300,
      LOCALIZATION_ERROR_GNSS = 3400,
      PERCEPTION_ERROR = 4000,
      PERCEPTION_ERROR_TF = 4001,
      PERCEPTION_ERROR_PROCESS = 4002,
      PERCEPTION_FATAL = 4003,
      PERCEPTION_ERROR_NONE = 4004,
      PERCEPTION_ERROR_UNKNOWN = 4005,
      PREDICTION_ERROR = 5000,
      PLANNING_ERROR = 6000,
      PLANNING_ERROR_NOT_READY = 6001,
      HDMAP_DATA_ERROR = 7000,
      ROUTING_ERROR = 8000,
      ROUTING_ERROR_REQUEST = 8001,
      ROUTING_ERROR_RESPONSE = 8002,
      ROUTING_ERROR_NOT_READY = 8003,
      END_OF_INPUT = 9000,
      HTTP_LOGIC_ERROR = 10000,
      HTTP_RUNTIME_ERROR = 10001,
      DRIVER_ERROR_GNSS = 12000,
      DRIVER_ERROR_VELODYNE = 13000,
      STORYTELLING_ERROR = 14000,
    };
    enum IsValid
    {
      INVALID = 0,
      VALID = 1,
    };
    enum Judgment
    {
      FALSE = 0,
      TRUE = 1,
    };
    enum MovingStatus
    {
      UNKNOWN_VEHICLE_STATE = 0,
      STATIONARY = 1,
      MOVING_FORWARD = 2,
      MOVING_BACKWARD = 3,
    };
    enum DrivingMode
    {
      COMPLETE_MANUAL = 0,
      COMPLETE_AUTO_DRIVE = 1,
      AUTO_STEER_ONLY = 2,
      AUTO_SPEED_ONLY = 3,
      EMERGENCY_MODE = 4,
      RE_COMPLETE_AUTO_DRIVE = 5,
      MANUAL_TAKEOVER = 6,
      REMOTE_DRIVE = 7,
    };
    enum GearPosition
    {
      GEAR_NEUTRAL = 0,
      GEAR_DRIVE = 1,
      GEAR_REVERSE = 2,
      GEAR_PARKING = 3,
      GEAR_LOW = 4,
      GEAR_INVALID = 5,
      GEAR_NONE = 6,
    };
    enum WheelSpeedType
    {
      FORWARD = 0,
      BACKWARD = 1,
      STANDSTIL = 2,
      WHEEL_INVALID = 3,
    };
    enum ControlStatus
    {
      CONTROLLABLE = 0,
      UNCONTRLLABLE = 1,
      CONTROL_MANUAL_INTERVENTION = 2,
    };
    enum EPBLevel
    {
      RELEASED = 0,
      APPLIED = 1,
      APPLYING_RELEASING = 2,
      UNKNOWN = 3,
    };
    enum TurnSignal
    {
      TURN_INACTIVE_SIGNAL = 0,
      TURN_LEFT_SIGNAL = 1,
      TURN_RIGHT_SIGNAL = 2,
      TURN_INVALID_SIGNAL = 3,
    };
    enum DoorStatus
    {
      CLOSEED = 0,
      OPENING = 1,
      DOOR_INVALID = 2,
    };
    enum EngineStauts
    {
      STOPPED = 0,
      CRANKING = 1,
      RUNNING = 2,
      ENGINE_STATUS_ERROR = 3,
    };
    enum SwitchStatus
    {
      SWITCH_STATUS_OFF = 0,
      SWITCH_STATUS_ON = 1,
      SWITCH_INVALID = 2,
    };
    enum FailureStatus
    {
      FAILURE_STATUS_UNKNOWN = 0,
      NO_FAULT = 1,
      ERROR_DETECTED = 2,
    };
    enum PlugStatus
    {
      PLUG_STATUS_UNKNOWN = 0,
      PULL_OUT = 1,
      PLUG_IN = 2,
    };
    enum FoldUnfoldStatus
    {
      FOLD_UNFOLD_STATUS_UNKNOWN = 0,
      UNFOLD = 1,
      FOLD = 2,
      FOLDING_UNFOLDING = 3,
    };
    enum TrafficLightColor
    {
      COLOR_UNKNOWN = 0,
      RED = 1,
      YELLOW = 2,
      GREEN = 3,
      BLACK = 4,
    };
    enum RoadMarkType
    {
      STOP_LINE = 1,
      ZEBRA_CROSSING = 2,
      NO_PARKING_ZONE = 3,
      GO_STRAIGHT_ARROW = 4,
      TURN_LEFT_ARROW = 5,
      TURN_RIGHT_ARROW = 6,
      GO_STRAIGHT_TURN_LEFT = 7,
      GO_STRAIGHT_TURN_RIGHT = 8,
      GO_STRAIGHT_TURN_LEFT_RIGHT = 9,
      TURN_AROUND = 10,
      TURN_LEFT_AROUND = 11,
      RHOMBUS = 12,
      INVERTED_TRIANGLE = 13,
      GROUND_WORDS = 14,
    };
    enum TrafficLightType
    {
      STRAIGHT = 0,
      TURN_LEFT = 1,
      TURN_RIGHT = 2,
      STRAIGHT_TURN_LEFT = 3,
      STRAIGHT_TURN_RIGHT = 4,
      CIRCULAR = 5,
      PEDESTRIAN = 6,
      CYCLIST = 7,
      TYPE_UNKNOWN = 8,
    };
    enum SensorID
    {
      CAMERA_FRONT_CENTER = 0,
      CAMERA_FRONT_LEFT = 1,
      CAMERA_FRONT_RIGHT = 2,
      CAMERA_LEFT_FRONT = 3,
      CAMERA_LEFT_BACK = 4,
      CAMERA_RIGHT_FRONT = 5,
      CAMERA_RIGHT_BACK = 6,
      CAMERA_BACK = 7,
      CAMERA_FISH_EYE_FRONT = 8,
      CAMERA_FISH_EYE_LEFT = 9,
      CAMERA_FISH_EYE_RIGHT = 10,
      CAMERA_FISH_EYE_BACK = 11,
      CAMERA_FUSION = 12,
      CAM_FRONT_WIDE = 13,
      CAM_FRONT_NARROW = 14,
    };
    enum ObstacleType
    {
      OBSTACLE_UNKNOWN = 0,
      OBSTACLE_UNKNOWN_MOVABLE = 1,
      OBSTACLE_UNKNOWN_UNMOVABLE = 2,
      OBSTACLE_PEDESTRIAN = 3,
      OBSTACLE_BICYCLE = 4,
      OBSTACLE_VEHICLE = 5,
      OBSTACLE_POTHOLE = 6,
    };
    enum ObstacleSubType
    {
      ST_UNKNOWN = 0,
      ST_UNKNOWN_MOVABLE = 1,
      ST_UNKNOWN_UNMOVABLE = 2,
      ST_CAR = 3,
      ST_VAN = 4,
      ST_TRUCK = 5,
      ST_BUS = 6,
      ST_CYCLIST = 7,
      ST_MOTORCYCLIST = 8,
      ST_TRICYCLIST = 9,
      ST_PEDESTRIAN = 10,
      ST_TRAFFICCONE = 11,
      ST_PILLAR = 12,
      ST_SPEED_BUMP = 13,
      ST_WATER_HORSE = 14,
      ST_PARKING_LOCK = 15,
      ST_ISOLATION_PILE = 16,
      ST_NO_PARKING_SIGN = 17,
      ST_CONSTRUCTION_SIGN = 18,
      ST_FIRE_HYDRANT = 19,
      ST_VEHICLE_WHEEL = 20,
    };
    enum BlinkerFlag
    {
      BLINKER_FLAG_OFF = 0,
      LEFT_TURN_VISIBLE = 1,
      LEFT_TURN_ON = 2,
      RIGHT_TURN_VISIBLE = 3,
      RIGHT_TURN_ON = 4,
      BRAKE_VISIBLE = 5,
      BRAKE_ON = 6,
      BLINKER_FLAG_UNKNOWN = 7,
    };
    enum LanePosition
    {
      NEXT_LEFT_LANE = -2,
      LEFT_LANE = -1,
      EGO_LANE = 0,
      RIGHT_LANE = 1,
      NEXT_RIGHT_LANE = 2,
      OTHERS = 3,
      LANE_POSITION_UNKNOWN = 4,
    };
    enum ParkingStatus
    {
      PARKING_ENABLE = 1,
      PARKING_DISENABLE = 0,
      PARKING_NONOPTIONAL = 2,
    };
    enum ParkingType
    {
      INVALID_PARKING = 0,
      PARALLEL_PARKING = 1,
      VERTICAL_PARKING = 2,
      OBLIQUE_PARKING = 3,
      UNKNOWN_PARKING = 4,
    };
    enum ParkingSourceType
    {
      LINE_PARKING = 0,
      SPACE_PARKING = 1,
      FUSED_PARKING = 2,
    };
    enum UssParkingType
    {
      RIGHT_PARALLEL_PARKING = 0,
      LEFT_PARALLEL_PARKING = 1,
      RIGHT_VERTICAL_PARKING = 2,
      LEFT_VERTICAL_PARKING = 3,
    };
    enum CoordinateSystem
    {
      INVALID_COORDINATE_SYSTEM = 0,
      IMAGE_COORDINATE_SYSTEM = 1,
      VEHICLE_COORDINATE_SYSTEM = 2,
      WORLD_COORDINATE_SYSTEM = 3,
    };
    enum LaneLineType
    {
      LANE_LINE_TYPE_UNKNOWN = 0,
      CURB = 1,
      WHITE_DASHED = 2,
      WHITE_SOLID = 3,
      YELLOW_DASHED = 4,
      YELLOW_SOLID = 5,
    };
    enum GnssPositionType
    {
      NONE = 0,
      FIXEDPOS = 1,
      FIXEDHEIGHT = 2,
      FLOATCONV = 4,
      WIDELANE = 5,
      NARROWLANE = 6,
      DOPPLER_VELOCITY = 8,
      SINGLE = 16,
      PSRDIFF = 17,
      WAAS = 18,
      PROPOGATED = 19,
      OMNISTAR = 20,
      L1_FLOAT = 32,
      IONOFREE_FLOAT = 33,
      NARROW_FLOAT = 34,
      L1_INT = 48,
      WIDE_INT = 49,
      NARROW_INT = 50,
      RTK_DIRECT_INS = 51,
      INS_SBAS = 52,
      INS_PSRSP = 53,
      INS_PSRDIFF = 54,
      INS_RTKFLOAT = 55,
      INS_RTKFIXED = 56,
      INS_OMNISTAR = 57,
      INS_OMNISTAR_HP = 58,
      INS_OMNISTAR_XP = 59,
      OMNISTAR_HP = 64,
      OMNISTAR_XP = 65,
      PPP_CONVERGING = 68,
      PPP = 69,
      INS_PPP_CONVERGING = 73,
      INS_PPP = 74,
      MSG_LOSS = 91,
    };
    enum Direction
    {
      DIR_INVALID = 0,
      LEFT = 1,
      UP = 2,
      RIGHT = 3,
      DOWN = 4,
    };
    enum ParkingMotionType
    {
      PARKING_MOTION_INVALID = 0,
      PARKING_IN = 1,
      PARKING_OUT = 2,
    };
    enum SteerMode
    {
      STEER_MODE_2WS = 0,
      STEER_MODE_4WS = 1,
    };
    enum UssObstacleRegion
    {
      USS_BACK = 0,
      USS_FRONT = 1,
      USS_RIGHT = 2,
      USS_LEFT = 3,
    };
    enum OutDirection
    {
      OUT_INVALID = 0,
      OUT_UNKNOWN = 1,
      OUT_LEFT = 2,
      OUT_RIGHT = 3,
      OUT_HEAD = 4,
      OUT_REAR_LEFT = 5,
      OUT_REAR_RIGHT = 6,
      OUT_REAR = 7,
      OUT_HEAD_LEFT = 8,
      OUT_HEAD_RIGHT = 9,
    };
    enum AlarmLevel
    {
      ALARM_INFO = 0,
      ALARM_WARING = 1,
      ALARM_ERROR = 2,
    };
    enum AlarmType
    {
      ALARM_TYPE_REPORT = 0,
      ALARM_TYPE_RECOVER = 1,
      ALARM_TYPE_EVENT = 2,
    };
    enum AlarmDisplay
    {
      ALARM_DISPLAY_TEXT = 0,
      ALARM_DISPLAY_SOUND = 1,
      ALARM_DISPLAY_TEXT_AND_SOUND = 2,
    };
    enum OccupiedStatus
    {
      UNKNOWN_OCCUPIED_STATUS = 0,
      EMPTY = 1,
      OCCUPIED = 2,
    };
    enum MessageActionMode
    {
      DO_NOTHING = 0,
      TO_ACTIVATE = 1,
      TO_DEACTIVATE = 2,
    };
    enum ParkingSceneType
    {
      COMMON = 0,
      DEAD_END = 1,
      SELF_CREATED = 2,
      NARROW_LANE = 3,
      NARROW_SPACE = 4,
    };
    enum class DrivingModeCMD
    {
      CODE = 20000,
      VAL_INVALID = 0,
      VAL_AUTO = 1,
      VAL_REMOTE = 2,
    };
  } // namespace common
} // namespace athena