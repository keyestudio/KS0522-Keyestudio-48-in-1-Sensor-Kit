# Lektion 02: RGB-LED

> **Bausatz:** Keyestudio 48-in-1 Sensor-Kit  
> **Platine:** Keyestudio V4.0 / Arduino-Uno-kompatible ATmega328P-Platine

![Projekt 2: RGB-LED-Illustration](../media/de14ae0679267cf87837b7c09934c52e.png)

## Beschreibung

Dies ist ein Vollfarben-LED-Modul, das 3 Grundfarben enthält－Rot, Grün und Blau. Sie können als separate LEDs betrachtet werden.

Nach dem Programmieren können Sie sie der Reihe nach ein- und ausschalten oder den PWM-Analogausgang verwenden, um die drei Farben zu mischen und verschiedene Farben zu erzeugen.

## Spezifikation

- Farbe: Rot, Grün und Blau

- Helligkeit: Hoch

- Spannung: 5V

- Eingang: digitaler Pegel

- Größe: 30 \*20mm

- Gewicht: 3g

## Anschlussdiagramm

Bereiten Sie vor dem Anschluss zuerst die folgenden Teile vor:

- V4.0 Platine\*1

- RGB-LED-Modul \*1

- USB-Kabel\*1

- Jumperkabel\*4

Verbinden Sie den V-Pin des Moduls mit dem 5V-Anschluss der V4.0-Platine, verbinden Sie den B-Pin mit Digital 11, den R-Pin mit Digital 10, den G-Pin mit Digital 9.

![Anschlussdiagramm-Illustration](../media/2c0a9305cd7c7b0c28c51bc2bc24eb39.jpeg)

## Beispielcode

Kopieren Sie den folgenden Code in die Arduino-Software.

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

## Beispielergebnis

Nachdem die Verkabelung abgeschlossen und die Stromversorgung eingeschaltet ist und der Code erfolgreich hochgeladen wurde, sehen Sie, wie das RGB-LED-Modul leuchtende Farben ausgibt.

![Beispielergebnis-Illustration](../media/0872e5256edf443efcb68218505096ba.png)

---
