# Lezione 38: Relè singolo

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Scheda:** Keyestudio V4.0 / scheda compatibile Arduino Uno con ATmega328P

![Progetto 38: Illustrazione relè singolo](../media/e0b4485cfd4ccebd974d81f19239dde3.png)

## Introduzione

Questo modulo relè singolo può essere usato in progetti interattivi. Il modulo utilizza un relè SONGLE 5V di alta qualità. Può inoltre essere impiegato per controllare illuminazione, apparecchi elettrici e altri dispositivi.

Il design modulare lo rende facile da usare con la scheda Arduino. Può essere controllato tramite una porta IO digitale, ad esempio per valvole elettromagnetiche, lampade, motori e altri dispositivi ad alta corrente o alta tensione.

## Specifiche

- Tipo: Digitale

- Corrente nominale: 10A (NO) 5A (NC)

- Tensione massima di commutazione: 150VAC 24VDC

- Interfaccia digitale

- Segnale di controllo: livello TTL

- Carico nominale: 8A 150VAC (NO), 10A 24VDC (NO), 5A 250VAC (NO/NC), 5A 24VDC (NO/NC)

- Potenza massima di commutazione: AC1200VA DC240W (NO), AC625VA DC120W (NC)

- Tempo di azione del contatto: 10ms

## Schema di collegamento

Per prima cosa è necessario preparare i seguenti componenti prima del collegamento.

- Scheda V4.0\*1

- Modulo relè\*1

- Modulo LED \*1

- Breadboard \*1

- Cavo USB\*1

- Jumper Wire\*9

Qui usiamo il modulo relè singolo per controllare l'accensione o lo spegnimento di un modulo LED.

Per il modulo relè, collegare il pin Signal alla porta digitale 8 della scheda V4.0, quindi collegare il suo pin positivo alla riga anodo della breadboard, portare via la riga alla porta 5V della scheda V4.0. Collegare il suo pin negativo alla riga catodo della breadboard, portare via la riga alla porta GND della scheda V4.0.

Per il modulo LED, collegare il suo pin Signal a un morsetto del modulo relè, l'altro morsetto del relè va collegato alla porta digitale 13 della scheda V4.0. Collegare il suo pin positivo alla riga anodo, il pin negativo alla riga catodo della breadboard.

![Illustrazione schema di collegamento](../media/21cf9b1d5f0843230ee516a0a8be77e1.jpeg)

## Codice di esempio

Copia e incolla il codice sottostante nel software Arduino.

```c
///////////////////////////////////////////////////////////////
 int Relay = 8;
  void setup()
{
  pinMode(13, OUTPUT);         //Set Pin13 as output
  digitalWrite(13, HIGH);     //Set Pin13 High
  pinMode(Relay, OUTPUT);     //Set Pin3 as output
}
void loop()
{
          digitalWrite(Relay, HIGH);   //Turn off relay
          delay(2000);
          digitalWrite(Relay, LOW);    //Turn on relay
          delay(2000);
}
///////////////////////////////////////////////////////////////
```

## Risultato d'esempio

![Illustrazione risultato d'esempio](../media/c751be64bd8acd8c6114598b89586cfa.png)

Questo modulo relè si attiva a livello HIGH.

Collegalo correttamente, alimenta la scheda, quindi carica il codice sopra: vedrai che il relè si accende（ON connesso, NC disconnesso）per due secondi, poi si spegne per due secondi（NC chiuso, ON disconnesso）, ripetutamente e ciclicamente.

Quando il relè è attivato, il LED esterno si accende. Se il relè è disattivato, il LED esterno si spegne.

---
