#include "LEDs.h"

LEDs::LEDs() {}

void LEDs::setup() {
    pinMode(PIN_LED_STATIC, OUTPUT);
    pinMode(PIN_LED_POWER, OUTPUT);
}
void LEDs::setStaticAmt(int _staticAmt) { staticAmt = _staticAmt; }
void LEDs::setPower(bool _power) {
    power = _power;
    digitalWrite(PIN_LED_POWER, _power);

    if (!power) {
        setStaticLEDOff();
    }
}
void LEDs::loop() {
    unsigned long currenttime = millis();
    if (staticAmt == 0) {
        // no static (0% chance)
        setStaticLEDOn();
        staticSwitchTime = currenttime;
    } else {
        // switch the led on/off on some interval
        if (currenttime > staticSwitchTime) {
            switchStaticLED(currenttime);
        }
    }
}
int LEDs::getStaticOnDuration() {
    if (staticAmt == 1) {
        return 1200 + (std::rand() % 1000);  // (1200->2200)
    } else if (staticAmt == 2) {
        return 400 + (std::rand() % 500);  // (400->900)
    } else if (staticAmt == 3) {
        return 100 + (std::rand() % 400);  // (100->500)
    }
    return 0;
}
int LEDs::getStaticOffDuration() {
    if (staticAmt == 1) {
        return 0 + std::rand() % 20;  // (0->20)
    } else if (staticAmt == 2) {
        return 0 + std::rand() % 20;  // (0->20)
    } else if (staticAmt == 3) {
        return 30 + std::rand() % 30;  // (30->60)
    }
    return 0;
}
void LEDs::switchStaticLED(unsigned long currenttime) {
    if (staticLEDStatus == HIGH) {
        staticSwitchTime = currenttime + getStaticOffDuration();
        setStaticLEDOff();
    } else {
        staticSwitchTime = currenttime + getStaticOnDuration();
        setStaticLEDOn();
    }
}
void LEDs::setStaticLEDOn() {
    digitalWrite(PIN_LED_STATIC, HIGH);
    staticLEDStatus = HIGH;
}
void LEDs::setStaticLEDOff() {
    digitalWrite(PIN_LED_STATIC, LOW);
    staticLEDStatus = LOW;
}