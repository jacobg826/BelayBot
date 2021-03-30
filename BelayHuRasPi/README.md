Python code to run on RasberryPi for BelayHu project



## Bluetooth compatability Set up Instructions:

Steps 1 and 2 need to only be done once. Step 3 is necessary everytime you want to connect the devices.

###  1.Enable SPP on Raspberry Pi
In order to use SPP, Bluetooth service needs to be restarted with ‘compatibility’ flag.

####  Open Bluetooth service configuration file.

`sudo nano /etc/systemd/system/dbus-org.bluez.service`
####  Look for a line starts with “ExecStart” and add compatibility flag ‘-C’ at the end of the line.

`ExecStart=/usr/lib/bluetooth/bluetoothd -C`
####  Add a line below immediately after “ExecStart” line, then save and close the file.

`ExecStartPost=/usr/bin/sdptool add SP`
####  Reload the configuration file.

`sudo systemctl daemon-reload`
####  Restart the service.

`sudo systemctl restart bluetooth.service`

###  2.Pair the devices

####  Launch bluetoothctl.

`sudo bluetoothctl`
####  Run the following commands to configure the agent.
`agent on`

`default-agent`

####  Scan for nearby devices.
`scan on`

Addresses of nearby bluetooth connections will start showing up.
Find the device you want to connect to and copy the 6-byte address

####  Pair with the device.
`pair <addr>`

Example: `pair 43:F0:36:A1:00:3C`

Depending on the kind of device you're pairing with, it will have a different pairing process. You can check if the pair was successful by running `paired-devices` and checking if you're device shows up.

####  Trust the device.
`trust <addr>`

####  Exit bluetoothctl
`exit`


###  3.Connect
Everytime you want to open a connection, run

`sudo rfcomm watch hci0`

If its working correctly, you should see:

`Waiting for connection on channel 1`

When the device the Pi is trying to connect with responds you should see:
```
Connection from XX:XX:XX:XX:XX:XX to /dev/rfcomm0
Press CTRL-C for hangup
```

Then the python code can be used to read and write to the bluetooth device.

#### Connecting to the HC-05:

The HC-05 can be a little difficult to connect to. If you want a connection with it you may need to type:

`sudo rfcomm connect hci0 <addr>`

#### NOTE: Re-connect the HC-05 before each run of the RasPi code
The HC-05 fails to return data if you skip doing this before each run. IDK why this is. I can continue looking in to it, but for now re-connecting before each run seems to work. 
