# Leçon 35 : Moniteur de fréquence cardiaque

> **Kit :** Kit de capteurs Keyestudio 48-en-1  
> **Carte :** Keyestudio V4.0 / carte compatible Arduino Uno ATmega328P

![Illustration du projet 35 : moniteur de fréquence cardiaque](../media/0ec440cd93e00e956357ece654ce2a9c.png)

## Description

Ce module utilise une LED infrarouge ultra-claire et un phototransistor pour détecter le pouls dans votre doigt. La LED rouge clignotera en rythme avec votre pouls.

Principe de fonctionnement

Faites briller la LED brillante sur un côté de votre doigt pendant que le phototransistor, de l'autre côté, capte la quantité de lumière transmise. La résistance du phototransistor variera légèrement à mesure que le sang pulse dans votre doigt.

## Schéma de connexion

Tout d'abord, préparez les pièces suivantes avant d'effectuer un test.

- Carte V4.0\*1

- Module de pouls\*1

- Câble USB\*1

- Fils de connexion\*3

Reliez la broche Signal du module à l'entrée analogique A0 de la carte V4.0, la broche positive au port 5V et la broche négative au port GND.

![Illustration du schéma de connexion](../media/fa86e3930b83753af7ad87d0418cd350.jpeg)

## Code d'exemple

Copiez et collez le code ci‑dessous dans le logiciel Arduino.

```c
///////////////////////////////////////////////////////////////
int ledPin = 13;
int sensorPin = 0;
double alpha = 0.75;
int period = 20;
double change = 0.0;
void setup()
{
pinMode(ledPin, OUTPUT);
Serial.begin(115200);
}
void loop()
{
static double oldValue = 0;
static double oldChange = 0;
int rawValue = analogRead(sensorPin);
double value = alpha * oldValue + (1 - alpha) * rawValue;
Serial.print(rawValue);
Serial.print(",");
Serial.println(value);
oldValue = value;
delay(period);
}
///////////////////////////////////////////////////////////////
```

## Exemple de résultat

Câblez correctement comme indiqué sur le schéma ci‑dessus, puis téléversez le code sur la carte et cliquez sur l'icône du moniteur série en haut à droite du logiciel Arduino. Réglez le débit en bauds sur 115200 ; vous verrez les données s'afficher dans le moniteur.

Vous pouvez copier-coller les données dans Excel ; cela générera finalement l'image correspondante montrée ci‑dessous.

![Illustration du résultat](../media/3c3a1a0d120f1c68c95095a0fd98fa47.png)

![Illustration du résultat](../media/215ab9a6174f9798a291bacb907eaf89.jpeg)

---
