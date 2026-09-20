# Lektion 40: Temperatur- und Feuchtigkeitsanzeige

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P-Platine

![Projekt 40: Temperatur- und Feuchtigkeitsanzeige Illustration](../media/e164737761b08de30da9358b47511d62.png)

## Einführung

Dieser DHT11-Sensor bietet kalibrierte digitale Signalausgabe in einem kombinierten Temperatur- und Feuchtesensor. Seine Technologie gewährleistet hohe Zuverlässigkeit und ausgezeichnete Langzeitstabilität.

Auf dem Sensor ist ein leistungsfähiger 8-Bit-Mikrocontroller integriert. Der Sensor enthält ein resistives Element und einen NTC-Temperaturfühler zur Feuchtemessung.

Er zeichnet sich durch hohe Qualität, schnelle Reaktionszeit, Störfestigkeit und ein gutes Preis-Leistungs-Verhältnis aus.

Jeder DHT11-Sensor verfügt über äußerst präzise Kalibrierungsdaten aus einer Feuchte-Kalibrierkammer. Die Kalibrierkoeffizienten sind im OTP-Programmspeicher abgelegt; interne Sensoren erkennen Signale während des Betriebs und nutzen diese Kalibrierkoeffizienten.

Eine einadrige serielle Schnittstelle ist integriert, was die Handhabung schnell und einfach macht. Kompakte Bauform, geringer Energieverbrauch und eine Signalübertragungsreichweite von bis zu 20 Metern machen ihn vielseitig einsetzbar, auch in anspruchsvollen Anwendungen.

## Technische Daten

- Versorgungsspannung: +5 V

- Temperaturbereich: 0–50 °C, Messfehler ±2 °C

- Feuchtigkeit: 20–90 % RH, Messfehler ±5 % RH

- Schnittstelle: Digital

## Anschlussdiagramm

Bereiten Sie vor dem Testen zunächst die folgenden Teile vor.

- V4.0 Platine\*1

- DHT11-Sensor\*1

- USB-Kabel\*1

- Jumperkabel\*3

Befolgen Sie dann das Anschlussdiagramm: Verbinden Sie den Signal-Pin des Sensors mit dem Digital 4-Port der V4.0-Platine, den negativen Pin mit GND und den positiven Pin mit 5V.

![Anschlussdiagramm Illustration](../media/d10a0556ea9e4a8314ee21f8f58ff236.jpeg)

## Beispielcode

Bitte laden Sie zuerst die [DHT11Lib](https://github.com/RobTillaart/Arduino/tree/master/libraries/DHTlib) herunter. Oder [besuchen Sie die Website](http://playground.arduino.cc/Main/DHTLib)

Kopieren Sie den folgenden Code und fügen Sie ihn in die Arduino-Software ein.

```c
#include <dht.h>

dht DHT;
#define DHT11_PIN 4

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT11 test"));
  Serial.print(F("DHTlib version: "));
  Serial.println(DHT_LIB_VERSION);
  Serial.println(F("Status,Humidity (%),Temperature (C)"));
}

void loop() {
  const int status = DHT.read11(DHT11_PIN);

  switch (status) {
    case DHTLIB_OK:
      Serial.print(F("OK, "));
      break;
    case DHTLIB_ERROR_CHECKSUM:
      Serial.print(F("Checksum error, "));
      break;
    case DHTLIB_ERROR_TIMEOUT:
      Serial.print(F("Timeout error, "));
      break;
    default:
      Serial.print(F("Unknown error, "));
      break;
  }

  Serial.print(DHT.humidity, 1);
  Serial.print(F(", "));
  Serial.println(DHT.temperature, 1);
  delay(2000);
}
```

## Beispielergebnis

Verdrahten Sie alles korrekt und laden Sie den obigen Code auf die V4.0-Platine hoch.

![Beispielergebnis Illustration](../media/cdbb75de748e3e2eb6f709b8f469193d.png)

Öffnen Sie dann den seriellen Monitor und stellen Sie die Baudrate auf 9600 ein; schließlich sehen Sie die aktuellen Temperatur- und Feuchtigkeitswerte.

![Beispielergebnis Illustration](../media/dffe8c9a0b348f7f4f12cbfe95c090f3.jpeg)

---
