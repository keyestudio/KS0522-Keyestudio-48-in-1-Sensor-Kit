# Les 02: RGB LED

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P bord

![Project 2: RGB LED illustratie](../media/de14ae0679267cf87837b7c09934c52e.png)

## Beschrijving

Dit is een full-colour LED-module, die 3 basiskleuren bevat – rood, groen en blauw. Ze kunnen worden gezien als afzonderlijke LED-lampjes.

Na programmeren kunt u ze achtereenvolgens aan- en uitzetten, of de PWM-analoge uitgang gebruiken om de drie kleuren te mengen en zo verschillende kleuren te genereren.

## Specificatie

- Kleur: rood, groen en blauw

- Helderheid: Hoog

- Spanning: 5V

- Ingang: digitaal niveau

- Afmeting: 30 \*20mm

- Gewicht: 3g

## Aansluitschema

Bereid eerst de volgende onderdelen voor voordat u ze aansluit:

- V4.0-bord\*1

- RGB LED-module \*1

- USB-kabel\*1

- Dupont-draad\*4

Verbind de V-pin van de module met de 5V-poort van het V4.0-board, verbind de B-pin met Digital 11, de R-pin met Digital 10 en de G-pin met Digital 9.

![Aansluitschema illustratie](../media/2c0a9305cd7c7b0c28c51bc2bc24eb39.jpeg)

## Voorbeeldcode

Kopieer en plak de onderstaande code in de Arduino-software.

```c
const uint8_t redPin = 11;
const uint8_t bluePin = 10;
const uint8_t greenPin = 9;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  for (int value = 255; value >= 0; --value) {
    analogWrite(redPin, value);
    analogWrite(bluePin, 255 - value);
    analogWrite(greenPin, 128 - value);
    delay(1);
  }
  for (int value = 0; value < 255; ++value) {
    analogWrite(redPin, value);
    analogWrite(bluePin, 255 - value);
    analogWrite(greenPin, 128 - value);
    delay(1);
  }
}
```

## Voorbeeldresultaat

Als de bedrading is voltooid en het bord van stroom is voorzien en de code succesvol is geüpload, zult u zien dat de RGB LED-module heldere kleuren uitstraalt.

![Voorbeeldresultaat illustratie](../media/0872e5256edf443efcb68218505096ba.png)

---
