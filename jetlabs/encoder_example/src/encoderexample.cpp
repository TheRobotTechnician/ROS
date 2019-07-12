#include <ros/ros.h>
#include "std_msgs/Int16.h"

class MotorEncoderExample
{
  public:
    MotorEncoderExample();

  private:
    ros::NodeHandle nh;
    ros::Subscriber sonar_sub;
    void leftEncoderCallback(const std_msgs::Int16::ConstPtr& msg);
    void rightEncoderCallback(const std_msgs::Int16::ConstPtr& msg);
};

MotorEncoderExample::MotorEncoderExample()
{
  // code
}

void MotorEncoderExample::leftEncoderCallback(const std_msgs::Int16::ConstPtr& msg)
{
  // msg->data returns the number of ticks moved
}

void MotorEncoderExample::rightEncoderCallback(const std_msgs::Int16::ConstPtr& msg)
{
  // msg->data returns the number of ticks moved
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "encoder");
  
  ROS_INFO("Example Output");

  MotorEncoderExample encoder;

  ros::spin();
}