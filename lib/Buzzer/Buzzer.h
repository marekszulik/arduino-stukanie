#ifndef Buzzer_h
#define Buzzer_h

#include "Arduino.h"

class Buzzer
{
  public:
    Buzzer(int pin);
    void playSound(int sound, int duration);
  private:
    int _pin;
};

#endif
