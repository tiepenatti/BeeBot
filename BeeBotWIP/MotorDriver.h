#ifndef MOTORDRIVER_H
#define MOTORDRIVER_H

#include <Arduino.h>
#include "Motor.h"

class MotorDriver {
private:
    Motor motorA;
    Motor motorB;

public:
    static const uint8_t FULL_SPEED = 255;

    MotorDriver(uint8_t pwmA, uint8_t ain1, uint8_t ain2, 
                uint8_t pwmB, uint8_t bin1, uint8_t bin2);
    void begin();
    void forward(uint8_t speed = FULL_SPEED);
    void backward(uint8_t speed = FULL_SPEED);
    void right(uint8_t speed = FULL_SPEED);
    void left(uint8_t speed = FULL_SPEED);
    void stop();
    void brake();
};

#endif