# LCD

## Description

Writing to an LCD Screen using LCD1602

## Required Libraries

- **LiquidCrystal** by Arduino

## LCD Pins

- **Vss** - Ground
- **Vdd** - 5V Power supply
- **V0** - To adjust the contrast
- **RS** - A register select pin that controls where in the LCD's memory you are writing data to. You can select either the data register, which holds what goes on the screen, or an instruction register, which is where the LCD's controller looks for instructionson what to do next
- **R/W** - A Read/Write pin to select between reading and writing mode
- **E** - An enabling pin that reads the information when high level is received. The instructions are run when the signal changes from high level to low level
- **D0-D7** - Data pins for reading/writing data
- **A** - LCD backlight anode
- **K** - LCD backlight cathode

## Wiring

- **Vss** - Ground
- **Vdd** - 5V
- **V0** - Middle pin of potentiometer. Left and right pins should be 5V and Ground respectively
- **RS** - Arduino pin 4
- **R/W** - Ground
- **E** - Arduino pin 6
- **D0-D3** - Not connected
- **D4-D7** - Arduino pins 10-13
- **A** - 3.3V
- **K** - Ground
