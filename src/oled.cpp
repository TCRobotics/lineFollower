#include "Arduino.h"
#include "SPI.h"
#include <TeensyView.h>  // Include the SFE_TeensyView library
#include "pinout.h"
#include "sensors.H"
#include "main.h"

int oledCount = 0;
TeensyView oled(oledResetPin, oledDCPin, oledCSPin, oledSCKPin, oledMOSIPin);

void setupOLED()   {
  oled.begin();    // Initialize the OLED
  oled.clear(ALL); // Clear the display's internal memory
  oled.clear(PAGE); // Clear the buffer.
}
const char *convertOledInt(uint16_t data, int chars) {
  static char buf[3];
  //strcpy(buf, u8g_u8toa( (uint8_t)(data), chars));
  return buf;
}

const char *convertOledFloat(uint16_t data) {
  static char buf[3];
  //strcpy(buf, u8g_u8toa( (uint8_t)(data), 1));
  buf[0] = (data / 10) + '0';
  buf[1] = '.';
  buf[2] = (data % 10) + '0';
  return buf;
}

const char *convertOledMmm(uint16_t data) {
  static char buf[8];
  buf[0] = ((data % 10000000)/100000)  + '0';
  buf[1] = ((data % 1000000)/100000)  + '0';
  buf[2] = ((data % 100000)/10000)  + '0';
  buf[3] = ((data % 10000)/1000)  + '0';
  buf[4] = '.';
  buf[5] = ((data % 1000)/100) + '0';
  buf[6] = ((data % 100)/10) + '0';
  buf[7] = (data % 10) + '0';
  return buf;
}

void showData() {
/*
  u8g_FirstPage(&u8g);
  do {

    u8g_DrawStr(&u8g,  0, 7, convertOledInt(sideSensorLeftValue/10,2));
    u8g_DrawStr(&u8g, 48, 7, convertOledInt(frontSensorLeftValue/10,2));
    u8g_DrawStr(&u8g, 64, 7, convertOledInt(frontSensorRightValue/10,2));
    u8g_DrawStr(&u8g, 115, 7, convertOledInt(sideSensorRightValue/10,2));

    u8g_DrawStr(&u8g, 00, 20, convertOledMmm(encoderL * mmPerTick));
    u8g_DrawStr(&u8g, 79, 20, convertOledMmm(encoderR * mmPerTick));

    if(wallsDetected & 0b010) u8g_DrawLine (&u8g, 47, 22, 76, 22);//north
    if(wallsDetected & 0b100) u8g_DrawLine (&u8g, 47, 22, 47, 49);//west
    if(wallsDetected & 0b001) u8g_DrawLine (&u8g, 76, 22, 76, 49);//east
    if(wallsDetected & 0b111) u8g_DrawLine (&u8g, 47, 49, 76, 49);//south

    u8g_DrawStr(&u8g,  59, 39, "A");


    u8g_DrawStr(&u8g, 0, 62, convertOledFloat(BattVoltage*10));
    u8g_DrawStr(&u8g, 18, 62, "V");

    //u8g_DrawStr(&u8g, 49, 62, "byTCRobotics");
  } while(u8g_NextPage(&u8g));
*/

  oled.clear(PAGE);  // Clear the page

  //oled.rect(5, 5, 20, 20);  // Draw a rectangle
  //oled.rectFill(35, 16, 23, 11);  // Draw a filled rectangle
  //oled.circle(22, 20, 7);  // Draw the circle:
  //oled.pixel(40, 7, WHITE, NORM);  // Draw a white pixel
  //oled.pixel(48, 21, BLACK, NORM);  // Draw a black pixel (on the above rectange)
  //oled.getLCDWidth() getLCDHeight

  oled.setFontType(0);  // Set font to type 1
  oled.setCursor(0,0); // move cursor
  oled.print("Bat:");  // Write a byte out as a character
  oled.print(BattVoltage);  // Write a byte out as a character
  oled.setCursor(0,8); // move cursor
  oled.print("Ticks:");  // Write a byte out as a character
  oled.print(oledCount);
  oledCount++;
  oled.display();  // Send the PAGE to the OLED memory
}
