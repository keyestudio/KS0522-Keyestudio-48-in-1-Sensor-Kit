# Lezione 19: Temperatura analogica

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Scheda:** Scheda Keyestudio V4.0 / compatibile con Arduino Uno ATmega328P

![Progetto 19: Temperatura analogica (illustrazione)](../media/8269d6536e383bcc592da1ae98bc3661.png)

## Descrizione

Questo modulo si basa sul principio di funzionamento di un termistore (la resistenza varia al variare della temperatura ambientale).

Può rilevare le variazioni di temperatura circostanti e inviare i dati all'IO analogico della scheda Arduino.

Basta convertire i dati di uscita del sensore in gradi Celsius tramite una semplice programmazione e visualizzarli sul monitor.

È comodo ed efficace, perciò è ampiamente utilizzato in giardinaggio, sistemi di allarme domestici e altri dispositivi.

## Specifiche

- Tipo di interfaccia: analogico

- Tensione di funzionamento: 5V

- Intervallo di temperatura: -55℃～315℃

- Dimensioni: 30\*20mm

- Peso: 3g

## Schema di collegamento

Per prima cosa, prepara i seguenti componenti prima del collegamento:

- Scheda V4.0\*1

- Sensore di temperatura analogico\*1

- Cavo USB\*1

- Cavi di collegamento\*3

Collega il pin S del modulo ad Analog A0 della scheda V4.0, il pin negativo a GND, il pin positivo a 5V.

![Schema di collegamento (illustrazione)](../media/330d37f05ac235a850d06726284243a5.jpeg)

## Codice di esempio

Copia e incolla il codice sottostante nell'IDE di Arduino.

```c
////////////////////////////////////////////////////////////////////
void setup()
{Serial.begin(9600);
}
// the loop routine runs over and over again forever:
void loop()
{int sensorValue = analogRead(A0);
Serial.println(sensorValue);
  delay(1); }
////////////////////////////////////////////////////////////////////
```

Il codice sopra è solo per il valore analogico.

Puoi osservare che il valore analogico cambia in funzione della temperatura ambientale, ma la variazione non è molto evidente.

Risolviamo questo usando la seguente equazione. Quindi carica il codice qui sotto sulla scheda Arduino. Il valore letto dalla porta seriale sarà simile alla temperatura reale. es. La temperatura al momento è 30°C.

```c
////////////////////////////////////////////////////////////////////
#include <math.h>
void setup()
{
   Serial.begin(9600);
}
void loop()
{
  double val=analogRead(0);
  double fenya=(val/1023)*5;
  double r=(5-fenya)/fenya*4700;
  Serial.println( 1/(  log(r/10000) /3950 + 1/(25+273.15))-273.15);
  delay(1000);
}
////////////////////////////////////////////////////////////////////
```

## Esempio di risultato

![Esempio di risultato (illustrazione)](../media/9ae4e8962bf9d46ceeb3ca0c2e560f43.png)

Dopo aver effettuato i collegamenti e alimentato come nella figura sopra, carica correttamente il codice sulla scheda e apri il monitor seriale dell'IDE di Arduino: vedrai il valore della temperatura corrente.

![Esempio di risultato (illustrazione)](../media/005b4c639460eba8158f99637f03686b.jpeg)

---
