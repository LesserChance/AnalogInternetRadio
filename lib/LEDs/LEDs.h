#ifndef LEDs_H
#define LEDs_H

#include "Arduino.h"

// CONFIGURATION OPTIONS
#define PIN_LED_STATIC 32
#define PIN_LED_POWER 33

class LEDs {
   public:
    LEDs();
    void setup();
    void loop();
    void setStaticAmt(int _staticAmt);
    void setPower(bool _power);

   private:
    bool power = false;
    int staticAmt = 0;
    unsigned long staticSwitchTime = 0;
    int staticLEDStatus = LOW;

    int getStaticOnDuration();
    int getStaticOffDuration();

    void switchStaticLED(unsigned long currenttime);
    void setStaticLEDOn();
    void setStaticLEDOff();
};

#endif