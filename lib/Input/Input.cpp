#include "Input.h"

Input::Input() {}

void Input::setup() {
    pinMode(PIN_SWITCH_ALARM_ENABLE, INPUT_PULLDOWN);
    pinMode(PIN_SWITCH_ALARM_ON, INPUT_PULLDOWN);
    pinMode(PIN_SWITCH_MODE_AM_FM, INPUT_PULLDOWN);
    pinMode(PIN_SWITCH_MODE_AUTO_MANUAL, INPUT_PULLDOWN);
    pinMode(PIN_SWITCH_MODE_POWER, INPUT_PULLDOWN);
    // pinMode(PIN_POT_VOLUME, INPUT_PULLDOWN);

    powerInput = digitalRead(PIN_SWITCH_MODE_POWER);
}

void Input::loop() {
    int _powerInput = digitalRead(PIN_SWITCH_MODE_POWER);
    if (_powerInput != powerInput) {
        switchedPowerInput = true;
    } else {
        switchedPowerInput = false;
    }
    powerInput = _powerInput;
}

bool Input::switchedPower() { return switchedPowerInput; }

int Input::getPowerInput() { return powerInput; }