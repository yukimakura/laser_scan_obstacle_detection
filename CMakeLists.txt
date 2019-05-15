cmake_minimum_required(VERSION 2.8.3)
project(laser_scan_obstacle_detection)
add_compile_options(-std=c++11)

find_package(catkin REQUIRED COMPONENTS
  geometry_msgs
  roscpp
  rospy
  sensor_msgs
  std_msgs
  object_direction_msgs
)

catkin_package(
  # INCLUDE_DIRS include
  LIBRARIES laser_scan_obstacle_detection
  CATKIN_DEPENDS geometry_msgs roscpp rospy sensor_msgs std_msgs object_direction_msgs
  DEPENDS system_lib
)

include_directories(
  include
  ${catkin_INCLUDE_DIRS}
)

add_executable(obstacle_detection_node src/obstacle_detection_node.cpp src/obstacle_detection.cpp)

target_link_libraries(obstacle_detection_node
  ${catkin_LIBRARIES}
)