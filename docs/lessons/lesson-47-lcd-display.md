# Les 47: LCD-display

> **Kit:** Keyestudio 48-in-1 sensorkit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P-bord

![Project 47: LCD-display illustratie](../media/1aa1fd551e180d013633c1fe857c24a6.jpeg)

## Beschrijving

In dit project gaan we dit 0802 LCD-display aansturen om tekst weer te geven in combinatie met het V4.0-bord.

De weergavecapaciteit van de LCD is 8x2 tekens en de bedrijfsvoering van de chip is 4.5～5.5V.

Er zijn twee aansluitmethoden voor het weergeven van tekst op de 0802 LCD: respectievelijk 4-bit en 8-bit aansluiting.

Zie de gerelateerde uitleg hieronder.

## Uitleg van de interfaces

| **Aansluiting** | **Pin** | **Uitleg**                                                    |
| :-----------: | :-----: | ------------------------------------------------------------ |
|       1       |   VSS   | Logische voedingsmassa                                       |
|       2       |   VDD   | Logische voeding                                             |
|       3       |   V0    | LCD instelbare spanning, verbinden met de middenpen van een 10K potentiometer |
|       4       |   RS    | Data\\ Commando optie                                        |
|       5       |   RW    | lezen\\schrijven optie                                       |
|       6       |    E    | Inschakelen lezen\\schrijven, actief bij HIGH, vallende flank vergrendelt de data |
|       7       |   DB0   | Data in-/uitgangspin                                         |
|       8       |   DB1   | Data in-/uitgangspin                                         |
|       9       |   DB2   | Data in-/uitgangspin                                         |
|      10       |   DB3   | Data in-/uitgangspin                                         |
|      11       |   DB4   | Data in-/uitgangspin                                         |
|      12       |   DB5   | Data in-/uitgangspin                                         |
|      13       |   DB6   | Data in-/uitgangspin                                         |
|      14       |   DB7   | Data in-/uitgangspin                                         |
|      15       |  LED-A  | Positieve voedingsaansluiting van de achtergrondverlichting |
|      16       |  LED-K  | Negatieve voedingsaansluiting van de achtergrondverlichting |

## Benodigde hardware

Allereerst moet je de volgende onderdelen voorbereiden:

- V4.0-bord × 1
- 0802 LCD × 1
- Draaipotentiometer × 1
- Breadboard × 1
- USB-kabel × 1
- Jumperdraden, indien nodig
- Dupont-draden, indien nodig

## Aansluitschema

## 4-bit aansluiting

![Illustratie 4-bit aansluiting](../media/6b3c862d4b36726275b67b747e6d5df3.jpeg)

## 8-bit aansluiting

![Illustratie 8-bit aansluiting](../media/97a92aff5ba45d0f7daaca6307b9a5fd.png)

## Broncode

## Voor 4-bit aansluiting

```C
//////////////////////////////////////////////////////////
#include <LiquidCrystal.h>
// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(11, 12, 6, 7, 4, 5);

void setup() {
  // set up the LCD's number of columns and rows:
  lcd.begin(8, 2);
  // Print a message to the LCD.
  lcd.setCursor(0, 0);
  lcd.print(" Hello");
  lcd.setCursor(0, 1);
  lcd.print(" world!");
}

void loop() {
}
//////////////////////////////////////////////////////////
```

## Voor 8-bit aansluiting

```C
#include <LiquidCrystal.h>

// RS, RW, Enable, D0, D1, D2, D3, D4, D5, D6, D7
LiquidCrystal lcd(12, 11, 2, 3, 4, 5, 6, 7, 8, 9, 10);

void setup() {
  lcd.begin(8, 2);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("ABCDEFGH");
  lcd.setCursor(0, 1);
  lcd.print("12345678");
}

void loop() {
  // The 8-bit display remains static after setup.
}
```

## Voorbeeldresultaat

Sluit alles goed aan, zet de voeding aan, upload de bovenstaande code naar het bord, stel de achtergrondverlichting van de LCD af door de potentiometer te draaien; uiteindelijk zie je de tekens op het LCD-scherm.

Als je de 4-bit aansluiting gebruikt, zou je op de eerste regel "Hallo" en op de tweede regel "wereld!" op het LCD moeten zien, zoals hieronder weergegeven.

![Illustratie voorbeeldresultaat](../media/7d2763d65677d2925902ffcc65bf1b12.png)

Als je de 8-bit aansluiting gebruikt, zie je andere tekens op het LCD weergegeven, zoals hieronder.

![Illustratie voorbeeldresultaat](../media/61002a13397f8041574b375b0032da26.png)

---
