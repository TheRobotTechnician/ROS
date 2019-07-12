#include <ros/ros.h>
#include "geometry_msgs/Twist.h"
#include "std_msgs/Int16.h"

class PlayGround
{
  public:
    PlayGround();

  private:
    ros::NodeHandle nh;

    ros::Publisher vel_pub;

    geometry_msgs::Twist vel_msg;
};

PlayGround::PlayGround()
{

}


int main(int argc, char **argv)
{
  ros::init(argc, argv, "playground");

  PlayGround playground;

  ros::spin();
}
