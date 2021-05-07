#!/usr/bin/env python
import rospy
from geometry_msgs.msg import Twist
from std_msgs.msg import String

def callback(data):
    #Log the m/s that we see
  #  rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)

    #Create a new publisher
    velocity_publisher = rospy.Publisher('/cmd_vel', Twist, queue_size=10)
    vel_msg = Twist()

    #Get the m/s for linear x and angular z
    metersecx = data.linear.x
    metersecangz = data.angular.z

    #Convert from m/s to rpm
    rpmx = (metersecx/(2*3.14*(0.1564/2)))*60
    rpmangz = (metersecangz/(2*3.14*(0.1564/2)))*60

    #Set the values we need
    vel_msg.linear.x = rpmx
    vel_msg.linear.y = 0
    vel_msg.linear.z = 0
    vel_msg.angular.x = 0
    vel_msg.angular.y = 0
    vel_msg.angular.z = rpmangz

    #Publish our new message
    velocity_publisher.publish(vel_msg)


def move():
    # Starts a new node
    rospy.init_node('mstorpm', anonymous=True)

    rospy.Subscriber("/diff_drive_ctrl/cmd_vel", Twist, callback)

    rospy.spin()

if __name__ == '__main__':
    try:
        #Testing our function
        move()
    except rospy.ROSInterruptException: pass
