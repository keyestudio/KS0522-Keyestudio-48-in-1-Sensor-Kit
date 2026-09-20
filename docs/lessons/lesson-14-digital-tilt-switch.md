# Lektion 14: Digitaler Kippschalter

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P-Platine

![Projekt 14: Digitaler Kippschalter Abbildung](../media/45a40bdcc098c1c4e0efb8246447173c.png)

## Beschreibung

Der Kipp-Sensor ist ein digitaler Neigungsschalter. Er kann als einfacher Kippschalter verwendet werden.

Einfach an unser IO/Sensor-Shield anschließen, einfache Kabelverbindung. Mit dem dedizierten Sensor-Shield und einem Arduino können Sie viele interessante und interaktive Projekte erstellen.

## Spezifikationen

- Versorgungsspannung: 3.3V bis 5V

- Schnittstelle: Digital

- Größe: 30*20mm

- Gewicht: 3g

## Anschlussdiagramm

Verbinden Sie den S-Pin des Moduls mit Digital 3 des V4.0-Boards, verbinden Sie den negativen Pin mit dem GND-Anschluss und den positiven Pin mit dem 5V-Anschluss.

![Anschlussdiagramm Abbildung](../media/b909cdd6f697779371498723dc1407ab.jpeg)

## Beispielcode

Kopieren Sie den untenstehenden Code in die Arduino-Software.

```c
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
```

## Beispielergebnis

Nachdem die Verdrahtung abgeschlossen und die Stromversorgung eingeschaltet ist, laden Sie den Code auf das V4.0-Board hoch.

![Beispielergebnis Abbildung](../media/d6a0aa9af1e43265114eec8570ac0f3c.png)

Kippen Sie dann den Sensor; Sie werden sehen, dass die LED am Sensor aufleuchtet. Wie unten gezeigt.

![Beispielergebnis Abbildung](../media/6c4a144c26675a100bffa806c532736c.png)

---
