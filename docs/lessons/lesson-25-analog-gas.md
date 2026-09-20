# Lektion 25: Analoger Gassensor

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P-Platine

![Projekt 25: Analoger Gassensor Abbildung](../media/36f00d2a934c497f390b49c4113c7c04.png)

## Beschreibung

Dieser analoge Gassensor MQ2 wird in Gasleckage-Erkennungsgeräten sowohl im Consumer- als auch im Industriebereich eingesetzt. Dieser Sensor eignet sich zum Erkennen von LPG, I-Butan, Propan, Methan, Alkohol, Wasserstoff und Rauch.

Der Erkennungsbereich dieses Sensors ist sehr breit, und er bietet hohe Empfindlichkeit sowie schnelle Reaktionszeiten.

Zusätzlich kann die Empfindlichkeit durch Drehen des Potentiometers auf dem Sensor eingestellt werden.

## Technische Daten

- Stromversorgung: 5V

- Schnittstellentyp: Analog

- Einfache Ansteuerschaltung

- Stabil und lange Lebensdauer

## Anschlussdiagramm

Verbinden Sie den A0-Pin des Moduls mit Analog A0 des V4.0-Boards, verbinden Sie den GND-Pin mit dem GND-Anschluss, den VCC-Pin mit dem 5V-Anschluss.

![Anschlussdiagramm Abbildung](../media/7b2cdff9418f79b2e9e566ce61a7966a.jpeg)

## Beispielcode

Kopieren Sie den folgenden Code in die Arduino-Software.

```c
////////////////////////////////////////////////////////////////////
//Arduino Sample Code
void setup()
{
  Serial.begin(9600); //Set serial baud rate to 9600 bps
}
void loop()
{
int val;
val=analogRead(0);//Read Gas value from analog 0
Serial.println(val,DEC);//Print the value to serial port
delay(100);
}

////////////////////////////////////////////////////////////////////
```

## Beispielergebnis

![Beispielergebnis Abbildung](../media/d440553d52e043d7a91928882d877dd1.png)

Nachdem die Verkabelung abgeschlossen und die Stromversorgung eingeschaltet ist, laden Sie den Code hoch, öffnen Sie dann den seriellen Monitor und stellen Sie die Baudrate auf 9600 ein. Sie sehen den analogen Wert. Beim Erfassen von Gas ändert sich der Wert.

![Beispielergebnis Abbildung](../media/cbf777feb6231d76347bc632f87d0e8e.jpeg)

---
