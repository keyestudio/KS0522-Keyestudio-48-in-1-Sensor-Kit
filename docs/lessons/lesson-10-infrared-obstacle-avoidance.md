# Lezione 10: Evitamento ostacoli a infrarossi

> **Kit:** Kit sensori Keyestudio 48-in-1  
> **Scheda:** Keyestudio V4.0 / scheda ATmega328P compatibile con Arduino Uno

![Illustrazione del progetto 10: Evitamento ostacoli a infrarossi](../media/54ab9db703340471fd9c3151934b85e7.png)

## Descrizione

Il sensore rilevatore di ostacoli a infrarossi è dotato di funzione di regolazione della distanza ed è progettato appositamente per robot su ruote.

Questo sensore ha una forte adattabilità alla luce ambientale ed è di alta precisione.

Dispone di una coppia di tubi trasmittente e ricevente a infrarossi. Quando il raggio infrarosso emesso dal tubo trasmittente incontra un ostacolo (il suo riflettore), il raggio verrà riflesso verso il tubo ricevente, così l'indicatore si illuminerà e l'interfaccia di uscita del segnale fornirà un segnale digitale.

Inoltre, è possibile ruotare la manopola del potenziometro per regolare la distanza di rilevamento (distanza effettiva: 2～40cm, tensione di lavoro: 3.3V-5V).

Grazie a un ampio intervallo di tensione, questo sensore può funzionare stabilmente anche con tensione di alimentazione variabile ed è adatto a vari microcontrollori, controller Arduino e controller BS2.

Un robot dotato di questo sensore può percepire gli ostacoli nell'ambiente.

## Specifiche

- Tensione di lavoro: DC 3.3V-5V

- Corrente di lavoro: ≥20mA

- Temperatura di esercizio: －10℃ a＋50℃

- Distanza di rilevamento: 2-40cm

- Interfaccia IO: 4 fili (-/+/S/EN)

- Segnale in uscita: tensione TTL

- Modalità di alloggiamento: regolazione della resistenza multigiro

- Angolo efficace: 35°

## Schema di collegamento

Per prima cosa, prepara i seguenti componenti prima del collegamento:

- Scheda V4.0\*1

- Modulo rilevatore ostacoli \*1

- Cavo USB\*1

- Cavi jumper\*3

Collega il pin Out del modulo a Digital 2 della scheda V4.0, collega il pin V+ alla porta 5V, il pin GND alla porta GND.

![Illustrazione schema di collegamento](../media/48f60a482d777df19bc43a3203479b0c.jpeg)

## Codice di esempio

Copia e incolla il codice sottostante nell'ambiente Arduino.

```c
const uint8_t sensorPin = 2;
const uint8_t ledPin = 13;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop() {
  const int sensorState = digitalRead(sensorPin);
  digitalWrite(ledPin, sensorState == HIGH ? HIGH : LOW);
}
```

## Risultato di esempio

Dopo aver caricato il codice sulla scheda, puoi vedere il LED sia sulla scheda V4.0 che sul sensore rilevatore di ostacoli acceso.

![Illustrazione del risultato di esempio](../media/44d035dfe09b4c803becd84c95b05956.png)

Se posizioniamo un blocco di schiuma davanti al sensore, questa volta quando il sensore rileva l'ostacolo, il LED sul sensore si accenderà.

![Illustrazione del risultato di esempio](../media/da4468fead816d42b2ac43b29716b91f.png)

---
