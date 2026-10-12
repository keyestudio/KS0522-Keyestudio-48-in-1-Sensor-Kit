# Leçon 40 : Affichage de la température et de l'humidité

> **Kit :** Keyestudio kit de capteurs 48-en-1  
> **Carte :** Keyestudio V4.0 / carte compatible Arduino Uno (ATmega328P)

![Projet 40 : Illustration de l'affichage de la température et de l'humidité](../media/e164737761b08de30da9358b47511d62.png)

## Introduction

Ce capteur DHT11 fournit une sortie de signal numérique calibrée avec un capteur combiné de température et d'humidité. Sa technologie assure une grande fiabilité et une excellente stabilité à long terme.

Un microcontrôleur 8 bits haute performance est intégré au capteur. Ce capteur comprend un élément résistif et des dispositifs de mesure de température NTC sensibles à l'humidité.

Il présente des avantages de grande qualité, de réponse rapide, de capacité anti-interférence et d'un bon rapport qualité-prix.

Chaque capteur DHT11 possède des données d'étalonnage extrêmement précises issues d'une chambre d'étalonnage d'humidité. Les coefficients d'étalonnage sont stockés dans la mémoire programme OTP ; les capteurs internes détectent les signaux pendant le processus, et il faut appliquer ces coefficients d'étalonnage.

L'interface série un fil est intégrée pour rendre la communication rapide et simple. Les caractéristiques de petite taille, de faible consommation et une distance de transmission de signal de 20 mètres le rendent largement applicable, même pour les usages les plus exigeants.

## Spécifications

- Tension d'alimentation : +5 V

- Plage de température : 0-50 °C, erreur de ± 2 °C

- Humidité : 20-90 % RH, erreur de ± 5 % RH

- Interface : Numérique

## Schéma de connexion

Préparez d'abord les éléments suivants avant le test.

- Carte V4.0\*1

- Capteur DHT11\*1

- Câble USB\*1

- Fils de connexion\*3

Ensuite, suivez le schéma de câblage : connectez la broche Signal du capteur au port Digital 4 de la carte V4.0, la broche négative au port GND et la broche positive au port 5V.

![Illustration du schéma de connexion](../media/d10a0556ea9e4a8314ee21f8f58ff236.jpeg)

## Exemple de code

Veuillez d'abord télécharger la [bibliothèque DHT11Lib](https://github.com/RobTillaart/Arduino/tree/master/libraries/DHTlib). Vous pouvez également [consulter le site Web](http://playground.arduino.cc/Main/DHTLib).

Copiez et collez le code ci‑dessous dans le logiciel Arduino.

```c
#include <dht.h>

dht DHT;
#define DHT11_PIN 4

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT11 test"));
  Serial.print(F("DHTlib version: "));
  Serial.println(DHT_LIB_VERSION);
  Serial.println(F("Status,Humidity (%),Temperature (C)"));
}

void loop() {
  const int status = DHT.read11(DHT11_PIN);

  switch (status) {
    case DHTLIB_OK:
      Serial.print(F("OK, "));
      break;
    case DHTLIB_ERROR_CHECKSUM:
      Serial.print(F("Checksum error, "));
      break;
    case DHTLIB_ERROR_TIMEOUT:
      Serial.print(F("Timeout error, "));
      break;
    default:
      Serial.print(F("Unknown error, "));
      break;
  }

  Serial.print(DHT.humidity, 1);
  Serial.print(F(", "));
  Serial.println(DHT.temperature, 1);
  delay(2000);
}
```

## Résultat d'exemple

Branchez correctement le montage et téléversez le code ci‑dessus sur la carte V4.0.

![Illustration du résultat d'exemple](../media/cdbb75de748e3e2eb6f709b8f469193d.png)

Ensuite, ouvrez le moniteur série et réglez le débit sur 9600 ; vous verrez alors les valeurs de température et d'humidité actuelles.

![Illustration du résultat d'exemple](../media/dffe8c9a0b348f7f4f12cbfe95c090f3.jpeg)

---
