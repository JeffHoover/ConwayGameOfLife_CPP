#ifndef _BOARD_H_
#define _BOARD_H_
#include "stdbool.h"
#include "stdint.h"

#define ALIVE true
#define DEAD !ALIVE

#define NUM_ROWS 32
#define NUM_COLS 64

class Board {
protected:
  bool value[NUM_COLS][NUM_ROWS];

public:
  void set(uint8_t x, uint8_t y, bool state);
  bool get(uint8_t x, uint8_t y);
  uint8_t neighbors(uint8_t x, uint8_t y);
};

#endif
