#include <Arduino.h>
#include <TM1637Display.h>
#include <Adafruit_NeoMatrix.h>
#include <ESP32Servo.h>
#include "gestionMatrice.h"
#include "gestionBouton.h"
#include "gestionCode.h"

//pin servo
#define SERVO_PIN 26

//pin matrice
#define MATRIX_PIN 18
#define BRIGHTNESS 10

//pin ecran 4 digits
#define CLK_PIN 17
#define DIO_PIN 16

#define BTN_PIN_A 13
#define BTN_PIN_B 12

Servo servo;

Adafruit_NeoMatrix matrix(8, 8, MATRIX_PIN,
  NEO_MATRIX_TOP + NEO_MATRIX_LEFT + NEO_MATRIX_ROWS +
  NEO_MATRIX_PROGRESSIVE, NEO_GRB + NEO_KHZ800);

TM1637Display display(CLK_PIN, DIO_PIN);

Button btnA = {BTN_PIN_A};
Button btnB = {BTN_PIN_B};

bool isEnteringCode = false;

void setup() {
  Serial.begin(9600);
  //setup de l’écran digital :
  display.setBrightness(0x0f);
  display.clear();
  //setup de la matrice :
  matrix.begin();
  matrix.setTextWrap(false);
  matrix.setBrightness(BRIGHTNESS);
  matrix.fillScreen(0);
  matrix.show();
  //setup du servo :
  servo.attach(SERVO_PIN);
  servo.write(90);
  //setup des boutons :
  pinMode(BTN_PIN_A, INPUT_PULLUP);
  pinMode(BTN_PIN_B, INPUT_PULLUP);
  fillMatrix(matrix.Color(0, 255, 0));
}

void loop() {
  updateFlash();
  bool isBLongPressed = isLongPress(btnB);

  if (!isEnteringCode) {
    if (isBLongPressed) {
      flashMatrix(matrix.Color(255, 165, 0), true);
      isEnteringCode = true;
      startEnteringCode();
    }
  } else if (enterCode()) {
    isEnteringCode = false;
    stopFlash();
    fillMatrix(matrix.Color(0, 0, 255));
  }
}