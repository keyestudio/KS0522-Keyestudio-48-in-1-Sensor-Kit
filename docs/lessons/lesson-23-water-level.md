# Lezione 23: Livello dell'acqua

> **Kit:** Kit sensori Keyestudio 48-in-1  
> **Scheda:** Keyestudio V4.0 / Scheda compatibile Arduino Uno con ATmega328P

![Progetto 23: illustrazione del livello dell'acqua](../media/23f40997b8634be91aed7311eca2dfbb.jpeg)

## Descrizione

Il sensore d'acqua Keyestudio è facile da usare, portatile e conveniente, progettato per identificare e rilevare il livello dell'acqua e le gocce d'acqua.

Questo piccolo sensore può misurare il volume di gocce d'acqua o la quantità d'acqua tramite una serie di tracce di fili paralleli esposti.

## Caratteristiche

- conversione fluida tra quantità d'acqua e valore analogico;

- alta flessibilità, con uscita di un valore analogico di base;

- basso consumo energetico e alta sensibilità;

- si collega direttamente a microprocessori o ad altri circuiti logici, adatto a una varietà di schede di sviluppo e controller come il controller Arduino, il microcontrollore STC, il microcontrollore AVR e altri.

## Specifiche

- Tensione di funzionamento: DC5V

- Corrente di funzionamento: ﹤20mA

- Tipo di sensore: Analogico

- Area di rilevamento: 40mm x16mm

- Processo di produzione: FR4 doppia faccia stagnata

- Design della forma: rientranza semilunare antiscivolo

- Temperatura di esercizio: 10℃-30℃

- Umidità di esercizio: 10%-90% senza condensazione

- Peso: 3g

- Dimensioni: 65mm x 20mm x 8mm

## Schema di collegamento

Collegare il pin S del modulo all'Analogico A0 della scheda V4.0, collegare il pin negativo al GND e il pin positivo al 5V.

![Illustrazione schema di collegamento](../media/92810e41aea313a15735eecb3a168e2f.jpeg)

## Codice di esempio

Copia e incolla il codice qui sotto nell'IDE Arduino.

```c
////////////////////////////////////////////////////////////////////
    int analogPin = 0; //connect water sensor to analog interface 0
int led = 13; //LED to digital interface 13
int val = 0; //define the initial value of variable ‘val’ as 0
int data = 0; //define the initial value of variable ‘data’ as 0
void setup()
{
pinMode(led, OUTPUT); //define led as output pin
Serial.begin(9600); //set baud rate at 9600
}
void loop()
{
val = analogRead(analogPin); //read and assign analog value to variable ’val’
if(val>700){ //decide whether variable ‘val’ is over 700
digitalWrite(led,HIGH); //turn on LED when variable ‘val’ is over 700
}
else{
digitalWrite(led,LOW); //turn off LED when variable ‘val’ is under 700
}
data = val; //variable ’val’ assigns value to variable ‘data’
Serial.println(data); //print variable ‘data’ by Serial.print
delay(100);
}
////////////////////////////////////////////////////////////////////
```

## Esempio di risultato

![Illustrazione del risultato di esempio](../media/ca727c75f4d4e454c95258d77afdf10e.png)

Dopo aver eseguito i passaggi precedenti, facciamo una prova con un livello d'acqua basso e verifichiamo cosa succede?

Carica correttamente il codice sulla scheda V4.0, poi apri il monitor seriale e imposta la velocità di trasmissione (baud) a 9600.

Quando posizioni il sensore nell'acqua a livelli diversi, vedrai il valore cambiare di conseguenza.

![Illustrazione del risultato di esempio](../media/8070cf2260fef39e5ec5e18b7a1849cf.jpeg)

Inoltre, puoi impostare un valore di soglia per l'allarme e collegare un cicalino per generare un avviso.

Il LED non si accenderà quando il livello dell'acqua non ha raggiunto il valore di allarme. Se il livello dell'acqua raggiunge il valore di allarme, il LED si accenderà e il cicalino suonerà per segnalare l'allarme.

---
