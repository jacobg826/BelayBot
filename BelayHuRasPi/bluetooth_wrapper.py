import serial
from time import sleep

class BluetoothWrapper:

    def __init__(self, baud, timeout):
        self.ser = serial.Serial("/dev/rfcomm0", baudrate=baud, timeout = timeout)

    def get_byte(self, size):
        return self.ser.read(size = size)
    
    def close(self):
        self.ser.close()

