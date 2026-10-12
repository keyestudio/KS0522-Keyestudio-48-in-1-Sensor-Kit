# Lezione 07: Pulsante Digitale

> **Kit:** Kit sensori Keyestudio 48-in-1  
> **Scheda:** Keyestudio V4.0 / scheda compatibile con Arduino Uno (ATmega328P)

![Illustrazione Progetto 7: Pulsante Digitale](../media/a8707354e54ea51bb92584f791ae79e5.png)

## Descrizione

Questo è un modulo pulsante di base. Puoi semplicemente collegarlo a uno shield IO per avere la tua prima esperienza con Arduino.

## Caratteristiche

- Ampia gamma di tensione da 3.3V a 5V

- Interfacce dei sensori facilmente riconoscibili ("A" per Analogico e "D" per Digitale)

- Foro di montaggio standard

- Icone chiare

- Connettore di alta qualità

- Facile da collegare e utilizzare

- Pulsante ampio e cappuccio di alta qualità

- Per realizzare progetti interessanti e interattivi

## Specifiche

- Tensione di alimentazione: 3.3V a 5V

- Interfaccia: Digitale

- Dimensioni: 30*20mm

- Peso: 4g

## Schema di collegamento

Per prima cosa, prepara i seguenti componenti prima del collegamento:

- Scheda V4.0*1

- Modulo pulsante*1

- Cavo USB*1

- Cavi jumper*3

Collega il pin S del modulo a Digital 3 della scheda V4.0, collega il pin negativo al connettore GND e il pin positivo al connettore 5V.

![Illustrazione schema di collegamento](../media/6ec73b961481bf0794572a842c5231fa.jpeg)

## Codice di esempio

Copia e incolla il codice sottostante nell'ambiente Arduino.

```c
////////////////////////////////////////////////////////////////////
/* # When you push the digital button, the Led 13 on the board will be turned on. Otherwise,the led is turned off.
*/
int ledPin = 13;                // choose the pin for the LED
int inputPin = 3;               // Connect sensor to input pin 3
void setup() {
  pinMode(ledPin, OUTPUT);      // set LED as output
  pinMode(inputPin, INPUT);     // set pushbutton as input
}
void loop(){
  int val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, LOW);  // turn LED OFF
  } else {
    digitalWrite(ledPin, HIGH); // turn LED ON
  }
}
////////////////////////////////////////////////////////////////////
```

## Risultato d'esempio

Collega tutto come mostrato nell'immagine sottostante, poi carica il codice sulla scheda.

Quando premi il pulsante digitale, il LED 13 sulla scheda V4.0 si accende. Quando rilasci il pulsante, il LED si spegne. Mostrato qui sotto.

![Illustrazione risultato d'esempio](../media/ac03d3fa1c0f5de7dae18c6e64406e60.png)

---
