# Leçon 11 : Interrupteur optique

> **Kit :** Keyestudio Kit de capteurs 48-en-1  
> **Carte :** Keyestudio V4.0 / carte compatible Arduino Uno ATmega328P

![Projet 11 : Illustration de l'interrupteur optique](../media/8b0f7b3ba3e139eeaeba9bb7f86a946a.png)

## Description

La partie verticale de ce capteur est un émetteur infrarouge et, de l'autre côté, un détecteur infrarouge protégé. En émettant un faisceau de lumière infrarouge d'une extrémité à l'autre, le capteur peut détecter un objet lorsqu'il passe à travers le faisceau.

Il est utilisé pour de nombreuses applications, notamment des interrupteurs de fin de course optiques, la distribution de pastilles, la détection générale d'objets, etc.

## Spécification

- Tension d'alimentation : 3.3V à 5V

- Interface : Numérique

- Taille : 30*20mm

- Poids : 3g

## Schéma de connexion

Tout d'abord, vous devez préparer les pièces suivantes avant la connexion :

- Carte V4.0\*1

- Module d'interrupteur optique \*1

- Câble USB\*1

- Fils de connexion\*3

Connectez la broche S du module à Digital 3 de la carte V4.0, connectez la broche négative au port GND et la broche positive au port 5V.

![Illustration du schéma de connexion](../media/669fa42ef7fb576047d6849940a305ba.jpeg)

## Code d'exemple

Copiez et collez le code ci-dessous dans le logiciel Arduino.

```c
////////////////////////////////////////////////////////////////////
// photo interrupter module
int Led = 13 ;// define LED Interface
int buttonpin = 3; // define the photo interrupter sensor interface
int val ;// define numeric variables val
void setup ()
{
  pinMode (Led, OUTPUT) ;// define LED as output interface
  pinMode (buttonpin, INPUT) ;// define the photo interrupter sensor output interface
}
void loop ()
{
  val = digitalRead (buttonpin) ;// digital interface will be assigned a value of 3 to read val
  if (val == HIGH) // When the light sensor detects a signal is interrupted, LED flashes
  {
    digitalWrite (Led, HIGH);
  }
  else
  {
    digitalWrite (Led, LOW);
  }
}
////////////////////////////////////////////////////////////////////
```

## Résultat d'exemple

Une fois le code téléversé sur la carte, vous pouvez voir que la LED sur la carte V4.0 et celle sur le module sont allumées. Comme montré ci-dessous.

![Illustration du résultat d'exemple](../media/fa4d06ebf82ec572b7eccf6b706942cb.png)

Lorsque vous insérez un papier dans la rainure du module, le signal est interrompu et la led1 du module s'éteint.

![Illustration du résultat d'exemple](../media/3ecb941fafc71843148e0e19b6ceda57.png)

---
