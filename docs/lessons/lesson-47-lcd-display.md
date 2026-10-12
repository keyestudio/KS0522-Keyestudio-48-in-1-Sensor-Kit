# Lezione 47: Display LCD

> **Kit:** Keyestudio Kit sensori 48-in-1  
> **Scheda:** Keyestudio V4.0 / scheda compatibile Arduino Uno ATmega328P

![Illustrazione progetto 47: display LCD](../media/1aa1fd551e180d013633c1fe857c24a6.jpeg)

## Descrizione

In questo progetto guideremo il display LCD 0802 per visualizzare testo utilizzando la scheda V4.0.

La capacità di visualizzazione dell'LCD è di 8x2 caratteri, e la tensione operativa del chip è 4,5～5,5V.

Esistono due metodi di collegamento per visualizzare testo sul 0802 LCD: collegamento a 4 bit e collegamento a 8 bit.

Puoi fare riferimento alle spiegazioni correlate di seguito.

## Spiegazione delle Interfacce

| **Interfaccia** | **Pin** | **Spiegazione**                                              |
| :-----------: | :-----: | ------------------------------------------------------------ |
|       1       |   VSS   | Massa alimentazione logica                                    |
|       2       |   VDD   | Alimentazione logica                                           |
|       3       |   V0    | Tensione regolabile LCD, collegare al pin centrale del potenziometro da 10K |
|       4       |   RS    | Selezione Dati\\Comando                                       |
|       5       |   RW    | Opzione lettura\\scrittura                                    |
|       6       |    E    | Abilita lettura\\scrittura, attivo a HIGH, al fronte di discesa blocca i dati |
|       7       |   DB0   | Pin di input/output dati                                      |
|       8       |   DB1   | Pin di input/output dati                                      |
|       9       |   DB2   | Pin di input/output dati                                      |
|      10       |   DB3   | Pin di input/output dati                                      |
|      11       |   DB4   | Pin di input/output dati                                      |
|      12       |   DB5   | Pin di input/output dati                                      |
|      13       |   DB6   | Pin di input/output dati                                      |
|      14       |   DB7   | Pin di input/output dati                                      |
|      15       |  LED-A  | Terminale positivo alimentazione retroilluminazione          |
|      16       |  LED-K  | Terminale negativo alimentazione retroilluminazione          |

## Materiale Necessario

Per prima cosa prepara le seguenti parti:

- Scheda V4.0 × 1
- 0802 LCD × 1
- Potenziometro rotativo × 1
- Piastra di prototipazione (breadboard) × 1
- Cavo USB × 1
- Cavi jumper, secondo necessità
- Cavi Dupont, secondo necessità

## Diagramma di Collegamento

## Connessione a 4 bit

![Illustrazione collegamento a 4 bit](../media/6b3c862d4b36726275b67b747e6d5df3.jpeg)

## Connessione a 8 bit

![Illustrazione collegamento a 8 bit](../media/97a92aff5ba45d0f7daaca6307b9a5fd.png)

## Codice Sorgente

## Per connessione a 4 bit

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

## Per connessione a 8 bit

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

## Risultato di Esempio

Collegalo correttamente, alimenta la scheda, carica il codice sopra sulla scheda, regola la retroilluminazione del LCD ruotando il potenziometro; alla fine vedrai i caratteri visualizzati sullo schermo LCD.

Se usi la connessione a 4 bit, dovresti vedere l'LCD visualizzare il testo "Ciao" sulla prima riga, e la seconda riga visualizzare il testo "mondo!" come mostrato di seguito.

![Illustrazione risultato di esempio](../media/7d2763d65677d2925902ffcc65bf1b12.png)

Se usi la connessione a 8 bit, vedrai altri caratteri visualizzati sull'LCD. Come mostrato di seguito.

![Illustrazione risultato di esempio](../media/61002a13397f8041574b375b0032da26.png)

---
