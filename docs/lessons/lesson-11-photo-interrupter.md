# Lezione 11: Foto-interruttore

> **Kit:** Keyestudio Kit sensori 48-in-1  
> **Scheda:** Keyestudio V4.0 / scheda compatibile Arduino Uno ATmega328P

![Progetto 11: Foto-interruttore - illustrazione](../media/8b0f7b3ba3e139eeaeba9bb7f86a946a.png)

## Descrizione

La parte verticale di questo sensore è un emettitore a infrarossi e sul lato opposto c’è un rivelatore a infrarossi schermato. Emettendo un fascio di luce infrarossa da un’estremità all’altra, il sensore può rilevare un oggetto quando questo attraversa il fascio.

Viene utilizzato in molte applicazioni, inclusi interruttori di fine corsa ottici, dosaggio di pellet, rilevamento generale di oggetti, ecc.

## Specifiche

- Tensione di alimentazione: 3.3V a 5V

- Interfaccia: Digitale

- Dimensioni: 30*20mm

- Peso: 3g

## Schema di collegamento

Per prima cosa, è necessario preparare le seguenti parti prima del collegamento:

- Scheda V4.0\*1

- Modulo foto-interruttore \*1

- Cavo USB\*1

- Cavi jumper\*3

Collega il pin S del modulo al Digital 3 della scheda V4.0, collega il pin negativo a GND e il pin positivo a 5V.

![Illustrazione dello schema di collegamento](../media/669fa42ef7fb576047d6849940a305ba.jpeg)

## Codice di esempio

Copia e incolla il codice sottostante nel software Arduino.

```c
////////////////////////////////////////////////////////////////////
// photo interrupter module
int Led = 13 ;// define LED Interface
int buttonpin = 3; // define the photo interrupter sensor interface
int val ;// define numeric variables val
void setup ()
{
  pinMode (Led, OUTPUT) ;// define LED as output interface
  pinMode (buttonpin, INPUT) ;// define the photo interrupter sensor output interface
}
void loop ()
{
  val = digitalRead (buttonpin) ;// digital interface will be assigned a value of 3 to read val
  if (val == HIGH) // When the light sensor detects a signal is interrupted, LED flashes
  {
    digitalWrite (Led, HIGH);
  }
  else
  {
    digitalWrite (Led, LOW);
  }
}
////////////////////////////////////////////////////////////////////
```

## Risultato di esempio

Dopo aver caricato il codice sulla scheda, puoi vedere sia il led sulla scheda V4.0 sia quello sul modulo accesi. Come mostrato di seguito.

![Illustrazione del risultato di esempio](../media/fa4d06ebf82ec572b7eccf6b706942cb.png)

Quando si inserisce un foglio nella scanalatura del modulo, il segnale viene interrotto e led1 sul modulo si spegne.

![Illustrazione del risultato di esempio](../media/3ecb941fafc71843148e0e19b6ceda57.png)

---
