# 电量
float64 battery
#充电状态   0：空闲 1: 准备充电 2：充电中 
uint8 chargingState
#手势
uint8 gesture
#速度 
float64 speed
#主人识别状态
uint8 person_state
# 目标点
geometry_msgs/Pose target_position
#报警信息
AlarmEntry[] alarmInfo
#动作信息
#ActionEntry[] actions
