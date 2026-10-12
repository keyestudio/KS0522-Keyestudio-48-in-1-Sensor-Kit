# Les 21: Fotocel

> **Set:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P-bord

![Project 21: Fotocel illustratie](../media/8eed60793fd64a7c0b9a9b2a2fc1ef67.png)

## Beschrijving

Een fotocel komt vaak voor in ons dagelijks leven en wordt voornamelijk gebruikt in intelligente schakelaars, maar ook in algemeen elektronisch ontwerp. Om het eenvoudiger en effectiever te maken, leveren we de bijbehorende modules.

De fotocel is een halfgeleider. Hij heeft kenmerken zoals hoge gevoeligheid, snelle reactie, spectrale karakteristiek en consistentie van de R-waarde, waardoor hij een hoge stabiliteit en betrouwbaarheid behoudt in extreme omgevingen, zoals hoge temperaturen en hoge luchtvochtigheid.

Hij wordt veel gebruikt in automatische schakelaars voor toepassingen zoals camera's, tuin-zonnenlampen, gazonverlichting, gelddetectoren, kwartsuurwerken, muziekbekers, cadeauboxen, mini-nachtlampjes, geluids- en lichtgestuurde schakelaars, enz.

## Specificatie

- Interface type: analoog

- Werkspanning: 5V

- Afmetingen: 30*20mm

- Gewicht: 3g

## Aansluitschema

Verbind de S-pin van de module met Analoge A0 van het V4.0-bord, verbind de negatieve pin met de GND-poort en de positieve pin met de 5V-poort.

![Aansluitschema illustratie](../media/28a1990cd088d6f0301f02d217cef301.jpeg)

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

![Voorbeeldresultaat illustratie](../media/78268e9cb1dbc127e7ae3299d3a35a45.png)

Als de bedrading klaar is en het bord van stroom is voorzien, upload je de code. Open vervolgens de seriële monitor; als je de fotocel op de sensor met je hand bedekt, zie je dat de analoge waarde afneemt.

![Voorbeeldresultaat illustratie](../media/85621deb4c66d6e53697cd0ef90cb6e2.jpeg)

---
