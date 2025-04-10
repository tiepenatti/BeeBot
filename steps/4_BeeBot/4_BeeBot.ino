// 2025-04-11 - Tie Penatti - 0.1.4
// Full BeeBot, see root readme.md for more details

/*

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
|      D2 |----- Start Button      ---> GND
|      D3 |----- Clear Button      ---> GND
|      D4 |----- Forward button    ---> GND
|      D5 |----- Left Button       ---> GND
|      D6 |----- Right Button      ---> GND
|      D7 |----- Back Button       ---> GND
+---------+

Power Connections:
- Arduino: 9V battery via DC jack
- Motors (VM): 9V battery pack (6x AA batteries)

*/

#include <Arduino.h>
#include "Debug.h"
#include "BeeBot.h"

// Pin definitions
const int MOTOR_PWMA = A0;
const int MOTOR_AIN2 = A1;
const int MOTOR_AIN1 = A2;
const int MOTOR_BIN1 = A3;
const int MOTOR_BIN2 = A4;
const int MOTOR_PWMB = A5;

const int BUTTON_START_PIN = 2;
const int BUTTON_CLEAR_PIN = 3;
const int BUTTON_FORWARD_PIN = 4;
const int BUTTON_LEFT_PIN = 5;
const int BUTTON_RIGHT_PIN = 6;
const int BUTTON_BACK_PIN = 7;

BeeBot beeBot(MOTOR_PWMA, MOTOR_AIN1, MOTOR_AIN2,
              MOTOR_PWMB, MOTOR_BIN1, MOTOR_BIN2,
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
}

void loop() {
    beeBot.update();
    delay(100);
}

