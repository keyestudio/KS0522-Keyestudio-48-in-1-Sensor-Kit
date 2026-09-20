# Lektion 48: Punktmatrix

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatibles ATmega328P-Board

![Projekt 48: Punktmatrix Illustration](../media/10e87958bbef207075643ae4f5481457.jpeg)

## Einführung

Was ist besser als eine einzelne LED? Viele LEDs! Eine unterhaltsame Möglichkeit, ein kleines Display zu bauen, ist die Verwendung einer 8x8-Matrix. Dieses Modul verwendet den HT16K33-Chip, um eine 8x8-Punktmatrix anzusteuern.

Es reicht, den I2C-Kommunikationsport des Mikrocontrollers zu verwenden, um die Punktmatrix zu steuern, wodurch mehr Portressourcen des Mikrocontrollers eingespart werden können. Das Matrixmodul wird mit einer 4Pin-Stiftleiste mit 2.54mm Pin-Abstand geliefert.

Sie können das Modul mit Jumper-Kabeln an die Steuerplatine für die Kommunikation anschließen.

Außerdem ist es mit drei DIP-Schaltern ausgestattet. Sie können die Schalter beliebig umlegen, um die I2C-Kommunikationsadresse auszuwählen.

## Die Adresseneinstellungen sind wie unten dargestellt

|   0x70   |          |          |      |   0x71   |          |          |      |   0x72   |          |          |
| :------: | :------: | :------: | ---- | :------: | :------: | :------: | ---- | :------: | :------: | :------: |
| A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |
| 0（AUS） | 0（AUS） | 0（AUS） |      | 1（EIN） | 0（AUS） | 0（AUS） |      | 0（AUS） | 1（EIN） | 0（AUS） |
|          |          |          |      |          |          |          |      |          |          |          |
| **0x73** |          |          |      | **0x74** |          |          |      | **0x75** |          |          |
| A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |
| 1（EIN） | 1（EIN） | 0（AUS） |      | 0（AUS） | 0（AUS） | 1（EIN） |      | 1（EIN） | 0（AUS） | 1（EIN） |
|          |          |          |      |          |          |          |      |          |          |          |
| **0x76** |          |          |      | **0x77** |          |          |      |          |          |          |
| A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |      |          |          |          |
| 0（AUS） | 1（EIN） | 1（EIN） |      | 1（EIN） | 1（EIN） | 1（EIN） |      |          |          |          |

## Technische Details

- Schnittstelle: 4Pin header

- Betriebsspannung: DC 4.5V-5.5V

- Ausgestattet mit drei DIP-Schaltern zur Adressauswahl

- Abmessungen：52mm\*34mm\*11mm

- Gewicht：13.2g

## Anschlussanleitung

Verbinden Sie den SCL-Pin mit dem analogen A5-Anschluss, den SDA-Pin mit dem analogen A4-Anschluss; verbinden Sie den VCC-Pin mit 5V und den GND-Pin mit GND.

![Anschlussanleitung Illustration](../media/e2c09c1a7851f64ad03a027c1aa25a14.jpeg)

## Testcode

Bibliothek herunterladen:

```C
#include <Wire.h>
#include "Adafruit_LEDBackpack.h"
#include "Adafruit_GFX.h"
#ifndef _BV
#define _BV(bit) (1<<(bit))
#endif
Adafruit_LEDBackpack matrix = Adafruit_LEDBackpack();
uint8_t counter = 0;
void setup() {
  Serial.begin(9600);
  Serial.println("HT16K33 test");
  matrix.begin(0x70);  // pass in the address
}
void loop() {
  // paint one LED per row. The HT16K33 internal memory looks like
  // a 8x16 bit matrix (8 rows, 16 columns)
  for (uint8_t i=0; i<8; i++) {
// draw a diagonal row of pixels

    matrix.displaybuffer[i] = _BV((counter+i) % 16) | _BV((counter+i+8) % 16)  ;
  }
  // write the changes we just made to the display
  matrix.writeDisplay();
  delay(100);
 counter++;
  if (counter >= 16) counter = 0;
}
```

**Hinweis:** Bevor Sie den Code kompilieren, denken Sie daran, den Matrix-Bibliotheksordner in das Verzeichnis \\Arduino\\libraries zu legen. Andernfalls schlägt die Kompilierung fehl.

Zum Beispiel: **C:\\Program Files\\Arduino\\libraries**

## Testergebnis

Nachdem der Code auf das Board hochgeladen wurde und das Gerät mit Strom versorgt ist, sollten Sie die 8\*8-Matrix sehen, die ein Herzsymbol anzeigt. Siehe unten.

![Testergebnis Abbildung](../media/4a53bb681a3299be450726255f4d56a2.jpeg)

## Einstellmethode

1. Setzen Sie die Kommunikationsadresse. Siehe das Adressdiagramm.

Der Code ist wie folgt eingestellt.

![Einstellmethode Illustration](../media/187557b09de67c1236bfd6536b0b95ee.png)

![Einstellmethode Illustration](../media/910472d4662d0c1f463f9bedfe4cef74.png)

![Einstellmethode Illustration](../media/165615f73e4c9a49c861f5e17eb333e3.png)

1. Stellen Sie das Anzeigebild ein

Sie können das Anzeigebild im unten gezeigten Code festlegen.

![Einstellmethode Illustration](../media/4a709cb4583c82f469c179dd6b1cfa71.png)

Platzieren Sie das Matrix-Modul wie folgt:

![Einstellmethode Illustration](../media/10e87958bbef207075643ae4f5481457.jpeg)

Konvertieren Sie dann 0x00,0x18,0x24,0x42,0x81,0x99,0x66,0x00 in Binärzahlen:

- `0x00` entspricht `0 0 0 0 0 0 0 0`.

- `0x18` entspricht `0 0 0 1 1 0 0 0`.

- `0x24` entspricht `0 0 1 0 0 1 0 0`.

- `0x42` entspricht `0 1 0 0 0 0 1 0`.

- `0x81` entspricht `1 0 0 0 0 0 0 1`.

- `0x99` entspricht `1 0 0 1 1 0 0 1`.

- `0x66` entspricht `0 1 1 0 0 1 1 0`.

- `0x00` entspricht `0 0 0 0 0 0 0 0`.

Die erste hexadezimale Zahl steuert die erste Spalte der LEDs.

Der zweite Wert steuert die zweite Spalte, und so weiter.

Diese Einstellungen wandeln jeden 8-Bit-Hexadezimalwert in seine binäre Darstellung um.

Die Zahl 0 bedeutet LED aus, und die Zahl 1 bedeutet LED an.

Die erste konvertierte Zahl steuert das Ein- und Ausschalten der ersten LED-Reihe, und so weiter.

![Einstellmethode Illustration](../media/3ba4bb34ddf3ef182c5aa5bc7a309605.png)

---
