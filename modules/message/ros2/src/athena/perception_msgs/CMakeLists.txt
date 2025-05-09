cmake_minimum_required(VERSION 3.5)
project(perception_msgs)

# 设置 C/C++ 标准
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

# 编译器警告选项
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# 查找构建所需依赖
find_package(ament_cmake REQUIRED)
find_package(geometry_msgs REQUIRED)
find_package(rosidl_default_generators REQUIRED)  # 新增：用于生成 msg/srv

# 生成接口（msg/srv）的代码
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/ActionEntry.msg"
  "msg/AlarmEntry.msg"
  "msg/PercCmd.msg"
  "msg/PercState.msg"
  "msg/PercReq.msg"
  "msg/TaskList.msg"
  "msg/DogState.msg"
  "srv/DogRecordBag.srv"
  DEPENDENCIES geometry_msgs
)

# 测试相关（可选）
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()