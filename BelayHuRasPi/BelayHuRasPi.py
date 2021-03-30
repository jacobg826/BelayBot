from bluetooth_wrapper import BluetoothWrapper
from acceleration_calc import AccCalc
from Motor import MotorControl
from gpiozero import DigitalOutputDevice
import numpy as np
import pylab as plt
import subprocess
import time
import json



DATA_BYTES_PER_READING = 2 #Acceleration data (signed)
HEADER_BYTES = 2 #Time between readings in ms (unsigned)
HEADER = [1, 2]
TIME_BYTES = 2
TOTAL_BYTES_PER_READING = DATA_BYTES_PER_READING + HEADER_BYTES + TIME_BYTES
DATA_BITS_PER_READING = 8 * DATA_BYTES_PER_READING
HALF_POINT = 2 ** (DATA_BITS_PER_READING - 1)
BAUDRATE = 9600
TIMEOUT = None 

    
#May need to change this function when we work out a convention
#for byte values between microcontroller and pi
def byte_to_acc(byt):
    
    #Get unsigned int value from bytes as twos complement
    int_val = int.from_bytes(byt, "little")
    if(int_val >=  HALF_POINT):
        int_val = int_val - (1 << DATA_BITS_PER_READING)
    
    #Treat max value(positive) as 2G and min value(negative) as -2G 
    #Ex: 2 byte -> min: -524288, max: 524287
    #Return as m/s^2, ex 1G = 9.8 m/s^2
    acc = (19.6 * int_val)/(HALF_POINT)
    rounded_acc = np.around(acc, decimals = 1)
    return acc

    
def wait_until_header(bw, mot):
    header_list = [None] * HEADER_BYTES
    while(True):
        #Get first header
        head_byt = bw.get_byte(1)
        h0 = head_byt[0]
        
        #Add it to the header_list and remove first
        del header_list[0]
        header_list.append(h0)
        
        #print("Checking for header: " + str(head_byt)) #For debugging
        if(header_list == HEADER):
            #print("Header Found")
            return 0
        
        #Check if button press is registered
        elif(header_list == [1,1]):
            #Check if climber has fallen
            if(mot.fall_flag == 1):
                #begin climbbing again
                mot.fall_flag = 0;
            else:
                mot.lower_flag = 1;
        

#numpy

with open("config.json") as json_data_file:
    config = json.load(json_data_file)
    
subprocess.run("sudo systemctl start bluetooth".split())
time.sleep(1)
try:
    
    addr = config["addr"]
    connect_string = ("sudo rfcomm connect hci0 " + addr)
    p = subprocess.Popen(connect_string.split())
    pid = p.pid
    try:
        fail = "Get info failed: No such device"
        check_con = fail
        while(check_con.strip() == fail):
            check_con = subprocess.run("sudo rfcomm show -i 0", shell=True, stderr=subprocess.PIPE, stdout=subprocess.PIPE).stderr.decode("utf-8")
            time.sleep(0.1)
            
            
        mot = MotorControl()
        bw = BluetoothWrapper(BAUDRATE, TIMEOUT)
        time_dt = time.time()
        prev_time_dt = 0

        print("Connection Successful")
        try:
            calc = AccCalc()
            for i in range(1500):
                wait_until_header(bw,mot)
                
                #Get Data Bytes
                data_byt = bw.get_byte(DATA_BYTES_PER_READING)
                prev_time_dt = time_dt
                time_dt = time.time()
                acc = byte_to_acc(data_byt)
                    

                
                #Get time bytes
                dt = time_dt - prev_time_dt
                time.sleep(.001)
                
                change = calc.new_datapoint(acc, dt)
                z_climber = calc.pos
                climberArray = np.append(climberArray, z_climber)
                mot.rotate(z_climber, acc)
                
                winchArray = np.append(winchArray, mot.z_winch)
                
        finally:
            bw.close()
    finally:
        subprocess.run(["sudo", "kill", str(pid)])
        subprocess.run("sudo rfcomm release hci0".split())
finally:
    subprocess.run("sudo systemctl stop bluetooth".split())
