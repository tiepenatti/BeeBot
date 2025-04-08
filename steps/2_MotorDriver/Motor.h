#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
public:
    Motor(int pwmPin, int in1Pin, int in2Pin);
    void run(int speed = FULL_SPEED);
    void reverse(int speed = FULL_SPEED);
    void stop();
    void toggle();
    bool isRunning();

private:
    int _pwmPin;
    int _in1Pin;
    int _in2Pin;
    int _runningSpeed;
    static const int FULL_SPEED = 255;
};

#endif