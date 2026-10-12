# Lezione 18: Sensore di movimento PIR

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Scheda:** Keyestudio V4.0 / Scheda compatibile Arduino Uno ATmega328P

![Illustrazione Progetto 18: Sensore di movimento PIR](../media/ce608db25742f19fdf6eceda756a59d9.png)

## Descrizione

Il sensore di movimento a infrarossi piroelettrico può rilevare segnali infrarossi provenienti da una persona in movimento o da un animale in movimento e fornire segnali di commutazione in uscita.

Può essere applicato in molteplici occasioni per rilevare lo spostamento del corpo umano.

I tradizionali sensori a infrarossi piroelettrici richiedono un rilevatore piroelettrico del corpo, un chip professionale e circuiti periferici complessi, pertanto le dimensioni sono maggiori, con circuito complesso e minore affidabilità.

Ora presentiamo questo nuovo sensore di movimento a infrarossi piroelettrico, progettato appositamente per Arduino.

Utilizza un sensore piroelettrico integrato digitale per il corpo, con dimensioni più ridotte, maggiore affidabilità, minore consumo energetico e circuito periferico più semplice.

## Specifiche

- Tensione di ingresso: 3.3 \~ 5V, massimo 6V

- Corrente di lavoro: 15uA

- Temperatura di lavoro: -20 \~ 85 ℃

- Tensione di uscita: Livello alto 3V, Livello basso 0V

- Tempo di ritardo di uscita (livello alto): circa 2.3 a 3 secondi

- Angolo di rilevamento: 100°

- Distanza di rilevamento: 7 metri

- LED indicatore di uscita (se l'uscita è HIGH, si accenderà)

- Corrente limite per il pin: 100mA

- Dimensioni: 30*20mm

- Peso: 4g

## Schema di collegamento

Per il collegamento, prepara i seguenti componenti:

- Scheda V4.0*1

- Sensore di movimento PIR*1

- Cavo USB*1

- Cavi jumper*3

Collega il pin S del modulo a Digital 3 della scheda V4.0, collega il pin negativo a GND e il pin positivo a 5V.

![Schema di collegamento illustrazione](../media/01970d510c03a8c7aa3ef0c13ea70cff.jpeg)

## Codice di esempio

Copia e incolla il codice sottostante nell'IDE Arduino.

```c
////////////////////////////////////////////////////////////////////
byte sensorPin = 3;
byte indicator = 13;
void setup()
{
  pinMode(sensorPin,INPUT);
  pinMode(indicator,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  byte state = digitalRead(sensorPin);
  digitalWrite(indicator,state);
  if(state == 1)Serial.println("Somebody is in this area!");
  else if(state == 0)Serial.println("No one!");
  delay(500);
}
////////////////////////////////////////////////////////////////////
```

## Esempio di risultato

Completati i collegamenti e alimentato il sistema, caricato correttamente il codice, se il sensore rileva qualcuno che si muove nelle vicinanze, l'indicatore D13 sulla scheda V4.0 si accenderà e "C'è qualcuno in questa zona!" verrà visualizzato nel monitor seriale del software Arduino.

Se non viene rilevato alcun movimento, l'indicatore D13 sulla scheda V4.0 sarà spento e "Nessuno!" verrà visualizzato nel monitor seriale.

![Esempio di risultato illustrazione](../media/e25d28654311fa7820a1886a285353e5.png)

![Esempio di risultato illustrazione](../media/9b6209c8ce5b4be73f8378d21b639d28.jpeg)

---
