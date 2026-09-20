# Lektion 20: Analoge Drehung

> **Bausatz:** Keyestudio 48-in-1 Sensor-Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P Platine

![Projekt 20: Analoge Drehung Illustration](../media/7a7fffa705c4a50e87455e6d378eb837.png)

## Beschreibung

Dieser analoge Rotationssensor ist mit Arduino kompatibel. Er basiert auf einem Potentiometer. Seine Spannung lässt sich in 1024 Werte unterteilen und er lässt sich einfach mit unserem Sensorshield an das Arduino anschließen.

In Kombination mit anderen Sensoren können Sie ihn für interessante Projekte verwenden, indem Sie den analogen Wert vom I/O-Port auslesen.

## Spezifikation

- Versorgungsspannung: 3,3 V bis 5 V

- Schnittstelle: Analog

- Größe: 30 × 20 mm

- Gewicht: 8 g

## Anschlussdiagramm

Verbinden Sie den S‑Pin des Moduls mit Analog A0 der V4.0‑Platine, verbinden Sie den negativen Pin mit dem GND‑Anschluss und den positiven Pin mit dem 5V‑Anschluss.

![Anschlussdiagramm Abbildung](../media/f8a0c2cca0f3d0935ce0c9a0c4dbe59e.jpeg)

## Beispielcode

Kopieren Sie den folgenden Code in die Arduino-Software.

```c
////////////////////////////////////////////////////////////////////
void setup()
{
  Serial.begin(9600); //Set serial baud rate to 9600 bps
}
void loop()
{
int val;
val=analogRead(0);//Read rotation sensor value from analog 0
Serial.println(val,DEC);//Print the value to serial port
delay(100);
}
////////////////////////////////////////////////////////////////////
```

## Beispielergebnis

![Beispielergebnis Illustration](../media/bae047449c10c99449c35a14b22d759c.png)

Nachdem die Verkabelung abgeschlossen und die Stromversorgung eingeschaltet ist und der Code erfolgreich hochgeladen wurde, öffnen Sie den seriellen Monitor und stellen Sie die Baudrate auf 9600 ein. Danach sehen Sie den analogen Wert. Wenn Sie den Drehknopf des Rotationssensors drehen, ändert sich der Wert im Bereich 0–1023. Siehe unten.

![Beispielergebnis Illustration](../media/bc7b15c3245b7cfd91b0ef4b0aeb8e7e.jpeg)

---
