#include "gestionMatrice.h"

uint16_t flashColor = 0;
int nbFlash = 0;
bool isOn = false;
unsigned long lastTime = 0;

void flashMatrix(uint16_t c) {
  flashColor = c;
  nbFlash = 3;
  isOn = false;
}

void flashMatrix(uint16_t c, bool keepFlash) {
  flashColor = c;
  if (keepFlash) {
    nbFlash = -1; // Infinite flashes
  } else {
    nbFlash = 3;
  }
  isOn = false;
}

void updateFlash() {
  if (nbFlash == 0 || millis() - lastTime < 200) return;

  lastTime = millis();
  isOn = !isOn;
  if (isOn) {
    fillMatrix(flashColor);
  } else {
    fillMatrix(0);
  }
  if (!isOn && nbFlash > 0) nbFlash--;
}

void fillMatrix(uint16_t c) {
  matrix.fillScreen(c);
  matrix.show();
}

void stopFlash() {
  nbFlash = 0;
}