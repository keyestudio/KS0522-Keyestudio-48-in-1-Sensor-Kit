# Leçon 12 : Capteur magnétique Hall

> **Kit :** Keyestudio 48-in-1 Sensor Kit  
> **Carte :** Keyestudio V4.0 / carte compatible Arduino Uno ATmega328P

![Illustration du Projet 12 : Capteur magnétique Hall](../media/c3d4d513b72ac04fad7e4f3015bfb1ed.png)

## Description

Il s'agit d'un capteur d'induction magnétique. Il peut détecter des matériaux magnétiques dans une portée de détection allant jusqu'à 3 cm. La portée de détection est proportionnelle à la force du champ magnétique. La sortie est numérique marche/arrêt.

Ce capteur utilise le SFE Reed Switch - Magnetic Field Sensor.

## Spécification

- Détection de matériaux magnétiques

- Portée de détection : jusqu'à 3 cm

- Sortie : numérique marche/arrêt

- Taille : 30*20mm

- Poids : 3g

## Schéma de connexion

Tout d'abord, vous devez préparer les pièces suivantes avant la connexion :

- Carte V4.0\*1

- Capteur Hall \*1

- Câble USB\*1

- Fils de connexion\*3

Connectez la broche S du module à Digital 3 de la carte V4.0, connectez la broche négative au port GND, la broche positive au port 5V.

![Illustration du schéma de connexion](../media/db4db0c53435ceb1d6caaaf40502247a.jpeg)

## Exemple de code

Copiez et collez le code ci-dessous dans le logiciel Arduino.

```c
////////////////////////////////////////////////////////////////////
int ledPin = 13;                // choose the pin for the LED
int inputPin = 3;               // Connect sensor to input pin 3
int val = 0;                    // variable for reading the pin status

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare push button as input
}

void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, LOW);  // turn LED OFF
  } else {
    digitalWrite(ledPin, HIGH); // turn LED ON
  }
}
////////////////////////////////////////////////////////////////////
```

## Exemple de résultat

Branchez le tout et téléversez correctement le code sur la carte, vous verrez que l'indicateur D13 sur la carte V4.0 est éteint, et la LED sur le module est également éteinte.

![Illustration du résultat exemple](../media/102f67e289b5834de7fa80b6e6d99c20.png)

Mais si vous approchez une bille magnétique du module Hall, vous verrez que l'indicateur D13 sur la carte V4.0 s'allume, et la LED sur le module s'allume également.

![Illustration du résultat exemple](../media/c3c4044f2205dd1ff162ef7e211d2b2c.png)

---
