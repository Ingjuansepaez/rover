cmake_minimum_required(VERSION 3.8)
project(rover)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(ament_cmake_python REQUIRED)
find_package(rclpy REQUIRED)
#find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(trajectory_msgs REQUIRED)
find_package(geometry_msgs REQUIRED)

#add_executable(talker src/publisher_member_function.cpp)
#ament_target_dependencies(talker rclcpp std_msgs)
#
#add_executable(listener src/subscriber_member_function.cpp)
#ament_target_dependencies(listener rclcpp  std_msgs)

#install(TARGETS
#  talker
#  DESTINATION lib/${PROJECT_NAME})

ament_python_install_package(public_py)
install(PROGRAMS
## scripts/joint_group_position_publisher.py
## scripts/joint_trajectory_publisher.py
 public_py/serial_publisher.py
 public_py/publisher_member_function.py
 public_py/subscriber_member_function.py
 DESTINATION lib/${PROJECT_NAME}
)

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

install(
  DIRECTORY launch rviz urdf meshes config 
  DESTINATION share/${PROJECT_NAME}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  set(ament_cmake_copyright_FOUND TRUE)
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()