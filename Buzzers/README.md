# Buzzers

## Description

Generating tones with active and passive buzzers.

## Notes

Active buzzers have a built-in oscillating source, which means that they will make sound when electrified. To do that just set the output pin to HIGH. To set the frequency, turn it on and off at that frequency. Passive buzzers need a square wave to generate sound. The simplest way to generate it is using the built-in tone(pin, frequency, duration?) method. To differentiate between active and passive look at their bottom side. If the color is black then it's an active buzzer, and if the color is green it's a passive buzzer.

Only one tone can be generated at a time. If a tone is already playing on a different pin, the call to tone() will have no effect. If the tone is playing on the same pin, the call will set its frequency.

Use of the tone() function will interfere with PWM output on pins 3 and 11 (on boards other than the Mega).

It is not possible to generate tones lower than 31Hz.

## Wiring

- **+** - Arduino PWM pin
- **-** - Ground

Connect the passive buzzer to Arduino pin 5 and the active buzzer to Arduino pin 6.
