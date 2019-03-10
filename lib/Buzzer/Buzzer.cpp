#include "Arduino.h"
#include "Buzzer.h"

Buzzer::Buzzer(int pin) {
  pinMode(pin, OUTPUT);
  _pin = pin;
}

void Buzzer::playSound(int sound, int duration) {
  tone(_pin, sound, duration);
}
