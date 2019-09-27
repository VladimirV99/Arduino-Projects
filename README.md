# Arduino Projects

## Instructions

On linux, if you get a permission denied on /dev/ttyACM0 error run the following command:
```bash
sudo chmod a+rw /dev/ttyACM0
```
Just replace ttyACM0 with the port from your error message

## Projects

- Buzzers
- DHT
- Gyroscope
- IR Receiver
- Joystick
- LCD
- Remote Custom
- RGB LED
- Servo Motor
- Sound Sensor
- Stepper Motor
- Ultrasonic Sensor

## Notes

### Resistors

Resistors are used to limit the current in the circuit. To calculate the current use [Ohm's law](https://en.wikipedia.org/wiki/Ohm%27s_law). Resistors don't have a polarity, which means they can be connected in either direction. To find out the resistance of your resistor look up resistor color codes.

### LEDs

An LED is a diode that emmits light. Like all diodes it has an anode(+) and a cathode(-). The shorter pin is the cathode and the longer pin is the anode. Connecting diodes the wrong way damages them. The voltage drop accross an LED is 1.8-2.2V. The current dictates the LED brightness. The operating amperage is 20mA (max 30mA), althought 10mA is sufficiently bright. They are usually connected to the Arduino through a 220ohm resistor. That resistance value was chosen because 220ohms is a standard resistor value nearest to the optimal calculated using Ohm's law (The actual optimal is 128ohms, but accounting for fault tolerances of +/- 5-10%, 220ohms is a better choice).

### Push Buttons

Push buttons can be connected to the Arduino with a pull up or pull down connection. For the pull up connection one side of the button should be connected to the Arduino input pin and 5V with a 1kohm resistor between them, and the other side to the ground. The pull down connection is the same except ground and 5V connections are swapped. The resistor is required not to short out the Arduino. Another way to connect a button is to set the pin mode to INPUT_PULLUP and connecting the button to ground and the input pin.
