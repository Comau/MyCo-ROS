力矩前馈模式硬件接口
====

使用硬件接口*myco_hardware_interface::PosTrqJointInterface*的控制器可以对myco进行力矩前馈模式控制。*myco_ros_controllers*软件包提供了一个简单的例子： *myco_pos_trq_controllers/JointTrajectoryController*，它的使用方法如下：

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
    +   type: myco_pos_trq_controllers/JointTrajectoryController
    +   joints:
    +      - myco_joint1
    +      - myco_joint2
    +      - myco_joint3
    +      - myco_joint4
    +      - myco_joint5
    +      - myco_joint6
    +   velocity_ff:
    +      myco_joint1: 1
    +      myco_joint2: 1
    +      myco_joint3: 1
    +      myco_joint4: 1
    +      myco_joint5: 1
    +      myco_joint6: 1
    +   constraints:
    +       goal_time: 0.6
    +       stopped_velocity_tolerance: 0.1
    +   stop_trajectory_duration: 0.05
    +   state_publish_rate:  25
    +   action_monitor_rate: 10

    ```
    
    velocity_ff: 此参数会与相应轴的目标速度相乘，以得到相应轴的与速度相关的前馈力矩。

2. 按[README.md](../README.md)的说明正常启动机械臂。