# Lektion 28: Analoge Keramik-Vibration

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P-Platine

![Analoger Keramik-Vibrationssensormodul](../media/2cf5c2793157816a2346a730ad064955.jpeg)

## Beschreibung

Dieser Vibrationssensor basiert auf einem analogen piezoelektrischen Keramikchip. Er nutzt den piezoelektrischen Effekt, bei dem die Keramik durch Vibration elektrische Signale erzeugt. Wenn der piezoelektrische Keramikchip vibriert, erzeugt der Signalausgang des Sensors elektrische Signale.

Der Sensor kann mit einem dedizierten Sensor-Shield für Arduino verwendet werden, und der analoge Eingang des Arduino kann schwache Vibrationssignale wahrnehmen, so dass interaktive Anwendungen in Bezug auf Vibration möglich sind, z. B. elektronische Schlaginstrumente.

Verbinden Sie den Vibrationssensor mit dem analogen Anschluss A0 des Arduino UNO. Wenn Sie den Sensor in unterschiedlicher Stärke vibrieren, sehen Sie verschiedene Ausgabewerte, die im seriellen Monitor der Arduino-Software angezeigt werden.

## Spezifikation

- Versorgungsspannung：3.3V bis 5V

- Betriebsstrom：\<1mA

- Betriebstemperaturbereich：－10℃～＋70℃

- Ausgangssignal：analoges Signal

## Anschlussdiagramm

Zuerst müssen Sie vor der Verbindung die folgenden Teile vorbereiten:

- V4.0-Platine\*1

- Vibrationssensor\*1

- USB-Kabel\*1

- Jumper-Kabel\*3

Verbinden Sie den S-Pin des Moduls mit Analog A0 der V4.0-Platine, verbinden Sie den negativen Pin mit dem GND-Anschluss, NC-Pin mit dem 5V-Anschluss.

![Anschlussdiagramm](../media/92fce2d45b05876a7928070bd2b137da.jpeg)

## Beispielcode

Kopieren Sie den folgenden Code in die Arduino-Software.

```c
///////////////////////////////////////////////////////////
void setup()
{
Serial.begin(9600); //Open the serial to set the baud rate as 9600bps
}
void loop()
{
int val;
val=analogRead(0); //Connect the sensor to analog interface A0
Serial.print("Vibration is ");
Serial.println(val,DEC);//Print the analog value read on serial port
delay(100);
}
///////////////////////////////////////////////////////////
```

## Beispielergebnis

![Beispielergebnis](../media/e21152ca9f30274fcc658091f76f7044.png)

Verdrahten Sie wie im obigen Diagramm und laden Sie den Code hoch, dann öffnen Sie den seriellen Monitor und stellen die Baudrate auf 9600.

Wenn Sie den Keramikchip zum Vibrieren bringen, sehen Sie die Datenänderungen wie in der unten gezeigten Abbildung.

![Beispielergebnis](../media/4be72e831696d59b36082aa45d77a04d.jpeg)

---
