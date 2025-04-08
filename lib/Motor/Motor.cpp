#include "Motor.h"

Motor::Motor(int pin) : _pin(pin), _state(LOW) {
    pinMode(_pin, OUTPUT);
}

void Motor::run() {
    if (_state == HIGH) {
        return;
    }
    _state = HIGH;
    digitalWrite(_pin, _state);
}

void Motor::stop() {
    if (_state == LOW) {
        return;
    }
    _state = LOW;
    digitalWrite(_pin, _state);
}

void Motor::toggle() {
    if (_state == LOW) {
        run();
    } else {
        stop();
    }
}