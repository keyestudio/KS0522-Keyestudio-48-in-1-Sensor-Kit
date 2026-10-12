# Lezione 26: Sensore alcolico analogico

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Scheda:** Keyestudio V4.0 / scheda compatibile Arduino Uno ATmega328P

![Progetto 26: Sensore alcolico analogico (illustrazione)](../media/288162cf02f2968eda57b437292a42dd.png)

## Descrizione

Questo sensore MQ-3 analogico è adatto per rilevare l'alcol. Può essere utilizzato in un progetto di etilometro.

Ha buona selettività perché è più sensibile all'alcol e meno sensibile alla benzina.

La sensibilità può essere regolata ruotando il potenziometro sul sensore.

## Specifiche

- Alimentazione: 5V

- Tipo di interfaccia: Analogico

- Circuito di pilotaggio semplice

- Stabile e lunga durata

- Risposta rapida e alta sensibilità

## Schema di collegamento

Collega il pin A0 del modulo all'ingresso analogico A0 della scheda V4.0, collega il pin GND al terminale GND, il pin VCC al terminale 5V.

![Schema di collegamento (illustrazione)](../media/61632f44731176aaf95d313f2843c9de.jpeg)

## Codice di esempio

Copia e incolla il codice sottostante nel software Arduino.

```c
////////////////////////////////////////////////////////////////////
//Arduino Sample Code
void setup()
{
  Serial.begin(9600); //Set serial baud rate to 9600 bps
}
void loop()
{
int val;
val=analogRead(0);//Read Gas value from analog 0
Serial.println(val,DEC);//Print the value to serial port
delay(100);
}
////////////////////////////////////////////////////////////////////
```

## Risultato di esempio

![Risultato di esempio (illustrazione)](../media/a21d5b8c686e46a59128ab48b96d177c.png)

Dopo aver collegato i cavi e alimentato il circuito, carica correttamente il codice, poi apri il monitor seriale e imposta il baud rate a 9600; vedrai il valore analogico. Quando rileverà vapori di alcol, il valore varierà.

![Risultato di esempio (illustrazione)](../media/97565d8ba7691b30a7aa96efc6c7728b.jpeg)

---
