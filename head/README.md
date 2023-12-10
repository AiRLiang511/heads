1.先编译head文件

2.进入head文件夹 打开一个终端执行命令
source devel/setup.bash

然后执行命令roslaunch move head_world.launch

3.新开一个终端 执行命令
source devel/setup.bash，
然后执行rosrun move move_node

4.再开一个新终端，执行命令
rostopic pub  /desired_pose geometry_msgs/Pose

5.如果步骤2中head_world打开失败，则需新开一个gazebo，导入model文件夹中的model（gazebo中insert的add path）
