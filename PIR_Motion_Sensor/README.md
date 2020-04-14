# PIR Motion Sensor

## Description

Motion detection using an HC-SR501 PIR motion sensor.

## Notes

All objects with a temperature above absolute zero (0 Kelvin / -273.15 °C) emit heat energy in the form of infrared radiation. The hotter an object is, the more radiation it emits. A PIR sensor is specially designed to detect such radiation. 

It consists of two main parts: a pyroelectric sensor and a Fresnel lens which focuses the infrared signals onto the pyroelectric sensor. The sensor has two rectangular slots in it made of a material that allows the infrared radiation to pass. Behind these, are two separate infrared sensor electrodes, one responsible for producing a positive output and the other a negative output. This is because we are looking for a change in IR levels and not absolute levels. The two electrodes are wired up so that they cancel each other out. If one half sees more or less IR radiation than the other  the output will become higher or lower.

When there is no motion both electrodes measure the same IR levels and the output is zero. If something enters the area it first intercepts one half of the PIR sensor, which causes a positive differential change between the two halves. When it leaves the area, the reverse happens, whereby the sensor generates a negative differential change. Both of these cases result in the output being set to high.

The sensor has a built-in voltage regulator so it can be powered by any DC voltage from 4.5 to 12 volts.

There are two potentiometers on the board to adjust a couple of parameters:
- Sensitivity - The maximum distance that motion can be detected. Ranges from 3 meters to approximately 7 meters depending on the room
- Time - How long the output will remain high after detection. Ranges from 3 seconds to 300 seconds.

Finally the board has a jumper with two settings:
- H (Hold/Repeat/Retriggering) - continue to output a HIGH signal as long as there is movement.
- L (No-Repeat/Non-Retriggering) - the output will stay HIGH for the period set by the time potentiometer adjustment.

## Wiring

- **VCC** - 5V
- **OUT** - Arduino pin 2
- **GND** - Ground
