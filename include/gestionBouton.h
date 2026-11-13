#pragma once
#include <Arduino.h>


// Aide de Claude : mes fonctions partageaient les mêmes variables, donc l'état
// d'un bouton écrasait celui de l'autre. Claude a suggéré une struct Button
// pour que chaque bouton garde ses propres variables.
struct Button {
  int pin;
  bool state;
  unsigned long lastRead;
  bool wasDown;
  unsigned long pressStart;
};

bool isButtonPressed(Button &b);
bool isLongPress(Button &b);