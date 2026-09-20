# Lektion 09: Linienfolgesensor

> **Bausatz:** Keyestudio 48-in-1 Sensor-Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P-Platine

![Projekt 9: Linienfolgesensor Illustration](../media/c476ef922ab6a8d31cb68f3ab3fa2ced.png)

## Beschreibung

Dieser Linienfolgesensor kann weiße Linien auf schwarzem Untergrund oder schwarze Linien auf weißem Untergrund erkennen.

Das einzelne Linienverfolgungs-Signal liefert ein stabiles TTL-Ausgangssignal für eine genauere und stabilere Linienverfolgung. Eine Mehrkanal-Option kann einfach durch die Installation der benötigten Linienfolgesensoren für Roboter realisiert werden.

## Technische Daten

1. Versorgung: +5V

2. Betriebsstrom: \<10mA

3. Betriebstemperaturbereich: 0°C \~ + 50°C

4. Ausgangsschnittstelle: 3-polige Schnittstelle (1 - Signal, 2 - Versorgung, 3 - Versorgung negativ)

5. Ausgangspegel: TTL-Pegel

## Anschlussdiagramm

Bereiten Sie vor dem Anschluss zunächst die folgenden Teile vor:

- V4.0 Board\*1

- Linienfolge-Modul \*1

- USB-Kabel\*1

- Jumper-Kabel\*3

Verbinden Sie den S-Pin des Moduls mit Digital 3 des V4.0-Boards, verbinden Sie den GND-Pin mit dem GND-Anschluss und den V+-Pin mit dem 5V-Anschluss.

![Anschlussdiagramm Abbildung](../media/6727a1d7d92c3878fc51b8db0502fd14.jpeg)

## Beispielcode

Kopieren Sie den folgenden Code in die Arduino-Software.

```c
////////////////////////////////////////////////////////////////////
//Arduino Sample Code
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  Serial.println(digitalRead(3)); // print the data from the sensor
  delay(500);
}
////////////////////////////////////////////////////////////////////
```

## Beispielergebnis

![Beispielergebnis Abbildung](../media/af115c59987fee06447790f1740e3203.jpeg)

Nachdem der Code auf das Board hochgeladen wurde, öffnen Sie den seriellen Monitor und stellen Sie die Baudrate auf 9600 ein. Dann können Sie die Daten des Sensors sehen.

---
