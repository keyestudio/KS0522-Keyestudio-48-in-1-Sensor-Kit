# Lektion 41: Magischer Lichtbecher

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P-Platine

![Projekt 41: Magischer Lichtbecher Abbildung](../media/dc3acff676b2611f440643f1657b42e7.png)

## Einführung

Das Modul des magischen Lichtbechers kann mit Arduino interagieren. Das Prinzip beruht auf PWM-Dimmung.

Der Quecksilberschalter auf dem Modul liefert ein digitales Signal und löst die PWM-Regelung aus. Die Helligkeit von zwei Modulen wird über das Programm gemeinsam verändert, sodass man schließlich den Effekt sehen kann, dass zwei Becher Licht „ausgießen“.

## Technische Daten

- Versorgungsspannung: 3.3V bis 5V

- Schnittstelle: digital

## Anschlussdiagramm

![Anschlussdiagramm Abbildung](../media/9d8d534c60a81608741f85c08d4d0bbe.jpeg)

## Beispielcode

Kopiere den untenstehenden Code in die Arduino-Software.

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

## Beispielergebnis

![Beispielergebnis Abbildung](../media/f629888f2fedea9442ba74dc8761fcb3.png)

Verdrahte alles wie im obigen Diagramm und lade den Code auf die Platine hoch. Dann siehst du, dass ein Becher leuchtet, während der andere ausgeschaltet ist. Wenn du diese beiden Becher zur gleichen Seite kippst, wird ein Becher allmählich heller, während der andere allmählich dunkler wird.

![Beispielergebnis Abbildung](../media/cfc57515b967d19fcda65ea50bda76f1.png)

---
