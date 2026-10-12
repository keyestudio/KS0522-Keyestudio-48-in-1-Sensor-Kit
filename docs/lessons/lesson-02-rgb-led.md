# Lezione 02: LED RGB

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Scheda:** Keyestudio V4.0 / scheda compatibile Arduino Uno ATmega328P

![Progetto 2: illustrazione LED RGB](../media/de14ae0679267cf87837b7c09934c52e.png)

## Descrizione

Questo è un modulo LED a colori completi, che contiene 3 colori di base: rosso, verde e blu. Possono essere considerati come LED separati.

Dopo la programmazione, puoi accenderli e spegnerli in sequenza oppure utilizzare l'uscita analogica PWM per miscelare i tre colori e generare colori diversi.

## Specifiche

- Colore: rosso, verde e blu

- Luminosità: Alta

- Tensione: 5V

- Ingresso: livello digitale

- Dimensioni: 30 \*20mm

- Peso: 3g

## Schema di collegamento

Per prima cosa, è necessario preparare i seguenti componenti prima del collegamento:

- Scheda V4.0\*1

- Modulo LED RGB \*1

- Cavo USB\*1

- Cavi jumper\*4

Collega il pin V del modulo alla porta 5V della scheda V4.0, collega il pin B al Digital 11, il pin R al Digital 10, il pin G al Digital 9.

![Illustrazione dello schema di collegamento](../media/2c0a9305cd7c7b0c28c51bc2bc24eb39.jpeg)

## Codice di esempio

Copia e incolla il codice sottostante nel software Arduino.

```c
const uint8_t redPin = 11;
const uint8_t bluePin = 10;
const uint8_t greenPin = 9;

void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  for (int value = 255; value >= 0; --value) {
    analogWrite(redPin, value);
    analogWrite(bluePin, 255 - value);
    analogWrite(greenPin, 128 - value);
    delay(1);
  }
  for (int value = 0; value < 255; ++value) {
    analogWrite(redPin, value);
    analogWrite(bluePin, 255 - value);
    analogWrite(greenPin, 128 - value);
    delay(1);
  }
}
```

## Risultato di esempio

Dopo aver completato i collegamenti e alimentato la scheda, e aver caricato correttamente il codice, vedrai il modulo LED RGB emettere colori brillanti.

![Illustrazione del risultato](../media/0872e5256edf443efcb68218505096ba.png)

---
