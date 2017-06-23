#include "SPI.h"          //needed for Teensyview
#include <TeensyView.h>  // Include the SFE_TeensyView library
#include "pinout.h"
#include "sensors.H"
#include "main.h"

TeensyView oled(oledResetPin, oledDCPin, oledCSPin, oledSCKPin, oledMOSIPin);

uint8_t TCRobotics [] PROGMEM = {
0xFF, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xC1, 0x41, 0x41, 0x81, 0x41,
0x41, 0x81, 0x01, 0x81, 0x41, 0x41, 0x41, 0x81, 0x01, 0x81, 0x41, 0x41, 0x81, 0xF1, 0x01, 0x81,
0x41, 0x41, 0x41, 0x81, 0x01, 0x01, 0x01, 0x01, 0xF1, 0x81, 0x41, 0x41, 0x81, 0x01, 0xC1, 0x01,
0x01, 0x01, 0xC1, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,
0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0xFF,
0xFF, 0x00, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xC0, 0xCF, 0xC0, 0xC0, 0xCF, 0x00,
0x00, 0x0F, 0x00, 0x06, 0x89, 0xC9, 0xC5, 0xCF, 0xC0, 0xC7, 0xC8, 0xC8, 0x84, 0x8F, 0x00, 0x07,
0x09, 0xC9, 0xC9, 0xC5, 0xC0, 0xC0, 0xC0, 0xC0, 0xCF, 0x84, 0x08, 0x08, 0x07, 0x00, 0x20, 0x27,
0x18, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xE0,
0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0xE0, 0xE0, 0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF,
0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0xFC, 0xFE, 0xFF, 0x07, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x00, 0x00,
0x00, 0xFF, 0xFF, 0xFF, 0x60, 0x60, 0xE0, 0xF1, 0xBF, 0x1F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0xE0,
0xF0, 0xF8, 0x1C, 0x0C, 0x0C, 0x0C, 0x0C, 0x1C, 0xF8, 0xF0, 0xE0, 0x00, 0x00, 0x00, 0xFF, 0xFF,
0xFF, 0x18, 0x0C, 0x0C, 0x0C, 0x1C, 0xFC, 0xF8, 0xF0, 0x00, 0x00, 0xE0, 0xF0, 0xF8, 0x1C, 0x0C,
0x0C, 0x0C, 0x0C, 0x1C, 0xF8, 0xF0, 0xE0, 0x00, 0x00, 0x0C, 0xFF, 0xFF, 0xFF, 0x0C, 0x0C, 0x0C,
0x00, 0x00, 0x00, 0xFC, 0xFC, 0xFC, 0x00, 0x00, 0x00, 0xE0, 0xF0, 0xF8, 0x1C, 0x0C, 0x0C, 0x0C,
0x0C, 0x18, 0x00, 0x00, 0x00, 0x70, 0x78, 0xFC, 0xCC, 0xCC, 0x8C, 0x8C, 0x8C, 0x0C, 0x00, 0xFF,
0xFF, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x9F, 0x9F, 0x9F, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80,
0x80, 0x81, 0x83, 0x87, 0x8F, 0x9C, 0x9C, 0x98, 0x98, 0x98, 0x98, 0x98, 0x8C, 0x8C, 0x80, 0x80,
0x80, 0x9F, 0x9F, 0x9F, 0x80, 0x80, 0x81, 0x83, 0x87, 0x8F, 0x9E, 0x9C, 0x90, 0x80, 0x80, 0x83,
0x87, 0x8F, 0x9C, 0x98, 0x98, 0x98, 0x98, 0x9C, 0x8F, 0x87, 0x83, 0x80, 0x80, 0x80, 0x9F, 0x9F,
0x9F, 0x8C, 0x98, 0x98, 0x98, 0x9C, 0x8F, 0x8F, 0x83, 0x80, 0x80, 0x83, 0x87, 0x8F, 0x9C, 0x98,
0x98, 0x98, 0x98, 0x9C, 0x8F, 0x87, 0x83, 0x80, 0x80, 0x80, 0x8F, 0x8F, 0x9F, 0x98, 0x98, 0x98,
0x80, 0x80, 0x80, 0x9F, 0x9F, 0x9F, 0x80, 0x80, 0x80, 0x83, 0x8F, 0x8F, 0x9E, 0x98, 0x98, 0x98,
0x98, 0x8C, 0x80, 0x80, 0x80, 0x8C, 0x98, 0x98, 0x98, 0x99, 0x99, 0x9F, 0x8F, 0x87, 0x80, 0xFF
};

