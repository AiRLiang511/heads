#include <ros/ros.h>
#include <geometry_msgs/Pose.h>
#include <gazebo_msgs/ModelState.h>
#include <std_msgs/String.h>

ros::Publisher modelStatePub;

void poseCallback(const geometry_msgs::Pose::ConstPtr& poseMsg)
{
   

    gazebo_msgs::ModelState modelStateMsg;
    modelStateMsg.model_name = "model";  // 替换成模型名称
    modelStateMsg.pose = *poseMsg;  // 将接收到的 pose 直接赋值给模型的位置

    
    modelStatePub.publish(modelStateMsg);// 发布移动命令给 Gazebo 中的模型
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "controll");
    ros::NodeHandle nh;

    // 用于发布移动命令给 Gazebo 中的模型
    modelStatePub = nh.advertise<gazebo_msgs::ModelState>("/gazebo/set_model_state", 10);

    // 订阅 "/desired_pose" 话题，消息类型为 Pose
    ros::Subscriber poseSub = nh.subscribe("/desired_pose", 10, poseCallback);

    ros::spin();

    return 0;
}

