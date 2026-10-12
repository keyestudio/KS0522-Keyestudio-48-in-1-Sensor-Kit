# Leçon 15 : Touche capacitive

> **Kit :** Keyestudio 48-en-1 Kit de capteurs  
> **Carte :** Keyestudio V4.0 / carte compatible Arduino Uno ATmega328P

![Illustration du projet 15 : Touche capacitive](../media/bceabc7d4302bd41ae380e179a281314.png)

## Description

Vous en avez assez de cliquer sur des boutons mécaniques ? Essayez notre capteur tactile capacitif. On trouve des capteurs tactiles principalement sur des appareils électroniques. Améliorez donc votre projet Arduino avec ce capteur pour le rendre plus moderne.

Ce petit capteur peut détecter le contact du corps et du métal en renvoyant un niveau de tension haut/bas. Même isolé par du tissu ou du papier, il peut encore détecter le contact. Mais sa sensibilité diminue lorsque la couche d'isolation devient plus épaisse.

Nous apporterons d'autres améliorations à ces modules capteurs pour vous offrir une meilleure expérience.

## Spécifications

- Tension d'alimentation: 3.3V à 5V

- Interface: Numérique

- Taille: 30*20mm

- Poids: 3g

## Schéma de connexion

Premièrement, vous devez préparer les composants suivants avant la connexion :

- Carte V4.0*1

- Capteur tactile capacitif*1

- Câble USB*1

- Fils de connexion*3

Connectez la broche S du module au Digital 2 de la carte V4.0, connectez la broche négative au port GND et la broche positive au port 5V.

![Illustration du schéma de connexion](../media/18193a53377b60f43fb583c29337f3aa.jpeg)

## Code d'exemple

Copiez et collez le code ci-dessous dans le logiciel Arduino.

```c
const uint8_t ledPin = 13;  // On-board LED.
const uint8_t touchPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(touchPin, INPUT);
}

void loop() {
  const int touched = digitalRead(touchPin);
  digitalWrite(ledPin, touched == HIGH ? HIGH : LOW);
}
```

## Exemple de résultat

Après avoir réalisé le câblage, alimenté le montage et téléversé correctement le code, touchez le capteur avec votre doigt : la LED D2 sur le capteur et l'indicateur D13 sur la carte V4.0 s'allument. Sinon, ces deux voyants sont éteints.

![Illustration du résultat](../media/31a751feed0f21236458b93eed14af9f.png)

---
