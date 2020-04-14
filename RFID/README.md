# RFID

## Description

RFID card/tag reader using an MFRC522 RFID reader.

## Required Libraries

### Arduino Libraries

- **MFRC522** by GithubCommunity

## Notes

[Radio-frequency identification](https://en.wikipedia.org/wiki/Radio-frequency_identification) (RFID) uses electromagnetic fields to automatically identify and track tags attached to objects. An RFID tag consists of a tiny radio transponder (radio receiver and transmitter). When triggered by an electromagnetic interrogation pulse from a nearby RFID reader device, the tag transmits digital data, usually an identifying inventory number, back to the reader. There are two types of tags: passive and active. Passive tags are powered by energy from the RFID reader's interrogating radio waves, while active tags are powered by a battery and thus can be read at a greater range from the RFID reader.

The RFID reader we are going to use is MFRC522 reader module and it communicates with the Arduino through [SPI protocol](https://en.wikipedia.org/wiki/Serial_Peripheral_Interface). It operates at 13.56 MHz frequency.

The tags are based on [MIFARE protocol](https://en.wikipedia.org/wiki/MIFARE) and they have 1kb of memory which should be enough for storing a name, credit card number, unique identification number, birth date and some more information. They also have a microchip that can perform arithmetic operations.

To find the UID of a tag open the "Dumpinfo" project from examples and upload it in your Arduino IDE. Then open the serial monitor and bring the RFID card in front of the reader, it will show you the information of the RFID tag.

## Wiring

- **SDA** - Arduino pin 10
- **SCK** - Arduino pin 13
- **MOSI** - Arduino pin 11
- **MISO** - Arduino pin 12
- **IRQ** - Not connected
- **GND** - Ground
- **RST** - Arduino pin 9
- **3.3V** - 3.3V
