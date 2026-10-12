# Lezione 20: Rotazione analogica

> **Kit:** Kit sensori Keyestudio 48-in-1  
> **Scheda:** Keyestudio V4.0 / scheda compatibile Arduino Uno ATmega328P

![Progetto 20: sensore di rotazione analogico illustrazione](../media/7a7fffa705c4a50e87455e6d378eb837.png)

## Descrizione

Questo sensore di rotazione analogico è compatibile con Arduino. È basato su un potenziometro. La sua tensione può essere suddivisa in 1024 livelli, ed è facile da collegare ad Arduino con il nostro shield per sensori.

Combinato con altri sensori, puoi usarlo per realizzare progetti interessanti leggendo il valore analogico dalla porta IO.

## Specifiche

- Tensione di alimentazione: 3.3V a 5V

- Interfaccia: Analogica

- Dimensioni: 30*20mm

- Peso: 8g

## Schema di collegamento

Collega il pin S del modulo all'ingresso analogico A0 della scheda V4.0, collega il pin negativo a GND e il pin positivo a 5V.

![Schema di collegamento illustrazione](../media/f8a0c2cca0f3d0935ce0c9a0c4dbe59e.jpeg)

## Codice di esempio

Copia e incolla il codice qui sotto nell'IDE di Arduino.

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

![Risultato di esempio illustrazione](../media/bae047449c10c99449c35a14b22d759c.png)

Dopo aver effettuato il cablaggio e alimentato il circuito, carica correttamente il codice, poi apri il monitor seriale e imposta la velocità di trasmissione (baud) su 9600; infine vedrai il valore analogico. Se ruoti la manopola del sensore di rotazione, il valore varierà tra 0 e 1023. Come mostrato sotto.

![Risultato di esempio illustrazione](../media/bc7b15c3245b7cfd91b0ef4b0aeb8e7e.jpeg)

---
