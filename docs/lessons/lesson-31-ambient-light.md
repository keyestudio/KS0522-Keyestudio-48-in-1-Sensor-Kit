# Lezione 31: Luce Ambientale

> **Kit:** Kit Keyestudio 48-in-1 di sensori  
> **Scheda:** Scheda Keyestudio V4.0 / scheda compatibile Arduino Uno con ATmega328P

![Illustrazione Progetto 31: Luce Ambientale](../media/3eda1bbb84995dc2195a0406f1b0c196.jpeg)

## Descrizione

A un certo punto vorrai rilevare la luminosità ambientale con maggiore precisione rispetto al tuo fidato fotoresistore senza aggiungere complessità al progetto. Quando arriverà quel giorno, procurati un sensore di luce ambientale TEMT6000.

Il TEMT6000 è progettato per adattarsi alla sensibilità dell'occhio umano, ma si è dimostrato meno performante in condizioni di luce bassa. Funziona però molto bene nel reagire a piccole variazioni su un ampio intervallo di luminosità. Poiché è pensato per imitare l'occhio umano, non risponde bene alla luce IR o UV, quindi tienine conto quando lo utilizzi nel tuo progetto.

## Specifiche

- Tensione di alimentazione: +5VDC 50mA

- Dimensioni: 36.5\*16mm

- Peso: 4g

## Schema di collegamento

Per prima cosa prepara i seguenti componenti.

- Scheda V4.0\*1

- Sensore di luce ambientale TEMT6000\*1

- Cavo USB\*1

- Cavo jumper\*3

Si tratta di un componente estremamente semplice: collega solo alimentazione e massa, e il pin di segnale alla porta di ingresso analogico; una volta collegato, il sensore fornirà una tensione analogica che aumenta quando diventa più luminoso. Puoi alimentarlo anche con 3.3V se preferisci; il valore di uscita sarà semplicemente molto più basso.

![Schema di collegamento illustrazione](../media/dae046a9efbeea661b9b6a2ab632fcbc.jpeg)

## Codice di esempio

Non si può fare più semplice di così – questo riporta semplicemente il valore di lettura dal sensore al terminale seriale: 0-1023, con 1023 molto luminoso e 0 molto buio.

```c
///////////////////////////////////////////////////////////////
int temt6000Pin = 0;
void setup() {
 Serial.begin(9600);
}
void loop() {
 int value = analogRead(temt6000Pin);
 Serial.println(value);
 delay(100); //only here to slow down the output so it is easier to read
}
///////////////////////////////////////////////////////////////
```

## Risultato di esempio

Dopo aver collegato correttamente e caricato il codice sopra, apri il monitor seriale dell'IDE Arduino.

![Illustrazione risultato di esempio](../media/ea9ab82076983cc965fe016297b6ad76.png)

Quindi copri il sensore con la mano o con un foglio di carta: la luce diminuisce e vedrai infine il valore mostrato nel monitor diminuire.

![Illustrazione risultato di esempio](../media/846828c9af69a9823ca7218157cc181e.jpeg)

---
