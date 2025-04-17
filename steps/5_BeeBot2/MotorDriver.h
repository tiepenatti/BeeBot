#ifndef MOTOR_DRIVER_H
#define MOTOR_DRIVER_H

#include <Arduino.h>
#include "Motor.h"

class MotorDriver {
    public:
        MotorDriver(int pwmA, int dirA, int breakA, int pwmB, int dirB, int breakB);
        void begin();
        void stop();
        void forward(uint8_t speed);
        void backward(uint8_t speed);
        void left(uint8_t speed);
        void right(uint8_t speed);
        void brake();
        bool isMoving();

    private:
        Motor _leftMotor;
        Motor _rightMotor;
};

#endif