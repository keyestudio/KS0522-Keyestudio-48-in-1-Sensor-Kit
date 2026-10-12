# Les 34: Digitale IR-zender

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P bord

![Afbeelding Project 34: Digitale IR-zender](../media/9fe876a8c857650226cbe2f8a9bead59.png)

## Beschrijving

De IR-zendermodule is ontworpen voor IR-communicatie, die veel wordt gebruikt voor het bedienen van bijvoorbeeld een televisie op korte zichtafstand.

Aangezien infrarood (IR) afstandsbediening gebruikmaakt van licht, is een rechte zichtlijn vereist om het doelapparaat te bedienen. Het signaal kan echter, net als elk ander licht, door spiegels worden teruggekaatst.

Infraroodontvangers hebben ook vaak een min of meer beperkte werkhoek, wat voornamelijk afhangt van de optische eigenschappen van de fototransistor.

Het is echter eenvoudig om de werkhoek te vergroten door een mat transparant object voor de ontvanger te plaatsen.

## Specificaties

- Voedingsspanning: 3-5V

- Infrarood golflengte: 850nm-940nm

- Uitzendhoek: ongeveer 20 graden

- Uitzendafstand: ongeveer 1.3m (5V 38Khz)

- Interface-aansluiting: JST PH2.0

- Bevestigingsgat: binnendiameter is 3.2mm, afstand is 15mm

## Aansluitschema

Bereid eerst de volgende onderdelen voor voordat je gaat aansluiten.

- V4.0 Board\*1

- IR Transmitter module\*1

- USB Cable\*1

- Jumper Wire\*3

Verbind de S-pin van de module met Digital 3 van het V4.0-bord, verbind de negatieve pin met de GND-poort en de positieve pin met de 5V-poort.

![Afbeelding Aansluitschema](../media/31c03e9ad144e1124260ff6e0538fe69.jpeg)

## Voorbeeldcode 1

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

In een donkere omgeving zie je op het scherm van je telefoon een knipperend blauw licht als je met de camera op de infrarood-LED richt.

Upload de bovenstaande code naar het bord; de LED op de sensor zal rood knipperen.

Laten we verdergaan met een interactief voorbeeld tussen een IR-ontvanger en een IR-zendermodule.

## Infrarood afstandsbediening/communicatie

## Benodigde hardware

- Arduino R3 x2

- Digital IR Receiver x1

- IR Transmitter Module x1

Opmerking: voor dit experiment zijn twee microcontrollerborden nodig. Een breadboard vervangt het tweede bord niet omdat het de ontvanger-sketch niet kan uitvoeren.

## Communicatie-opstelling met twee borden

## Voor IR-zender

Let op: Arduino-IR remote ondersteunt alleen D3 als zender.

![Afbeelding Voor IR-zender](../media/08ebf9b37949caf1782e499f49934f1d.png)

## Voor IR-ontvanger

Verbind de signaalpin met poort D11.

![Afbeelding Voor IR-ontvanger](../media/687d429fe6360707f95fb6c5ddfa2ca7.jpeg)

## Upload code 2 naar het V4.0-bord dat met de IR-zender is verbonden

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

## Upload code 3 naar het V4.0-bord dat met de IR-ontvanger is verbonden

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

## Resultaat

Wanneer de IR-ontvangermodule het infraroodsignaal van de IR-zender ontvangt, zal de D1-led op de IR-ontvangermodule knipperen.

Wanneer de IR-ontvangermodule het infraroodsignaal van de IR-zender ontvangt, zal de D1-led op de IR-ontvangermodule knipperen.

![Afbeelding Resultaat](../media/4d73a7178e89de72df7e82a147778ae9.png)

---
