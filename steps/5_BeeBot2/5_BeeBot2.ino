// 2025-04-17 - Tie Penatti - 0.1.5
// Full BeeBot, using diymore L298NH Motor Driver Shield

/*

Arduino Uno                L298NH Motor Driver Shield (diymore)
+---------+              +------------------+
|         |              |                  |
|     5V  |--------------|  5V         OUT1 |----- Motor1 +
|    3.3V |              |             OUT2 |----- Motor1 -
|    GND  |--------------|  GND        OUT3 |----- Motor2 +
|         |              |             OUT4 |----- Motor2 -
|         |              |                  |
|     D12 |--------------|  Motor A Dir     | 
|     D13 |--------------|  Motor B Dir     |
|      D3 |--------------|  PWMA            |
|     D11 |--------------|  PWMB            |
|      D9 |--------------|  Break A         |
|      D8 |--------------|  Break B         |
|      A0 |--------------|  Current Sense A |  (not used)
|      A1 |--------------|  Current Sense B |  (not used)
|         |              +-----------------+
|         |
|      D2 |----- [ Start Button   ]---> GND
|      D4 |----- [ Clear Button   ]---> GND
|      D5 |----- [ Forward Button ]---> GND
|      D6 |----- [ Left Button    ]---> GND
|      D7 |----- [ Right Button   ]---> GND
|     D10 |----- [ Back Button    ]---> GND
+---------+

Power Connections:
- Arduino: 9V battery via DC jack
- Motors: External 12V via shield power terminal

Notes:
- PWMA on D3 and PWMB on D11 for independent motor speed control
- Current sensing pins A0 and A1 available for future motor current monitoring
- Break pins can be used for quick motor stopping

*/

#include <Arduino.h>

#include "Debug.h"
#include "BeeBot.h"

// Pin definitions for diymore L298NH Shield
const int MOTOR_DIR_A = 12;    // Motor A direction
const int MOTOR_DIR_B = 13;    // Motor B direction
const int MOTOR_PWMA = 3;      // PWM control for Motor A
const int MOTOR_PWMB = 11;     // PWM control for Motor B
const int MOTOR_BREAK_A = 9;   // Break control for Motor A
const int MOTOR_BREAK_B = 8;   // Break control for Motor B
// const int MOTOR_SENSE_A = A0;  // Current sensing A (unused)
// const int MOTOR_SENSE_B = A1;  // Current sensing B (unused)

// Button pins using remaining available digital pins. Only pin 2 and 3 allow interruptions
const int BUTTON_START_PIN = 2;
const int BUTTON_CLEAR_PIN = 4;
const int BUTTON_FORWARD_PIN = 5;
const int BUTTON_LEFT_PIN = 6;
const int BUTTON_RIGHT_PIN = 7;
const int BUTTON_BACK_PIN = 10;

const int LED_OFF = HIGH;
const int LED_ON = LOW;

// Create BeeBot instance with the new pin configuration
BeeBot beeBot(MOTOR_PWMA, MOTOR_DIR_A, MOTOR_BREAK_A,
              MOTOR_PWMB, MOTOR_DIR_B, MOTOR_BREAK_B,
              BUTTON_START_PIN, BUTTON_CLEAR_PIN,
              BUTTON_FORWARD_PIN, BUTTON_LEFT_PIN,
              BUTTON_RIGHT_PIN, BUTTON_BACK_PIN);

void setup() {
    DEBUG_BEGIN(9600);
    #ifdef DEBUG
    while (!Serial) {
        ; // Wait for serial port to connect. Needed for native USB port only
    }
    #endif

    DEBUG_PRINTLN("Bee-Bot!!");
    beeBot.begin();
    
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, LED_OFF);
}

void loop() {
    beeBot.update();
    digitalWrite(LED_BUILTIN, LED_ON);
    delay(100);
    digitalWrite(LED_BUILTIN, LED_OFF);
}

