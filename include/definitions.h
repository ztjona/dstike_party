
#pragma once
#include <Arduino.h>
#include <tft.h> // my tft library
#include <Adafruit_NeoPixel.h>
#include <BuzzerESP32.h>

#define TFT_DC 22
#define TFT_RST 23

#define TFT_MOSI 17 // for hardware SPI data pin (all of available pins)
#define TFT_SCLK 16 // for hardware SPI sclk pin (all of available pins)

#define BUTTON_PRESS 18
#define BUTTON_LEFT 5
#define BUTTON_RIGHT 19

#define BUZZER 32
#define PIXEL_PIN 33 // Digital IO pin connected to the NeoPixels.

#define PIXEL_COUNT 1

#define LED_HIGHLIGHT 27
// SD
#define DAT2 12
#define DAT3 13
#define CMD 15
#define CLK 14
#define DAT0 2
#define DAT1 4
#define card 21

// constructors
Arduino_ST7789 tft(TFT_DC, TFT_RST, TFT_MOSI, TFT_SCLK); //for display without CS pin

Adafruit_NeoPixel pixel(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

Buzzer buzzer(BUZZER);