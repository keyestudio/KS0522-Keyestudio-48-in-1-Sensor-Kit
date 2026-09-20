# Lektion 15: Kapazitiver Touch

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatibles ATmega328P-Platine

![Projekt 15: Kapazitiver Touch](../media/bceabc7d4302bd41ae380e179a281314.png)

## Beschreibung

Hast du genug von mechanischen Klicktasten? Dann probiere unseren kapazitiven Touch-Sensor. Touch-Sensoren werden häufig in elektronischen Geräten verwendet. Rüste dein Arduino-Projekt mit diesem Sensor auf, um es cooler zu machen.

Dieser kleine Sensor erkennt Berührungen von Körper und Metall und gibt ein High-/Low-Signal aus. Selbst wenn er durch Stoff oder Papier isoliert ist, kann er die Berührung noch wahrnehmen. Allerdings nimmt die Empfindlichkeit ab, je dicker die Isolationsschicht wird.

Wir werden diese Sensormodule weiter verbessern, um dir ein besseres Erlebnis zu bieten.

## Spezifikation

- Versorgungsspannung: 3.3V bis 5V

- Schnittstelle: Digital

- Größe: 30*20mm

- Gewicht: 3g

## Anschlussdiagramm

Zuerst musst du vor dem Anschluss die folgenden Teile vorbereiten:

- V4.0-Platine*1

- Kapazitiver Touch-Sensor*1

- USB-Kabel*1

- Jumperkabel*3

Verbinde den S-Pin des Moduls mit Digital 2 der V4.0-Platine, den negativen Pin mit dem GND-Anschluss und den positiven Pin mit dem 5V-Anschluss.

![Anschlussdiagramm](../media/18193a53377b60f43fb583c29337f3aa.jpeg)

## Beispielcode

Kopiere und füge den folgenden Code in die Arduino-Software ein.

```c
const uint8_t ledPin = 13;  // On-board LED.
const uint8_t touchPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(touchPin, INPUT);
}

void loop() {
  const int touched = digitalRead(touchPin);
  digitalWrite(ledPin, touched == HIGH ? HIGH : LOW);
}
```

## Beispielergebnis

Nachdem die Verkabelung abgeschlossen und die Platine mit Strom versorgt wurde und der Code erfolgreich hochgeladen ist, berühre den Sensor mit deinem Finger. Sowohl die D2-LED am Sensor als auch die D13-Anzeige an der V4.0-Platine leuchten. Andernfalls sind diese beiden Anzeigen ausgeschaltet.

![Beispielergebnis](../media/31a751feed0f21236458b93eed14af9f.png)

---
