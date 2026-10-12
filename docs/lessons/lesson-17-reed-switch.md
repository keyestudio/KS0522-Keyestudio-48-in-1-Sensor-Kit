# Lezione 17: Interruttore Reed

> **Kit:** Keyestudio Kit sensori 48-in-1  
> **Scheda:** Keyestudio V4.0 / scheda compatibile Arduino Uno (ATmega328P)

![Progetto 17: illustrazione Interruttore Reed](../media/e580999515f6522eb603ea723bf62173.png)

## Descrizione

L'interruttore reed è un interruttore speciale e un componente principale per relè reed e interruttori di prossimità.

Un interruttore reed è solitamente costituito da due materiali magnetici morbidi e contatti a lama metallici che si aprono quando non è presente un campo magnetico.

Inoltre, alcuni interruttori reed sono dotati di una terza lama che funge da contatto normalmente chiuso. Questi contatti a lama sono incapsulati in un tubo di vetro pieno di gas inerti (come azoto ed elio) o in un tubo di vetro sottovuoto.

Le lame incapsulate nel tubo di vetro sono disposte in parallelo con le estremità sovrapposte. Viene riservata una certa distanza o un contatto reciproco per costituire i contatti normalmente aperti o normalmente chiusi dell'interruttore.

L'interruttore reed può essere usato per conteggio, come finecorsa o per altri scopi.

Ad esempio, un contachilometri per bicicletta può essere costituito applicando un magnete al pneumatico e montando l'interruttore reed accanto.

È possibile montare l'interruttore reed sulla porta per scopi di allarme o come interruttore.

L'interruttore reed è ampiamente utilizzato in elettrodomestici, automobili, comunicazioni, industria, sanità e ambito sicurezza.

Inoltre, può essere applicato ad altri sensori e dispositivi elettrici come misuratori di liquidi, magneti per porte, relè reed, sensori di livello dell'olio e sensori di prossimità (sensori magnetici). Può essere utilizzato in ambienti ad alto rischio.

## Specifiche

1. Tensione di funzionamento: DC 3.3V-5V

2. Corrente di funzionamento: ≥20mA

3. Temperatura di funzionamento: －10℃ a ＋50℃

4. Distanza di rilevamento: ≤10mm

5. Interfaccia IO: 3 fili (-/+/S)

6. Dimensioni: 30\*20mm

7. Peso: 3g

## Schema di collegamento

Collegare il pin S del modulo al Digital 3 della scheda V4.0, collegare il pin negativo al connettore GND, il pin positivo al connettore 5V.

![Illustrazione schema di collegamento](../media/ad39b511b42657baed492704a9c84b13.jpeg)

## Codice di esempio

Copia e incolla il codice seguente nell'IDE Arduino.

```c
////////////////////////////////////////////////////////////////////
int Led=13;//define LED interface
int buttonpin=3; //define magnetic ring sensor interface
int val;//define digital variable val
void setup()
{
pinMode(Led,OUTPUT);//define LED as output interface
pinMode(buttonpin,INPUT);//define magnetic ring sensor as output interface
 }
void loop()
{

val=digitalRead(buttonpin);// read and assign the value of digital interface 3 to val

if(val==HIGH)//When a signal is detected by magnetic ring sensor, LED will flash
{
digitalWrite(Led,HIGH);
}
else
{
digitalWrite(Led,LOW);
}
}
////////////////////////////////////////////////////////////////////
```

## Risultato di esempio

Dopo aver effettuato i collegamenti e alimentato la scheda, caricato correttamente il codice sulla scheda, puoi vedere che il D13 led sulla scheda V4.0 è acceso.

![Illustrazione risultato di esempio](../media/a2f983d5a5b324f55e3c0994458d4cbc.png)

Poi avviciniamo alcune sfere magnetiche al sensore. Quando il sensore rileva il campo magnetico, il led sul sensore si accende mentre il D13 led si spegne.

![Illustrazione risultato di esempio](../media/ecbec914abc799076513f5c61149b004.png)

---
