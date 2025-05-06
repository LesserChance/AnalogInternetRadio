#include <Arduino.h>
#include <Input.h>
#include <LEDs.h>
#include <OLED.h>
#include <Radio.h>
#include <SSIDSetup.h>
#include <Tuner.h>

#include <string>

SSIDSetup server;
OLED oled;
Tuner tuner;
Radio radio;
Input input;
LEDs leds;

int station;
int staticAmt;
int loopCount = 0;
bool power = false;

void setup() {
    Serial.begin(115200);

    Serial.println("Starting...");
    server = SSIDSetup(true);
    server.setup();

    input = Input();
    input.setup();
    power = true;

    oled = OLED();
    oled.setup();
    oled.drawText("KEXP");

    tuner = Tuner();
    tuner.setup();

    radio = Radio();
    radio.setup();

    leds = LEDs();
    leds.setup();
    leds.setPower(power);
}

void loop() {
    // read new switch inputs
    input.loop();

    if (input.switchedPower()) {
        power = input.getPowerInput();
        radio.setPower(power);
        leds.setPower(power);
        oled.setPower(power);
    }

    if (!power) {
        return;
    }

    // get any newly tuned station
    tuner.loop();
    station = tuner.getStation();
    staticAmt = tuner.getStatic();
    // Serial.println(staticAmt);

    // update the LEDs
    leds.setStaticAmt(staticAmt);
    leds.loop();

    // set the new station
    radio.setStaticAmt(staticAmt);
    radio.setStation(station);

    // draw the station name to the oled
    oled.drawText(radio.getStationName());

    // output audio
    radio.loop();
}
