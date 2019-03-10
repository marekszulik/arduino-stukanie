#ifndef Led_h
#define Led_h

#include "Arduino.h"

class Led
{
  public:
    Led(int pin);
    void on();
    void off();
    void toggle();
    void toggleState();
    void invalidate();
    bool isOn();
  private:
    int _pin;
    int _state;
};

#endif
