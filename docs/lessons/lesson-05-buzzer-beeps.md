# Les 05: Zoemerpiepjes

> **Set:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P-bord

![Project 5: Zoemerpiepjes illustratie](../media/88c349b0602dfa2e166faabc13cb2f20.png)

## Beschrijving

Hier is de eenvoudigste geluidsmodule. Je kunt deze aansturen met hoge/lage niveaus. Door de frequentie te veranderen, kan het zoemen verschillende geluiden produceren.

Deze module wordt veel gebruikt in dagelijkse apparaten zoals PC, koelkast, telefoons, enz.

Bovendien kun je met deze kleine maar nuttige module veel interessante interactieve projecten maken. Probeer het gewoon!! Je zult het elektronische geluid dat het voortbrengt erg fascinerend vinden.

## Specificaties

- Werkspanning: 3.3-5v

- Interface-type: digitaal

- Afmetingen: 30*20mm

- Gewicht: 4g

## Aansluitschema

Sluit de S-pin van de module aan op Digital 3 van het V4.0-bord, sluit de negatieve pin aan op GND, en de positieve pin op 5V.

![Aansluitschema illustratie](../media/173f2e9a828b0b20d76dc07de57892c1.jpeg)

## Voorbeeldcode

Kopieer en plak de onderstaande code in de Arduino-software.

```c
////////////////////////////////////////////////////////////////////
int buzzPin =3;    //Connect Buzzer on Digital Pin3
 void setup()
 {
  pinMode(buzzPin, OUTPUT);
}
 void loop()
{
  digitalWrite(buzzPin, HIGH);
  delay(1);
  digitalWrite(buzzPin, LOW);
  delay(1);
}
////////////////////////////////////////////////////////////////////
```

## Voorbeeldresultaat

Na het uploaden van de code naar het bord zal de zoemer geluid maken.

![Voorbeeldresultaat illustratie](../media/109e3287bff29d1d1fb88369d6705ad3.png)

---
