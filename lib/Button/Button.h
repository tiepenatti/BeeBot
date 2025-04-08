#ifndef BUTTON_H
#define BUTTON_H

#include <Arduino.h>

class Button {
public:
    Button(int pin);
    bool isReleased(unsigned long debounceDelay = 50);

private:
    int _pin;
    int _state;
    int _lastState;
;

#endif