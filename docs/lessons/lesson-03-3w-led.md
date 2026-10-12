# Lezione 03: LED 3W

> **Kit:** Kit sensori Keyestudio 48-in-1  
> **Scheda:** Keyestudio V4.0 / scheda compatibile Arduino Uno ATmega328P

![Progetto 3: illustrazione LED 3W](../media/0b1110577bfde7df3b6aec41d5b21b28.png)

## Descrizione

Questo modulo LED è ad alta luminosità perché i chip LED che monta sono da 3W.
Puoi applicare questo modulo a progetti Arduino, ideale per robot o piattaforme di
ricerca e soccorso.

Ad esempio, robot intelligenti possono utilizzare questo modulo per scopi di
illuminazione. Nota che la luce del LED non deve essere esposta direttamente agli occhi umani per ragioni di sicurezza.

## Specifiche

- Temperatura del colore: 6000\~7000K

- Flusso luminoso: 180\~210lm

- Corrente: 700\~750mA

- Potenza: 3W

- Angolo di luce: 140 gradi

- Temperatura di funzionamento: -50\~80℃

- Temperatura di conservazione: -50\~100℃

- Modulo LED ad alta potenza, controllato da una porta IO del microcontrollore

- Tipo IO: Digitale

- Tensione di alimentazione: 3.3V a 5V

- Dimensioni: 40x28mm

- Peso: 6g

## Diagramma di collegamento

Per prima cosa, prepara i seguenti componenti prima del collegamento:

- Scheda V4.0\*1

- Modulo LED 3W \*1

- Cavo USB\*1

- Cavi jumper\*3

Collega il pin S del modulo al pin Digital 13 della scheda V4.0, collega il pin negativo al connettore GND e il pin positivo al connettore 5V.

![Illustrazione diagramma di collegamento](../media/7ca6e53405c422f3ae9b04ac572b40ef.jpeg)

## Codice di esempio

Copia e incolla il seguente codice nell'ambiente di sviluppo Arduino.

```c
///////////////////////////////////////////////////////////
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
///////////////////////////////////////////////////////////
```

## Risultato di esempio

Dopo aver collegato i cavi e alimentato il circuito, e aver caricato correttamente il codice, sia il LED D13 sia il LED sul modulo lampeggeranno per un secondo e poi si spegneranno, ciclicamente.

![Illustrazione risultato di esempio](../media/edeb5b089be0300c719652badfd269e7.png)

---
