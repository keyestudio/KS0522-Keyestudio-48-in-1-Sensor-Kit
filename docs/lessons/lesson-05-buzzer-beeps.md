# Lektion 05: Summer-Piepen

> **Bausatz:** Keyestudio 48-in-1 Sensor-Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatible ATmega328P-Platine

![Projekt 5: Summer-Piepen Illustration](../media/88c349b0602dfa2e166faabc13cb2f20.png)

## Beschreibung

Hier ist das einfachste Klangmodul. Du kannst es mit hohem oder niedrigem Pegel ansteuern. Durch Ändern der Frequenz, mit der es brummt, lassen sich unterschiedliche Töne erzeugen.

Dieses Modul wird häufig in Alltagsgeräten wie PC, Kühlschrank, Telefonen usw. verwendet.

Außerdem kannst du mit diesem kleinen, aber nützlichen Modul viele interessante interaktive Projekte erstellen. Probier es einfach aus!! Du wirst den von ihm erzeugten elektronischen Klang sehr faszinierend finden.

## Spezifikation

- Betriebsspannung: 3.3-5v

- Schnittstellentyp: digital

- Größe: 30*20mm

- Gewicht: 4g

## Anschlussdiagramm

Verbinde den S-Pin des Moduls mit Digital 3 der V4.0-Platine, den Minus-Pin mit dem GND-Anschluss und den Plus-Pin mit dem 5V-Anschluss.

![Anschlussdiagramm Illustration](../media/173f2e9a828b0b20d76dc07de57892c1.jpeg)

## Beispielcode

Kopiere den folgenden Code in die Arduino-Software.

```c
////////////////////////////////////////////////////////////////////
int buzzPin =3;    //Connect Buzzer on Digital Pin3
 void setup()
 {
  pinMode(buzzPin, OUTPUT);
}
 void loop()
{
  digitalWrite(buzzPin, HIGH);
  delay(1);
  digitalWrite(buzzPin, LOW);
  delay(1);
}
////////////////////////////////////////////////////////////////////
```

## Beispielergebnis

Nachdem der Code auf die Platine hochgeladen wurde, gibt der Summer einen Ton von sich.

![Beispielergebnis Illustration](../media/109e3287bff29d1d1fb88369d6705ad3.png)

---
