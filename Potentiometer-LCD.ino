#include <Wire.h>
#include "rgb_lcd.h"

rgb_lcd lcd;

const int potentiometer = A3;  // Pin qu'on veut utiliser sur la carte Arduino.

int colorR = 0; // Init de la valeur pour le rouge
int colorB = 255; // Init de la valeur pour le bleu
int colorG = 0; // Init de la valeur pour vert

int val;

void setup() {
    lcd.begin(16, 2); //Initialise l'interface du LCD.
    pinMode(potentiometer, INPUT); //On met en sortie pin le potentiomètre
    lcd.clear();
}

void loop() {
    float value = analogRead(potentiometer);
    value = map(value, 0, 1023, -25, 85);// On crée une map qui permet de changer la plage de 0 à 1023 de -25 à 85.
    lcd.setCursor(6, 1); 
    lcd.print(value); 
    delay(500);
    lcd.setRGB(colorR, colorG, colorB);

}
