# Les 28: Analoge keramische trilling

> **Set:** Keyestudio 48-in-1 Sensorset  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P-bord

![Analoge keramische trillingssensormodule](../media/2cf5c2793157816a2346a730ad064955.jpeg)

## Beschrijving

Deze trillingssensor is gebaseerd op een piëzo-elektrische keramische chip voor analoge trilling. Hij maakt gebruik van het anti-omzettingsproces waarbij de piëzo-elektrische keramische trilling elektrische signalen genereert. Wanneer de keramische piëzochip trilt, zal de signaalaansluiting van de sensor elektrische signalen produceren.

De sensor kan worden gebruikt met een Arduino-dedicated sensor shield, en de analoge poort van de Arduino kan zwakke trilsignalen waarnemen, zodat hij interactieve toepassingen met trillingen kan aansturen, zoals een elektronische drum.

Sluit de trillingssensor aan op de analoge poort A0 van het V4.0-bord. Wanneer je de sensor in verschillende mate laat trillen, zie je verschillende uitvoerwaarden weergegeven in de seriële monitor van de Arduino-software.

## Specificatie

- Voedingsspanning: 3.3V tot 5V

- Werkstroom：\<1mA

- Werktemperatuurbereik：－10℃～＋70℃

- Uitgangssignaal：analoog signaal

## Aansluitschema

Eerst moet je de volgende onderdelen voorbereiden voordat je aansluit:

- V4.0-bord\*1

- trillingssensor\*1

- USB-kabel\*1

- Jumperdraad\*3

Verbind de S-pin van de module met analoog A0 van het V4.0-bord, verbind de negatieve pin met de GND-aansluiting, en de NC-pin met de 5V-aansluiting.

![Aansluitschema illustratie](../media/92fce2d45b05876a7928070bd2b137da.jpeg)

## Voorbeeldcode

Kopieer en plak onderstaande code in de Arduino-software.

```c
///////////////////////////////////////////////////////////
void setup()
{
Serial.begin(9600); //Open the serial to set the baud rate as 9600bps
}
void loop()
{
int val;
val=analogRead(0); //Connect the sensor to analog interface A0
Serial.print("Vibration is ");
Serial.println(val,DEC);//Print the analog value read on serial port
delay(100);
}
///////////////////////////////////////////////////////////
```

## Voorbeeldresultaat

![Voorbeeldresultaat illustratie](../media/e21152ca9f30274fcc658091f76f7044.png)

Bedraad volgens het bovenstaande schema en upload de code, open vervolgens de seriële monitor en stel de baudrate (baud-snelheid) in op 9600.

Wanneer je de keramische chip laat trillen, zie je de gegevens veranderen zoals in de onderstaande afbeelding.

![Voorbeeldresultaat illustratie](../media/4be72e831696d59b36082aa45d77a04d.jpeg)

---
