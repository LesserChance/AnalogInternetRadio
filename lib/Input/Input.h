#ifndef Input_H
#define Input_H

#include "Arduino.h"

// CONFIGURATION OPTIONS
#define PIN_SWITCH_ALARM_ENABLE 19      // latching
#define PIN_SWITCH_ALARM_ON 39          // latching
#define PIN_SWITCH_MODE_AM_FM 34        // latching
#define PIN_SWITCH_MODE_AUTO_MANUAL 35  // latching
#define PIN_SWITCH_MODE_POWER 5         // latching

#define PIN_POT_VOLUME 36

class Input {
   public:
    Input();
    void setup();
    void loop();
    bool switchedPower();
    bool switchedAlarm();

    bool isAlarmEnableOn();
    bool isAlarmOn();
    bool isAmFmOn();
    bool isAutoManualOn();
    bool isPowerOn();

    int getVolume();

   private:
    bool alarmEnableOn = false;
    bool alarmOn = false;
    bool amFmOn = false;
    bool autoManualOn = false;
    bool powerOn = false;

    bool switchedPowerInput = false;
    bool switchedAlarmInput = false;

    int volume = 0;
    void readVolume();
};

#endif