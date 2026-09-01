#include <Arduino.h>
#include "Adafruit_ST7796S_kbv.h"
#include "User_Setup.h"
#include <SPI.h>

// Use hardware SPI on the ESP8266: MOSI=13, MISO=12, SCLK=14, then CS/DC/RST
// below.
//Adafruit_ST7796S_kbv tft = Adafruit_ST7796S_kbv(TFT_CS, TFT_DC, TFT_RST);

// SoftSPI - note that on some processors this might be *faster* than hardware
// SPI!
Adafruit_ST7796S_kbv tft = Adafruit_ST7796S_kbv(TFT_CS, TFT_DC, MOSI, SCK, TFT_RST, MISO);

unsigned long testText();
unsigned long testFilledCircles(uint8_t radius, uint16_t color);
unsigned long testCircles(uint8_t radius, uint16_t color);

void drawEyes(int radius) {
  int w = tft.width(), h = tft.height(), r2 = radius * 2;
  int x = w/4;
  int y = h/2;
  tft.fillCircle(x, y, r2, ST7796S_BLUE);

  int x_2 = w - w/4;
  tft.fillCircle(x_2, y, r2, ST7796S_BLUE);
}


void setup() {
  Serial.begin(9600);

  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ST7796S_BLACK);
  drawEyes(55);

  pinMode(LED_PIN, OUTPUT);
  pinMode(BEEP_PIN, OUTPUT);
}

void loop(void) {
  digitalWrite(LED_PIN, HIGH);
  digitalWrite(BEEP_PIN, HIGH);
  delay(1000);
  digitalWrite(LED_PIN, LOW);
  digitalWrite(BEEP_PIN, LOW);
  delay(1000);
}


unsigned long testFilledCircles(uint8_t radius, uint16_t color) {
  unsigned long start;
  int x, y, w = tft.width(), h = tft.height(), r2 = radius * 2;

  tft.fillScreen(ST7796S_BLACK);
  start = micros();
  for (x = radius; x < w; x += r2) {
    for (y = radius; y < h; y += r2) {
      tft.fillCircle(x, y, radius, color);
    }
  }

  return micros() - start;
}

unsigned long testCircles(uint8_t radius, uint16_t color) {
  unsigned long start;
  int x, y, r2 = radius * 2, w = tft.width() + radius,
            h = tft.height() + radius;

  // Screen is not cleared for this one -- this is
  // intentional and does not affect the reported time.
  start = micros();
  for (x = 0; x < w; x += r2) {
    for (y = 0; y < h; y += r2) {
      tft.drawCircle(x, y, radius, color);
    }
  }

  return micros() - start;
}
