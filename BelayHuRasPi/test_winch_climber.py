from bluetooth_wrapper import BluetoothWrapper
from acceleration_calc import AccCalc
from Motor import MotorControl
from gpiozero import DigitalOutputDevice
import numpy as np
import pylab as plt
import subprocess
import time
import json


#Arrays for plots
climberArray = np.zeros(1)
winchArray = np.zeros(1)
accArray = np.zeros(1)
timeArray = np.zeros(1)


#1 selects constant climbing
#2 selects constant climbing and a fall
programSelector = 2
    
#Variables used to calculate position
mot = MotorControl()
time_dt = time.time()
prev_time_dt = 0
calc = AccCalc()

for i in range(1500):
    
    prev_time_dt = time_dt
    time_dt = time.time()
    numAccPoints = len(accArray)
    
    if(programSelector == 1):
        if(i == 10):
            acc = 9
        elif(i == 500):
            acc = 0
        else:
            acc = 0
    elif(programSelector == 2):
        if(i == 10):
            acc = 9
        elif(i == 500):
            acc = -9
        else:
            acc = 0
    else:
            acc = 0
        
    numAccPoints = len(accArray)
        
    accArray = np.append(accArray, acc)

    dt = .01
    time.sleep(.01)
        
    timeArray = np.append(timeArray, timeArray[i]+dt)
    
    change = calc.new_datapoint(acc, dt)
    z_climber = calc.pos
    climberArray = np.append(climberArray, z_climber)
    mot.rotate(z_climber, acc)
    
    winchArray = np.append(winchArray, mot.z_winch)

plt.figure(0, figsize = (5,5))
plt.subplot(3,1,1)
plt.plot(timeArray, climberArray)
plt.title('Climber Position')
plt.xlabel('Seconds')
plt.ylabel('Meters')
plt.subplot(3,1,2)
plt.plot(timeArray, winchArray)
plt.title('Winch Position')
plt.xlabel('Seconds')
plt.ylabel('Meters')
plt.subplot(3,1,3)
plt.plot(timeArray, accArray)
plt.title('Cimber Acceleration')
plt.xlabel('Seconds')
plt.ylabel('Meters/second^2')
plt.tight_layout()      
plt.show()

mot.winch_in.off()
mot.winch_out.off()