MyCo Robot
======

<p align="center">
  <img src="docs/images/MyCo-3.5-0.95.webp" />
</p>

This repository provides ROS support for the myco Robot. The recommend operating environment is on Ubuntu 18.04 with ROS Melodic. So far These packages haven't been tested in other environment.

### Installation

#### Ubuntu 18.04 + ROS Melodic

**Install some important dependent software packages:**
```sh
$ sudo apt-get install ros-melodic-soem ros-melodic-gazebo-ros-control ros-melodic-ros-control ros-melodic-ros-controllers
```
**Install or upgrade MoveIt!.** 

If you have installed MoveIt!, please make sure that it's been upgraded to the latest version.

Install/Upgrade MoveIt!:

```sh
$ sudo apt-get update
$ sudo apt-get install ros-melodic-moveit-*
```

install trac_ik plugin
```sh
sudo apt-get install ros-melodic-trac-ik
```

**Install this repository from Source**

First set up a catkin workspace (see [this tutorials](http://wiki.ros.org/catkin/Tutorials)).  
Then clone the repository into the src/ folder. It should look like /path/to/your/catkin_workspace/src/myco_robot.  
Make sure to source the correct setup file according to your workspace hierarchy, then use catkin_make to compile.  

Assuming your catkin workspace folder is ~/catkin_ws, you should use the following commands:
```sh
$ cd ~/catkin_ws/src
$ git clone https://github.com/Comau/MyCo-ROS.git
$ cd ..
$ catkin_make
$ source devel/setup.bash
```


---

### Usage with Gazebo Simulation

***There are launch files available to bringup a simulated robot - either myco3, myco5 or myco10.  
In the following the commands for myco3 are given. For myco5 or myco10, simply replace the prefix accordingly.***

Bring up the simulated robot in Gazebo:
```sh
$ roslaunch myco_gazebo MyCo-3-0.59_empty_world.launch```

Start up RViz with a configuration including the MoveIt! Motion Planning plugin:
```sh
$ roslaunch myco_3_590mm_moveit_config moveit_planning_execution.launch
```
If you don't want to start up RViz at the moment, just run:
```sh
$ roslaunch myco_3_590mm_moveit_config moveit_planning_execution.launch display:=false
```

Start up myco basic api and "myco Control Panel" interface:
```sh
$ roslaunch myco_basic_api myco_basic_api.launch
```

> Tutorial about how to use MoveIt! RViz plugin: [docs/moveit_plugin_tutorial_english.md](docs/moveit_plugin_tutorial_english.md)  
Tips:
Every time you want to plan a trajectory, you should set the start state to current first.


---

###  Usage with real Hardware

***There are launch files available to bringup a real robot - either myco3, myco5 or myco10.  
In the following the commands for myco3 are given. For myco5 or myco10, simply replace the prefix accordingly.***

Put the file *myco_drivers.yaml*, that you got from the vendor, into the folder myco_robot_bringup/config/.

Connect myco to the computer with a LAN cable. Then confirm the ethernet interface name of the connection with `ifconfig`. The default ethernet name is eth0. If the ethernet name is not eth0, you should correct the following line in the file *myco_robot_bringup/config/myco_drivers.yaml* 

```
myco_ethernet_name: eth0
```

Load myco robot model：
```sh
$ roslaunch myco_robot_bringup MyCo-3-0.59_bringup.launch
```

Bring up the hardware of myco. Before bringing up the hardware, you should setup Linux with PREEMPT_RT properly. There is a [tutorial](https://wiki.linuxfoundation.org/realtime/documentation/howto/applications/preemptrt_setup). There are two versions of myco EtherCAT slaves. Please bring up the hardware accordingly.

```sh
$ sudo chrt 10 bash
$ roslaunch myco_robot_bringup myco_ros_control.launch
```

Start up RViz with a configuration including the MoveIt! Motion Planning plugin:
```sh
$ roslaunch myco_3_590mm_moveit_config moveit_planning_execution.launch
```
If you don't want to start up RViz at the moment, just run:
```sh
$ roslaunch myco_3_590mm_moveit_config moveit_planning_execution.launch display:=false
```

Start up myco basic api and "myco Control Panel" interface:
```sh
$ roslaunch myco_basic_api myco_basic_api.launch
```

Enable the servos of myco with "myco Control Panel" interface: if there is no "Warning", just press the "Servo On" button to enable the robot. If there is "Warning", press the "Clear Fault" button first and then press the "Servo On" button.

Tutorial about how to use MoveIt! RViz plugin: [docs/moveit_plugin_tutorial_english.md](docs/moveit_plugin_tutorial_english.md)  
Tips:
Every time you want to plan a trajectory, you should set the start state to current first.

Before turning the robot off, you should press the "Servo Off" button to disable the robot.

For more information about API, see [docs/API_description_english.md](docs/API_description_english.md)
