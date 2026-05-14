# AccelGlow

A PWM-controlled Arduino motor/LED acceleration system using an L298N H-Bridge and custom 2x2 button matrix input.

## Overview

AccelGlow is an Arduino-based control system that simulates smooth acceleration using exponential PWM ramping. Using an L298N H-Bridge, a 2x2 button matrix, and either DC motors or LEDs, the project creates realistic acceleration behavior with directional control.

The project was built to explore:

PWM motor control
H-Bridge direction control
Matrix keypad scanning
Non-blocking timing using millis()
Exponential acceleration curves
Real-time serial debugging
