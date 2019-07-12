#include <ros/ros.h>
#include "std_msgs/Int16.h"

class SonarSensorExample
{
  public:
    SonarSensorExample();

  private:
    ros::NodeHandle nh;
    ros::Subscriber sonar_sub;
    void sonarCallback(const std_msgs::Int16::ConstPtr& msg);
};

SonarSensorExample::SonarSensorExample()
{
  // method constructor
}

void SonarSensorExample::sonarCallback(const std_msgs::Int16::ConstPtr& msg)
{
  // msg->data returns the value of the range sensor in cm.
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "sonar");
  
  ROS_INFO("Example Output");

  SonarSensorExample sonar;

  ros::spin();
}
