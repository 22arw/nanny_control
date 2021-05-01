# nanny_control

This repository contains all of the necessary code for the control of the Nanny. This includes the differential drive controller, teleop operations, and files needed for ros_canopen.

To control the Nanny within Gazebo you will need to have teleop_twist_joy (joystick) or teleop_twist_keyboard (keyboard). These packages send velocity commands to our robot cmd_vel in simulation so we are able to move the robot around using the keys or joysticks.


For instructions on how to setup the Joystick see the README for [teleop_twist_joy](https://github.com/22arw/nanny_control/blob/main/teleop_twist_joy/README.md) and to setup the keyboard see the README for [teleop_twist_keyboard](https://github.com/22arw/nanny_control/blob/main/teleop_twist_keyboard/README.md) 

# CANOpen 

More detailed information regarding ros_canopen can be found on the [ROS Wiki](http://wiki.ros.org/ros_canopen) page.

Install Muparser
```
sudo apt-get install libmuparser-dev
```
Install ros_canopen
```
sudo apt-get install ros-melodic-ros-canopen
```
Clone CANOpen GitHub
```
cd catkin_ws
cd src
git clone https://github.com/ros-industrial/ros_canopen.git
cd ..
catkin_make
```
SocketCan

Allows you to send can messages and create can dumps see [CAN communications](https://sgframework.readthedocs.io/en/latest/cantutorial.html) for usage.

Install can-utils
```
sudo apt-get install can-utils
```

CANOpen Configuration Files

can.yaml: sets up the bus and initialize the driver for SocketCANInterface

nanny_motor.yaml: Initialize the nodes, sets the defaults for each node and gives path to the Eds file 

test_limits: sets limits on the joints leftwheel/rightwheel

Launch 
```
cd catkin_ws/
source devel/setup.bash
roslaunch nanny_control nanny_can.launch
```

# ROS-DRIVER

This package allows us to connect our Computers to our motor controller through a serial connection to output commands to our motor controller from cmd_vel for more info visit the [GitHub](https://github.com/Roboteq-Inc/ROS-Driver/tree/FW2.1/ROS-Driver-Update)

Clone ROS-Driver repo
```
cd catkin_ws
cd src
git clone https://github.com/Roboteq-Inc/ROS-Driver.git
cd ..
catkin_make
```

Launch 
```
cd catkin_ws/
source devel/setup.bash
roslaunch roboteq_motor_controller_driver driver.launch
```
