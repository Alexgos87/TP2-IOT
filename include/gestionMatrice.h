#pragma once
#include <Arduino.h>
#include <Adafruit_NeoMatrix.h>

extern Adafruit_NeoMatrix matrix;

void flashMatrix(uint16_t c);
void flashMatrix(uint16_t c, bool keepFlash);
void updateFlash();
void fillMatrix(uint16_t c);
void stopFlash();
bool isFlashing();