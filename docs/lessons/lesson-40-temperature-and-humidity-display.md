# Lezione 40: Visualizzazione di Temperatura e Umidità

> **Kit:** Kit sensori Keyestudio 48-in-1  
> **Scheda:** Keyestudio V4.0 / Scheda compatibile Arduino Uno ATmega328P

![Progetto 40: Illustrazione Visualizzazione di Temperatura e Umidità](../media/e164737761b08de30da9358b47511d62.png)

## Introduzione

Questo sensore DHT11 dispone di un'uscita del segnale digitale calibrata con il sensore combinato di temperatura e umidità. La sua tecnologia garantisce alta affidabilità e un'eccellente stabilità a lungo termine.

Un microcontrollore ad alte prestazioni a 8 bit è integrato nel sensore. Questo sensore include un elemento resistivo e dispositivi di misura della temperatura NTC sensibili all'umidità.

Presenta vantaggi come ottima qualità, risposta rapida, buona immunità alle interferenze e elevato rapporto qualità-prezzo.

Ogni sensore DHT11 dispone di dati di calibrazione estremamente accurati ottenuti in una camera di calibrazione dell'umidità. I coefficienti di calibrazione sono memorizzati nella memoria programma OTP; i sensori interni rilevano i segnali nel processo e si utilizzano questi coefficienti di calibrazione.

È integrato un sistema di interfaccia seriale a filo singolo per renderne l'uso rapido e semplice. Le caratteristiche di dimensioni ridotte, basso consumo e una distanza di trasmissione del segnale fino a 20 metri lo rendono adatto a un'ampia gamma di applicazioni, anche quelle più esigenti.

## Specifiche

- Tensione di alimentazione: +5 V

- Intervallo di temperatura: 0-50 °C errore di ± 2 °C

- Umidità: 20-90% RH ± 5% RH errore

- Interfaccia: Digitale

## Schema di Collegamento

Per prima cosa è necessario preparare i seguenti componenti prima del test.

- Scheda V4.0\*1

- Sensore DHT11\*1

- Cavo USB\*1

- Cavi jumper\*3

Successivamente segui lo schema di collegamento: collega il pin Signal del sensore alla porta Digital 4 della scheda V4.0, il pin negativo al connettore GND e il pin positivo al connettore 5V.

![Illustrazione schema di collegamento](../media/d10a0556ea9e4a8314ee21f8f58ff236.jpeg)

## Codice di Esempio

Per prima cosa scarica la [DHT11Lib](https://github.com/RobTillaart/Arduino/tree/master/libraries/DHTlib). Oppure [visita il sito web](http://playground.arduino.cc/Main/DHTLib)

Copia e incolla il codice seguente nell'ambiente di sviluppo Arduino.

```c
#include <dht.h>

dht DHT;
#define DHT11_PIN 4

void setup() {
  Serial.begin(9600);
  Serial.println(F("DHT11 test"));
  Serial.print(F("DHTlib version: "));
  Serial.println(DHT_LIB_VERSION);
  Serial.println(F("Status,Humidity (%),Temperature (C)"));
}

void loop() {
  const int status = DHT.read11(DHT11_PIN);

  switch (status) {
    case DHTLIB_OK:
      Serial.print(F("OK, "));
      break;
    case DHTLIB_ERROR_CHECKSUM:
      Serial.print(F("Checksum error, "));
      break;
    case DHTLIB_ERROR_TIMEOUT:
      Serial.print(F("Timeout error, "));
      break;
    default:
      Serial.print(F("Unknown error, "));
      break;
  }

  Serial.print(DHT.humidity, 1);
  Serial.print(F(", "));
  Serial.println(DHT.temperature, 1);
  delay(2000);
}
```

## Risultato di esempio

Collega tutto correttamente e carica il codice sopra sulla scheda V4.0.

![Illustrazione del risultato di esempio](../media/cdbb75de748e3e2eb6f709b8f469193d.png)

Poi apri il monitor seriale e imposta la velocità di trasmissione (baud rate) a 9600; alla fine vedrai i valori correnti di temperatura e umidità.

![Illustrazione del risultato di esempio](../media/dffe8c9a0b348f7f4f12cbfe95c090f3.jpeg)

---
