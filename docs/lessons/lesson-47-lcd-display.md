# Lektion 47: LCD-Anzeige

> **Bausatz:** Keyestudio 48-in-1 Sensorsatz  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatibles ATmega328P-Board

![Projekt 47: LCD-Anzeige Abbildung](../media/1aa1fd551e180d013633c1fe857c24a6.jpeg)

## Beschreibung

In diesem Projekt werden wir dieses 0802-LCD verwenden, um Text mit dem V4.0-Board anzuzeigen.

Die Anzeige des LCD hat eine Kapazität von 8x2 Zeichen, und die Betriebsspannung des Chips beträgt 4.5～5.5V.

Es gibt zwei Anschlussarten für das 0802-LCD zur Textanzeige, nämlich 4-Bit- und 8-Bit-Verbindung.

Siehe die nachstehende Erklärung.

## Schnittstellen-Erklärung

| **Schnittstelle** | **Pin** | **Erklärung**                                              |
| :-----------: | :-----: | ------------------------------------------------------------ |
|       1       |   VSS   | Logik-Masse                                                 |
|       2       |   VDD   | Logik-Spannungsversorgung                                   |
|       3       |   V0    | Einstellbare LCD-Spannung, mit dem mittleren Anschluss des 10K-Potentiometer verbinden |
|       4       |   RS    | Daten\\ Befehlsauswahl                                       |
|       5       |   RW    | Lesen\\Schreiboption                                        |
|       6       |    E    | Aktiviert Lesen\\Schreiben; bei HIGH aktiviert, bei fallender Flanke werden die Daten übernommen |
|       7       |   DB0   | Daten Ein-/Ausgangspin                                       |
|       8       |   DB1   | Daten Ein-/Ausgangspin                                       |
|       9       |   DB2   | Daten Ein-/Ausgangspin                                       |
|      10       |   DB3   | Daten Ein-/Ausgangspin                                       |
|      11       |   DB4   | Daten Ein-/Ausgangspin                                       |
|      12       |   DB5   | Daten Ein-/Ausgangspin                                       |
|      13       |   DB6   | Daten Ein-/Ausgangspin                                       |
|      14       |   DB7   | Daten Ein-/Ausgangspin                                       |
|      15       |  LED-A  | Positive Klemme der Hintergrundbeleuchtung                  |
|      16       |  LED-K  | Negative Klemme der Hintergrundbeleuchtung                  |

## Benötigte Hardware

Zuerst müssen Sie die folgenden Teile vorbereiten:

- V4.0-Platine × 1
- 0802 LCD × 1
- Drehpotentiometer × 1
- Steckbrett × 1
- USB-Kabel × 1
- Jumperkabel, nach Bedarf
- Dupont-Kabel, nach Bedarf

## Anschlussdiagramm

## 4-Bit-Verbindung

![4-Bit-Verbindung Abbildung](../media/6b3c862d4b36726275b67b747e6d5df3.jpeg)

## 8-Bit-Verbindung

![8-Bit-Verbindung Abbildung](../media/97a92aff5ba45d0f7daaca6307b9a5fd.png)

## Quellcode

## Für 4-Bit-Verbindung

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

## Für 8-Bit-Verbindung

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

## Beispielergebnis

Gut verdrahten, mit Strom versorgen, den obigen Code auf das Board hochladen, die Hintergrundbeleuchtung des LCD über das Drehen am Potentiometer einstellen — schließlich sollten die Zeichen auf dem LCD-Bildschirm angezeigt werden.

Wenn Sie die 4-Bit-Verbindung verwenden, sollte das LCD in der ersten Zeile "Hallo" und in der zweiten Zeile "Welt!" anzeigen, wie unten dargestellt.

![Beispielergebnis Abbildung](../media/7d2763d65677d2925902ffcc65bf1b12.png)

Bei Verwendung der 8-Bit-Verbindung werden andere Zeichen auf dem LCD angezeigt, wie unten gezeigt.

![Beispielergebnis Abbildung](../media/61002a13397f8041574b375b0032da26.png)

---
