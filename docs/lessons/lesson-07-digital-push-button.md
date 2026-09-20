# Lektion 07: Digitaler Taster

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-compatible ATmega328P board

![Projekt 7: Digitaler Taster Abbildung](../media/a8707354e54ea51bb92584f791ae79e5.png)

## Beschreibung

Dies ist ein einfaches Tastermodul. Du kannst es einfach an ein IO-Shield anschließen, um deinen ersten Versuch mit Arduino zu starten.

## Eigenschaften

- Breiter Spannungsbereich von 3.3V bis 5V

- Leicht erkennbare Schnittstellen der Sensoren ("A" für Analog und "D" für Digital)

- Standardisierte Montagebohrung

- Klare Symbolillustrationen

- Hochwertiger Anschluss

- Einfach zu stecken und zu bedienen

- Großer Taster und hochwertige Kappe

- Ermöglicht interessante und interaktive Arbeiten

## Technische Daten

- Versorgungsspannung: 3.3V bis 5V

- Schnittstelle: Digital

- Abmessungen: 30*20mm

- Gewicht: 4g

## Anschlussdiagramm

Bereite zunächst die folgenden Teile vor, bevor du die Verbindung herstellst:

- V4.0 Board*1

- Tastermodul*1

- USB-Kabel*1

- Jumperkabel*3

Verbinde den S-Pin des Moduls mit Digital 3 des V4.0 board, verbinde den negativen Pin mit dem GND-Anschluss und den positiven Pin mit dem 5V-Anschluss.

![Anschlussdiagramm Abbildung](../media/6ec73b961481bf0794572a842c5231fa.jpeg)

## Beispielcode

Kopiere den untenstehenden Code in die Arduino-Software.

```c
////////////////////////////////////////////////////////////////////
/* # When you push the digital button, the Led 13 on the board will be turned on. Otherwise,the led is turned off.
*/
int ledPin = 13;                // choose the pin for the LED
int inputPin = 3;               // Connect sensor to input pin 3
void setup() {
  pinMode(ledPin, OUTPUT);      // set LED as output
  pinMode(inputPin, INPUT);     // set pushbutton as input
}
void loop(){
  int val = digitalRead(inputPin);  // read input value
  if (val == HIGH) {            // check if the input is HIGH
    digitalWrite(ledPin, LOW);  // turn LED OFF
  } else {
    digitalWrite(ledPin, HIGH); // turn LED ON
  }
}
////////////////////////////////////////////////////////////////////
```

## Beispielergebnis

Verdrahte alles wie in der unten gezeigten Abbildung und lade dann den Code auf das V4.0 board hoch.

Wenn du den digitalen Taster drückst, leuchtet die LED 13 auf dem V4.0 board. Wenn du den Taster loslässt, geht die LED aus. Siehe unten.

![Beispielergebnis Abbildung](../media/ac03d3fa1c0f5de7dae18c6e64406e60.png)

---
