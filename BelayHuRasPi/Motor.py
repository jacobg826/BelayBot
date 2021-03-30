from gpiozero import DigitalOutputDevice
import time
import numpy as np

class MotorControl:
    
    def __init__(self):
        
        #Define a winch carabiner height variable (meters)
        self.z_winch = 0;

        #Define winch to to climber margin of error (meters)
        self.WINCH_OFFSET = .05;

        #Define winch speed CONSTANT (meters/s)
        self.WINCH_SPEED = 0.1;

        #Define winch_in timer
        self.winch_in_timer = 0;

        #Define winch_out timer
        self.winch_out_timer = 0;

        #Define winch out switch variable (meters/s)
        self.winch_out = DigitalOutputDevice(23);

        #Define a lowering flag
        self.lower_flag = 0;

        #Define winch in switch variable (meters/s)
        self.winch_in = DigitalOutputDevice(25);
        
        #Deine a fall flag
        self.fall_flag = 0;
        
        #Define fall timer for seeing how long after a fall
        self.fall_timer = 0;
        
        # stop motor if above threshold
        self.threshhold = .5

    def rotate(self,z_climber, acc):
        #Update the winch position
        if(self.winch_in.value == 1):
            self.z_winch = self.z_winch + self.WINCH_SPEED * (time.time() - self.winch_in_timer);
        elif(self.winch_out.value == 1):
            self.z_winch = self.z_winch - self.WINCH_SPEED * (time.time() - self.winch_out_timer);
        else:
            self.z_winch = self.z_winch;
        
        
        #check if a fall has occurred
        if(self.fall_flag == 1):
            #Check the timer to see if 2 seconds has elapsed and lower climber
            if((time.time() - self.fall_timer) >= 5):
                self.lower_flag = 1;
                self.fall_flag = 0
            
        #check if lowering
        elif(self.lower_flag == 1):

            #Check if climber to winch distance is greater than 5 cm
#             if((z_climber - self.z_winch) > self.WINCH_OFFSET):
#                 #turn off motor_out
#                 self.winch_out.off();
#                 #Reset motor_out_timer
#                 self.winch_out_timer = 0;
#                 #turn on motor_in
#                 self.winch_in.on();
#                 #Record motor_in_timer start time
#                 self.winch_in_timer = time.time();
# 
            #If at the bottom, stop the winch
            if (self.z_winch < self.WINCH_OFFSET):
                #Turn off motor_in and motor_out
                self.winch_in.off();
                #Reset motor_in_timer
                self.winch_in_timer = 0;
                self.winch_out.off();
                #Reset motor_out_timer
                self.winch_out_timer = 0;

            #Otherwise continue lowering
            else:
                self.winch_out.on();
                #Record motor_out_timer start time
                self.winch_out_timer = time.time();
                self.winch_in.off();
                #Reset motor_in_timer
                self.winch_in_timer = 0;

        #Normal climbing mode
        else:
            if(self.z_winch >= self.threshhold):
                    self.winch_out.off()
                    self.winch_out_timer = 0
                    self.winch_in.off()
                    self.winch_in_timer = 0
            
            #Check if climber is higher than winch carabiner
            elif((z_climber - self.z_winch) > self.WINCH_OFFSET):

                
                    
                #Check if motor in and out are both on
                if(self.winch_in.value == 1 and self.winch_out.value == 1):
                    #Turn off winch_out
                    self.winch_out.off();
                    #Reset motor_out_timer
                    self.winch_out_timer = 0;
                    #Turn on winch_in
                    self.winch_in.on();
                    #Record motor_in_timer start time
                    self.winch_out_timer = time.time();
                    
                #Check if winch_in is off and motor_out is 1
                elif(self.winch_in.value == 0 and self.winch_out.value == 1):
                    #Turn off motor_out
                    self.winch_out.off();
                    #Reset motor_out_timer
                    self.winch_out_timer = 0;
                    #Turn on winch_in
                    self.winch_in.on();
                    #Record motor_in_timer start time
                    self.winch_in_timer = time.time();

                #Check if motor in and out are off
                elif(self.winch_in.value == 0 and self.winch_out.value == 0):
                    #Turn off motor_out
                    self.winch_out.off();
                    #Reset motor_out_timer
                    self.winch_out_timer = 0;
                    #Turn on motor_in
                    self.winch_in.on();
                    #Record motor_in_timer start time
                    self.winch_in_timer = time.time();

                #Check if motor_in is on and motor_out is off
                elif(self.winch_in.value == 1 and self.winch_out.value == 0):
                    #Turn off motor_out
                    self.winch_out.off();
                    #Reset motor_out_timer
                    self.winch_out_timer = 0;
                    #Turn on motor_in
                    self.winch_in.on();
                    #Record motor_in_timer start time
                    self.winch_in_timer = time.time();

                #motor_in == 1 must always be true in this condition
                else:
                    self.winch_out.off();
                    #Reset motor_out_timer
                    self.winch_out_timer = 0;
                    self.winch_in.on();
                    #Record motor_in_timer start time
                    self.winch_in_timer = time.time();

            #Check if climber and winch positions are equal
            elif(np.abs(z_climber - self.z_winch) < self.WINCH_OFFSET):
                #Turn off motor_in and motor_out
                self.winch_in.off();
                #Reset winch_in_timer
                self.winch_in_timer = 0;
                self.winch_out.off();
                #Reset winch_out_timer
                self.winch_in_timer = 0;

            #Check if climber position is less than carabiner
            if(acc < -8.5): #((z_climber - self.z_winch) < (-1*self.WINCH_OFFSET)):
                #This is a fall condition we need to accomodate
                self.fall_flag = 1;
                #start fall timer
                self.fall_timer = time.time();
                #Turn off motor_in
                self.winch_in.off();
                #Record motor_in_timer start time
                self.winch_in_timer = 0;
                #Turn on motor_out
                self.winch_out.off();
                #Set winch_out_timer start time
                self.winch_out_timer = 0;
