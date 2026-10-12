# Lezione 48: Matrice a punti

> **Kit:** Keyestudio 48-in-1 Kit sensori  
> **Scheda:** Keyestudio V4.0 / scheda compatibile Arduino Uno ATmega328P

![Progetto 48: illustrazione Matrice a punti](../media/10e87958bbef207075643ae4f5481457.jpeg)

## Introduzione

Cosa c'è di meglio di un singolo LED? Molti LED! Un modo divertente per realizzare un piccolo display è usare una matrice 8x8. Questo modulo utilizza il chip HT16K33 per pilotare una matrice a punti 8x8.

È sufficiente utilizzare la porta di comunicazione I2C del microcontrollore per controllare la matrice, il che permette di risparmiare molte risorse di porte del microcontrollore. Il modulo matrice è fornito con un connettore a 4 pin con passo di 2,54 mm.

Puoi collegare il modulo alla scheda di controllo per la comunicazione usando cavetti jumper.

Inoltre, è fornito con tre interruttori DIP. Puoi impostare gli interruttori a piacere per selezionare l'indirizzo di comunicazione I2C.

## Le impostazioni dell'indirizzo sono indicate di seguito

|   0x70   |          |          |      |   0x71   |          |          |      |   0x72   |          |          |
| :------: | :------: | :------: | ---- | :------: | :------: | :------: | ---- | :------: | :------: | :------: |
| A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |
| 0（SPENTO） | 0（SPENTO） | 0（SPENTO） |      | 1（ACCESO）  | 0（SPENTO） | 0（SPENTO） |      | 0（SPENTO） | 1（ACCESO）  | 0（SPENTO） |
|          |          |          |      |          |          |          |      |          |          |          |
| **0x73** |          |          |      | **0x74** |          |          |      | **0x75** |          |          |
| A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |
| 1（ACCESO）  | 1（ACCESO）  | 0（SPENTO） |      | 0（SPENTO） | 0（SPENTO） | 1（ACCESO）  |      | 1（ACCESO）  | 0（SPENTO） | 1（ACCESO）  |
|          |          |          |      |          |          |          |      |          |          |          |
| **0x76** |          |          |      | **0x77** |          |          |      |          |          |          |
| A0（1）  | A1（2）  | A2（3）  |      | A0（1）  | A1（2）  | A2（3）  |      |          |          |          |
| 0（SPENTO） | 1（ACCESO）  | 1（ACCESO）  |      | 1（ACCESO）  | 1（ACCESO）  | 1（ACCESO）  |      |          |          |          |

## Dettagli tecnici

- Interfaccia: header a 4 pin

- Tensione di funzionamento: DC 4.5V-5.5V

- Fornito con tre interruttori DIP per la selezione dell'indirizzo

- Dimensioni：52mm\*34mm\*11mm

- Peso：13.2g

## Guida al collegamento

Collega il pin SCL alla porta analogica A5, il pin SDA alla porta analogica A4; collega il pin VCC a 5V e GND a GND.

![Guida al collegamento: illustrazione](../media/e2c09c1a7851f64ad03a027c1aa25a14.jpeg)

## Codice di prova

Scarica la libreria:

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

**Nota:** prima di compilare il codice, ricordati di posizionare la cartella della libreria Matrix nella directory \\Arduino\\libraries. Altrimenti la compilazione fallirà.

Per esempio: **C:\\Program Files\\Arduino\\libraries**

## Risultato del test

Dopo aver caricato il codice sulla scheda e alimentato, dovresti vedere la matrice 8\*8 visualizzare un'immagine a forma di cuore. Mostrato qui sotto.

![Risultato del test: illustrazione](../media/4a53bb681a3299be450726255f4d56a2.jpeg)

## Metodo di impostazione

1. Imposta l'indirizzo di comunicazione. Consulta la tabella degli indirizzi.

Il codice è impostato come segue.

![Metodo di impostazione: illustrazione](../media/187557b09de67c1236bfd6536b0b95ee.png)

![Metodo di impostazione: illustrazione](../media/910472d4662d0c1f463f9bedfe4cef74.png)

![Metodo di impostazione: illustrazione](../media/165615f73e4c9a49c861f5e17eb333e3.png)

1. Imposta l'immagine da visualizzare

Puoi impostare l'immagine da visualizzare nel codice mostrato di seguito.

![Metodo di impostazione: illustrazione](../media/4a709cb4583c82f469c179dd6b1cfa71.png)

Posiziona il modulo matrice come segue:

![Metodo di impostazione: illustrazione](../media/10e87958bbef207075643ae4f5481457.jpeg)

Quindi converti 0x00,0x18,0x24,0x42,0x81,0x99,0x66,0x00 in numeri binari:

- `0x00` corrisponde a `0 0 0 0 0 0 0 0`.

- `0x18` corrisponde a `0 0 0 1 1 0 0 0`.

- `0x24` corrisponde a `0 0 1 0 0 1 0 0`.

- `0x42` corrisponde a `0 1 0 0 0 0 1 0`.

- `0x81` corrisponde a `1 0 0 0 0 0 0 1`.

- `0x99` corrisponde a `1 0 0 1 1 0 0 1`.

- `0x66` corrisponde a `0 1 1 0 0 1 1 0`.

- `0x00` corrisponde a `0 0 0 0 0 0 0 0`.

Il primo numero esadecimale controlla la prima colonna di LED.

Il secondo valore controlla la seconda colonna, e così via.

Queste impostazioni convertono ogni valore esadecimale a 8 bit nella sua rappresentazione binaria.

Il numero 0 indica LED spento, 1 indica LED acceso.

Il primo numero convertito controlla l'accensione/spegnimento della prima riga di LED, e così via.

![Metodo di impostazione: illustrazione](../media/3ba4bb34ddf3ef182c5aa5bc7a309605.png)

---
