#include "lib/Led/Led.cpp"
#include "lib/Buzzer/Buzzer.cpp"

#include <Stepper.h>

#define STEPS 128

const int IDLE_TIME = 180 * 1000;
const int RIDE_TIME = 30 * 1000;
const int SOUND_SENSOR_PIN = 7;
const int MOVEMENT_DISTANCE = 15000;

Stepper stepper (STEPS, 2, 4, 3, 5);

long lastSoundTime = 0;
bool shouldMove = false;
bool moving = false;
long movementForwardTime = 0;

void setup() {
  pinMode(SOUND_SENSOR_PIN, INPUT);
  stepper.setSpeed(200);
}

void loop() {
  int soundHigh = digitalRead(SOUND_SENSOR_PIN);
  if (!shouldMove && soundHigh && (millis() - lastSoundTime > IDLE_TIME || lastSoundTime == 0)) {
    lastSoundTime = millis();
    shouldMove = true;
  }

  if (shouldMove) {
    if (!moving) {
      moving = true;
      movementForwardTime = millis();
      stepper.step(-MOVEMENT_DISTANCE);
      stepper.step(MOVEMENT_DISTANCE);
    }

    if (moving && millis() - movementForwardTime > RIDE_TIME) {
      shouldMove = false;
      moving = false;
    }
  }
}
