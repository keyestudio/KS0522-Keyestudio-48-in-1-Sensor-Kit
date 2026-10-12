# Lezione 24: Umidità del Suolo

> **Kit:** Kit sensori Keyestudio 48-in-1  
> **Scheda:** Keyestudio V4.0 / scheda compatibile Arduino Uno ATmega328P  

![Progetto 24: illustrazione Umidità del Suolo](../media/d1041a8e2cbfca69c5d8bbd9ba7d4f92.jpeg)

## Descrizione

Questo è un semplice sensore di umidità del suolo progettato per rilevare l'umidità del terreno. Se il terreno è carente d'acqua, il valore analogico in uscita dal sensore diminuirà, altrimenti aumenterà.

Se usi questo sensore per costruire un dispositivo di irrigazione automatico, può rilevare se le tue piante hanno sete per evitare che appassiscano quando sei fuori.

Combinando questo sensore con un controllore Arduino puoi rendere le tue piante più curate e il tuo giardino più intelligente.

Il modulo sensore di umidità del suolo non è così complicato come potresti pensare, quindi se hai bisogno di rilevare l'umidità nel tuo progetto sarà una delle migliori scelte.

Il sensore è dotato di due sonde che vengono inserite nel terreno. Se la corrente passa attraverso il terreno, il sensore ottiene il valore di resistenza leggendo le variazioni di corrente tra le due sonde, quindi converte il valore di resistenza in contenuto di umidità.

Maggiore è l'umidità (minore resistenza), maggiore è la conducibilità del terreno.

La superficie del sensore è stata sottoposta a un processo di metallizzazione per prolungarne la durata. Inseriscilo nel terreno e poi usa il convertitore AD per leggerne il valore. Con l'aiuto di questo sensore, la pianta può ricordarti: Ho bisogno d'acqua.

## Specifiche

- Tensione di alimentazione: 3.3V o 5V

- Corrente di lavoro: ≤ 20mA

- Tensione in uscita: 0-2.3V (Quando il sensore è completamente immerso in acqua, la tensione sarà 2.3V)  
  Più alta è l'umidità, più alta sarà la tensione in uscita.

- Tipo di sensore: Uscita analogica

- Interfaccia: Pin1 - segnale, Pin2 - GND, Pin3 - VCC

## Schema di Collegamento

Collega il pin S del modulo ad Analog A0 della scheda V4.0, collega il pin negativo a GND e il pin positivo a 5V.

![Illustrazione schema di collegamento](../media/b1685a438f171f4bbb3cd8d1b1782bb1.jpeg)

## Codice di esempio

Copia e incolla il codice sottostante nel software Arduino.

```c
////////////////////////////////////////////////////////////////////
/*
  # Example code for the moisture sensor
  # Connect the sensor to the A0(Analog 0) pin on the Arduino board
  # the sensor value description
  # 0  ~300     dry soil
  # 300~700     humid soil
  # 700~950     in water
*/
void setup(){
  Serial.begin(57600);
}
void loop(){
  Serial.print("Moisture Sensor Value:");
  Serial.println(analogRead(0));
  delay(100);
}
////////////////////////////////////////////////////////////////////
```

## Risultato di esempio

![Illustrazione risultato di esempio](../media/1200f0f53ca0758afc505c475ce75e68.png)

Dopo aver collegato i cavi e alimentato il circuito, carica correttamente il codice, quindi apri il monitor seriale e imposta la velocità di trasmissione a 57600: vedrai il valore. Quando il sensore rileva l'umidità, il valore cambierà di conseguenza. Mostrato di seguito.

![Illustrazione risultato di esempio](../media/cb240ae7199f877c17b9ac3a4d9d6ced.jpeg)

---
