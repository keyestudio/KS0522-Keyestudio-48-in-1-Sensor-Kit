# Les 09: Lijnvolgsensor

> **Set:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P-bord

![Project 9: Lijnvolgsensor illustratie](../media/c476ef922ab6a8d31cb68f3ab3fa2ced.png)

## Beschrijving

Deze lijnvolgsensor kan een witte lijn op een zwarte achtergrond of een zwarte lijn op een witte achtergrond detecteren.

De enkele lijnvolguitgang levert een stabiel TTL-signaal voor een nauwkeurigere en stabielere lijndetectie. Een meerkanaalsoptie kan eenvoudig worden gerealiseerd door de benodigde lijnvolg-robotsensoren te installeren.

## Specificatie

1. Voedingsspanning: +5V

2. Bedrijfstroom: \<10mA

3. Bedrijfstemperatuurbereik: 0°C \~ + 50°C

4. Uitgangsinterface: 3-draads interface (1 - signaal, 2 - voeding, 3 - voedingsnegatief)

5. Uitgangsniveau: TTL-niveau

## Aansluitschema

Bereid eerst de volgende onderdelen voor voordat je gaat aansluiten:

- V4.0-bord\*1

- Lijnvolgmodule\*1

- USB-kabel\*1

- Jumperdraad\*3

Verbind de S-pin van de module met Digital 3 van het V4.0-bord, verbind de GND-pin met GND en de V+-pin met 5V.

![Aansluitschema illustratie](../media/6727a1d7d92c3878fc51b8db0502fd14.jpeg)

## Voorbeeldcode

Kopieer en plak de onderstaande code in de Arduino-software.

```c
////////////////////////////////////////////////////////////////////
//Arduino Sample Code
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  Serial.println(digitalRead(3)); // print the data from the sensor
  delay(500);
}
////////////////////////////////////////////////////////////////////
```

## Voorbeeldresultaat

![Voorbeeldresultaat illustratie](../media/af115c59987fee06447790f1740e3203.jpeg)

Nadat de code naar het bord is geüpload, open je de seriële monitor en stel je de baudrate in op 9600; vervolgens zie je de gegevens van de sensor.

---
