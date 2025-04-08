#include "Button.h"

Button::Button(int pin) : _pin(pin), _state(HIGH), _lastState(HIGH), _lastDebounceTime(0) {
    pinMode(_pin, INPUT_PULLUP);
}

bool Button::isReleased(unsigned long debounceDelay) {
    int reading = digitalRead(_pin);
    unsigned long currentTime = millis();

    if (reading != _lastState) {
        _lastDebounceTime = currentTime;
    }

    if ((currentTime - _lastDebounceTime) > debounceDelay) {
        if (reading != _state) {
            _state = reading;
            if (_state == HIGH && _lastState == LOW) {
                _lastState = _state;
                return true;
            }
        }
    }

    _lastState = reading;
    return false;
}