# Stepper Motor

## Description

Controlling a 28BYJ-48 Steper Motor with a ULN2003 driver board.

## Required Libraries

- **Arduino Stepper Library** by Arduino

## Notes

The 28BYJ-48 is a 5-wire unipolar stepper motor that moves 32 steps per rotation internally but has a gearing system that moves the shaft by a factor of 64. The result is a motor that spins at 2048 steps per rotation. Motor voltage is 5V. The motor is commonly used with a driver board like the ULN2003.

We define three constants to handle motor rotation:

- **STEPS_PER_REV** is the number of steps the actual motor takes per revolution. This is set at 32.
- **GEAR_REDUCTION** is the amount of gear reduction. This is set at 64.
- **STEPS_PER_OUT_REV** is the final output of the motor shaft after gear reduction. It is the multiple of the above two numbers.

The 28BYJ-48 Unipolar stepper motor has a step sequence as follows: 1-3-2-4. This information will be used to drive the motor by creating an instance of the Stepper class with the pin sequence of 8, 10, 9, 11. Make sure you get this right or the motor will not operate properly.

Even though the motor runs on the same voltage as the Arduino produces you should never use the Arduino as a power source for any motor. Motors induce electrical noise onto its power supply lines which could damage the Arduino. Always use a separate power supply to power your stepper motors.

## Wiring

Connecting the ULN2003:

- **IN1** - Arduino pin 8
- **IN2** - Arduino pin 9
- **IN3** - Arduino pin 10
- **IN4** - Arduino pin 11
- **-** - Power supply ground
- **+** - Power supply 5V

Connect the stepper motor to the appropriate connector on the driver board. Connect the Arduino and power supply grounds together to make a common ground.
