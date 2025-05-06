#include "Tuner.h"

AS5600 as5600(&Wire1);

Tuner::Tuner() {}

void Tuner::setup() {
    while (!Serial);
    Wire1.begin(16, 17);

    as5600.begin(4);                         //  set direction pin.
    as5600.setDirection(AS5600_CLOCK_WISE);  //  default, just be explicit.
    as5600.setOutputMode(AS5600_OUTMODE_ANALOG_100);

    int b = as5600.isConnected();
    Serial.print("Connect: ");
    Serial.println(b);

    std::fill_n(readData, READINGS, 0);
    for (int i = 0; i < READINGS; i++) {
        readAndCalculate();
    }
}

void Tuner::loop() { readAndCalculate(); }
int Tuner::getStation() { return stationValue; }
int Tuner::getStatic() { return staticAmt; }

void Tuner::readAndCalculate() {
    // get an average read value
    int angle = as5600.readAngle();
    int value = MAX_READ_VALUE - MIN_READ_VALUE -
                (clamp(angle, MIN_READ_VALUE, MAX_READ_VALUE) - MIN_READ_VALUE);
    readTotal = readTotal - readData[readIndex];
    readData[readIndex] = value;
    readTotal = readTotal + value;
    readIndex = (readIndex + 1) % READINGS;
    readAverage = std::floor(readTotal / READINGS);

    int stationNumber = roundToNearest(readAverage, STATION_RANGE);
    staticAmt = (int)std::abs(
        roundToNearest(stationNumber - readAverage, STATIC_RANGE) /
        STATIC_RANGE);
    stationValue = (int)stationNumber / STATION_RANGE;
}

int Tuner::roundToNearest(float number, float round) {
    return static_cast<int>(std::round(number / round) * round);
}

int Tuner::clamp(int value, int min, int max) {
    if (value < min) return min;
    if (value > max) return max;
    return value;
}