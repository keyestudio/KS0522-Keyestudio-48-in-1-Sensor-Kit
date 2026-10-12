# Leçon 22 : Son analogique

> **Kit :** Keyestudio 48-in-1 Sensor Kit  
> **Carte :** Keyestudio V4.0 / carte compatible Arduino Uno ATmega328P

![Illustration du Projet 22 : Son analogique](../media/a494bbec73f7c8ff91b3133c9d2798a7.jpeg)

## Description

Le capteur de son analogique est généralement utilisé pour détecter le volume des sons ambiants. Le capteur est équipé d'un potentiomètre que vous pouvez tourner pour ajuster le gain du signal.

Vous pouvez l'utiliser pour réaliser des projets intéressants et interactifs, comme un interrupteur commandé par la voix.

## Spécifications

- Tension d'alimentation : 3.3V à 5V

- Interface : Analogique

- Taille : 30*20mm

- Poids : 4g

## Schéma de connexion

Connectez la broche S du module à l'entrée analogique A0 de la carte V4.0, connectez la broche négative à GND, la broche positive à 5V.

![Illustration du schéma de connexion](../media/22e1124550d57015a6d2d5782b8febda.jpeg)

## Exemple de code

Copiez et collez le code ci-dessous dans l'IDE Arduino.

```c
////////////////////////////////////////////////////////////////////
int sensorPin =A0 ;
int value = 0;
void setup()
{
 Serial.begin(9600); }
void loop()
{
 value = analogRead(sensorPin);

Serial.println(value, DEC);

delay(50);
}
////////////////////////////////////////////////////////////////////
```

## Exemple de résultat

Une fois le câblage effectué et l'alimentation branchée, téléversez correctement le code, puis ouvrez le moniteur série et réglez le débit en bauds sur 9600 : vous verrez la valeur analogique. En parlant vers le microphone, la valeur augmentera. Illustré ci‑dessous.

![Illustration du résultat](../media/4d753036151413a1bdda3c0b283b8551.png)

---
