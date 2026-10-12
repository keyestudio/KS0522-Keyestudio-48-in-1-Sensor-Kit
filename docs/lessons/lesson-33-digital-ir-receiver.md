# Leçon 33 : Récepteur IR numérique

> **Kit :** Keyestudio Kit de capteurs 48-en-1  
> **Carte :** Keyestudio V4.0 / Carte compatible Arduino Uno ATmega328P

![Illustration du projet 33 : Récepteur IR numérique](../media/f64f21b6ca681f928c3318bd2d33a017.png)

## Description

L'IR est largement utilisé dans les télécommandes. Avec ce récepteur IR, un projet Arduino peut recevoir des commandes de n'importe quelle télécommande IR si vous disposez du bon décodeur. Il est également facile de créer votre propre télécommande IR en utilisant un émetteur IR.

## Spécifications

- Alimentation : 5V

- Interface : Numérique

- Fréquence de modulation : 38 kHz

- Connecteur du module : JST PH2.0

- Taille : 30*20 mm

- Poids : 4 g

## Schéma de connexion

Tout d'abord, vous devez préparer les pièces suivantes avant le branchement.

- Carte V4.0\*1

- Module récepteur IR\*1

- Câble USB\*1

- Fil de liaison\*3

Connectez la broche S du module au Digital 11 de la carte V4.0, la broche négative au GND, la broche positive au port 5V.

![Illustration du schéma de connexion](../media/687d429fe6360707f95fb6c5ddfa2ca7.jpeg)

Dans le code d'exemple ci‑dessous, la broche numérique 11 est utilisée ; vous pouvez soit modifier votre câblage, soit adapter le code d'exemple pour correspondre.

## Exemple de code

Copiez et collez le code ci‑dessous dans le logiciel Arduino.

```c
///////////////////////////////////////////////////////////////
#include <IRremote.h>
 int RECV_PIN = 11;
 IRrecv irrecv(RECV_PIN);
 decode_results results;
 void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}
 void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
}

///////////////////////////////////////////////////////////////
```

**Remarque :** avant de compiler le code, n'oubliez pas de placer la bibliothèque dans le répertoire libraries de l'IDE Arduino. Sinon, la compilation échouera.

La bibliothèque IR Remote inclut quelques exemples pour l'envoi et la réception.

<https://github.com/shirriff/Arduino-IRremote>

## Exemple de résultat

![Illustration du résultat](../media/2692333113be48ffa11c27649d18dcb8.png)

Après avoir réalisé le câblage et téléversé le code, contrôlez le module récepteur IR avec une télécommande infrarouge : la LED D1 clignotera.

![Illustration du résultat](../media/4bb52e2957e3aaeace252021e7084c95.png)

---
