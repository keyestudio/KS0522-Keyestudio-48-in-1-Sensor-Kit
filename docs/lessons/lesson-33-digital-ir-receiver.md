# Lezione 33: Ricevitore IR digitale

> **Kit:** Kit sensori Keyestudio 48-in-1  
> **Scheda:** Keyestudio V4.0 / scheda compatibile Arduino Uno ATmega328P

![Progetto 33: illustrazione Ricevitore IR digitale](../media/f64f21b6ca681f928c3318bd2d33a017.png)

## Descrizione

L'IR è ampiamente utilizzato nei telecomandi. Con questo ricevitore IR, un progetto Arduino è in grado di ricevere comandi da qualsiasi telecomando IR se si dispone del decodificatore corretto. Inoltre, sarà facile realizzare il proprio controller IR usando un trasmettitore IR.

## Specifiche

- Alimentazione: 5V

- Interfaccia: Digitale

- Frequenza di modulazione: 38Khz

- Connettore modulo: JST PH2.0

- Dimensioni: 30*20mm

- Peso: 4g

## Schema di collegamento

Prima di tutto devi preparare le seguenti parti prima del collegamento.

- Scheda V4.0\*1

- Modulo ricevitore IR\*1

- Cavo USB\*1

- Cavi jumper\*3

Collega il pin S del modulo a Digital 11 della scheda V4.0, collega il pin negativo al connettore GND, il pin positivo al connettore 5V.

![Illustrazione schema di collegamento](../media/687d429fe6360707f95fb6c5ddfa2ca7.jpeg)

Nel codice di esempio qui sotto è utilizzato il pin Digital 11; puoi modificare il cablaggio o il codice di esempio per farli corrispondere.

## Codice di esempio

Copia e incolla il codice qui sotto nel software Arduino.

```c
///////////////////////////////////////////////////////////////
#include <IRremote.h>
 int RECV_PIN = 11;
 IRrecv irrecv(RECV_PIN);
 decode_results results;
 void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn(); // Start the receiver
}
 void loop() {
  if (irrecv.decode(&results)) {
    Serial.println(results.value, HEX);
    irrecv.resume(); // Receive the next value
  }
}

///////////////////////////////////////////////////////////////
```

**Nota:** prima di compilare il codice, ricordati di inserire la libreria nella directory libraries dell'IDE Arduino. Altrimenti la compilazione fallirà.

La libreria IR Remote include alcuni esempi per l'invio e la ricezione.

<https://github.com/shirriff/Arduino-IRremote>

## Risultato di esempio

![Illustrazione risultato di esempio](../media/2692333113be48ffa11c27649d18dcb8.png)

Una volta completato il cablaggio e caricato il codice, controlla il modulo ricevitore IR con un telecomando a infrarossi; il LED D1 lampeggerà.

![Illustrazione risultato di esempio](../media/4bb52e2957e3aaeace252021e7084c95.png)

---
