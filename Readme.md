# Arduino Bee-Bot Project

This project aims to replicate the basic functionality of a Bee-Bot robot using an Arduino microcontroller.

## Phase 1: Basic Functionality (Button Input)

### 1.1 Project Goals

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

### Components Required

* Arduino Uno
* Lego DC Motors (2) with Wheels
* Motor Driver TB6612FNG
* Push Buttons (6)
* Power Source: 9V battery for Arduino, battery pack for motors
* Jumper Wires
* Breadboard

### Button Assignments

* **Forward:** Moves the Bee-Bot forward.
* **Backward:** Moves the Bee-Bot backward.
* **Left Turn:** Turns the Bee-Bot left.
* **Right Turn:** Turns the Bee-Bot right.
* **Clear Program:** Resets the stored command sequence.
* **Start Program:** Executes the stored command sequence.

### Phases

1.  **One button:**
    * Connect a button to pin 2 to control internal led.
2.  **One motor:**
    * Connect a motor to the motor driver.
    * Connect the motor driver to the Arduino.
    * Connect one push button to control the motor.
3.  **Two motors:**
    * Connect arduino to lego chasis with 2 motors and one free wheel, using the motor driver, and two buttons to turn on/off each motor
4.  **Full BeeBot:**
    * Add all 6 buttons
    * Implement storing logic and sequencing
    * Test parameters like time and current required for a 90 degree turn
    * Test a circuit like program
    * Let the kids have fun !

### Wiring Diagram

```
Arduino Uno                TB6612FNG Motor Driver
+---------+               +------------------+
|         |      VM  ----|  VM         AO1 |----- Motor1 +
|     5V  |----- VCC ----|  VCC        AO2 |----- Motor1 -
|    GND  |----- GND ----|  GND        BO1 |----- Motor2 +
|         |              |             BO2 |----- Motor2 -
|      D4 |----- PWMA ---|  PWMA       STBY|----- 5V
|      D5 |----- AIN1 ---|  AIN1           |
|      D6 |----- AIN2 ---|  AIN2           |
|      D7 |----- PWMB ---|  PWMB           |
|      D8 |----- BIN1 ---|  BIN1           |
|      D9 |----- BIN2 ---|  BIN2           |
|         |               +-----------------+
|         |
|      D2 |----- Forward Button    ---> GND
|      D3 |----- Backward Button   ---> GND
|     D10 |----- Left Turn Button  ---> GND
|     D11 |----- Right Turn Button ---> GND
|     D12 |----- Clear Button      ---> GND
|     D13 |----- Start Button      ---> GND
+---------+

Power Connections:
- Arduino: 9V battery via DC jack
- Motors (VM): 9V battery pack (6x AA batteries)

```

### Future work / ideas

* Add a camera and use COCO SSD[https://github.com/tensorflow/tfjs-models/blob/master/coco-ssd] to find a person in a frame and control motors to follow it
* Add microfone and Speach Commands[https://github.com/tensorflow/tfjs-models/blob/master/speech-commands] to control the BeeBot via voice commands