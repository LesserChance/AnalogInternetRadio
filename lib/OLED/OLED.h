#ifndef OLED_H
#define OLED_H

#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <SPI.h>
#include <Wire.h>

#include <string>

// CONFIGURATION OPTIONS
#define ROTATION 1
#define TEXT_SIZE 3
#define MARGIN_TOP 10
#define MARGIN_LEFT 30
#define SCREEN_WIDTH 128  // OLED display width, in pixels
#define SCREEN_HEIGHT 64  // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1  // Reset pin # (or -1 if sharing Arduino reset pin)

class OLED {
   public:
    OLED();
    void setup();
    void drawText(std::string str);
    void setPower(bool _power);

   private:
    bool power = false;
    std::string currentText = "";
    void drawCurrentText();
};

#endif