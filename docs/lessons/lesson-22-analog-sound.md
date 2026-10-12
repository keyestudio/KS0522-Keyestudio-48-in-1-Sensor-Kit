# Lezione 22: Suono Analogico

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Scheda:** Keyestudio V4.0 / scheda ATmega328P compatibile con Arduino Uno

![Progetto 22: illustrazione Suono Analogico](../media/a494bbec73f7c8ff91b3133c9d2798a7.jpeg)

## Descrizione

Il sensore di suono analogico viene tipicamente usato per rilevare il volume dei suoni ambientali. Il sensore è dotato di un potenziometro, che puoi ruotare per regolare il guadagno del segnale.

Puoi usarlo per creare lavori interessanti e interattivi, come un interruttore attivato dalla voce.

## Specifiche

- Tensione di alimentazione: 3.3V a 5V

- Interfaccia: Analogico

- Dimensioni: 30*20mm

- Peso: 4g

## Diagramma di collegamento

Collega il pin S del modulo al pin A0 analogico della scheda V4.0, collega il pin negativo al connettore GND, il pin positivo al connettore 5V.

![Illustrazione del diagramma di collegamento](../media/22e1124550d57015a6d2d5782b8febda.jpeg)

## Codice di esempio

Copia e incolla il codice seguente nell'IDE Arduino.

```c
////////////////////////////////////////////////////////////////////
int sensorPin =A0 ;
int value = 0;
void setup()
{
 Serial.begin(9600); }
void loop()
{
 value = analogRead(sensorPin);

Serial.println(value, DEC);

delay(50);
}
////////////////////////////////////////////////////////////////////
```

## Risultato di esempio

Dopo aver completato i collegamenti e alimentato la scheda, carica il codice, poi apri il monitor seriale e imposta la velocità di trasmissione (baud) a 9600; vedrai il valore analogico. Quando parli rivolgendoti verso il microfono, il valore aumenterà. Mostrato qui sotto.

![Illustrazione del risultato di esempio](../media/4d753036151413a1bdda3c0b283b8551.png)

---
