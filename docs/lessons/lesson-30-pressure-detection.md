# Les 30: Drukdetectie

> **Set:** Keyestudio 48-in-1 Sensor Kit  
> **Ontwikkelbord:** Keyestudio V4.0 / Arduino Uno-compatibele ATmega328P-bord

![Project 30: Illustratie drukdetectie](../media/313f11bf4a7f52ac903c78976fe1e633.jpeg)

## Beschrijving

Deze sensor gebruikt nieuw flexibel nano druksensitief materiaal met een ultradunne filmlaag. Hij is waterdicht en heeft de functie drukdetectie.

Wanneer de sensor druk van buiten detecteert, verandert de weerstand van de sensor.

Met dit circuit kan het druksignaal, dat drukveranderingen detecteert, worden omgezet naar het overeenkomstige elektrische signaal.

Op deze manier kunnen we de toestanden van drukveranderingen bepalen door de signaalveranderingen te detecteren.

## Specificaties

- Werkspanning：DC 3.3V—5V

- Bereik：0-10KG

- Dikte：＜0.25mm

- Responsdrempel：＜20g

- Herhaalbaarheid：＜±5.8%（50% belasting）

- Nauwkeurigheid：±2.5%（85% bereikinterval）

- Duurzaamheid：＞100 duizend keer

- Initiële Weerstand：＞100MΩ（geen belasting）

- Reactietijd：＜1ms

- Hersteltijd：＜15ms

- Werktemperatuur：﹣20℃—60℃

## Aansluitschema

Bereid eerst de volgende onderdelen voor voordat u aansluit.

- V4.0-bord\*1

- Druksensor\*1

- USB-kabel\*1

- Jumperdraad\*3

Verbind de S-pin van de module met Analoge A0 van het V4.0-bord, verbind de negatieve pin met de GND-poort, de positieve pin met de 5V-poort.
![Aansluitschema illustratie](../media/3325303180f71db75d9e13acc5036d8f.jpeg)

## Voorbeeldcode

Kopieer en plak de onderstaande code in de Arduino-software.

```c
///////////////////////////////////////////////////////////////
int s_pin = A0;
void setup()
{
  Serial.begin(9600);
  pinMode(s_pin,INPUT);

}

void loop()
{
  Serial.println(analogRead(s_pin));
  delay(500);
}
///////////////////////////////////////////////////////////////
```

## Voorbeeldresultaat

Als de bedrading goed is en de code is geüpload, open dan de seriële monitor in de Arduino-software.

Druk vervolgens stevig met uw hand op de sensor; de op de monitor weergegeven waarde neemt toe.
![Voorbeeldresultaat illustratie](../media/a6c4be8596a0048cb5f3b2f1612241bd.png)

![Voorbeeldresultaat illustratie](../media/e055d2749b14c62b92c22496a3d1f96a.jpeg)

---
