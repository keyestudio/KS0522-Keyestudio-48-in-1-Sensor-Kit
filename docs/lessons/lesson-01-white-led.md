# Lezione 01: LED bianco

> **Kit:** Kit sensori Keyestudio 48-in-1  
> **Board:** scheda Keyestudio V4.0 / compatibile Arduino Uno con ATmega328P

![Illustrazione Progetto 1: LED bianco](../media/6819f1c2047a7bb2b58e9cf0d7d3a617.jpeg)

## Descrizione

Questo modulo LED bianco è ideale per chi inizia con Arduino. Può essere facilmente collegato allo shield IO/Sensor. Permette l'interazione con progetti legati alla luce.

Nota: Puoi scegliere altri moduli LED per emettere colori diversi come giallo, rosso, verde e blu.

## Specifiche

- Modulo LED bianco

- Tipo: Digitale

- Presa PH2.54

- Dimensioni: 30\*20mm

- Peso: 3g

## Schema di collegamento

Per prima cosa, prepara i seguenti componenti prima del collegamento:

- scheda V4.0\*1

- Modulo LED bianco \*1

- Cavo USB\*1

- Cavi jumper\*3

Collega il pin S del modulo a Digital 3 della scheda V4.0; collega il pin negativo al connettore GND e il pin positivo al connettore 5V.

![Illustrazione schema di collegamento](../media/cb67155c3b3cf25025edea5ae31d6c5f.jpeg)

## Codice di esempio

Copia e incolla il codice seguente nell'ambiente di sviluppo Arduino.

```c
const uint8_t ledPin = 3;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
  delay(1000);
}
```

## Risultato di esempio

Dopo aver collegato i cavi, alimentato la scheda e caricato correttamente il codice, vedrai il modulo LED emettere luce bianca.

![Illustrazione risultato di esempio](../media/40448f38601a6312bfb1e3764be22158.png)

---
