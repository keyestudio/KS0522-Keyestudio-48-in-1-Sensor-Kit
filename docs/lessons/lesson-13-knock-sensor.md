# Lezione 13: Sensore Knock

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Scheda:** Keyestudio V4.0 / scheda compatibile Arduino Uno ATmega328P

![Progetto 13: Illustrazione del sensore knock](../media/cef729e5b57059bc14518b0e2fdd2817.png)

## Descrizione

Questo modulo è un sensore knock. Quando lo colpisci, può inviare un segnale momentaneo.

Puoi combinarlo con Arduino per realizzare esperimenti interessanti, ad esempio una batteria elettronica.

## Specifiche

- Tensione di funzionamento: 5V

- Dimensioni: 30\*20mm

- Peso: 3g

## Schema di collegamento

Per prima cosa, prepara i seguenti componenti prima del collegamento:

- Scheda V4.0\*1

- Sensore knock \*1

- Cavo USB\*1

- Cavi jumper\*3

Collega il pin S del modulo al pin digitale 3 della scheda V4.0, il pin negativo a GND e il pin positivo a 5V.

![Illustrazione dello schema di collegamento](../media/1b9c27f145275e7a38d06763114f1847.jpeg)

## Codice di esempio

Copia e incolla il codice seguente nell'IDE Arduino.

```c
////////////////////////////////////////////////////////////////////
int Led=13;//define LED interface
int Shock=3;//define knock sensor interface
int val;//define digital variable val
void setup()
{
pinMode(Led,OUTPUT);//define LED to be output interface
pinMode(Shock,INPUT);//define knock sensor to be output interface
}
void loop()
{
val=digitalRead(Shock);//read the value of interface3 and evaluate it to val
if(val==HIGH)//when the knock sensor detect a signal, LED will be flashing
{
digitalWrite(Led,LOW);
}
else
{
digitalWrite(Led,HIGH);
}
}
////////////////////////////////////////////////////////////////////
```

![Illustrazione del codice di esempio](../media/c3fc14de7267b517a739268ed5b88674.png)

## Esempio di risultato

Dopo aver effettuato i collegamenti e alimentato la scheda come indicato, e aver caricato correttamente il codice, colpisci il sensore: vedrai accendersi sia il LED D13 sulla scheda V4.0 sia il LED D1 sul sensore.

---
