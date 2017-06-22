#include "SPI.h"          //needed for Teensyview
#include <TeensyView.h>  // Include the SFE_TeensyView library
#include "pinout.h"
#include "sensors.H"
#include "main.h"

TeensyView oled(oledResetPin, oledDCPin, oledCSPin, oledSCKPin, oledMOSIPin);

void setupOLED()   {
  oled.begin();    // Initialize the OLED
  oled.clear(ALL); // Clear the display's internal memory
  oled.clear(PAGE); // Clear the buffer.
  oled.setFontType(0);  // Set font to type 1
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
