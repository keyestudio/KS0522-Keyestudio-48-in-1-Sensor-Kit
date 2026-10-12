# Leçon 04 : Feu tricolore

> **Kit :** Keyestudio 48-in-1 Sensor Kit  
> **Carte :** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Illustration du projet 4 : Feu tricolore](../media/a20653cffac8985dc4919614540ac367.jpeg)

## Description

Lors de l'apprentissage du microcontrôleur, on utilise généralement trois LED, à savoir les voyants rouge, vert et jaune, pour simuler le clignotement d'un feu tricolore via un branchement externe.

Cette fois-ci nous avons conçu spécialement ce module qui est très pratique pour le câblage ; sur le module vous pouvez voir les LED rouge, jaune et verte.

Ce module est entièrement compatible avec le microcontrôleur Arduino et le système Raspberry Pi.

## Spécification

- Tension de fonctionnement : 3.3-5v

- Type d'interface : numérique

- Connecteur PH2.54

## Schéma de connexion

Tout d'abord, vous devez préparer les pièces suivantes avant la connexion :

- Carte V4.0\*1

- Module de feu tricolore \*1

- Câble USB\*1

- Fils de connexion\*4

Connectez la broche R du module au Digital 5 de la carte V4.0, connectez la broche Y au Digital 4, la broche G au Digital 3, et la broche GND au port de masse.

![Illustration du schéma de connexion](../media/b6884692ce41d05d4afb167af5b2239d.jpeg)

## Code d'exemple

Copiez et collez le code ci-dessous dans le logiciel Arduino.

```c
////////////////////////////////////////////////////////////////////
int redled =5; // initialize digital pin 5.
int yellowled =4; // initialize digital pin 4.
int greenled =3; // initialize digital pin 3.
void setup()
{
pinMode(redled, OUTPUT);// set the pin with red LED as “output”
pinMode(yellowled, OUTPUT); // set the pin with yellow LED as “output”
pinMode(greenled, OUTPUT); // set the pin with green LED as “output”
}
void loop()
{
digitalWrite(greenled, HIGH);//// turn on green LED
delay(5000);// wait 5 seconds
digitalWrite(greenled, LOW); // turn off green LED
for(int i=0;i<3;i++)// blinks for 3 times
{
delay(500);// wait 0.5 seconds
digitalWrite(yellowled, HIGH);// turn on yellow LED
delay(500);// wait 0.5 seconds
digitalWrite(yellowled, LOW);// turn off yellow LED
}
delay(500);// wait 0.5 seconds
digitalWrite(redled, HIGH);// turn on red LED
delay(5000);// wait 5 seconds
digitalWrite(redled, LOW);// turn off red LED
}
////////////////////////////////////////////////////////////////////
```

## Exemple de résultat

Une fois le téléversement du code terminé et l'alimentation branchée, les trois LED sur le module simuleront automatiquement l'allumage et l'extinction du feu tricolore, en boucle.

![Illustration du résultat](../media/6dd1ff8660b0a62795bd53fc6b6ff591.png)

---
