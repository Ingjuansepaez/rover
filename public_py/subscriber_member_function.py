#!/usr/bin/env python3
# Librerias de ROS2
import rclpy
from rclpy.node import Node
from std_msgs.msg import String
import serial
import time
import math

class MinimalSubscriber(Node):
    def __init__(self):
        super().__init__('minimal_subscriber')
        self.subscription = self.create_subscription(String, 'topic', self.listener_callback, 10)

    def listener_callback(self, msg):
        self.get_logger().info('I heard: "%s"')
    
    def write_to_serial_port(self, serial_port):
        data_out = "Switch On the LED"
        try:
            for i in range(1, 20):
                print(data_out)
                serial_port.write(bytes(data_out, 'utf-8')) 
                time.sleep(1.5) 
                #data_in = serial_port.readline() 
                #print(data_in)
        except:
            pass

def main(args=None):
    rclpy.init(args=args)
    microcontroller_port = "/dev/ttyUSB0"
    baudrate = 9600
    minimal_subscriber = MinimalSubscriber()
    try:
        with serial.Serial(microcontroller_port, baudrate, timeout=1) as serial_port:
            minimal_subscriber.write_to_serial_port(serial_port)
    except KeyboardInterrupt:
        minimal_subscriber.destroy_node()
        rclpy.try_shutdown()

if __name__ == '__main__':
    main()
