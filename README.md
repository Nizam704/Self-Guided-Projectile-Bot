# Self-Guided Projectile Bot 🤖🎯  
*An Autonomous Line-Following and Target-Firing Robot*

**Self-Guided Projectile Bot** is an Arduino Mega-powered autonomous robot that navigates a predefined track, detects targets, and fires projectiles with precision. The project integrates embedded systems, mechanical design, and sensor-based automation to simulate real-world industrial robotics applications.

---

## 📘 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [Applications](#applications)
- [System Architecture](#system-architecture)
- [Hardware Components](#hardware-components)
- [Software Design](#software-design)
- [Setup Instructions](#setup-instructions)
- [3D Design Overview](#3d-design-overview)
- [License](#license)

---

## 🧠 Overview

The **Self-Guided Projectile Bot** autonomously follows a black line, identifies junctions, and launches projectiles at predefined targets using ultrasonic sensors and servo-driven mechanisms. Its modular design allows for adaptability and precision in task execution.

---

## ⭐ Features

- IR-based line following using a 3-sensor array
- Dual servo-powered ball shooting mechanism
- Junction-based navigation logic with hardcoded pathing
- Obstacle/target detection using ultrasonic sensors
- Modular multi-floor acrylic chassis with 3D printed supports

---

## 🏭 Applications

- Warehouse logistics and item sorting  
- Automated delivery systems  
- Educational robotics competitions  
- Industrial automation prototypes  
- Autonomous target engagement systems

---

## 🧩 System Architecture

- **Navigation**: 3-sensor IR array tracks black path and detects junctions  
- **Target Detection**: Ultrasonic sensors detect distance to target  
- **Control Logic**: Arduino Mega processes input and controls movement and shooting  
- **Actuation**: DC motors for movement; servo motors for projectile release

---

## 🔧 Hardware Components

- **Arduino Mega 2560** – Core microcontroller  
- **L298N Motor Driver** – Controls 4 DC gear motors  
- **IR Sensor Array** – Line tracking  
- **Ultrasonic Sensors** – Distance sensing for target detection  
- **DC Gear Motors** – Precision movement  
- **Servo Motors** – Targeted ball shooting  
- **3D Printed Brackets** – Structural support  
- **Acrylic Chassis** – Lightweight, multi-floor frame

---

## 💻 Software Design

### Control Logic

- **Line Following**: Center IR sensor follows black track, side sensors correct deviation.  
- **Junction Handling**: Detected using a combination of sensor values; each junction triggers predefined behavior (e.g., turn, shoot).  
- **Shooting**: Triggered via ultrasonic proximity; servo actuates shooting mechanism based on distance thresholds.

### Platforms Used

- **Arduino IDE** – Programming and flashing firmware  
- **SolidWorks** – Mechanical design of chassis and brackets  
- **TinkerCAD** – Simulation and wiring planning  
- **Cura** – 3D printing slicing

---

## ⚙️ Setup Instructions

### Assembly

1. Cut and assemble a 3-layer acrylic chassis using screws and 3D-printed supports.  
2. Mount motors, IR sensors, ultrasonic sensors, and Arduino as per floor design.  
3. Wire components to Arduino Mega via L298N motor driver shield.  
4. Install shooting mechanisms using servo motors and ball holders.

### Software

1. Open Arduino IDE and upload `SelfGuidedProjectileBot.ino` to the Arduino Mega.  
2. Ensure proper calibration of IR and ultrasonic sensors.  
3. Power the system using a 12V supply or battery pack.  
4. Place the robot on the starting point of the black track and press reset to begin.

---

## 🏗️ 3D Design Overview

- **Base Floor**: Contains drive motors, IR sensors, and power unit  
- **Middle Floor**: Houses initial shooting mechanism  
- **Top Floor**: Hosts secondary shooter and additional components  
- Designed for compactness and modularity using PLA and 6mm acrylic

---

## 📄 License

This project is licensed under the MIT License. See the `LICENSE` file for details.
