# Automatic Borewell Pump Controller

An Arduino-based automatic borewell pump controller.

## Features

- Automatic pump ON/OFF
- Overhead tank level monitoring
- Borewell water detection
- Dry-run protection
- Buzzer warning
- LED status indication

## Components

- Arduino UNO
- Water level sensors
- Relay/Contactor
- Buzzer
- LEDs
- Borewell pump

## Arduino Pins

| Component | Pin |
|---|---|
| Borewell Sensor | D2 |
| Tank LOW Sensor | D3 |
| Tank FULL Sensor | D4 |
| Pump Relay | D8 |
| Buzzer | D9 |
| Pump LED | D10 |
| Fault LED | D11 |

## Working

When the overhead tank is low and borewell water is available,
the Arduino starts the pump.

When the tank becomes full, the pump stops.

If borewell water is not detected, the pump is stopped to
provide dry-run protection.
