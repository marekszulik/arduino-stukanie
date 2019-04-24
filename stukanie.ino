#include <Stepper.h>

// My stepper motor is apparently designed to have 64 steps (max speed), but I _think_ setting the steps to 128
// makes it faster.
#define STEPS 128

// Since we don't want the robot to listen to sounds while we fall asleep, we set an initial delay of 4 hours
const long INITIAL_DELAY = 4 * 60 * 60 * 1000L;

// The robot should not move if it moved in the last 3 minutes.
const long IDLE_TIME = 180 * 1000L;

const int MOVEMENT_DISTANCE = 15000;

const int SOUND_SENSOR_PIN = 7;

Stepper stepper (STEPS, 2, 4, 3, 5);

long lastSoundTime = 0;

void setup() {
  pinMode(SOUND_SENSOR_PIN, INPUT);
  stepper.setSpeed(STEPS);
}

void loop() {
  int soundHigh = digitalRead(SOUND_SENSOR_PIN);
  if (soundHigh && isTimeConstraintMet()) {
    lastSoundTime = millis();
    stepper.step(-MOVEMENT_DISTANCE);
    stepper.step(MOVEMENT_DISTANCE);
  }
}

bool isTimeConstraintMet() {
  return millis() > INITIAL_DELAY && millis() - lastSoundTime > IDLE_TIME;
}
