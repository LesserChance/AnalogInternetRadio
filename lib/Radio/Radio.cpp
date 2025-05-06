#include "Radio.h"
Audio audio;
Audio noise;

Radio::Radio() {}

void Radio::setup() {
    initSPIFFS();

    audio.setPinout(MAX98357A_I2S_BCLK, MAX98357A_I2S_LRC, MAX98357A_I2S_DOUT);
    audio.setVolume(100);
    // audio.connecttohost("http://vis.media-ice.musicradio.com/CapitalMP3");
    connectToStation();

    noise.setPinout(MAX98357A_I2S_BCLK, MAX98357A_I2S_LRC, MAX98357A_I2S_DOUT);
    noise.setVolume(10);
    noise.connecttoFS(SPIFFS, "/audio/whitenoise.wav");
    noise.setFileLoop(true);
}
void Radio::initSPIFFS() {
    if (!SPIFFS.begin(true)) {
        Serial.println("An error has occurred while mounting SPIFFS");
    }
}
void Radio::setPower(bool _power) {
    power = _power;

    if (power) {
        // reconnect to the station
        connectToStation();
    }
}
std::string Radio::getStationName() { return stationName; }
void Radio::setStaticAmt(int _staticAmt) { staticAmt = _staticAmt; }
void Radio::setBand(int _band) {
    if (band != _band) {
        band = _band;
        connectToStation();
    }
}
void Radio::setStation(int _station) {
    if (station != _station) {
        station = _station;
        connectToStation();
    }
}
void Radio::connectToStation() {
    if (band == BAND_FM) {
        audio.connecttohost(fmStations[station][0].c_str());
        stationName = fmStations[station][1];
    } else if (band == BAND_AM) {
        audio.connecttohost(amStations[station][0].c_str());
        stationName = amStations[station][1];
    }
}

void Radio::loop() {
    if (staticAmt == 0 or staticAmt == 1) {
        // no static at all
        audio.loop();
    } else if (staticAmt == 2) {
        // less frequent static (10% chance)
        if (std::rand() % 100 < 10) {
            noise.loop();
        } else {
            audio.loop();
        }
    } else if (staticAmt == 3) {
        // most frequent static (75% chance)
        if (std::rand() % 100 < 75) {
            noise.loop();
        } else {
            audio.loop();
        }
    }
}