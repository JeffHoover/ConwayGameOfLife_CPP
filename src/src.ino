
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

#define CLK  11   // USE THIS ON ADAFRUIT METRO M0, etc.
//#define CLK A4 // USE THIS ON METRO M4 (not M0)
//#define CLK 11 // USE THIS ON ARDUINO MEGA
#define OE   9
#define LAT 10
#define A   A0
#define B   A1
#define C   A2
#define D   A3

RGBmatrixPanel matrix(A, B, C, D, CLK, LAT, OE, false, 64);

void setup() {
  matrix.begin();
  gameSetup();
  

}

void loop() {

    bool *active;
    active = (bool *)grid;

    display(active);
    delay(5000);

    active = (bool *)altGrid;

    display(active);
    delay(5000);
    
}

void display(bool *active)
{
  for(int x = 0; x < NUM_ROWS; x++)
  {
        for(int y = 0; y < NUM_COLS; y++)
      {
        bool *cellIsAlive = active+(x*NUM_COLS + y);
        matrix.drawPixel(x, y, matrix.Color333(0 , 0, *cellIsAlive * 7));

      }
  }
  matrix.drawPixel(2,2, matrix.Color333(7,0,0));
}