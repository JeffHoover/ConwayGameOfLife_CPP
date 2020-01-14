#include "system.h"
#include "Arduino.h"

void system::pinMode(uint8_t pin, uint8_t mode) { ::pinMode(pin, mode); }
void system::digitalWrite(uint8_t pin, uint8_t value) {
  ::digitalWrite(pin, value);
}
int system::digitalRead(uint8_t pin) { return ::digitalRead(pin); }