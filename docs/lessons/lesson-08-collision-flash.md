# Lektion 08: Kollisionsblitz

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatibles ATmega328P Board

![Projekt 8: Kollisionsblitz-Illustration](../media/29c4641406064a4f1df5d59aefbca480.png)

## Beschreibung

Der Kollisionssensor, auch als elektronischer Schalter bekannt, ist ein digitales Ein-/Aus-Eingangsmodul, das für grundlegende Elektroniklernzwecke notwendig ist.

Durch Programmierung kann er zur Steuerung von Licht- und Schallgeräten, zur Tastenwahlfunktion eines LCD-Displays usw. eingesetzt werden.

Über ein 3P-Sensorkabel mit einem Sensor-Shield verbunden, kann er auf einer 4WD-AL-Legierungs-Mobilrobotplattform montiert werden, um eine Kollisionsdetektionsfunktion zu realisieren. Das ist sowohl praktisch als auch effizient.

Sie können einen Kollisionsblinker mit dem Kollisionsmodul und der eingebauten LED an Schnittstelle 13 erstellen. Verbinden Sie den Kollisionssensor mit Pin 3. Wenn der Kollisionssensor ein Kollisionssignal erkennt, leuchten die LEDs sowohl auf dem Hauptboard als auch am Modul gleichzeitig.

## Parameter

1. Wenn eine Kollision an der Vorderseite des installierten Kollisionsmoduls erfolgt, gibt das Modul ein Low-Signal aus; keine Kollision = High-Signal.

2. Das Modul verfügt über eine M3-Befestigungsbohrung, praktisch zur Fixierung an einem Fahrzeug.

3. Mit Schalterstatusanzeige: Bei Kollision leuchtet die Anzeige; ohne Kollision ist sie aus.

## Pindefinition

1. Positive Klemme (+): an eine 3V–12V-Stromversorgung anschließen

2. Negative Klemme (-): an GND anschließen

3. Signalklemme (S): High-/Low-Pegel-Ausgang

## Anschlussdiagramm

Zuerst müssen Sie vor dem Anschluss folgende Teile vorbereiten:

- V4.0 Platine\*1

- Kollisionsmodul \*1

- USB-Kabel\*1

- Jumperkabel\*3

Verbinden Sie den S-Pin des Moduls mit Digital 3 des V4.0-Boards, verbinden Sie die negative Klemme mit dem GND-Anschluss und die positive Klemme mit dem 5V-Anschluss.

![Anschlussdiagramm-Illustration](../media/a4ec0b7f8fd95fb2d6bb5c06ca0776f0.jpeg)

## Beispielcode

Kopieren Sie den folgenden Code in die Arduino-Software.

```c
const uint8_t ledPin = 13;
const uint8_t collisionPin = 3;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(collisionPin, INPUT);
}

void loop() {
  const int state = digitalRead(collisionPin);
  digitalWrite(ledPin, state == HIGH ? LOW : HIGH);
}
```

## Beispielergebnis

Verdrahten Sie alles korrekt und laden Sie dann den Code auf das Board hoch.

Wenn ein Objekt den Schalter des Sensors trifft, leuchten sowohl die LED am Sensor als auch die LED 13 auf dem Board auf.

---
