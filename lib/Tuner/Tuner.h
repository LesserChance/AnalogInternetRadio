#ifndef Tuner_H
#define Tuner_H

#include "AS5600.h"

// CONFIGURATION OPTIONS
// how many read values to average out to smooth out the signal
#define READINGS 20
// the minimum value that can be read from the AS5600
#define MIN_READ_VALUE 100
// the maximum value that can be read from the AS5600
#define MAX_READ_VALUE 3900
// how many stations are in each frequency band
#define STATIONS 15
// static increases to this amount as the tuner gets further from the center
#define MAX_STATIC 3

// CONSTANTS
#define STATION_RANGE ((MAX_READ_VALUE - MIN_READ_VALUE) / STATIONS)
#define STATIC_RANGE (STATION_RANGE / (MAX_STATIC * 2))

class Tuner {
   public:
    Tuner();
    void setup();
    void loop();
    int getStation();
    int getStatic();

   private:
    int readIndex = 0;
    int readTotal = 0;
    int readAverage = 0;
    int readData[READINGS];

    int stationValue = 0;
    int staticAmt = 0;

    void readAndCalculate();

    int roundToNearest(float number, float round);
    int clamp(int value, int min, int max);
};

#endif