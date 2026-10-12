# Les 08: Botsingsflits

> **Kit:** Keyestudio 48-in-1 sensorenkit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P-bord

![Project 8: Illustratie Botsingsflits](../media/29c4641406064a4f1df5d59aefbca480.png)

## Beschrijving

Botsingssensor, ook bekend als elektronische schakelaar, is een digitale aan/uit-ingangsmodule die noodzakelijk is voor basis elektronische leeractiviteiten.

Met programmeren kan deze gebruikt worden om licht, geluidsapparaten, toetskeuzefuncties van een LCD-display, enz. te regelen.

Door een 3P-sensorkabel te gebruiken om hem aan een sensor shield te koppelen, kan hij op een 4WD AL-legering mobiel robotplatform worden gemonteerd om botsingsdetectie mogelijk te maken. Het is zowel handig als efficiënt.

Je kunt een botsingsknipper maken met de botsingsmodule en de ingebouwde LED op interface 13. Verbind de botsingssensor met pin 3. Wanneer de botsingssensor een botsingssignaal detecteert, gaan de LEDs op zowel het hoofdboard als de module gelijktijdig branden.

## Kenmerken

1. Als er een botsing plaatsvindt aan de voorkant van waar de botsingsmodule is gemonteerd, geeft de module een laag signaal uit; geen botsing geeft een hoog signaal uit.

2. De module heeft een M3-montagegat gereserveerd, handig voor bevestiging op een voertuig.

3. Met een schakelaar-indicatorlampje: bij een botsing is het lampje aan; zonder botsing is het lampje uit.

## Pindefinitie

1. Positieve pin (+): verbinden met 3v-12v voedingsspanning

2. Negatieve pin (-): verbinden met GND

3. Signaalpin (S): geeft hoog/laag niveau uit

## Aansluitschema

Bereid vooraf de volgende onderdelen voor:

- V4.0-bord\*1

- Botsingsmodule \*1

- USB-kabel\*1

- Jumperdraad\*3

Verbind de S-pin van de module met Digital 3 van het V4.0-bord, verbind de negatieve pin met de GND-poort en de positieve pin met de 5V-poort.

![Aansluitschema-illustratie](../media/a4ec0b7f8fd95fb2d6bb5c06ca0776f0.jpeg)

## Voorbeeldcode

Kopieer en plak onderstaande code in de Arduino-software.

```c
const uint8_t ledPin = 13;
const uint8_t collisionPin = 3;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(collisionPin, INPUT);
}

void loop() {
  const int state = digitalRead(collisionPin);
  digitalWrite(ledPin, state == HIGH ? LOW : HIGH);
}
```

## Voorbeeldresultaat

Sluit alles goed aan en upload vervolgens de code naar het bord.

Wanneer een object de schakelaar van de sensor raakt, gaan zowel de LED op de sensor als LED 13 op het bord aan.

---
