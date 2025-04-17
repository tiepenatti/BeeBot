#include <Arduino.h>
#include "BeeBot.h"

BeeBot* BeeBot::instance = nullptr; // Store instance for interrupt handler

BeeBot::BeeBot(uint8_t pwmA, uint8_t ain1, uint8_t ain2,
               uint8_t pwmB, uint8_t bin1, uint8_t bin2,
               uint8_t startPin, uint8_t clearPin,
               uint8_t forwardPin, uint8_t leftPin,
               uint8_t rightPin, uint8_t backPin)
    : btnStart(startPin)
    , btnClear(clearPin)
    , btnForward(forwardPin)
    , btnLeft(leftPin)
    , btnRight(rightPin)
    , btnBack(backPin)
    , motors(pwmA, ain1, ain2, pwmB, bin1, bin2)
    , commandCount(0)
    , isExecuting(false) {
    instance = this;
}

void BeeBot::begin() {
    motors.begin();
    clearCommands();

    // Disabled for now as only pin 2 n 3 allow interrupts
    // Set up clear button pin for interrupt
    // pinMode(btnClear.getPin(), INPUT_PULLUP);
    // Set up interrupt for clear button. 
    // attachInterrupt(digitalPinToInterrupt(btnClear.getPin()), handleClearInterrupt, FALLING);

    DEBUG_PRINTLN("BeeBot initialized and ready!");
}

void BeeBot::clearCommands() {
    commandCount = 0;
    isExecuting = false;
    DEBUG_PRINTLN("Commands cleared!");
}

void BeeBot::addCommand(Command cmd) {
    if (commandCount < MAX_COMMANDS && !isExecuting) {
        commands[commandCount++] = cmd;
        DEBUG_PRINT("Added command: ");
        DEBUG_PRINTLN(commandCount);
    }
}

void BeeBot::executeCommands() {
    if (commandCount == 0) {
        DEBUG_PRINTLN("No commands to execute!");
        return;
    }

    isExecuting = true;
    DEBUG_PRINTLN("Executing commands...");

    for (int i = 0; i < commandCount; i++) {

        if (btnClear.isPressed() || btnClear.isReleased() ) {
            DEBUG_PRINTLN("Clear button pressed, finishing command execution!");
            motors.brake();
            isExecuting = false;
            return;
        }

        DEBUG_PRINT("Executing command ");
        DEBUG_PRINTLN(i + 1);

        switch (commands[i]) {
            case CMD_FORWARD:
                motors.forward(MOVE_SPEED);
                delay(MOVE_DURATION);
                break;
            case CMD_BACKWARD:
                motors.backward(MOVE_SPEED);
                delay(MOVE_DURATION);
                break;
            case CMD_LEFT:
                motors.left(TURN_SPEED);
                delay(TURN_DURATION);
                break;
            case CMD_RIGHT:
                motors.right(TURN_SPEED);
                delay(TURN_DURATION);
                break;
        }
        
        motors.brake();
        if (btnClear.isPressed() || btnClear.isReleased() ) {
            DEBUG_PRINTLN("Clear button pressed, finishing command execution!");
            isExecuting = false;
            return;
        }
        delay(PAUSE_DURATION);
    }

    DEBUG_PRINTLN("Command execution complete!");
    isExecuting = false;
}

void BeeBot::handleClearInterrupt() {
    DEBUG_PRINTLN("Clear button pressed! Emergency stop triggered!");
    
    if (instance != nullptr) {
        instance->emergencyStop();
    }
}

void BeeBot::emergencyStop() {
    motors.stop();
    clearCommands();
    DEBUG_PRINTLN("Emergency stop triggered!");
}

void BeeBot::update() {

    if (btnClear.isReleased() ) {
        DEBUG_PRINTLN("Clear button pressed!");
        emergencyStop();
    }

    if (btnStart.isReleased() && !isExecuting) {
        DEBUG_PRINTLN("Start button pressed!");
        executeCommands();
    }

    if (btnForward.isReleased() && !isExecuting) {
        DEBUG_PRINTLN("Forward command added!");
        addCommand(CMD_FORWARD);
    }

    if (btnLeft.isReleased() && !isExecuting) {
        DEBUG_PRINTLN("Left command added!");
        addCommand(CMD_LEFT);
    }

    if (btnRight.isReleased() && !isExecuting) {
        DEBUG_PRINTLN("Right command added!");
        addCommand(CMD_RIGHT);
    }

    if (btnBack.isReleased() && !isExecuting) {
        DEBUG_PRINTLN("Backward command added!");
        addCommand(CMD_BACKWARD);
    }
}

void BeeBot::forward() {
    motors.forward(MOVE_SPEED);
    delay(MOVE_DURATION);
    motors.stop();
    delay(PAUSE_DURATION);
}

void BeeBot::back() {
    motors.backward(MOVE_SPEED);
    delay(MOVE_DURATION);
    motors.stop();
    delay(PAUSE_DURATION);
}

void BeeBot::left() {
    motors.left(TURN_SPEED);
    delay(TURN_DURATION);
    motors.stop();
    delay(PAUSE_DURATION);
}

void BeeBot::right() {
    motors.right(TURN_SPEED);
    delay(TURN_DURATION);
    motors.stop();
    delay(PAUSE_DURATION);
}