# Leçon 25 : Gaz analogique

> **Kit :** Keyestudio 48-in-1 Kit de capteurs  
> **Carte :** Keyestudio V4.0 / carte ATmega328P compatible Arduino Uno

![Projet 25 : Gaz analogique (illustration)](../media/36f00d2a934c497f390b49c4113c7c04.png)

## Description

Ce capteur de gaz analogique MQ2 est utilisé dans les dispositifs de détection de fuites de gaz, tant dans l'électronique grand public que dans les applications industrielles. Ce capteur est adapté à la détection de GPL (LPG), i-butane, propane, méthane, alcool, hydrogène et fumée.

La plage de détection de ce capteur est très large, et il offre une grande sensibilité et une réponse rapide.

De plus, la sensibilité peut être ajustée en tournant le potentiomètre présent sur le capteur.

## Spécifications

- Alimentation : 5V

- Type d'interface : Analogique

- Circuit de pilotage simple

- Stable et longue durée de vie

## Schéma de connexion

Connectez la broche A0 du module à l'Analog A0 de la carte V4.0, connectez la broche GND au port GND, et la broche VCC au port 5V.

![Schéma de connexion (illustration)](../media/7b2cdff9418f79b2e9e566ce61a7966a.jpeg)

## Exemple de code

Copiez et collez le code ci-dessous dans le logiciel Arduino.

```c
////////////////////////////////////////////////////////////////////
//Arduino Sample Code
void setup()
{
  Serial.begin(9600); //Set serial baud rate to 9600 bps
}
void loop()
{
int val;
val=analogRead(0);//Read Gas value from analog 0
Serial.println(val,DEC);//Print the value to serial port
delay(100);
}

////////////////////////////////////////////////////////////////////
```

## Exemple de résultat

![Exemple de résultat (illustration)](../media/d440553d52e043d7a91928882d877dd1.png)

Une fois le câblage terminé et l'alimentation mise sous tension, téléversez correctement le code, puis ouvrez le moniteur série et réglez la vitesse sur 9600 bauds. Vous verrez la valeur analogique. Lors de la détection de gaz, la valeur changera.

![Exemple de résultat (illustration)](../media/cbf777feb6231d76347bc632f87d0e8e.jpeg)

---
