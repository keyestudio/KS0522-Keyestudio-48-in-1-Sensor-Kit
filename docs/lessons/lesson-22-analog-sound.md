# Les 22: Analoog geluid

> **Set:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P-bord

![Project 22: Analoog geluid illustratie](../media/a494bbec73f7c8ff91b3133c9d2798a7.jpeg)

## Beschrijving

Een analoge geluidsensor wordt meestal gebruikt om het volumeniveau van omgevingsgeluiden te detecteren. De sensor is voorzien van een potentiometer, zodat je deze kunt draaien om de signaalversterking aan te passen.

Je kunt hem gebruiken om interessante en interactieve projecten te maken, zoals een spraakgestuurde schakelaar.

## Specificaties

- Voedingsspanning: 3.3V tot 5V

- Interface: Analoog

- Afmetingen: 30*20mm

- Gewicht: 4g

## Aansluitschema

Verbind de S-pin van de module met Analoog A0 van het V4.0-bord, verbind de negatieve pin met de GND-poort en de positieve pin met de 5V-poort.

![Aansluitschema illustratie](../media/22e1124550d57015a6d2d5782b8febda.jpeg)

## Voorbeeldcode

Kopieer en plak de onderstaande code in de Arduino-software.

```c
////////////////////////////////////////////////////////////////////
int sensorPin =A0 ;
int value = 0;
void setup()
{
 Serial.begin(9600); }
void loop()
{
 value = analogRead(sensorPin);

Serial.println(value, DEC);

delay(50);
}
////////////////////////////////////////////////////////////////////
```

## Voorbeeldresultaat

Na het aansluiten en inschakelen en het correct uploaden van de code, open de seriële monitor en stel de baudrate in op 9600; je ziet de analoge waarde. Als je naar de microfoon spreekt, zal de waarde toenemen. Zie hieronder.

![Voorbeeldresultaat illustratie](../media/4d753036151413a1bdda3c0b283b8551.png)

---
