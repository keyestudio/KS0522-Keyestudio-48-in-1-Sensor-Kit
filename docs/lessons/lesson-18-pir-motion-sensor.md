# Leçon 18 : Capteur de mouvement PIR

> **Kit :** Kit de capteurs Keyestudio 48-en-1  
> **Carte :** Keyestudio V4.0 / Carte compatible Arduino Uno ATmega328P

![Illustration du projet 18 : capteur de mouvement PIR](../media/ce608db25742f19fdf6eceda756a59d9.png)

## Description

Le capteur de mouvement infrarouge pyroélectrique peut détecter les signaux infrarouges émis par une personne ou un animal en mouvement, et fournir des signaux de commutation en sortie.

Il peut être appliqué à diverses situations pour détecter le mouvement du corps humain.

Les capteurs infrarouges pyroélectriques conventionnels nécessitent un détecteur pyroélectrique corporel, une puce professionnelle et un circuit périphérique complexe, ce qui entraîne une taille beaucoup plus importante, un circuit complexe et une fiabilité moindre.

Nous lançons maintenant ce nouveau capteur de mouvement infrarouge pyroélectrique, spécialement conçu pour Arduino.

Il utilise un capteur pyroélectrique infrarouge corporel numérique intégré, avec une taille réduite, une fiabilité accrue, une consommation d'énergie plus faible et un circuit périphérique plus simple.

## Spécifications

- Tension d'entrée : 3.3 \~ 5V, maximum 6V

- Courant de fonctionnement : 15 µA

- Température de fonctionnement : -20 \~ 85 ℃

- Tension de sortie : Haut 3V, Bas 0V

- Temps de maintien de la sortie (niveau Haut) : Environ 2,3 à 3 secondes

- Angle de détection : 100°

- Distance de détection : 7 mètres

- LED indicatrice de sortie (si la sortie est à l'état Haut, elle sera ALLUMÉE)

- Courant limite pour la broche : 100 mA

- Taille : 30*20 mm

- Poids : 4 g

## Schéma de connexion

Avant de connecter, vous devez préparer les pièces suivantes :

- Carte V4.0*1

- Capteur de mouvement PIR*1

- Câble USB*1

- Fils de raccordement*3

Connectez la broche S du module au Digital 3 de la carte V4.0, connectez la broche négative au port GND, la broche positive au port 5V.

![Schéma de connexion](../media/01970d510c03a8c7aa3ef0c13ea70cff.jpeg)

## Exemple de code

Copiez et collez le code ci-dessous dans l'IDE Arduino.

```c
////////////////////////////////////////////////////////////////////
byte sensorPin = 3;
byte indicator = 13;
void setup()
{
  pinMode(sensorPin,INPUT);
  pinMode(indicator,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  byte state = digitalRead(sensorPin);
  digitalWrite(indicator,state);
  if(state == 1)Serial.println("Somebody is in this area!");
  else if(state == 0)Serial.println("No one!");
  delay(500);
}
////////////////////////////////////////////////////////////////////
```

## Exemple de résultat

Une fois le câblage réalisé et l'alimentation connectée, et le code bien téléversé, si le capteur détecte une personne en mouvement à proximité, le témoin D13 sur la carte V4.0 s'allumera, et "Quelqu'un se trouve dans cette zone !" s'affichera sur le moniteur série de l'IDE Arduino.

S'il ne détecte aucun mouvement, le témoin D13 sur la carte V4.0 restera éteint, et "Personne !" s'affichera sur le moniteur série.

![Illustration du résultat (1)](../media/e25d28654311fa7820a1886a285353e5.png)

![Illustration du résultat (2)](../media/9b6209c8ce5b4be73f8378d21b639d28.jpeg)

---
