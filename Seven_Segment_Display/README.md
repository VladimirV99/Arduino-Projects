# Seven-Segment Display

## Description

A counter using a single digit(5161AS) and four digit(5461AS) seven-segment displays.

## Notes

A [seven-segment display](https://en.wikipedia.org/wiki/Seven-segment_display) is a form of electronic device for displaying decimal numbers. They are widely used in digital clocks, electronic meters, basic calculators, and other electronic devices that display numerical information.

Segments of the display are labeled with letters A-G clockwise starting from the top segment and the middle segment being G. The display can also contain a decimal point which would then be labeled DP.

There are two types of seven-segment displays: common cathode and common anode. In common cathode displays, all of the cathodes are connected to ground and individual segments are turned on and off by switching power to the anodes. In common anode displays, all of the anodes are connected to Vcc, and individual segments are turned on and off by switching power to the cathodes.

Single digit seven-segment displays typically have 10 pins. Two pins connect to ground, and the other 8 connect to each of the segments. For the 5161AS common cathode display the pins listed left-to-right with the display facing towards you are G, F, -, A, B for the first row and E, D, -, C, DP for the second.

In multi-digit displays, one segment pin (A, B, C, D, E, F, G and DP) controls the same segment on all of the digits but they also have separate common pins for each digit. These are the digit pins. You can turn a digit on or off by switching the digit pin. For the 5461AS common cathode display the pins listed left-to-right with the display facing towards you are D4, A, F, D3, D2, B for the first row and E, D, DP, C, G, D1 for the second.

## Wiring

### One digit display

- **A** - Arduino pin 6
- **B** - Arduino pin 5
- **C** - Arduino pin 2
- **D** - Arduino pin 3
- **E** - Arduino pin 4
- **F** - Arduino pin 7
- **G** - Arduino pin 8
- **DP** - Arduino pin 9
- **-** - Ground through a 1kOhm resistor

### Four digit display

- **A** - Arduino pin 9
- **B** - Arduino pin 2
- **C** - Arduino pin 3
- **D** - Arduino pin 5
- **E** - Arduino pin 6
- **F** - Arduino pin 8
- **G** - Arduino pin 7
- **DP** - Arduino pin 4
- **D1** - Arduino pin 13 through a 1kOhm resistor
- **D2** - Arduino pin 12 through a 1kOhm resistor
- **D3** - Arduino pin 11 through a 1kOhm resistor
- **D4** - Arduino pin 10 through a 1kOhm resistor