# Lektion 35: Pulsmessgerät

> **Bausatz:** Keyestudio 48-in-1 Sensor-Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P-Platine

![Projekt 35: Pulsmessgerät – Illustration](../media/0ec440cd93e00e956357ece654ce2a9c.png)

## Beschreibung

Dieses Modul verwendet eine ultraklare Infrarot-LED und einen Phototransistor, um den Puls in Ihrem Finger zu erkennen. Die rote LED blinkt im Takt Ihres Pulses.

Funktionsprinzip

Richten Sie die helle LED auf eine Seite Ihres Fingers, während der Phototransistor auf der anderen Seite die Menge des durchgelassenen Lichts erfasst. Der Widerstand des Phototransistors ändert sich leicht, wenn das Blut durch Ihren Finger pulsiert.

## Anschlussdiagramm

Bereiten Sie zunächst die folgenden Teile vor, bevor Sie einen Test durchführen.

- V4.0-Platine*1

- Pulsmodul*1

- USB-Kabel*1

- Jumper-Kabel*3

Verbinden Sie den Signal-Pin des Moduls mit Analog A0 der V4.0-Platine, den positiven Pin mit dem 5V-Anschluss und den negativen Pin mit GND.

![Anschlussdiagramm – Abbildung](../media/fa86e3930b83753af7ad87d0418cd350.jpeg)

## Beispielcode

Kopieren Sie den folgenden Code in die Arduino-Software.

```c
///////////////////////////////////////////////////////////////
int ledPin = 13;
int sensorPin = 0;
double alpha = 0.75;
int period = 20;
double change = 0.0;
void setup()
{
pinMode(ledPin, OUTPUT);
Serial.begin(115200);
}
void loop()
{
static double oldValue = 0;
static double oldChange = 0;
int rawValue = analogRead(sensorPin);
double value = alpha * oldValue + (1 - alpha) * rawValue;
Serial.print(rawValue);
Serial.print(",");
Serial.println(value);
oldValue = value;
delay(period);
}
///////////////////////////////////////////////////////////////
```

## Beispielergebnis

Verdrahten Sie alles wie im obigen Diagramm, laden Sie dann den Code auf das Board hoch und klicken Sie in der Arduino-Software oben rechts auf das Symbol des seriellen Monitors. Stellen Sie die Baudrate auf 115200 ein; die Daten werden im Monitor angezeigt.

Sie können die Daten in Excel kopieren und einfügen; schließlich wird das entsprechende unten gezeigte Diagramm erstellt.

![Beispielergebnis – Abbildung](../media/3c3a1a0d120f1c68c95095a0fd98fa47.png)

![Beispielergebnis – Abbildung](../media/215ab9a6174f9798a291bacb907eaf89.jpeg)

---
