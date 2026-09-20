# Lektion 32: Ultraviolettes Licht

> **Bausatz:** Keyestudio 48-in-1 Sensor-Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P-Platine

![Projekt 32: Ultraviolettes Licht Illustration](../media/15613ff0e8f059a9034e923ab5c2be24.jpeg)

## Beschreibung

Der Keyestudio GUVA-S12SD Ultraviolett-Sensor wird verwendet, um ultraviolettes Licht zu erkennen. Er wird unter anderem eingesetzt, um den UV-Index intelligenter Wearables wie Uhren, Smartphones und Outdoor-Geräte mit UV-Index-Erkennung zu messen.

Er kann auch zur Überwachung der Intensität von UV-Licht oder als UV-Flammendetektor bei der Desinfektion von Gegenständen mit UV-Licht verwendet werden.

## Parameter

- Größe: 15mm×30mm×0.7mm

- Versorgungsspannung: 2.5V～5V

- Ausgangssignal: Analoges Signal

- Erkennungsbereich des Spektrums: 240-370nm

- Aktive Fläche: 0.076mm2

- Empfindlichkeit: 0.14A/W

- Dunkelstrom: 1nA

- Lichtstrom: 101\~125nA UVA-Licht, 1mW/cm2

## Anschlussdiagramm

Zuerst müssen Sie die folgenden Teile vor dem Anschluss vorbereiten.

- V4.0 Platine\*1

- GUVA-S12SD 3528 Ultraviolett-Sensor \*1

- USB-Kabel\*1

- Jumperkabel\*3

Verbinde den S-Pin des Moduls mit dem analogen A0 des V4.0-Boards, den Minuspol mit dem GND-Anschluss und den Pluspol mit dem 3V3-Anschluss.

![Verbindungsdiagramm Illustration](../media/092ebb11142cfe83507989a5b2de0526.jpeg)

## Beispielcode

Kopiere den folgenden Code in die Arduino-Software.

```c
///////////////////////////////////////////////////////////////
/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

 This example code is in the public domain.
 */

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
}
///////////////////////////////////////////////////////////////
```

## Beispielergebnis

![Beispielergebnis Illustration](../media/e81338e1f55ff6b55fbfe369f92b54da.png)

Verdrahte alles korrekt und lade den Programmcode hoch, dann öffne den seriellen Monitor; er zeigt die Daten an.

Wenn UV-Licht auf den Sensor gerichtet wird, ändern sich die Daten im seriellen Monitor, wie in der folgenden Abbildung gezeigt.

![Beispielergebnis Illustration](../media/3a7f2a608faa9c72aee76d2820f78845.png)

![Beispielergebnis Illustration](../media/610d2325395cd3b44ce3c18e05595518.jpeg)

---
