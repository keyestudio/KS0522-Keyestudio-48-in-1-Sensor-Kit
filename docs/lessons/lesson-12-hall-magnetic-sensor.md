# Lezione 12: Sensore magnetico Hall

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Scheda:** Keyestudio V4.0 / scheda compatibile Arduino Uno ATmega328P

![Illustrazione Progetto 12: Sensore magnetico Hall](../media/c3d4d513b72ac04fad7e4f3015bfb1ed.png)

## Descrizione

Questo è un sensore a induzione magnetica. Può rilevare materiali magnetici entro un raggio di rilevamento fino a 3cm. Il raggio di rilevamento e l'intensità del campo magnetico sono proporzionali. L'uscita è digitale on/off.

Questo sensore utilizza lo SFE Reed Switch - Magnetic Field Sensor.

## Specifiche

- Rileva materiali magnetici

- Raggio di rilevamento: fino a 3cm

- Uscita: digitale on/off

- Dimensioni: 30*20mm

- Peso: 3g

## Schema di collegamento

Per prima cosa, prepara i seguenti componenti prima della connessione:

- Scheda V4.0\*1

- Sensore Hall \*1

- Cavo USB\*1

- Cavo jumper\*3

Collega il pin S del modulo a Digital 3 della scheda V4.0, collega il pin negativo alla porta GND, il pin positivo alla porta 5V.

![Illustrazione schema di collegamento](../media/db4db0c53435ceb1d6caaaf40502247a.jpeg)

## Codice di esempio

Copia e incolla il codice sottostante nel software Arduino.

```c
////////////////////////////////////////////////////////////////////
int ledPin = 13;                // choose the pin for the LED
int inputPin = 3;               // Connect sensor to input pin 3
int val = 0;                    // variable for reading the pin status

void setup() {
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(inputPin, INPUT);     // declare push button as input
}

void loop(){
  val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, LOW);  // turn LED OFF
  } else {
    digitalWrite(ledPin, HIGH); // turn LED ON
  }
}
////////////////////////////////////////////////////////////////////
```

## Risultato di esempio

Collega i fili e carica correttamente il codice sulla scheda, vedrai che l'indicatore D13 sulla scheda V4.0 è spento, e anche il LED sul modulo è spento.

![Illustrazione risultato di esempio](../media/102f67e289b5834de7fa80b6e6d99c20.png)

Ma se avvicini una sfera magnetica al modulo Hall, vedrai che l'indicatore D13 sulla scheda V4.0 si accende, e anche il LED sul modulo si accende.

![Illustrazione risultato di esempio](../media/c3c4044f2205dd1ff162ef7e211d2b2c.png)

---
