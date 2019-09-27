# Sound Sensor

## Description

Turning lights on and off when a double clap is detected using a sound sensor.

## Notes

Depending on the sensor, it can have an analog as well as digital outputs labeled AO and DO respectively. You can use either of the outputs, just connect them to the corresponding analog/digital inputs. The analog input gives you the amplitude, not just if the threshold was passed, but it is slower to read.

## Wiring

- **OUT** - Arduino pin 3
- **GND** - Ground
- **VCC** - 5V

Also connect an LED through a 220ohm resistor to the Arduino pin 2

## Instructions

You need to configure the sensitivity of the sensor using the screw on the top of the sensor. Then just run the Arduino program.
