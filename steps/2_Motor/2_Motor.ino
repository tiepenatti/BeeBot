// 2025-04-05 - Tie Penatti - 0.1.1
// 2 - TB6612FNG Motor Driver Prototype - Turn motor on/off with a button

/*
Arduino Uno              TB6612FNG Driver              Motor
 _____                   ________________              _____
|     |                 |                |            |     |
| 5V  |-----.-----------|    VCC         |            |     |
|     |      \----------|    STBY        |            |     |
|     |                 |                |            |     |
| GND |-----------.-----|    GND         |            |     |
|     |          /      |                |            |     |
|  D2 |--[BTN]--/       |                |            |     |
|     |                 |                |            |     |
| A0  |-----------------|    PWMA        |            |     |
| A1  |-----------------|    AIN1        |            |     |
| A2  |-----------------|    AIN2        |            |     |
|     |                 |                |            |     |
|     |                 |    AO1         |------------|+    |
|     |                 |    AO2         |------------|−    |
|_____|                 |________________|            |_____|

Power Supply:
9V ------------------|VM on TB6612FNG|
*/

#include "Button.h"
#include "Motor.h"


const int MOTOR_PWMA = A0;
const int MOTOR_AIN1 = A1;
const int MOTOR_AIN2 = A2;

const int BUTTON_PIN = 2;

Button btn(BUTTON_PIN);
Motor motor(MOTOR_PWMA, MOTOR_AIN1, MOTOR_AIN2);

void setup() {
    // No setup needed as it's handled in the constructors
}

void loop() {
    if (btn.isReleased()) {
        motor.toggle();
        digitalWrite(LED_BUILTIN, motor.isRunning() ? HIGH : LOW);
    }
}
