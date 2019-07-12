cmake_minimum_required(VERSION 2.8.3)
project(jet_playground)

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

add_executable(playground src/playground.cpp)
target_link_libraries(playground ${catkin_LIBRARIES})
