#include "gestionBouton.h"

const unsigned long LONG_PRESS_TIME = 3000; // ms

bool isButtonPressed(Button &b) {
  if (millis() - b.lastRead >= 50) {
    b.lastRead = millis();
    b.state = digitalRead(b.pin) == LOW;
  }
  return b.state;
}

bool isLongPress(Button &b) {
  if (isButtonPressed(b)) {
    if (!b.wasDown) {
      b.wasDown = true;
      b.pressStart = millis();
    }
    return millis() - b.pressStart > LONG_PRESS_TIME;
  }
  b.wasDown = false;
  return false;
}