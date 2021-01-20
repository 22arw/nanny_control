teleop_twist_joy [![Build Status](https://travis-ci.org/ros-teleop/teleop_twist_joy.svg?branch=indigo-devel)](https://travis-ci.org/ros-teleop/teleop_twist_joy)
================

Simple joystick teleop for twist robots. See [ROS Wiki](http://wiki.ros.org/teleop_twist_joy)

# First time setting up Xbox controller
Install xbox driver: 
```
sudo apt-get install xboxdrv
```

Install sysfsutils for bluetooth connection:
```
sudo apt install sysfsutils
```

Edit file with "sudo nano /etx/sysfs.conf":
```
at bottom of file add : /module/bluetooth/parameters/disable_ertm=1 (Restart device for changes to take effect)
```
Connecting Xbox Controller
```
rosparam set joy_node/dev "/dev/input/js0"

rosrun joy joy_node

Connect controller via bluetooth.
```
# Launch

Bring up robot in virtual store
Run.
```
roslaunch nanny_bringup nanny_robot_store_world.launch
```
Start the joy node to connect controller 
Run.
```
rosrun joy joy_node
```
Connect controller via bluetooth

Run.
```
roslaunch nanny_control teleop_joy.launch
```

To control movements.
```
Hold L1 to activate the robot (keep holding to drive)

Using the left analog stick will move you forward or backwards 

Right analog stick will allow you to turn right or left 
```



