#include "lib/Led/Led.cpp"
#include "lib/Buzzer/Buzzer.cpp"

const int ledPin = 10;
const int buzzerPin = 11;
const int soundSensorPin = 12;

const int BUZZING_TIME = 2000;
const int IDLE_TIME = 5000;

Led led(ledPin);
Buzzer buzzer(buzzerPin);

int lastSoundTime = 0;
bool buzzerStart = false;
bool buzzerStarted = false;
int ledToggleTime = 0;
int buzzerStartedTime = 0;

void setup() {
  pinMode(soundSensorPin, INPUT);
}

void loop() {
  int soundHigh = digitalRead(soundSensorPin);
  if (soundHigh && millis() - lastSoundTime > IDLE_TIME) {
    lastSoundTime = millis();
    buzzerStart = true;
  }

  if (buzzerStart) {
    if (millis() - ledToggleTime > 50) {
      led.toggle();
      ledToggleTime = millis();
    }

    if (!buzzerStarted) {
      buzzer.playSound(20000, BUZZING_TIME);
      buzzerStartedTime = millis();
      buzzerStarted = true;
    }

    if (millis() - buzzerStartedTime > BUZZING_TIME) {
      buzzerStarted = false;
      buzzerStart = false;
      led.off();
    }
  }
}
