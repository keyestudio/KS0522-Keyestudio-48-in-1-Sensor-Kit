# Lektion 21: Fotowiderstand

> **Bausatz:** Keyestudio 48-in-1 Sensor-Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P-Platine

![Projekt 21: Fotowiderstand Illustration](../media/8eed60793fd64a7c0b9a9b2a2fc1ef67.png)

## Beschreibung

Fotowiderstände kommen in unserem Alltag häufig vor und werden hauptsächlich in intelligenten Schaltkreisen sowie im allgemeinen Elektronikdesign eingesetzt. Um die Verwendung zu vereinfachen und effektiver zu machen, liefern wir entsprechende Module.

Der Fotowiderstand ist ein Halbleiter. Er zeichnet sich durch hohe Empfindlichkeit, schnelle Reaktion, spektrale Eigenschaften und konstante R-Werte aus und behält hohe Stabilität und Zuverlässigkeit auch unter extremen Umgebungsbedingungen wie hoher Temperatur und hoher Luftfeuchtigkeit.

Er wird weit verbreitet in automatischen Steuerungsfeldern eingesetzt, z. B. in Kameras, solarbetriebenen Gartenleuchten, Rasenlampen, Geldscheinprüfern, Quarzuhren, Musikbechern, Geschenkboxen, kleinen Nachtlichtern, Licht- und Ton-Steuerschaltern usw.

## Spezifikation

- Schnittstellentyp: analog

- Betriebsspannung: 5V

- Größe: 30*20mm

- Gewicht: 3g

## Anschlussdiagramm

Verbinden Sie den S-Pin des Moduls mit dem analogen Anschluss A0 der V4.0-Platine, verbinden Sie den Negativ-Pin mit dem GND-Anschluss, den Positiv-Pin mit dem 5V-Anschluss.

![Anschlussdiagramm Abbildung](../media/28a1990cd088d6f0301f02d217cef301.jpeg)

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

![Beispielergebnis Abbildung](../media/78268e9cb1dbc127e7ae3299d3a35a45.png)

Nachdem die Verdrahtung abgeschlossen und die Platine mit Strom versorgt ist, laden Sie den Code hoch und öffnen dann den seriellen Monitor. Wenn Sie den Fotowiderstand auf dem Sensor mit Ihrer Hand abdecken, sehen Sie, dass der analoge Wert abnimmt.

![Beispielergebnis Abbildung](../media/85621deb4c66d6e53697cd0ef90cb6e2.jpeg)

---
