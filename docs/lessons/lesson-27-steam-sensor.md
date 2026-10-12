# Lezione 27: Sensore di vapore

> **Kit:** Kit sensori Keyestudio 48-in-1  
> **Scheda:** Keyestudio V4.0 / Scheda compatibile con Arduino Uno (ATmega328P)

![Illustrazione Progetto 27: Sensore di vapore](../media/d19ac9430f793cdbedde891ee92671e7.jpeg)

## Descrizione

Il sensore di vapore è un sensore analogico e può essere usato come semplice rivelatore di pioggia e come interruttore di livello del liquido. Quando l'umidità sulla superficie del sensore aumenta, la tensione di uscita aumenterà.

Attenzione: le parti di collegamento non sono impermeabili, quindi non immergerle in acqua.

## Parametri

- Tensione di funzionamento: 3.3V o 5V

- Corrente di funzionamento: \<20mA

- Intervallo di temperatura di funzionamento: －10℃～＋70℃

- Tipo di interfaccia: Uscita segnale analogico

## Definizione dei pin

- Pin S: per uscita segnale

- Pin positivo (+): per alimentazione (VCC)

- Pin negativo (-): per massa (GND)

## Diagramma di collegamento

Prima di collegare, prepara i seguenti componenti:

- Scheda V4.0*1

- Sensore di vapore*1

- Cavo USB*1

- Cavo jumper*3

Collega il pin S del modulo all'analogico A0 della scheda V4.0, collega il pin negativo al GND e il pin positivo al 5V.

![Diagramma di collegamento - illustrazione](../media/8fa51466dbc9650dcaa740bce4dd654e.jpeg)

## Codice di esempio

Copia e incolla il codice qui sotto nell'ambiente software Arduino.

```c
////////////////////////////////////////////////////////////////////
void setup()
{
Serial.begin(9600); //open serial port, and set baud rate at 9600bps
}
void loop()
{
int val;
val=analogRead(0); //plug vapor sensor into analog port 0
Serial.print("Moisture is ");
Serial.println(val,DEC); //read analog value through serial port printed
delay(100);
}
////////////////////////////////////////////////////////////////////
```

## Esempio di risultato

![Risultato di esempio - illustrazione](../media/c4633c5911c042224d187645db4d0588.png)

Quando vengono rilevati diversi gradi di umidità, il sensore restituisce valori di corrente differenti. Come mostrato nell'immagine seguente.

A causa delle condizioni limitate, puoi mettere una goccia d'acqua sul sensore; il valore di umidità cambierà nel Monitor Seriale del software Arduino.

![Risultato di esempio - illustrazione](../media/80e9b3e19db4bec337f3254545a58e9e.jpeg)

---
