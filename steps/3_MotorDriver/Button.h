#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
public:
    Button(int pin);
    bool isReleased(unsigned long debounceDelay = 50); // true after releasing a button that was pressesd
    bool isPressed(); // true if button is currently pressed

private:
    int _pin;
    int _state;
    int _lastState;
    int _lastDebounceTime;
};

#endif