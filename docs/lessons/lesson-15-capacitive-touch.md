# Lezione 15: Touch capacitivo

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Scheda:** Keyestudio V4.0 / scheda compatibile Arduino Uno ATmega328P

![Illustrazione del progetto 15: Touch capacitivo](../media/bceabc7d4302bd41ae380e179a281314.png)

## Descrizione

Se sei stanco di premere pulsanti meccanici, prova il nostro sensore touch capacitivo. I sensori touch sono comunemente usati nei dispositivi elettronici. Aggiorna il tuo progetto Arduino con questo sensore per renderlo più interessante.

Questo piccolo sensore può rilevare il tocco del corpo e dei metalli restituendo un livello di tensione alto/basso. Anche se isolato da tessuto o carta, può ancora percepire il contatto, sebbene la sensibilità diminuisca all'aumentare dello spessore dello strato isolante.

Apporteremo ulteriori miglioramenti a questi moduli sensore per offrirti una migliore esperienza.

## Specifiche

- Tensione di alimentazione: 3.3V a 5V

- Interfaccia: Digitale

- Dimensioni: 30*20mm

- Peso: 3g

## Schema di collegamento

Prima di collegare, prepara i seguenti componenti:

- Scheda V4.0*1

- Sensore touch capacitivo*1

- Cavo USB*1

- Cavi jumper*3

Collega il pin S del modulo al Digital 2 della scheda V4.0, collega il pin negativo al GND e il pin positivo al 5V.

![Illustrazione dello schema di collegamento](../media/18193a53377b60f43fb583c29337f3aa.jpeg)

## Codice di esempio

Copia e incolla il codice seguente nell'IDE Arduino.

```c
const uint8_t ledPin = 13;  // On-board LED.
const uint8_t touchPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(touchPin, INPUT);
}

void loop() {
  const int touched = digitalRead(touchPin);
  digitalWrite(ledPin, touched == HIGH ? HIGH : LOW);
}
```

## Risultato di esempio

Dopo aver effettuato i collegamenti e alimentato la scheda, caricato correttamente il codice, tocca il sensore con il dito: sia il LED D2 sul sensore sia l'indicatore D13 sulla scheda V4.0 si accendono. Altrimenti, entrambi gli indicatori sono spenti.

![Illustrazione del risultato di esempio](../media/31a751feed0f21236458b93eed14af9f.png)

---
