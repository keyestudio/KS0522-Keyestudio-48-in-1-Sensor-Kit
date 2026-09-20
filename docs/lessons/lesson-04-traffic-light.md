# Lektion 04: Ampel

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P-Platine

![Projekt 4: Ampel Illustration](../media/a20653cffac8985dc4919614540ac367.jpeg)

## Beschreibung

Beim Erlernen des Mikrocontrollers verwendet man üblicherweise drei LEDs – nämlich rote, grüne und gelbe Leuchten –, um per externer Verbindung das Blinken einer Ampel zu simulieren.

Für dieses Projekt haben wir ein Modul speziell entworfen, das sehr praktisch zu verdrahten ist. Auf dem Modul sind die rote, gelbe und grüne LED sichtbar.

Dieses Modul ist vollständig kompatibel mit Arduino-Mikrocontrollern und dem Raspberry Pi.

## Spezifikation

- Betriebsspannung: 3.3-5v

- Schnittstellentyp: digital

- PH2.54 Socket

## Anschlussdiagramm

Zuerst müssen Sie vor dem Anschluss die folgenden Teile bereitstellen:

- V4.0 Platine\*1

- Ampelmodul \*1

- USB-Kabel\*1

- Jumperkabel\*4

Verbinden Sie den R-Pin des Moduls mit Digital 5 der V4.0-Platine, den Y-Pin mit Digital 4, den G-Pin mit Digital 3 und den GND-Pin mit dem Masseanschluss.

![Anschlussdiagramm Abbildung](../media/b6884692ce41d05d4afb167af5b2239d.jpeg)

## Beispielcode

Kopieren Sie den folgenden Code in die Arduino-Software.

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

## Beispielergebnis

Nachdem der Code hochgeladen und die Stromversorgung aktiviert wurde, simulieren die drei LEDs auf dem Modul automatisch zyklisch das Ein- und Ausschalten einer Ampel.

![Beispielergebnis Abbildung](../media/6dd1ff8660b0a62795bd53fc6b6ff591.png)

---
