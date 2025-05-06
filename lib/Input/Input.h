#ifndef Input_H
#define Input_H

#include "Arduino.h"

// CONFIGURATION OPTIONS
#define PIN_SWITCH_ALARM_ENABLE 36      // latching
#define PIN_SWITCH_ALARM_ON 39          // latching
#define PIN_SWITCH_MODE_AM_FM 34        // latching
#define PIN_SWITCH_MODE_AUTO_MANUAL 35  // latching
#define PIN_SWITCH_MODE_POWER 4         // latching

#define PIN_POT_VOLUME 15

class Input {
   public:
    Input();
    void setup();
    void loop();
    bool switchedPower();
    int getPowerInput();

   private:
    bool powerInput = false;
    bool switchedPowerInput = false;
};

#endif