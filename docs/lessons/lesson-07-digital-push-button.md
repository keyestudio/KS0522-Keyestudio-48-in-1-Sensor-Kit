# Leçon 07 : Bouton poussoir numérique

> **Kit :** Keyestudio 48-in-1 Sensor Kit  
> **Carte :** Keyestudio V4.0 / carte compatible Arduino Uno ATmega328P

![Illustration du projet 7 : bouton poussoir numérique](../media/a8707354e54ea51bb92584f791ae79e5.png)

## Description

C'est un module de bouton basique. Vous pouvez simplement le brancher sur un shield IO pour votre première expérimentation avec Arduino.

## Fonctionnalités

- Large plage de tension de 3.3V à 5V

- Interfaces facilement reconnaissables des capteurs ("A" pour analogique et "D" pour numérique)

- Trou de montage standard

- Icônes claires

- Connecteur de haute qualité

- Facile à brancher et à utiliser

- Grand bouton et capuchon de haute qualité

- Pour réaliser des projets intéressants et interactifs

## Spécifications

- Tension d'alimentation : 3.3V à 5V

- Interface : Digital

- Dimensions : 30*20mm

- Poids : 4g

## Schéma de connexion

Tout d'abord, préparez les éléments suivants avant la connexion :

- Carte V4.0*1

- Module de bouton poussoir*1

- Câble USB*1

- Fils de connexion*3

Connectez la broche S du module à Digital 3 de la carte V4.0, connectez la broche négative au port GND, la broche positive au port 5V.

![Illustration du schéma de connexion](../media/6ec73b961481bf0794572a842c5231fa.jpeg)

## Code d'exemple

Copiez et collez le code ci-dessous dans le logiciel Arduino.

```c
////////////////////////////////////////////////////////////////////
/* # When you push the digital button, the Led 13 on the board will be turned on. Otherwise,the led is turned off.
*/
int ledPin = 13;                // choose the pin for the LED
int inputPin = 3;               // Connect sensor to input pin 3
void setup() {
  pinMode(ledPin, OUTPUT);      // set LED as output
  pinMode(inputPin, INPUT);     // set pushbutton as input
}
void loop(){
  int val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, LOW);  // turn LED OFF
  } else {
    digitalWrite(ledPin, HIGH); // turn LED ON
  }
}
////////////////////////////////////////////////////////////////////
```

## Résultat

Câblez-le correctement comme sur la figure ci-dessous, puis téléversez le code sur la carte.

Lorsque vous appuyez sur le bouton numérique, la LED 13 de la carte V4.0 s'allume. Lorsque vous relâchez le bouton, la LED s'éteint. Illustré ci-dessous.

![Illustration du résultat](../media/ac03d3fa1c0f5de7dae18c6e64406e60.png)

---
