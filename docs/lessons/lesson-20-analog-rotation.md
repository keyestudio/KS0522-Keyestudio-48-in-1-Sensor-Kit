# Les 20: Analoge rotatie

> **Kit:** Keyestudio 48-in-1 sensorkit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P-bord

![Project 20: illustratie analoge rotatie](../media/7a7fffa705c4a50e87455e6d378eb837.png)

## Beschrijving

Deze analoge rotatiesensor is compatibel met Arduino. Hij is gebaseerd op een potentiometer. De uitgangsspanning wordt onderverdeeld in 1024 stappen en is eenvoudig aan te sluiten op een Arduino met onze sensorshield.

Gecombineerd met andere sensoren kun je er interessante projecten mee maken door de analoge waarde van de IO-poort uit te lezen.

## Specificaties

- Voedingsspanning: 3.3V tot 5V

- Interface: Analoog

- Afmetingen: 30*20mm

- Gewicht: 8g

## Aansluitschema

Verbind de S-pin van de module met analoog A0 van de V4.0-bord, verbind de negatieve pin met GND en de positieve pin met 5V.

![Aansluitschema illustratie](../media/f8a0c2cca0f3d0935ce0c9a0c4dbe59e.jpeg)

## Voorbeeldcode

Kopieer en plak de onderstaande code in de Arduino-software.

```c
////////////////////////////////////////////////////////////////////
void setup()
{
  Serial.begin(9600); //Set serial baud rate to 9600 bps
}
void loop()
{
int val;
val=analogRead(0);//Read rotation sensor value from analog 0
Serial.println(val,DEC);//Print the value to serial port
delay(100);
}
////////////////////////////////////////////////////////////////////
```

## Voorbeeldresultaat

![Voorbeeldresultaat illustratie](../media/bae047449c10c99449c35a14b22d759c.png)

Als de bedrading klaar is en de voeding is ingeschakeld, upload je de code. Open vervolgens de seriële monitor en stel de baudrate in op 9600; je zult dan de analoge waarde zien. Draai aan de knop van de rotatiesensor en de waarde verandert binnen het bereik 0-1023. Zie hieronder.

![Voorbeeldresultaat illustratie](../media/bc7b15c3245b7cfd91b0ef4b0aeb8e7e.jpeg)

---
