 API 简介
=====
### Subscribed Topics:

* **myco_basic_api/joint_goal (sensor_msgs/JointState)**  
令机械臂规划到达指定臂型的路径并执行此路径  
example: function_pub_joints() in myco_robot_bringup/script/cmd_pub.py

* **myco_basic_api/cart_goal (geometry_msgs/PoseStamped)**  
令机械臂规划到达指定空间位置的路径并执行此路径  
example: function_pub_cart_xxx() in myco_robot_bringup/script/cmd_pub.py

* **myco_basic_api/cart_path_goal (geometry_msgs/PoseArray)**  
令机械臂规划一条路径，以直线方式依次经过各个指定的点，并执行此路径  
example: function_pub_cart_path_xxx() in myco_robot_bringup/script/cmd_pub.py

* **myco_arm_controller/command (trajectory_msgs/JointTrajectory)**  
本消息内容为一条轨迹，可令机械臂沿着这条轨迹运动

* **myco_teleop_joint_cmd_no_limit (std_msgs/Int64)**  
本指令为调试机器时使用的指令，不建议客户使用。发送本指令后，机械臂的特定关节会向一个方向移动一点距离，连续发送就会连续运动。  
消息内容含义如下：

	| data | joint       | direction |
	| ------- | ------------| -------------- |
	| 1 | myco_joint1| ccw |
	| -1 | myco_joint1 | cw |
	| 2 | myco_joint2 | ccw |
	| -2 | myco_joint2 | cw |
	| 3 | myco_joint3| ccw |
	| -3 | myco_joint3 | cw |
	| 4 | myco_joint4 | ccw |
	| -4 | myco_joint4 | cw |
	| 5 | myco_joint5| ccw |
	| -5 | myco_joint5 | cw |
	| 6 | myco_joint6 | ccw |
	| -6 | myco_joint6 | cw |

------
### Published Topics:

* **myco_arm_controller/state (control_msgs/JointTrajectoryControllerState)**  
反映机械臂各个关节的状态

* **myco_ros_control/myco/enable_state (std_msgs/Bool)**  
反映此时myco机械臂上电机的使能状态。  
true: 使能  / false: 未使能

* **myco_ros_control/myco/fault_state (std_msgs/Bool)**  
反映此时myco机械臂上电机的报错状态。  
true: 有报错  / false: 无报错

* **myco_basic_api/parameter_updates (dynamic_reconfigure/Config)**  
反映myco_basic_api相关的动态参数，例如: velocity scaling 。

* **myco_basic_api/reference_link_name (std_msgs/String)**  
myco_basic_api节点计算时所使用的参考基坐标系的名字

* **myco_basic_api/end_link_name (std_msgs/String)**  
myco_basic_api节点计算时所使用的末端坐标系的名字

------
### Services:

* **myco_basic_api/get_reference_link (std_srvs/SetBool)**  
呼叫本服务得到的反馈信息中会包含myco_basic_api规划时的参考基坐标系名

* **myco_basic_api/get_end_link (std_srvs/SetBool)**  
呼叫本服务得到的反馈信息中会包含myco_basic_api规划时的末端坐标系名

* **myco_basic_api/stop_teleop (std_srvs/SetBool)**  
呼叫本服务会令机械臂停止运动

* **myco_basic_api/set_parameters (dynamic_reconfigure/Reconfigure)**  
设置myco_basic_api相关的动态参数，例如: velocity scaling  
example: set_parameters() in myco_robot_bringup/script/set_velocity_scaling.py

* **myco_ros_control/myco/get_txpdo (std_srvs/SetBool)**  
呼叫本服务得到的反馈信息中会包含机械臂上从站的txpdo信息

* **myco_ros_control/myco/get_rxpdo (std_srvs/SetBool)**  
呼叫本服务得到的反馈信息中会包含机械臂上从站的rxpdo信息

* **myco_ros_control/myco/get_current_position (std_srvs/SetBool)**  
呼叫本服务得到的反馈信息中会包含机械臂各轴的位置的编码器值  

* **myco_ros_control/myco/recognize_position (std_srvs/SetBool)**  
呼叫本服务可使机械臂进行姿态识别

* **myco_ros_control/myco/io_port1/write_do (myco_robot_msgs/mycoIODWrite)**  
向DO中写入内容  
example:  
	```
	rosservice call /myco_ros_control/myco/io_port1/write_do "digital_output: 0x001b"
	```

