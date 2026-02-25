 API description
=====
### Subscribed Topics:

* **myco_basic_api/joint_goal (sensor_msgs/JointState)**  
make the robot move to a position in joint space after planning a trajectory.  
example: function_pub_joints() in myco_robot_bringup/script/cmd_pub.py

* **myco_basic_api/cart_goal (geometry_msgs/PoseStamped)**  
make the robot move to a position in cartesian coordination system after planning a trajectory.  
example: function_pub_cart_xxx() in myco_robot_bringup/script/cmd_pub.py

* **myco_basic_api/cart_path_goal (geometry_msgs/PoseArray)**  
make the robot move through the assigned positions in cartesian coordination system after planning a trajectory composed of lines.  
example: function_pub_cart_path_xxx() in myco_robot_bringup/script/cmd_pub.py

* **myco_arm_controller/command (trajectory_msgs/JointTrajectory)**  
This topic contain a trajectory. When you publish this topic, the robot will move along the trajectory.

* **myco_teleop_joint_cmd_no_limit (std_msgs/Int64)**  
This is a topic for developer, customers are not supposed to use it. A particular joint will move a little distance after subscribing this topic for once.

	Meaning of the data in the topic:

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
The current status of the joints.

* **myco_ros_control/myco/enable_state (std_msgs/Bool)**  
The servo status of the robot.  
true: enabled / false: disabled

* **myco_ros_control/myco/fault_state (std_msgs/Bool)**  
The fault status of the robot.  
true: warning / false: no fault

* **myco_basic_api/parameter_updates (dynamic_reconfigure/Config)**  
The value of the dynamic parameters of myco_basic_api, e.g. velocity scaling.

* **myco_basic_api/reference_link_name (std_msgs/String)**  
The reference link in the calculations of the myco_basic_api node

* **myco_basic_api/end_link_name (std_msgs/String)**  
The end link in the calculations of the myco_basic_api node

------
### Services:

* **myco_basic_api/get_reference_link (std_srvs/SetBool)**  
You can get the reference link name of *myco_basic_api* from the response of this service.

* **myco_basic_api/get_end_link (std_srvs/SetBool)**  
You can get the end link name of *myco_basic_api* from the response of this service.

* **myco_basic_api/stop_teleop (std_srvs/SetBool)**  
Make the robot stop moving.

* **myco_ros_control/myco/get_txpdo (std_srvs/SetBool)**  
You can get the content of TxPDOs from the response of this service.

* **myco_ros_control/myco/get_rxpdo (std_srvs/SetBool)**  
You can get the content of RxPDOs from the response of this service.

* **myco_ros_control/myco/get_current_position (std_srvs/SetBool)**  
You can get the count values of the current joint positions from the response of this service.

* **myco_basic_api/set_parameters (dynamic_reconfigure/Reconfigure)**  
Set the dynamic parameters of myco_basic_api, e.g. velocity scaling  
example: set_parameters() in myco_robot_bringup/script/set_velocity_scaling.py

* **myco_ros_control/myco/recognize_position (std_srvs/SetBool)**  
Recognize the position of joints.

* **myco_ros_control/myco/io_port1/write_do (myco_robot_msgs/mycoIODWrite)**  
Write a value into DO  
example:  
	```
	rosservice call /myco_ros_control/myco/io_port1/write_do "digital_output: 0x001b"
	```

* **myco_ros_control/myco/io_port1/read_di (myco_robot_msgs/mycoIODRead)**  
Read the value from DI  
example:  
	```
	rosservice call /myco_ros_control/myco/io_port1/read_di "data: true"
	```

* **myco_ros_control/myco/io_port1/get_txpdo (std_srvs/SetBool)**  
You can get the content of TxPDOs from the response of this service.

* **myco_ros_control/myco/io_port1/get_rxpdo (std_srvs/SetBool)**  
You can get the content of RxPDOs from the response of this service.

* **myco_module_open_brake_slaveX(std_srvs/SetBool)**  
When the module is not enabled, you can open the brake of the corresponding module using this service.  
for example:
	```sh
	rosservice call myco_module_open_brake_slave1 "data: true"
	```

* **myco_module_close_brake_slaveX(std_srvs/SetBool)**  
When the module is not enabled, you can close the brake of the corresponding module using this service.  
for example:
	```sh
	rosservice call myco_module_close_brake_slave1 "data: true"
	```

***Following are the services, that support "myco Control Panel" interface.  customers are not supposed to use them.***

* **myco_basic_api/enable_robot (std_srvs/SetBool)**  
Enable the robot.  

* **myco_ros_control/myco/enable_robot (std_srvs/SetBool)**  
The recommand service for enabling the robot is *myco_basic_api/enable_robot*. The robot will be enabled directly when you call this service. So you may need to deal with the status of controllers by yourself. For details: http://wiki.ros.org/controller_manager .

* **myco_basic_api/disable_robot (std_srvs/SetBool)**  
Disable the robot.  

* **myco_ros_control/myco/disable_robot (std_srvs/SetBool)**  
The recommand service for disabling the robot is *myco_basic_api/disable_robot*. The robot will be disabled directly when you call this service. So you may need to deal with the status of controllers by yourself. For details: http://wiki.ros.org/controller_manager .

* **myco_ros_control/myco/clear_fault (std_srvs/SetBool)**  
Clear fault.  

* **myco_basic_api/set_reference_link (myco_robot_msgs/SetString)**  
Set the reference link in the calculations of the myco_basic_api node  

* **myco_basic_api/set_end_link (myco_robot_msgs/SetString)**  
Set the end link in the calculations of the myco_basic_api node  

* **myco_basic_api/joint_teleop (myco_robot_msgs/SetInt16)**  
When this service is called, a particular joint will move in a direction and will NOT stop until it reach the limit position or myco_basic_api/stop_teleop is called. Please be careful when you call this service.

	Meaning of the data in the service:

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
When this service is called, the end link of the robot will move in a direction in cartsian coordination system and will NOT stop until it reach the limit position or myco_basic_api/stop_teleop is called. Please be careful when you call this service.

	Meaning of the data in the service:

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
When this service is called, the robot will move to home position and will NOT stop until it reach the home position or myco_basic_api/stop_teleop is called. Please be careful when you call this service.
