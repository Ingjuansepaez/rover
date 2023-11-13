#!/usr/bin/env python3
# ROS2 Libraries
import rclpy
from rclpy.node import Node
from std_msgs.msg import Int16
from geometry_msgs.msg import Twist
# Python Libraries
import serial

class SerialPortWriter(Node):
    def __init__(self):
        super().__init__('serial_port_writer')
        # Subscribing to variable to control
        self.position_subscriber = self.create_subscription(Twist, '/diff_cont/cmd_vel_unstamped', self.write_to_serial_port, 10)
        self.position_msg = Twist()

        # Serial port's information
        self.microcontroller_port = "/dev/ttyUSB0"
        self.microcontroller_baudrate = 9600
        self.serial_port = serial.Serial(self.microcontroller_port, self.microcontroller_baudrate, timeout=1)

    def write_to_serial_port(self, position_msg):
        self.position_msg = position_msg
        print(self.position_msg )
        data_out = f"{self.position_msg.linear.x:.2f}"  # Convertir el número de punto flotante en una cadena con 2 decimales
        data_out2 = f"{self.position_msg.angular.z:.2f}" # Convertir numero a string
        data_total = "["+data_out+","+data_out2+"];"
        self.serial_port.write(data_total.encode())  # Escribir datos en el microcontrolador a través del puerto serie
        #print(f"{self.position_msg.linear.x}")  # Imprimir la velocidad lineal en la consola
        print(data_total)
        print(self.serial_port.write(data_total.encode()))

def main(args=None):
    rclpy.init(args=args)
    serial_port_writer_node = SerialPortWriter()
    try:
        rclpy.spin(serial_port_writer_node)
    except KeyboardInterrupt:
        serial_port_writer_node.destroy_node()
        rclpy.shutdown()

if __name__ == '__main__':
    main()

