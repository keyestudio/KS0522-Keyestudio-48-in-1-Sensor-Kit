# Lezione 21: Fotocellula

> **Kit:** Kit sensori Keyestudio 48-in-1  
> **Scheda:** Keyestudio V4.0 / scheda compatibile Arduino Uno con ATmega328P

![Progetto 21: illustrazione fotocellula](../media/8eed60793fd64a7c0b9a9b2a2fc1ef67.png)

## Descrizione

La fotocellula è comunemente presente nella nostra vita quotidiana ed è principalmente utilizzata negli interruttori intelligenti, nonché nei normali progetti elettronici. Per rendere il suo utilizzo più semplice ed efficace, forniamo i moduli corrispondenti.

La fotocellula è un semiconduttore. Presenta elevata sensibilità, risposta rapida, caratteristiche spettrali e costanza del valore R, mantenendo alta stabilità e affidabilità anche in ambienti estremi come alte temperature e alta umidità.

È ampiamente utilizzata nei campi del controllo automatico come fotocamere, luci solari da giardino, lampade per prati, rilevatori di banconote, orologi al quarzo, tazze musicali, scatole regalo, mini luci notturne, interruttori a controllo sonoro e luminoso, ecc.

## Specifiche

- Tipo interfaccia: analogico

- Tensione di lavoro: 5V

- Dimensioni: 30*20mm

- Peso: 3g

## Schema di collegamento

Collegare il pin S del modulo all'Analog A0 della scheda V4.0, collegare il pin negativo al connettore GND e il pin positivo al connettore 5V.

![Illustrazione schema di collegamento](../media/28a1990cd088d6f0301f02d217cef301.jpeg)

## Codice di esempio

Copia e incolla il codice sottostante nell'IDE Arduino.

```c
////////////////////////////////////////////////////////////////////
void setup()
{
  Serial.begin(9600); //Set serial baud rate to 9600 bps
}
void loop()
{
int val;
val=analogRead(0);//Read rotation sensor value from analog 0
Serial.println(val,DEC);//Print the value to serial port
delay(100);
}
////////////////////////////////////////////////////////////////////
```

## Risultato di esempio

![Illustrazione del risultato di esempio](../media/78268e9cb1dbc127e7ae3299d3a35a45.png)

Dopo aver completato i collegamenti e alimentato la scheda, carica correttamente il codice, poi apri il monitor seriale. Se copri la fotocellula sul sensore con la mano, vedrai il valore analogico diminuire.

![Illustrazione del risultato di esempio](../media/85621deb4c66d6e53697cd0ef90cb6e2.jpeg)

---
