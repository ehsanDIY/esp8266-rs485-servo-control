# ESP8266 RS485 Remote Servo Control

> 🛠️ Transmit analog potentiometer values over RS485 to control a servo motor in real time — using two ESP8266 modules.


## 🎯 Goal
Demonstrate **noise-immune, long-distance analog control** for servos using low-cost hardware — ideal for industrial or outdoor setups where WiFi is unreliable.

## 🧰 Hardware Used
| Component | Quantity |
|---------|----------|
| ESP8266 (e.g., NodeMCU) | 2 |
| MAX485 Module | 2 |
| SG90 or MG90S Servo | 1 |
| 10kΩ Potentiometer | 1 |
| 5V Power Supply (≥1A for servo) | 1 |
| Jumper Wires & Breadboard | — |

### 🔌 Wiring Summary

#### 📡 **Transmitter (Potentiometer Side)**
| ESP8266 | → | Module |
|--------|----|--------|
| A0 | → | Potentiometer wiper |
| D1 (GPIO5) | → | DI (Data Input) of MAX485 |
| VCC | → | DE & RE |
| GND | → | GND of MAX485 & Pot |
| 3.3V | → | VCC of MAX485 |

> ⚠️ Connect `A` and `B` of both MAX485 modules together (twisted pair recommended). Add 120Ω termination resistor across A–B at *both ends* for >50m runs.

#### 📥 **Receiver (Servo Side)**
| ESP8266 | → | Module |
|--------|----|--------|
| D0 (GPIO16) | → | Servo signal |
| D1 (GPIO5) | → | RO (Receiver Output) of MAX485 |
| GND | → | DE & RE |
| GND | → | GND of MAX485 & Servo |
| VIN / External 5V | → | Servo VCC (+) |
| GND | → | Servo GND (–) |

> 🔌 Servo MUST be powered externally (e.g., 5V/2A USB adapter) — ESP8266 3.3V regulator can’t handle servo current.
