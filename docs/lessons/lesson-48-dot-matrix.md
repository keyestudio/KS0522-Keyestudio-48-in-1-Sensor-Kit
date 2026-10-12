# Leçon 48 : Matrice de points

> **Kit :** Keyestudio 48-in-1 Sensor Kit  
> **Carte :** Keyestudio V4.0 / Carte compatible Arduino Uno ATmega328P

![Illustration du projet 48 : Matrice de points](../media/10e87958bbef207075643ae4f5481457.jpeg)

## Introduction

Quoi de mieux qu'une seule LED ? Beaucoup de LED ! Une façon amusante de créer un petit affichage est d'utiliser une matrice 8x8. Ce module utilise la puce HT16K33 pour piloter une matrice de points 8x8.

Il suffit d'utiliser le port de communication I2C du microcontrôleur pour contrôler la matrice, ce qui permet d'économiser davantage de broches du microcontrôleur. Le module de matrice est livré avec un connecteur 4 broches au pas de 2,54 mm.

Vous pouvez connecter le module à la carte de contrôle pour la communication à l'aide de fils de liaison.

De plus, il est fourni avec trois interrupteurs DIP. Vous pouvez basculer les commutateurs de manière aléatoire pour sélectionner l'adresse de communication I2C.

## Paramètres d'adresse

|   0x70   |          |          |      |   0x71   |          |          |      |   0x72   |          |          |
| :------: | :------: | :------: | ---- | :------: | :------: | :------: | ---- | :------: | :------: | :------: |
| A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |
| 0（ARRÊT） | 0（ARRÊT） | 0（ARRÊT） |      | 1（MARCHE）  | 0（ARRÊT） | 0（ARRÊT） |      | 0（ARRÊT） | 1（MARCHE）  | 0（ARRÊT） |
|          |          |          |      |          |          |          |      |          |          |          |
| **0x73** |          |          |      | **0x74** |          |          |      | **0x75** |          |          |
| A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |
| 1（MARCHE）  | 1（MARCHE）  | 0（ARRÊT） |      | 0（ARRÊT） | 0（ARRÊT） | 1（MARCHE）  |      | 1（MARCHE）  | 0（ARRÊT） | 1（MARCHE）  |
|          |          |          |      |          |          |          |      |          |          |          |
| **0x76** |          |          |      | **0x77** |          |          |      |          |          |          |
| A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |      |          |          |          |
| 0（ARRÊT） | 1（MARCHE）  | 1（MARCHE）  |      | 1（MARCHE）  | 1（MARCHE）  | 1（MARCHE）  |      |          |          |          |

## Détails techniques

- Interface : connecteur 4 broches

- Tension de fonctionnement : DC 4.5V-5.5V

- Livré avec trois interrupteurs DIP pour la sélection d'adresse

- Dimensions：52mm\*34mm\*11mm

- Poids：13.2g

## Guide de branchement

Connectez la broche SCL au port Analog A5, la broche SDA au port Analog A4 ; connectez la broche VCC au port 5V, la broche GND au port GND.

![Illustration du guide de branchement](../media/e2c09c1a7851f64ad03a027c1aa25a14.jpeg)

## Code de test

Téléchargez la bibliothèque :

```C
#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#ifndef _BV
#define _BV(bit) (1<<(bit))
#endif
Adafruit_LEDBackpack matrix = Adafruit_LEDBackpack();
uint8_t counter = 0;
void setup() {
  Serial.begin(9600);
  Serial.println("HT16K33 test");
  matrix.begin(0x70);  // pass in the address
}
void loop() {
  // paint one LED per row. The HT16K33 internal memory looks like
  // a 8x16 bit matrix (8 rows, 16 columns)
  for (uint8_t i=0; i<8; i++) {
// draw a diagonal row of pixels

    matrix.displaybuffer[i] = _BV((counter+i) % 16) | _BV((counter+i+8) % 16)  ;
  }
  // write the changes we just made to the display
  matrix.writeDisplay();
  delay(100);
 counter++;
  if (counter >= 16) counter = 0;
}
```

**Remarque :** avant de compiler le code, pensez à placer le dossier de la bibliothèque Matrix dans le répertoire \\Arduino\\libraries. Sinon, la compilation échouera.

Par exemple : **C:\\Program Files\\Arduino\\libraries**

## Résultat du test

Une fois le code téléversé sur la carte et l'alimentation mise sous tension, vous devriez voir la matrice 8\*8 afficher une image de cœur. Comme illustré ci-dessous.

![Illustration du résultat du test](../media/4a53bb681a3299be450726255f4d56a2.jpeg)

## Méthode de configuration

1. Définissez l'adresse de communication. Reportez-vous au tableau d'adresses.

Le code est configuré comme ci-dessous.

![Illustration de la méthode de configuration](../media/187557b09de67c1236bfd6536b0b95ee.png)

![Illustration de la méthode de configuration](../media/910472d4662d0c1f463f9bedfe4cef74.png)

![Illustration de la méthode de configuration](../media/165615f73e4c9a49c861f5e17eb333e3.png)

1. Définissez l'image d'affichage

Vous pouvez définir l'image d'affichage dans le code montré ci-dessous.

![Illustration de la méthode de configuration](../media/4a709cb4583c82f469c179dd6b1cfa71.png)

Placez le module de matrice comme suit :

![Illustration de la méthode de configuration](../media/10e87958bbef207075643ae4f5481457.jpeg)

Ensuite convertissez 0x00,0x18,0x24,0x42,0x81,0x99,0x66,0x00 en nombres binaires :

- `0x00` correspond à `0 0 0 0 0 0 0 0`.

- `0x18` correspond à `0 0 0 1 1 0 0 0`.

- `0x24` correspond à `0 0 1 0 0 1 0 0`.

- `0x42` correspond à `0 1 0 0 0 0 1 0`.

- `0x81` correspond à `1 0 0 0 0 0 0 1`.

- `0x99` correspond à `1 0 0 1 1 0 0 1`.

- `0x66` correspond à `0 1 1 0 0 1 1 0`.

- `0x00` correspond à `0 0 0 0 0 0 0 0`.

Le premier nombre hexadécimal contrôle la première colonne de LED.

La seconde valeur contrôle la deuxième colonne, et ainsi de suite.

Ces réglages convertissent chaque valeur hexadécimale sur 8 bits en sa représentation binaire.

Le chiffre 0 signifie LED éteinte, et le chiffre 1 signifie LED allumée.

Le premier nombre converti contrôle l'allumage et l'extinction de la première rangée de LED, et ainsi de suite.

![Illustration de la méthode de configuration](../media/3ba4bb34ddf3ef182c5aa5bc7a309605.png)

---
