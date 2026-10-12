# Leçon 32 : Lumière ultraviolette

> **Kit :** Kit Keyestudio 48-en-1 de capteurs  
> **Carte :** Keyestudio V4.0 / Carte compatible Arduino Uno ATmega328P

![Projet 32 : Illustration de la lumière ultraviolette](../media/15613ff0e8f059a9034e923ab5c2be24.jpeg)

## Description

Le capteur ultraviolet Keyestudio GUVA-S12SD sert à détecter la lumière ultraviolette. Le GUVA-S12SD est utilisé pour mesurer l'indice UV des dispositifs portables intelligents, tels que les montres, les smartphones et les appareils extérieurs dotés d'une détection de l'indice UV.

Il peut également être utilisé pour surveiller l'intensité de la lumière UV ou comme détecteur de flamme UV lors de la désinfection d'objets par lumière ultraviolette.

## Paramètres

- Taille : 15mm×30mm×0.7mm

- Tension d'alimentation : 2.5V～5V

- Signal de sortie : Signal analogique

- Plage de détection du spectre : 240-370nm

- Région active : 0.076mm2

- Responsivité : 0.14A/W

- Courant d'obscurité : 1nA

- Courant lumineux : 101\~125nA Lumière UVA, 1mW/cm2

## Schéma de connexion

Préparez d'abord les éléments suivants avant la connexion.

- Carte V4.0\*1

- Capteur ultraviolet GUVA-S12SD 3528 \*1

- Câble USB\*1

- Fils de connexion (jumpers)\*3

Connectez la broche S du module à l'entrée analogique A0 de la carte V4.0, la broche négative au port GND, la broche positive au port 3V3.

![Illustration du schéma de connexion](../media/092ebb11142cfe83507989a5b2de0526.jpeg)

## Code d'exemple

Copiez et collez le code ci-dessous dans le logiciel Arduino.

```c
///////////////////////////////////////////////////////////////
/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

 This example code is in the public domain.
 */

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
}
///////////////////////////////////////////////////////////////
```

## Résultat d'exemple

![Illustration du résultat d'exemple](../media/e81338e1f55ff6b55fbfe369f92b54da.png)

Branchez correctement, téléversez le code du programme, puis ouvrez le moniteur série : il affichera les données.

Si vous éclairez le capteur avec de la lumière UV, les données dans le moniteur série changent, comme montré sur l'image suivante.

![Illustration du résultat d'exemple](../media/3a7f2a608faa9c72aee76d2820f78845.png)

![Illustration du résultat d'exemple](../media/610d2325395cd3b44ce3c18e05595518.jpeg)

---
