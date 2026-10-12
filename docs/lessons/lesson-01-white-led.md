# Les 01: Witte LED

> **Set:** Keyestudio 48-in-1 Sensor Kit  
> **Ontwikkelbord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P-board

![Project 1: Witte LED illustratie](../media/6819f1c2047a7bb2b58e9cf0d7d3a617.jpeg)

## Beschrijving

Deze witte LED-lichtmodule is ideaal voor Arduino-beginners. Hij kan eenvoudig worden aangesloten op een IO/Sensor shield. Hij maakt interactie met lichtgerelateerde projecten mogelijk.

Opmerking: Je kunt ook andere LED-modules kiezen om andere kleuren te laten uitstralen, zoals geel, rood, groen en blauw.

## Specificatie

- Witte LED-module

- Type: Digitaal

- PH2.54-connector

- Afmetingen: 30\*20mm

- Gewicht: 3g

## Aansluitschema

Bereid eerst de volgende onderdelen voor voordat je gaat aansluiten:

- V4.0-ontwikkelbord\*1

- Witte LED-module \*1

- USB-kabel\*1

- Dupont-kabel\*3

Sluit de S-pin van de module aan op Digital 3 van het V4.0-ontwikkelbord, sluit de negatieve pin aan op de GND-poort en de positieve pin op de 5V-poort.

![Aansluitschema illustratie](../media/cb67155c3b3cf25025edea5ae31d6c5f.jpeg)

## Voorbeeldcode

Kopieer en plak de onderstaande code in de Arduino-software.

```c
const uint8_t ledPin = 3;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
```

## Voorbeeldresultaat

Na het aansluiten en inschakelen, en nadat je de code succesvol hebt geüpload, zal de LED-module wit licht uitstralen.

![Voorbeeldresultaat illustratie](../media/40448f38601a6312bfb1e3764be22158.png)

---
