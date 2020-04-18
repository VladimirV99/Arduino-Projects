# Arduino Projects

This is a collection of [Arduino](https://www.arduino.cc/) based projects that demonstrate the usage of various sensors and components.

## Required Software

- [Arduino IDE](https://www.arduino.cc/en/Main/Software)
- [Python](https://www.python.org/downloads/)
- [Processing](https://processing.org/download/)

## Projects

- [Buzzers](https://github.com/VladimirV99/Arduino-Projects/tree/master/Buzzers)
- [DHT](https://github.com/VladimirV99/Arduino-Projects/tree/master/DHT)
- [Gyroscope](https://github.com/VladimirV99/Arduino-Projects/tree/master/Gyroscope)
- [IR Receiver](https://github.com/VladimirV99/Arduino-Projects/tree/master/IR_Receiver)
- [Joystick](https://github.com/VladimirV99/Arduino-Projects/tree/master/Joystick)
- [LCD](https://github.com/VladimirV99/Arduino-Projects/tree/master/LCD)
- [PIR Motion Sensor](https://github.com/VladimirV99/Arduino-Projects/tree/master/PIR_Motion_Sensor)
- [Remote Custom](https://github.com/VladimirV99/Arduino-Projects/tree/master/Remote_Custom)
- [RFID](https://github.com/VladimirV99/Arduino-Projects/tree/master/RFID)
- [RGB LED](https://github.com/VladimirV99/Arduino-Projects/tree/master/RGB_LED)
- [Servo Motor](https://github.com/VladimirV99/Arduino-Projects/tree/master/Servo_Motor)
- [Seven-Segment Display](https://github.com/VladimirV99/Arduino-Projects/tree/master/Seven_Segment_Display)
- [Sound Sensor](https://github.com/VladimirV99/Arduino-Projects/tree/master/Sound_Sensor)
- [Stepper Motor](https://github.com/VladimirV99/Arduino-Projects/tree/master/Stepper_Motor)
- [Ultrasonic Sensor](https://github.com/VladimirV99/Arduino-Projects/tree/master/Ultrasonic_Sensor)

## Planned Projects

- Remote

## Basic Components

### Arduino board

An Arduino board is an open-source programmable microcontroller board. There are many versions of [Arduino boards](https://en.wikipedia.org/wiki/List_of_Arduino_boards_and_compatible_systems) like the Uno, Mega, Leonardo, Nano and a lot of others. For these projects we will be using an [Arduino Uno](https://en.wikipedia.org/wiki/Arduino_Uno). It can be powered by USB or by an external 9V battery (It supports 7-20V inputs). Some of the projects in this repository require libraries to work. Libraries are downloaded through the Library Manager in the Arduino IDE.

### Breadboard

A [breadboard](https://en.wikipedia.org/wiki/Breadboard) is a construction base for prototyping of electronics. It is a plastic board with a lot of holes which are connected in a specific way. The holes let you easily insert electronic components and connect them with jumper cables which is very useful for testing circuits. There are two strips on each side labeled "+" and "-" used to supply power and they are connected by column. The board is divided in two halves vertically and all of the holes in each half are connected by row.

### Resistors

[Resistors](https://en.wikipedia.org/wiki/Resistor) are electronic components used to limit the current in a circuit. To calculate the current use [Ohm's law](https://en.wikipedia.org/wiki/Ohm%27s_law). Resistors don't have a polarity, which means they can be connected in either direction. To find out the resistance of your resistor look up resistor [color codes](https://en.wikipedia.org/wiki/Electronic_color_code).

### Diodes

A [diode](https://en.wikipedia.org/wiki/Diode) is a two-terminal electronic component that conducts current primarily in one direction. It has low resistance in one direction, and high resistance in the other. Watch out connecting diodes, because connecting them the wrong way can damage them.

### LEDs

An [LED](https://en.wikipedia.org/wiki/Light-emitting_diode) is a diode that emmits light. Like all diodes it has an anode(+) and a cathode(-), the shorter pin being the cathode and the longer pin being the anode. The voltage drop accross an LED is 1.8-2.2V. The current dictates the LED brightness. The operating amperage is 20mA (max 30mA), althought 10mA is sufficiently bright. They are usually connected to the Arduino through a 220ohm resistor. That resistance value was chosen because 220ohms is a standard resistor value nearest to the optimal calculated using [Ohm's law](https://en.wikipedia.org/wiki/Ohm%27s_law). The actual optimal is 128ohms, but accounting for fault tolerances of +/- 5-10%, 220ohms is a better choice.

### Transistors

A [transistor](https://en.wikipedia.org/wiki/Transistor) is a semiconductor device used to amplify or switch electronic signals and electrical power. Transistors have three pins: collector, base and emitter. Note that the order of the pins vary between different transistors. When the power is supplied to the base it lets current pass from the collector to the emitter. To use a transistor as an amplifier connect the input signal to the base. This works because the power required to activate the base is less than the power supplied by the power source.

### Push Buttons

[Push buttons](https://en.wikipedia.org/wiki/Push-button) are used to open or close a circuit. They can be connected to the Arduino with a pull up or pull down connection. For the pull up connection one side of the button should be connected to the Arduino input pin and 5V with a 1kohm resistor between them, and the other side to the ground. The pull down connection is the same except ground and 5V connections are swapped. The resistor is required not to short out the Arduino. Another way to connect a button is to set the pin mode to INPUT_PULLUP and connecting the button to ground and the input pin.

## Troubleshooting

On linux, if you get a permission denied on /dev/ttyACM0 error run the following command:
```bash
sudo chmod a+rw /dev/ttyACM0
```
Just replace ttyACM0 with the port from your error message
