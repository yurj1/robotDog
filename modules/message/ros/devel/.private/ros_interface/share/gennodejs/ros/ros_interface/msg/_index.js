
"use strict";

let PlanningAnalysis = require('./PlanningAnalysis.js');
let ObuCmdMsg = require('./ObuCmdMsg.js');
let Pavementype = require('./Pavementype.js');
let VehicleConfig = require('./VehicleConfig.js');
let CommCommand = require('./CommCommand.js');
let HMIParkingInfoList = require('./HMIParkingInfoList.js');
let UltrasonicObstacle = require('./UltrasonicObstacle.js');
let StopPoint = require('./StopPoint.js');
let SecurityDecision = require('./SecurityDecision.js');
let ImageRect = require('./ImageRect.js');
let WheelInfo = require('./WheelInfo.js');
let ParkingRoi = require('./ParkingRoi.js');
let LaneletInfo = require('./LaneletInfo.js');
let Faults = require('./Faults.js');
let PredictionTrajectoryPoint = require('./PredictionTrajectoryPoint.js');
let PerceptionObstacle = require('./PerceptionObstacle.js');
let DrivableRegion = require('./DrivableRegion.js');
let CurvatureInfo = require('./CurvatureInfo.js');
let DiagnosticStatus = require('./DiagnosticStatus.js');
let SLBoundary = require('./SLBoundary.js');
let Twist = require('./Twist.js');
let HMIObuCmdMsg = require('./HMIObuCmdMsg.js');
let Header = require('./Header.js');
let Point3D = require('./Point3D.js');
let SensorCalibrator = require('./SensorCalibrator.js');
let SpeedPoint = require('./SpeedPoint.js');
let GaussianInfo = require('./GaussianInfo.js');
let ParkingStateDisplay = require('./ParkingStateDisplay.js');
let VehicleMotionPoint = require('./VehicleMotionPoint.js');
let RadarObstacleListMsg = require('./RadarObstacleListMsg.js');
let TrafficLight = require('./TrafficLight.js');
let FrenetFramePoint = require('./FrenetFramePoint.js');
let HMIObstacle = require('./HMIObstacle.js');
let RoutingRequest = require('./RoutingRequest.js');
let HMIObuCmd = require('./HMIObuCmd.js');
let WLConstraintInfoList = require('./WLConstraintInfoList.js');
let TrajectoryArray = require('./TrajectoryArray.js');
let HMIDiagnosticArray = require('./HMIDiagnosticArray.js');
let WarningCommand = require('./WarningCommand.js');
let VehicleState = require('./VehicleState.js');
let TrajectoryLimitCommand = require('./TrajectoryLimitCommand.js');
let StopInfo = require('./StopInfo.js');
let PointENU = require('./PointENU.js');
let Gnss = require('./Gnss.js');
let PredictionObstacles = require('./PredictionObstacles.js');
let ObuCmd = require('./ObuCmd.js');
let Image = require('./Image.js');
let Fault = require('./Fault.js');
let Ins = require('./Ins.js');
let KeyValues = require('./KeyValues.js');
let Matrix3D = require('./Matrix3D.js');
let CameraParkingInfo = require('./CameraParkingInfo.js');
let PathPoint = require('./PathPoint.js');
let UssParkingInfo = require('./UssParkingInfo.js');
let RoadMarkList = require('./RoadMarkList.js');
let RadarState = require('./RadarState.js');
let GlobalRouteMsg = require('./GlobalRouteMsg.js');
let GuideInfo = require('./GuideInfo.js');
let EndPoints = require('./EndPoints.js');
let PlanningCmd = require('./PlanningCmd.js');
let Location = require('./Location.js');
let TrajectoryInPrediction = require('./TrajectoryInPrediction.js');
let Imu = require('./Imu.js');
let HMITrajectoryPoint = require('./HMITrajectoryPoint.js');
let WLConstraintInfo = require('./WLConstraintInfo.js');
let Odometry = require('./Odometry.js');
let Path = require('./Path.js');
let ParkingOutInfo = require('./ParkingOutInfo.js');
let Event = require('./Event.js');
let LaneLine = require('./LaneLine.js');
let LaneLineCubicCurve = require('./LaneLineCubicCurve.js');
let CompressedImage = require('./CompressedImage.js');
let SotifMonitorResult = require('./SotifMonitorResult.js');
let Ultrasonic = require('./Ultrasonic.js');
let TrafficEvents = require('./TrafficEvents.js');
let PredictionObstacle = require('./PredictionObstacle.js');
let ADCTrajectory = require('./ADCTrajectory.js');
let LimitSpeedInfo = require('./LimitSpeedInfo.js');
let UssObstacle = require('./UssObstacle.js');
let PointXYZIRT = require('./PointXYZIRT.js');
let VehicleSignal = require('./VehicleSignal.js');
let TrafficLightBox = require('./TrafficLightBox.js');
let RadarObstacle = require('./RadarObstacle.js');
let TrajectoryPoint = require('./TrajectoryPoint.js');
let ParkingStopper = require('./ParkingStopper.js');
let Grid = require('./Grid.js');
let SLPoint = require('./SLPoint.js');
let GuideRoad = require('./GuideRoad.js');
let LaneInfo = require('./LaneInfo.js');
let Region = require('./Region.js');
let ObstaclePriority = require('./ObstaclePriority.js');
let Log = require('./Log.js');
let BBox2D = require('./BBox2D.js');
let PointBasic = require('./PointBasic.js');
let ParkingInfo = require('./ParkingInfo.js');
let Obstacle = require('./Obstacle.js');
let PointCloud = require('./PointCloud.js');
let HMITrajectory = require('./HMITrajectory.js');
let TrafficLightDebug = require('./TrafficLightDebug.js');
let CameraParkingInfoList = require('./CameraParkingInfoList.js');
let Stories = require('./Stories.js');
let UssObstacleList = require('./UssObstacleList.js');
let ObstacleFeature = require('./ObstacleFeature.js');
let Chassis = require('./Chassis.js');
let VehicleMotion = require('./VehicleMotion.js');
let ImageKeyPoint = require('./ImageKeyPoint.js');
let TimeConsume = require('./TimeConsume.js');
let FreeSpace = require('./FreeSpace.js');
let ObstacleInteractiveTag = require('./ObstacleInteractiveTag.js');
let KeyPoint = require('./KeyPoint.js');
let ParkingInfoList = require('./ParkingInfoList.js');
let PlanningParkingDebug = require('./PlanningParkingDebug.js');
let HMIObstacleList = require('./HMIObstacleList.js');
let Command = require('./Command.js');
let Trajectory = require('./Trajectory.js');
let Events = require('./Events.js');
let ModuleStatus = require('./ModuleStatus.js');
let Polygon2D = require('./Polygon2D.js');
let HMIVehicleMsg = require('./HMIVehicleMsg.js');
let Time = require('./Time.js');
let Quaternion = require('./Quaternion.js');
let UssParkingInfoList = require('./UssParkingInfoList.js');
let DiagnosticArray = require('./DiagnosticArray.js');
let RadarStateMode = require('./RadarStateMode.js');
let TrafficLightMsg = require('./TrafficLightMsg.js');
let RoadMark = require('./RoadMark.js');
let HolisticPathPrediction = require('./HolisticPathPrediction.js');
let HMIParkingStateDisplay = require('./HMIParkingStateDisplay.js');
let Pose = require('./Pose.js');
let RadarStateError = require('./RadarStateError.js');
let Point2dList = require('./Point2dList.js');
let Status = require('./Status.js');
let JunctionInfo = require('./JunctionInfo.js');
let ControlAnalysis = require('./ControlAnalysis.js');
let VehicleParam = require('./VehicleParam.js');
let ControlCommand = require('./ControlCommand.js');
let AlarmMessage = require('./AlarmMessage.js');
let CameraParkingStopper = require('./CameraParkingStopper.js');
let RoutingResponse = require('./RoutingResponse.js');
let HMIParkingInfo = require('./HMIParkingInfo.js');
let Polygon3D = require('./Polygon3D.js');
let CommandRespond = require('./CommandRespond.js');
let HMIDiagnosticStatus = require('./HMIDiagnosticStatus.js');
let PointLLH = require('./PointLLH.js');
let ObstacleList = require('./ObstacleList.js');
let RSSInfo = require('./RSSInfo.js');
let EStop = require('./EStop.js');
let Uncertainty = require('./Uncertainty.js');
let ObstacleIntent = require('./ObstacleIntent.js');
let RouteFusionInfo = require('./RouteFusionInfo.js');
let LaneList = require('./LaneList.js');
let LanePoint = require('./LanePoint.js');
let PadMessage = require('./PadMessage.js');
let Message = require('./Message.js');
let TrajectoryPointInPrediction = require('./TrajectoryPointInPrediction.js');
let Point2D = require('./Point2D.js');

