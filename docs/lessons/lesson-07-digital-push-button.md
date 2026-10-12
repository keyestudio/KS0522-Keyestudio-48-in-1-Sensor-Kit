# Les 07: Digitale drukknop

> **Set:** Keyestudio 48-in-1 sensorkit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P-bord

![Project 7: Digitale drukknop illustratie](../media/a8707354e54ea51bb92584f791ae79e5.png)

## Beschrijving

Dit is een basis knoppenmodule. Je kunt deze eenvoudig in een IO-shield pluggen om je eerste Arduino-ervaring uit te proberen.

## Kenmerken

- Breed spanningsbereik van 3.3V tot 5V

- Gemakkelijk herkenbare sensorinterfaces ("A" voor Analoog en "D" voor Digitaal)

- Standaard montagegat

- Duidelijke pictogrammen

- Hoogwaardige connector

- Gemakkelijk in te pluggen en te bedienen

- Grote knop en hoogwaardige kap

- Om interessante en interactieve projecten te realiseren

## Specificatie

- Voedingsspanning: 3.3V tot 5V

- Interface: Digitaal

- Afmetingen: 30*20mm

- Gewicht: 4g

## Aansluitschema

Bereid eerst de volgende onderdelen voor voordat je gaat aansluiten:

- V4.0-bord*1

- Drukknopmodule*1

- USB-kabel*1

- Jumperdraden*3

Verbind de S-pin van de module met Digital 3 van het V4.0-bord, verbind de negatieve pin met de GND-aansluiting en de positieve pin met de 5V-aansluiting.

![Aansluitschema illustratie](../media/6ec73b961481bf0794572a842c5231fa.jpeg)

## Voorbeeldcode

Kopieer en plak onderstaande code in de Arduino-software.

```c
////////////////////////////////////////////////////////////////////
/* # When you push the digital button, the Led 13 on the board will be turned on. Otherwise,the led is turned off.
*/
int ledPin = 13;                // choose the pin for the LED
int inputPin = 3;               // Connect sensor to input pin 3
void setup() {
  pinMode(ledPin, OUTPUT);      // set LED as output
  pinMode(inputPin, INPUT);     // set pushbutton as input
}
void loop(){
  int val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, LOW);  // turn LED OFF
  } else {
    digitalWrite(ledPin, HIGH); // turn LED ON
  }
}
////////////////////////////////////////////////////////////////////
```

## Voorbeeldresultaat

Sluit alles goed aan zoals in de onderstaande afbeelding en upload vervolgens de code naar het bord.

Wanneer je de digitale knop indrukt, gaat LED 13 op het V4.0-bord aan. Wanneer je de knop loslaat, gaat de LED uit. Zie hieronder.

![Voorbeeldresultaat illustratie](../media/ac03d3fa1c0f5de7dae18c6e64406e60.png)

---
