#include <Arduino.h>
#include <TFT_eSPI.h>

#define ledpin 16
#define buzzpin 2 //builtin led same pin, but inverted

TFT_eSPI tft;

// the setup function runs once when you press reset or power the board
void setup() {
  tft.init();
  tft.setRotation(1);

  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(TFT_WHITE, TFT_BLACK);
  tft.setTextSize(3);
  tft.setCursor(20, 20);
  tft.println("Hello!");

  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledpin, OUTPUT);
  pinMode(buzzpin, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(ledpin, HIGH);  // change state of the LED by setting the pin to the HIGH voltage level
  digitalWrite(buzzpin, HIGH);
  delay(1000);                      // wait for a second
  digitalWrite(ledpin, LOW);
  digitalWrite(buzzpin, LOW);   // change state of the LED by setting the pin to the LOW voltage level
  delay(1000);                      // wait for a second
}