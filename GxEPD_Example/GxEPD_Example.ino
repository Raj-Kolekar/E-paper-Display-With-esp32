#define ENABLE_GxEPD2_GFX 0 // we won't need the GFX base class
#include <GxEPD2_BW.h>
// Online tool for converting images to byte arrays: 
// https://javl.github.io/image2cpp/
#include "Bitmaps.h"

// Instantiate the GxEPD2_BW class for our display type 
GxEPD2_BW<GxEPD2_420, GxEPD2_420::HEIGHT>
display(GxEPD2_420(SS, 4, 5, 16));

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  // wait for display to become available
  display.init(115200);
  // display ACROBOTIC logo on the display
  drawBitmaps(ACROBOTIC_LOGO);
}

void loop() {
  // put your main code here, to run repeatedly:
}

void drawBitmaps(const unsigned char *bitmap) {
  // Configure the display according to our preferences
  display.setRotation(0);
  display.setFullWindow();
  // Display the bitmap image
  display.firstPage();
  do {
    display.fillScreen(GxEPD_WHITE);
    display.drawInvertedBitmap(0, 0, bitmap, display.epd2.WIDTH, display.epd2.HEIGHT, GxEPD_BLACK);
  } while(display.nextPage());
}
