# Lektion 11: Lichtschranke

> **Bausatz:** Keyestudio 48-in-1 Sensorsatz  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P-Platine

![Projekt 11: Lichtschranke Abbildung](../media/8b0f7b3ba3e139eeaeba9bb7f86a946a.png)

## Beschreibung

Der aufrechte Teil dieses Sensors ist ein Infrarot-Emitter und auf der gegenüberliegenden Seite befindet sich ein abgeschirmter Infrarot-Detektor. Indem ein Strahl von Infrarotlicht von einem Ende zum anderen ausgesendet wird, kann der Sensor ein Objekt erkennen, wenn dieses den Strahl unterbricht.

Er wird für viele Anwendungen verwendet, einschließlich optischer Endschalter, Pellet-Ausgabe, allgemeiner Objekterkennung usw.

## Technische Daten

- Versorgungsspannung: 3.3V bis 5V

- Schnittstelle: Digital

- Größe: 30*20mm

- Gewicht: 3g

## Anschlussdiagramm

Bereiten Sie zunächst die folgenden Teile vor, bevor Sie anschließen:

- V4.0-Platine\*1

- Lichtschranken-Modul \*1

- USB-Kabel\*1

- Jumper-Kabel\*3

Verbinden Sie den S-Pin des Moduls mit Digital 3 der V4.0-Platine, verbinden Sie den negativen Pin mit dem GND-Anschluss und den positiven Pin mit dem 5V-Anschluss.

![Anschlussdiagramm Abbildung](../media/669fa42ef7fb576047d6849940a305ba.jpeg)

## Beispielcode

Kopieren Sie den folgenden Code in die Arduino-Software.

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

## Beispielergebnis

Nachdem Sie den Code auf die Platine hochgeladen haben, leuchten sowohl die LED auf der V4.0-Platine als auch die am Modul. Siehe unten.

![Beispielergebnis Abbildung](../media/fa4d06ebf82ec572b7eccf6b706942cb.png)

Wenn Sie ein Stück Papier in den Schlitz des Moduls schieben, wird das Signal unterbrochen und LED1 am Modul schaltet aus.

![Beispielergebnis Abbildung](../media/3ecb941fafc71843148e0e19b6ceda57.png)

---
