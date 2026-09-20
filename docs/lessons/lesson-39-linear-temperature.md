# Lektion 39: Lineare Temperatur

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatibles ATmega328P-Board

![Projekt 39: Lineare Temperatur Illustration](../media/9a9b328cb85401dce3932f047f0979e0.png)

## Einführung

Der LM35 Linear-Temperatursensor basiert auf dem Halbleiter-Temperatursensor LM35. Er kann zur Messung der Umgebungslufttemperatur verwendet werden.

Der Sensor hat einen Funktionsbereich von 0 °C bis 100 °C. Die Empfindlichkeit beträgt 10 mV pro Grad Celsius. Die Ausgangsspannung ist proportional zur Temperatur.

Als Temperaturmesssensoren werden üblicherweise Thermoelemente, Platin-Widerstandssensoren, Widerstandsthermometer und Halbleiter-Temperatursensoren eingesetzt.

Der Chip wird häufig in Thermoelementen zur Messung hoher Temperaturen verwendet.

Platin-Widerstandstemperatursensoren werden zur Messung von Temperaturen bis etwa 800 °C eingesetzt, während Wärmewiderstände und Halbleiter-Temperatursensoren für Messungen bis etwa 100–200 °C oder darunter geeignet sind. Bei einfachen Anwendungen bieten Halbleiter-Temperatursensoren eine gute Linearität und hohe Empfindlichkeit.

Der LM35 Linear-Temperatursensor kann einfach an ein Arduino-Shield angeschlossen werden.

## Technische Daten

- Empfindlichkeit: 10mV pro Grad Celsius

- Funktionsbereich: 0 Grad Celsius bis 100 Grad Celsius

- Größe: 30*20mm

- Gewicht: 3g

## Anschlussdiagramm

Bereiten Sie zunächst die folgenden Teile vor.

- V4.0 Board\*1

- LM35-Temperatursensor\*1

- USB-Kabel\*1

- Jumper-Kabel\*3

Befolgen Sie dann das Anschlussdiagramm: Verbinden Sie den Signalausgang des Sensors mit dem A0-Anschluss des V4.0-Boards, den Minuspol mit dem GND-Anschluss und den Pluspol mit dem 5V-Anschluss.

![Anschlussdiagramm Illustration](../media/e2f1fc77bb6b54c35bc3d1a8834cbf6b.jpeg)

## Beispielcode

Kopieren Sie den folgenden Code in die Arduino-Software.

```c
///////////////////////////////////////////////////////////////
void setup()
{
    Serial.begin(9600);//Set Baud Rate to 9600 bps
}
 void loop()
{  int val;
    int dat;
    val=analogRead(0);//Connect LM35 on Analog 0
    dat=(500 * val) /1024;;
    Serial.print("Temp:"); //Display the temperature on Serial monitor
    Serial.print(dat);
    Serial.println("C");
    delay(500);
}
///////////////////////////////////////////////////////////////
```

## Beispielergebnis

![Beispielergebnis Illustration](../media/95d0d43a93fd2bf1e9c7248e80edcedc.png)

Verdrahten Sie alles wie im obigen Diagramm, laden Sie den Code auf das Board hoch, öffnen Sie dann den Seriellen Monitor und stellen Sie die Baudrate auf 9600.

Sie sehen den aktuellen Temperaturwert, wie unten dargestellt. Der Wert kann je nach Ort und Wetter leicht abweichen.

![Beispielergebnis Illustration](../media/8331a0416c8006161b3227e170a3b033.jpeg)

---