uint8_t TCRobotics2 [] PROGMEM = {
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x00, 0x00, 0x04, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x00, 0x00, 0x04, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x1D, 0x8E, 0x34, 0xE0, 0xB2, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x12, 0x51, 0x4D, 0x10, 0xCA, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x12, 0x4F, 0x45, 0xF0, 0x89, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x12, 0x51, 0x45, 0x00, 0x89, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x12, 0x53, 0x4D, 0x10, 0xC9, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x12, 0x4D, 0x34, 0xE0, 0xB0, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x00, 0x00, 0x00, 0x00, 0x03, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x01,
0xBF, 0xFE, 0x07, 0xF0, 0x7F, 0x80, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x01,
0xBF, 0xFE, 0x0F, 0xFC, 0x7F, 0xC0, 0x00, 0x03, 0x80, 0x00, 0x00, 0x00, 0x1C, 0x00, 0x00, 0x01,
0x81, 0xC0, 0x1E, 0x0C, 0x71, 0xE0, 0x00, 0x03, 0x80, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x01,
0x81, 0xC0, 0x38, 0x00, 0x70, 0xE0, 0x00, 0x03, 0x80, 0x00, 0x00, 0x38, 0x00, 0x00, 0x00, 0x01,
0x81, 0xC0, 0x78, 0x00, 0x70, 0xE0, 0x3F, 0x03, 0xBE, 0x03, 0xF0, 0x7F, 0x1C, 0x0F, 0x81, 0xFD,
0x81, 0xC0, 0x70, 0x00, 0x70, 0xE0, 0x7F, 0x83, 0xFF, 0x07, 0xF8, 0x7F, 0x1C, 0x1F, 0xC3, 0xFD,
0x81, 0xC0, 0x70, 0x00, 0x71, 0xC0, 0xE1, 0xC3, 0xC7, 0x8E, 0x1C, 0x38, 0x1C, 0x38, 0x47, 0x01,
0x81, 0xC0, 0x70, 0x00, 0x7F, 0x81, 0xC0, 0xE3, 0x83, 0x9C, 0x0E, 0x38, 0x1C, 0x70, 0x07, 0x01,
0x81, 0xC0, 0x70, 0x00, 0x7F, 0x01, 0xC0, 0xE3, 0x83, 0x9C, 0x0E, 0x38, 0x1C, 0x70, 0x07, 0xC1,
0x81, 0xC0, 0x70, 0x00, 0x73, 0x81, 0xC0, 0xE3, 0x83, 0x9C, 0x0E, 0x38, 0x1C, 0x70, 0x01, 0xF9,
0x81, 0xC0, 0x78, 0x00, 0x73, 0xC1, 0xC0, 0xE3, 0x83, 0x9C, 0x0E, 0x38, 0x1C, 0x70, 0x00, 0x7D,
0x81, 0xC0, 0x38, 0x00, 0x71, 0xE1, 0xC0, 0xE3, 0x83, 0x9C, 0x0E, 0x38, 0x1C, 0x78, 0x00, 0x1D,
0x81, 0xC0, 0x1E, 0x0C, 0x70, 0xF0, 0xE1, 0xC3, 0xC7, 0x0E, 0x1C, 0x38, 0x1C, 0x38, 0x44, 0x1D,
0x81, 0xC0, 0x0F, 0xFC, 0x70, 0x70, 0x7F, 0x83, 0xFF, 0x07, 0xF8, 0x3F, 0x1C, 0x3F, 0xC7, 0xF9,
0x81, 0xC0, 0x07, 0xF0, 0x70, 0x38, 0x3F, 0x03, 0xBC, 0x03, 0xF0, 0x0F, 0x1C, 0x0F, 0x83, 0xF1,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

void oledSplash() {
  oled.clear(ALL); // Clear the display's internal memory
  oled.clear(PAGE);
  oled.drawBitmap(TCRobotics);
  oled.display();  // Send the PAGE to the OLED memory
  delay(1000);
}

void setupOLED()   {
  oled.begin();    // Initialize the OLED
  oled.clear(ALL); // Clear the display's internal memory
  oled.clear(PAGE); // Clear the buffer.
  oled.setFontType(0);  // Set font to type 1
  oledSplash();
}

void oledShowData() {
  oled.clear(PAGE);  // Clear the page
  //FOR REFERENCE
  //oled.rect(5, 5, 20, 20);  // Draw a rectangle
  //oled.rectFill(35, 16, 23, 11);  // Draw a filled rectangle
  //oled.circle(22, 20, 7);  // Draw the circle:
  //oled.pixel(40, 7, WHITE, NORM);  // Draw a white pixel
  //oled.pixel(48, 21, BLACK, NORM);  // Draw a black pixel (on the above rectange)
  //oled.getLCDWidth() getLCDHeight

  oled.setCursor(0,0); // move cursor
  oled.print("Bat:");  // Write a byte out as a character
  oled.print(BattVoltage);  // Write a byte out as a character

  oled.setCursor(0,8); // move cursor
  oled.print("Ticks:");  // Write a byte out as a character
  //oled.print(oledCount);

  oled.setCursor(0,16); // move cursor
  oled.print("Line:");  // Write a byte out as a character
  oled.print(linePosition);  // Write a byte out as a character
  oled.display();  // Send the PAGE to the OLED memory
}