module.exports = {
  PlanningAnalysis: PlanningAnalysis,
  ObuCmdMsg: ObuCmdMsg,
  Pavementype: Pavementype,
  VehicleConfig: VehicleConfig,
  CommCommand: CommCommand,
  HMIParkingInfoList: HMIParkingInfoList,
  UltrasonicObstacle: UltrasonicObstacle,
  StopPoint: StopPoint,
  SecurityDecision: SecurityDecision,
  ImageRect: ImageRect,
  WheelInfo: WheelInfo,
  ParkingRoi: ParkingRoi,
  LaneletInfo: LaneletInfo,
  Faults: Faults,
  PredictionTrajectoryPoint: PredictionTrajectoryPoint,
  PerceptionObstacle: PerceptionObstacle,
  DrivableRegion: DrivableRegion,
  CurvatureInfo: CurvatureInfo,
  DiagnosticStatus: DiagnosticStatus,
  SLBoundary: SLBoundary,
  Twist: Twist,
  HMIObuCmdMsg: HMIObuCmdMsg,
  Header: Header,
  Point3D: Point3D,
  SensorCalibrator: SensorCalibrator,
  SpeedPoint: SpeedPoint,
  GaussianInfo: GaussianInfo,
  ParkingStateDisplay: ParkingStateDisplay,
  VehicleMotionPoint: VehicleMotionPoint,
  RadarObstacleListMsg: RadarObstacleListMsg,
  TrafficLight: TrafficLight,
  FrenetFramePoint: FrenetFramePoint,
  HMIObstacle: HMIObstacle,
  RoutingRequest: RoutingRequest,
  HMIObuCmd: HMIObuCmd,
  WLConstraintInfoList: WLConstraintInfoList,
  TrajectoryArray: TrajectoryArray,
  HMIDiagnosticArray: HMIDiagnosticArray,
  WarningCommand: WarningCommand,
  VehicleState: VehicleState,
  TrajectoryLimitCommand: TrajectoryLimitCommand,
  StopInfo: StopInfo,
  PointENU: PointENU,
  Gnss: Gnss,
  PredictionObstacles: PredictionObstacles,
  ObuCmd: ObuCmd,
  Image: Image,
  Fault: Fault,
  Ins: Ins,
  KeyValues: KeyValues,
  Matrix3D: Matrix3D,
  CameraParkingInfo: CameraParkingInfo,
  PathPoint: PathPoint,
  UssParkingInfo: UssParkingInfo,
  RoadMarkList: RoadMarkList,
  RadarState: RadarState,
  GlobalRouteMsg: GlobalRouteMsg,
  GuideInfo: GuideInfo,
  EndPoints: EndPoints,
  PlanningCmd: PlanningCmd,
  Location: Location,
  TrajectoryInPrediction: TrajectoryInPrediction,
  Imu: Imu,
  HMITrajectoryPoint: HMITrajectoryPoint,
  WLConstraintInfo: WLConstraintInfo,
  Odometry: Odometry,
  Path: Path,
  ParkingOutInfo: ParkingOutInfo,
  Event: Event,
  LaneLine: LaneLine,
  LaneLineCubicCurve: LaneLineCubicCurve,
  CompressedImage: CompressedImage,
  SotifMonitorResult: SotifMonitorResult,
  Ultrasonic: Ultrasonic,
  TrafficEvents: TrafficEvents,
  PredictionObstacle: PredictionObstacle,
  ADCTrajectory: ADCTrajectory,
  LimitSpeedInfo: LimitSpeedInfo,
  UssObstacle: UssObstacle,
  PointXYZIRT: PointXYZIRT,
  VehicleSignal: VehicleSignal,
  TrafficLightBox: TrafficLightBox,
  RadarObstacle: RadarObstacle,
  TrajectoryPoint: TrajectoryPoint,
  ParkingStopper: ParkingStopper,
  Grid: Grid,
  SLPoint: SLPoint,
  GuideRoad: GuideRoad,
  LaneInfo: LaneInfo,
  Region: Region,
  ObstaclePriority: ObstaclePriority,
  Log: Log,
  BBox2D: BBox2D,
  PointBasic: PointBasic,
  ParkingInfo: ParkingInfo,
  Obstacle: Obstacle,
  PointCloud: PointCloud,
  HMITrajectory: HMITrajectory,
  TrafficLightDebug: TrafficLightDebug,
  CameraParkingInfoList: CameraParkingInfoList,
  Stories: Stories,
  UssObstacleList: UssObstacleList,
  ObstacleFeature: ObstacleFeature,
  Chassis: Chassis,
  VehicleMotion: VehicleMotion,
  ImageKeyPoint: ImageKeyPoint,
  TimeConsume: TimeConsume,
  FreeSpace: FreeSpace,
  ObstacleInteractiveTag: ObstacleInteractiveTag,
  KeyPoint: KeyPoint,
  ParkingInfoList: ParkingInfoList,
  PlanningParkingDebug: PlanningParkingDebug,
  HMIObstacleList: HMIObstacleList,
  Command: Command,
  Trajectory: Trajectory,
  Events: Events,
  ModuleStatus: ModuleStatus,
  Polygon2D: Polygon2D,
  HMIVehicleMsg: HMIVehicleMsg,
  Time: Time,
  Quaternion: Quaternion,
  UssParkingInfoList: UssParkingInfoList,
  DiagnosticArray: DiagnosticArray,
  RadarStateMode: RadarStateMode,
  TrafficLightMsg: TrafficLightMsg,
  RoadMark: RoadMark,
  HolisticPathPrediction: HolisticPathPrediction,
  HMIParkingStateDisplay: HMIParkingStateDisplay,
  Pose: Pose,
  RadarStateError: RadarStateError,
  Point2dList: Point2dList,
  Status: Status,
  JunctionInfo: JunctionInfo,
  ControlAnalysis: ControlAnalysis,
  VehicleParam: VehicleParam,
  ControlCommand: ControlCommand,
  AlarmMessage: AlarmMessage,
  CameraParkingStopper: CameraParkingStopper,
  RoutingResponse: RoutingResponse,
  HMIParkingInfo: HMIParkingInfo,
  Polygon3D: Polygon3D,
  CommandRespond: CommandRespond,
  HMIDiagnosticStatus: HMIDiagnosticStatus,
  PointLLH: PointLLH,
  ObstacleList: ObstacleList,
  RSSInfo: RSSInfo,
  EStop: EStop,
  Uncertainty: Uncertainty,
  ObstacleIntent: ObstacleIntent,
  RouteFusionInfo: RouteFusionInfo,
  LaneList: LaneList,
  LanePoint: LanePoint,
  PadMessage: PadMessage,
  Message: Message,
  TrajectoryPointInPrediction: TrajectoryPointInPrediction,
  Point2D: Point2D,
};
