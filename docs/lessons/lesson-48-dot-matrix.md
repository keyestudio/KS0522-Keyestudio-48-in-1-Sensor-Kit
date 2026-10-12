# Les 48: Puntmatrix

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Bord:** Keyestudio V4.0 / Arduino Uno-compatibel ATmega328P-bord

![Project 48: Puntmatrix illustratie](../media/10e87958bbef207075643ae4f5481457.jpeg)

## Inleiding

Wat is beter dan één LED? Veel LED's! Een leuke manier om een klein display te maken is met een 8x8-matrix. Deze module gebruikt de HT16K33-chip om een 8x8 puntmatrix aan te sturen.

Je hoeft alleen de I2C-communicatiepoort van de microcontroller te gebruiken om de puntmatrix te besturen, wat meer poortreserves van de microcontroller kan besparen. De matrixmodule wordt geleverd met een 4-pins header met 2,54 mm pinafstand.

Je kunt de module met jumperdraden aansluiten op de besturingskaart voor communicatie.

Bovendien is hij uitgerust met drie DIP-schakelaars. Je kunt willekeurig een schakelaar omzetten om het I2C-communicatieadres te selecteren.

## De adresinstellingen zijn als volgt

|   0x70   |          |          |      |   0x71   |          |          |      |   0x72   |          |          |
| :------: | :------: | :------: | ---- | :------: | :------: | :------: | ---- | :------: | :------: | :------: |
| A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |
| 0（UIT） | 0（UIT） | 0（UIT） |      | 1（AAN） | 0（UIT） | 0（UIT） |      | 0（UIT） | 1（AAN） | 0（UIT） |
|          |          |          |      |          |          |          |      |          |          |          |
| **0x73** |          |          |      | **0x74** |          |          |      | **0x75** |          |          |
| A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |
| 1（AAN） | 1（AAN） | 0（UIT） |      | 0（UIT） | 0（UIT） | 1（AAN） |      | 1（AAN） | 0（UIT） | 1（AAN） |
|          |          |          |      |          |          |          |      |          |          |          |
| **0x76** |          |          |      | **0x77** |          |          |      |          |          |          |
| A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |      |          |          |          |
| 0（UIT） | 1（AAN） | 1（AAN） |      | 1（AAN） | 1（AAN） | 1（AAN） |      |          |          |          |

## Technische gegevens

- Interface: 4Pin header

- Bedrijfsspanning: DC 4.5V-5.5V

- Voorzien van drie DIP-schakelaars voor adresselectie

- Afmetingen：52mm\*34mm\*11mm

- Gewicht：13.2g

## Aansluitschema

Sluit de SCL-pin aan op de Analoge A5-poort, de SDA-pin op de Analoge A4-poort; sluit de VCC-pin aan op de 5V-poort en de GND-pin op GND.

![Aansluitschema illustratie](../media/e2c09c1a7851f64ad03a027c1aa25a14.jpeg)

## Testcode

Download de bibliotheek:

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

**Opmerking:** voordat je de code compileert, zorg ervoor dat je de Matrix-bibliotheekmap plaatst in de directory \\Arduino\\libraries. Anders mislukt het compileren van de code.

Bijvoorbeeld: **C:\\Program Files\\Arduino\\libraries**

## Testresultaat

Nadat je de code naar het bord hebt geüpload en de voeding inschakelt, zou je de 8\*8-matrix een hartafbeelding moeten zien weergeven. Zie hieronder.

![Testresultaat illustratie](../media/4a53bb681a3299be450726255f4d56a2.jpeg)

## Instelmethode

1. Stel het communicatieadres in. Raadpleeg de adresgrafiek.

De code is als volgt ingesteld.

![Instelmethode illustratie](../media/187557b09de67c1236bfd6536b0b95ee.png)

![Instelmethode illustratie](../media/910472d4662d0c1f463f9bedfe4cef74.png)

![Instelmethode illustratie](../media/165615f73e4c9a49c861f5e17eb333e3.png)

1. Stel het weergavebeeld in

Je kunt het weergegeven beeld instellen in de onderstaande code.

![Instelmethode illustratie](../media/4a709cb4583c82f469c179dd6b1cfa71.png)

Plaats de matrixmodule als volgt:

![Instelmethode illustratie](../media/10e87958bbef207075643ae4f5481457.jpeg)

Converteer vervolgens 0x00,0x18,0x24,0x42,0x81,0x99,0x66,0x00 naar binaire getallen:

- `0x00` komt overeen met `0 0 0 0 0 0 0 0`.

- `0x18` komt overeen met `0 0 0 1 1 0 0 0`.

- `0x24` komt overeen met `0 0 1 0 0 1 0 0`.

- `0x42` komt overeen met `0 1 0 0 0 0 1 0`.

- `0x81` komt overeen met `1 0 0 0 0 0 0 1`.

- `0x99` komt overeen met `1 0 0 1 1 0 0 1`.

- `0x66` komt overeen met `0 1 1 0 0 1 1 0`.

- `0x00` komt overeen met `0 0 0 0 0 0 0 0`.

Het eerste hexadecimale getal bestuurt de eerste kolom van LED's.

De tweede waarde bestuurt de tweede kolom, enzovoort.

Deze instellingen zetten elke 8-bits hexadecimale waarde om in de binaire weergave.

Het cijfer 0 betekent LED uit, en het cijfer 1 betekent LED aan.

Het eerste geconverteerde getal bestuurt het aan/uit van de eerste rij LEDs, enzovoort.

![Instelmethode illustratie](../media/3ba4bb34ddf3ef182c5aa5bc7a309605.png)

---
