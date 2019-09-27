# Remote

## Description

Remote to keyboard shortcut mapper for an old TV remote.

## Required Libraries

### Arduino Libraries

- **IRRemote** by Ken Shirriff

### Python Libraries

- **pyserial**
- **keyboard**

## Notes

The Arduino program reads data from the IR sensor and if the key matches the remote it gets sent to the serial port. Then it's read by the python script which simulates a key press.

There are two types of keys, repeating and non-repeating. Repeating keys are simulated continuously while the remote button is held, for example the volume buttons. However, remotes don't send the button code when it's being held instead they send a repeat code. That's why we keep track of the last button code on the Arduino and when we detect a repeat code we send the last button code. Non-repeating keys we send only once no matter how long they are held.

There is a problem with pressing the windows key on linux. We can't press it by name, instead we need to use the key code directly. The codes are 125 for left windows key and 126 for right windows key.

## Wiring

The IR Sensor pins from left to right are OUT, GND and VCC. Connect GND to ground, VCC to 5V and OUT to Arduino pin 7.

## Instructions

You need to change the values of the buttons in the Arduino and Python scripts and the serial port in the Python script. To find out values for your remote you can use the IR Receiver Demo, the wiring is the same. After that, run the Arduino program first, then the python script. The python script needs to be run as sudo on linux.

