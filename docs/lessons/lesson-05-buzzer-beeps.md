# Lezione 05: Suoni del cicalino

> **Kit:** Kit sensori Keyestudio 48-in-1  
> **Scheda:** Keyestudio V4.0 / scheda compatibile Arduino Uno ATmega328P

![Progetto 5: Suoni del cicalino - illustrazione](../media/88c349b0602dfa2e166faabc13cb2f20.png)

## Descrizione

Ecco il modulo più semplice per produrre suoni. Puoi pilotarlo con livello alto/basso. Cambiando la frequenza con cui vibra si possono ottenere suoni diversi.

Questo modulo è ampiamente utilizzato nei nostri elettrodomestici quotidiani come PC, frigorifero, telefoni, ecc.

Inoltre, puoi creare molti progetti interattivi interessanti con questo piccolo ma utile modulo. Provalo! Troverai davvero affascinante il suono elettronico che crea.

## Specifiche

- Tensione di lavoro: 3.3-5V

- Tipo di interfaccia: digitale

- Dimensioni: 30*20mm

- Peso: 4g

## Schema di collegamento

Collega il pin S del modulo a Digital 3 della scheda V4.0, collega il pin negativo al connettore GND, il pin positivo al connettore 5V.

![Schema di collegamento - illustrazione](../media/173f2e9a828b0b20d76dc07de57892c1.jpeg)

## Codice di esempio

Copia e incolla il codice sottostante nel software Arduino.

```c
////////////////////////////////////////////////////////////////////
int buzzPin =3;    //Connect Buzzer on Digital Pin3
 void setup()
 {
  pinMode(buzzPin, OUTPUT);
}
 void loop()
{
  digitalWrite(buzzPin, HIGH);
  delay(1);
  digitalWrite(buzzPin, LOW);
  delay(1);
}
////////////////////////////////////////////////////////////////////
```

## Esempio di risultato

Dopo aver caricato il codice sulla scheda, il cicalino emetterà un suono.

![Esempio di risultato - illustrazione](../media/109e3287bff29d1d1fb88369d6705ad3.png)

---
