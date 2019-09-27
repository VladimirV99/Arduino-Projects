# Servo Motor

## Description

Controlling an SG90 Servo Motor.

## Required Libraries

- **Arduino Servo Library** by Arduino

## Notes

A Servo Motor is a low-speed, high-torque, high-precision motor. Unlike the DC and Stepper motors the Servo Motor does not normally spin a full 360 degree rotation. Instead it is limited to a range of 180, 270 or 90 degrees. A control signal is sent to the servo to position the shaft at the desired angle. It can be powered by Arduino or separate power supply with a common ground with the Arduino. The control wire needs to be connected to a pin that supports PWM because the servos position is determined by the input pulse width. In a conventional analog servo motor a PWM signal with a period of 20 ms is used to control the motors. The width of the pulse is varied between 1ms (0 deg) and 2ms (180 deg).

## Wiring

- **Black Wire** - Ground
- **Red Wire** - 5V
- **Orange Wire** - Arduino pin 8
