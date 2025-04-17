#include "MotorDriver.h"
#include "Debug.h"

MotorDriver::MotorDriver(int pwmA, int dirA, int breakA, int pwmB, int dirB, int breakB) 
    : _leftMotor(pwmA, dirA, breakA, true), _rightMotor(pwmB, dirB, breakB) {
}

void MotorDriver::begin() {
    stop();
}

void MotorDriver::stop() {
    _leftMotor.stop();
    _rightMotor.stop();
}

void MotorDriver::forward(uint8_t speed) {
    _leftMotor.forward(speed);
    _rightMotor.forward(speed);
}

void MotorDriver::backward(uint8_t speed) {
    _leftMotor.reverse(speed);
    _rightMotor.reverse(speed);
}

void MotorDriver::right(uint8_t speed) {
    _leftMotor.forward(speed);
    _rightMotor.reverse(speed);
}

void MotorDriver::left(uint8_t speed) {
    _leftMotor.reverse(speed);
    _rightMotor.forward(speed);
}

void MotorDriver::brake() {
    _leftMotor.brake();
    _rightMotor.brake();
}

bool MotorDriver::isMoving() {
    return _leftMotor.isRunning() || _rightMotor.isRunning();
}