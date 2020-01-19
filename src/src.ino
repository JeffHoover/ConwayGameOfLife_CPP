
#include <RGBmatrixPanel.h>
#include "game.h"

#define CLK 11 // USE THIS ON ADAFRUIT METRO M0, etc.
#define OE 9
#define LAT 10
#define A A0
#define B A1
#define C A2
#define D A3

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);

void setup()
{
  matrix.begin();
  gameSetup();
  Serial.begin(9600);
}

void loop()
{
  gameLoop();
}
