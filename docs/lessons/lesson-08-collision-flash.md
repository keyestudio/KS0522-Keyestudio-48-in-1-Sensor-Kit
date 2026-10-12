# Leçon 08 : Clignotement de collision

> **Kit :** Keyestudio 48-in-1 Sensor Kit  
> **Carte :** Keyestudio V4.0 / carte compatible Arduino Uno ATmega328P

![Illustration du projet 8 : Clignotement de collision](../media/29c4641406064a4f1df5d59aefbca480.png)

## Description

Le capteur de collision, également appelé interrupteur électronique, est un module d'entrée numérique on/off indispensable pour l'apprentissage élémentaire de l'électronique.

Grâce à la programmation, il permet de contrôler des voyants, des dispositifs sonores, la fonction de sélection de touches d'un afficheur LCD, etc.

En utilisant un câble capteur 3P pour le connecter au shield de capteurs, il peut être installé sur la plateforme robot mobile 4WD AL en alliage pour réaliser la fonction de détection de collision. C'est à la fois pratique et efficace.

Vous pouvez réaliser un clignoteur de collision en utilisant le module de collision et la LED intégrée à l'interface 13. Connectez le capteur de collision à la broche 3. Lorsque le capteur détecte un signal de collision, les LEDs de la carte principale et du module s'allument simultanément.

## Paramètres

1. Si une collision se produit en face de l'endroit où le module de collision est installé, le module délivre un signal de niveau bas ; en l'absence de collision, il délivre un signal de niveau haut.

2. Le module dispose d'un trou de fixation M3, pratique pour la fixation sur un véhicule.

3. Avec une LED indicatrice d'interrupteur : en cas de collision, la LED est allumée ; sans collision, elle est éteinte.

## Définition des broches

1. Broche positive (+) : connecter à une alimentation 3v-12v

2. Broche négative (-) : connecter à GND

3. Broche signal (S) : sortie de niveau haut/bas

## Schéma de connexion

Avant de connecter, vous devez préparer les pièces suivantes :

- Carte V4.0\*1

- Module de collision \*1

- Câble USB\*1

- Fils de connexion\*3

Connectez la broche S du module au Digital 3 de la carte V4.0, connectez la broche négative au port GND et la broche positive au port 5V.

![Illustration du schéma de connexion](../media/a4ec0b7f8fd95fb2d6bb5c06ca0776f0.jpeg)

## Code d'exemple

Copiez et collez le code ci-dessous dans le logiciel Arduino.

```c
const uint8_t ledPin = 13;
const uint8_t collisionPin = 3;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(collisionPin, INPUT);
}

void loop() {
  const int state = digitalRead(collisionPin);
  digitalWrite(ledPin, state == HIGH ? LOW : HIGH);
}
```

## Résultat de l'exemple

Branchez correctement les fils puis téléversez le code sur la carte.

Lorsque l'objet heurte l'interrupteur du capteur, la LED sur le capteur et la LED 13 de la carte s'allument.

---
