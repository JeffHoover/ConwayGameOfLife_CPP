
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

extern char buf[40];

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);

void setup()
{
  matrix.begin();
  gameSetup();
  Serial.begin(9600);
}

bool *current;
bool *next;

void loop()
{
  computeGeneration(*altGrid, *grid);
  display(*grid, &matrix);
  // Red pixel for frame indicator and 0,0 orientation
  matrix.drawPixel(2, 2, matrix.Color333(7, 0, 0));
  matrix.drawPixel(60, 2, matrix.Color333(0, 7, 7));
  // delay(1000);

  computeGeneration(*grid, *altGrid);
  display(*grid, &matrix);
  // Blue pixel for frame indicator and 0,0 orientation
  matrix.drawPixel(2, 2, matrix.Color333(0, 0, 7));
  matrix.drawPixel(60, 2, matrix.Color333(0, 7, 7));
  // delay(1000);
}

void display(bool *current, RGBmatrixPanel *myMatrix)
{
  int numPix = 0;
  for (int x = 0; x < NUM_COLS; x++)
  {
    for (int y = 0; y < NUM_ROWS; y++)
    {
      bool *cellIsAlive = current + (x * NUM_ROWS + y);

      uint8_t colorIntensity = *cellIsAlive * 3;
      myMatrix->drawPixel(x, y, myMatrix->Color333(colorIntensity, colorIntensity, colorIntensity));

      numPix++;
    }
  }

  sprintf(buf, "displayed %d pixels\n", numPix);
  Serial.println(buf);
  Serial.flush();
}
