# Lektion 19: Analoge Temperatur

> **Bausatz:** Keyestudio 48-in-1 Sensor-Kit  
> **Platine:** Keyestudio V4.0 / mit Arduino Uno kompatible ATmega328P-Platine

![Projekt 19: Analoge Temperatur Abbildung](../media/8269d6536e383bcc592da1ae98bc3661.png)

## Beschreibung

Dieses Modul basiert auf dem Funktionsprinzip eines Thermistors (Widerstand ändert sich mit Temperaturänderungen in der Umgebung).

Es kann Temperaturänderungen in der Umgebung erfassen und die Daten an die analogen IOs des Arduino-Boards senden.

Alles, was wir tun müssen, ist die Ausgangsdaten des Sensors mittels einfacher Programmierung in Grad Celsius umzuwandeln und schließlich auf dem Monitor anzuzeigen.

Es ist sowohl praktisch als auch effektiv und wird daher häufig in Gartenanwendungen, Hausalarmsystemen und anderen Geräten eingesetzt.

## Spezifikation

- Schnittstellentyp: analog

- Betriebsspannung: 5V

- Temperaturbereich: -55℃～315℃

- Größe: 30\*20mm

- Gewicht: 3g

## Anschlussdiagramm

Zuerst müssen Sie vor dem Anschluss die folgenden Teile vorbereiten:

- V4.0-Platine\*1

- Analoger Temperatursensor\*1

- USB-Kabel\*1

- Jumper-Kabel\*3

Verbinde den S-Pin des Moduls mit dem analogen A0 des V4.0-Boards, verbinde den negativen Pin mit dem GND-Anschluss und den positiven Pin mit dem 5V-Anschluss.

![Anschlussdiagramm Abbildung](../media/330d37f05ac235a850d06726284243a5.jpeg)

## Beispielcode

Kopiere und füge den folgenden Code in die Arduino-Software ein.

```c
////////////////////////////////////////////////////////////////////
void setup()
{Serial.begin(9600);
}
// the loop routine runs over and over again forever:
void loop()
{int sensorValue = analogRead(A0);
Serial.println(sensorValue);
  delay(1); }
////////////////////////////////////////////////////////////////////
```

Der obige Code gibt nur den analogen Wert aus.

Sie können sehen, dass sich der analoge Wert entsprechend der Temperaturänderung in der Umgebung ändert. Aber das ist nicht sehr deutlich.

Lösen wir das mit folgender Gleichung. Laden Sie dann den untenstehenden Code auf das Arduino-Board hoch. Der vom seriellen Port gelesene Wert entspricht ungefähr der tatsächlichen Temperatur. z. B.: Die aktuelle Temperatur beträgt 30°C.

```c
////////////////////////////////////////////////////////////////////
#include <math.h>
void setup()
{
   Serial.begin(9600);
}
void loop()
{
  double val=analogRead(0);
  double fenya=(val/1023)*5;
  double r=(5-fenya)/fenya*4700;
  Serial.println( 1/(  log(r/10000) /3950 + 1/(25+273.15))-273.15);
  delay(1000);
}
////////////////////////////////////////////////////////////////////
```

## Beispielergebnis

![Beispielergebnis Abbildung](../media/9ae4e8962bf9d46ceeb3ca0c2e560f43.png)

Nachdem die Verkabelung wie oben vorgenommen und die Stromversorgung eingeschaltet wurde und der Code erfolgreich auf das Board hochgeladen wurde, öffnen Sie den seriellen Monitor der Arduino-IDE; Sie werden den aktuellen Temperaturwert sehen.

![Beispielergebnis Abbildung](../media/005b4c639460eba8158f99637f03686b.jpeg)

---
