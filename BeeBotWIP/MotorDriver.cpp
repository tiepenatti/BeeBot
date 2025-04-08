#include "MotorDriver.h"

MotorDriver::MotorDriver(uint8_t pwmA, uint8_t ain1, uint8_t ain2, 
                        uint8_t pwmB, uint8_t bin1, uint8_t bin2)
    : motorA(pwmA, ain1, ain2),
      motorB(pwmB, bin1, bin2) {
}

void MotorDriver::begin() {
    stop();
}

void MotorDriver::forward(uint8_t speed) {
    motorA.run(speed);
    motorB.run(speed);
}

void MotorDriver::backward(uint8_t speed) {
    motorA.reverse(speed);
    motorB.reverse(speed);
}

void MotorDriver::stop() {
    motorA.stop();
    motorB.stop();
}