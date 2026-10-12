# Leçon 34 : Émetteur IR numérique

> **Kit :** Keyestudio 48-in-1 Sensor Kit  
> **Carte :** Keyestudio V4.0 / carte compatible Arduino Uno (ATmega328P)

![Illustration du projet 34 : émetteur IR numérique](../media/9fe876a8c857650226cbe2f8a9bead59.png)

## Description

Le module émetteur IR est conçu pour la communication infrarouge, largement utilisée pour piloter un téléviseur à courte distance en ligne de visée.

Comme la télécommande infrarouge (IR) utilise la lumière, elle nécessite une ligne de visée pour faire fonctionner l'appareil cible. Le signal peut cependant être réfléchi par des miroirs, comme toute autre source lumineuse.

Les récepteurs infrarouges ont également tendance à avoir un angle de réception plus ou moins limité, qui dépend principalement des caractéristiques optiques du phototransistor.

Toutefois, il est facile d'augmenter l'angle de réception en plaçant un objet transparent mat devant le récepteur.

## Spécification

- Alimentation : 3-5V

- Fréquence centrale infrarouge : 850nm-940nm

- Angle d'émission infrarouge : environ 20 degrés

- Portée d'émission infrarouge : environ 1,3 m (5V 38Khz)

- Connecteur : JST PH2.0

- Trou de montage : diamètre intérieur 3,2mm, entraxe 15mm

## Schéma de connexion

Avant la connexion, vous devez préparer les pièces suivantes.

- Carte V4.0\*1

- Module émetteur IR\*1

- Câble USB\*1

- Fils de connexion\*3

Connectez la broche S du module au Digital 3 de la carte V4.0, la broche négative au port GND, la broche positive au port 5V.

![Illustration du schéma de connexion](../media/31c03e9ad144e1124260ff6e0538fe69.jpeg)

## Exemple de code 1

```c
int led = 3;
void setup() {
   pinMode(led, OUTPUT);
}
void loop() {
  digitalWrite(led, HIGH);
  delay(1000);
  digitalWrite(led, LOW);
  delay(1000);
}
```

Dans l'obscurité, vous verrez une lumière bleue clignotante sur l'écran du téléphone si vous utilisez l'appareil photo pour filmer la LED infrarouge.

Téléversez correctement le code ci‑dessus sur la carte ; la LED du capteur clignotera en rouge.

Passons maintenant à un exemple interactif entre le module récepteur IR et le module émetteur IR.

## Télécommande/communication infrarouge

## Matériel requis

- Arduino R3 x2

- Récepteur IR numérique x1

- Module émetteur IR x1

Remarque : cette expérience nécessite deux cartes microcontrôleurs. Une plaque d'essai (breadboard) ne remplace pas la deuxième carte car elle ne peut pas exécuter le sketch du récepteur.

## Configuration de communication à deux cartes

## Pour l'émetteur IR

Remarque : Arduino-IR remote ne prend en charge que D3 comme émetteur.

![Illustration pour l'émetteur IR](../media/08ebf9b37949caf1782e499f49934f1d.png)

## Pour le récepteur IR

Connectez la broche signal au port D11.

![Illustration pour le récepteur IR](../media/687d429fe6360707f95fb6c5ddfa2ca7.jpeg)

## Téléversez le code 2 sur la V4.0 connectée à l'émetteur IR

```c
 #include <IRremote.h>
  IRsend irsend;
 void setup()
 {}
 void loop() {
  irsend.sendRC5(0x0, 8); //send 0x0 code (8 bits)
     delay(200);
  irsend.sendRC5(0x1, 8);
     delay(200); }
```

## Téléversez le code 3 sur la V4.0 connectée au récepteur IR

```c
#include <IRremote.h>
 const int RECV_PIN = 11;
 const int LED_PIN = 13;
 IRrecv irrecv(RECV_PIN);
 decode_results results;
 void setup()
 {Serial.begin(9600);
   irrecv.enableIRIn(); // Start the receiver
 }
  void loop()
 {if (irrecv.decode(&results))
   { if ( results.bits > 0 )
     {

       int state;
       if ( 0x1 == results.value )
       {
         state = HIGH;
       }
       else
       {
         state = LOW;
       }
       digitalWrite(LED_PIN, state);
     }
  irrecv.resume();        // prepare to receive the next value
   }}
```

## Résultat

Lorsque le module récepteur IR reçoit le signal infrarouge de l'émetteur IR, la LED D1 du module récepteur IR clignotera.

Lorsque le module récepteur IR reçoit le signal infrarouge de l'émetteur IR, la LED D1 du module récepteur IR clignotera.

![Illustration du résultat](../media/4d73a7178e89de72df7e82a147778ae9.png)

---
