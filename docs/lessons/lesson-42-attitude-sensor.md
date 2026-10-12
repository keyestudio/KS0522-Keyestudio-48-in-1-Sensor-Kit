# Leçon 42 : Capteur d'attitude

> **Kit :** Keyestudio 48-in-1 Sensor Kit  
> **Carte :** Keyestudio V4.0 / carte compatible Arduino Uno ATmega328P

![Illustration du projet 42 : Capteur d'attitude](../media/8eb8d16c5e76e50a6609678130a9ee29.jpeg)

## Introduction

**Avis de compatibilité.** La liste de composants indique cette carte comme APDS-9930, mais l'exemple historique suivant cible un APDS-9960 et utilise `SparkFun_APDS9960`. Vérifiez le marquage du circuit intégré sur le module réel avant d'uploader ce sketch ; n'utilisez pas cet exemple avec une carte APDS-9930. L'APDS-9930 en boîtier 8 broches unique peut fournir le capteur de lumière ambiante compatible avec l'interface I2C et le capteur de proximité par LED infrarouge.

Le capteur de proximité, complètement réglé, peut détecter un objet à 100 mm, et dispense des exigences d'étalonnage en usine pour l'équipement terminal ainsi que les sous-composants.

Du plein soleil à la pièce sombre, la fonction de détection de proximité du capteur peut fonctionner correctement.

Ce module intègre une micro-lentille optique qui permet une transmission et une réception infrarouges efficaces, ce qui peut réduire la consommation d'énergie globale.

De plus, sa machine d'état interne peut mettre l'appareil en mode basse consommation, offrant une consommation moyenne très faible.

## Paramètres

- Tension de fonctionnement：DC 3.3-3.8V

- Courant de sortie：0-20mA

- Plage de température：-40℃—85℃

## Caractéristiques

1. Module optique intégré avec ALS, LED infrarouge et détecteur de proximité ;

2. Jusqu'à 16 bits de résolution ;

3. Haute sensibilité de fonctionnement derrière du verre foncé ;

4. Performance basse lumière de 0.01 lux ;

5. Détection de proximité, entièrement calibrée jusqu'à 100 mm ;

6. Intègre la LED infrarouge et le pilote LED synchrone ;

7. Élimine l'étalonnage en usine pour les capteurs de proximité ;

8. Minuterie d'attente programmable, consommation en état d'attente - 90μA (valeur typique) ;

9. Plage programmable de 2.7 millisecondes à 8 secondes ;

10. Compatible avec l'interface I2C, jusqu'à 400kHz (mode rapide I2C) ;

11. Broche d'interruption dédiée ;

12. Consommation en mode veille - 2.2μA (valeur typique).

## Schéma de connexion

Tout d'abord, vous devez préparer les pièces suivantes :

- Carte V4.0\*1

- Capteur d'attitude\*1

- Câble USB\*1

- Fils de connexion\*5

Connectez la broche INT du capteur au port Digital 2 de la carte V4.0, la broche SCL au port Analog A5, la broche SDA au port Analog A4 ; Connectez la broche 3V3 au port 3V3, la broche GND au port GND.

![Illustration du schéma de connexion](../media/c906c4e8a06998118eac5e3b981386d6.jpeg)

## Exemple de code

**IMPORTANT** : L'APDS-9960 n'accepte que 3.3V !

## Connexions matérielles

| Broche Arduino | Carte APDS-9960 | Fonction       |
| :------------: | :-------------: | :-------------: |
|     3.3V       |       VCC       | Alimentation   |
|      GND       |       GND       | Masse          |
|      A4        |       SDA       | Données I2C    |
|      A5        |       SCL       | Horloge I2C    |
|      D2        |       INT       | Interruption   |
|      D13       |        -        | LED            |

**Ressources :** Inclure Wire.h et SparkFun_APDS-9960.h

**Détails de l'environnement de développement :** Écrit pour Arduino 1.0.5

Copiez-collez le code ci-dessous dans le logiciel Arduino.

```c
#include <Wire.h>
#include <SparkFun_APDS9960.h>

// Pins
#define APDS9960_INT    2  // Needs to be an interrupt pin
#define LED_PIN         13 // LED for showing interrupt

// Constants
#define LIGHT_INT_HIGH  1000 // High light level for interrupt
#define LIGHT_INT_LOW   10   // Low light level for interrupt

// Global variables
SparkFun_APDS9960 apds = SparkFun_APDS9960();
uint16_t ambient_light = 0;
uint16_t red_light = 0;
uint16_t green_light = 0;
uint16_t blue_light = 0;
int isr_flag = 0;
uint16_t threshold = 0;

void setup() {
  // Set LED as output
  pinMode(LED_PIN, OUTPUT);
  pinMode(APDS9960_INT, INPUT);
  // Initialize Serial port
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("-------------------------------------"));
  Serial.println(F("SparkFun APDS-9960 - Light Interrupts"));
  Serial.println(F("-------------------------------------"));
  // Initialize interrupt service routine
  attachInterrupt(0, interruptRoutine, FALLING);
  // Initialize APDS-9960 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("APDS-9960 initialization complete"));
  } else {
    Serial.println(F("Something went wrong during APDS-9960 init!"));
  }
  // Set high and low interrupt thresholds
  if ( !apds.setLightIntLowThreshold(LIGHT_INT_LOW) ) {
    Serial.println(F("Error writing low threshold"));
  }
  if ( !apds.setLightIntHighThreshold(LIGHT_INT_HIGH) ) {
    Serial.println(F("Error writing high threshold"));
  }
  // Start running the APDS-9960 light sensor (no interrupts)
  if ( apds.enableLightSensor(false) ) {
    Serial.println(F("Light sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during light sensor init!"));
  }
  // Read high and low interrupt thresholds
  if ( !apds.getLightIntLowThreshold(threshold) ) {
    Serial.println(F("Error reading low threshold"));
  } else {
    Serial.print(F("Low Threshold: "));
    Serial.println(threshold);
  }
  if ( !apds.getLightIntHighThreshold(threshold) ) {
    Serial.println(F("Error reading high threshold"));
  } else {
    Serial.print(F("High Threshold: "));
    Serial.println(threshold);
  }
  // Enable interrupts
  if ( !apds.setAmbientLightIntEnable(1) ) {
    Serial.println(F("Error enabling interrupts"));
  }
  // Wait for initialization and calibration to finish
  delay(500);
}
void loop() {
  // If interrupt occurs, print out the light levels
  if ( isr_flag == 1 ) {

    // Read the light levels (ambient, red, green, blue) and print
    if (  !apds.readAmbientLight(ambient_light) ||
          !apds.readRedLight(red_light) ||
          !apds.readGreenLight(green_light) ||
          !apds.readBlueLight(blue_light) ) {
      Serial.println("Error reading light values");
    } else {
      Serial.print("Interrupt! Ambient: ");
      Serial.print(ambient_light);
      Serial.print(" R: ");
      Serial.print(red_light);
      Serial.print(" G: ");
      Serial.print(green_light);
      Serial.print(" B: ");
      Serial.println(blue_light);
    }
    // Turn on LED for a half a second
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);

    // Reset flag and clear APDS-9960 interrupt (IMPORTANT!)
    isr_flag = 0;
    if ( !apds.clearAmbientLightInt() ) {
      Serial.println("Error clearing interrupt");
    }
  }
}
void interruptRoutine() {
  isr_flag = 1;
}
```

Remarque : avant de compiler le code, pensez à placer la bibliothèque dans le répertoire libraries de l'IDE Arduino. Sinon, la compilation échouera.

## Résultat d'exemple

![Illustration du résultat d'exemple](../media/2a30729fa77874e4e61f51d2bb8e62c1.png)

Après avoir téléversé le code, ouvrez le moniteur série et réglez le débit en bauds sur 9600.

![Illustration du résultat d'exemple](../media/935c7035ef43f54ca65eaa49bbaf5e98.jpeg)

---
