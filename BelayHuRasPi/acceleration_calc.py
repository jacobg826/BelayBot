import numpy as np


class AccCalc:
    
    def __init__(self):
        self.pos = 0.0
        self.vel = 0.0
        self.acc = 0.0
    
    #Returns the increase in position
    #prev_acc - acceleration recorded at previous instance
    #prev_vel - velocity at previous instance
    #new_acc - acceleration recorded at next instance
    #dt - difference in seconds between prev_acc recording and new_acc recording
    def new_datapoint(self, new_acc, dt):
        acc_arr = np.array([self.acc, new_acc])
        vel_change = np.trapz(acc_arr, dx = dt)
        new_vel  = self.vel + vel_change
        
        vel_arr = np.array([self.vel, new_vel])
        pos_change = np.trapz(vel_arr, dx = dt)
        new_pos = self.pos + pos_change
        
        self.acc = new_acc
        self.vel = new_vel
        self.pos = new_pos
        
        return pos_change
        
