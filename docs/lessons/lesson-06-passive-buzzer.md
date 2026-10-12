# Lezione 06: Buzzer Passivo

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Scheda:** Keyestudio V4.0 / Scheda compatibile Arduino Uno con ATmega328P

![Illustrazione Progetto 6: Buzzer Passivo](../media/1bd2e3afebf5a0d3712fe42092b0a1b4.png)

## Descrizione

Possiamo utilizzare Arduino per realizzare molte opere interattive, delle quali la più comunemente usata è la visualizzazione acustica e ottica. Il circuito in questo esperimento può produrre suono.

Normalmente, l'esperimento può essere eseguito con un buzzer o un altoparlante, mentre il buzzer è più semplice e facile da usare.

Il buzzer introdotto qui è un buzzer passivo. Non può essere azionato da solo, ma richiede impulsi esterni a determinate frequenze. Frequenze diverse producono suoni diversi. Puoi usare Arduino per programmare la melodia di una canzone; è piuttosto divertente e semplice.

## Specifiche

- Tensione di esercizio: 3.3-5V

- Tipo di interfaccia: digitale

- Dimensioni: 30\*20mm

- Peso: 4g

## Diagramma di collegamento

Per prima cosa, prepara i seguenti componenti prima del collegamento:

- Scheda V4.0*1

- Modulo buzzer passivo*1

- Cavo USB*1

- Cavi jumper*3

Collega il pin S del modulo a Digital 3 della scheda V4.0, collega il pin negativo alla porta GND, il pin positivo alla porta 5V.

![Illustrazione Diagramma di collegamento](../media/e9e7ba383738c3b6be85a1f3c97e5385.jpeg)

## Codice di esempio

Copia e incolla il codice qui sotto nell'IDE di Arduino.

```c
////////////////////////////////////////////////////////////////////
int buzzer=3;//set digital IO pin of the buzzer
void setup()
{
pinMode(buzzer,OUTPUT);// set digital IO pin pattern, OUTPUT to be output
}
void loop()
{ unsigned char i,j;//define variable
while(1)
{ for(i=0;i<80;i++)// output a frequency sound
{ digitalWrite(buzzer,HIGH);// sound
delay(1);//delay1ms
digitalWrite(buzzer,LOW);//not sound
delay(1);//ms delay
}
for(i=0;i<100;i++)// output a frequency sound
{
digitalWrite(buzzer,HIGH);// sound
digitalWrite(buzzer,LOW);//not sound
delay(2);//2ms delay
}
}
}
////////////////////////////////////////////////////////////////////
```

## Risultato di esempio

Dopo aver caricato il codice sulla scheda, il buzzer emetterà un suono.

![Illustrazione risultato di esempio](../media/9b29eccd437694e479a836b7da66d500.png)

---
