# Lektion 01: Weiße LED

> **Bausatz:** Keyestudio 48-in-1 Sensor-Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P-Platine

![Projekt 1: Weiße LED Abbildung](../media/6819f1c2047a7bb2b58e9cf0d7d3a617.jpeg)

## Beschreibung

Dieses weiße LED-Lichtmodul ist ideal für Arduino-Einsteiger. Es kann einfach an ein IO/Sensor-Shield angeschlossen werden. Es ermöglicht Interaktionen mit lichtbezogenen Projekten.

Hinweis: Sie können auch andere LED-Module wählen, um verschiedene Farben wie Gelb, Rot, Grün und Blau auszustrahlen.

## Spezifikation

- Weißes LED-Modul

- Typ: Digital

- PH2.54-Buchse

- Größe: 30\*20mm

- Gewicht: 3g

## Anschlussdiagramm

Bereiten Sie vor dem Anschluss zunächst die folgenden Teile vor:

- V4.0-Platine\*1

- Weißes LED-Modul \*1

- USB-Kabel\*1

- Jumperkabel\*3

Verbinden Sie den S-Pin des Moduls mit Digital 3 der V4.0-Platine, verbinden Sie den negativen Pin mit dem GND-Port, den positiven Pin mit dem 5V-Port.

![Anschlussdiagramm Abbildung](../media/cb67155c3b3cf25025edea5ae31d6c5f.jpeg)

## Beispielcode

Kopieren Sie den folgenden Code in die Arduino-Software.

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

## Beispielergebnis

Nach dem Verdrahten, Einschalten und erfolgreichem Hochladen des Codes leuchtet das LED-Modul weiß.

![Beispielergebnis Abbildung](../media/40448f38601a6312bfb1e3764be22158.png)

---
