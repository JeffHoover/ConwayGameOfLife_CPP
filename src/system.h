#ifndef _SYSTEM_H_
#define _SYSTEM_H_

#include <stdint.h>

class system {
public:
  virtual void pinMode(uint8_t pin, uint8_t mode);
  virtual void digitalWrite(uint8_t pin, uint8_t value);
  virtual int digitalRead(uint8_t pin);
};

#endif