
#include <RGBmatrixPanel.h>
#include "life.h"
// Most of the signal pins are configurable, but the CLK pin has some
// special constraints.  On 8-bit AVR boards it must be on PORTB...
// Pin 8 works on the Arduino Uno & compatibles (e.g. Adafruit Metro),
// Pin 11 works on the Arduino Mega.  On 32-bit SAMD boards it must be
// on the same PORT as the RGB data pins (D2-D7)...
// Pin 8 works on the Adafruit Metro M0 or Arduino Zero,
// Pin A4 works on the Adafruit Metro M4 (if using the Adafruit RGB
// Matrix Shield, cut trace between CLK pads and run a wire to A4).

#define CLK 11 // USE THIS ON ADAFRUIT METRO M0, etc.
//#define CLK A4 // USE THIS ON METRO M4 (not M0)
//#define CLK 11 // USE THIS ON ARDUINO MEGA
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
}

bool *current;
bool *next;

void loop()
{
  // method NOT TESTED

  current = (bool *)grid;
  next = (bool *)altGrid;
  computeGeneration(current, next);

  display(next, &matrix);
  delay(5000);

  current = (bool *)altGrid;
  next = (bool *)grid;
  computeGeneration(current, next);

  display(next, &matrix);
  delay(5000);
}

void display(bool *current, RGBmatrixPanel *myMatrix)
{
  // method NOT TESTED

  for (int x = 0; x < NUM_ROWS; x++)
  {
    for (int y = 0; y < NUM_COLS; y++)
    {
      bool *cellIsAlive = current + (x * NUM_COLS + y);

      uint8_t colorIntensity = *cellIsAlive * 7;
      myMatrix->drawPixel(x, y, myMatrix->Color333(colorIntensity, colorIntensity, colorIntensity));
    }
  }
  myMatrix->drawPixel(2, 2, myMatrix->Color333(7, 0, 0)); // Red pixel for orientation
}