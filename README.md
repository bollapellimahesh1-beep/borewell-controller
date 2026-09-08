# 💧 Automatic Borewell Pump Controller

An Arduino-based automatic borewell pump controller designed to
automatically control a water pump based on borewell water
availability and overhead tank level.

## 🚀 Features

- Automatic pump ON/OFF
- Borewell water monitoring
- Overhead tank level monitoring
- Dry-run protection
- Buzzer warning
- Pump status LED
- Fault indication LED

## 🔧 Components

- Arduino UNO
- Water level sensors
- Relay/Contactor
- Buzzer
- LEDs
- Borewell pump
- Power supply

## ⚙️ Working Principle

1. The Arduino monitors the borewell water sensor.
2. It monitors the overhead tank level.
3. When the tank is LOW and borewell water is available,
   the pump is switched ON.
4. When the tank becomes FULL, the pump is switched OFF.
5. If borewell water is unavailable, the pump is stopped to
   prevent dry running.
6. A buzzer and fault LED indicate a fault condition.

## 🔌 Pin Configuration

| Component | Arduino Pin |
|---|---|
| Borewell Sensor | D2 |
| Tank LOW Sensor | D3 |
| Tank FULL Sensor | D4 |
| Pump Relay | D8 |
| Buzzer | D9 |
| Pump Status LED | D10 |
| Fault LED | D11 |

## 📷 Circuit Diagram

![Circuit Diagram](circuit-diagram.png)

## 🔮 Future Enhancements

- IoT-based monitoring
- Mobile app control
- Water-level display
- GSM alerts
- Voltage/current monitoring
- Automatic fault notifications

## 👨‍💻 Project Type

Embedded Systems / Arduino Project

## 📜 License

This project is for educational purposes.
