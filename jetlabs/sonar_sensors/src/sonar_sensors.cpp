#include <ros/ros.h>
#include "std_msgs/Int16.h"
  
void sonar2_callback(const std_msgs::Int16::ConstPtr& msg){
    ROS_INFO("Distance (cm): %d", msg->data);
}
 
int main(int argc, char **argv){
    ros::init(argc, argv, "sonar_sensors");
    ros::NodeHandle nh;
    std_msgs::Int16 msg;
 
    ros::Subscriber sonar_sub = nh.subscribe("/arduino/sonar_2", 10, &sonar2_callback);
    
    ros::spin();
}
