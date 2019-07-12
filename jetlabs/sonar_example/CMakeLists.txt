cmake_minimum_required(VERSION 2.8.3)
project(sonar_example)

find_package(catkin REQUIRED COMPONENTS
  roscpp
  rospy
  std_msgs
  cv_bridge
  image_transport
)

catkin_package(
  CATKIN_DEPENDS roscpp rospy std_msgs cv_bridge image_transport
)

include_directories(
  ${catkin_INCLUDE_DIRS}
)

add_executable(sonar_example src/sonarsensorexample.cpp)
target_link_libraries(sonar_example ${catkin_LIBRARIES})
