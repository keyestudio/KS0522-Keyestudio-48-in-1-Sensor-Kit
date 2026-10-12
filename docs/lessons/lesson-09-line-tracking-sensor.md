# Lezione 09: Sensore di tracciamento della linea

> **Kit:** Kit sensori Keyestudio 48-in-1  
> **Scheda:** Keyestudio V4.0 / Scheda compatibile Arduino Uno ATmega328P

![Progetto 9: Illustrazione del sensore di tracciamento della linea](../media/c476ef922ab6a8d31cb68f3ab3fa2ced.png)

## Descrizione

Questo sensore di tracciamento della linea può rilevare una linea bianca su nero o una linea nera su bianco.

Il singolo segnale di tracciamento fornisce un'uscita stabile TTL per una linea più precisa e più stabile. L'opzione multicanale può essere facilmente ottenuta installando i sensori per robot di tracciamento della linea necessari.

## Specifiche

1. Alimentazione: +5V

2. Corrente di funzionamento: \<10mA

3. Intervallo di temperatura di funzionamento: 0°C \~ + 50°C

4. Interfaccia di uscita: interfaccia a 3 fili (1 - segnale, 2 - alimentazione, 3 - negativo dell'alimentazione)

5. Livello di uscita: livello TTL

## Schema di collegamento

Per prima cosa, è necessario preparare i seguenti componenti prima del collegamento:

- Scheda V4.0\*1

- Modulo di tracciamento linea \*1

- Cavo USB\*1

- Cavi jumper\*3

Collega il pin S del modulo a Digital 3 della scheda V4.0, collega il pin GND alla porta GND, il pin V+ alla porta 5V.

![Illustrazione dello schema di collegamento](../media/6727a1d7d92c3878fc51b8db0502fd14.jpeg)

## Codice di esempio

Copia e incolla il codice seguente nel software Arduino.

```c
////////////////////////////////////////////////////////////////////
//Arduino Sample Code
void setup()
{
  Serial.begin(9600);
}
void loop()
{
  Serial.println(digitalRead(3)); // print the data from the sensor
  delay(500);
}
////////////////////////////////////////////////////////////////////
```

## Esempio di risultato

![Illustrazione dell'esempio di risultato](../media/af115c59987fee06447790f1740e3203.jpeg)

Dopo aver caricato il codice sulla scheda, apri il monitor seriale e imposta la velocità di trasmissione (baud) a 9600, quindi potrai vedere i dati dal sensore.

---
