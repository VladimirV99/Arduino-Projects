# IR Receiver

## Description

Receiving IR signals and processing them in python.

## Required Libraries

### Arduino Libraries

- **IRRemote** by Ken Shirriff

### Python Libraries

- **pyserial**

## Wiring

The IR Sensor pins from left to right are OUT, GND and VCC. Connect GND to ground, VCC to 5V and OUT to Arduino pin 7.

## Instructions

Replace the serial port in the python script with your Arduino port. First run the Arduino program, then run the python script. The received signals will be printed in the serial monitor and the python console.
