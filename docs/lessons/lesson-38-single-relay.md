# Les 38: Enkele relais

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P bord

![Project 38: Enkele relais illustratie](../media/e0b4485cfd4ccebd974d81f19239dde3.png)

## Introductie

Deze enkele relaismodule kan worden gebruikt in interactieve projecten. Deze module gebruikt een SONGLE 5v relais van hoge kwaliteit. Hij kan ook worden gebruikt om verlichting, elektrische en andere apparaten te schakelen.

Het modulaire ontwerp maakt het eenvoudig te gebruiken met een Arduino-bord. Het kan worden aangestuurd via een digitale IO-poort, zoals elektromagnetische kleppen, lampen, motoren en andere hoge stroom- of hoge spanningsapparaten.

## Specificatie

- Type: Digitaal

- Nominale stroom: 10A (NO) 5A (NC)

- Maximale schakelspanning: 150VAC 24VDC

- Digitale interface

- Controlesignaal: TTL-niveau

- Nominale belasting: 8A 150VAC (NO), 10A 24VDC (NO), 5A 250VAC (NO/NC), 5A 24VDC (NO/NC)

- Maximale schakelvermogen: AC1200VA DC240W (NO), AC625VA DC120W (NC)

- Contactwerktijd: 10ms

## Aansluitschema

Bereid eerst de volgende onderdelen voor voordat je gaat aansluiten.

- V4.0 Bord\*1

- Relaismodule\*1

- LED-module \*1

- Steekbord \*1

- USB-kabel\*1

- Dupont-kabel\*9

Hier gebruiken we de enkele relaismodule om een LED-module aan of uit te schakelen.

Voor de relaismodule, sluit de Signaalpin aan op Digitale poort 8 van het V4.0-bord, verbind vervolgens de positieve pin met de anode-rij van het steekbord, leid die rij naar de 5V-poort van het V4.0-bord. Verbind de negatieve pin met de kathode-rij van het steekbord, leid die rij naar de GND-poort van het V4.0-bord.

Voor de LED-module, sluit de Signaalpin aan op één klemblok van de relaismodule, een ander klemblok van het relais is verbonden met Digitale poort 13 van het V4.0-bord. Verbind de positieve pin met de anode-rij en de negatieve pin met de kathode-rij van het steekbord.

![Aansluitschema illustratie](../media/21cf9b1d5f0843230ee516a0a8be77e1.jpeg)

## Voorbeeldcode

Kopieer en plak de onderstaande code in de Arduino-software.

```c
///////////////////////////////////////////////////////////////
 int Relay = 8;
  void setup()
{
  pinMode(13, OUTPUT);         //Set Pin13 as output
  digitalWrite(13, HIGH);     //Set Pin13 High
  pinMode(Relay, OUTPUT);     //Set Pin3 as output
}
void loop()
{
          digitalWrite(Relay, HIGH);   //Turn off relay
          delay(2000);
          digitalWrite(Relay, LOW);    //Turn on relay
          delay(2000);
}
///////////////////////////////////////////////////////////////
```

## Voorbeeldresultaat

![Voorbeeldresultaat illustratie](../media/c751be64bd8acd8c6114598b89586cfa.png)

Deze relaismodule is actief bij HIGH-niveau.

Sluit alles goed aan, zet de voeding aan, upload dan de bovenstaande code naar het bord; je zult zien dat het relais twee seconden ingeschakeld is（ON verbonden, NC losgekoppeld）, daarna twee seconden uitgeschakeld is（NC gesloten,ON losgekoppeld）, herhaald en cyclisch.

Wanneer het relais is ingeschakeld, is de externe LED aan. Als het relais is uitgeschakeld, is de externe LED uit.

---
