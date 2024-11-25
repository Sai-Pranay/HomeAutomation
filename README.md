# HomeAutomation

This project demonstrates a basic model of home automation by interfacing various sensors to monitor and control the environment. The system integrates with **Blynk Cloud** and the **Blynk Mobile App** for real-time data monitoring and control.

---

## Features

The project includes interfacing the following sensors:  
- **LDR (Light Dependent Resistor)**: For light intensity detection.  
- **DHT11**: For temperature and humidity monitoring.  
- **PIR (Passive Infrared Sensor)**: For motion detection.  
- **Ultrasonic Sensor**: For distance measurement.  
- **MQ2**: For gas and smoke detection.  

---

## How It Works

1. Sensor data is collected and processed using a microcontroller (e.g., Arduino).  
2. The processed data is transmitted to the **Blynk Cloud** platform.  
3. The **Blynk Mobile App** is used to visualize sensor readings and control connected devices in real time.  

---

## Requirements

- **Hardware**:
  - Microcontroller board (e.g., Arduino Uno, NodeMCU, etc.)
  - LDR, DHT11, PIR, Ultrasonic, and MQ2 sensors
  - Connecting wires and power supply  

- **Software**:
  - [Arduino IDE](https://www.arduino.cc/en/software) for uploading code
  - [Blynk Mobile App](https://blynk.io/) for real-time monitoring and control

---

## Setup Instructions

1. **Arduino IDE Configuration**:  
   - Install the required libraries for Blynk and the sensors.  
   - Connect the sensors to the microcontroller as per the provided wiring diagram.  

2. **Code Upload**:  
   - Write or modify the Arduino sketch to include your **Blynk Authentication Token**.  
   - Upload the code to the microcontroller using the Arduino IDE.  

3. **Blynk Cloud Integration**:  
   - Create a new project on the Blynk Mobile App and obtain the authentication token.  
   - Configure widgets in the app to monitor sensor data and control connected devices.  

4. **Run the System**:  
   - Power up the microcontroller and sensors.  
   - Monitor real-time data on the Blynk app and control devices as needed.  

---

## Applications

- Smart home systems  
- Environment monitoring  
- Security and automation  
