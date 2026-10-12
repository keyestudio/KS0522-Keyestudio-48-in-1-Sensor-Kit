# Lesson 16: Flame Alarm

> **Kit:** Keyestudio Kit sensori 48-in-1  
> **Scheda:** Keyestudio V4.0 / scheda compatibile Arduino Uno con ATmega328P

![Illustrazione Progetto 16: Allarme Fiamma](../media/35c5a2593df5d4e76865158e790feada.png)

## Descrizione

Questo sensore di fiamma può essere utilizzato per rilevare incendi o altre sorgenti luminose con lunghezze d'onda comprese tra 760nm \~ 1100nm.

Nel gioco/competizione del robot antincendio, la fiamma ha un ruolo importante nelle rilevazioni e può essere usata come "occhi" del robot per trovare la sorgente di incendio.

## Specifiche

1. Tensione di alimentazione: 3.3V a 5V

2. Distanza di rilevamento: 20cm (4.8V) \~ 100cm (1V)

3. Intervallo della banda spettrale: 760nm a 1100nm

4. Temperatura di esercizio: -25℃ a 85℃

5. Interfaccia: digitale

6. Dimensioni: 44*16.7mm

7. Peso: 4g

## Diagramma di collegamento

Per prima cosa, prepara i seguenti componenti prima del collegamento:

- Scheda V4.0*1

- Sensore di fiamma*1

- Cavo USB*1

- Cavi jumper*3

Collega il pin D0 del modulo al Digital 2 della scheda V4.0, collega il pin GND alla porta GND, il pin VCC alla porta 5V.

![Illustrazione Diagramma di collegamento](../media/a1ee506fc9921c7616349500c258b733.jpeg)

## Codice di esempio

Copia e incolla il codice sottostante nel software Arduino.

```c
////////////////////////////////////////////////////////////////////
const int flamePin = 2;     // the number of the flame pin
const int ledPin =  13;      // the number of the LED pin
// variables will change:
int State = 0;         // variable for reading status
void setup() {
  // initialize the LED pin as an output:
  pinMode(ledPin, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(flamePin, INPUT);
}
void loop(){
  // read the state of the value:
State = digitalRead(flamePin);
  if (State == HIGH) {
    // turn LED on:
    digitalWrite(ledPin, HIGH);
  }
  else {
    // turn LED off:
    digitalWrite(ledPin, LOW);
  }
}
////////////////////////////////////////////////////////////////////
```

## Risultato di esempio

Dopo aver completato i collegamenti e alimentato la scheda, carica correttamente il codice sulla scheda.

![Illustrazione Risultato di esempio](../media/c769453bbd0e1c5fcf6c80cf697030b3.png)

Se avvicini un accendino al sensore, quando il sensore rileva la fiamma, un altro LED sul modulo si accende.

![Illustrazione Risultato di esempio](../media/2ee5a36673d2cbeb934ca2af29dab607.png)

---
