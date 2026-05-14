# AccelGlow

Demo Video: [Watch AccelGlow in Action]([/IMG_3782.mp4](https://youtu.be/5spB4EzLQUQ))

A PWM-controlled Arduino motor/LED acceleration system using an L298N H-Bridge and custom 2x2 button matrix input.

## Overview

AccelGlow is an Arduino-based control system that simulates smooth acceleration using exponential PWM ramping. Using an L298N H-Bridge, a 2x2 button matrix, and either DC motors or LEDs, the project creates realistic acceleration behavior with directional control.

The project was built to explore:

* PWM motor control
* H-Bridge direction control
* Matrix keypad scanning
* Non-blocking timing using millis()
* Exponential acceleration curves
* Real-time serial debugging

### Features

* Smooth exponential acceleration
* Forward, backward, left, and right movement
* Custom 2x2 matrix button input
* Direction, button, and speed output
* Works with motors or LEDs for visual testing

### Demo

When running, the Serial Monitor outputs:

Button: 1 | Direction: Forward | Speed: 8
Button: 1 | Direction: Forward | Speed: 15
Button: 1 | Direction: Forward | Speed: 23
Button: 3 | Direction: Left | Speed: 48
Button: 0 | Direction: Stopped | Speed: 0

### Hardware Used
Arduino Uno (or compatible)
L298N Motor Driver
LEDs or DC motors
Push Buttons
Breadboards
Jumper wires
External power source (optional for motors)


### Wiring

| L298N Pin | Arduino Pin |
| --------- | ----------- |
| ENA       | 3 (PWM)     |
| ENB       | 9 (PWM)     |
| IN1       | 8           |
| IN2       | 4           |
| IN3       | 5           |
| IN4       | 6           |


### Button Matrix

| Matrix Pin | Arduino Pin |
| ---------- | ----------- |
| Row 1      | 10          |
| Row 2      | 11          |
| Col 1      | 12          |
| Col 2      | 13          |


### Controls

| Button | Action   |
| ------ | -------- |
| 1      | Forward  |
| 2      | Backward |
| 3      | Left     |
| 4      | Right    |


## How It Works
## 1. Matrix Scanning

The Arduino scans each row and checks each column for button presses.

## 2. Exponential Acceleration

Acceleration uses:

v_new =v+(0.07v+1)

This creates:

* Slow startup
* Smooth ramp-up
* Faster acceleration near max speed
  
## 3. PWM Output

Speed is sent through PWM to the L298N enable pins:

* ENA → pin 3
* ENB → pin 9

PWM range: 0 -> 255

## 4. Serial Debugging

AccelGlow reports:

* Button pressed
* Direction
* Current speed

Useful for testing and tuning acceleration.

## Future Improvements and Additions

* Add a joystick input
* Better Wire management
* clean up code
* Wireless control via Bluetooth

