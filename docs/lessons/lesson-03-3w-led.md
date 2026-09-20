# Lektion 03: 3W-LED

> **Bausatz:** Keyestudio 48-in-1 Sensor Kit  
> **Platine:** Keyestudio V4.0 / Arduino Uno-kompatibles ATmega328P-Board

![Projekt 3: 3W-LED Abbildung](../media/0b1110577bfde7df3b6aec41d5b21b28.png)

## Beschreibung

Dieses LED-Modul hat eine hohe Helligkeit, da die verbauten LED-Chips 3W Leistung haben.
Sie können dieses Modul in Arduino-Projekten einsetzen, ideal für Roboter- oder Such- und
Rettungsplattform-Anwendungen.

Beispielsweise können intelligente Roboter dieses Modul zur Beleuchtung verwenden.
Bitte beachten Sie aus Sicherheitsgründen, dass das LED-Licht nicht direkt auf menschliche Augen gerichtet werden darf.

## Technische Daten

- Farbtemperatur: 6000\~7000K

- Lichtstrom: 180\~210lm

- Strom: 700\~750mA

- Leistung: 3W

- Abstrahlwinkel: 140 Grad

- Arbeitstemperatur: -50\~80℃

- Lagertemperatur: -50\~100℃

- Hochleistungs-LED-Modul, gesteuert über I/O-Port des Mikrocontrollers

- I/O-Typ: Digital

- Versorgungsspannung: 3.3V bis 5V

- Größe: 40x28mm

- Gewicht: 6g

## Anschlussdiagramm

Bereiten Sie vor dem Anschließen zunächst die folgenden Teile vor:

- V4.0-Board\*1

- 3W-LED-Modul \*1

- USB-Kabel\*1

- Jumperkabel\*3

Verbinden Sie den S-Anschluss des Moduls mit Digital 13 des V4.0-Boards, den negativen Anschluss mit dem GND-Anschluss und den positiven Anschluss mit dem 5V-Anschluss.

![Anschlussdiagramm Abbildung](../media/7ca6e53405c422f3ae9b04ac572b40ef.jpeg)

## Beispielcode

Kopieren Sie den folgenden Code in die Arduino-Software.

```c
///////////////////////////////////////////////////////////
// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
///////////////////////////////////////////////////////////
```

## Beispielergebnis

Nachdem die Verkabelung abgeschlossen, die Stromversorgung eingeschaltet und der Code erfolgreich hochgeladen wurde, blinken sowohl die D13-LED als auch die LED des Moduls eine Sekunde lang und sind dann eine Sekunde aus, zyklisch.

![Beispielergebnis Abbildung](../media/edeb5b089be0300c719652badfd269e7.png)

---
