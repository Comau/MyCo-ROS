速度+力矩前馈模式硬件接口
====

使用硬件接口*myco_hardware_interface::PosVelTrqJointInterface*的控制器可以对myco进行速度+力矩前馈模式控制。**只有使用Version 2版本EtherCAT从站的myco有这个接口**。  
*myco_ros_controllers*软件包提供了一个简单的例子： *myco_pos_vel_controllers/JointTrajectoryController*，它的使用方法如下：

1. 更改myco_robot_bringup/config/myco_arm_control.yaml中的控制器类型:

    ```diff
    - myco_arm_controller:
    -   type: position_controllers/JointTrajectoryController
    -   joints:
    -      - myco_joint1
    -      - myco_joint2
    -      - myco_joint3
    -      - myco_joint4
    -      - myco_joint5
    -      - myco_joint6
    -   constraints:
    -       goal_time: 0.6
    -       stopped_velocity_tolerance: 0.1
    -   stop_trajectory_duration: 0.05
    -   state_publish_rate:  25
    -   action_monitor_rate: 10
    + myco_arm_controller:
    +   type: myco_pos_vel_controllers/JointTrajectoryController
    +   joints:
    +      - myco_joint1
    +      - myco_joint2
    +      - myco_joint3
    +      - myco_joint4
    +      - myco_joint5
    +      - myco_joint6
    +   constraints:
    +       goal_time: 0.6
    +       stopped_velocity_tolerance: 0.1
    +   stop_trajectory_duration: 0.05
    +   state_publish_rate:  25
    +   action_monitor_rate: 10

    ```
    
    前馈速度： 目标速度  
    前馈力矩： 0

2. 按[README.md](../README.md)的说明正常启动机械臂。