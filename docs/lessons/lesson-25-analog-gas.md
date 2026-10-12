# Les 25: Analoog gas

> **Kit:** Keyestudio 48-in-1 sensorkit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P board

![Project 25: Analoog gas illustratie](../media/36f00d2a934c497f390b49c4113c7c04.png)

## Beschrijving

Deze analoge gassensor MQ2 wordt gebruikt in apparatuur voor het detecteren van gaslekken, zowel in consumentenelektronica als in de industrie. Deze sensor is geschikt voor het detecteren van LPG, i-butaan, propaan, methaan, alcohol, waterstof en rook.

Het detectiebereik van deze sensor is zeer ruim en hij heeft een hoge gevoeligheid en een snelle respons.

Daarnaast kan de gevoeligheid worden aangepast door de potentiometer op de sensor te verdraaien.

## Specificatie

- Voedingsspanning: 5V

- Interface-type: Analoog

- Eenvoudig stuurcircuit

- Stabiel en lange levensduur

## Aansluitschema

Verbind de A0-pin van de module met Analog A0 van het V4.0-board, verbind de GND-pin met de GND-poort en de VCC-pin met de 5V-poort.

![Aansluitschema illustratie](../media/7b2cdff9418f79b2e9e566ce61a7966a.jpeg)

## Voorbeeldcode

Kopieer en plak onderstaande code in de Arduino-software.

```c
////////////////////////////////////////////////////////////////////
//Arduino Sample Code
void setup()
{
  Serial.begin(9600); //Set serial baud rate to 9600 bps
}
void loop()
{
int val;
val=analogRead(0);//Read Gas value from analog 0
Serial.println(val,DEC);//Print the value to serial port
delay(100);
}

////////////////////////////////////////////////////////////////////
```

## Voorbeeldresultaat

![Voorbeeldresultaat illustratie](../media/d440553d52e043d7a91928882d877dd1.png)

Als de bedrading klaar is en de voeding is aangesloten, upload je de code, open je de seriële monitor en stel je de baudrate in op 9600; je zult de analoge waarde zien. Bij het detecteren van gas zal de waarde veranderen.

![Voorbeeldresultaat illustratie](../media/cbf777feb6231d76347bc632f87d0e8e.jpeg)

---
