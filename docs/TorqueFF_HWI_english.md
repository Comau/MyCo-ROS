Torque feed forward mode hardware interface
====

A controller with the hardware interface *'myco_hardware_interface::PosTrqJointInterface'* can control the myco in torque feed forward mode. There is a sample example in the *myco_ros_controllers* package: *'myco_pos_trq_controllers/JointTrajectoryController'*. You can use it by the following method.

1. Change the controller type in the file *myco_robot_bringup/config/myco_arm_control.yaml*:

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
    
    velocity_ff: velocity related feedforward factor. velocity_ff * desired_velocity = velocity_related_feedforward_torque

2. Start the robot arm normally as described in the [README_english.md](../README_english.md)