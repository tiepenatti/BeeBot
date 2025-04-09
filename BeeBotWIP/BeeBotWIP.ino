// tmp wip file for testing

/*

Arduino Uno                TB6612FNG Motor Driver
+---------+              +------------------+
|         |      VM  ----|  VM         AO1 |----- Motor1 +
|     5V  |----- VCC ----|  VCC        AO2 |----- Motor1 -
|    GND  |----- GND ----|  GND        BO1 |----- Motor2 +
|         |              |             BO2 |----- Motor2 -
|      A0 |--------------|  PWMA       STBY|----- 5V
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

#include "Button.h"
#include "MotorDriver.h"

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

Button btnStart(BUTTON_START_PIN);
Button btnClear(BUTTON_CLEAR_PIN);
Button btnForward(BUTTON_FORWARD_PIN);
Button btnLeft(BUTTON_LEFT_PIN);
Button btnRight(BUTTON_RIGHT_PIN);
Button btnBack(BUTTON_BACK_PIN);

 MotorDriver motors(MOTOR_PWMA, MOTOR_AIN1, MOTOR_AIN2, MOTOR_PWMB, MOTOR_BIN1, MOTOR_BIN2);

void setup() {
    Serial.begin(9600);
    while (!Serial) {
        ; // Wait for serial port to connect. Needed for native USB port only
    }
    Serial.println("BeeBot Test");
    Serial.println("initializing motors...");

    // Initialize both motors in stopped state
    motors.begin();

    pinMode(LED_BUILTIN, OUTPUT);
    Serial.println("Waiting for button presses...");
}

void loop() {
    bool anyButtonPressed = false;
    uint8_t speed = 16;

    // Check each button and print debug info if pressed
    if (btnStart.isPressed()) {
        Serial.println("Start button is pressed!");
        // anyButtonPressed = true;
        if (speed < 128) {
            speed = speed << 1;
        }
    }
    if (btnClear.isPressed()) {
        Serial.println("Clear button is pressed!");
        // anyButtonPressed = true;
        if (speed > 2) {
            speed = speed >> 1;
        }
    }
    if (btnForward.isPressed()) {
        Serial.println("Forward button is pressed!");
        anyButtonPressed = true;
        motors.forward(speed);
    }
    if (btnLeft.isPressed()) {
        Serial.println("Left button is pressed!");
        anyButtonPressed = true;
        motors.left(speed);
    }
    if (btnRight.isPressed()) {
        Serial.println("Right button is pressed!");
        anyButtonPressed = true;
        motors.right(speed);
    }
    if (btnBack.isPressed()) {
        Serial.println("Back button is pressed!");
        anyButtonPressed = true;
        motors.backward(speed);
    }
    
    if (!anyButtonPressed) {
        Serial.println("Motors stopping!");
        motors.stop();
    }

    // Control LED based on any button being pressed
    digitalWrite(LED_BUILTIN, anyButtonPressed ? HIGH : LOW);
    
    // Small delay to avoid flooding the serial monitor
    delay(100);
}
