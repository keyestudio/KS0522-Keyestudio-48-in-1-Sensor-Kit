# Lektion 31: Umgebungslicht

> **Bausatz:** Keyestudio 48-in-1 Sensor-Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P-Platine

![Projekt 31: Umgebungslicht Abbildung](../media/3eda1bbb84995dc2195a0406f1b0c196.jpeg)

## Beschreibung

Irgendwann werden Sie die Umgebungshelligkeit mit besserer Präzision als mit Ihrem bewährten Fotowiderstand messen wollen, ohne die Komplexität Ihres Projekts zu erhöhen. Für diesen Fall besorgen Sie sich einen TEMT6000-Umgebungslichtsensor.

Der TEMT6000 ist an die Empfindlichkeit des menschlichen Auges angepasst, zeigte sich jedoch bei schlechten Lichtverhältnissen als mäßig. Er reagiert jedoch sehr gut auf sehr kleine Helligkeitsänderungen über einen großen Bereich. Da er das menschliche Auge nachahmen soll, reagiert er nicht gut auf IR- oder UV-Licht, beachten Sie das also bei der Verwendung in Ihrem Projekt.

## Spezifikation

- Betriebsspannung: +5VDC 50mA

- Größe: 36.5\*16mm

- Gewicht: 4g

## Anschlussdiagramm

Zuerst müssen Sie die folgenden Teile vor dem Anschluss vorbereiten.

- V4.0-Platine\*1

- TEMT6000-Umgebungslichtsensor\*1

- USB-Kabel\*1

- Jumperkabel\*3

Dies ist ein extrem einfaches Bauteil: Verbinden Sie einfach Versorgungsspannung und Masse sowie den Signalausgang mit einem analogen Eingangsport. Ist die Verbindung hergestellt, gibt der Sensor eine analoge Spannung aus, die mit zunehmender Helligkeit ansteigt. Sie können ihn auch mit 3.3V betreiben; dann sind die Ausgangswerte nur deutlich niedriger.

![Anschlussdiagramm Abbildung](../media/dae046a9efbeea661b9b6a2ab632fcbc.jpeg)

## Beispielcode

Einfacher geht es kaum – dieses Beispiel gibt nur den Messwert des Sensors an den seriellen Monitor aus: 0-1023, wobei 1023 sehr hell und 0 sehr dunkel ist.

```c
///////////////////////////////////////////////////////////////
int temt6000Pin = 0;
void setup() {
 Serial.begin(9600);
}
void loop() {
 int value = analogRead(temt6000Pin);
 Serial.println(value);
 delay(100); //only here to slow down the output so it is easier to read
}
///////////////////////////////////////////////////////////////
```

## Beispielergebnis

Nachdem Sie korrekt verdrahtet und den obigen Code hochgeladen haben, öffnen Sie den seriellen Monitor der Arduino-Software.

![Beispielergebnis Abbildung](../media/ea9ab82076983cc965fe016297b6ad76.png)

Bedecken Sie dann den Sensor mit Ihrer Hand oder einem Papier; das Licht wird schwächer und schließlich sehen Sie, wie der auf dem Monitor angezeigte Wert abnimmt.

![Beispielergebnis Abbildung](../media/846828c9af69a9823ca7218157cc181e.jpeg)

---
