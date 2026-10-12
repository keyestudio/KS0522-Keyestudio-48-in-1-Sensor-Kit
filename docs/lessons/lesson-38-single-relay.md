# Leçon 38 : Relais simple

> **Kit :** Kit de capteurs Keyestudio 48-en-1  
> **Carte :** Carte Keyestudio V4.0 / compatible Arduino Uno ATmega328P

![Illustration du projet 38 : relais simple](../media/e0b4485cfd4ccebd974d81f19239dde3.png)

## Introduction

Ce module relais simple peut être utilisé dans des projets interactifs. Ce module utilise un relais SONGLE 5v de haute qualité. Il peut également être utilisé pour contrôler l'éclairage, des appareils électriques et autres équipements.

La conception modulaire facilite l'utilisation avec la carte Arduino. Il peut être commandé via un port E/S numérique et permet de contrôler des électrovannes, lampes, moteurs et autres appareils à fort courant ou haute tension.

## Spécifications

- Type : Numérique

- Courant nominal : 10A (NO) 5A (NC)

- Tension maximale de commutation : 150VAC 24VDC

- Interface numérique

- Signal de commande : niveau TTL

- Charge nominale : 8A 150VAC (NO), 10A 24VDC (NO), 5A 250VAC (NO/NC), 5A 24VDC (NO/NC)

- Puissance maximale de commutation : AC1200VA DC240W (NO), AC625VA DC120W (NC)

- Temps d'action des contacts : 10ms

## Schéma de connexion

Tout d'abord, vous devez préparer les pièces suivantes avant le branchement.

- Carte V4.0\*1

- Module relais\*1

- Module LED \*1

- Plaque d'essai \*1

- Câble USB\*1

- Fils de connexion\*9

Ici, nous utilisons le module relais simple pour commander l'allumage ou l'extinction d'un module LED.

Pour le module relais, connectez la broche Signal au port numérique 8 de la carte V4.0, puis connectez sa broche positive à la rangée d'anode de la breadboard, reliez cette rangée au port 5V de la carte V4.0. Connectez sa broche négative à la rangée de cathode de la breadboard, reliez cette rangée au port GND de la carte V4.0.

Pour le module LED, connectez sa broche Signal à un des borniers du module relais, l'autre bornier du relais est connecté au port numérique 13 de la carte V4.0. Connectez sa broche positive à la rangée d'anode, sa broche négative à la rangée de cathode de la breadboard.

![Illustration du schéma de connexion](../media/21cf9b1d5f0843230ee516a0a8be77e1.jpeg)

## Exemple de code

Copiez et collez le code ci-dessous dans le logiciel Arduino.

```c
///////////////////////////////////////////////////////////////
 int Relay = 8;
  void setup()
{
  pinMode(13, OUTPUT);         //Set Pin13 as output
  digitalWrite(13, HIGH);     //Set Pin13 High
  pinMode(Relay, OUTPUT);     //Set Pin3 as output
}
void loop()
{
          digitalWrite(Relay, HIGH);   //Turn off relay
          delay(2000);
          digitalWrite(Relay, LOW);    //Turn on relay
          delay(2000);
}
///////////////////////////////////////////////////////////////
```

## Résultat

![Illustration du résultat](../media/c751be64bd8acd8c6114598b89586cfa.png)

Ce module relais est actif au niveau HIGH.

Câblez correctement, alimentez, puis téléversez le code ci-dessus sur la carte ; vous verrez le relais s'enclencher（ON connecté, NC déconnecté）pendant deux secondes, puis se couper pendant deux secondes（NC fermé,ON déconnecté）, de façon répétée et cyclique.

Lorsque le relais est activé, la LED externe est allumée. Si le relais est désactivé, la LED externe est éteinte.

---
