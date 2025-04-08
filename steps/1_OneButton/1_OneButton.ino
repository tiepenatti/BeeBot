// 2025-04-05 - Tie Penatti - 0.1.1
// 1 Pull-up Button Prototype - Turn led on/off with a button

/*
  Arduino             Button
                            
  +-----+              +---+
  |  2  |--------------|   |
  | GND |--------------|   |
  +-----+              +---+

- Pin 2: Connect to one terminal of the button
- GND: Connect to other terminal of button
*/

#include <Arduino.h>

const int BUTTON_PIN = 2;
const int LED_PIN = LED_BUILTIN; // Internal LED pin (13 on most Arduinos)

int buttonState = HIGH;
int lastButtonState = buttonState;
int ledState = LOW;

void setup() {
    // setup pins and modes
    pinMode(BUTTON_PIN, INPUT_PULLUP); // Button input with internal pull-up resistor
    pinMode(LED_PIN, OUTPUT); // allows to use the internal led as output

    // setup initial state
    digitalWrite(LED_PIN, ledState);
}

void loop() {
    lastButtonState = checkButtonState();
}

int checkButtonState() {
    buttonState = digitalRead(BUTTON_PIN);

    if (lastButtonState == LOW && buttonState == HIGH) {
        ledState = !ledState;
        digitalWrite(LED_PIN, ledState);
        debounceDelay();
    }
    return buttonState;
}

void debounceDelay() {
    delay(50);
}
