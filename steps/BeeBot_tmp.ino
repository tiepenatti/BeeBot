// 2025-04-08 - Tie Penatti - 0.1.3
// Full BeeBot

/*
// ...existing code...

/// Arduino Pull-up Button
class Button {
public:
    Button(int pin) : _pin(pin), _state(HIGH), _lastState(HIGH) {
        pinMode(_pin, INPUT_PULLUP);
    }

    bool isReleased() {
        _state = digitalRead(_pin);
        if (_lastState == LOW && _state == HIGH) {
            _lastState = _state;
            return true;
        }
        _lastState = _state;
        return false;
    }

private:
    int _pin;
    int _state;
    int _lastState;
};

const int INITIAL_PIN = 2;
const int BUTTON_1_PIN = INITIAL_PIN;
const int BUTTON_2_PIN = INITIAL_PIN + 1;

Button button1(BUTTON_1_PIN);
Button button2(BUTTON_2_PIN);

void setup() {
    // setup pins and modes
    pinMode(BUTTON_PIN, INPUT_PULLUP); // Button input with internal pull-up resistor
    pinMode(LED_PIN, OUTPUT); // allows to use the internal led as output

    // setup initial state
    digitalWrite(LED_PIN, ledState);
}

void loop() {
    if (button1.isReleased()) {
        Serial.println("Button 1 released!");
        myFunction1();
    }

    if (button2.isReleased()) {
        Serial.println("Button 2 released!");
        myFunction2();
    }
}

void myFunction1() {
    // Function called on button 1 release
    Serial.println("Function 1 called");
}

void myFunction2() {
    // Function called on button 2 release
    Serial.println("Function 2 called");
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
*/
