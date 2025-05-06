#include "OLED.h"
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

OLED::OLED() {}

void OLED::setup() {
    // SSD1306_SWITCHCAPVCC = generate display voltage from 3.3V internally
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("SSD1306 allocation failed"));
        for (;;);  // Don't proceed, loop forever
    }

    display.clearDisplay();
}

void OLED::setPower(bool _power) {
    power = _power;
    Serial.print("OLED POWER, ");
    Serial.println(power);

    if (!power) {
        display.clearDisplay();
        display.display();
        Serial.println("clear");
    } else {
        drawCurrentText();
    }
}
void OLED::drawText(std::string str) {
    if (str == currentText) return;

    currentText = str;
    drawCurrentText();
}
void OLED::drawCurrentText() {
    display.clearDisplay();

    display.setRotation(ROTATION);
    display.setTextSize(TEXT_SIZE);
    display.setTextColor(WHITE);
    display.setCursor(MARGIN_LEFT, MARGIN_TOP);

    // Use full 256 char 'Code Page 437' font
    display.cp437(true);

    for (char& c : currentText) {
        display.write(c);
        display.write("\n");
        display.setCursor(MARGIN_LEFT, display.getCursorY());
    }
    display.display();
}