# OopsStopper v1.0 - Edge Detection Robot

A table safety robot built with Arduino that autonomously navigates surfaces using infrared sensors to detect edges and prevent falls.

## Overview

OopsStopper v1.0 is an autonomous edge detection robot designed to safely navigate on elevated surfaces. Using real-time IR sensor input, the robot detects table edges and automatically adjusts its path to avoid falling, making it ideal for robotics education and IoT applications.


## Features

- Autonomous forward navigation on flat surfaces
- Real-time edge detection using IR sensors
- Automatic direction change when edge is detected
- Configurable motor speed and response timing
- Serial debugging support

## Hardware Requirements

| Component | Quantity | Specification |
|-----------|----------|---------------|
| Arduino Uno | 1 | ATmega328P |
| IR Sensor | 1 | Digital output |
| L298N Motor Driver | 1 | Dual H-Bridge |
| DC Motors | 4 | With wheels |
| Battery | 2 | 3.7V Lithium |
| Battery Holder | 1 | With power switch |
| Breadboard | 1 | Standard size |
| Jumper Wires | Multiple | Male-to-male |

## Circuit Configuration

### L298N Motor Driver
```
Arduino Pin 5  → ENA (PWM Speed Control A)
Arduino Pin 6  → IN1 (Motor A Direction)
Arduino Pin 7  → IN2 (Motor A Direction)
Arduino Pin 8  → IN3 (Motor B Direction)
Arduino Pin 9  → IN4 (Motor B Direction)
Arduino Pin 10 → ENB (PWM Speed Control B)
```

### IR Sensor
```
Arduino Pin 2 → OUT (Digital Signal)
Arduino 5V    → VCC
Arduino GND   → GND
```

### Power Supply
```
Battery 7.4V → Arduino Vin + L298N 12V
Common Ground: Arduino GND ↔ L298N GND
```

## Software Setup

### Prerequisites
- Arduino IDE 1.8.x or higher
- USB cable (data transfer capable)
- Basic knowledge of Arduino programming

### Installation

1. Clone the repository:
```bash
git clone https://github.com/yourusername/OopsStopper-v1.0.git
cd OopsStopper-v1.0
```

2. Open Arduino IDE and load the sketch:
```
File → Open → OopsStopper_v1.0.ino
```

3. Configure Arduino IDE:
```
Tools → Board → Arduino Uno
Tools → Port → [Select appropriate COM port]
```

4. Upload the code:
```
Sketch → Upload (or Ctrl+U)
```

## Configuration

Adjust these parameters in the code to customize behavior:

```cpp
const int MOTOR_SPEED = 150;      // Motor speed (0-255)
const int TURN_SPEED = 180;       // Turning speed
const int BACKWARD_TIME = 800;    // Backward duration (ms)
const int TURN_TIME = 600;        // Turn duration (ms)
```

## Operation

1. Place the robot on a flat elevated surface
2. Ensure IR sensor is mounted facing downward at 30-45° angle
3. Power on the system using the battery switch
4. Robot will move forward until an edge is detected
5. Upon edge detection, robot will:
   - Stop immediately
   - Move backward
   - Turn to change direction
   - Resume forward movement

## Debugging

Enable Serial Monitor for debugging:
```
Tools → Serial Monitor (Ctrl+Shift+M)
Baud Rate: 9600
```

The system outputs real-time sensor readings and operational status.

## Troubleshooting

**Motors not responding:**
- Verify battery voltage (minimum 7.4V)
- Check motor driver connections
- Confirm common ground between Arduino and L298N

**Edge detection failure:**
- Adjust IR sensor angle (should face downward)
- Modify sensor sensitivity using onboard potentiometer
- Verify sensor wiring connections

**Inconsistent behavior:**
- Check for loose wire connections
- Reduce motor speed for better response time
- Calibrate timing parameters in code

## Technical Specifications

- Operating Voltage: 7.4V DC
- Motor Speed Range: 0-255 (PWM)
- Sensor Response Time: <50ms
- Turn Radius: Approximately 30cm
- Operating Surface: Flat, non-reflective

## Key Learnings

This project provided practical experience in:
- Arduino microcontroller programming
- Sensor integration and real-time processing
- Motor control using H-bridge drivers
- Embedded systems design
- Hardware debugging and troubleshooting
- Autonomous navigation algorithms


## Author
"Rafiul Islam"  
GitHub: 

## Acknowledgments

- Arduino Community Documentation
- Open Source Hardware Community
