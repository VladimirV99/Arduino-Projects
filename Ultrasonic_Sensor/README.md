# Ultrasonic Sensor

## Description

Distance measuring using an HC-SR04 ultrasonic sensor.

## Notes

The ultrasonic sensor uses sonar to determine the distance to an object. Here’s what happens:

1. The transmitter (trig pin) sends a signal, a high-frequency sound.
2. When the signal finds an object, it is reflected
3. The transmitter (echo pin) receives it.

The time between the transmission and reception of the signal allows us to calculate the distance to an object. This is possible because we know the sound’s velocity in the air.

To improve accuracy you can connect a temperature sensor like in the DHT example. The speed of sound depends on the temperature as follows:

```c
float temperature = dht.readTemperature();
float sound_speed = 331.3 + (0.606 * temperature);
distance = duration * (sound_speed / 10000) / 2;
```

## Wiring

- **VCC** - 5V
- **TRIG** - Arduino pin 2
- **ECHO** - Arduino pin 3
- **GND** - Ground
