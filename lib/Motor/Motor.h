#ifndef MOTOR_H
#define MOTOR_H

#include <Arduino.h>

class Motor {
public:
    Motor(int pin);
    void run();
    void stop();
    void toggle();

private:
    int _pin;
    int _state;
};

#endif