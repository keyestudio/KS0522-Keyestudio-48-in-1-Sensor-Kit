# Lezione 32: Luce ultravioletta

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Scheda:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Illustrazione del Progetto 32: Luce ultravioletta](../media/15613ff0e8f059a9034e923ab5c2be24.jpeg)

## Descrizione

Il sensore ultravioletto Keyestudio GUVA-S12SD viene utilizzato per rilevare la luce ultravioletta. È adatto per misurare l'indice UV in dispositivi indossabili intelligenti, come orologi, smartphone e dispositivi esterni con rilevamento dell'indice UV.

Può anche essere usato per monitorare l'intensità della luce ultravioletta o come rivelatore di fiamma UV durante la disinfezione con luce ultravioletta.

## Parametri

- Dimensioni: 15mm×30mm×0.7mm

- Tensione di alimentazione: 2.5V～5V

- Segnale di uscita: Segnale analogico

- Gamma di rilevamento dello spettro: 240-370nm

- Area attiva: 0.076mm2

- Responsività: 0.14A/W

- Corrente a buio: 1nA

- Corrente alla luce: 101\~125nA luce UVA, 1mW/cm2

## Schema di collegamento

Prima di effettuare i collegamenti, prepara i seguenti componenti.

- Scheda V4.0\*1

- GUVA-S12SD 3528 Sensore ultravioletto \*1

- Cavo USB\*1

- Cavi jumper\*3

Collega il pin S del modulo all'Analog A0 della scheda V4.0, collega il pin negativo alla porta GND e il pin positivo alla porta 3V3.

![Illustrazione schema di collegamento](../media/092ebb11142cfe83507989a5b2de0526.jpeg)

## Codice di esempio

Copia e incolla il codice qui sotto nell'IDE Arduino.

```c
///////////////////////////////////////////////////////////////
/*
  AnalogReadSerial
  Reads an analog input on pin 0, prints the result to the serial monitor.
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

 This example code is in the public domain.
 */

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
}
///////////////////////////////////////////////////////////////
```

## Risultato di esempio

![Illustrazione risultato di esempio](../media/e81338e1f55ff6b55fbfe369f92b54da.png)

Collega tutto correttamente e carica il codice sul dispositivo, poi apri il Monitor seriale: verranno visualizzati i dati.

Se esponi il sensore a luce UV, i valori sul Monitor seriale varieranno come mostrato nelle immagini seguenti.

![Illustrazione risultato di esempio](../media/3a7f2a608faa9c72aee76d2820f78845.png)

![Illustrazione risultato di esempio](../media/610d2325395cd3b44ce3c18e05595518.jpeg)

---
