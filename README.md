# Room Thermostat Simulator (8051 + DS18B20 + LCD)

## 📌 Overview
This project simulates a thermostat system using an 8051 microcontroller, DS18B20 temperature sensor, and LCD display.  
The system monitors room temperature, displays it on an LCD, and activates a simulated cooling system using PWM when the temperature exceeds a threshold.

## ⚙️ Features
- **Temperature Monitoring** using DS18B20 sensor (simulated in code)
- **LCD Display** for real-time temperature and cooling status
- **PWM Output** to simulate cooling system control
- **Interrupt-driven sampling** (expandable)
- **Proteus Simulation** for testing without hardware

 🚀 How to Run
1. Open `thermostat.uvprojx` in Keil uVision.
2. Build the project (`F7`).
3. Simulate in Proteus using the provided `.pdsprj` file (or create your own schematic with DS18B20 + LCD).
4. Watch simulated temperature changes on LCD.

## 📊 Simulation Behavior
- Temperature cycles between **22°C and 30°C**.
- Cooling system turns ON when temperature > 25°C.
- LCD displays both temperature and cooling status.

## 📜 License
This project is for academic & learning purposes.
