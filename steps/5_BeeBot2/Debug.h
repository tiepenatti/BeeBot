#ifndef DEBUG_H
#define DEBUG_H

#include <Arduino.h>

#if defined(ARDUINO_AVR_UNO)
extern HardwareSerial Serial;
#endif

// Debug macro definitions
#define DEBUG  // Comment this line to disable debug output

#ifdef DEBUG
  #define DEBUG_BEGIN(x) Serial.begin(x)
  #define DEBUG_PRINT(x) Serial.print(x)
  #define DEBUG_PRINTLN(x) Serial.println(x)
#else
  #define DEBUG_BEGIN(x)
  #define DEBUG_PRINT(x)
  #define DEBUG_PRINTLN(x)
#endif

#endif // DEBUG_H