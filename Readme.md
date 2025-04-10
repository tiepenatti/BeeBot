# Arduino + Lego Bee-Bot Project

This project aims to replicate the basic functionality of a Bee-Bot robot using an Arduino microcontroller. A Bee-Bot is a small, programmable, floor robot designed primarily for young children (typically ages 3-7) to introduce them to basic coding concepts.

## Project Goals

* Implement basic movement commands:
    * Forward
    * Backward
    * Left Turn
    * Right Turn
* Use push buttons for command input.
* Include buttons for:
    * Clear Program (reset command sequence)
    * Start Program (execute command sequence)
* No sensors will be used in this initial phase.

![Lego + Arduino Bee-Bot](assets/beebot.jpg)

## Components Required

* Arduino Uno
* Lego DC Motors (2) with Wheels
* Motor Driver TB6612FNG
* Push Buttons (6)
* Power Source: 9V battery for Arduino, battery pack for motors
* Jumper Wires
* Breadboard

## Button Assignments

* **Forward:** Moves the Bee-Bot forward.
* **Backward:** Moves the Bee-Bot backward.
* **Left Turn:** Turns the Bee-Bot left.
* **Right Turn:** Turns the Bee-Bot right.
* **Clear Program:** Resets the stored command sequence.
* **Start Program:** Executes the stored command sequence.

### Incremental development in 4 steps:

1.  **One button:**
    * Connect a pull-up button to pin 2 to control internal led.
2.  **One motor:**
    * Connect a motor to the motor driver.
    * Connect the motor driver to the Arduino.
    * Connect one push button to control the motor.
3.  **Two motors:**
    * Connect arduino to lego chasis with 2 motors and one free wheel, using the motor driver, and the 6 buttons, using the directional ones to control the motors and the other 2 to control the motor speed
4.  **Full BeeBot:**
    * Implement storing commands and sequencing
    * Test parameters like time and speed required for a 90 degree turn
    * Let the kids have fun !

## Wiring Diagram

```

Arduino Uno                TB6612FNG Motor Driver
+---------+              +------------------+
|         |      VM  ----|  VM         AO1 |----- Motor1 +
|     5V  |------.-------|  VCC        AO2 |----- Motor1 -
|         |       \------|  STBY       BO1 |----- Motor2 +
|    GND  |-----------.--|  GND        BO2 |----- Motor2 -
|         |   GNDM---/   |                 |
|         |              |                 |
|      A0 |--------------|  PWMA           |
|      A1 |--------------|  AIN2           |
|      A2 |--------------|  AIN1           |
|      A3 |--------------|  BIN1           |
|      A4 |--------------|  BIN2           |
|      A5 |--------------|  PWMB           |
|         |              +-----------------+
|         |
|      D2 |----- [Start Button] --------> GND
|      D3 |----- [Clear Button] --------> GND
|      D4 |----- [Forward button] ------> GND
|      D5 |----- [Left Button] ---------> GND
|      D6 |----- [Right Button] --------> GND
|      D7 |----- [Back Button] ---------> GND
+---------+

Power Connections:
- Arduino: 9V battery via DC jack
- Motors (VM): 9V battery pack (6x AA batteries)

```

## Future work / ideas

* Add a camera and use [COCO SSD](https://github.com/tensorflow/tfjs-models/blob/master/coco-ssd) to find a person in a frame and control motors to follow it
* Add microphone and [Speech Commands](https://github.com/tensorflow/tfjs-models/blob/master/speech-commands) to control the BeeBot via voice commands