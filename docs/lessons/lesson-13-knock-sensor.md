# Les 13: Klopsensor

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Board:** Keyestudio V4.0 / Arduino Uno-compatibele ATmega328P board

![Project 13: Klopsensor illustratie](../media/cef729e5b57059bc14518b0e2fdd2817.png)

## Beschrijving

Deze module is een klopsensor. Wanneer je erop klopt, kan hij een momentair signaal afgeven.

Je kunt het combineren met een Arduino voor interessante experimenten, bijvoorbeeld een elektronische drum.

## Specificaties

- Werkspanning: 5V

- Afmeting: 30\*20mm

- Gewicht: 3g

## Aansluitschema

Bereid eerst de volgende onderdelen voor voordat je aansluit:

- V4.0 Board\*1

- Klopsensor \*1

- USB-kabel\*1

- Jumperdraad\*3

Verbind de S pin van de module met Digital 3 van het V4.0 board, verbind de negatieve pin met de GND-poort en de positieve pin met de 5V-poort.

![Aansluitschema illustratie](../media/1b9c27f145275e7a38d06763114f1847.jpeg)

## Voorbeeldcode

Kopieer en plak onderstaande code in de Arduino-software.

```c
////////////////////////////////////////////////////////////////////
int Led=13;//define LED interface
int Shock=3;//define knock sensor interface
int val;//define digital variable val
void setup()
{
pinMode(Led,OUTPUT);//define LED to be output interface
pinMode(Shock,INPUT);//define knock sensor to be output interface
}
void loop()
{
val=digitalRead(Shock);//read the value of interface3 and evaluate it to val
if(val==HIGH)//when the knock sensor detect a signal, LED will be flashing
{
digitalWrite(Led,LOW);
}
else
{
digitalWrite(Led,HIGH);
}
}
////////////////////////////////////////////////////////////////////
```

![Voorbeeldcode illustratie](../media/c3fc14de7267b517a739268ed5b88674.png)

## Voorbeeldresultaat

Als de bedrading zoals hierboven is gemaakt en de voeding is aangesloten en je hebt de code succesvol geüpload, en je klopt op de sensor, zie je dat zowel de D13 led op het V4.0 board als de D1 led op de sensor aangaan.

---
