# Les 18: PIR-bewegingssensor

> **Set:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P bord

![Project 18: PIR-bewegingssensor illustratie](../media/ce608db25742f19fdf6eceda756a59d9.png)

## Beschrijving

Pyro-elektrische infrarood bewegingssensor kan infraroodsignalen detecteren van een bewegend persoon of dier, en geeft schakelsignalen uit.

Hij kan toegepast worden in verschillende situaties om de beweging van het menselijk lichaam te detecteren.

Conventionele pyro-elektrische infraroodsensoren vereisen een lichaams-pyro-elektrische infrarooddetector, professionele chip en complexe randcircuits, waardoor de grootte veel groter is, met complexe schakelingen en lagere betrouwbaarheid.

Nu brengen we deze nieuwe pyro-elektrische infrarood bewegingssensor op de markt, speciaal ontworpen voor Arduino.

Hij gebruikt een geïntegreerde digitale lichaams-pyro-elektrische infraroodsensor, met kleinere afmetingen, hogere betrouwbaarheid, lager stroomverbruik en eenvoudigere randcircuits.

## Specificatie

- Ingangsspanning: 3.3 \~ 5V, maximum 6V

- Werkstroom: 15uA

- Werktemperatuur: -20 \~ 85 ℃

- Uitgangsspanning: Hoog 3V, Laag 0V

- Uitgangsvertraging (Hoog niveau): Ongeveer 2.3 tot 3 seconden

- Detectiehoek: 100 °

- Detectieafstand: 7 meter

- Uitgangs-LED (als uitgang HIGH is, brandt deze)

- Limietstroom voor pin: 100mA

- Formaat: 30*20mm

- Gewicht: 4g

## Aansluitschema

Bereid eerst de volgende onderdelen voor voordat je gaat aansluiten:

- V4.0-bord*1

- PIR bewegingssensor*1

- USB-kabel*1

- Jumperkabel*3

Verbind de S-pin van de module met Digital 3 van het V4.0-bord, verbind de negatieve pin met de GND-poort, de positieve pin met de 5V-poort.

![Aansluitschema illustratie](../media/01970d510c03a8c7aa3ef0c13ea70cff.jpeg)

## Voorbeeldcode

Kopieer en plak de onderstaande code in de Arduino-software.

```c
////////////////////////////////////////////////////////////////////
byte sensorPin = 3;
byte indicator = 13;
void setup()
{
  pinMode(sensorPin,INPUT);
  pinMode(indicator,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  byte state = digitalRead(sensorPin);
  digitalWrite(indicator,state);
  if(state == 1)Serial.println("Somebody is in this area!");
  else if(state == 0)Serial.println("No one!");
  delay(500);
}
////////////////////////////////////////////////////////////////////
```

## Voorbeeldresultaat

Na het aansluiten en inschakelen en het succesvol uploaden van de code: als de sensor iemand in de buurt detecteert, zal de D13-indicator op het V4.0-bord oplichten en wordt "Iemand is in dit gebied!" weergegeven in de seriële monitor van de Arduino-software.

Als er geen beweging wordt gedetecteerd, blijft de D13-indicator op het V4.0-bord uit en wordt "Niemand!" weergegeven in de seriële monitor.

![Voorbeeldresultaat illustratie](../media/e25d28654311fa7820a1886a285353e5.png)

![Voorbeeldresultaat illustratie](../media/9b6209c8ce5b4be73f8378d21b639d28.jpeg)

---
