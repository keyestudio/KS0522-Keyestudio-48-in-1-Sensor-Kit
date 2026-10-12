# Leçon 10 : Évitement d'obstacles infrarouges

> **Kit :** Keyestudio Kit de capteurs 48 en 1  
> **Carte :** Keyestudio V4.0 / carte compatible Arduino Uno ATmega328P

![Illustration du projet 10 : Évitement d'obstacles infrarouges](../media/54ab9db703340471fd9c3151934b85e7.png)

## Description

Le capteur détecteur d'obstacles infrarouge est équipé d'une fonction de réglage de la distance et est spécialement conçu pour les robots à roues.

Ce capteur présente une forte adaptabilité à la lumière ambiante et une grande précision.

Il possède une paire d'émetteur et de récepteur infrarouges. Lorsque le rayon infrarouge émis par le tube émetteur rencontre un obstacle (son réflecteur), le rayon infrarouge est réfléchi vers le tube récepteur, ainsi l'indicateur s'allume et l'interface de sortie de signal fournit un signal numérique.

De plus, vous pouvez tourner le bouton du potentiomètre pour ajuster la distance de détection (distance effective : 2～40cm, tension de fonctionnement : 3.3V-5V).

Grâce à une large plage de tension, ce capteur peut fonctionner de manière stable même en cas de fluctuation de la tension d'alimentation, et convient à divers microcontrôleurs, contrôleurs Arduino et contrôleurs BS2.

Un robot équipé de ce capteur peut détecter les obstacles dans son environnement.

## Spécifications

- Tension de fonctionnement : DC 3.3V-5V

- Courant de fonctionnement : ≥20mA

- Température de fonctionnement : －10℃ à ＋50℃

- Distance de détection : 2-40cm

- Interface IO : 4 interfaces filaires (-/+/S/EN)

- Signal de sortie : tension TTL

- Mode de réglage : potentiomètre multi-tours

- Angle effectif : 35°

## Schéma de connexion

Tout d'abord, vous devez préparer les pièces suivantes avant la connexion :

- Carte V4.0\*1

- Module détecteur d'obstacles \*1

- Câble USB\*1

- Fils de liaison\*3

Connectez la broche Out du module à Digital 2 de la carte V4.0, connectez la broche V+ au port 5V, la broche GND au port GND.

![Illustration du schéma de connexion](../media/48f60a482d777df19bc43a3203479b0c.jpeg)

## Exemple de code

Copiez et collez le code ci-dessous dans le logiciel Arduino.

```c
const uint8_t sensorPin = 2;
const uint8_t ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop() {
  const int sensorState = digitalRead(sensorPin);
  digitalWrite(ledPin, sensorState == HIGH ? HIGH : LOW);
}
```

## Résultat

Une fois le code téléversé sur la carte, vous pouvez voir la LED sur la carte V4.0 et sur le capteur de détection d'obstacles s'allumer.

![Illustration du résultat](../media/44d035dfe09b4c803becd84c95b05956.png)

Si l'on place un bloc de mousse devant le capteur, lorsque le capteur détecte l'obstacle, la LED du capteur s'allume.

![Illustration du résultat](../media/da4468fead816d42b2ac43b29716b91f.png)

---
