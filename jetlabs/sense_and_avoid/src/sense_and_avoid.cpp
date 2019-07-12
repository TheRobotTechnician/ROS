#include <ros/ros.h>
#include "geometry_msgs/Twist.h"
#include "std_msgs/Int16.h"
 
enum STATE {FORWARD, BACKWARD, TURN};
STATE state = FORWARD;

double dist;
double timer;
double timestep = 0.25;
 
geometry_msgs::Twist vel_msg;
 
void sonar_callback(const std_msgs::Int16::ConstPtr& msg) {
    dist = msg->data;
}
 
int main(int argc, char **argv) {
    ros::init(argc, argv, "sense_and_avoid_lab");
    ros::NodeHandle nh;
    ros::Subscriber sonar_sub = nh.subscribe("/arduino/sonar_2", 10, &sonar_callback);
    ros::Publisher vel_pub = nh.advertise<geometry_msgs::Twist>("/cmd_vel", 10);
    while (ros::ok()) {
		if (state == FORWARD && dist <= 60 && dist > 0) {
			state = BACKWARD;
			ROS_INFO("Wall detected");
		}
		else if (state == FORWARD && dist > 60) {
			vel_msg.linear.x = 0.7;
			vel_msg.angular.z = 0;
		}
		else if (state == BACKWARD && dist >= 70) {
			state = TURN;
			ROS_INFO("Beginning turn");
			timer = 0;
		}
		else if (state == BACKWARD && dist < 70) {
			vel_msg.linear.x = -0.4;
			vel_msg.angular.z = 0;
		}
		else if (state == TURN && timer >= 1.5) {
			state = FORWARD;
			ROS_INFO("Moving Forward");
		}
		else if (state == TURN && timer < 1.5) {
			timer += timestep;
			vel_msg.linear.x = 0;
			vel_msg.angular.z = -3.0;
		}
        vel_pub.publish(vel_msg);
        ros::Duration(timestep).sleep();
        ros::spinOnce();
    }
}
