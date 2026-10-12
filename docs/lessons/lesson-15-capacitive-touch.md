# Les 15: Capacitieve aanraking

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibele ATmega328P board

![Project 15: Capacitieve aanraking illustratie](../media/bceabc7d4302bd41ae380e179a281314.png)

## Beschrijving

Ben je het zat om mechanische knoppen te gebruiken? Probeer dan onze capacitieve aanraaksensor. Aanraaksensoren worden meestal gebruikt op elektronische apparaten. Upgrade dus je Arduino-project met deze aanraaksensor om je project stoerder te maken.

Deze kleine sensor kan aanraking van het lichaam en metaal detecteren en geeft als feedback een hoog/laag spanningsniveau. Zelfs wanneer geïsoleerd door kleding of papier kan hij de aanraking nog steeds voelen. Maar de gevoeligheid neemt af naarmate de isolatielaag dikker wordt.

We zullen deze sensormodules verder verbeteren om je een betere ervaring te bieden.

## Specificaties

- Voedingsspanning: 3.3V tot 5V

- Interface: Digitaal

- Grootte: 30*20mm

- Gewicht: 3g

## Aansluitschema

Bereid eerst de volgende onderdelen voor voordat je gaat aansluiten:

- V4.0-bord*1

- Capacitieve aanraaksensor*1

- USB-kabel*1

- Jumperdraad*3

Verbind de S-pin van de module met Digital 2 van het V4.0-board, verbind de negatieve pin met de GND-poort en de positieve pin met de 5V-poort.

![Aansluitschema illustratie](../media/18193a53377b60f43fb583c29337f3aa.jpeg)

## Voorbeeldcode

Kopieer en plak onderstaande code in de Arduino-software.

```c
const uint8_t ledPin = 13;  // On-board LED.
const uint8_t touchPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(touchPin, INPUT);
}

void loop() {
  const int touched = digitalRead(touchPin);
  digitalWrite(ledPin, touched == HIGH ? HIGH : LOW);
}
```

## Voorbeeldresultaat

Na het aansluiten en inschakelen, en nadat je de code hebt geüpload, raak je de sensor met je vinger aan; zowel de D2-led op de sensor als de D13-indicator op het V4.0-board gaan branden. Anders zijn die twee indicatoren uit.

![Voorbeeldresultaat illustratie](../media/31a751feed0f21236458b93eed14af9f.png)

---
