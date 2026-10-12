# Leçon 19 : Température analogique

> **Kit :** Keyestudio 48-en-1 Kit de capteurs  
> **Carte :** Carte Keyestudio V4.0 / compatible Arduino Uno ATmega328P

![Projet 19 : Illustration Température analogique](../media/8269d6536e383bcc592da1ae98bc3661.png)

## Description

Ce module est basé sur le principe de fonctionnement d'une thermistance (la résistance varie en fonction des changements de température de l'environnement).

Il peut détecter les variations de température ambiante et envoyer les données à l'entrée analogique de la carte Arduino.

Il suffit de convertir la sortie du capteur en degrés Celsius par un simple programme, puis de l'afficher sur le moniteur.

Il est à la fois pratique et efficace, et est donc largement utilisé pour le jardinage, les systèmes d'alarme domestiques et d'autres appareils.

## Spécifications

- Type d'interface : analogique

- Tension de fonctionnement : 5V

- Plage de températures : -55℃～315℃

- Taille : 30\*20mm

- Poids : 3g

## Schéma de connexion

Tout d'abord, préparez les pièces suivantes avant le branchement :

- Carte V4.0\*1

- Capteur de température analogique\*1

- Câble USB\*1

- Fils de connexion\*3

Connectez la broche S du module à l'analogique A0 de la carte V4.0, la broche négative au port GND et la broche positive au port 5V.

![Illustration du schéma de connexion](../media/330d37f05ac235a850d06726284243a5.jpeg)

## Exemple de code

Copiez et collez le code ci‑dessous dans le logiciel Arduino.

```c
////////////////////////////////////////////////////////////////////
void setup()
{Serial.begin(9600);
}
// the loop routine runs over and over again forever:
void loop()
{int sensorValue = analogRead(A0);
Serial.println(sensorValue);
  delay(1); }
////////////////////////////////////////////////////////////////////
```

Le code ci‑dessus n'affiche que la valeur analogique.

Vous pouvez voir que la valeur analogique change selon la température ambiante. Mais ce n'est pas très explicite.

Résolvons cela en utilisant l'équation suivante. Ensuite téléversez le code ci‑dessous sur la carte Arduino. La valeur lue depuis le port série correspondra à une température en degrés Celsius réaliste, par exemple : la température actuelle est 30°C.

```c
////////////////////////////////////////////////////////////////////
#include <math.h>
void setup()
{
   Serial.begin(9600);
}
void loop()
{
  double val=analogRead(0);
  double fenya=(val/1023)*5;
  double r=(5-fenya)/fenya*4700;
  Serial.println( 1/(  log(r/10000) /3950 + 1/(25+273.15))-273.15);
  delay(1000);
}
////////////////////////////////////////////////////////////////////
```

## Exemple de résultat

![Illustration du résultat](../media/9ae4e8962bf9d46ceeb3ca0c2e560f43.png)

Après avoir câblé et alimenté comme sur la figure ci‑dessus, téléversez correctement le code sur la carte, puis ouvrez le moniteur série de l'IDE Arduino : vous verrez la valeur de la température actuelle.

![Illustration du résultat](../media/005b4c639460eba8158f99637f03686b.jpeg)

---
