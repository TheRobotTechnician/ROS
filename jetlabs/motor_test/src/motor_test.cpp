#include <ros/ros.h>
#include "geometry_msgs/Twist.h"
#include "std_msgs/Int16.h"

#define LINEAR_SPEED 0.7
#define ANGULAR_SPEED 0.5

class MotorTest
{
  public:
    MotorTest();
  private:
    ros::Publisher vel_pub;
    ros::NodeHandle nh;
    geometry_msgs::Twist vel_msg;
    void moveForward();
    void moveBackward();
    void turnRobot();
};

MotorTest::MotorTest()
{
  vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);

  MotorTest::moveForward();
  ros::Duration(2.0).sleep(); // Wait 2 seconds
  MotorTest::turnRobot();
  ros::Duration(2.0).sleep(); // Wait 2 seconds
  MotorTest::moveBackward();
  ros::Duration(2.0).sleep(); // Wait 2 seconds

  ros::shutdown();
}

void MotorTest::moveForward()
{
  // Write code here
}

void MotorTest::moveBackward()
{
  // Write code here
}

void MotorTest::turnRobot()
{
  // Write code here
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "motor_test");

  MotorTest motor_test;

  ros::spin();
}
