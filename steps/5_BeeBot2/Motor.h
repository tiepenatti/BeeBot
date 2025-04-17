#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
public:
    Motor(int pwmPin, int dirPin, int brakePin, bool flipDirection = false);
    void forward(uint8_t speed);
    void reverse(uint8_t speed);
    void stop();
    void brake();
    void releaseBrake();
    bool isRunning();

private:
    int _pwmPin;
    int _dirPin;
    int _brakePin;
    uint8_t _runningSpeed;
    bool _flipDirection;
};

#endif