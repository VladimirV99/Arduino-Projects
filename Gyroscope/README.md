# Gyroscope

## Description

Reading gyroscope data with an MPU6050

## Required Libraries

- **Wire** by Arduino

For more advanced projects take a look at:

- **I2Cdev** by jrowberg
- **MPU6050** by jrowberg

## Notes

The MPU6050 is a six-axis motion tracking device, its main features are:
- Three-axis accelerometer
- Three-axis gyroscpe
- Digital output temperature sensor
- Six 16-bit analog to digital conversion (ADC) - three for accelerometer and three for gyroscope
- Integrated digital motion processor(DMP) which reduces computational load from the host processor (Arduino) by processing the data itself.
- 1024B FIFO Buffer - we will send an interrupt signal to the Arduino when this buffer fills to read the data

It communicates using I2C protocol so it must be connected to the I2C pins of the Arduino. Those pins are A4(SDA) and A5(SCL) for Arduino Uno.

## Sensor Pins

- **VCC** - 3V-5V
- **GND** - Ground
- **SCL** - Serial Clock (I2C pin)
- **SDA** - Serial Data (I2C pin)
- **XDA** - Auxiliary Serial Data (I2C pin)
- **XCL** - Auxiliary Serial Clock (I2C pin)
- **ADO** - Selects between I2C address 0x68 and 0x69. That makes it possible to have two of these sensors in a project. Most breakout boards have a pullup or pulldown resistor to make AD0 default low or high. Connect AD0 to GND or 3.3V for the other I2C address.
- **INT** - Interrupt pin, activates when the buffer is full

## Wiring

- **VCC** - 5V
- **GND** - Ground
- **SCL** - Arduino pin A5
- **SDA** - Arduino pin A4
- **XDA** - Not connected
- **XCL** - Not connected
- **ADO** - Not connected
- **INT** - Arduino pin 2

## Instructions

Run the program and open the Serial Monitor to view the data.

