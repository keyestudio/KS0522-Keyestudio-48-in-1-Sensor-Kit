# Leçon 44 : Détection d'accélération numérique triaxiale

> **Kit :** Keyestudio 48-in-1 Sensor Kit  
> **Carte :** Keyestudio V4.0 / carte compatible Arduino Uno ATmega328P

![Illustration du projet 44 : Détection d'accélération numérique triaxiale](../media/2a26949601eb888348b798711fe1151e.jpeg)

## Introduction

Le MMA8452Q est un capteur d'accélération capacitif micromécanique (MEMS) intelligent et basse consommation, à trois axes, avec une résolution de 12 bits.

Ce capteur d'accélération dispose de nombreuses fonctions embarquées, avec des options configurables par l'utilisateur et une configuration à deux broches d'interruption.

La fonction d'interruption intégrée peut réduire la consommation globale d'énergie et éviter la charge d'interroger en permanence les données par le processeur principal.

De plus, le MMA8452Q propose une plage optionnelle de ±2g / ±4g / ±8g, et peut fournir en temps réel des données filtrées en passe-haut et des données non filtrées.

Cet appareil peut être configuré pour générer une interruption de réveil inertielle, ce qui permet au MMA8452Q de rester en mode basse consommation à l'état statique tout en surveillant les événements.

## Paramètres de performance

- Tension d'alimentation : 1.95 V à 3.6 V

- Tension d'interface : 1.6 V à 3.6 V

- Plage dynamique optionnelle : ±2g / ±4g / ±8g

- Plage de fréquence de sortie des données (ODR) : 1.56 Hz à 800 Hz

- Bruit : 99 μg/√Hz

- Sorties numériques 12 bits et 8 bits ;

- Interface de sortie numérique I2C (jusqu'à 2.25 MHz lorsque la résistance de pull-up est de 4.7 kΩ) ;

- Deux broches d'interruption programmables appliquées à six sources d'interruption ;

- Trois canaux intégrés de détection de mouvement : détection de chute libre, détection d'impulsion, détection de secousse ;

- Détection de direction (transversale/longitudinale) avec compensation de décalage configurable ;

- Réveil automatique et ODR en veille automatique pouvant être modifiés automatiquement ;

- Les données filtrées passe-haut peuvent être exportées en temps réel ;

- Consommation : 6 μA – 165 μA

## Diagramme de connexion

Tout d'abord, vous devez préparer les pièces suivantes :

- Carte V4.0*1

- Capteur MMA8452Q*1

- Câble USB*1

- Fils de connexion*4

Connectez la broche SCL au port Analog A5, la broche SDA au port Analog A4 ; connectez la broche positive au port 3V3, la broche négative au port GND.

![Illustration du diagramme de connexion](../media/fdd68f7da45d46e65f42918eac68a2f3.jpeg)

## Exemple de code

Copiez-collez le code ci-dessous dans le logiciel Arduino.

```c
#include <Wire.h> // Must include Wire library for I2C
#include <SparkFun_MMA8452Q.h> // Includes the SFE_MMA8452Q library
// Begin using the library by creating an instance of the MMA8452Q
//  class. We'll call it "accel". That's what we'll reference from
//  here on out.
MMA8452Q accel;
// The setup function simply starts serial and initializes the
//  accelerometer.
void setup()
{
  Serial.begin(9600);
  Serial.println("MMA8452Q Test Code!");

  // Choose your adventure! There are a few options when it comes
  // to initializing the MMA8452Q:
  //  1. Default init. This will set the accelerometer up
  //     with a full-scale range of +/-2g, and an output data rate
  //     of 800 Hz (fastest).
  accel.init();
  //  2. Initialize with FULL-SCALE setting. You can set the scale
  //     using either SCALE_2G, SCALE_4G, or SCALE_8G as the value.
  //     That'll set the scale to +/-2g, 4g, or 8g respectively.
  //accel.init(SCALE_4G); // Uncomment this out if you'd like
  //  3. Initialize with FULL-SCALE and DATA RATE setting. If you
  //     want control over how fast your accelerometer produces
  //     data use one of the following options in the second param:
  //     ODR_800, ODR_400, ODR_200, ODR_100, ODR_50, ODR_12,
  //     ODR_6, or ODR_1.
  //     Sets to 800, 400, 200, 100, 50, 12.5, 6.25, or 1.56 Hz.
  //accel.init(SCALE_8G, ODR_6);
}

// The loop function will simply check for new data from the
//  accelerometer and print it out if it's available.
void loop()
{
  // Use the accel.available() function to wait for new data
  //  from the accelerometer.
  if (accel.available())
  {
    // First, use accel.read() to read the new variables:
    accel.read();

    // accel.read() will update two sets of variables.
    // * int's x, y, and z will store the signed 12-bit values
    //   read out of the accelerometer.
    // * floats cx, cy, and cz will store the calculated
    //   acceleration from those 12-bit values. These variables
    //   are in units of g's.
    // Check the two function declarations below for an example
    // of how to use these variables.
    printCalculatedAccels();
    //printAccels(); // Uncomment to print digital readings

    // The library also supports the portrait/landscape detection
    //  of the MMA8452Q. Check out this function declaration for
    //  an example of how to use that.
    printOrientation();

    Serial.println(); // Print new line every time.
  }
}

// The function demonstrates how to use the accel.x, accel.y and
//  accel.z variables.
// Before using these variables you must call the accel.read()
//  function!
void printAccels()
{
  Serial.print(accel.x, 3);
  Serial.print("\t");
  Serial.print(accel.y, 3);
  Serial.print("\t");
  Serial.print(accel.z, 3);
  Serial.print("\t");
}

// This function demonstrates how to use the accel.cx, accel.cy,
//  and accel.cz variables.
// Before using these variables you must call the accel.read()
//  function!
void printCalculatedAccels()
{
  Serial.print(accel.cx, 3);
  Serial.print("\t");
  Serial.print(accel.cy, 3);
  Serial.print("\t");
  Serial.print(accel.cz, 3);
  Serial.print("\t");
}

// This function demonstrates how to use the accel.readPL()
// function, which reads the portrait/landscape status of the
// sensor.
void printOrientation()
{
  // accel.readPL() will return a byte containing information
  // about the orientation of the sensor. It will be either
  // PORTRAIT_U, PORTRAIT_D, LANDSCAPE_R, LANDSCAPE_L, or
  // LOCKOUT.
  byte pl = accel.readPL();
  switch (pl)
  {
  case PORTRAIT_U:
    Serial.print("Portrait Up");
    break;
  case PORTRAIT_D:
    Serial.print("Portrait Down");
    break;
  case LANDSCAPE_R:
    Serial.print("Landscape Right");
    break;
  case LANDSCAPE_L:
    Serial.print("Landscape Left");
    break;
  case LOCKOUT:
    Serial.print("Flat");
    break;
  }
}
```

Remarque : avant de compiler le code, pensez à placer la bibliothèque dans le répertoire libraries de l'IDE Arduino. Sinon, la compilation échouera.

## Exemple de résultat

![Illustration de l'exemple de résultat](../media/9f81d233c0387bc32d25951abd3a407c.png)

Après avoir téléversé le code et ouvert le moniteur série, il affichera l'accélération triaxiale du capteur et son état comme indiqué ci-dessous.

![Illustration de l'exemple de résultat](../media/03421d279e2e961d7b40f645b7576d73.jpeg)

---
