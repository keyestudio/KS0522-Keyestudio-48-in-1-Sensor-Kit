# Lezione 08: Lampeggio da collisione

> **Kit:** Keyestudio 48-in-1 Kit sensori  
> **Scheda:** Keyestudio V4.0 / Scheda ATmega328P compatibile con Arduino Uno

![Illustrazione del Progetto 8: Lampeggio da collisione](../media/29c4641406064a4f1df5d59aefbca480.png)

## Descrizione

Il sensore d'urto, noto anche come interruttore elettronico, è un modulo di ingresso digitale on-off necessario per l'apprendimento elementare dell'elettronica.

Attraverso la programmazione può controllare luci, dispositivi sonori, funzioni di selezione tasti di un display LCD, ecc.

Utilizzando un cavo sensore 3P per collegarlo allo shield sensori, può essere installato sulla piattaforma robot mobile 4WD in lega AL per realizzare la funzione di rilevamento delle collisioni. È sia comodo che efficiente.

Puoi realizzare un lampeggiatore di collisione utilizzando il modulo di collisione e il LED integrato sull'interfaccia 13. Collega il sensore di collisione al pin 3. Quando il sensore di collisione rileva un segnale di collisione, i LED sia sulla scheda principale sia sul modulo si accendono contemporaneamente.

## Parametri

1. Se avviene una collisione nella parte anteriore dove è installato il modulo di collisione, il modulo emette un segnale a livello basso; in assenza di collisione, emette un segnale a livello alto.

2. Il modulo prevede un foro di montaggio M3, comodo per il fissaggio su un veicolo.

3. Con spia dell'interruttore: in caso di collisione la spia è accesa; in assenza di collisione la spia è spenta.

## Definizione dei pin

1. Pin positivo (+): collegare all'alimentazione 3v-12v

2. Pin negativo (-): collegare a GND

3. Pin segnale (S): collegare all'uscita di livello alto/basso

## Schema di collegamento

Prima di collegare, è necessario preparare i seguenti componenti:

- Scheda V4.0\*1

- Modulo d'urto \*1

- Cavo USB\*1

- Cavo jumper\*3

Collega il pin S del modulo a Digital 3 della scheda V4.0, collega il pin negativo alla porta GND, il pin positivo alla porta 5V.

![Illustrazione dello schema di collegamento](../media/a4ec0b7f8fd95fb2d6bb5c06ca0776f0.jpeg)

## Codice di esempio

Copia e incolla il codice qui sotto nell'IDE di Arduino.

```c
const uint8_t ledPin = 13;
const uint8_t collisionPin = 3;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(collisionPin, INPUT);
}

void loop() {
  const int state = digitalRead(collisionPin);
  digitalWrite(ledPin, state == HIGH ? LOW : HIGH);
}
```

## Risultato d'esempio

Collega tutto correttamente e poi carica il codice sulla scheda.

Quando un oggetto urta l'interruttore del sensore, sia il LED sul sensore che il LED 13 sulla scheda si accendono.
