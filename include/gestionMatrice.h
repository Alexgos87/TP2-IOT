#pragma once
#include <Arduino.h>
#include <Adafruit_NeoMatrix.h>

extern Adafruit_NeoMatrix matrix;

void flashMatrix(uint16_t c);
void updateFlash();
void fillMatrix(uint16_t c);