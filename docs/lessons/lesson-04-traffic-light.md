# Lezione 04: Semaforo

> **Kit:** Keyestudio 48-in-1 Sensor Kit  
> **Scheda:** Keyestudio V4.0 / Scheda ATmega328P compatibile con Arduino Uno

![Progetto 4: Illustrazione del semaforo](../media/a20653cffac8985dc4919614540ac367.jpeg)

## Descrizione

Quando si impara a usare un microcontrollore, si utilizzano di solito tre LED — rosso, verde e giallo — per simulare il lampeggio di un semaforo tramite collegamenti esterni.

Questa volta abbiamo progettato appositamente questo modulo, molto comodo per il cablaggio; sul modulo sono presenti i LED rosso, giallo e verde.

Questo modulo è completamente compatibile con il microcontrollore Arduino e con il sistema Raspberry Pi.

## Specifiche

- Tensione di funzionamento: 3.3-5V

- Tipo di interfaccia: digitale

- Connettore PH2.54

## Diagramma di collegamento

Per prima cosa, è necessario preparare le seguenti parti prima del collegamento:

- Scheda V4.0\*1

- Modulo semaforo \*1

- Cavo USB\*1

- Cavi jumper\*4

Collegare il pin R del modulo al Digital 5 della scheda V4.0, collegare il pin Y al Digital 4, il pin G al Digital 3, il pin GND alla porta di massa.

![Illustrazione del diagramma di collegamento](../media/b6884692ce41d05d4afb167af5b2239d.jpeg)

## Codice di esempio

Copia e incolla il codice seguente nel software Arduino.

```c
////////////////////////////////////////////////////////////////////
int redled =5; // initialize digital pin 5.
int yellowled =4; // initialize digital pin 4.
int greenled =3; // initialize digital pin 3.
void setup()
{
pinMode(redled, OUTPUT);// set the pin with red LED as “output”
pinMode(yellowled, OUTPUT); // set the pin with yellow LED as “output”
pinMode(greenled, OUTPUT); // set the pin with green LED as “output”
}
void loop()
{
digitalWrite(greenled, HIGH);//// turn on green LED
delay(5000);// wait 5 seconds
digitalWrite(greenled, LOW); // turn off green LED
for(int i=0;i<3;i++)// blinks for 3 times
{
delay(500);// wait 0.5 seconds
digitalWrite(yellowled, HIGH);// turn on yellow LED
delay(500);// wait 0.5 seconds
digitalWrite(yellowled, LOW);// turn off yellow LED
}
delay(500);// wait 0.5 seconds
digitalWrite(redled, HIGH);// turn on red LED
delay(5000);// wait 5 seconds
digitalWrite(redled, LOW);// turn off red LED
}
////////////////////////////////////////////////////////////////////
```

## Risultato di esempio

Dopo aver caricato il codice e alimentato, i tre LED sul modulo simuleranno automaticamente l'accensione e lo spegnimento del semaforo in modo ciclico.

![Illustrazione del risultato](../media/6dd1ff8660b0a62795bd53fc6b6ff591.png)

---
