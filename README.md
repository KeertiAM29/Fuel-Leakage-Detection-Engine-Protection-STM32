# 🔥 Fuel Leakage Detection & Engine Protection System — STM32

> **STM32-based automotive safety system** that detects fuel vapors using an MQ-3 gas sensor and automatically shuts down the engine when leakage is detected.

---

## 📌 Overview

An embedded automotive safety system that detects fuel-related vapors using an **MQ-3 gas sensor** and automatically stops a DC motor (representing the vehicle engine) when the detected vapor concentration exceeds a predefined threshold. The system provides real-time visual indication via LEDs for safe and unsafe conditions.

---

## 🎯 Objective

To interface an MQ-3 gas sensor with the STM32 microcontroller and implement **threshold-based fuel leakage detection** with automatic engine shutdown and warning indication.

---

## 🛠️ Hardware Components

| Component | Specification |
|-----------|--------------|
| Microcontroller | STM32F103C8T6 (Blue Pill) |
| Gas Sensor | MQ-3 (Alcohol/Fuel Vapor) |
| Actuator | 5–12V DC Motor (Engine simulation) |
| Indicators | Green LED (Safe) + Red LED (Warning) |
| Resistors | 330Ω (for LEDs) |
| Misc | Connecting Wires, Breadboard |

---

## 🏗️ System Architecture

```
MQ-3 Sensor → ADC → STM32F103C8T6 → Threshold Decision → Motor / LED Control
                         │
                    ┌────┴────┐
               Safe │         │ Leakage Detected
                    ▼         ▼
              Green LED    Red LED
              Motor ON     Motor OFF
```

---

## ⚙️ Working

### Normal Condition (No Leakage)
- MQ-3 sensor reads vapor concentration via ADC
- ADC value **below threshold** → safe condition
- ✅ Green LED **ON**
- ✅ DC Motor **RUNNING**

### Leakage Detected
- ADC value **exceeds threshold** → leakage detected
- 🔴 Red LED **ON** (warning)
- ❌ Green LED **OFF**
- ❌ DC Motor **STOPPED** (engine shutdown)

---

## 💻 Technologies Used

- **STM32F103C8T6** — ARM Cortex-M3 microcontroller
- **Embedded C** — firmware development
- **ADC (Analog to Digital Converter)** — sensor reading
- **GPIO** — LED and motor control
- **Sensor Interfacing** — MQ-3 gas sensor
- **Threshold-Based Control** — decision logic
- **Automotive Safety Monitoring**

---

## 📁 Project Structure

```
Fuel-Leakage-Detection/
├── Core/
│   ├── Src/
│   │   └── main.c          # Main firmware logic
│   └── Inc/
│       └── main.h
├── Drivers/                # STM32 HAL drivers
├── README.md
└── .ioc                    # STM32CubeMX config file
```

---

## 🚀 How to Run

**Step 1** — Open project in **STM32CubeIDE**

**Step 2** — Connect STM32 Blue Pill via ST-Link programmer

**Step 3** — Build the project → Flash to STM32

**Step 4** — Power the circuit → observe LED and motor behavior

**Step 5** — Bring alcohol/fuel vapor near MQ-3 sensor → motor should stop and red LED should activate

---

## 📊 Results

- ✅ Successfully detected alcohol-based vapors used to simulate fuel leakage
- ✅ Red LED activated when vapor concentration exceeded threshold
- ✅ DC motor stopped automatically to represent engine shutdown
- ✅ System returned to normal operation when vapor cleared

---

## 🔌 Circuit Connections

| STM32 Pin | Connected To |
|-----------|-------------|
| PA0 (ADC) | MQ-3 Analog Output |
| PB0 | Green LED (+) |
| PB1 | Red LED (+) |
| PB5 | DC Motor control |
| GND | Common Ground |
| 3.3V / 5V | Sensor VCC |

---