* **myco_ros_control/myco/io_port1/read_di (myco_robot_msgs/mycoIODRead)**  
从DI中读取内容  
example:  
	```
	rosservice call /myco_ros_control/myco/io_port1/read_di "data: true"
	```

* **myco_ros_control/myco/io_port1/get_txpdo (std_srvs/SetBool)**  
呼叫本服务得到的反馈信息中会包含IO从站的txpdo信息

* **myco_ros_control/myco/io_port1/get_rxpdo (std_srvs/SetBool)**  
呼叫本服务得到的反馈信息中会包含IO从站的rxpdo信息

* **myco_module_open_brake_slaveX(std_srvs/SetBool)**  
在模组未使能情况下，呼叫本服务可以打开相应模组的抱闸  
for example:
	```sh
	rosservice call myco_module_open_brake_slave1 "data: true"
	```

* **myco_module_close_brake_slaveX(std_srvs/SetBool)**  
在模组未使能情况下，呼叫本服务可以关闭相应模组的抱闸  
for example:
	```sh
	rosservice call myco_module_close_brake_slave1 "data: true"
	```

***以下Services都会被myco Control Panel 界面调用， 不建议客户直接使用***

* **myco_basic_api/enable_robot (std_srvs/SetBool)**  
呼叫本服务可使机械臂使能。

* **myco_ros_control/myco/enable_robot (std_srvs/SetBool)**  
推荐使用*myco_basic_api/enable_robot*服务来使能机械臂。呼叫本服务可直接使机械臂使能，所以需自行处理*controllers*的状态。详见： http://wiki.ros.org/controller_manager 。

* **myco_basic_api/disable_robot (std_srvs/SetBool)**  
呼叫本服务可使机械臂去使能。

* **myco_ros_control/myco/disable_robot (std_srvs/SetBool)**  
推荐使用*myco_basic_api/disable_robot*服务来使机械臂去使能。呼叫本服务可直接使机械臂去使能，所以需自行处理*controllers*的状态。详见： http://wiki.ros.org/controller_manager 。  

* **myco_ros_control/myco/clear_fault (std_srvs/SetBool)**  
呼叫本服务可使机械臂清除报错状态。  

* **myco_basic_api/set_reference_link (myco_robot_msgs/SetString)**  
设置myco_basic_api节点计算时所使用的参考基坐标系  

* **myco_basic_api/set_end_link (myco_robot_msgs/SetString)**  
设置myco_basic_api节点计算时所使用的末端坐标系  

* **myco_basic_api/joint_teleop (myco_robot_msgs/SetInt16)**  
呼叫本服务后，机械臂的特定关节会向一个方向一直移动，直到运动到极限位置或用户调用myco_basic_api/stop_teleop，请慎用。

	消息内容含义如下：

	| data | joint       | direction |
	| ------- | ------------| -------------- |
	| 1 | myco_joint1| ccw |
	| -1 | myco_joint1 | cw |
	| 2 | myco_joint2 | ccw |
	| -2 | myco_joint2 | cw |
	| 3 | myco_joint3| ccw |
	| -3 | myco_joint3 | cw |
	| 4 | myco_joint4 | ccw |
	| -4 | myco_joint4 | cw |
	| 5 | myco_joint5| ccw |
	| -5 | myco_joint5 | cw |
	| 6 | myco_joint6 | ccw |
	| -6 | myco_joint6 | cw |

* **myco_basic_api/cart_teleop (myco_robot_msgs/SetInt16)**  
呼叫本服务后，机械臂会沿着一个空间方向一直移动，直到运动到极限位置或用户调用myco_basic_api/stop_teleop，请慎用。

	消息内容含义如下：

	| data | axis       | direction |
	| ------- | ------------| -------------- |
	| 1 | X | positive |
	| -1 | X | negative |
	| 2 | Y | positive |
	| -2 | Y | negative |
	| 3 | Z | positive |
	| -3 | Z | negative |
	| 4 | Rx | ccw |
	| -4 | Rx | cw |
	| 5 | Ry | ccw |
	| -5 | Ry | cw |
	| 6 | Rz | ccw |
	| -6 | Rz | cw |

* **myco_basic_api/home_teleop (std_srvs/SetBool)**  
呼叫本服务后，机械臂会一直运动，直到回到零位置或用户调用myco_basic_api/stop_teleop，请慎用。
