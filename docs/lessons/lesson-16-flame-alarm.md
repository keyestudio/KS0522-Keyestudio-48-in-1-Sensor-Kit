# Leçon 16 : Alarme de flamme

> **Kit :** Keyestudio Kit de capteurs 48-en-1  
> **Carte :** Keyestudio V4.0 / carte compatible Arduino Uno ATmega328P

![Projet 16 : illustration Alarme de flamme](../media/35c5a2593df5d4e76865158e790feada.png)

## Description

Ce capteur de flamme peut être utilisé pour détecter le feu ou d'autres sources lumineuses dont la longueur d'onde se situe entre 760nm \~ 1100nm.

Dans le jeu de robot-pompier, la flamme joue un rôle important dans la détection, pouvant servir d'yeux du robot pour trouver la source du feu.

## Spécifications

1. Tension d'alimentation : 3.3V à 5V

2. Plage de détection : 20cm (4.8V) \~ 100cm (1V)

3. Plage de bande spectrale : 760nm à 1100nm

4. Température de fonctionnement : -25℃ à 85℃

5. Interface : numérique

6. Taille : 44*16.7mm

7. Poids : 4g

## Schéma de connexion

Tout d'abord, vous devez préparer les pièces suivantes avant la connexion :

- Carte V4.0*1

- Capteur de flamme*1

- Câble USB*1

- Fils de connexion*3

Connectez la broche D0 du module à Digital 2 de la carte V4.0, la broche GND au port GND, et la broche VCC au port 5V.

![Illustration du schéma de connexion](../media/a1ee506fc9921c7616349500c258b733.jpeg)

## Code d'exemple

Copiez et collez le code ci-dessous dans le logiciel Arduino.

```c
////////////////////////////////////////////////////////////////////
const int flamePin = 2;     // the number of the flame pin
const int ledPin =  13;      // the number of the LED pin
// variables will change:
int State = 0;         // variable for reading status
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(flamePin, INPUT);
}
void loop(){
  // read the state of the value:
State = digitalRead(flamePin);
  if (State == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  }
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
////////////////////////////////////////////////////////////////////
```

## Exemple de résultat

Une fois le câblage effectué et l'alimentation mise, téléversez correctement le code sur la carte.

![Illustration du résultat d'exemple](../media/c769453bbd0e1c5fcf6c80cf697030b3.png)

Ensuite, si vous approchez un briquet du capteur, lorsque le capteur détecte la flamme, une autre DEL sur le capteur s'allume.

![Illustration du résultat d'exemple](../media/2ee5a36673d2cbeb934ca2af29dab607.png)

---
