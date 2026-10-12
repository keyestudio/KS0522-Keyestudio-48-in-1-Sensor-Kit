# Les 40: Temperatuur- en Vochtigheidsweergave

> **Set:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibele ATmega328P board

![Project 40: Temperatuur- en Vochtigheidsweergave illustratie](../media/e164737761b08de30da9358b47511d62.png)

## Introductie

Deze DHT11-sensor biedt een gekalibreerde digitale signaaluitgang voor de gecombineerde temperatuur- en vochtigheidssensor. De technologie zorgt voor hoge betrouwbaarheid en uitstekende lange termijnstabiliteit.

Een krachtige 8-bit microcontroller is op de sensor ingebouwd. De sensor bevat een resistief element en een NTC-temperatuurmeetelement voor vochtigheidsdetectie.

Het heeft voordelen zoals uitstekende kwaliteit, snelle respons, storingsbestendigheid en hoge kostenefficiëntie.

Elke DHT11-sensor beschikt over zeer nauwkeurige kalibratiegegevens uit een vochtigheidskalibratiekamer. De kalibratiecoëfficiënten zijn opgeslagen in het OTP-programmageheugen; interne sensoren detecteren signalen tijdens het proces en deze kalibratiecoëfficiënten worden aangeroepen.

Het eendraads seriële interfacesysteem is geïntegreerd, wat het snel en eenvoudig maakt. De kleine afmetingen, het lage energieverbruik en een signaaltransmissieafstand tot 20 meter maken het breed inzetbaar, zelfs voor veeleisende toepassingen.

## Specificatie

- Voedingsspanning: +5 V

- Temperatuurbereik: 0-50 °C, fout ± 2 °C

- Vochtigheid: 20-90% RH, fout ± 5% RH

- Interface: Digitaal

## Aansluitschema

Allereerst moet je de volgende onderdelen voorbereiden voordat je begint met testen.

- V4.0 Board\*1

- DHT11-sensor\*1

- USB-kabel\*1

- Jumper Wire\*3

Volg vervolgens het aansluitschema: verbind de signaalpin van de sensor met de Digital 4-poort van de V4.0 Board, de negatieve pin met GND en de positieve pin met 5V.

![Aansluitschema illustratie](../media/d10a0556ea9e4a8314ee21f8f58ff236.jpeg)

## Voorbeeldcode

Download eerst de [DHT11Lib](https://github.com/RobTillaart/Arduino/tree/master/libraries/DHTlib). Of [bezoek de website](http://playground.arduino.cc/Main/DHTLib)

Kopieer en plak de onderstaande code in de Arduino-software.

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

## Voorbeeldresultaat

Sluit alles goed aan en upload de bovenstaande code naar de V4.0 Board.

![Voorbeeldresultaat illustratie](../media/cdbb75de748e3e2eb6f709b8f469193d.png)

Open vervolgens de seriële monitor en stel de baudrate in op 9600; uiteindelijk zie je de huidige temperatuur- en vochtigheidswaarden.

![Voorbeeldresultaat illustratie](../media/dffe8c9a0b348f7f4f12cbfe95c090f3.jpeg)

---
