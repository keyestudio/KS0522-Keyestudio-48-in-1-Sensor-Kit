# Les 27: Stoomsensor

> **Set:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P-bord

![Project 27: stoomsensor illustratie](../media/d19ac9430f793cdbedde891ee92671e7.jpeg)

## Beschrijving

De stoomsensor is een analoge sensor en kan gebruikt worden als eenvoudige regenwaterdetector en vloeistofniveauschakelaar. Wanneer de vochtigheid op het oppervlak van deze sensor toeneemt, zal de uitgangsspanning stijgen.

Let op: de aansluitingsdelen zijn niet waterdicht, plaats ze daarom niet in water.

## Parameters

- Werkspanning: 3.3V of 5V

- Werkstroom: \<20mA

- Werktemperatuurbereik: －10℃～＋70℃

- Interface-type: Analoge signaaluitgang

## Pindefinitie

- S-pin: voor signaaluitgang

- Positieve pin (+): voor voedingsspanning (VCC)

- Negatieve pin (-): voor massa (GND)

## Aansluitschema

Bereid eerst de volgende onderdelen voor:

- V4.0-bord*1

- Stoomsensor*1

- USB-kabel*1

- Jumperdraad*3

Verbind de S-pin van de module met analoge A0 van het V4.0-bord, verbind de negatieve pin met de GND-aansluiting en de positieve pin met de 5V-aansluiting.

![Aansluitschema illustratie](../media/8fa51466dbc9650dcaa740bce4dd654e.jpeg)

## Voorbeeldcode

Kopieer en plak onderstaande code in de Arduino-software.

```c
////////////////////////////////////////////////////////////////////
void setup()
{
Serial.begin(9600); //open serial port, and set baud rate at 9600bps
}
void loop()
{
int val;
val=analogRead(0); //plug vapor sensor into analog port 0
Serial.print("Moisture is ");
Serial.println(val,DEC); //read analog value through serial port printed
delay(100);
}
////////////////////////////////////////////////////////////////////
```

## Voorbeeldresultaat

![Voorbeeldresultaat illustratie](../media/c4633c5911c042224d187645db4d0588.png)

Bij detectie van verschillende vochtigheidsniveaus geeft de sensor verschillende meetwaarden terug. Zie de volgende afbeelding.

Vanwege de beperkte omstandigheden kun je een druppel water op de sensor plaatsen; de vochtwaarde verandert dan in de seriële monitor van de Arduino-software.

![Voorbeeldresultaat illustratie](../media/80e9b3e19db4bec337f3254545a58e9e.jpeg)

---
