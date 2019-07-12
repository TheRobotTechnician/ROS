cmake_minimum_required(VERSION 2.8.3)
project(encoder_example)

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

add_executable(encoder_example src/encoderexample.cpp)
target_link_libraries(encoder_example ${catkin_LIBRARIES})
