# Leçon 13 : Capteur de percussion

> **Kit :** Keyestudio 48-in-1 Sensor Kit  
> **Carte :** Keyestudio V4.0 / carte compatible Arduino Uno ATmega328P

![Illustration du projet 13 : capteur de percussion](../media/cef729e5b57059bc14518b0e2fdd2817.png)

## Description

Ce module est un capteur de percussion. Lorsque vous le frappez, il peut envoyer un signal momentané.

Vous pouvez le combiner avec Arduino pour réaliser des expériences intéressantes, par ex. une batterie électronique.

## Spécifications

- Tension de fonctionnement: 5V

- Taille: 30\*20mm

- Poids: 3g

## Schéma de connexion

Avant la connexion, préparez les éléments suivants :

- Carte V4.0\*1

- Capteur de percussion \*1

- Câble USB\*1

- Fils de connexion\*3

Connectez la broche S du module au Digital 3 de la carte V4.0, connectez la broche négative au port GND, la broche positive au port 5V.

![Illustration du schéma de connexion](../media/1b9c27f145275e7a38d06763114f1847.jpeg)

## Exemple de code

Copiez et collez le code ci-dessous dans le logiciel Arduino.

```c
////////////////////////////////////////////////////////////////////
int Led=13;//define LED interface
int Shock=3;//define knock sensor interface
int val;//define digital variable val
void setup()
{
pinMode(Led,OUTPUT);//define LED to be output interface
pinMode(Shock,INPUT);//define knock sensor to be output interface
}
void loop()
{
val=digitalRead(Shock);//read the value of interface3 and evaluate it to val
if(val==HIGH)//when the knock sensor detect a signal, LED will be flashing
{
digitalWrite(Led,LOW);
}
else
{
digitalWrite(Led,HIGH);
}
}
////////////////////////////////////////////////////////////////////
```

![Illustration du code d'exemple](../media/c3fc14de7267b517a739268ed5b88674.png)

## Résultat

Après avoir réalisé le câblage et alimenté comme indiqué ci‑dessus, téléversez correctement le code, puis frappez le capteur : vous verrez que la LED D13 de la carte V4.0 et la LED D1 du capteur s'allument.

---
