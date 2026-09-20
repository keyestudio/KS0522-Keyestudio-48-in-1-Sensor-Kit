# Lektion 26: Analoger Alkohol

> **Bausatz:** Keyestudio 48-in-1 Sensorsatz  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P-Platine

![Projekt 26: Analoger Alkohol - Abbildung](../media/288162cf02f2968eda57b437292a42dd.png)

## Beschreibung

Dieser analoge MQ-3-Sensor eignet sich zur Erkennung von Alkohol. Er kann in einem Atemalkoholmessgerät verwendet werden.

Er besitzt eine gute Selektivität, da er gegenüber Alkohol eine höhere Empfindlichkeit und gegenüber Benzin eine geringere Empfindlichkeit aufweist.

Die Empfindlichkeit kann durch Drehen des Potentiometers auf dem Sensor eingestellt werden.

## Spezifikationen

- Versorgungsspannung: 5V

- Schnittstellentyp: Analog

- Einfache Ansteuerschaltung

- Stabil und lange Lebensdauer

- Schnelle Reaktion und hohe Empfindlichkeit

## Anschlussdiagramm

Verbinden Sie den A0-Pin des Moduls mit dem analogen A0 der V4.0-Platine, verbinden Sie den GND-Pin mit dem GND-Anschluss und den VCC-Pin mit dem 5V-Anschluss.

![Anschlussdiagramm - Abbildung](../media/61632f44731176aaf95d313f2843c9de.jpeg)

## Beispielcode

Kopieren Sie den untenstehenden Code in die Arduino-Software.

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

![Beispielergebnis - Abbildung](../media/a21d5b8c686e46a59128ab48b96d177c.png)

Nachdem die Verdrahtung abgeschlossen und die Stromversorgung eingeschaltet ist, laden Sie den Code hoch, öffnen Sie dann den seriellen Monitor und stellen Sie die Baudrate auf 9600 ein. Sie sehen den Analogwert. Beim Erkennen von Alkoholgas ändert sich der Wert.

![Beispielergebnis - Abbildung](../media/97565d8ba7691b30a7aa96efc6c7728b.jpeg)

---
