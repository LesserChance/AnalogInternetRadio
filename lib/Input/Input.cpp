#include "Input.h"

Input::Input() {}

void Input::setup() {
    pinMode(PIN_SWITCH_ALARM_ENABLE, INPUT_PULLDOWN);
    pinMode(PIN_SWITCH_ALARM_ON, INPUT_PULLDOWN);
    pinMode(PIN_SWITCH_MODE_AM_FM, INPUT_PULLDOWN);
    pinMode(PIN_SWITCH_MODE_AUTO_MANUAL, INPUT_PULLDOWN);
    pinMode(PIN_SWITCH_MODE_POWER, INPUT_PULLDOWN);
    pinMode(PIN_POT_VOLUME, INPUT_PULLDOWN);

    alarmEnableOn = digitalRead(PIN_SWITCH_ALARM_ENABLE);
    alarmOn = digitalRead(PIN_SWITCH_ALARM_ON);
    amFmOn = digitalRead(PIN_SWITCH_MODE_AM_FM);
    autoManualOn = digitalRead(PIN_SWITCH_MODE_AUTO_MANUAL);
    powerOn = digitalRead(PIN_SWITCH_MODE_POWER);

    readVolume();
}

void Input::loop() {
    alarmEnableOn = digitalRead(PIN_SWITCH_ALARM_ENABLE);
    amFmOn = digitalRead(PIN_SWITCH_MODE_AM_FM);
    autoManualOn = digitalRead(PIN_SWITCH_MODE_AUTO_MANUAL);

    int _powerOn = digitalRead(PIN_SWITCH_MODE_POWER);
    switchedPowerInput = (_powerOn != powerOn);
    powerOn = _powerOn;

    int _alarmOn = (alarmEnableOn and digitalRead(PIN_SWITCH_ALARM_ON));
    switchedAlarmInput = (_alarmOn != alarmOn);
    alarmOn = _alarmOn;

    readVolume();
}

bool Input::switchedPower() { return switchedPowerInput; }
bool Input::switchedAlarm() { return switchedAlarmInput; }

bool Input::isAlarmEnableOn() { return alarmEnableOn; }
bool Input::isAlarmOn() { return alarmOn; }
bool Input::isAmFmOn() { return amFmOn; }
bool Input::isAutoManualOn() { return autoManualOn; }
bool Input::isPowerOn() { return powerOn; }
int Input::getVolume() { return volume; }

void Input::readVolume() {
    int volumeRaw = analogRead(PIN_POT_VOLUME);
    volume = map(volumeRaw, 0, 4095, 5, 100);
}