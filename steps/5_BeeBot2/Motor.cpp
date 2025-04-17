#include "Motor.h"

Motor::Motor(int pwmPin, int dirPin, int brakePin, bool flipDirection) {
    _pwmPin = pwmPin;
    _dirPin = dirPin;
    _brakePin = brakePin;
    _runningSpeed = 0;
    _flipDirection = flipDirection;

    pinMode(_pwmPin, OUTPUT);
    pinMode(_dirPin, OUTPUT);
    pinMode(_brakePin, OUTPUT);
    
    stop();
    brake();
}

void Motor::forward(uint8_t speed) {
    releaseBrake();
    digitalWrite(_dirPin, _flipDirection ? LOW : HIGH);
    analogWrite(_pwmPin, speed);
    _runningSpeed = speed;
}

void Motor::reverse(uint8_t speed) {
    releaseBrake();
    digitalWrite(_dirPin, _flipDirection ? HIGH : LOW);
    analogWrite(_pwmPin, speed);
    _runningSpeed = speed;
}

void Motor::stop() {
    analogWrite(_pwmPin, 0);
    _runningSpeed = 0;
}

void Motor::brake() {
    stop();
    digitalWrite(_brakePin, HIGH);
}

void Motor::releaseBrake() {
    digitalWrite(_brakePin, LOW);
}

bool Motor::isRunning() {
    return _runningSpeed > 0;
}