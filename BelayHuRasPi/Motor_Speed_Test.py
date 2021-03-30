from gpiozero import DigitalOutputDevice
import time

winch_in = DigitalOutputDevice(25);
winch_out = DigitalOutputDevice(23);


winch_in.off();
winch_out.off();
for i in range(1):
    winch_out.on()
    
    time.sleep(1);

winch_in.off();
winch_out.off();
