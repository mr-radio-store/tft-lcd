/*
Show letter
Line 1: "Hello"       (Yellow)
Line 2: "ST7735S"     (Cyan)
Line 3: "Welcome TFT" (Green)

on ST7735S

Wire Connection
Wiring: ST7735S TFT to Arduino UNO

Your code uses SPI (hardware SPI + control pins). Wire as follows:
TFT Display Pin	Arduino UNO Pin	Function
VCC	5V	Power supply
GND	GND	Ground
CS	10	Chip Select (TFT_CS)
RESET (RST)	8	Reset (TFT_RST)
DC (A0)	9	Data/Command (TFT_DC)
SDA (MOSI)	11	SPI MOSI (data line)
SCK	13	SPI Clock
LED (BL)	5V (via 100Ω res)	Backlight (can use 3.3V)

🧠 Note: Some modules are 3.3V logic. If yours is not 5V-tolerant, use a logic level shifter.

*/

#include <Adafruit_GFX.h>
#include <Adafruit_ST7735.h>
#include <SPI.h>

// Define TFT pins for UNO
#define TFT_CS     10
#define TFT_DC     9
#define TFT_RST    8

// Initialize TFT
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  tft.initR(INITR_BLACKTAB);  // or GREENTAB or REDTAB if BLACKTAB doesn't work
  tft.setRotation(1);         // Landscape
  tft.fillScreen(ST7735_BLACK);
}

void loop() {
  // Show text
  tft.fillScreen(ST7735_BLACK);
  tft.setTextColor(ST7735_YELLOW);
  tft.setTextSize(2);
  tft.setCursor(10, 20);
  tft.println("Hello");

  tft.setCursor(10, 50);
  tft.setTextColor(ST7735_CYAN);
  tft.println("ST7735S");

  tft.setCursor(10, 80);
  tft.setTextColor(ST7735_GREEN);
  tft.println("Welcome TFT");

  delay(500); // On for 500ms

  // Clear screen
  tft.fillScreen(ST7735_BLACK);
  delay(500); // Off for 500ms
}
