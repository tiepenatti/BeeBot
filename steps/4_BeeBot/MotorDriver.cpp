#include "MotorDriver.h"

MotorDriver::MotorDriver(uint8_t pwmA, uint8_t ain1, uint8_t ain2, 
                        uint8_t pwmB, uint8_t bin1, uint8_t bin2)
    : motorLeft(pwmA, ain1, ain2),
      motorRight(pwmB, bin1, bin2) {
}

void MotorDriver::begin() {
    stop();
}

void MotorDriver::forward(uint8_t speed) {
    motorLeft.forward(speed);
    motorRight.forward(speed);
}

void MotorDriver::backward(uint8_t speed) {
    motorLeft.reverse(speed);
    motorRight.reverse(speed);
}

void MotorDriver::right(uint8_t speed) {
    motorLeft.forward(speed);
    motorRight.reverse(speed);
}

void MotorDriver::left(uint8_t speed) {
    motorLeft.reverse(speed);
    motorRight.forward(speed);
}

void MotorDriver::stop() {
    motorLeft.stop();
    motorRight.stop();
}

void MotorDriver::brake() {
    motorLeft.brake();
    motorRight.brake();
}

bool MotorDriver::isMoving() {
    return motorLeft.isRunning() || motorRight.isRunning();
}