#ifndef BEEBOT_H
#define BEEBOT_H

#include <Arduino.h>
#include "Debug.h"
#include "Button.h"
#include "MotorDriver.h"
#include "Commands.h"

class BeeBot {
private:
    Button btnStart;
    Button btnClear;
    Button btnForward;
    Button btnLeft;
    Button btnRight;
    Button btnBack;
    MotorDriver motors;

    static const int MAX_COMMANDS = 40;
    Command commands[MAX_COMMANDS];
    int commandCount;
    bool isExecuting;

    // Command execution parameters (time in ms, speed in 0-255 range)
    static const int MOVE_DURATION = 1000;
    static const int TURN_DURATION = 750;
    static const int PAUSE_DURATION = 500;
    static const uint8_t MOVE_SPEED = 200;
    static const uint8_t TURN_SPEED = 160;

    void addCommand(Command cmd);
    void executeCommands();
    void clearCommands();

public:
    BeeBot(uint8_t pwmA, uint8_t ain1, uint8_t ain2, 
           uint8_t pwmB, uint8_t bin1, uint8_t bin2,
           uint8_t startPin, uint8_t clearPin,
           uint8_t forwardPin, uint8_t leftPin,
           uint8_t rightPin, uint8_t backPin);

    void begin();
    void update();  // Called in loop to handle button presses and commands
};

#endif