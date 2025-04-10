#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
public:
    Motor(int pwmPin, int in1Pin, int in2Pin);
    void forward(int speed);
    void reverse(int speed);
    void stop();
    void brake();
    bool isRunning();

private:
    int _pwmPin;
    int _in1Pin;
    int _in2Pin;
    int _runningSpeed;
};

#endif