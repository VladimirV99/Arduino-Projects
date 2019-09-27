# DHT

## Description

Measuring temperature and humidity using DHT11, DHT21 or DHT22 sensors.

## Required Libraries

- **Adafruit Unified Sensor** by Adafruit
- **DHT sensor library** by Adafruit

## Wiring

#### Three pin DHT

- **Pin 1** - Output, connected to Arduino pin 2
- **Pin 2** - 5V
- **Pin 3** - GND

#### Four pin DHT

- **Pin 1** - 5V
- **Pin 2** - Output, connected to Arduino pin 2 and to DHT pin 1 through a 10K pull up resistor
- **Pin 3** - Not connected
- **Pin 4** - GND

## Instructions

Uncomment the DHT_TYPE definition line for your model. Run the program and open the Serial Monitor to view the results.
