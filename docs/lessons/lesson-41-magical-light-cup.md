# Lezione 41: Coppa di Luce Magica

> **Kit:** Kit sensori Keyestudio 48-in-1  
> **Scheda:** Keyestudio V4.0 / scheda compatibile Arduino Uno ATmega328P

![Illustrazione del Progetto 41: Coppa di Luce Magica](../media/dc3acff676b2611f440643f1657b42e7.png)

## Introduzione

Il modulo Coppa di Luce Magica può interagire con ARDUINO. Il principio si basa sulla regolazione della luminosità tramite PWM.

L'interruttore a mercurio presente sul modulo può fornire un segnale digitale e attivare la regolazione PWM. La luminosità dei due moduli verrà modificata contemporaneamente tramite il programma; infine potrai vedere l'effetto di cambiamento come se due serie di coppe stessero versando la luce.

## Specifiche

- Tensione di alimentazione: da 3,3V a 5V

- Interfaccia: Digitale

## Schema di Collegamento

![Illustrazione dello schema di collegamento](../media/9d8d534c60a81608741f85c08d4d0bbe.jpeg)

## Codice di esempio

Copia e incolla il codice seguente nell'IDE Arduino.

```c
///////////////////////////////////////////////////////////////
int LedPinA = 5;
int LedPinB = 6;
int ButtonPinA = 7;
int ButtonPinB = 4;
int buttonStateA = 0;
int buttonStateB = 0;
int brightnessA = 0;
int brightnessB= 255;
void setup()
{
Serial.begin(9600);
pinMode(LedPinA, OUTPUT);
pinMode(LedPinB, OUTPUT);

pinMode(ButtonPinA, INPUT);
pinMode(ButtonPinB, INPUT);
}
void loop()
{
buttonStateA = digitalRead(ButtonPinA);
if (buttonStateA == HIGH && brightnessA != 255)
{
brightnessA ++;
}
if (buttonStateA == LOW && brightnessA != 0)
{
brightnessA --;
}
analogWrite(LedPinB, brightnessA);
Serial.print(brightnessA);

Serial.print("   ");
buttonStateB = digitalRead(ButtonPinB);
if (buttonStateB == HIGH && brightnessB != 0)
{
brightnessB --;
}
if (buttonStateB == LOW && brightnessB != 255)
{
brightnessB++;
}
analogWrite(LedPinA, brightnessB);
Serial.println(brightnessB);
delay(5);
}
///////////////////////////////////////////////////////////////
```

## Risultato di esempio

![Illustrazione del risultato d'esempio](../media/f629888f2fedea9442ba74dc8761fcb3.png)

Collega il circuito come mostrato nello schema sopra e carica correttamente il codice sulla scheda; vedrai che una coppa si accende mentre l'altra è spenta. Quando inclini le due coppe dalla stessa parte, una coppa diventa progressivamente più luminosa mentre l'altra si spegne gradualmente.

![Illustrazione del risultato d'esempio](../media/cfc57515b967d19fcda65ea50bda76f1.png)

---
