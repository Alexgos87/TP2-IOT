# Coffre-fort d'hôtel connecté

Prototype de coffre-fort à code (ESP32) : programmation d'un code à 4 chiffres,
fermeture, ouverture, et journal des événements dans Firestore.

## Broches utilisées

| Composant | Broche ESP32 |
|---|---|
| Bouton A | GPIO 13 |
| Bouton B | GPIO 12 |
| Afficheur TM1637 | CLK : GPIO 17, DIO : GPIO 16 |
| Matrice WS2812B | DIN : GPIO 18 |
| Servomoteur | Signal : GPIO 26 |

## Bibliothèques

- Adafruit NeoMatrix
- TM1637
- ESP32Servo
- Firebase Arduino Client Library for ESP8266 and ESP32

## Configuration

Copier `include/secret-example.h` vers `include/secrets.h` et remplir les vraies valeurs.

## Liens

[lien vers le repo](https://github.com/Alexgos87/TP2-IOT)

[lien vers la video](https://youtu.be/scQeLeZZ-Xg)