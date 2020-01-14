Files in this directory:
Arduino.h
mockArduino.c

For Conway, all we need to mock is setting pinmode,
digitalWrite, and digitalRead (for reading a floating 
pin to seed random )
void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t value);
int digitalRead(uint8_t pin);

