#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
public:
    Button(int pin);
    bool isReleased(unsigned long debounceDelay = 10);
    bool isPressed();
    int getPin() const { return _pin; }

private:
    int _pin;
    int _state;
    int _lastState;
    int _lastDebounceTime;
};

#endif