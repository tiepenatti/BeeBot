#include "Motor.h"

Motor::Motor(int pwmPin, int in1Pin, int in2Pin) : 
    _pwmPin(pwmPin), 
    _in1Pin(in1Pin), 
    _in2Pin(in2Pin),
    _runningSpeed(0) {
    pinMode(_pwmPin, OUTPUT);
    pinMode(_in1Pin, OUTPUT);
    pinMode(_in2Pin, OUTPUT);
    stop();
}

void Motor::run(int speed = FULL_SPEED) {
    digitalWrite(_in1Pin, HIGH);
    digitalWrite(_in2Pin, LOW);
    analogWrite(_pwmPin, speed);
    _runningSpeed = speed;
}

void Motor::reverse(int speed = FULL_SPEED) {
    digitalWrite(_in1Pin, LOW);
    digitalWrite(_in2Pin, HIGH);
    analogWrite(_pwmPin, speed);
    _runningSpeed = speed * -1;
}

void Motor::stop() {
    digitalWrite(_in1Pin, LOW);
    digitalWrite(_in2Pin, LOW);
    analogWrite(_pwmPin, 0);
    _runningSpeed = 0;
}

bool Motor::isRunning() {
    return _runningSpeed != 0;
}

void Motor::toggle() {
    if (isRunning()) {
        stop();
    } else {
        run();
    }
}