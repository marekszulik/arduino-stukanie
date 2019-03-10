#include "Arduino.h"
#include "Led.h"

Led::Led(int pin) {
  pinMode(pin, OUTPUT);
  _pin = pin;
  _state = LOW;
}

void Led::on() {
  _state = HIGH;
  digitalWrite(_pin, _state);
}

void Led::off() {
  _state = LOW;
  digitalWrite(_pin, _state);
}

void Led::toggle() {
  _state = !_state;
  digitalWrite(_pin, _state);
}

void Led::toggleState() {
  _state = !_state;
}

void Led::invalidate() {
  digitalWrite(_pin, _state);
}

bool Led::isOn() {
  return _state == HIGH;
}
