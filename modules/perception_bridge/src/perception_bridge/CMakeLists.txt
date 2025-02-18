cmake_minimum_required(VERSION 3.0.2)
project(perception_bridge)

set(CMAKE_CXX_STANDARD 17)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
  geometry_msgs
  perception_msgs
)

# 生成消息和服务
catkin_package(
  INCLUDE_DIRS 
    include
  CATKIN_DEPENDS 
    roscpp 
    std_msgs 
    geometry_msgs 
    perception_msgs
)

# 包含头文件和库文件
include_directories(
  include
  ${catkin_INCLUDE_DIRS}
  ${roscpp_INCLUDE_DIRS}
	${PROJECT_SOURCE_DIR}/../../message/ros/devel/include/perception_msgs
)

# 声明可执行文件
add_executable(perception_bridge_two_node 
			src/perception_bridge_node.cpp
			src/RobotDogState.cpp
			src/DogMain.cpp
			)

# 链接库
target_link_libraries(perception_bridge_two_node
  ${catkin_LIBRARIES}
)

# 安装目标
install(TARGETS perception_bridge_two_node
  ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
  RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
)

# 安装头文件（如果有）
install(DIRECTORY include/${PROJECT_NAME}/
  DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
  FILES_MATCHING PATTERN "*.h"
)

# 安装 launch 文件（如果有）
install(DIRECTORY launch/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/launch
)

# 安装配置文件（如果有）
install(DIRECTORY config/
  DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}/config
)
